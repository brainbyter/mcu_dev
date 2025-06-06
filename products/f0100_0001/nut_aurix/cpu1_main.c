// Copyright @2023 Pony AI Inc. All rights reserved.

#include "iLLD/TC39B/Tricore/Cpu/Std/Ifx_Types.h"
#include "iLLD/TC39B/Tricore/Cpu/Std/IfxCpu.h"
#include "iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.h"

#include "products/f0100_0001/nut_aurix/app/power.h"
#include <CAN_Extern.h>
#include <bsp_can.h>
#include <CAN_Typedefs.h>

#include <sw_version.h>

#include <Diag_typedefs.h>

/*Power*/
#include "adc_monitor.h"

/* UDP */
#include "UDP_Extern.h"

/* CAN */
#include <CAN.h>

/* Simulink */
#include "DASCU/simulink/ADAS/ADAS.h"
#include "DASCU/simulink/vlc/VLCforADAS_UMP.h"

#include "ERAG.h"
#include <CAN_PostSettings.h>

#include "DASCU/ext_vars.h"

extern IfxCpu_syncEvent g_cpu_sync_event;
float adc_volt = 0.0;
pwr_awu_mode_t pwr_awu_mode = {.pwr_state = pwr_idle_state, .currTick = 0};

void core1_main(void)
{
	IfxCpu_enableInterrupts();
	// !!WATCHDOG1 IS DISABLED HERE!!
	// Enable the watchdog and service it periodically if it is required
	IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());

	// Wait for CPU sync event
	IfxCpu_emitEvent(&g_cpu_sync_event);
	IfxCpu_waitEvent(&g_cpu_sync_event, 100);

	while(1)
	{
		if (!fPrepareToFirmware)
		{
			if (fVlcStep)
			{
				VLCforADAS_UMP_step();
				fVlcStep = 0;
			}

			if (fAdasStep)
			{
				fAdasStep = 0;
				ADAS_step();

				flgModelOut = 1;
			}

			if (g_fNMEA)
			{
				handlerMes();
			}
			SetDefault_ERAG_NMEA();

			/* AA State Switch TEST */
			AASwitch();

			/* Turn Indicator Process (forming level signal for MRRX) */
			TurnIndLeft_process();
			TurnIndRight_process();
			refreshTurnState();

			/* ERAG SOS Call Management*/
			manageEragRequest();
			configEragSos();
			eragDiagState();

			/*
			if (fUdsProcess)
			{
				fUdsProcess = 0;

				if (uds_state_dascu.frame_status.flg_request == isRequest || uds_state_dascu.frame_status.FC_reqEn==1)
				{
					uds_state_dascu.frame_status.flg_request = isIdle;
					uds_state_dascu.frame_status.FC_reqEn = 0;
					answerFrame(&uds_state_dascu);
				}

				//routineSendImage(&uds_state_dascu);
			}
			*/
/*
			if (fAdcStep)
			{
				fAdcStep = 0;
				while (GetAdcVoltageById(kKl30In1Flt, &adc_volt) != ERROR_OK);
			}
*/
			/*
			if (fPowerManagement)
			{
				if (pwr_awu_mode.pwr_state == pwr_idle_state)
				{
					if (adc_volt >= 12.5)
					{
						pwr_awu_mode.pwr_state = pwr_turnon_state;
						PowerOnOrinA();
						pwr_awu_mode.currTick = 3000;
					}
				}
				else if (pwr_awu_mode.pwr_state == pwr_turnoff_state)
				{
					if (adc_volt > 12.5)
					{
						pwr_awu_mode.currTick+=250;

						if (pwr_awu_mode.currTick >= 3000)
						{
							pwr_awu_mode.pwr_state = pwr_turnon_state;
							PowerOnOrinA();
						}
					}
				}
				else if (pwr_awu_mode.pwr_state == pwr_turnon_state)
				{
					if (adc_volt < 12.3)
					{
						if (adc_volt < 10)
						{
							pwr_awu_mode.pwr_state = pwr_turnoff_state;
							pwr_awu_mode.currTick = 0;
							PowerOffOrinA();
						}
						else
						{
							pwr_awu_mode.currTick-=250;

							if (pwr_awu_mode.currTick <= 0)
							{
								pwr_awu_mode.pwr_state = pwr_turnoff_state;
								PowerOffOrinA();
							}
						}
					}
					else
					{
						if (pwr_awu_mode.currTick < 3000 )
						{
							pwr_awu_mode.currTick = 3000;
						}
					}
				}

				fPowerManagement = 0;
			}
			*/
		}
	}
}
