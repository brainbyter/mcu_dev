// Copyright @2023 Pony AI Inc. All rights reserved.

#include "iLLD/TC39B/Tricore/Cpu/Std/Ifx_Types.h"
#include "iLLD/TC39B/Tricore/Cpu/Std/IfxCpu.h"
#include "iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.h"

#include <sw_version.h>

#include "platform/device/bsp/bsp_can.h"
#include <interrupt_handlers.h>
#include <CAN_Typedefs.h>
#include <CAN_Extern.h>
#include "xcp_node.h"

extern IfxCpu_syncEvent g_cpu_sync_event;

extern IfxCpu_syncEvent g_cpu_sync_event;

#ifdef SW_AURUS
#ifdef HW_DEBUG
unsigned int dtConnectXcp = 0;
unsigned char rdyToConnectXcp = 0;
#endif
#endif

#ifdef SW_AURUS
#ifdef HW_DEBUG
void canRxInterruptXcpCan(void)
{
	can_msg_t rx_msg;
	CanMsgRecv(XCP_CAN, &rx_msg, 1);

	if (rx_msg.id == 0x069U)
	{
		rdyToConnectXcp = 1;
		dtConnectXcp = SystemTime;
		return;
	}

	XCP_ProcessMessageTest(rx_msg.data, rx_msg.len);
}
#endif
#endif

void core5_main(void)
{
	IfxCpu_enableInterrupts();

	// !!WATCHDOG5 IS DISABLED HERE!!
	// Enable the watchdog and service it periodically if it is required
	IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());

	// Wait for CPU sync event
	IfxCpu_emitEvent(&g_cpu_sync_event);
	IfxCpu_waitEvent(&g_cpu_sync_event, 100);

	while(1)
	{
#ifdef HW_DEBUG
		if (!fPrepareToFirmware)
		{
			if (fXcpCheck)
			{
				fXcpCheck = 0;
				XCPProcess();
			}

			if (fXcpTxIrqEn)
			{
				fXcpTxIrqEn = 0;
				TxInterrupt();
			}

			if (rdyToConnectXcp != 0)
			{
				if ((SystemTime-dtConnectXcp)>=500 && rdyToConnectXcp == 1)
				{
					can_msg_t test_msg = {
							.ide = kCanIdStd,
							.id = 0x070U,
							.rtr = kCanRtrData,
							.fdf = kCanFdTypeClassic,
							.len = 1
					};
					test_msg.data[0] = 0x01U;
					while (CanMsgSend(XCP_CAN, &test_msg, 1)==0);
					rdyToConnectXcp = 2;
				}
				else if ((SystemTime-dtConnectXcp)>=1000 && rdyToConnectXcp == 2)
				{
					dtConnectXcp = 0;
					rdyToConnectXcp = 0;
					fPrepareToFirmware = 1;
				}
			}
		}
#else
		__nop();
#endif
	}
}
