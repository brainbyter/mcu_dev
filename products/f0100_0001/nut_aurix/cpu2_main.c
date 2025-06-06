// Copyright @2023 Pony AI Inc. All rights reserved.

#include "iLLD/TC39B/Tricore/Cpu/Std/Ifx_Types.h"
#include "iLLD/TC39B/Tricore/Cpu/Std/IfxCpu.h"
#include "iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.h"

#include "platform/device/bsp/bsp_can.h"
#include "platform/system/debug.h"
#include "platform/system/systemtime.h"

#include <sw_version.h>

/* Timer */
#include "timer.h"

/* CAN */
#include <CAN.h>
#include <CAN_Extern.h>
#include <MCMCAN.h>
#include <CAN_Private.h>
#include <CAN_Extern.h>
#include <CAN_PostSettings.h>

/* Simulink */
#include "DASCU/simulink/ADAS/ADAS.h"
#include "DASCU/simulink/vlc/VLCforADAS_UMP.h"

/*Power*/
#include "adc_monitor.h"

/* UDP */
#include "UDP_Extern.h"
#include "UdpHandlers.h"
#include "DASCU/UDP/inc/udp_echoclient.h"

/* MRRX */
#include "MRRX_DATA_Buff.h"
#include "DiagMrr_typedefs.h"
#include "DiagMrr_ext_vars.h"
#include "DiagMrr_ext_functions.h"

/* DIAG */
#include "Diag_typedefs.h"

/* Ext. Vars */
#include "DASCU/ext_vars.h"

/* Events Vars */
#include "TurnInd_event.h"

/* Diag ERAG Vars */
#include "DiagErag_typedefs.h"
#include "DiagErag_ext_vars.h"
#include "DiagErag_ext_functions.h"

#include "ADASCANFD_IDs.h"

#include "FD_Vars.h"
#include "xcp_node.h"

#include <CAN_Typedefs.h>

#include "ERAG.h"

#include <interrupt_handlers.h>

#include <IfxScuRcu.h>

extern IfxCpu_syncEvent g_cpu_sync_event;
unsigned int dtConnectAdas = 0;
unsigned char rdyToConnectAdas = 0;

unsigned char fl_reset_mem = 0;

#define RESET_SRC               APPLICATION_RESET                   /* Macro used to set the type of software reset */
#define APPLICATION_RESET       IfxScuRcu_ResetType_application
#define SYSTEM_RESET            IfxScuRcu_ResetType_system

void triggerSwReset(IfxScuRcu_ResetType resetType);

#ifdef SW_AURUS
void canRxInterruptCanAdas(void)
{
	can_msg_t rx_msg;
	CanMsgRecv(ADASCANFD, &rx_msg, 1);

	flgCanAdasRx = 1;

	/* if Diagnostic Message */
	if (rx_msg.id == Diag_To_DASCU_ID && rx_msg.data[0] == 0x00 && rx_msg.data[7]==0x66)
	{
		rdyToConnectAdas = 1;
		dtConnectAdas = SystemTime;
		return;
	}

	if (rx_msg.id == Diag_To_DASCU_ID && rx_msg.data[0] == 0x00 && rx_msg.data[7]==0x77)
	{
		triggerSwReset(APPLICATION_RESET);
		return;
	}

	if (rx_msg.id == Diag_To_DASCU_ID && rx_msg.data[0] == 0x00 && rx_msg.data[7]==0x88)
	{
		fl_reset_mem = 1;
		return;
	}

	if (rx_msg.id == Diag_To_DASCU_ID)
	{
		Diag_dascu_process_receive(&uds_state_dascu, &rx_msg);
//		answerFrame();
		return;
	}

	if (rx_msg.id == Diag_From_ERAG_ID)
	{
		Diag_dascu_process_receive(&uds_state_client_erag, &rx_msg);
		return;
	}

	unsigned int i=0;

	while (i < ADAS_BUFF_MAX_ITEMS && rxDataAdasBuffer[i].msgNonReadedFromFifo == TRUE)
	{
		i++;
	}

	rxDataAdasBuffer[i].fdf = rx_msg.fdf;
	rxDataAdasBuffer[i].id= rx_msg.id;
	rxDataAdasBuffer[i].ide = rx_msg.ide;
	rxDataAdasBuffer[i].len = rx_msg.len;
	rxDataAdasBuffer[i].rtr= rx_msg.rtr;
	rxDataAdasBuffer[i].msgNonReadedFromFifo = TRUE;
	memcpy(&rxDataAdasBuffer[i].data, rx_msg.data, rx_msg.len);
	g_count_can_adas++;

	unsigned int deep=0;
	unsigned int count_in_fifo=0;

	while ((deep < ADAS_BUFF_MAX_ITEMS) && (count_in_fifo < g_count_can_adas))
	{
		if (rxDataAdasBuffer[deep++].msgNonReadedFromFifo == TRUE)
		{
			count_in_fifo++;
		}
	}

	g_count_can_adas_maxdeep = deep;
}
#endif

