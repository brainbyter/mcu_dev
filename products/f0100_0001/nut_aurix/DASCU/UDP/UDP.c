#include "Platform_Types.h"
#include "UDP_Typedefs.h"
#include "UDP_Extern.h"
#include <stdint.h>
#include "CAN_Extern.h"
#include "bsp_can.h"
#include <f0100_03_0001_aurix_driver.h>
#include "CAN_Private.h"
#include <math.h>

UdpMessageObject_t *lastUdpMessageObject = 0;


void UDP_InitMessageObject(UdpMessageObject_t* UdpMessageObj)
{
    if (!((UdpMessageObj->dir == ToGpu) && (UdpMessageObj->cycle == 0)))
    {
        UdpMessageObj->prevUdpMessageObj = lastUdpMessageObject;
        lastUdpMessageObject = UdpMessageObj;
    }

    UdpMessageObj->lastMessageTime = 0;

    static unsigned char voidTimeout = 1;

    if(UdpMessageObj->pTimeout == 0)
    {
        UdpMessageObj->pTimeout = &voidTimeout;
    }
}


void readUdpPacket(uint8 id, uint8 *data, uint8 len)
{
    UdpMessageObject_t* UdpMessageObject = lastUdpMessageObject;

    while(UdpMessageObject)
    {
        if (id == UdpMessageObject->ID)
        {
        	//if (len == UdpMessageObject->DLC)
        	//{
        		if (UdpMessageObject->handler != 0)
        		{
        			UdpMessageObject->handler(data);
        		}

        		*UdpMessageObject->pTimeout = 0;
        		UdpMessageObject->lastMessageTime = SystemTime;
        		break;
        //	}
        }

        UdpMessageObject = UdpMessageObject->prevUdpMessageObj;
    }
}

float udpIsNan(float val)
{
	if (isnan(val))
	{
		return 202.0f;
	}

	return val;
}
