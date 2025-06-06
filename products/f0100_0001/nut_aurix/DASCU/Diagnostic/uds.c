#include "Diag_typedefs.h"
#include "DiagMrr_typedefs.h"
#include "ADASCANFD_MessageObjects.h"
#include "CAN_Private.h"
#include "DiagMrr_ext_vars.h"
#include "DiagMrr_ext_functions.h"
#include "DiagErag_ext_vars.h"
#include "DiagErag_ext_functions.h"


unsigned char uds_req_data[1024];
unsigned char uds_data[1024];

uds_state_t uds_state_dascu;

void Diag_dascu_process_receive(uds_state_t *uds_state, can_msg_t *rx_msg)
{
    uint8 code_frame = (rx_msg->data[0]>>4)&0x03;

    switch (code_frame)
    {
    	case SINGLE_FRAME:
            uds_state->frame_type = SINGLE_FRAME;
            Single_Frame_Handler(uds_state, rx_msg->data);
    		break;

    	case FIRST_FRAME:
            uds_state->frame_type = FIRST_FRAME;
            First_Frame_Handler(uds_state, rx_msg->data);
            break;

        case CONSECUTIVE_FRAME:
            uds_state->frame_type = CONSECUTIVE_FRAME;
            Consecutive_Frame_Handler(uds_state, rx_msg->data);
            break;

        case FLOW_CONTROL_FRAME:
            uds_state->frame_type = FLOW_CONTROL_FRAME;
            FlowControl_Frame_Handler(uds_state, rx_msg->data);
            break;

        default:
        	break;
    }
}

void Single_Frame_Handler(uds_state_t *uds_state, uint8 *data)
{
    uint8 sid;

    if (uds_state == &uds_state_dascu)
    {
        if (uds_state->frame_status.flg_request)    // ??????
        {

        }
        else
        {
            sid = data[1];
            uds_state->frame_status.flg_request = isRequest;
            checkServiceId(uds_state, sid, data, SINGLE_FRAME);
        }

        return;
    }

    if (uds_state == &uds_state_client_mrr)
    {
        if (diag_process_status.diag_state_rl == isEnable || diag_process_status.diag_state_rr == isEnable)
        {
            if (data[1] == (uds_state->frame_status.SID+PRC_0x40))
            {
                uds_state->frame_status.NRC = 0x00;
                uds_state->frame_status.PRC = data[1];
                uds_state->frame_status.subfunc_code = data[2];
                uds_state->frame_status.LEN = data[0] & 0x0F;
                uds_state->lastMessageTime = SystemTime;

                if (uds_state->frame_status.SID == ReadDataByIdentifierService_0x22)
                {
                    memcpy(uds_data, data, 8);
                    uds_state->lastMessageTime = SystemTime;
                }
            }
            return;
        }
    }

    if (uds_state == &uds_state_request_mrr)
    {
        if (data[1] == (uds_state->frame_status.SID+PRC_0x40))
        {
            uds_state->frame_status.LEN = data[0] & 0x0F;
            uds_state->frame_status.NRC = 0x00;
            uds_state->frame_status.PRC = data[1];
            uds_state->lastMessageTime = SystemTime;

            if (uds_state->frame_status.useDid == 1)
            {
                uds_state->frame_status.useDid = 0;

                int i = find_did(uds_state->frame_status.DID);

                if (i >= 0)
                {
                    didss_list[i].data_did_handler(data, g_radar_pos);
                }
            }

            return ;
        }
    }
}

