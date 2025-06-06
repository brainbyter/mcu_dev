#include "DiagErag_typedefs.h"
#include "DiagErag_ext_vars.h"
#include "DiagErag_ext_functions.h"
#include "ADASCANFD_MessageObjects.h"
#include "CAN_Extern.h"
#include "CAN_Private.h"
#include "stdlib.h"
#include "../ext_vars.h"

uds_state_t uds_state_client_erag;
ERAG_SOS_FSM_t ERAG_SOS_FSM = {.lastTimeIncMessage 0, .countTryRequest = 0, .SOS_State = SOS_Idle, \
		.last_SOS_State = SOS_Idle, .TesterPresetServEn = 0, .TesterPresetServLastTimeMessage = 0, .startTimeAwaitEragStatus = 0};


void udsPosResponceSos(SOS_State_t target_SOS_State);
unsigned long SeedToKey(unsigned int seed,unsigned char rnd);
unsigned short swap16bits(unsigned short in);
unsigned int swap32bits(unsigned int in);

unsigned int seed_value = 0x00;
static unsigned int key_value = 0x00;
unsigned char RoutineStatus = 0x00;
unsigned char fSosIdle = 0;


unsigned int eragDiagLong = 0x00;
unsigned int eragDiagLat = 0x00;
unsigned int g_eragDiagLong = 0x00;
unsigned int g_eragDiagLat = 0x00;

void udsPosResponceSos(SOS_State_t target_SOS_State)
{
	ERAG_SOS_FSM.SOS_State = target_SOS_State;
    uds_state_client_erag.frame_status.NRC = 0x00;
    uds_state_client_erag.frame_status.PRC = 0x00;
    uds_state_client_erag.frame_status.SID = 0x00;
    uds_state_client_erag.frame_status.LEN = 0x0000;
    uds_state_client_erag.frame_status.DID = 0x0000;
    uds_state_client_erag.frame_type = SINGLE_FRAME;
}


