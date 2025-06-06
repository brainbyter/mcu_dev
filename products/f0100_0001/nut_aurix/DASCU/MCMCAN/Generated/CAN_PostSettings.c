#include <CAN_PostSettings.h>
#include <DiagVars.h>
#include <UdpMessageObjects.h>
#include <string.h>
#include <ERAG.h>
#include <ADASCANFD_IDs.h>

unsigned char FIU_ADAS_Config_Handler_dtd = 0;

void CAN_PostSettings()
{
	FIU_ADAS_Config_MO.failHandler = 0;
	FIU_Msg3_MO.failHandler = 0;
	IC_HUD_01_MO.failHandler = 0;

	MainStart_MO.failHandler = SetDefault_MainStart_Mod;
	MainStart_MO.handler = MainStart_Handler_Mod;
	MainStart_MO.diagHandler = 0;

/* Установка цикл-таймов для тестовых в 0 */
	TestData_AA_MO.cycle = 0;
	UdpPacketsStat_MO.cycle = 0;
	TestData_SOS_Status_MO.cycle = 0;
	ERAG_Data_MO.cycle = 0;
	ADASCANFD_Timeouts_MO.cycle = 0;
	TestData_ALCC_MO.cycle = 0;
	TestData_FromMRRs_MO.cycle = 0;
	TestData_ToMRRs_MO.cycle = 0;
	TestData_GPU_States_MO.cycle = 0;
	TestData_DOW_MO.cycle = 0;
	OncomeCrossPercData_MO.cycle = 0;
	TestData_VISUAL_MO.cycle = 0;
	SignPercData_MO.cycle = 0;
	RearPercData17_18_MO.cycle = 0;
	RearPercData15_16_MO.cycle = 0;
	RearPercData12_14_MO.cycle = 0;
	TestData_RDA_MO.cycle = 0;
	TestData_RCW_MO.cycle = 0;
	TestData_MLIA_MO.cycle = 0;
	MliaPercData20_21_MO.cycle = 0;
	MliaPercData12_19_MO.cycle = 0;
	MliaPercData06_11_MO.cycle = 0;
	MliaPercData01_05_MO.cycle = 0;
	MainDataFromPerc_MO.cycle = 0;
	TestData_LKA_MO.cycle = 0;
	TestData_LCC_MO.cycle = 0;
	TestData_LDW_MO.cycle = 0;
	LaneFrontPercData_MO.cycle = 0;
	LaneRearPercData_MO.cycle = 0;
	FrontPercData4_6_MO.cycle = 0;
	FrontPercData1_3_MO.cycle = 0;
	TestData_FIU_MO.cycle = 0;
	TestData_AEB_MO.cycle = 0;
	TestData_ACC_MO.cycle = 0;

	DiagMrrLResp_MO.cycle = 0;
	DiagMrrRResp_MO.cycle = 0;
	DiagGpuResp_MO.cycle = 0;


	// kostyl FIU Manager
	FIU_ADAS_Config_MO.handler = FIU_ADAS_Config_Handler_Mod;
	DAS_FIU_Settings_MO.cycle = 0;

	DiagPanelConn_MO.handler = DiagPanelConn_Handler_Mod;
	DiagPanelConn_MO.failHandler = SetDefault_DiagPanelConn_Mod;
	DiagPanelConn_MO.diagHandler = 0;
	//	DiagMrrLResp_MO.failHandler = SetDefault_DiagMrrDidReq_Mod;
	DiagMrrLResp_MO.failHandler = SetDefault_DiagMrrL_DidReq_Mod;
	DiagMrrRResp_MO.failHandler = SetDefault_DiagMrrR_DidReq_Mod;


	ESC_04_MO.handler = ESC_04_Handler_Mod;

	Emu_EMS_MO.failHandler = SetDefault_Emu_EMS_Mod;

	Emu_Spd_MO.failHandler = SetDefault_Emu_Spd_Mod;
	Emu_Blink_Xcp_MO.failHandler = SetDefault_Emu_Blink_Xcp_Mod;

	/* FUCKING KOSTYL! */
	DASCU_HLL_Object_MO.diagHandler = FillCS_DASCU_HLL_Object_Mod;
	DASCU_HLR_Object_MO.diagHandler = FillCS_DASCU_HLR_Object_Mod;

	/* Haval Mod Handler */
	ABM1_MO.handler = ABM1_Handler_Mod;
	ABM2_MO.handler = ABM2_Handler_Mod;
	ABS1_MO.handler = ABS1_Handler_Mod;
	ABS2_MO.handler = ABS2_Handler_Mod;
	ABS3_MO.handler = ABS3_Handler_Mod;
	ACC_FD2_MO.handler = ACC_FD2_Handler_Mod;
	AEB_FD1_MO.handler = AEB_FD1_Handler_Mod;
	CSA1_MO.handler = CSA1_Handler_Mod;
	CSA2_MO.handler = CSA2_Handler_Mod;
	ESP1_MO.handler = ESP1_Handler_Mod;
	IFC_FD2_MO.handler = IFC_FD2_Handler_Mod;

	Diag_To_ERAG_MO.handler = 0;

	ERAG_NMEA6_MO.handler = ERAG_NMEA6_Handler_Mod;
	ERAG_NMEA5_MO.handler = ERAG_NMEA5_Handler_Mod;
	ERAG_NMEA4_MO.handler = ERAG_NMEA4_Handler_Mod;
	ERAG_NMEA3_MO.handler = ERAG_NMEA3_Handler_Mod;
	ERAG_NMEA2_MO.handler = ERAG_NMEA2_Handler_Mod;
	ERAG_NMEA1_MO.handler = ERAG_NMEA1_Handler_Mod;
	
	DAS_04_MO.handler = DAS_04_Handler_Mod;

	DAS_HUD_02_MO.handler = DAS_HUD_02_Handler_Mod;


	/* Change default init cycle 5 value time for 2 cycletime */
	Emu_MLIA_Xcp_MO.countCycleTimeout = 2;
	Emu_EMS_MO.countCycleTimeout = 2;
	DiagToolFake_MO.countCycleTimeout = 2;
	Emu_Spd_MO.countCycleTimeout = 2;
	DiagPanelConn_MO.countCycleTimeout = 2;
	MainStart_MO.countCycleTimeout = 2;
	Emu_Blink_Xcp_MO.countCycleTimeout = 2;


}