void First_Frame_Handler(uds_state_t *uds_state, uint8* data)
{
    uint8 sid;

    if (uds_state == &uds_state_dascu)
    {
        if (uds_state->frame_status.flg_request)    // ???????????
        {

        }
        else
        {
            sid = data[2];
            uds_state->frame_status.flg_request = isRequest;
            checkServiceId(uds_state, sid, data, FIRST_FRAME);
        }

        return;
    }

    if (uds_state == &uds_state_client_mrr)
    {
        if (diag_process_status.diag_state_rl == isEnable || diag_process_status.diag_state_rr == isEnable)
        {
            if (data[2] == (uds_state->frame_status.SID+PRC_0x40))
            {
                uds_state->frame_status.LEN = (unsigned short)((data[0]&0x0F)<<8) | data[1];
                uds_state->frame_status.NRC = 0x00;
                uds_state->frame_status.PRC = data[2];
                //ret.subfunc_code = data[3];	// ?? not for read/write (!)

                uds_state->frame_type = FIRST_FRAME;
                uds_state->targetLen = uds_state->frame_status.LEN;	// 8;
                uds_state->frame_status.FC_FLAG = 0;
                uds_state->frame_status.FC_BS = 0;
                uds_state->frame_status.FC_ST = 0x14;
                uds_state->lastMessageTime = SystemTime;

                if (uds_state->frame_status.SID == ReadDataByIdentifierService_0x22)
                {
                    memcpy(uds_data, data, 8);
                    uds_state->p_next_data = (uds_data+8);
                    uds_state->frame_status.useDid = 1;
                }
            }

            return;
        }
    }

    if (uds_state == &uds_state_request_mrr)
    {
        if (data[2] == (uds_state->frame_status.SID+PRC_0x40))
        {
            uds_state->frame_status.LEN = (unsigned short)(data[0]&0x0F)<<8 | data[1];
            uds_state->frame_status.NRC = 0x00;
            uds_state->frame_status.PRC = data[2];
            uds_state->frame_status.subfunc_code = data[3];
            uds_state->targetLen = uds_state->frame_status.LEN;
            uds_state->reminderLen = uds_state->targetLen-6;	//11-6 = 5
            uds_state->frame_type = FLOW_CONTROL_FRAME;
            uds_state->frame_status.FC_FLAG = 0;
            uds_state->frame_status.FC_BS = 0;
            uds_state->frame_status.FC_ST = 0x14;
            uds_state->lastMessageTime = SystemTime;
            uds_state->frame_status.flg_request = isRequest;

            if (uds_state->frame_status.SID == ReadDataByIdentifierService_0x22)
            {
                memcpy(uds_data, data, 8);
                uds_state->p_next_data = &uds_data[0];
                uds_state->frame_status.useDid = 1;
                uds_state->p_next_data +=8;
            }

            return;
        }
    }

    if (uds_state == &uds_state_client_erag)
    {
    	if (data[2] == (uds_state->frame_status.SID+PRC_0x40))
    	{
    		uds_state->frame_status.LEN = (unsigned short)(data[0]&0x0F)<<8 | data[1];
    	    uds_state->frame_status.NRC = 0x00;
    	    uds_state->frame_status.PRC = data[2];
    	    //uds_state->frame_status.subfunc_code = data[3];
    	    uds_state->targetLen = uds_state->frame_status.LEN;
    	    uds_state->reminderLen = uds_state->targetLen-6;
    	    uds_state->frame_type = FLOW_CONTROL_FRAME;
    	    uds_state->frame_status.FC_FLAG = 0;
    	    uds_state->frame_status.FC_BS = 0;
    	    uds_state->frame_status.FC_ST = 0x14;
    	    uds_state->lastMessageTime = SystemTime;
//?    	    uds_state->frame_status.flg_request = isRequest;

    	    if (uds_state->frame_status.SID == EragReadDataById_0x22)
    	    {
    	    	memcpy(uds_data, data, 8);
    	    	uds_state->p_next_data = &uds_data[0];
    	    	uds_state->frame_status.useDid = 1;
    	    	uds_state->p_next_data +=8;
    	    }

    	    return;
    	}
    }
}

