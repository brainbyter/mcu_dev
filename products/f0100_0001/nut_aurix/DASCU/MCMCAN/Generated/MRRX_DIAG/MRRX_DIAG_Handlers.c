#include <MRRX_DIAG_Vars.h>
#include <CAN_Private.h>
#include <string.h>
#include "ADAS.h"
#include "CAN.h"
#include "ADASCANFD_Vars.h"
#include "CAN_Mapping.h"

void DAS_VehInfo1_Handler(uint8_t *data, uint8_t dlc)
{
	memset(data, 0, 8);
	uint32_t raw_signal = 0;

	/* Prepare data */
	Str_Angle_V = (SAS_CAL_Stat == 1) ? 0 : 1;
	YawRat_V = (ESC_PSIP1_Stat==0) ? 0 : 1;
	VehSpeed_V = ESC_VehicleSpeed_ValueError;
	VehSpeed_IN = ESC_VehicleSpeed;
	YawRate_IN = (-1)*(ESC_PSIP1_Val * M_PI / 180);
	Str_Angle = SAS_Angle;

	raw_signal = (VehSpeed_V);
	data[0] = (raw_signal & 0x01U) << 7;
	raw_signal = (YawRate_IN + 2.093f) * 4166.67f;
	data[2] = (raw_signal >> 8) & 0xFFU;
	data[3] = (raw_signal & 0xFF) << 0;
	raw_signal = (YawRat_V);
	data[0] |= (raw_signal & 0x01U) << 6;
	raw_signal = (VehSpeed_IN) * 17.7778f;
	data[0] |= (raw_signal >> 8) & 0x1FU;
	data[1] = (raw_signal & 0xFF) << 0;
	raw_signal = (Str_Angle_V);
	data[0] |= (raw_signal & 0x01U) << 5;
	raw_signal = (Str_Angle + 900) * 10;
	data[4] = (raw_signal >> 8) & 0xFFU;
	data[5] = (raw_signal & 0xFF) << 0;
}

void DAS_VehInfo2_Handler(uint8_t *data, uint8_t dlc)
{
	memset(data, 0, 8);

	/* Prepare data */
	IGN_State_V = 0;
	IGN_State = BCM_T15_Stat;
	GEAR_STA_NOW_V = 0;	//(stGearLvr!=0 && stGearLvr<=4) ? 0 : 1;
	GEAR_STATE_NOW = stGearLvr==4 ? 1 : (stGearLvr==2 ? 7 : 0);

	data[0] = (GEAR_STA_NOW_V & 0x01) << 3;
	data[0] |= (GEAR_STATE_NOW  & 0x07) << 4;
	data[1] = (IGN_State & 0x01) << 4;
	data[1] |= (IGN_State_V & 0x01) << 5;
}

void DAS_VehInfo3_Handler(uint8_t *data, uint8_t dlc)
{
	memset(data, 0, 8);

	/* Prepare data*/

	RightTurnSWSts = BCM_TurnIndR_Req;
	LeftTurnSWSts = BCM_TurnIndL_Req;

	DriverDoorSts = (~DMFL_DoorAjarState) & 0x01;
	PassengerDoorSts = (~DMFR_DoorAjarState) & 0x01;
	RLDoorSts = (~DMRL_DoorAjarState) & 0x01;
	RRDoorSts = (~DMRR_DoorAjarState) & 0x01;

	//LockSts = ~(DMFL_DoorAjarState & DMFR_DoorAjarState & DMRL_DoorAjarState & DMRR_DoorAjarState);
	LockSts = (~VehicleLockState) & 0x01;

	data[2] = (RRDoorSts & 0x01) << 3;
	data[2] |= (PassengerDoorSts & 0x01) << 4;
	data[2] |= (RLDoorSts & 0x01) << 5;
	data[2] |= (DriverDoorSts & 0x01) << 6;
	data[2] |= (LockSts & 0x01) << 7;
	data[6] = (RightTurnSWSts & 0x01) << 1;
	data[6] |= (LeftTurnSWSts & 0x01) << 2;
}

/* DIAG Handlers */
void DAS_SwitchCalibWave_Handler(uint8_t *data, uint8_t dlc)
{
	memset(data, 0, 8);
	data[0] = 0x01;
}

void UDS_CALIB_RL_REQ_Handler(uint8_t *data, uint8_t dlc)
{
//	memset(data, 0, 8);
}

void UDS_CALIB_RL_RESP_Handler(uint8_t *data, uint8_t dlc)
{
//	memset(data, 0, 8);
}

void UDS_CALIB_RR_REQ_Handler(uint8_t *data, uint8_t dlc)
{
//	memset(data, 0, 8);
}

void UDS_CALIB_RR_RESP_Handler(uint8_t *data, uint8_t dlc)
{
//	memset(data, 0, 8);
}