void MainStart_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	M_AaStart = (uint8_t)(((data[3] >> 1) & 0x01U));
	M_UdpPackets_St = (uint8_t)(((data[3]) & 0x01U));
	M_Sos_Status = (uint8_t)(((data[2] >> 7) & 0x01U));
	M_Erag_Data = (uint8_t)(((data[2] >> 6) & 0x01U));
	M_Adascanfd_to = (uint8_t)(((data[2] >> 5) & 0x01U));
	M_AlccStart = (uint8_t)(((data[2] >> 4) & 0x01U));
	M_MRR_InOutDataStart = (uint8_t)(((data[2] >> 3) & 0x01U));
	M_GpuStates_Start = (uint8_t)(((data[2] >> 2) & 0x01U));
	M_DowStart = (uint8_t)(((data[2] >> 1) & 0x01U));
	M_OncomCrossPerc_Start = (uint8_t)(((data[2]) & 0x01U));
	M_VisualStart = (uint8_t)(((data[1] >> 7) & 0x01U));
	M_SignPerc_Start = (uint8_t)(((data[1] >> 6) & 0x01U));
	M_RearPerc_Start = (uint8_t)(((data[1] >> 5) & 0x01U));
	M_RdaStart = (uint8_t)(((data[1] >> 4) & 0x01U));
	M_RcwStart = (uint8_t)(((data[1] >> 3) & 0x01U));
	M_MliaStart = (uint8_t)(((data[1] >> 2) & 0x01U));
	M_MliaPerc_Start = (uint8_t)(((data[1] >> 1) & 0x01U));
	M_MainData_Start = (uint8_t)(((data[1]) & 0x01U));
	M_LkaStart = (uint8_t)(((data[0] >> 7) & 0x01U));
	M_LdwStart = (uint8_t)(((data[0] >> 6) & 0x01U));
	M_LccStart = (uint8_t)(((data[0] >> 5) & 0x01U));
	M_LanePerc_Start = (uint8_t)(((data[0] >> 4) & 0x01U));
	M_FrontPerc_Start = (uint8_t)(((data[0] >> 3) & 0x01U));
	M_FiuStart = (uint8_t)(((data[0] >> 2) & 0x01U));
	M_AebStart = (uint8_t)(((data[0] >> 1) & 0x01U));
	M_AccStart = (uint8_t)(((data[0]) & 0x01U));

	TestData_AA_MO.cycle = M_AaStart ? TestDataOut_Cycle_Value : 0;
	UdpPacketsStat_MO.cycle = M_UdpPackets_St ? TestDataOut_Cycle_Value : 0;
	TestData_SOS_Status_MO.cycle = M_Sos_Status ? TestDataOut_Cycle_Value : 0;
	ERAG_Data_MO.cycle = M_Erag_Data ? TestDataOut_Cycle_Value : 0;
	ADASCANFD_Timeouts_MO.cycle = M_Adascanfd_to ? TestDataOut_Cycle_Value : 0;
	TestData_ALCC_MO.cycle = M_AlccStart ? TestDataOut_Cycle_Value : 0;
	TestData_FromMRRs_MO.cycle = M_MRR_InOutDataStart ? TestDataOut_Cycle_Value : 0;
	TestData_ToMRRs_MO.cycle = M_MRR_InOutDataStart ? TestDataOut_Cycle_Value : 0;
	TestData_GPU_States_MO.cycle = M_GpuStates_Start ? TestDataOut_Cycle_Value : 0;
	TestData_DOW_MO.cycle = M_DowStart ? TestDataOut_Cycle_Value : 0;
	OncomeCrossPercData_MO.cycle = M_OncomCrossPerc_Start ? TestDataOut_Cycle_Value : 0;
	TestData_VISUAL_MO.cycle = M_VisualStart ? TestDataOut_Cycle_Value : 0;
	SignPercData_MO.cycle = M_SignPerc_Start ? TestDataOut_Cycle_Value : 0;
	RearPercData17_18_MO.cycle = M_RearPerc_Start ? TestDataOut_Cycle_Value : 0;
	RearPercData15_16_MO.cycle = M_RearPerc_Start ? TestDataOut_Cycle_Value : 0;
	RearPercData12_14_MO.cycle = M_RearPerc_Start ? TestDataOut_Cycle_Value : 0;
	TestData_RDA_MO.cycle = M_RdaStart ? TestDataOut_Cycle_Value : 0;
	TestData_RCW_MO.cycle = M_RcwStart ? TestDataOut_Cycle_Value : 0;
	TestData_MLIA_MO.cycle = M_MliaStart ? TestDataOut_Cycle_Value : 0;
	MliaPercData20_21_MO.cycle = M_MliaPerc_Start ? TestDataOut_Cycle_Value : 0;
	MliaPercData12_19_MO.cycle = M_MliaPerc_Start ? TestDataOut_Cycle_Value : 0;
	MliaPercData06_11_MO.cycle = M_MliaPerc_Start ? TestDataOut_Cycle_Value : 0;
	MliaPercData01_05_MO.cycle = M_MliaPerc_Start ? TestDataOut_Cycle_Value : 0;
	MainDataFromPerc_MO.cycle = M_MainData_Start ? TestDataOut_Cycle_Value : 0;
	TestData_LKA_MO.cycle = M_LkaStart ? TestDataOut_Cycle_Value : 0;
	TestData_LCC_MO.cycle = M_LccStart ? TestDataOut_Cycle_Value : 0;
	TestData_LDW_MO.cycle = M_LdwStart ? TestDataOut_Cycle_Value : 0;
	LaneFrontPercData_MO.cycle = M_LanePerc_Start ? TestDataOut_Cycle_Value : 0;
	LaneRearPercData_MO.cycle = M_LanePerc_Start ? TestDataOut_Cycle_Value : 0;
	FrontPercData4_6_MO.cycle = M_FrontPerc_Start ? TestDataOut_Cycle_Value : 0;
	FrontPercData1_3_MO.cycle = M_FrontPerc_Start ? TestDataOut_Cycle_Value : 0;
	TestData_FIU_MO.cycle = M_FiuStart ? TestDataOut_Cycle_Value : 0;
	TestData_AEB_MO.cycle = M_AebStart ? TestDataOut_Cycle_Value : 0;
	TestData_ACC_MO.cycle = M_AccStart ? TestDataOut_Cycle_Value : 0;
}

