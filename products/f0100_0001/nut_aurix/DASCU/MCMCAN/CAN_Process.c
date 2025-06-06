#include "CAN_Private.h"
#include "CAN.h"
#include "CAN_Extern.h"
#include "MCMCAN.h"
#include "bsp_can.h"
#include "f0100_03_0001_aurix_driver.h"
#include "sw_version.h"

void CAN_TransmitAutomotivePeriodicalFrame(CanMessageObject_t* messageObj);
void CAN_TransmitDebugPeriodicalFrame(CanMessageObject_t* messageObj);
void CAN_TransmitMrrxDiagPeriodicalFrame(CanMessageObject_t* messageObj);
void checkFifoAdas();
void checkFifoAdasDebug();


void checkFifoAdas()
{
	can_msg_t *rxBuff = &rxDataAdasBuffer[ADAS_BUFF_MAX_ITEMS-1];
	int i=(ADAS_BUFF_MAX_ITEMS);
	int cnt = 0;

	while(i)
	{
		if (rxBuff->msgNonReadedFromFifo == TRUE)
		{
			cnt++;
		}

		i--;

		if (i > 0)
		{
			rxBuff--;
		}
	}

	if (cnt != g_count_can_adas)
	{
		g_count_can_adas = cnt;
	}
}

void checkFifoAdasDebug()
{
	can_msg_t *rxBuff = &rxDataTestAdasBuffer[DEBUG_BUFF_MAX_ITEMS-1];
	int i=(DEBUG_BUFF_MAX_ITEMS);
	int cnt = 0;

	while(i)
	{
		if (rxBuff->msgNonReadedFromFifo == TRUE)
		{
			cnt++;
		}

		i--;

		if (i > 0)
		{
			rxBuff--;
		}
	}

	if (cnt != g_count_can_test_adas)
	{
		g_count_can_test_adas = cnt;
	}
}


void CAN_ProcessAutomotive()
{
	CanMessageObject_t* MessageObject = lastMessageObjectAurus;

	g_await_count_can_adas_maxdeep = g_count_can_adas_maxdeep;

	unsigned char flgNeedCheckFifo = 0;

	while(MessageObject)
	{
		switch (MessageObject->dir)
		{
		case TX:
#ifdef PWR_MAN_EN
			if (BCM_ADASTerm_Stat > 0)
			{
				CAN_TransmitAutomotivePeriodicalFrame(MessageObject);
			}
#else
			CAN_TransmitAutomotivePeriodicalFrame(MessageObject);
#endif

			break;

		case RX:
			if (g_count_can_adas)
			{
				CAN_ReceiveSdkFrameAdas(MessageObject);
			}

			unsigned char timeout = 0;

			if (MessageObject->cycle != 0)
			{
				if  ((SystemTime - MessageObject->lastMessageTime) > (MessageObject->cycle * MessageObject->countCycleTimeout))
				{
					timeout = 1;
				}

				//if (timeout && (MessageObject->failHandler != 0))
				if (timeout && !*MessageObject->pTimeout && (MessageObject->failHandler != 0))
				{
					MessageObject->failHandler();
				}

				*MessageObject->pTimeout |= timeout;
			}


			break;

		default:
			break;
		}

		MessageObject = MessageObject->prevMessageObj;

		if (flgCanAdasRx)
		{
			flgCanAdasRx = 0;
			flgNeedCheckFifo = 1;
		}
	}

	if (flgNeedCheckFifo)
	{
		checkFifoAdas();
	}
}