void configEragSos()
{
	uint8 txData[8];
	//memset(txData, 0x00, 8);

    if (ERAG_SOS_FSM.TesterPresetServEn)
    {
    	if ((SystemTime - ERAG_SOS_FSM.TesterPresetServLastTimeMessage) >= 3500U)
    	{
    		prepareEragServTesterPresent(txData, 0x00);
    		CAN_TransmitFrame(&Diag_To_ERAG_MO, txData);
    		ERAG_SOS_FSM.TesterPresetServLastTimeMessage = SystemTime;
    	}
    }


    if (ERAG_SOS_FSM.SOS_State != SOS_Idle)
    {
    	fSosIdle = 0;
    }

	switch(ERAG_SOS_FSM.SOS_State)
	{
	case SOS_Idle:
		if (fSosIdle == 0)
		{
			udsExitSos();
			fSosIdle = 1;
		}

		break;

	case SOS_WAIT_DEBUG:
		break;

	case SOS_Await_Result:
		if (((SystemTime - ERAG_SOS_FSM.startTimeAwaitEragStatus) >= 3000))
		{
			if (++ERAG_SOS_FSM.countTryRequest < 3)
			{
				uds_state_client_erag.frame_type = SINGLE_FRAME;
				ERAG_SOS_FSM.SOS_State = ERAG_SOS_FSM.last_SOS_State;
				ERAG_SOS_FSM.lastTimeIncMessage = SystemTime;
				ERAG_SOS_FSM.startTimeAwaitEragStatus = SystemTime;
			}
			else
			{
				udsPosResponceSos(SOS_SendDefSess);
				return;
			}
		}

		if (ERAG_Status == 0x0B)
		{
			udsPosResponceSos(SOS_SendDefSess);
			return;
		}

		break;

	case SOS_AwaitResp:
		if (uds_state_client_erag.frame_status.FC_reqEn == 1)
		{
			ERAG_SOS_FSM.SOS_State = ERAG_SOS_FSM.last_SOS_State;
		}
		else if ((uds_state_client_erag.frame_status.PRC == uds_state_client_erag.frame_status.SID+0x40) || uds_state_client_erag.frame_status.NRC == 0x7FU)
		{
			ERAG_SOS_FSM.SOS_State = ERAG_SOS_FSM.last_SOS_State;
			ERAG_SOS_FSM.last_SOS_State = SOS_Idle;
			ERAG_SOS_FSM.countTryRequest = 0;
			ERAG_SOS_FSM.lastTimeIncMessage = 0;
		}
		else
		{
			if (((SystemTime - ERAG_SOS_FSM.lastTimeIncMessage) >= 1000))
			{
				if (++ERAG_SOS_FSM.countTryRequest < 5)
				{
					uds_state_client_erag.frame_type = SINGLE_FRAME;
					ERAG_SOS_FSM.SOS_State = ERAG_SOS_FSM.last_SOS_State;
					ERAG_SOS_FSM.lastTimeIncMessage = SystemTime;
				}
				else
				{
					udsExitSos();
					return;
				}
			}
		}

		break;

	case SOS_SendExtSess:
        if (uds_state_client_erag.frame_status.PRC == uds_state_client_erag.frame_status.SID+0x40)
		{
			udsPosResponceSos(SOS_SendRND);
        	ERAG_SOS_FSM.TesterPresetServEn = 1;
			ERAG_SOS_FSM.TesterPresetServLastTimeMessage = SystemTime;
		}
		else
		{
			prepareEragServChangeSession(uds_data, 0x03);
			uds_state_client_erag.frame_type = SINGLE_FRAME;
			uds_state_client_erag.lastMessageTime = SystemTime;
            uds_state_client_erag.frame_status.SID = 0x10;	//EragDiagnosticSessionControlService_0x10;
            ERAG_SOS_FSM.SOS_State = SOS_AwaitResp;
            ERAG_SOS_FSM.last_SOS_State = SOS_SendExtSess;
            ERAG_SOS_FSM.lastTimeIncMessage = SystemTime;
            memcpy(txData, uds_data, 8);
            CAN_TransmitFrame(&Diag_To_ERAG_MO, txData);
		}

		break;

	case SOS_SendRND:
		if (uds_state_client_erag.frame_status.PRC == uds_state_client_erag.frame_status.SID+0x40)
		{
			seed_value = (unsigned int)uds_data[3] << 0 | (unsigned int)uds_data[4]<< 8 | (unsigned int)uds_data[5] << 16 | (unsigned int)uds_data[6]<< 24;
			seed_value = swap32bits(seed_value);
			key_value = SeedToKey(seed_value, 0);
			udsPosResponceSos(SOS_SendKey);
		}
		else
		{
			prepareEragServSecurutyAccess(uds_data, 0x01, 0x00, UDS_SEED);
			uds_state_client_erag.frame_type = SINGLE_FRAME;
			uds_state_client_erag.lastMessageTime = SystemTime;
			uds_state_client_erag.frame_status.SID = EragSecurityAccessService_0x27;
			uds_state_client_erag.frame_status.subfunc_code = 0x01;
			ERAG_SOS_FSM.SOS_State = SOS_AwaitResp;
			ERAG_SOS_FSM.last_SOS_State = SOS_SendRND;
			ERAG_SOS_FSM.lastTimeIncMessage = SystemTime;
			memcpy(txData, uds_data, 8);
			CAN_TransmitFrame(&Diag_To_ERAG_MO, txData);
		}

		break;

	case SOS_SendKey:
		if (uds_state_client_erag.frame_status.PRC == uds_state_client_erag.frame_status.SID+0x40)
		{
			udsPosResponceSos(SOS_SendRoutineSos);
		}
		else if (uds_state_client_erag.frame_status.NRC == 0x7F)
		{
			udsPosResponceSos(SOS_SendDefSess);
		}
		else
		{
			key_value = swap32bits(key_value);
			prepareEragServSecurutyAccess(uds_data, 0x02, key_value, UDS_KEY);
			uds_state_client_erag.frame_type = SINGLE_FRAME;
			uds_state_client_erag.lastMessageTime = SystemTime;
			uds_state_client_erag.frame_status.SID = EragSecurityAccessService_0x27;
			uds_state_client_erag.frame_status.subfunc_code = 0x02;
			ERAG_SOS_FSM.SOS_State = SOS_AwaitResp;
			ERAG_SOS_FSM.last_SOS_State = SOS_SendKey;
			ERAG_SOS_FSM.lastTimeIncMessage = SystemTime;
			memcpy(txData, uds_data, 8);
			CAN_TransmitFrame(&Diag_To_ERAG_MO, txData);
		}

		break;

	case SOS_SendRoutineSos:
		if (uds_state_client_erag.frame_status.PRC == uds_state_client_erag.frame_status.SID+0x40)
		{
			RoutineStatus = uds_data[5];

			if (RoutineStatus == 0x00)
			{
				udsPosResponceSos(SOS_Await_Result);
				ERAG_SOS_FSM.startTimeAwaitEragStatus = SystemTime;
				ERAG_SOS_FSM.last_SOS_State = SOS_Await_Result;
				ERAG_SOS_FSM.lastTimeIncMessage = SystemTime;
			}
			else
			{
				udsPosResponceSos(SOS_SendDefSess);
			}
		}
		else if (uds_state_client_erag.frame_status.NRC == 0x7F)
		{
			udsPosResponceSos(SOS_SendDefSess);
		}
		else
		{
			prepareEragServRoutineControl(uds_data, 0x04, 0x01, 0x18E6);
			uds_state_client_erag.frame_type = SINGLE_FRAME;
			uds_state_client_erag.lastMessageTime = SystemTime;
			uds_state_client_erag.frame_status.SID = EragRoutineControlService_0x31;
			uds_state_client_erag.frame_status.subfunc_code = 0x01;
			ERAG_SOS_FSM.SOS_State = SOS_AwaitResp;
			ERAG_SOS_FSM.last_SOS_State = SOS_SendRoutineSos;
			ERAG_SOS_FSM.lastTimeIncMessage = SystemTime;
			memcpy(txData, uds_data, 8);
			CAN_TransmitFrame(&Diag_To_ERAG_MO, txData);
		}

		break;

	case SOS_SendDefSess:
		if (uds_state_client_erag.frame_status.PRC == uds_state_client_erag.frame_status.SID+0x40)
		{
			udsExitSos();
		}
		else
		{
			prepareEragServChangeSession(uds_data, 0x01);
			uds_state_client_erag.frame_type = SINGLE_FRAME;
			uds_state_client_erag.lastMessageTime = SystemTime;
			uds_state_client_erag.frame_status.SID = EragDiagnosticSessionControlService_0x10;
			ERAG_SOS_FSM.SOS_State = SOS_AwaitResp;
			ERAG_SOS_FSM.last_SOS_State = SOS_SendDefSess;
			ERAG_SOS_FSM.lastTimeIncMessage = SystemTime;
			memcpy(txData, uds_data, 8);
			CAN_TransmitFrame(&Diag_To_ERAG_MO, txData);
		}

		break;
	}
}