void SetDefault_MainStart_Mod()
{
	M_AaStart = 0;
	M_UdpPackets_St = 0;
	M_Sos_Status = 0;
	M_Erag_Data = 0;
	M_Adascanfd_to = 0;
	M_AlccStart = 0;
	M_MRR_InOutDataStart = 0;
	M_GpuStates_Start = 0;
	M_DowStart = 0;
	M_OncomCrossPerc_Start = 0;
	M_VisualStart = 0;
	M_SignPerc_Start = 0;
	M_RearPerc_Start = 0;
	M_RdaStart = 0;
	M_RcwStart = 0;
	M_MliaStart = 0;
	M_MliaPerc_Start = 0;
	M_MainData_Start = 0;
	M_LkaStart = 0;
	M_LdwStart = 0;
	M_LccStart = 0;
	M_LanePerc_Start = 0;
	M_FrontPerc_Start = 0;
	M_FiuStart = 0;
	M_AebStart = 0;
	M_AccStart = 0;

	TestData_AA_MO.cycle = 0;
	UdpPacketsStat_MO.cycle = 0;
	TestData_SOS_Status_MO.cycle = 0;
	ERAG_Data_MO.cycle = 0;
	ADASCANFD_Timeouts_MO.cycle = 0;
	TestData_ALCC_MO.cycle = 0;
	TestData_FromMRRs_MO.cycle = 0;
	TestData_ToMRRs_MO.cycle = 0;
	TestData_GPU_States_MO.cycle = 0;
	TestData_DOW_MO.cycle = 0;
	OncomeCrossPercData_MO.cycle = 0;
	TestData_VISUAL_MO.cycle = 0;
	SignPercData_MO.cycle = 0;
	RearPercData17_18_MO.cycle = 0;
	RearPercData15_16_MO.cycle = 0;
	RearPercData12_14_MO.cycle = 0;
	TestData_RDA_MO.cycle = 0;
	TestData_RCW_MO.cycle = 0;
	TestData_MLIA_MO.cycle = 0;
	MliaPercData20_21_MO.cycle = 0;
	MliaPercData12_19_MO.cycle = 0;
	MliaPercData06_11_MO.cycle = 0;
	MliaPercData01_05_MO.cycle = 0;
	MainDataFromPerc_MO.cycle = 0;
	TestData_LKA_MO.cycle = 0;
	TestData_LCC_MO.cycle = 0;
	TestData_LDW_MO.cycle = 0;
	LaneFrontPercData_MO.cycle = 0;
	LaneRearPercData_MO.cycle = 0;
	FrontPercData4_6_MO.cycle = 0;
	FrontPercData1_3_MO.cycle = 0;
	TestData_FIU_MO.cycle = 0;
	TestData_AEB_MO.cycle = 0;
	TestData_ACC_MO.cycle = 0;
}


