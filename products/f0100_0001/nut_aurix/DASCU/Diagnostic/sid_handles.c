#include "Diag_typedefs.h"
#include "CAN_private.h"

SID_desc_t SID_desc[16] =
{
    {.sid = DiagnosticSessionControl_0x10, .NRC_list[0] = subFunctionNotSupported_0x12, .NRC_list[1] = incorrectMessageLengthOrInvalidFormat_0x13, .NRC_list[2] = conditionsNotCorrect_0x22, .sid_handler = DiagnosticSessionControl_0x10_handler},
    {.sid = ECUReset_0x11, .NRC_list[0] = subFunctionNotSupported_0x12, .NRC_list[1] = incorrectMessageLengthOrInvalidFormat_0x13, .NRC_list[2] = conditionsNotCorrect_0x22, .NRC_list[3] = securityAccessDenied_0x33, .sid_handler = ECUReset_0x11_handler},
    {.sid = ReadDataByIdentifier_0x22, .NRC_list[0] = incorrectMessageLengthOrInvalidFormat_0x13, .NRC_list[1] = responseTooLong_0x14, .NRC_list[2] = conditionsNotCorrect_0x22, .NRC_list[3] = requestOutOfRange_0x31, .NRC_list[4] = securityAccessDenied_0x33, .sid_handler = ReadDataByIdentifier_0x22_handler},
    {.sid = WriteDataByIdentifier_0x2E, .NRC_list[0] = incorrectMessageLengthOrInvalidFormat_0x13, .NRC_list[1] = conditionsNotCorrect_0x22, .NRC_list[2] = requestOutOfRange_0x31, .NRC_list[3]=securityAccessDenied_0x33, .NRC_list[4] = generalProgrammingFailure_0x72, .sid_handler=WriteDataByIdentifier_0x2E_handler}
};

void checkServiceId(uds_state_t *uds_state, uint8 sid, uint8* data, frame_t frame_type)
{
    int i;

    for (i=0; i < 4; i++)
    {
        if (sid == SID_desc[i].sid)
        {
            SID_desc[i].sid_handler(uds_state, data, frame_type);
            return;
        }
    }

    uds_state->frame_status.NRC = serviceNotSupported_0x11;
}

void DiagnosticSessionControl_0x10_handler(uds_state_t *uds_state, unsigned char *data, frame_t frame)
{
	unsigned char len = data[0] & 0x0F;
	unsigned char sid = data[1];
	unsigned char subfunc = data[2];
	
	if (((data[2] & 0x0F) == 0) || ((data[2] & 0x0F) > 5))
	{
        uds_state->frame_status.NRC = subFunctionNotSupported_0x12;
		return;
	}
	
	if (len != 2)
	{
        uds_state->frame_status.NRC = incorrectMessageLengthOrInvalidFormat_0x13;
		return;
	}
	
	if (frame != SINGLE_FRAME)
	{
        uds_state->frame_status.NRC = conditionsNotCorrect_0x22;
		return;
	}
	
    uds_state->frame_type = SINGLE_FRAME;
    uds_state->frame_status.SID = sid;
    uds_state->frame_status.NRC = positiveResponse;
    uds_state->frame_status.PRC = sid + PRC_0x40;
    uds_state->frame_status.subfunc_code = subfunc;
    uds_state->frame_status.LEN = len;
    uds_state->frame_status.flg_request = isRequest;
    uds_state->frame_status.useDid = 0;
    uds_state->session_type = subfunc;
}

void ECUReset_0x11_handler(uds_state_t *uds_state, unsigned char *data, frame_t frame)
{
	unsigned char sid = data[1];
	unsigned char subfunc = data[2];
	unsigned char len = data[0] & 0x0F;
	
	if (((data[2] & 0x0F) == 0) || ((data[2] & 0x0F) > 6))
	{
        uds_state->frame_status.NRC = subFunctionNotSupported_0x12;
		return;
	}
	
	if (len != 2)	
	{
        uds_state->frame_status.NRC = incorrectMessageLengthOrInvalidFormat_0x13;
		return;
	}
	
	if (frame != SINGLE_FRAME)
	{
        uds_state->frame_status.NRC = conditionsNotCorrect_0x22;
		return;
	}

	// Add securityAccessDenied_0x33

    uds_state->frame_status.NRC = positiveResponse;
    uds_state->frame_status.PRC = sid + PRC_0x40;
    uds_state->frame_status.subfunc_code = subfunc;
    uds_state->frame_status.LEN = len;
    uds_state->frame_status.flg_request = isRequest;
}