#ifdef SW_HAVAL
void canRxInterruptCanHaval(void)
{
	can_msg_t rx_msg;
	CanMsgRecv(HAVAL, &rx_msg, 1);

	unsigned int i=0;

	while (i < ADAS_BUFF_MAX_ITEMS && rxDataAdasBuffer[i].msgNonReadedFromFifo == TRUE)
	{
		i++;
	}

	rxDataAdasBuffer[i].fdf = rx_msg.fdf;
	rxDataAdasBuffer[i].id= rx_msg.id;
	rxDataAdasBuffer[i].ide = rx_msg.ide;
	rxDataAdasBuffer[i].len = rx_msg.len;
	rxDataAdasBuffer[i].rtr= rx_msg.rtr;
	rxDataAdasBuffer[i].msgNonReadedFromFifo = TRUE;
	memcpy(&rxDataAdasBuffer[i].data, rx_msg.data, rx_msg.len);
	g_count_can_adas++;

	unsigned int deep=0;
	unsigned int count_in_fifo=0;

	while ((deep < ADAS_BUFF_MAX_ITEMS) && (count_in_fifo < g_count_can_adas))
	{
		if (rxDataAdasBuffer[deep++].msgNonReadedFromFifo == TRUE)
		{
			count_in_fifo++;
		}
	}

	g_count_can_adas_maxdeep = deep;
}
#endif


unsigned char zero_array[50] = {0};

void core2_main(void)
{
	IfxCpu_enableInterrupts();

	// !!WATCHDOG2 IS DISABLED HERE!!
	// Enable the watchdog and service it periodically if it is required
	IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());

	// Wait for CPU sync event
	IfxCpu_emitEvent(&g_cpu_sync_event);
	IfxCpu_waitEvent(&g_cpu_sync_event, 100);

	while(1)
	{
		if (!fPrepareToFirmware)
		{
			if (fl_reset_mem)
			{
				fl_reset_mem = 0;
				EraseFlash (0xAF000000, 50);
				WriteFlash (0xAF000000, zero_array, 50);
				ReadFlash (0xAF000000, zero_array, 4);
				Printf("%d, %d, %d, %d \n", zero_array[0], zero_array[1], zero_array[2], zero_array[3]);
			}


			CAN_ProcessAutomotive();

			/* FIU */
			if (FIU_ADAS_Config_Handler_dtd)
			{
				FIU_ADAS_Config_Handler_dtd = 0;

				if (FIU_StartSet_Req)
				{
					DAS_FIU_Settings_MO.cycle = 100;
				}
				else
				{
					DAS_FIU_Settings_MO.cycle = 0;
				}
			}

			if (rdyToConnectAdas != 0)
			{
				if ((SystemTime-dtConnectAdas)>=500 && rdyToConnectAdas == 1)
				{
					can_msg_t test_msg = {
							.ide = kCanIdStd,
							.id = 0x7C5U,
							.rtr = kCanRtrData,
							.fdf = kCanFdTypeClassic,
							.len = 8
					};
					test_msg.data[0] = 0x40U;
					test_msg.data[7] = 0x77U;
					while (CanMsgSend(ADASCANFD, &test_msg, 1)==0);
					rdyToConnectAdas = 2;
				}
				else if ((SystemTime-dtConnectAdas)>=1000 && rdyToConnectAdas == 2)
				{
					dtConnectAdas = 0;
					rdyToConnectAdas = 0;
					fPrepareToFirmware = 1;
				}
			}

	//		manageRequestDascu();
		}
	}
}

void triggerSwReset(IfxScuRcu_ResetType resetType)
{
    /* Get the CPU EndInit password */
    uint16 CPUEndinitPw = IfxScuWdt_getCpuWatchdogPassword();

    /* Configure the request trigger in the Reset Configuration Register */
    IfxScuRcu_configureResetRequestTrigger(IfxScuRcu_Trigger_sw, resetType);

    /* Clear CPU EndInit protection to write in the SWRSTCON register of SCU */
    IfxScuWdt_clearCpuEndinit(CPUEndinitPw);

    /* Trigger a software reset based on the configuration of RSTCON register */
    IfxCpu_triggerSwReset();

    /* The following instructions are not executed if a SW reset occurs */
    /* Set CPU EndInit protection */
    IfxScuWdt_setCpuEndinit(CPUEndinitPw);
}