void SetDefault_DiagMrrL_DidReq_Mod()
{
	DiagMrrLResp_MO.cycle = 0;
}

void SetDefault_DiagMrrR_DidReq_Mod()
{
	DiagMrrRResp_MO.cycle = 0;
}


void SetDefault_DiagMrrDidReq_Mod()
{
	DiagMrrLResp_MO.cycle = 0;
	DiagMrrRResp_MO.cycle = 0;
}

void SetDefault_DiagPanelConn_Mod()
{
	DiagPanelEn = 0;
	UDP_Diag_Calibration_MO.cycle = 0;
	DiagGpuResp_MO.cycle = 0;
}

void DiagPanelConn_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	DiagPanelEn = data[0] & 0x01;
	UDP_Diag_Calibration_MO.cycle = (DiagPanelEn==1) ? 100 : 0;
	DiagGpuResp_MO.cycle = (DiagPanelEn==1) ? 100 : 0;

	step_counter = 5;
	get_req = 0;

	temp_REQ_GPU_FrcuVirtAngReset = REQ_GPU_FrcuVirtAngReset = 0;
	temp_REQ_GPU_FrcuGetImg = REQ_GPU_FrcuGetImg = 0;
	temp_REQ_GPU_FcuVirtAngReset = REQ_GPU_FcuVirtAngReset = 0;
	temp_REQ_GPU_FcuSetYawAngle = REQ_GPU_FcuSetYawAngle = 0;
	temp_REQ_GPU_FcuSetPitchAngle = REQ_GPU_FcuSetPitchAngle = 0;
	temp_REQ_GPU_FcuCalibStart = REQ_GPU_FcuCalibStart = 0;
	temp_REQ_GPU_FcuCalibStop = REQ_GPU_FcuCalibStop = 0;
	temp_REQ_GPU_FcuGetWideImg = REQ_GPU_FcuGetWideImg = 0;
	temp_REQ_GPU_FcuGetNarrowImg = REQ_GPU_FcuGetNarrowImg = 0;
	temp_REQ_GPU_TicuCalibStart = REQ_GPU_TicuCalibStart = 0;
	temp_REQ_GPU_TicuCalibStop = REQ_GPU_TicuCalibStop = 0;
	temp_REQ_GPU_TicuGetImg = REQ_GPU_TicuGetImg = 0;
	temp_REQ_GPU_LidCalibStart = REQ_GPU_LidCalibStart = 0;
	temp_REQ_GPU_LidCalibStop = REQ_GPU_LidCalibStop = 0;
	temp_REQ_GPU_LidGetImg = REQ_GPU_LidGetImg = 0;
}