void prepareEragServChangeSession(unsigned char *data, unsigned char subFunc)
{
	data[0] = 0x00 | 0x02;
	data[1] = 0x10;
	data[2] = subFunc;
	memset(&data[3], 0xAA, 5);
}

void prepareEragServSecurutyAccess(unsigned char *data, unsigned char subFunc, unsigned int param, TypeSecureAccess_t TypeSecureAccess)
{
	if (TypeSecureAccess == UDS_SEED)
	{
		data[0] = 0x03;
		data[1] = 0x27;
		data[2] = subFunc;
		data[3] = (unsigned char)param;	// RND Value
		memset(&data[4], 0xAA, 4);
	}

	if (TypeSecureAccess == UDS_KEY)
	{
		data[0] = 0x06;
		data[1] = 0x27;
		data[2] = subFunc;
		memcpy(&data[3], &param, 4);
		data[7] = 0xAA;
	}
}

void prepareEragServRoutineControl(unsigned char *data, unsigned short len, unsigned char subFunc, unsigned short did)
{
	data[0] = (unsigned char)len&0x07;
	data[1] = 0x31;
	data[2] = subFunc;
	data[3] = did>>8;
	data[4] = did;
	memset(&data[5], 0xAA, 3);
}

void prepareEragServTesterPresent(unsigned char *data, unsigned char subFunc)
{
	data[0] = 0x02;
	data[1] = 0x3E;
	data[2] = subFunc;
	memset(&data[5], 0xAA, 3);
}



void prepareEragServReadDataById(unsigned char *data, unsigned short did)
{
	data[0] = 0x03;
	data[1] = 0x22;
	data[2] = did>>8;
	data[3] = (unsigned char)did;
	memset(&data[4], 0xAA, 4);
}


