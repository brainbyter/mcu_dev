#include "xcp_node.h"
#include <xcp.h>
#include <string.h>

#include "bsp_can.h"
#include <CAN_Typedefs.h>

uint32_t Send(uint8_t* data, uint8_t size)
{
	uint32_t ret = 0;
    uint8_t txData[8];

    can_msg_t xcp_msg= {
    		.ide = kCanIdStd,
    		.id = 0x792,
    		.rtr = kCanRtrData,
    		.fdf = kCanFdTypeClassic,
    		.len = size
    };

    memcpy(xcp_msg.data, data, size);

    ret = CanMsgSend(XCP_CAN, &xcp_msg, 1);
    return ret;
}


void XCP_Send(uint8_t* data, uint8_t size)
{
    SendToFIFO(data, size);
}