void ESC_04_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	ESC_04_CS = (((uint8_t)(((data[7]) & 0xFFU))));
	ESC_CtlActiveTcs = (((uint8_t)(((data[3] >> 4) & 0x01U))));
	ESC_CtlActiveAbs = (((uint8_t)(((data[3] >> 2) & 0x01U))));
	ESC_Bls_Out = (((uint8_t)(((data[2] >> 3) & 0x01U))));
	ESC_HDC_Activated = (((uint8_t)(((data[4]) & 0x01U))));
	ESC_CtlActiveEbd = (((uint8_t)(((data[3] >> 3) & 0x01U))));
	ESC_CtlActiveVdc = (((uint8_t)(((data[3] >> 5) & 0x01U))));
	ESC_VehicleSpeed_ValueError = (((uint8_t)(((data[2]) & 0x01U))));
	ESC_04_RC = (((uint8_t)(((data[6] >> 4) & 0x0FU))));
	ESC_Bla = (((uint8_t)(((data[2] >> 4) & 0x01U))));

	if (Emu_Spd_Switch)
	{
		ESC_VehicleSpeed = (float)Emu_Vehicle_Spd_Val;
	}
	else
	{
		//ESC_VehicleSpeed = ((float)((uint16_t)(((data[0]) & 0xFFU) | (uint32_t)((data[1] & 0xFFU) << 8))) * 0.01f);
		ESC_VehicleSpeed = (float)(uint16_t)((((uint16_t)data[0]) & 0xFFU) | (((uint16_t)data[1] & 0xFFU) << 8)) * 0.01f;
	}
}


void SetDefault_Emu_EMS_Mod()
{
	Emu_DAS_CcMotIncFlag_Switch = 0;
}


/* Haval_Mod_Handlers */
void ABM1_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	DrvSBR = (((uint8_t)(((data[1] >> 3) & 0x01))));

	FrontBuckleDriver_L = DrvSBR;
}

void ABM2_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	VehLgtAccel = ((float)((uint16_t)(((data[1] & 0xFFU) << 8) | (uint32_t)((data[2] >> 0) & 0xFF))) * 0.00098)-21.592;
	VehLatAccel = ((float)((uint16_t)(((data[3] & 0xFFU) << 8) | (uint32_t)((data[4] >> 0) & 0xFF))) * 0.00098)-21.592;
	VehYawRate = ((float)((uint16_t)(((data[5] & 0xFFU) << 8) | (uint32_t)((data[6] >> 0) & 0xFF))) * 0.00024)-2.093;
	VehLgtAccelVld = (((uint8_t)(((data[7] >> 7) & 0x01U))));
	VehLatAccelVld = (((uint8_t)(((data[7] >> 6) & 0x01U))));
	VehDynYawRateVld = (((uint8_t)(((data[7] >> 5) & 0x01U))));

	ESC_AY_Val = VehLatAccel / 9.80665;
	ESC_AY_Stat = (VehLatAccelVld==1) ? 0 : 2;
	ESC_PSIP1_Val = -((VehYawRate * 180)/3.1415926535897f);
	ESC_PSIP1_Stat = (VehDynYawRateVld==1) ? 0 : 2;
	ESC_AX = VehLgtAccel / 9.80665;
	ESC_AX_Stat = (VehLgtAccelVld==1) ? 0 : 2;
}


void ABS1_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	FLWheelDriveDirection = (((uint8_t)(((data[1] >> 6) & 0x03U))));
	FLWheelSpd = ((float)((uint16_t)(((data[1] & 0x1FU) << 8) | (uint32_t)((data[2] >> 0) & 0xFF))) * 0.05625);
	FRWheelDriveDirection = (((uint8_t)(((data[3] >> 6) & 0x03U))));
	FRWheelSpd = ((float)((uint16_t)(((data[3] & 0x1FU) << 8) | (uint32_t)((data[4] >> 0) & 0xFF))) * 0.05625);

	ESC_WheelSpeed_FL = FLWheelSpd;
	ESC_WheelSpeed_FR = FRWheelSpd;

	if (FLWheelDriveDirection == 0)
	{
		ESC_WheelDirectionInfo_FL = 0;
	}
	else if (FLWheelDriveDirection == 1)
	{
		ESC_WheelDirectionInfo_FL = 2;
	}
	else if (FLWheelDriveDirection == 2)
	{
		ESC_WheelDirectionInfo_FL = 3;
	}
	else //if (FLWheelDriveDirection == 3)
	{
		ESC_WheelDirectionInfo_FL = 1;
	}

	if (FRWheelDriveDirection == 0)
	{
		ESC_WheelDirectionInfo_FR = 0;
	}
	else if (FRWheelDriveDirection == 1)
	{
		ESC_WheelDirectionInfo_FR = 2;
	}
	else if (FRWheelDriveDirection == 2)
	{
		ESC_WheelDirectionInfo_FR = 3;
	}
	else// if (FRWheelDriveDirection == 3)
	{
		ESC_WheelDirectionInfo_FR = 1;
	}
}