#ifdef HW_DEBUG
void CAN_ProcessDebug(void)
{
	CanMessageObject_t* MessageObject = lastMessageObjectDebug;

	g_await_count_can_test_adas_maxdeep = g_count_can_test_adas_maxdeep;

	unsigned char flgNeedCheckFifo = 0;

	while(MessageObject)
	{
		switch (MessageObject->dir)
		{
		case TX:
			CAN_TransmitDebugPeriodicalFrame(MessageObject);
			break;

		case RX:
			if (g_count_can_test_adas)
			{
				CAN_ReceiveSdkFrameTestAdas(MessageObject);
			}

			unsigned char timeout = 0;

			//boolean timeout = ((SystemTime - MessageObject->lastMessageTime) > (MessageObject->cycle * MessageObject->countCycleTimeout));
			if (MessageObject->cycle != 0)
			{
				if  ((SystemTime - MessageObject->lastMessageTime) > (MessageObject->cycle * MessageObject->countCycleTimeout))
				{
					timeout = 1;
				}

				if (timeout && !*MessageObject->pTimeout && (MessageObject->failHandler != 0))
				{
					MessageObject->failHandler();
				}

				*MessageObject->pTimeout |= timeout;
			}

			break;

		default:
			break;
		}

		MessageObject = MessageObject->prevMessageObj;

		if (flgCanAdasDebugRx)
		{
			flgCanAdasDebugRx = 0;
			flgNeedCheckFifo = 1;
		}
	}

	if (flgNeedCheckFifo)
	{
		checkFifoAdasDebug();
	}
}
#endif

void CAN_ProcessMrrxDiag()
{
	CanMessageObject_t* MessageObject = lastMessageObjectMrrxDiag;

	while(MessageObject)
	{
		switch (MessageObject->dir)
		{
		case TX:
			CAN_TransmitMrrxDiagPeriodicalFrame(MessageObject);
			break;

		default:
			break;
		}

		MessageObject = MessageObject->prevMessageObj;
	}
}



void CAN_TransmitFrame(CanMessageObject_t* messageObj, uint8* data)
{
	if(messageObj->prepareHandler != 0)
    {
		messageObj->prepareHandler();
    }

    if(messageObj->handler != 0)
    {
    	messageObj->handler(data, messageObj->DLC);
    }

    can_msg_t txSingleMsg =
    {
    		.ide = kCanIdStd,
			.id = messageObj->ID,
			.rtr = kCanRtrData,
			.fdf = messageObj->FD ? kCanFdTypeCanFd: kCanFdTypeClassic,
			.len = messageObj->DLC
    };

	memcpy(txSingleMsg.data, data, messageObj->DLC);

	//CanMsgSend(messageObj->network, &txSingleMsg, 1);
	while(!CanMsgSend(messageObj->network, &txSingleMsg, 1));
}



void CAN_TransmitAutomotivePeriodicalFrame(CanMessageObject_t* messageObj)
{
	if (((SystemTime - messageObj->lastMessageTime) >= messageObj->cycle) && messageObj->cycle != 0)
	{
		uint8 txd[64];
		uint32 id = messageObj->ID;
		uint8 fdf = messageObj->FD ? kCanFdTypeCanFd: kCanFdTypeClassic;
		uint8 dlc = messageObj->DLC;

		if (messageObj->txOk)
		{
			if(messageObj->prepareHandler != 0)
			{
				messageObj->prepareHandler();
			}
		}

		if(messageObj->handler != 0)
		{
			messageObj->handler(txd, messageObj->DLC);
		}

		if(messageObj->diagHandler != 0)
		{
			messageObj->diagHandler(txd, messageObj->DLC);
		}

		can_msg_t tx_msg = {
				.ide = kCanIdStd,
				.id = id,
				.rtr = kCanRtrData,
				.fdf = fdf,
				.len = dlc
		};

		memcpy(tx_msg.data, txd, dlc);

		//CanMsgSend(ADASCANFD, &tx_msg, 1);
		//while(!CanMsgSend(ADASCANFD, &tx_msg, 1));

		if (CanMsgSend(ADASCANFD, &tx_msg, 1))
		{
			messageObj->txOk = 1;
			messageObj->lastMessageTime = SystemTime;
		}
		else
		{
			messageObj->txOk = 0;
		}

//		messageObj->lastMessageTime = SystemTime;
	}
}