#define Mask01 0x75A1A006
unsigned long SeedToKey(unsigned int seed,unsigned char rnd)
{
	unsigned int i;
    unsigned long key=seed;

    if (rnd < (255-35) )
    {
    	rnd += 35;
    }
    else
    {
    	rnd = 255;
    }

    for(i=1; i <= rnd; i++)
    {
    	if((key&0x80000000) != 0)
    	{
    		key = (key << 1) ^ Mask01;
    	}
    	else key <<= 1;
    }

    return key;
}


void udsExitSos()
{
	ERAG_SOS_FSM.countTryRequest = 0;
	ERAG_SOS_FSM.lastTimeIncMessage = 0;
	ERAG_SOS_FSM.last_SOS_State = SOS_Idle;
	ERAG_SOS_FSM.SOS_State = SOS_Idle;
	ERAG_SOS_FSM.TesterPresetServEn = 0;
	ERAG_SOS_FSM.TesterPresetServLastTimeMessage = 0;
	ERAG_SOS_FSM.startTimeAwaitEragStatus = 0;

    uds_state_client_erag.frame_status.LEN = 0;
    uds_state_client_erag.frame_status.NRC = 0;
    uds_state_client_erag.frame_status.PRC = 0;
    uds_state_client_erag.frame_status.DID = 0;
    uds_state_client_erag.frame_status.SID = 0;
    uds_state_client_erag.frame_status.flg_request = 0;
    uds_state_client_erag.frame_status.useDid = 0;
    uds_state_client_erag.frame_status.subfunc_code= 0;
    uds_state_client_erag.frame_status.FC_BS = 0;
    uds_state_client_erag.frame_status.FC_FLAG = 0;
    uds_state_client_erag.frame_status.FC_reqEn = 0;
    uds_state_client_erag.frame_status.FC_ST = 0;
    uds_state_client_erag.frame_type = SINGLE_FRAME;
	uds_state_client_erag.frameNumber = 0;
	uds_state_client_erag.lastMessageTime = 0;
	uds_state_client_erag.p_next_data = 0;
	uds_state_client_erag.reminderLen = 0;
	uds_state_client_erag.targetLen = 0;
}

unsigned short swap16bits(unsigned short in)
{
	return (in >> 8) | (in << 8);
}

unsigned int swap32bits(unsigned int in)
{
	return (in>>24) | (in<<24) | ((in>>8)&0xFF00U) | ((in<<8)&0xFF0000U);
}


///////////////////////////////
// DIAG ERAG READ DATA BY IDENTIFIER /////////////
void requestEragCoords()
{
	unsigned char txData[8];

	uds_state_client_erag.frame_type = SINGLE_FRAME;
	uds_state_client_erag.lastMessageTime = SystemTime;
	uds_state_client_erag.frame_status.SID = EragReadDataById_0x22;
	uds_state_client_erag.frame_status.useDid = 1;
	uds_state_client_erag.frame_status.DID = 0x0B07;
	prepareEragServReadDataById(uds_data, (unsigned short)0x0B07);
	memcpy(txData, uds_data, 8);
	CAN_TransmitFrame(&Diag_To_ERAG_MO, txData);
}


void eragDiagState()
{
	unsigned char txData[8];

	if (uds_state_client_erag.frame_type == FLOW_CONTROL_FRAME)
	{
		prepareFlowControlFrame(&uds_state_client_erag, txData);
		CAN_TransmitFrame(&Diag_To_ERAG_MO, txData);
		uds_state_client_erag.frame_type = CONSECUTIVE_FRAME;
		return;
	}

	if (uds_state_client_erag.frame_type == CONSECUTIVE_FRAME)
	{
		if (uds_state_client_erag.flgConsecFrSended == 1)
		{
			uds_state_client_erag.flgConsecFrSended = 0;

			memcpy(&eragDiagLong, &uds_state_client_erag.p_next_data[5], 4);
			memcpy(&eragDiagLat, &uds_state_client_erag.p_next_data[9], 4);

			eragDiagLong = swap32bits(eragDiagLong);
			eragDiagLat = swap32bits(eragDiagLat);
		}

		return;
	}
}