void ABS2_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	RLWheelSpd = ((float)((uint16_t)(((data[1] & 0x1F) << 8) | ((data[2] >> 0) & 0xFF))) * 0.05625);
	RRWheelSpd = ((float)((uint16_t)(((data[3] & 0x1F) << 8) | ((data[4] >> 0) & 0xFF))) * 0.05625);

	ESC_WheelSpeed_RL = RLWheelSpd;
	ESC_WheelSpeed_RR = RRWheelSpd;
}

void ABS3_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	VehSpd = ((float)((uint16_t)(((data[1] & 0x1F) << 8) | ((data[2] >> 0) & 0xFF))) * 0.05625);
	ABSActv = (((uint8_t)(((data[3] >> 3) & 0x01))));

	ESC_VehicleSpeed = IC_Speed = VehSpd;
	ESC_CtlActiveAbs = ABSActv;
}

void ACC_FD2_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	ACC_ModDisp = (((uint8_t)(((data[18] >> 3) & 0x1F))));
	ACC_FctSts = (((uint8_t)(((data[18] >> 1) & 0x03))));
	ACC_SpdSetValue = (((uint8_t)(((data[22] >> 0) & 0xFF))));

	DAS_CcMode_Stat = ACC_ModDisp;
	DAS_CcType_Stat = ACC_FctSts;
	DAS_CcSetSpeed_Stat = ACC_SpdSetValue;
}

void AEB_FD1_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	AEB_TgtDecel_Req = (((uint8_t)(((data[9] >> 2) & 0x01))));

	DAS_AebDecelFlag_Req = AEB_TgtDecel_Req;
}

void CSA1_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	LTurnLmpSwtSts = (((uint8_t)(((data[2] >> 3) & 0x01))));
	RTurnLmpSwtSts = (((uint8_t)(((data[2] >> 4) & 0x01))));

	BCM_TurnIndL_Req = LTurnLmpSwtSts;
	BCM_TurnIndR_Req = RTurnLmpSwtSts;
}

void CSA2_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	SteerWheelAng = ((float)((uint16_t)(((data[1] & 0xFF) << 7) | ((data[2] >> 1) & 0x7F))) * 0.1);
	SteerWheelAngSign = (((uint8_t)(((data[2] >> 0) & 0x01))));
	SteerWheelSpd = ((float)((uint16_t)(((data[3] & 0xFF) << 7) | ((data[4] >> 1) & 0x7F))) * 0.1);
	SteerWheelSpdSign = (((uint8_t)(((data[4] >> 0) & 0x01))));

	SAS_Angle = ((SteerWheelAngSign == 1) ? 1 : -1)*SteerWheelAng;
	SAS_Speed = ((SteerWheelSpdSign == 1) ? 1 : -1)*SteerWheelSpd;
	SAS_CAL_Stat = 1;
	SAS_OK_Stat = 1;
}

void ESP1_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	VDCActv = (((uint8_t)(((data[2] >> 4) & 0x01))));

	ESC_CtlActiveVdc = VDCActv;
}

void IFC_FD2_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	ELKActSts = (((uint8_t)(((data[20] >> 6) & 0x03))));

	DAS_LkaMode_Stat = ELKActSts;
}


void FillCS_DASCU_HLL_Object_Mod(uint8* data, uint8 dlc)
{
	data[48] = CAN_CalculateXOR8(data, dlc, (dlc - 1) * 8);
}

void FillCS_DASCU_HLR_Object_Mod(uint8* data, uint8 dlc)
{
	data[48] = CAN_CalculateXOR8(data, dlc, (dlc - 1) * 8);
}


void SetDefault_Emu_Spd_Mod()
{
	Emu_BCM_Switch = 0;
	Emu_Vehicle_Spd_Val = 0;
	Emu_Mlia_Start_Req = 0;
	Emu_IC_Visual_Req = 0;
	Emu_HighBeam_Req = 0;
	Emu_Spd_Switch = 0;
}

void SetDefault_Emu_Blink_Xcp_Mod()
{
  // Emu_BlinkPeriod = DEFAULT_Emu_BlinkPeriod;
   Emu_BlinkPeriodCheckMode = DEFAULT_Emu_BlinkPeriodCheckMode;
}



