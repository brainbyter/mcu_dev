// Copyright @2023 Pony AI Inc. All rights reserved.

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "iLLD/TC39B/Tricore/Cpu/Std/Ifx_Types.h"
#include "iLLD/TC39B/Tricore/Cpu/Std/IfxCpu.h"
#include "iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.h"

#include "common/driver/bootchain/bootchain.h"
#include "common/mcu/system/init.h"
#include "platform/device/bsp/bsp_cpu.h"
#include "platform/device/bsp/bsp_delay.h"
#include "platform/device/bsp/bsp_gpio.h"
#include "platform/device/bsp/bsp_i2c.h"
#include "platform/device/bsp/bsp_spi.h"
#include "platform/device/bsp/bsp_timer.h"
#include "platform/device/bsp/bsp_uart.h"
#include "platform/device/driver/bootloader/ab_loader_main.h"
#include "platform/device/driver/bootloader/boot_control_ab.h"
#include "platform/device/driver/bootloader/loader_main.h"
#include "platform/device/driver/infineon/tlf35584.h"
#include "platform/device/driver/led.h"
#include "platform/device/driver/lwip/netif/ethernetif.h"
#include "platform/device/driver/ti/tca9539_q1.h"
#include "platform/product/common/pony_driver.h"
#include "platform/product/common/pony_system.h"
#include "platform/protocol/router.h"
#include "platform/system/debug.h"
#include "platform/system/systemtime.h"
#include "products/f0100_0001/aurix_a/app/camera_trigger.h"
#include "products/f0100_0001/aurix_a/app/config.h"
#include "products/f0100_0001/aurix_a/app/eeprom.h"
#include "products/f0100_0001/aurix_a/app/ethernet.h"
#include "products/f0100_0001/aurix_a/app/led.h"
#include "products/f0100_0001/aurix_a/app/rtc.h"
#include "products/f0100_0001/aurix_a/app/switch_flash.h"
#include "products/f0100_0001/aurix_a/app/tcp_cli_print.h"
#include "products/f0100_0001/aurix_a/app/temperature.h"
#include "products/f0100_0001/aurix_a/app/tlf35584.h"
#include "products/f0100_0001/aurix_a/app/version.h"
#include "products/f0100_0001/aurix_a/sdk/can_bridge_demo.h"
#include "products/f0100_0001/aurix_a/sdk/network.h"
#include "products/f0100_0001/nut_aurix/app/bootchain.h"
#include "products/f0100_0001/nut_aurix/app/cli.h"
#include "products/f0100_0001/nut_aurix/app/power.h"
#ifndef ELMOS_SDK_DISABLE
#include "products/f0100_0001/aurix_a/app/elmos.h"
#endif

#include <sw_version.h>

/* Timer */
#include "products/f0100_0001/aurix_a/sdk/timer.h"

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
#include "DASCU/UDP/inc/udp_echoclient.h"
#include <UDP_Extern.h>
#include <UdpHandlers.h>
#include <UDP_Postsettings.h>

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

/* XCP */
#include <xcp.h>
#include <xcp_node.h>

#include <CAN_Typedefs.h>
#include <interrupt_handlers.h>

#include "DASCU/events/MRRX_UDP/MRRX_UDP.h"

#include "pwr_mngmnt.h"

#include "memfiu.h"

uint8 fPrepareToFirmware = 0;
volatile uint8 fAdasStep = 0;      // every 50 ms call model from ADAS_Step() function
volatile uint8 fVlcStep = 0;      // every 10 ms call model from ADAS_Step() function
volatile uint8 fAdcStep = 0;
volatile uint8 fPowerManagement = 0;
volatile uint8 fMrrxDataSendUdp = 0;
volatile uint8 fMrrxDiag = 0;
volatile uint8 fUdsProcess = 0;
volatile uint8 fXcpCheck = 0;
volatile uint8 fUdpProcess = 0;
volatile uint8 fDiagCanBusState = 0;

volatile uint8 flgCanAdasRx = 0;
volatile uint8 flgCanAdasDebugRx = 0;



unsigned char flgModelOut = 0;

//void readFlashConfig();
//void writeFlashConfig();
//void parseConfigData();

/* This interrupt is raised by the STM0 */

IFX_ALIGN(4) IfxCpu_syncEvent g_cpu_sync_event = 0;

