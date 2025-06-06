#include "UDP_Typedefs.h"
#include "UDP_IC_Typedefs.h"
#include "UDP_Extern.h"
#include "CAN_Extern.h"
#include "../inc/udp_echoclient.h"
#include <bsp_can.h>
#include <CAN_Mapping.h>
#include <string.h>
#include <../MCMCAN/Generated/CAN.h>
#include <UDP_IC_MessageObjects.h>


void UDP_TransmitPeriodicalPacketIC()
{
	unsigned char txUdpData[100];

//	if (((SystemTime - UDP_IC_Visual_MO.lastMessageTime) >= UDP_IC_Visual_MO.cycle) && UDP_IC_Visual_MO.cycle != 0)
	{
		uint16 dlc = (uint16)UDP_IC_Visual_MO.DLC;

	    // Fill Data
		UDP_IC_Visual_MO.handler(txUdpData);

		UDP_IC_Visual_MO.lastMessageTime = SystemTime;

	    /* SEND to IC; IP = 192.168.1.xx */
	    UdpSendPacket(udp_socket_ic_dst, txUdpData, dlc);
	}
}




void UDP_Process()
{
	UdpMessageObject_t* UdpMessageObject = lastUdpMessageObject;

	while(UdpMessageObject)
	{
		if(UdpMessageObject->dir == FromGpu)
		{
			UDP_ReceivePacket(UdpMessageObject);
		}

		if(UdpMessageObject->dir == ToGpu)
		{
		    UDP_TransmitPeriodicalFrame(UdpMessageObject);
		}

		UdpMessageObject = UdpMessageObject->prevUdpMessageObj;
	}
}


void UDP_TransmitPeriodicalFrame(UdpMessageObject_t* UdpMessageObj)
{
	unsigned char txUdpData[1024];

    if (((SystemTime - UdpMessageObj->lastMessageTime) >= UdpMessageObj->cycle) && UdpMessageObj->cycle != 0)
    {
        uint8 id = (uint8)UdpMessageObj->ID;
        uint16 dlc = (uint16)UdpMessageObj->DLC;

        if(UdpMessageObj->prepareHandler != 0)
        {
            UdpMessageObj->prepareHandler();
        }

        // Fill Id in First Byte
        txUdpData[0] = id;

        // Fill Data
        if(UdpMessageObj->handler != 0)
        {
            UdpMessageObj->handler(&txUdpData[1]);
        }

        // RC to LAST byte
        txUdpData[dlc-1] = *UdpMessageObj->pRC & 0x0F;

        UdpMessageObj->lastMessageTime = SystemTime;

        /* SEND to GPU */
        UdpSendPacket(udp_socket_dst, txUdpData, dlc);

        /* SEND to DEBUG PC; IP = 192.168.1.10 */
        UdpSendPacket(udp_socket_dst_debug_pc, txUdpData, dlc);
    }
}


void UDP_ReceivePacket(UdpMessageObject_t* UdpMessageObj)
{
    unsigned char timeout = ((SystemTime - UdpMessageObj->lastMessageTime) > (UdpMessageObj->cycle * UdpMessageObj->countCycleTimeout));

    if (timeout && !*UdpMessageObj->pTimeout && (UdpMessageObj->failHandler != 0))
    {
        UdpMessageObj->failHandler();
    }

    *UdpMessageObj->pTimeout |= timeout;
}

void UDP_TransmitFrame(UdpMessageObject_t* UdpMessageObj)
{
	uint8 txUdpSingleData[1024];
	//memset(txUdpSingleData, 0x00, 1024);

	uint8 id = (uint8)UdpMessageObj->ID;
	uint16 dlc = (uint16)UdpMessageObj->DLC;

	if(UdpMessageObj->prepareHandler != 0)
	{
		UdpMessageObj->prepareHandler();
	}

	// Fill Id in First Byte
	txUdpSingleData[0] = id;

	// Fill Data
	if(UdpMessageObj->handler != 0)
	{
		UdpMessageObj->handler(&txUdpSingleData[1]);
	}

	// RC to LAST byte
	txUdpSingleData[dlc-1] = *UdpMessageObj->pRC & 0x0F;

	/* SEND to DEBUG_PC; IP = 192.168.1.10*/
	//UdpSendPacket(udp_socket_dst_debug_pc, txUdpSingleData, dlc);

	/* SEND to GPU */
	UdpSendPacket(udp_socket_dst, txUdpSingleData, dlc);
}