void ERAG_NMEA6_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	memcpy(g_f.data, data, 8);
	g_fNMEA = 1;
	g_f.id = ERAG_NMEA6_ID;
}

void ERAG_NMEA5_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	memcpy(g_f.data, data, 8);
	g_fNMEA = 1;
	g_f.id = ERAG_NMEA5_ID;
}

void ERAG_NMEA4_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	memcpy(g_f.data, data, 8);
	g_fNMEA = 1;
	g_f.id = ERAG_NMEA4_ID;
}

void ERAG_NMEA3_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	memcpy(g_f.data, data, 8);
	g_fNMEA = 1;
	g_f.id = ERAG_NMEA3_ID;
}

void ERAG_NMEA2_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	memcpy(g_f.data, data, 8);
	g_fNMEA = 1;
	g_f.id = ERAG_NMEA2_ID;
}

void ERAG_NMEA1_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	memcpy(g_f.data, data, 8);
	g_fNMEA = 1;
	g_f.id = ERAG_NMEA1_ID;
}

void SetDefault_ERAG_NMEA()
{
	if (ComScl_ERAG_NMEA1_Timeout || ComScl_ERAG_NMEA2_Timeout || ComScl_ERAG_NMEA3_Timeout || ComScl_ERAG_NMEA4_Timeout || ComScl_ERAG_NMEA5_Timeout || ComScl_ERAG_NMEA6_Timeout)
	{
		g_trust_status = 1;
		ERAG_Longitude_degrees = 0;
		ERAG_Longitude_min = 0;
		ERAG_Longitude_min_fract = 0;
		ERAG_Longitude_sign = 0;
		ERAG_Latitude_degrees = 0;
		ERAG_Latitude_min = 0;
		ERAG_Latitude_min_fract = 0;
		ERAG_Latitude_sign = 0;
		ERAG_Speed = 0;
		ERAG_Course = 0;
	}
}

void DAS_04_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	uint8_t raw_signal = 0U;
	memset(data, 0x00, dlc);

	if (TestJerk_AfsBrakeJerkEnab_Stat)
	{
		raw_signal = (TestJerk_AfsBrakeJerk_Req);
	}
	else
	{
		raw_signal = (DAS_AfsBrakeJerk_Req);
	}

	data[1] = (raw_signal & 0x01U) << 5;
	raw_signal = (DAS_AebFuncError_Stat);
	data[2] = (raw_signal & 0x01U) << 3;
	raw_signal = (DAS_AebRdaStand_Req);
	data[2] |= (raw_signal & 0x01U) << 2;
	raw_signal = (DAS_04_RC);
	data[2] |= (raw_signal & 0x0FU) << 4;
	raw_signal = (DAS_CcFuncError_Stat);
	data[2] |= (raw_signal & 0x01U) << 1;
	raw_signal = (DAS_CcBrakeStandSt_Req);
	data[1] |= (raw_signal & 0x01U) << 1;
	raw_signal = (DAS_CcBrakeRelease_Req);
	data[1] |= (raw_signal & 0x01U) << 6;
	raw_signal = (DAS_AebMode_Stat);
	data[1] |= (raw_signal & 0x01U) << 7;
	raw_signal = (DAS_04_CS);
	data[3] = (raw_signal & 0xFFU);
	raw_signal = (DAS_CcMode_Stat);
	data[1] |= (raw_signal & 0x03U) << 2;
	raw_signal = (DAS_AebDecelFlag_Req);
	data[2] |= (raw_signal & 0x01U);

	if (TestJerk_AfsBrakeJerkEnab_Stat)
	{
		raw_signal = (TestJerk_AfsBrakeJerkEnab_Stat);
	}
	else
	{
		raw_signal = (DAS_AfsBrakeJerkEnab_Stat);
	}

	data[1] |= (raw_signal & 0x01U) << 4;

	if (TestJerk_AfsBrakeJerkEnab_Stat && TestJerk_AfsBrakeJerk_Req)
	{
		raw_signal = (TestJerk_AfsBrakeJerkLvl);
	}
	else
	{
		raw_signal = (DAS_AfsBrakeJerkLvl_Stat);
	}

	data[0] = (raw_signal & 0xFFU);
	raw_signal = (DAS_CcDecelFlag_Req);
	data[1] |= (raw_signal & 0x01U);
}