#ifdef HW_DEBUG
void CAN_TransmitDebugPeriodicalFrame(CanMessageObject_t* messageObj)
{
	if (((SystemTime - messageObj->lastMessageTime) >= messageObj->cycle) && messageObj->cycle != 0)
	{
		uint8 txd[64];
		uint32 id = messageObj->ID;
		uint8 fdf = messageObj->FD ? kCanFdTypeCanFd: kCanFdTypeClassic;
		uint8 dlc = messageObj->DLC;

		if (messageObj->txOk)
		{
			if(messageObj->prepareHandler != 0)
			{
				messageObj->prepareHandler();
			}
		}

		if(messageObj->handler != 0)
		{
			messageObj->handler(txd, messageObj->DLC);
		}

		if(messageObj->diagHandler != 0)
		{
			messageObj->diagHandler(txd, messageObj->DLC);
		}

		can_msg_t tx_msg = {
				.ide = kCanIdStd,
				.id = id,
				.rtr = kCanRtrData,
				.fdf = fdf,
				.len = dlc
		};

		memcpy(tx_msg.data, txd, dlc);

		//CanMsgSend(FD, &tx_msg, 1);
//		while(!CanMsgSend(FD, &tx_msg, 1));

		if (CanMsgSend(FD, &tx_msg, 1))
		{
			messageObj->txOk = 1;
			messageObj->lastMessageTime = SystemTime;
		}
		else
		{
			messageObj->txOk = 0;
		}

//		messageObj->lastMessageTime = SystemTime;
	}
}
#endif

void CAN_TransmitMrrxDiagPeriodicalFrame(CanMessageObject_t* messageObj)
{
	if (((SystemTime - messageObj->lastMessageTime) >= messageObj->cycle) && messageObj->cycle != 0)
	{
		uint8 txd[64];
		uint32 id = messageObj->ID;
		uint8 fdf = messageObj->FD ? kCanFdTypeCanFd: kCanFdTypeClassic;
		uint8 dlc = messageObj->DLC;

		if(messageObj->handler != 0)
		{
		    messageObj->handler(txd, messageObj->DLC);
		}

		can_msg_t tx_msg = {
				.ide = kCanIdStd,
				.id = id,
				.rtr = kCanRtrData,
				.fdf = fdf,
				.len = dlc
		};

		memcpy(tx_msg.data, txd, dlc);

		//CanMsgSend(MRRXCAN_DIAG, &tx_msg, 1);
//		while(!CanMsgSend(MRRXCAN_DIAG, &tx_msg, 1));

		if (CanMsgSend(MRRXCAN_DIAG, &tx_msg, 1))
		{
			messageObj->txOk = 1;
			messageObj->lastMessageTime = SystemTime;
		}
		else
		{
			messageObj->txOk = 0;
		}


//		messageObj->lastMessageTime = SystemTime;
	}
}

void CAN_ReceiveSdkFrameAdas(CanMessageObject_t* messageObj)
{
	can_msg_t *rxBuff = &rxDataAdasBuffer[0];

	for (unsigned int pos=0; pos < g_await_count_can_adas_maxdeep; pos++)
	{
		if (rxBuff->msgNonReadedFromFifo == TRUE && messageObj->ID == rxBuff->id)
		{
			rxBuff->msgNonReadedFromFifo = FALSE;
			*messageObj->pTimeout = 0;
			messageObj->lastMessageTime = SystemTime;

			if (messageObj->handler != 0)
			{
				messageObj->handler(rxBuff->data, messageObj->DLC);
			}

			g_count_can_adas--;
			break;
		}
		rxBuff++;
	}
}
#ifdef HW_DEBUG
void CAN_ReceiveSdkFrameTestAdas(CanMessageObject_t* messageObj)
{
	can_msg_t *rxBuff = &rxDataTestAdasBuffer[0];

	for (unsigned int pos=0; pos < g_await_count_can_test_adas_maxdeep; pos++)
	{
		if (rxBuff->msgNonReadedFromFifo == TRUE && messageObj->ID == rxBuff->id)
		{
			rxBuff->msgNonReadedFromFifo = FALSE;
			*messageObj->pTimeout = 0;
			messageObj->lastMessageTime = SystemTime;

			if (messageObj->handler != 0)
			{
				messageObj->handler(rxBuff->data, messageObj->DLC);
			}

			g_count_can_test_adas--;
			break;
		}
		rxBuff++;
	}
}
#endif

int DEBUG_CAN(uint16 can_device, can_msg_t *can_msg)
{
	int res = 0;

//	CanMsgSend(can_device, can_msg, 1);
	while(!CanMsgSend(can_device, can_msg, 1));
	return res;
}