void Consecutive_Frame_Handler(uds_state_t *uds_state, uint8* data)
{
    // HERE STOPPED!     uds_state->frame_status.MultiDIDs =

    if (uds_state == &uds_state_client_mrr)
    {
        if (diag_process_status.diag_state_rl == isEnable || diag_process_status.diag_state_rr == isEnable)
        {
            if (uds_state->frame_status.PRC == ReadDataByIdentifierService_0x22+PRC_0x40)	// if Read (!!!!)
            {
                memcpy(uds_state->p_next_data, &data[1], 7);
                uds_state->p_next_data += 7;
                uds_state->frame_status.useDid = 1;
            }

            return;
        }
    }

    if (uds_state == &uds_state_request_mrr)
    {
        memcpy(uds_state->p_next_data, &data[1], 7);
    	uds_state->reminderLen -= 7;

        if (uds_state->reminderLen <= 0)
        {
            uds_state->flgConsecFrSended = 1;

            if (uds_state->frame_status.useDid == 1)
            {
            	uds_state->frame_status.useDid = 0;
            	uds_state->p_next_data = uds_data;
            	uds_state->reminderLen = 0;

            	int i = find_did(uds_state->frame_status.DID);

            	if (i >= 0)
            	{
            		didss_list[i].data_did_handler(&uds_data[5], g_radar_pos);
            	}
            }
        }
        else
        {
            uds_state->p_next_data += 7;
            uds_state->frame_status.useDid = 1;
        }

        return;
    }


    if (uds_state == &uds_state_client_erag)
    {
    	memcpy(uds_state->p_next_data, &data[1], 7);
    	uds_state->reminderLen -= 7;

    	if (uds_state->reminderLen <= 0)
    	{
    		uds_state->flgConsecFrSended = 1;

    		if (uds_state->frame_status.useDid == 1)
    		{
    			uds_state->frame_status.useDid = 0;
    			uds_state->p_next_data = uds_data;
    			uds_state->reminderLen = 0;
    		}
    	}
    	else
    	{
    		uds_state->p_next_data += 7;
    		uds_state->frame_status.useDid = 1;
    	}

    	return;
    }
}

void FlowControl_Frame_Handler(uds_state_t *uds_state, uint8* data)
{
    uds_state->frame_status.FC_FLAG = data[0] & 0x0F;

    if (uds_state->frame_status.FC_FLAG < 3)
    {
        uds_state->frame_status.FC_reqEn = 1;
        uds_state->frame_status.FC_BS = data[1];
        uds_state->frame_status.FC_ST = data[2];
        uds_state->lastMessageTime = SystemTime;
        uds_state->frame_type = CONSECUTIVE_FRAME;
        uds_state->frame_status.NRC = 0x00;
        uds_state->frame_status.PRC = 0x00;
    }
    else
    {
        uds_state->frame_status.FC_reqEn = 0;
    }
}

void answerFrame(uds_state_t *uds_state)
{
	uint8 txd[8];
	memset(txd, 0x00, 8);

    if (uds_state->frame_status.NRC != positiveResponse)
	{
        prepareNRCFrame(uds_state, txd);
		CAN_TransmitFrame(&Diag_From_DASCU_MO, txd);
		return;
	}

    if (uds_state->frame_type == SINGLE_FRAME)
    {
        prepareSingleFrame(uds_state, txd);
    }
		
    if (uds_state->frame_type == FIRST_FRAME)
    {
        prepareFirstFrame(uds_state, txd);
    }
		
    if (uds_state->frame_type == CONSECUTIVE_FRAME)
    {
        prepareConsecutiveFrame(uds_state, txd);
    }

    if (uds_state->frame_type == FLOW_CONTROL_FRAME)
    {
        prepareFlowControlFrame(uds_state, txd);
    }

    CAN_TransmitFrame(&Diag_From_DASCU_MO, txd);
}

/* PREPAIRING RESPONCES for REQUESTS !!!*/
void prepareSingleFrame(uds_state_t *uds_state, uint8* data)
{
	uint8 calcLen=0;
	
    data[1] = uds_state->frame_status.PRC;
    calcLen++;  // 1

    if (uds_state->frame_status.useDid)
    {
        uds_state->frame_status.useDid = 0;
        calcLen += uds_state->frame_status.LEN;
        memcpy(&data[2], uds_data, uds_state->frame_status.LEN);
	}
	else
	{
        data[2] = uds_state->frame_status.subfunc_code;
		calcLen++;
    }
	
	data[0] = (SINGLE_FRAME<<4) | (calcLen &0x0F);
}

