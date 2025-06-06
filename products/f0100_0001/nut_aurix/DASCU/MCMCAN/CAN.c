#include "DASCU/MCMCAN/Generated/CAN.h"
#include "DASCU/MCMCAN/CAN_Private.h"
#include "DASCU/MCMCAN/Generated/CAN_Extern.h"
#include "DASCU/MCMCAN/MCMCAN.h"
#include "bsp_can.h"
#include "sw_version.h"

/* KOSTYL INIT for a little time */
/*float DtLogAaEragDate;
float DtLogAaEragTime;
float DtLogAaFuzzyScore;
uint8 DtLogAaWarnDms;
float DtLogAaTimeAnalWarn;
unsigned char DtLogAaSolverTrans;
*/

//unsigned char DtLogAaSolverTrans;

unsigned char DAS_LkaShootdownNotif_Req;

void CAN_InitNetworks(void);


volatile uint32 SystemTime = 0;

CanMessageObject_t* lastMessageObject = 0;
CanMessageObject_t* lastMessageObjectAurus = 0;
CanMessageObject_t* lastMessageObjectHaval = 0;
CanMessageObject_t* lastMessageObjectMrrxData = 0;
CanMessageObject_t* lastMessageObjectMrrxDiag = 0;
CanMessageObject_t* lastMessageObjectDebug = 0;
CanMessageObject_t* lastMessageObjectXcp = 0;

can_filter_item g_adas_filter_for_reset_items[2];
can_filter_config_t g_adas_filter_for_reset_config;

can_filter_item g_adas_filter_items[ADAS_MAX_RX_FILTER];
can_filter_config_t g_adas_filter_config;

can_filter_item g_test_adas_filter_items[DEBUG_ADAS_MAX_RX_FILTER];
can_filter_config_t g_test_adas_filter_config;

can_filter_item g_mrrx_diag_items[MRRX_DIAG_MAX_RX_FILTER];
can_filter_config_t g_mrrx_diag_filter_config;

can_filter_item g_mrrx_data_items[MRRX_DATA_MAX_RX_FILTER];
can_filter_config_t g_mrrx_data_filter_config;

can_filter_item g_haval_items[HAVAL_MAX_RX_FILTER];
can_filter_config_t g_haval_filter_config;

can_filter_item g_xcp_items[XCP_MAX_RX_FILTER];
can_filter_config_t g_xcp_filter_config;


uint16 posAdasMo = 0;
uint16 posTestAdasMo = 0;
uint16 posMrrxDataMo = 0;
uint16 posMrrxDiagMo = 0;
uint16 posHavalMo = 0;
uint16 posXcpMo = 0;


uint8 fGetAdasMo = 0;
uint8 fGetTestAdasMo = 0;
uint8 fGetMrxxDataMo = 0;
uint8 fGetMrxxDiagMo = 0;
uint8 fGetHavalMo = 0;
uint8 fGetXcpMo = 0;

volatile sint8 cntMrrxDataSendUdp = -1;

void CAN_InitNetworks(void)
{
	int i;

    for (i = 0; i < CAN_MAX_NETWORKS; i++)
    {
        CAN_Networks[i].txEn = 1;
        CAN_Networks[i].rxEn = 1;
    }
}


void CAN_InitMessageObject(CanMessageObject_t* messageObj)
{
	if (!((messageObj->dir == TX) && (messageObj->cycle == 0)))
	{
		messageObj->prevMessageObjForFilter = lastMessageObject;
		lastMessageObject = messageObj;

		switch (messageObj->network)
		{
#ifdef SW_AURUS
		case ADASCANFD:
			messageObj->prevMessageObj = lastMessageObjectAurus;
			lastMessageObjectAurus = messageObj;
			break;
#endif

#ifdef SW_HAVAL
		case HAVAL:
			messageObj->prevMessageObj = lastMessageObjectHaval;
			lastMessageObjectHaval = messageObj;
			break;
#endif

		case MRRX_DATA:
			messageObj->prevMessageObj = lastMessageObjectMrrxData;
			lastMessageObjectMrrxData = messageObj;
			break;

		case MRRXCAN_DIAG:
			messageObj->prevMessageObj = lastMessageObjectMrrxDiag;
			lastMessageObjectMrrxDiag = messageObj;
			break;

#ifdef HW_DEBUG
		case FD:
			messageObj->prevMessageObj = lastMessageObjectDebug;
			lastMessageObjectDebug = messageObj;
			break;

		case XCP_CAN:
			messageObj->prevMessageObj = lastMessageObjectXcp;
			lastMessageObjectXcp = messageObj;
			break;
#endif
		default:
			break;
		}
	}

	messageObj->lastMessageTime = 0;

	static boolean voidTimeout = TRUE;

	if(messageObj->pTimeout == 0)
	{
	    messageObj->pTimeout = &voidTimeout;
	}
}


void ClearCANFaults()
{
	int i;

	for(i = 0; i < CAN_MAX_NETWORKS; i++)
	{
		CAN_Networks[i].lastMessageTime = SystemTime;
		*CAN_Networks[i].pBusOffFlt = 0;
		*CAN_Networks[i].pErrorPassivNetwork = 0;
	}
}


void SetCANTXEn(CANNetworkID_t network, boolean enable)
{
    CAN_Networks[network].txEn = enable;
}


void SetCANRXEn(CANNetworkID_t network, boolean enable)
{
    CAN_Networks[network].rxEn = enable;
}