void SecurityAccess_0x27_handler()
{
	
}

void CommunicationControl_0x28_handler()
{
	
}

void TesterPresent_0x3E_handler()
{
	
}

void AccessTimingParameter_0x83_handler()
{
	
}

void SecuredDataTransmission_0x84_handler()
{
	
}

void ControlDTCSetting_0x85_handler()
{
	
}

void ResponceOnEvent_0x86_handler()
{
	
}

void LinkControl_0x87_handler()
{
	
}

void ReadDataByIdentifier_0x22_handler(uds_state_t *uds_state, unsigned char* data, frame_t frame)
{	
	unsigned char sid = 0;
	uint16 len = 0;
    uint16 lenData = 0;
    uint16 tempLenData=0;
    uds_state->frame_status.DidsCount = 0;

	if (frame == SINGLE_FRAME)
	{		
        len = data[0] & 0x0F;
        sid = data[1];

        if (len < 3 || len > 7 || (len % 2) == 0 )
		{
            uds_state->frame_status.NRC = incorrectMessageLengthOrInvalidFormat_0x13;
			return;
		}
		
		//responseTooLong_0x14 = 0x14 -- dont need
		//conditionsNotCorrect_0x22 = 0x22 -- dont need
        //securityAccessDenied_0x33

        memcpy(uds_req_data, &data[2], 6);

        uds_state->frame_status.useMultiDids = (len == 3) ? 0 : 1;
        uds_state->frame_status.useDid = 1;
        uds_state->frame_status.MultiDIDs = (unsigned short*)uds_req_data;
        uds_state->p_next_data = uds_data;

        for (int i=3; i <= len; i+=2)    // 7 <= 7?
        {
            // 1)=4, 2)=2 3)=4
            tempLenData = checkDataLenghtDid(*(unsigned short*)uds_state->frame_status.MultiDIDs, uds_state->p_next_data);

            if (tempLenData > 0)
            {
                uds_state->frame_status.DidsCount++;    // 1)1, 2)2 3)3
                lenData += tempLenData; // 1)0+1=1, 2)1+1=2, 3)2+4 =6
                uds_state->p_next_data += (2+tempLenData); //1)+=3, 2)+=3, 3) +=6
            }

            uds_state->frame_status.MultiDIDs++;
        }

        if (lenData == 0)
        {
            uds_state->frame_status.NRC = requestOutOfRange_0x31;
            return;
        }

        if (uds_state->frame_status.useMultiDids == 0)
        {
            if (lenData > 4)
            {
                uds_state->frame_type = FIRST_FRAME;
            }
            else
            {
                uds_state->frame_type = SINGLE_FRAME;
            }
        }
        else
        {
            if (lenData > 2)
            {
                uds_state->frame_type = FIRST_FRAME;
            }
            else
            {
                uds_state->frame_type = SINGLE_FRAME;
            }
        }

        uds_state->frame_status.SID = sid;  // 0x22
        uds_state->frame_status.NRC = positiveResponse;
        uds_state->frame_status.PRC = sid + PRC_0x40;
        uds_state->frame_status.subfunc_code = 0x00;
        uds_state->frame_status.LEN = lenData + (uds_state->frame_status.DidsCount * 2); // 12
        uds_state->frame_status.flg_request = isRequest;
	}


	if (frame == FIRST_FRAME)
	{
        len = (unsigned short)(data[0]&0x0F)<<8 | data[1];
        sid = data[2];

		if (len < 7 || (len % 2) == 0) 
		{
            uds_state->frame_status.NRC = incorrectMessageLengthOrInvalidFormat_0x13;
			return;
		}
		//conditionsNotCorrect_0x22 = 0x22 -- dont need
        //securityAccessDenied_0x33

        memcpy(uds_req_data, &data[3], 5);  //

        uds_state->frame_status.FC_reqEn = 1;   // FOR FLOW CONTROL!

        uds_state->frame_status.useMultiDids = 1;
        uds_state->frame_status.useDid = 1;
        uds_state->frame_status.MultiDIDs = (unsigned short*)uds_req_data+5;
        uds_state->p_next_data = uds_data;

        uds_state->frame_status.SID = sid;  // 0x22
        uds_state->frame_status.NRC = positiveResponse;
        uds_state->frame_status.PRC = sid + PRC_0x40;
        uds_state->frame_status.subfunc_code = 0x00;
        uds_state->frame_status.DidsCount = (len-1)>>1; // (minus SID-byte and div 2)
        //uds_state->frame_status.LEN = lenData + (uds_state->frame_status.DidsCount * 2); // 12
        //uds_state->frame_status.flg_request = isRequest;
        uds_state->frame_type = FLOW_CONTROL_FRAME;
    }
}