static const uint32_t kCountToMarkSuccessfullBoot = 3;

static const char* kGreetingsPicture = "\r\n"
"\r\n"
"< Greetings from F0100_0001 Nut Aurix! >\r\n"
"\r\n"
" \\     _^^\r\n"
"  \\  _- 6789\\\r\n"
"     \\----- \\______\r\n"
"           \\       )\\\r\n"
"           ||-----|| \\\r\n"
"           ||     ||\r\n";

static void StartLoaderHandler(void) { SetLedLevel(kLedIsUpdating); }

static void StopLoaderHandler(void) { SetLedLevel(kLedNormal); }

#if defined(AB_LOADER_FIRMWARE_SLOT_A)
static const Slot kCurrentSlot = kSlotA;
#endif

#if defined(AB_LOADER_FIRMWARE_SLOT_B)
static const Slot kCurrentSlot = kSlotB;
#endif

static pony_loader_ops_t g_local_loader_ops = {
  APP_INFO_ADDRESS, StartLoaderHandler, NULL, StopLoaderHandler, APP_START_ADDRESS,};

extern Tlf35584 g_tlf35584;

static void BoardGpioInit(void) {
  PONY_ASSERT(SetGpioMode(ORINA_PRE_PWR_PG, PIN_MODE_INPUT) == ERROR_OK);
  PONY_ASSERT(SetGpioMode(AURIXA_ORIN_SMU_FSP1, PIN_MODE_OUTPUT) == ERROR_OK);
  WriteGpio(AURIXA_ORIN_SMU_FSP1, PIN_LOW);
  PONY_ASSERT(SetGpioMode(CAN2_STANDBY_PIN_CTL, PIN_MODE_OUTPUT) == ERROR_OK);
  WriteGpio(CAN2_STANDBY_PIN_CTL, PIN_LOW);
  PONY_ASSERT(SetGpioMode(CAN3_STANDBY_PIN_CTL, PIN_MODE_OUTPUT) == ERROR_OK);
  WriteGpio(CAN3_STANDBY_PIN_CTL, PIN_LOW);
  PONY_ASSERT(SetGpioMode(CAN4_STANDBY_PIN_CTL, PIN_MODE_OUTPUT) == ERROR_OK);
  WriteGpio(CAN4_STANDBY_PIN_CTL, PIN_LOW);
  PONY_ASSERT(SetGpioMode(CANX_STANDBY_PIN_CTL, PIN_MODE_OUTPUT) == ERROR_OK);
  WriteGpio(CANX_STANDBY_PIN_CTL, PIN_LOW);
  PONY_ASSERT(SetGpioMode(AK_USS1_DOUT, PIN_MODE_OUTPUT) == ERROR_OK);
  PONY_ASSERT(SetGpioMode(AK_USS2_DOUT, PIN_MODE_OUTPUT) == ERROR_OK);
  WriteGpio(AK_USS2_DOUT, PIN_LOW);
  WriteGpio(AK_USS1_DOUT, PIN_LOW);
  PONY_ASSERT(SetGpioMode(GMSL_TRIGGER1, PIN_MODE_OUTPUT) == ERROR_OK);
  WriteGpio(GMSL_TRIGGER1, PIN_HIGH);
  PONY_ASSERT(SetGpioMode(GMSL_TRIGGER2, PIN_MODE_OUTPUT) == ERROR_OK);
  WriteGpio(GMSL_TRIGGER2, PIN_HIGH);
  PONY_ASSERT(SetGpioMode(GMSL_TRIGGER3, PIN_MODE_OUTPUT) == ERROR_OK);
  WriteGpio(GMSL_TRIGGER3, PIN_HIGH);
  PONY_ASSERT(SetGpioMode(GMSL_TRIGGER4, PIN_MODE_OUTPUT) == ERROR_OK);
  WriteGpio(GMSL_TRIGGER4, PIN_HIGH);
}

