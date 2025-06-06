#include "Diag_typedefs.h"
#include "ADASCANFD_MessageObjects.h"
#include "CAN_Private.h"

void manageRequestDascu()
{
	/*
    if (REQ_Image)
    {
        uint8 txd[8];

        REQ_Image = 0;

        uds_state_dascu.frame_status.SID = WriteDataByIdentifier_0x2E;
        uds_state_dascu.frame_status.useDid = 1;
        uds_state_dascu.frame_status.DID = 0xF1F6;
        uds_state_dascu.frame_type = FIRST_FRAME;
        //uds_state_dascu.p_next_data = prepareServWriteDataDascu(txd, uds_data, sizeof(test_image)+3, 0xF1F6, FIRST_FRAME);
        prepareUdsImg(uds_state_dascu.p_next_data, 3958);

        uds_state_dascu.flgSendImage = 1;
        uds_state_dascu.frameNumber = 0;
        //uds_state_dascu.targetLen = sizeof(test_image)+3;	// 3955+3 = 3958
        uds_state_dascu.reminderLen = (uds_state_dascu.targetLen-6);	// remaining... 3952
        uds_state_dascu.p_next_data += 3;

        uds_state_dascu.frame_status.flg_request = isRequest;

        CAN_TransmitFrame(&Diag_From_DASCU_MO, uds_data);
    }
    */
}

void prepareUdsImg(unsigned char *data, unsigned short len)
{
   // memcpy(data, test_image, len);
}

void routineSendImage(uds_state_t *uds_state)
{
    uint8 txd[8];

    if (uds_state->frame_status.FC_reqEn == 1)
    {
        uds_state->reminderLen -= 7;

        if (uds_state->reminderLen <= 0)
        {
            uds_state->flgSendImage = 0;
            uds_state->p_next_data = uds_data;
            uds_state->targetLen = 0;
            uds_state->frame_type = SINGLE_FRAME;
            uds_state->frame_status.FC_reqEn = 0;
            uds_state->frameNumber = 0;
            uds_state->reminderLen = 0;
        }
        else
        {
            prepareConsecutiveFrame(uds_state, txd);
            CAN_TransmitFrame(&Diag_From_DASCU_MO, txd);
        }
    }
}