void prepareFirstFrame(uds_state_t *uds_state, uint8* data)
{
    uint16 calcLen=0;

    data[2] = uds_state->frame_status.PRC;
    calcLen++;  // 1

    if (uds_state->frame_status.useDid)
    {
        calcLen += uds_state->frame_status.LEN;
        memcpy(&data[3], uds_data, 5);
        uds_state->p_next_data = uds_data+5;
        uds_state->targetLen = calcLen; // 13
        uds_state->reminderLen = calcLen-6; // 7
    }
    else
    {
        // Prorabotat' later!!!
    }

    data[0] = (FIRST_FRAME<<4) | ((calcLen >> 8) &0x0F);
    data[1] = (calcLen &0x0F);
}

void prepareConsecutiveFrame(uds_state_t *uds_state, uint8* data)
{
    uds_state->frameNumber = (uds_state->frameNumber + 1) & 0xF;

    if (uds_state->frameNumber == 0)
	{
        uds_state->frameNumber = 1;
	}

    data[0] = (CONSECUTIVE_FRAME<<4) | uds_state->frameNumber;	// 1) 1

    memcpy(&data[1], uds_state->p_next_data, 7);
    uds_state->p_next_data += 7;

    /* check for remainig data */
    uds_state->reminderLen -= 7;

    if (uds_state->reminderLen > 0)
    {
        uds_state->frame_status.FC_reqEn = 1;
    }
    else
    {
        uds_state->frame_status.FC_reqEn = 0;
        uds_state->frameNumber = 0;
        uds_state->reminderLen = 0;
        uds_state->targetLen = 0;
    }
}

void prepareFlowControlFrame(uds_state_t *uds_state, uint8* data)
{
	data[0] = (FLOW_CONTROL_FRAME<<4) | 0x00;
    data[1] = 0x00;
    data[2] = 0x00;
    memset(&data[3], 0xAA, 5);

    uds_state->frame_status.FC_BS = 0x00;
    uds_state->frame_status.FC_ST = 0x00;
    uds_state->lastMessageTime = SystemTime;
    uds_state->frame_type = CONSECUTIVE_FRAME;
}

void prepareNRCFrame(uds_state_t *uds_state, uint8* data)
{
	data[0] = 0x03;
    data[1] = NRC_0x7F;
    data[2] = uds_state->frame_status.SID;
    data[3] = uds_state->frame_status.NRC;
	memset(&data[4], 0xAA, 4);
}

unsigned char* prepareServWriteDataDascu(unsigned char *txData, unsigned char *buff, unsigned short len, unsigned short did, frame_t frame)
{
	unsigned char *ret;

	if (frame == SINGLE_FRAME)
	{
		buff[0] = (frame&0x03)<<4;
		buff[0] |= (unsigned char)len & 0x07;
		buff[1] = 0x2E;
		buff[2] = did >>8;
		buff[3] = (unsigned char)did;
		ret = &buff[4];
	}

	if (frame == FIRST_FRAME)
	{
		buff[0] = (frame&0x03)<<4;
		buff[0] |= (len>>8)& 0x0F;
		buff[1] = (unsigned char)len;
		buff[2] = 0x2E;
		buff[3] = did>>8;
		buff[4] = (unsigned char)did;
		ret = &buff[5];
	}

	if (frame == CONSECUTIVE_FRAME)
	{
		uds_state_dascu.frameNumber = (uds_state_dascu.frameNumber+1)&0x0F;

		if (uds_state_dascu.frameNumber == 0)
		{
			uds_state_dascu.frameNumber = 1;
		}

		txData[0] = CONSECUTIVE_FRAME <<4;
		txData[0] |= uds_state_dascu.frameNumber;
		memcpy(&txData[1], buff, 7);
		ret = buff+7;
	}

	return ret;
}
