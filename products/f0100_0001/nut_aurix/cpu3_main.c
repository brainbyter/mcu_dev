// Copyright @2023 Pony AI Inc. All rights reserved.

#include "iLLD/TC39B/Tricore/Cpu/Std/Ifx_Types.h"
#include "iLLD/TC39B/Tricore/Cpu/Std/IfxCpu.h"
#include "iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.h"

#include "platform/device/bsp/bsp_can.h"
#include <sw_version.h>
#include "DASCU/MCMCAN/Generated/CAN.h"
#include <CAN_Extern.h>
#include <MCMCAN.h>
#include "FD_MessageObjects.h"
#include <sw_version.h>
#include <interrupt_handlers.h>

#include <ADASCANFD_MessageObjects.h>

#include <UDP_Extern_vars.h>

extern IfxCpu_syncEvent g_cpu_sync_event;

#ifdef HW_DEBUG
unsigned char rdyToConnectDebug = 0;
unsigned int dtConnectDebug = 0;
#endif

#ifdef HW_DEBUG
#ifdef SW_AURUS
void canRxInterruptCanTestAdas(void)
{
	can_msg_t rx_msg;
	CanMsgRecv(FD, &rx_msg, 1);

	flgCanAdasDebugRx = 1;

	if (rx_msg.id == 0x069U)
	{
		rdyToConnectDebug = 1;
		dtConnectDebug = SystemTime;
		return;
	}

	if (rx_msg.id == 0x6E5)
	{
		DiagGpuReq_MO.handler(rx_msg.data, 8);
		return;
	}

	unsigned int i=0;

	while (i < DEBUG_BUFF_MAX_ITEMS && rxDataTestAdasBuffer[i].msgNonReadedFromFifo == TRUE)
	{
		i++;
	}

	rxDataTestAdasBuffer[i].fdf = rx_msg.fdf;
	rxDataTestAdasBuffer[i].id = rx_msg.id;
	rxDataTestAdasBuffer[i].ide = rx_msg.ide;
	rxDataTestAdasBuffer[i].len = rx_msg.len;
	rxDataTestAdasBuffer[i].rtr = rx_msg.rtr;
	rxDataTestAdasBuffer[i].msgNonReadedFromFifo = TRUE;
	memcpy(&rxDataTestAdasBuffer[i].data, rx_msg.data, rx_msg.len);
	g_count_can_test_adas++;

	unsigned int deep=0;
	unsigned int count_in_fifo=0;

	while ((deep < DEBUG_BUFF_MAX_ITEMS) && (count_in_fifo < g_count_can_test_adas))
	{
		if (rxDataTestAdasBuffer[deep++].msgNonReadedFromFifo == TRUE)
		{
			count_in_fifo++;
		}
	}

	g_count_can_test_adas_maxdeep = deep;
}
#endif
#endif

void core3_main(void)
{
	IfxCpu_enableInterrupts();

	// !!WATCHDOG3 IS DISABLED HERE!!
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
			CAN_ProcessDebug();

			if (rdyToConnectDebug != 0)
			{
				if ((SystemTime-dtConnectDebug)>=500 && rdyToConnectDebug == 1)
				{
					can_msg_t test_msg = {
							.ide = kCanIdStd,
							.id = 0x070U,
							.rtr = kCanRtrData,
							.fdf = kCanFdTypeClassic,
							.len = 1
					};
					test_msg.data[0] = 0x01U;
					while (CanMsgSend(FD, &test_msg, 1)==0);
					rdyToConnectDebug = 2;
				}
				else if ((SystemTime-dtConnectDebug)>=1000 && rdyToConnectDebug == 2)
				{
					dtConnectDebug = 0;
					rdyToConnectDebug = 0;
					fPrepareToFirmware = 1;
				}
			}
		}
#else
		__nop();
#endif
	}
}