void FIU_ADAS_Config_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	FIU_SettRDAAutoBrake_Req = (uint8_t)(((data[1]) & 0x01U));
	FIU_SettLCCMode_Req = (uint8_t)(((data[4] >> 4) & 0x03U));
	FIU_SettRDAsts_Req = (uint8_t)(((data[0] >> 2) & 0x01U));
	FIU_SettCCMode_Req = (uint8_t)(((data[3] >> 2) & 0x03U));
	FIU_SettSensCleanSts_Req = (uint8_t)(((data[6] >> 7) & 0x01U));
	FIU_SettLCCSoundAlert_Req = (uint8_t)(((data[2] >> 3) & 0x01U));
	FIU_SettAEBSts_Req = (uint8_t)(((data[1] >> 6) & 0x01U));
	FIU_SettDOWSts_Req = (uint8_t)(((data[2] >> 5) & 0x01U));
	FIU_SettAebFcwVibration_Req = (uint8_t)(((data[1] >> 5) & 0x01U));
	FIU_SettLDPSts_Req = (uint8_t)(((data[3] >> 4) & 0x01U));
	FIU_SettRecFileSize_Req = (uint8_t)(((data[5]) & 0x03U));
	FIU_SettLDWMode_Req = (uint8_t)(((data[4] >> 2) & 0x03U));
	FIU_SettRecResol_Req = (uint8_t)(((data[3]) & 0x03U));
	FIU_SettAebFcwMode_Req = (uint8_t)(((data[4] >> 6) & 0x03U));
	FIU_SettLDWVibration_Req = (uint8_t)(((data[2]) & 0x01U));
	FIU_SettRCTCsts_Req = (uint8_t)(((data[0] >> 3) & 0x01U));
	FIU_SettASLAOver_Req = (uint8_t)(((data[5] >> 2) & 0x3FU))-1;
	FIU_SettCCType_Req = (uint8_t)(((data[6] >> 4) & 0x07U));
	FIU_SettALCCSts_Req = (uint8_t)(((data[2] >> 4) & 0x01U));
	FIU_SettDOWSoundAlert_Req = (uint8_t)(((data[2] >> 6) & 0x01U));
	FIU_SettRecSts_Req = (uint8_t)(((data[1] >> 4) & 0x01U));
	FIU_StartSet_Req = (uint8_t)(((data[0]) & 0x01U));
	FIU_SettLCCSts_Req = (uint8_t)(((data[1] >> 7) & 0x01U));
	FIU_SettAFSsts_Req = (uint8_t)(((data[3] >> 7) & 0x01U));
	FIU_SettAAmode_Req = (uint8_t)(((data[4]) & 0x03U));
	FIU_SettFCWSts_Req = (uint8_t)(((data[1] >> 2) & 0x01U));
	FIU_SettCCSpdCorrect_Req = (uint8_t)(((data[0] >> 6) & 0x01U));
	FIU_SettLKASts_Req = (uint8_t)(((data[1] >> 1) & 0x01U));
	FIU_SettLCCVibration_Req = (uint8_t)(((data[2] >> 2) & 0x01U));
	FIU_SettLDWSts_Req = (uint8_t)(((data[2] >> 7) & 0x01U));
	FIU_SettASLASts_Req = (uint8_t)(((data[0] >> 7) & 0x01U));
	FIU_SettAAsts_Req = (uint8_t)(((data[3] >> 6) & 0x01U));
	FIU_SettTSRsts_Req = (uint8_t)(((data[3] >> 5) & 0x01U));
	FIU_SettLDWSoundAlert_Req = (uint8_t)(((data[2] >> 1) & 0x01U));

	FIU_ADAS_Config_Handler_dtd = 1;
}

void DAS_HUD_02_Handler_Mod(uint8_t *data, uint8_t dlc)
{
	uint8_t raw_signal = 0U;
	memset(data, 0x00, dlc);

	switch (DAS_RoadLaneAddressing_Stat)
	{
	case 0x00:
		data[0] = (DAS_LeftLaneLDWWarning_Req & 0x01U) << 7;
		break;

	case 0x01:
		data[0] = (DAS_RightLaneLDWWarning_Req & 0x01U) << 7;
		break;
	}

	switch (DAS_RoadSignAddressing_Stat)
	{
	case 0x00:
		data[2] = (DAS_SPLimRoadSignInf1_Stat & 0x3FU);
		break;

	case 0x01:
		data[2] = (DAS_SPLimRoadSignInf2_Stat & 0x3FU);
		break;

	case 0x02:
		data[2] = (DAS_SPLimRoadSignInf3_Stat & 0x3FU);
		break;

	default:
		break;
	}

	data[2] |= (DAS_RoadSignAddressing_Stat & 0x03U) << 6;
	data[3] = (DAS_SPLimRoadSignCurrSpeed_Stat & 0xFFU);
	data[4] = (DAS_RoadLaneAddressing_Stat & 0x01U) << 2;
}