void ReadMemoryByAddress_0x23_handler()
{
	
}

void ReadScalingDataByIdentifier_0x24_handler()
{
	
}

void ReadDataByPeriodicIdentifier_0x2A_handler()
{
	
}

void DynamicallyDefineDataIdentifier_0x2C_handler()
{
	
}

void WriteDataByIdentifier_0x2E_handler(uds_state_t *uds_state, unsigned char* data, frame_t frame)
{
	unsigned char sid = 0;
	uint16 len = 0;
	
	if (frame == SINGLE_FRAME)
	{		
		sid = data[1];
		len = data[0] & 0x0F;
		
		if (len < 4 || len > 0x07)	 	
		{
            uds_state->frame_status.NRC = incorrectMessageLengthOrInvalidFormat_0x13;
			return;
		}
		
		//responseTooLong_0x14 = 0x14 -- dont need
		//conditionsNotCorrect_0x22 = 0x22 -- dont need
		//requestOutOfRange_0x31 = 0x31 -- need making a find_did dunction for scanning supports DID!!!
		//securityAccessDenied_0x33
		
        uds_state->frame_status.DID = (unsigned short)data[2]<<8 | data[3];
	}
	
	if (frame == FIRST_FRAME)
	{	
		sid = data[2];
		len = (unsigned short)(data[0]&0x0F)<<8 | data[1];
	
		if (len < 4)
		{
            uds_state->frame_status.NRC = incorrectMessageLengthOrInvalidFormat_0x13;
			return;
		}
		
		//responseTooLong_0x14 = 0x14 -- dont need
		//conditionsNotCorrect_0x22 = 0x22 -- dont need
		//requestOutOfRange_0x31 = 0x31 -- need making a find_did dunction for scanning supports DID!!!
		//securityAccessDenied_0x33
		
        uds_state->frame_status.DID = (unsigned short)data[3]<<8 | data[4];
	}
	
    uds_state->frame_status.NRC = positiveResponse;
    uds_state->frame_status.PRC = sid + PRC_0x40;
    uds_state->frame_status.subfunc_code = 0x00;
    uds_state->frame_status.LEN = len;
    uds_state->frame_status.flg_request = isRequest;
    uds_state->frame_status.useDid = 1;
}

void WriteMemoryByAddress_0x3D_handler()
{
	
}

void ClearDiagnosticInformation_0x14_handler()
{
	
}

void ReadDTCInformation_0x19_handler()
{
	
}

void IOControlByIdentidier_0x2F_handler()
{
	
}

void RoutineControl_0x31_handler()
{
	
}

void RequestDownload_0x34_handler()
{
	
}

void RequestUpload_0x35_handler()
{
	
}

void TransferData_0x36_handler()
{
	
}

void RequestTransferExit_0x37_handler()
{
	
}

void RequestFileTransfer_0x38_handler()
{
	
}