void CAN_InitRxDascuIdItems()
{
	CanMessageObject_t* MessageObject = lastMessageObject;

	uint32 id;

	while(MessageObject)
	{
		if (MessageObject->dir == RX)
		{
			switch (MessageObject->network)
			{
#ifdef SW_AURUS
				case ADASCANFD:
					id = MessageObject->ID;
					g_adas_filter_items[posAdasMo].id = id;
					g_adas_filter_items[posAdasMo].ide = kCanIdStd;
					g_adas_filter_items[posAdasMo].rtr = kCanRtrData;
					g_adas_filter_items[posAdasMo].mask = 0xFFFFFFFF;
					g_adas_filter_items[posAdasMo].fdf = MessageObject->FD ? kCanFdTypeCanFd : kCanFdTypeClassic;
					posAdasMo++;
					fGetAdasMo = 1;
					break;
#endif

#ifdef SW_HAVAL
				case HAVAL:
					id = MessageObject->ID;
					g_haval_items[posHavalMo].id = id;
					g_haval_items[posHavalMo].ide = kCanIdStd;
					g_haval_items[posHavalMo].rtr = kCanRtrData;
					g_haval_items[posHavalMo].mask = 0xFFFFFFFF;
					g_haval_items[posHavalMo].fdf = MessageObject->FD ? kCanFdTypeCanFd : kCanFdTypeClassic;
					posHavalMo++;
					fGetHavalMo = 1;
					break;
#endif

				case MRRX_DATA:
					id = MessageObject->ID;
					g_mrrx_data_items[posMrrxDataMo].id = id;
					g_mrrx_data_items[posMrrxDataMo].ide = kCanIdStd;
					g_mrrx_data_items[posMrrxDataMo].rtr = kCanRtrData;
					g_mrrx_data_items[posMrrxDataMo].mask = 0xFFFFFFFF;
					//g_mrrx_data_items[posMrrxDataMo].fdf = MessageObject->FD ? kCanFdTypeCanFd : kCanFdTypeClassic;
					g_mrrx_data_items[posMrrxDataMo].fdf = kCanFdTypeCanFd;
					posMrrxDataMo++;
					fGetMrxxDataMo = 1;
					break;

				case MRRXCAN_DIAG:
					id = MessageObject->ID;
					g_mrrx_diag_items[posMrrxDiagMo].id = id;
					g_mrrx_diag_items[posMrrxDiagMo].ide = kCanIdStd;
					g_mrrx_diag_items[posMrrxDiagMo].rtr = kCanRtrData;
					g_mrrx_diag_items[posMrrxDiagMo].mask = 0xFFFFFFFF;
					g_mrrx_diag_items[posMrrxDiagMo].fdf = MessageObject->FD ? kCanFdTypeCanFd : kCanFdTypeClassic;
					posMrrxDiagMo++;
					fGetMrxxDiagMo = 1;
					break;
#ifdef HW_DEBUG
				case FD:
					id = MessageObject->ID;
					g_test_adas_filter_items[posTestAdasMo].id = id;
					g_test_adas_filter_items[posTestAdasMo].ide = kCanIdStd;
					g_test_adas_filter_items[posTestAdasMo].rtr = kCanRtrData;
					g_test_adas_filter_items[posTestAdasMo].mask = 0xFFFFFFFF;
					g_test_adas_filter_items[posTestAdasMo].fdf = MessageObject->FD ? kCanFdTypeCanFd : kCanFdTypeClassic;
					posTestAdasMo++;
					fGetTestAdasMo = 1;
					break;

				case XCP_CAN:
					id = MessageObject->ID;
					g_xcp_items[posXcpMo].id = id;
					g_xcp_items[posXcpMo].ide = kCanIdStd;
					g_xcp_items[posXcpMo].rtr = kCanRtrData;
					g_xcp_items[posXcpMo].mask = 0xFFFFFFFF;
					g_xcp_items[posXcpMo].fdf = MessageObject->FD ? kCanFdTypeCanFd : kCanFdTypeClassic;
					posXcpMo++;
					fGetXcpMo = 1;
					break;
#endif
				default:
					break;
			}
		}

		MessageObject = MessageObject->prevMessageObjForFilter;
	}
}

#ifdef SW_AURUS
void CAN_InitRxAdasFilters()
{
	if (fGetAdasMo == 1)
	{
		g_adas_filter_config.count = posAdasMo;
		g_adas_filter_config.active = 1;
		g_adas_filter_config.items = g_adas_filter_items;
	}
}
#endif

#ifdef SW_HAVAL
void CAN_InitRxHavalFilters()
{
	if (fGetHavalMo == 1)
	{
		g_haval_filter_config.count = posHavalMo;
		g_haval_filter_config.active = 1;
		g_haval_filter_config.items = g_haval_items;
	}
}
#endif

void CAN_InitRxMrrxDataFilters()
{
	if (fGetMrxxDataMo == 1)
	{
		g_mrrx_data_filter_config.count = posMrrxDataMo;
		g_mrrx_data_filter_config.active = 1;
		g_mrrx_data_filter_config.items = g_mrrx_data_items;
	}
}

void CAN_InitRxMrrxDiagFilters()
{
	if (fGetMrxxDiagMo == 1)
	{
		g_mrrx_diag_filter_config.count = posMrrxDiagMo;
		g_mrrx_diag_filter_config.active = 1;
		g_mrrx_diag_filter_config.items = g_mrrx_diag_items;
	}
}

#ifdef HW_DEBUG
void CAN_InitRxTestAdasFilters()
{
	if (fGetTestAdasMo == 1)
	{
		g_test_adas_filter_config.count = posTestAdasMo;
		g_test_adas_filter_config.active = 1;
		g_test_adas_filter_config.items = g_test_adas_filter_items;
	}
}
#ifdef SW_AURUS
void CAN_InitRxXcpFilters()
{
	if (fGetXcpMo == 1)
	{
		g_xcp_filter_config.count = posXcpMo;
		g_xcp_filter_config.active = 1;
		g_xcp_filter_config.items = g_xcp_items;
	}
}
#endif
#endif