#ifdef SW_AURUS
can_data_ready_callback_t data_ready_callback_can_adas = {.callback=canRxInterruptCanAdas};
#endif
#ifdef SW_HAVAL
can_data_ready_callback_t data_ready_callback_haval = {.callback=canRxInterruptCanHaval};
#endif
can_data_ready_callback_t data_ready_callback_mrrx_diag = {.callback=canRxInterruptCanMrrxDiag};
can_data_ready_callback_t data_ready_callback_mrrx_data = {.callback=canRxInterruptCanMrrxData};
#ifdef HW_DEBUG
can_data_ready_callback_t data_ready_callback_can_test_adas = {.callback=canRxInterruptCanTestAdas};
#ifdef SW_AURUS
can_data_ready_callback_t data_ready_callback_xcp_rx = {.callback=canRxInterruptXcpCan};
#endif
#endif

unsigned char tcp_connected = 0;
unsigned int dtResetOrin = 0;
unsigned char stateResetOrin = 0;


#ifdef HW_DEBUG
#ifdef SW_AURUS
CANNetworkID_t CANNetworkList[5] = {
#endif
#ifdef SW_HAVAL
CANNetworkID_t CANNetworkList[4] = {
#endif
#else
CANNetworkID_t CANNetworkList[3] = {
#endif
#ifdef SW_AURUS
ADASCANFD,
#endif
#ifdef SW_HAVAL
HAVAL,
#endif
#ifdef HW_DEBUG
FD,
#ifdef SW_AURUS
XCP_CAN,
#endif
#endif
MRRX_DATA,
MRRXCAN_DIAG
};

void RecoverBusOff(CANNetworkID_t CANNetwork);

void core0_main(void)
{
	IfxCpu_enableInterrupts();
	IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
	IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());

	// Wait for CPU sync event
	IfxCpu_emitEvent(&g_cpu_sync_event);
	IfxCpu_waitEvent(&g_cpu_sync_event, 100);

	InitialSetup();
	Printf("%s\r\n", kGreetingsPicture);

	InitSystemTime();
	BoardGpioInit();
	InitBootChain();
	InitEeprom();

#ifndef ELMOS_SDK_DISABLE
	InitElmos();
#endif
	InitConfigManager();
	SwitchFlashInit();
	PowerOnSystem();
	InitSimpleCliTask();

#ifdef PWR_MAN_EN
	PowerOffOrinA();
#endif

	if (InitNetwork() != ERROR_OK)
	{
		PONY_LOG(DEBUG_ERR, "Failed to init network!");
	}
	LOG_IF_ERROR(RegisterDebugWriteFunc(AdcuDebugWrite));

	if (InitLocalRouter(NULL, 0) != ERROR_OK)
	{
		PONY_LOG(DEBUG_FATAL, "Failed to initialize local router!");
	}

	InitTempSensor();
	InitialCameraTrigger();

	if (InitialRtcTime() != ERROR_OK)
	{
		PONY_LOG(DEBUG_ERR, "Failed to init RTC.");
	}

	SetLedLevel(kLedNormal);

	if (ABLoaderInit(&g_local_loader_ops, kCurrentSlot) != ERROR_OK)
	{
		PONY_LOG(DEBUG_FATAL, "Failed to initialize A/B loader!");
	}

	PrintVersion();

	PONY_LOG(DEBUG_INFO, "Starting F0100_0001 AURIX A.");

	uint32_t tick = GetSystemTick(0);
	static const uint32_t kTaskCycleTicksIn1s = 500;
	uint32_t count = 0;
	static bool has_marked = false;
	InitEthCli();

	/* NAMI SECTION INIT BEGIN */
	/* Init ADAS Model */
	ADAS_initialize();
	ReadMemData();


	/* Init VLC Model */
	VLCforADAS_UMP_initialize();

	/* Init Kuzov ^_^ */
	ApplyParameters_Sedan();

	/* INIT UDP */
	UDP_InitMessageObjects();
	UDP_PostSettings();
	udp_client_connect();
	udp_client_mrr_connect();
	udp_client_ic_connect();

	/* INIT CAN */
	CAN_InitMessageObjects();
	CAN_PostSettings();
	CAN_InitRxDascuIdItems();
#ifdef SW_AURUS
	CAN_InitRxAdasFilters();
#endif
#ifdef SW_HAVAL
	CAN_InitRxHavalFilters();
#endif
	CAN_InitRxMrrxDataFilters();
	CAN_InitRxMrrxDiagFilters();
#ifdef HW_DEBUG
	CAN_InitRxTestAdasFilters();
#ifdef SW_AURUS
	CAN_InitRxXcpFilters();
#endif
#endif
/*
	g_adas_filter_for_reset_items[0].id = 0x7D5U;
	g_adas_filter_for_reset_items[0].ide = kCanIdStd;
	g_adas_filter_for_reset_items[0].rtr = kCanRtrData;
	g_adas_filter_for_reset_items[0].mask = 0xFFFFFFFF;
	g_adas_filter_for_reset_items[0].fdf = kCanFdTypeClassic;

	g_adas_filter_for_reset_config.count = 1;
	g_adas_filter_for_reset_config.active = 1;
	g_adas_filter_for_reset_config.items = g_adas_filter_for_reset_items;
*/
	/* CAN interface Init */
	//AUTOMOBILE: ADASCANFD AURUS MATRIX
	while(CanIoctl(ADASCANFD, kCanIoctlCmdSetFilter, &g_adas_filter_config)!= ERROR_OK);
	while(CanIoctl(ADASCANFD, kCanIoctlCmdSetDataReadyCallback, &data_ready_callback_can_adas)!= ERROR_OK);
	while(CanOpen(ADASCANFD) != ERROR_OK);

#ifdef SW_HAVAL
	// AUTOMOBILE: HAVAL MATRIX
	while(CanIoctl(HAVAL, kCanIoctlCmdSetFilter, &g_haval_filter_config)!= ERROR_OK);
	while(CanIoctl(HAVAL, kCanIoctlCmdSetDataReadyCallback, &data_ready_callback_haval)!= ERROR_OK);
	while(CanOpen(HAVAL) != ERROR_OK);
#endif
	// REAR-RADAR-DIAG NEED TO CHANGE FILTER_CONFIG AND CALL-BACK
	while(CanIoctl(MRRXCAN_DIAG, kCanIoctlCmdSetFilter, &g_mrrx_diag_filter_config)!= ERROR_OK);
	while(CanIoctl(MRRXCAN_DIAG, kCanIoctlCmdSetDataReadyCallback, &data_ready_callback_mrrx_diag)!= ERROR_OK);
	while(CanOpen(MRRXCAN_DIAG) != ERROR_OK);

	// REAR-RADAR-DATA NEED TO CHANGE FILTER_CONFIG AND CALL-BACK
	while(CanIoctl(MRRX_DATA, kCanIoctlCmdSetFilter, &g_mrrx_data_filter_config)!= ERROR_OK);
	while(CanIoctl(MRRX_DATA, kCanIoctlCmdSetDataReadyCallback, &data_ready_callback_mrrx_data)!= ERROR_OK);
	while(CanOpen(MRRX_DATA) != ERROR_OK);

#ifdef HW_DEBUG
#ifdef SW_AURUS
	// XCP CAN
	while(CanIoctl(XCP_CAN, kCanIoctlCmdSetFilter, &g_xcp_filter_config)!= ERROR_OK);
	while(CanIoctl(XCP_CAN, kCanIoctlCmdSetDataReadyCallback, &data_ready_callback_xcp_rx)!= ERROR_OK);
	while(CanOpen(XCP_CAN) != ERROR_OK);
#endif
	// TEST-CAN
	while(CanIoctl(FD, kCanIoctlCmdSetFilter, &g_test_adas_filter_config)!= ERROR_OK);
	while(CanIoctl(FD, kCanIoctlCmdSetDataReadyCallback, &data_ready_callback_can_test_adas)!= ERROR_OK);
	while(CanOpen(FD) != ERROR_OK);
#endif

#ifdef HW_DEBUG
	/* INIT XCP */
	XCP_Init();
#endif
	/* INIT Timers */
	InitTimer();

	/* INIT FIRMWARE DATA RELEASE And Active SLOT */
<<<<<<< HEAD
	VerDay = 06U;
	VerMonth = 06U;
	VerYear = 2025U;
	VerActiveSlot = 0U;	// 0 = Slot_A, 1 = Slot_B
=======
	VerDay = 03U;
	VerMonth = 06U;
	VerYear = 2025U;
	VerActiveSlot = 0U;	// 0 = Slot_A, 1 = Slot_B

	// test Prepare DATA!
	/*
		readFlashConfig();
		parseConfigData();
		writeFlashConfig();
	*/
>>>>>>> parent of cc6caff (changed date =))

	/* NAMI SECTION INIT END */

	while (1)
	{
		if (time_after(GetSystemTick(0), tick))
		{
			if (has_marked)
			{
				Tlf35584ServiceWindowWatchdog(&g_tlf35584);
			}

			tick += kTaskCycleTicksIn1s;

			if ((!has_marked) && (count++ == kCountToMarkSuccessfullBoot))
			{
				if (ABLoaderMarkBootSuccessful() != ERROR_OK)
				{
					PONY_LOG(DEBUG_ERR, "Failed to mark current boot successful.");
				}
				else
				{
					has_marked = true;
				}
			}
		}

		LightLedsByStatus();
		LwipTask();
		HandleRouterTask();

		if (!IsInBurning())
		{
			AppSimpleCliTask();
		}
/*
		if(IsInitCanBridge())
		{
			CanTransferTask();
		}
*/

/* NAMI SECTION CODE - BEGIN */
		if (!fPrepareToFirmware)
		{
			Watch_T15_state ();

			if (fUdpProcess)
			{
				fUdpProcess = 0;
				UDP_Process();
			}

			MRRX_UDP_Release();

		// ADD VISUAL UDP TRANSFER DATA!!!! AND CONDITION!!!
			if (flgModelOut)
			{
				//UDP_TransmitPeriodicalPacketIC();
				flgModelOut = 0;
			}

#ifdef PWR_MAN_EN
			pwr_mngmnt_state();
#endif

			/* CAN Recover busoff error */
			if (fDiagCanBusState)
			{
				fDiagCanBusState = 0;

				for (int i=0; i < sizeof(CANNetworkList)/sizeof(CANNetworkID_t); i++)
				{
					RecoverBusOff(CANNetworkList[i]);
				}
			}

			if (stateResetOrin == 0)
			{
				if (OrinResetReq == 1)
				{
					OrinResetReq = 0;
					dtResetOrin = SystemTime;
					stateResetOrin = 1;
					PowerOffOrinA();
				}
				else
				{
					dtResetOrin = 0;
				}
			}
			else if (stateResetOrin == 1)
			{
				if ((SystemTime-dtResetOrin)>=1000)
				{
					stateResetOrin = 0;
					dtResetOrin = 0;
					PowerOnOrinA();
					OrinResetReq = 0;
				}
			}
		}

		if (fPrepareToFirmware)
		{
			if (tcp_connected == 0)
			{
				tcp_connected = 1;
#ifdef SW_AURUS
				while(CanClose(ADASCANFD) != ERROR_OK);
#endif
#ifdef SW_HAVAL
				while(CanClose(HAVAL) != ERROR_OK);
#endif
#ifdef HW_DEBUG
#ifdef SW_AURUS
				while(CanClose(XCP_CAN) != ERROR_OK);
#endif
				while(CanClose(FD) != ERROR_OK);
#endif
				while(CanClose(MRRXCAN_DIAG) != ERROR_OK);
				while(CanClose(MRRX_DATA) != ERROR_OK);
				udp_client_disconnect();
				udp_client_mrr_disconnect();
				udp_client_ic_disconnect();
			}
		}

/* NAMI SECTION CODE - END*/
	}
}



void RecoverBusOff(CANNetworkID_t CANNetwork)
{
	can_status_t status = {0};

	if ((CanGetStatus(CANNetwork, &status) == ERROR_OK) && (status.error_code != 0))
	{
		if (status.error_code & (1 << kCanErrorTypeBusOff))
		{
			CanIoctl(CANNetwork, kCanIoctlCmdRecoverBusOff, NULL);
		}
	}
}


static void InitDevices(void) {
  OpenUart(0);
  ReturnCode result = OpenI2cBus(0);
  if (result != ERROR_OK) {
    PONY_LOG(DEBUG_ERR, "Open I2C0 failed, result=%d!", result);
  }
  result = OpenI2cBus(1);
  if (result != ERROR_OK) {
    PONY_LOG(DEBUG_ERR, "Open I2C1 failed, result=%d!", result);
  }
  result = OpenI2cBus(3);
  if (result != ERROR_OK) {
    PONY_LOG(DEBUG_ERR, "Open mdio failed, result=%d!", result);
  }
}

addAppStep1(InitDevices);
