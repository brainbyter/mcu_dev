// Copyright @2023 Pony AI Inc. All rights reserved.

#include "iLLD/TC39B/Tricore/Cpu/Std/Ifx_Types.h"
#include "iLLD/TC39B/Tricore/Cpu/Std/IfxCpu.h"
#include "iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.h"

#include "platform/device/bsp/bsp_can.h"

#include <sw_version.h>
#include <CAN_Typedefs.h>
#include <CAN.h>
#include <MRRX_DATA_Handlers.h>
#include "DiagMrr_ext_functions.h"
#include "DiagMrr_ext_vars.h"
#include "MRRX_DATA_Buff.h"
#include "CAN_Extern.h"
#include "MRRX_UDP.h"
#include <interrupt_handlers.h>

extern IfxCpu_syncEvent g_cpu_sync_event;

void canRxInterruptCanMrrxData(void)
{
	can_msg_t rx_msg;
	CanMsgRecv(MRRX_DATA, &rx_msg, 1);

	Mrrx_data_state_buff.buff_lastMessageTime = SystemTime;
	Mrrx_data_state_buff.buff_timeout = FALSE;

	if (Mrrx_data_state_buff.buff_mode_a.buff_mode == is_fill)
	{
		fill_can_message(udp_rr_data_packet+nOfFrame, &rx_msg);
		nOfFrame++;
		Mrrx_data_state_buff.buff_mode_a.buff_num_of_packet = nOfFrame;
	}

	if (nOfFrame >= 100)
	{
		Mrrx_data_state_buff.buff_mode_a.buff_mode = is_full;
	}

	if (rx_msg.id == 0x480)
	{
		Radar_Rear_ADAS_Handler(rx_msg.data, rx_msg.len);
	}
}

void canRxInterruptCanMrrxDiag(void)
{
	can_msg_t rx_msg;
	CanMsgRecv(MRRXCAN_DIAG, &rx_msg, 1);

	Diag_dascu_process_receive(&uds_state_client_mrr, &rx_msg);
	answerMrrxFrame();
}

void core4_main(void)
{
	IfxCpu_enableInterrupts();

	// !!WATCHDOG4 IS DISABLED HERE!!
	// Enable the watchdog and service it periodically if it is required
	IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());

	// Wait for CPU sync event
	IfxCpu_emitEvent(&g_cpu_sync_event);
	IfxCpu_waitEvent(&g_cpu_sync_event, 100);

	while(1)
	{
		if (!fPrepareToFirmware)
		{
			if (diag_process_status.diag_state_rl == isEnable)
			{
				CalibrationRadar(MRR_REAR_LEFT, &diag_process_status.diag_state_rl);
			}

			if (diag_process_status.diag_state_rr == isEnable)
			{
				CalibrationRadar(MRR_REAR_RIGHT, &diag_process_status.diag_state_rr);
			}

			manageStateCalibr();
			manageRequest();

			CAN_ProcessMrrxDiag();
		}
	}
}
