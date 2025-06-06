#include <stdint.h>
#include <UDP_Typedefs.h>
#include <UdpHandlers.h>
#include <ADASCANFD_Vars.h>
#include <ADAS.h>
#include <DiagVars.h>
#include <string.h>
#include <FD_Vars.h>
#include <../MCMCAN/Generated/CAN.h>
#include <O_PERC_DAS.h>
#include <CAN_Mapping.h>
#include <bsp_can.h>
#include <UDP_Extern_vars.h>
#include <ERAG.h>
#include <I_DIAG_DAS.h>
#include <math.h>
#include <UDP_Extern.h>

/*
uint8 fUdp1Rcv = 0;
uint8 fUdp2Rcv = 0;
uint8 fUdp3Rcv = 0;
uint8 fUdp4Rcv = 0;
uint8 fUdp5Rcv = 0;
uint8 fUdp6Rcv = 0;
uint8 fUdp7Rcv = 0;
*/
void UDP_Main_Start_Handler(uint8* data)
{
	memcpy(&data[0], &DtPercStartMlia, 1);
	memcpy(&data[1], &DtPercStartFrontPasObj, 1);
	memcpy(&data[2], &DtPercStartFrontOncomObj, 1);
	memcpy(&data[3], &DtPercStartSign, 1);
	memcpy(&data[4], &DtPercStartLane, 1);
	memcpy(&data[5], &DtPercStartRearObj, 1);
	memcpy(&data[6], &DtPercRecToInc_Req, 1);
	memcpy(&data[7], &DtPercStartRec, 1);
	memcpy(&data[8], &UDP_Main_Start_RC, 1);
}

void UDP_Climatic_Handler(uint8* data)
{
	memcpy(&data[0], &RainDetected, 1);
	memcpy(&data[1], &RainDensity, 1);
	memcpy(&data[2], &UDP_Climatic_RC, 1);
}

void UDP_BCM_LGT_Handler(uint8* data)
{
	memcpy(&data[0], &BCM_TurnIndL_Req, 1);
	memcpy(&data[1], &BCM_TurnIndR_Req, 1);
	memcpy(&data[2], &UDP_BCM_LGT_RC, 1);
}

void UDP_BCM_VehState_Handler(uint8* data)
{
	memcpy(&data[0], &BCM_VehicleType_Stat, 1);
	memcpy(&data[1], &BCM_VehicleBody_Stat, 1);
	memcpy(&data[2], &UDP_BCM_VehState_RC, 1);
}

void UDP_ESC_Front_Speed_Handler(uint8* data)
{
	memcpy(&data[0], &ESC_WheelDirectionInfo_FL, 1);
	memcpy(&data[1], &ESC_WheelDirectionInfo_FR, 1);
	memcpy(&data[2], &ESC_WheelSpeed_FL, 4);
	memcpy(&data[6], &ESC_WheelSpeed_FR, 4);
	memcpy(&data[10], &ESC_WheelSpeed_ValueError_FL, 1);
	memcpy(&data[11], &ESC_WheelSpeed_ValueError_FR, 1);
	memcpy(&data[12], &UDP_ESC_Front_Speed_RC, 1);
}

void UDP_ESC_Rear_Speed_Handler(uint8* data)
{
	memcpy(&data[0], &ESC_WheelSpeed_RL, 4);
	memcpy(&data[4], &ESC_WheelSpeed_RR, 4);
	memcpy(&data[8], &ESC_WheelSpeed_ValueError_RL, 1);
	memcpy(&data[9], &ESC_WheelSpeed_ValueError_RR, 1);
	memcpy(&data[10], &UDP_ESC_Rear_Speed_RC, 1);
}

void UDP_ESC_Veh_Speed_Handler(uint8* data)
{
	memcpy(&data[0], &ESC_VehicleSpeed, 4);
	memcpy(&data[4], &ESC_VehicleSpeed_ValueError, 1);
	memcpy(&data[5], &ESC_CtlActiveAbs, 1);
	memcpy(&data[6], &ESC_CtlActiveVdc, 1);
	memcpy(&data[7], &UDP_ESC_Veh_Speed_RC, 1);
}

void UDP_ESC_YR_Handler(uint8* data)
{
	memcpy(&data[0], &ESC_AY_Val, 4);
	memcpy(&data[4], &ESC_AY_Stat, 1);
	memcpy(&data[5], &ESC_PSIP1_Val, 4);
	memcpy(&data[9], &ESC_PSIP1_Stat, 1);
	memcpy(&data[10], &UDP_ESC_YR_RC, 1);
}

void UDP_ESC_AX_Handler(uint8* data)
{
	memcpy(&data[0], &ESC_AX, 4);
	memcpy(&data[4], &ESC_AX_Stat, 1);
	memcpy(&data[5], &UDP_ESC_AX_RC, 1);
}

void UDP_SAS_Handler(uint8* data)
{
	memcpy(&data[0], &SAS_Angle, 4);
	memcpy(&data[4], &SAS_Speed, 4);
	memcpy(&data[8], &SAS_CAL_Stat, 1);
	memcpy(&data[9], &SAS_OK_Stat, 1);
	memcpy(&data[10], &UDP_SAS_RC, 1);
}

void UDP_MAS_Front_Sensor_Handler(uint8* data)
{
	memcpy(&data[0], &MAS_Sensor2_Distance_Val, 1);
	memcpy(&data[1], &MAS_Sensor3_Distance_Val, 1);
	memcpy(&data[2], &MAS_Sensor4_Distance_Val, 1);
	memcpy(&data[3], &MAS_Sensor5_Distance_Val, 1);
	memcpy(&data[4], &UDP_MAS_Front_Sensor_RC, 1);
}

void UDP_MAS_Rear_Sensor_Handler(uint8* data)
{
	memcpy(&data[0], &MAS_Sensor11_Distance_Val, 1);
	memcpy(&data[1], &MAS_Sensor10_Distance_Val, 1);
	memcpy(&data[2], &MAS_Sensor9_Distance_Val, 1);
	memcpy(&data[3], &MAS_Sensor8_Distance_Val, 1);
	memcpy(&data[4], &UDP_MAS_Rear_Sensor_RC, 1);
}

void UDP_MAS_Side_Sensor_Handler(uint8* data)
{
	memcpy(&data[0], &MAS_Sensor1_Distance_Val, 4);
	memcpy(&data[4], &MAS_Sensor6_Distance_Val, 4);
	memcpy(&data[8], &MAS_Sensor12_Distance_Val, 4);
	memcpy(&data[12], &MAS_Sensor7_Distance_Val, 4);
	memcpy(&data[16], &UDP_MAS_Side_Sensor_RC, 1);
}

void UDP_SCU_Handler(uint8* data)
{
	memcpy(&data[0], &SCU_LeftFrHeight, 1);
	memcpy(&data[1], &SCU_RightFrHeight, 1);
	memcpy(&data[2], &SCU_LeftRearHeight, 1);
	memcpy(&data[3], &SCU_RightRearHeight, 1);
	memcpy(&data[4], &UDP_SCU_RC, 1);
}

void UDP_IC_ABSOLUTE_CLOCK_Handler(uint8* data)
{
	memcpy(&data[0], &IC_AbsoluteDateAndTime, 4);
	memcpy(&data[4], &UDP_IC_ABSOLUTE_CLOCK_RC, 1);
}

void UDP_IC_HUD_01_Handler(uint8* data)
{
	memcpy(&data[0], &IC_Speed, 4);
	memcpy(&data[4], &UDP_IC_HUD_01_RC, 1);
}

void UDP_Diag_Config_Handler(uint8* data)
{
	memcpy(&data[0], &McuDiagSession, 1);
	memcpy(&data[1], &DfDiagFrontRadarAvail, 1);
	memcpy(&data[2], &DfDiagThermalCameraAvail, 1);
	memcpy(&data[3], &DfDiagLidarAvail, 1);
	memcpy(&data[4], &DfDiagRearRadarAvail, 1);
	memcpy(&data[5], &McuRRCalibSts, 1);
	memcpy(&data[6], &McuRRL_AngVal, 4);
	memcpy(&data[10], &McuRRR_AngVal, 4);
	memcpy(&data[14], &McuRRErrorSts, 1);
	memcpy(&data[15], &DfDiagBodyType, 1);
	memcpy(&data[16], &DfDiagArmorType, 1);
	memcpy(&data[17], &DfDiagPowerType, 1);
	memcpy(&data[18], &DfDiagSteeringRackType, 1);
	memcpy(&data[19], &DfDiagRearSteeringActuatorAvail, 1);
	memcpy(&data[20], &SettRecResol, 1);
	memcpy(&data[21], &SettRecFileSize, 1);
	memcpy(&data[22], &UDP_Diag_Config_RC, 1);
}

void UDP_Diag_Calibration_Handler(uint8* data)
{
	memcpy(&data[0], &McuFrcuVirtAngReset, 1);
	memcpy(&data[1], &McuFrcuGetImg, 1);
	memcpy(&data[2], &McuFrcuAngRead, 1);
	memcpy(&data[3], &McuFcuVirtAngReset, 1);
	memcpy(&data[4], &McuFcuSetYawfAngle, 4);
	memcpy(&data[8], &McuFcuSetPitchAngle, 4);
	memcpy(&data[12], &McuFcuCalibStart, 1);
	memcpy(&data[13], &McuFcuCalibStop, 1);
	memcpy(&data[14], &McuFcuGetWideImg, 1);
	memcpy(&data[15], &McuFcuGetNarrImg, 1);
	memcpy(&data[16], &McuTicuCalibStart, 1);
	memcpy(&data[17], &McuTicuCalibStop, 1);
	memcpy(&data[18], &McuTicuGetThermImg, 1);
	memcpy(&data[19], &McuLidCalibStart, 1);
	memcpy(&data[20], &McuLidCalibStop, 1);
	memcpy(&data[21], &McuLidGetLidarImg, 1);
	memcpy(&data[22], &UDP_Diag_Calibration_RC, 1);
}

void UDP_FanSpeedControl_Handler(uint8* data)
{
	memcpy(&data[0], &FanSpeedReq, 1);
	memcpy(&data[1], &UDP_FanSpeedControl_RC, 1);
}

void UDP_ERAG_Handler(uint8* data)
{
	memcpy(&data[0], &g_trust_status, 1);
	memcpy(&data[1], &ERAG_Longitude_degrees, 1);
	memcpy(&data[2], &ERAG_Longitude_min, 1);
	memcpy(&data[3], &ERAG_Longitude_min_fract, 4);
	memcpy(&data[7], &ERAG_Longitude_sign, 1);
	memcpy(&data[8], &ERAG_Latitude_degrees, 1);
	memcpy(&data[9], &ERAG_Latitude_min, 1);
	memcpy(&data[10], &ERAG_Latitude_min_fract, 4);
	memcpy(&data[14], &ERAG_Latitude_sign, 1);
	memcpy(&data[15], &ERAG_Year, 2);
	memcpy(&data[17], &ERAG_Month, 1);
	memcpy(&data[18], &ERAG_Day, 1);
	memcpy(&data[19], &ERAG_Hours, 1);
	memcpy(&data[20], &ERAG_Minutes, 1);
	memcpy(&data[21], &ERAG_Seconds, 1);
	memcpy(&data[22], &ERAG_Speed, 4);
	memcpy(&data[26], &ERAG_Course, 4);
	memcpy(&data[30], &UDP_ERAG_RC, 1);
}

void UDP_TCU_R932_1_Handler(uint8* data)
{
	memcpy(&data[0], &stGearLvr, 1);
	memcpy(&data[1], &UDP_TCU_R932_1_RC, 1);
}

void UDP_MainDataFromPerc_Handler(uint8* data)
{
	memcpy(&DfPercFcuDirtSts, &data[0], 1);
	memcpy(&DfPercFrcuDirtSts, &data[1], 1);
	memcpy(&DfPercTicuDirtSts, &data[2], 1);
	memcpy(&DfPercMrrxDirtSts, &data[3], 1);
	memcpy(&DfPercLidarDirtSts, &data[4], 1);
	memcpy(&DfPercValidDataFront, &data[5], 1);
	memcpy(&DfPercValidDataRear, &data[6], 1);
	memcpy(&DfPercValidDataLane, &data[7], 1);
	memcpy(&DfPercValidDataSign, &data[8], 1);
	memcpy(&DfPercValidDataMlia, &data[9], 1);
	memcpy(&UDP_MainDataFromPerc_RC, &data[10], 1);

//	fUdp1Rcv = 1;
}

void UDP_FrontPas_Handler(uint8* data)
{
	memcpy(&DfFPObj1detect, &data[0], 1);
	memcpy(&DfFPObj1Sx1, &data[1], 4);
	memcpy(&DfFPObj1Sy1, &data[5], 4);
	memcpy(&DfFPObj1Sx2, &data[9], 4);
	memcpy(&DfFPObj1Sy2, &data[13], 4);
	memcpy(&DfFPObj1Vx, &data[17], 4);
	memcpy(&DfFPObj1Vy, &data[21], 4);
	memcpy(&DfFPObj1type, &data[25], 1);
	memcpy(&DfFPObj1Orient, &data[26], 4);
	memcpy(&DfFPObj1DynamID, &data[30], 1);
	memcpy(&DfFPObj1Probabil, &data[31], 1);
	memcpy(&DfFPObj2detect, &data[32], 1);
	memcpy(&DfFPObj2Sx1, &data[33], 4);
	memcpy(&DfFPObj2Sy1, &data[37], 4);
	memcpy(&DfFPObj2Sx2, &data[41], 4);
	memcpy(&DfFPObj2Sy2, &data[45], 4);
	memcpy(&DfFPObj2Vx, &data[49], 4);
	memcpy(&DfFPObj2Vy, &data[53], 4);
	memcpy(&DfFPObj2type, &data[57], 1);
	memcpy(&DfFPObj2Orient, &data[58], 4);
	memcpy(&DfFPObj2DynamID, &data[62], 1);
	memcpy(&DfFPObj2Probabil, &data[63], 1);
	memcpy(&DfFPObj3detect, &data[64], 1);
	memcpy(&DfFPObj3Sx1, &data[65], 4);
	memcpy(&DfFPObj3Sy1, &data[69], 4);
	memcpy(&DfFPObj3Sx2, &data[73], 4);
	memcpy(&DfFPObj3Sy2, &data[77], 4);
	memcpy(&DfFPObj3Vx, &data[81], 4);
	memcpy(&DfFPObj3Vy, &data[85], 4);
	memcpy(&DfFPObj3type, &data[89], 1);
	memcpy(&DfFPObj3Orient, &data[90], 4);
	memcpy(&DfFPObj3DynamID, &data[94], 1);
	memcpy(&DfFPObj3Probabil, &data[95], 1);
	memcpy(&DfFPObj4detect, &data[96], 1);
	memcpy(&DfFPObj4Sx1, &data[97], 4);
	memcpy(&DfFPObj4Sy1, &data[101], 4);
	memcpy(&DfFPObj4Sx2, &data[105], 4);
	memcpy(&DfFPObj4Sy2, &data[109], 4);
	memcpy(&DfFPObj4Vx, &data[113], 4);
	memcpy(&DfFPObj4Vy, &data[117], 4);
	memcpy(&DfFPObj4type, &data[121], 1);
	memcpy(&DfFPObj4Orient, &data[122], 4);
	memcpy(&DfFPObj4DynamID, &data[126], 1);
	memcpy(&DfFPObj4Probabil, &data[127], 1);
	memcpy(&DfFPObj5detect, &data[128], 1);
	memcpy(&DfFPObj5Sx1, &data[129], 4);
	memcpy(&DfFPObj5Sy1, &data[133], 4);
	memcpy(&DfFPObj5Sx2, &data[137], 4);
	memcpy(&DfFPObj5Sy2, &data[141], 4);
	memcpy(&DfFPObj5Vx, &data[145], 4);
	memcpy(&DfFPObj5Vy, &data[149], 4);
	memcpy(&DfFPObj5type, &data[153], 1);
	memcpy(&DfFPObj5Orient, &data[154], 4);
	memcpy(&DfFPObj5DynamID, &data[158], 1);
	memcpy(&DfFPObj5Probabil, &data[159], 1);
	memcpy(&DfFPObj6detect, &data[160], 1);
	memcpy(&DfFPObj6Sx1, &data[161], 4);
	memcpy(&DfFPObj6Sy1, &data[165], 4);
	memcpy(&DfFPObj6Sx2, &data[169], 4);
	memcpy(&DfFPObj6Sy2, &data[173], 4);
	memcpy(&DfFPObj6Vx, &data[177], 4);
	memcpy(&DfFPObj6Vy, &data[181], 4);
	memcpy(&DfFPObj6type, &data[185], 1);
	memcpy(&DfFPObj6Orient, &data[186], 4);
	memcpy(&DfFPObj6DynamID, &data[190], 1);
	memcpy(&DfFPObj6Probabil, &data[191], 1);
	memcpy(&DfFPObj7detect, &data[192], 1);
	memcpy(&DfFPObj7Sx1, &data[193], 4);
	memcpy(&DfFPObj7Sy1, &data[197], 4);
	memcpy(&DfFPObj7Sx2, &data[201], 4);
	memcpy(&DfFPObj7Sy2, &data[205], 4);
	memcpy(&DfFPObj7Vx, &data[209], 4);
	memcpy(&DfFPObj7Vy, &data[213], 4);
	memcpy(&DfFPObj7type, &data[217], 1);
	memcpy(&DfFPObj7Orient, &data[218], 4);
	memcpy(&DfFPObj7DynamID, &data[222], 1);
	memcpy(&DfFPObj7Probabil, &data[223], 1);
	memcpy(&DfFPObj8detect, &data[224], 1);
	memcpy(&DfFPObj8Sx1, &data[225], 4);
	memcpy(&DfFPObj8Sy1, &data[229], 4);
	memcpy(&DfFPObj8Sx2, &data[233], 4);
	memcpy(&DfFPObj8Sy2, &data[237], 4);
	memcpy(&DfFPObj8Vx, &data[241], 4);
	memcpy(&DfFPObj8Vy, &data[245], 4);
	memcpy(&DfFPObj8type, &data[249], 1);
	memcpy(&DfFPObj8Orient, &data[250], 4);
	memcpy(&DfFPObj8DynamID, &data[254], 1);
	memcpy(&DfFPObj8Probabil, &data[255], 1);
	memcpy(&DfFPObj9detect, &data[256], 1);
	memcpy(&DfFPObj9Sx1, &data[257], 4);
	memcpy(&DfFPObj9Sy1, &data[261], 4);
	memcpy(&DfFPObj9Sx2, &data[265], 4);
	memcpy(&DfFPObj9Sy2, &data[269], 4);
	memcpy(&DfFPObj9Vx, &data[273], 4);
	memcpy(&DfFPObj9Vy, &data[277], 4);
	memcpy(&DfFPObj9type, &data[281], 1);
	memcpy(&DfFPObj9Orient, &data[282], 4);
	memcpy(&DfFPObj9DynamID, &data[286], 1);
	memcpy(&DfFPObj9Probabil, &data[287], 1);
	memcpy(&DfFPObj10detect, &data[288], 1);
	memcpy(&DfFPObj10Sx1, &data[289], 4);
	memcpy(&DfFPObj10Sy1, &data[293], 4);
	memcpy(&DfFPObj10Sx2, &data[297], 4);
	memcpy(&DfFPObj10Sy2, &data[301], 4);
	memcpy(&DfFPObj10Vx, &data[305], 4);
	memcpy(&DfFPObj10Vy, &data[309], 4);
	memcpy(&DfFPObj10type, &data[313], 1);
	memcpy(&DfFPObj10Orient, &data[314], 4);
	memcpy(&DfFPObj10DynamID, &data[318], 1);
	memcpy(&DfFPObj10Probabil, &data[319], 1);
	memcpy(&DfFPObj11detect, &data[320], 1);
	memcpy(&DfFPObj11Sx1, &data[321], 4);
	memcpy(&DfFPObj11Sy1, &data[325], 4);
	memcpy(&DfFPObj11Sx2, &data[329], 4);
	memcpy(&DfFPObj11Sy2, &data[333], 4);
	memcpy(&DfFPObj11Vx, &data[337], 4);
	memcpy(&DfFPObj11Vy, &data[341], 4);
	memcpy(&DfFPObj11type, &data[345], 1);
	memcpy(&DfFPObj11Orient, &data[346], 4);
	memcpy(&DfFPObj11DynamID, &data[350], 1);
	memcpy(&DfFPObj11Probabil, &data[351], 1);
	memcpy(&UDP_FrontPas_RC, &data[352], 1);

//	fUdp2Rcv = 1;
}

void UDP_RearPass_Handler(uint8* data)
{
	memcpy(&DfRPObj12detect, &data[0], 1);
	memcpy(&DfRPObj12Sx1, &data[1], 4);
	memcpy(&DfRPObj12Sy1, &data[5], 4);
	memcpy(&DfRPObj12Sx2, &data[9], 4);
	memcpy(&DfRPObj12Sy2, &data[13], 4);
	memcpy(&DfRPObj12Vx, &data[17], 4);
	memcpy(&DfRPObj12Vy, &data[21], 4);
	memcpy(&DfRPObj12DynamID, &data[25], 1);
	memcpy(&DfRPObj12Probabil, &data[26], 1);
	memcpy(&DfRPObj13detect, &data[27], 1);
	memcpy(&DfRPObj13Sx1, &data[28], 4);
	memcpy(&DfRPObj13Sy1, &data[32], 4);
	memcpy(&DfRPObj13Sx2, &data[36], 4);
	memcpy(&DfRPObj13Sy2, &data[40], 4);
	memcpy(&DfRPObj13Vx, &data[44], 4);
	memcpy(&DfRPObj13Vy, &data[48], 4);
	memcpy(&DfRPObj13DynamID, &data[52], 1);
	memcpy(&DfRPObj13Probabil, &data[53], 1);
	memcpy(&DfRPObj14detect, &data[54], 1);
	memcpy(&DfRPObj14Sx1, &data[55], 4);
	memcpy(&DfRPObj14Sy1, &data[59], 4);
	memcpy(&DfRPObj14Sx2, &data[63], 4);
	memcpy(&DfRPObj14Sy2, &data[67], 4);
	memcpy(&DfRPObj14Vx, &data[71], 4);
	memcpy(&DfRPObj14Vy, &data[75], 4);
	memcpy(&DfRPObj14DynamID, &data[79], 1);
	memcpy(&DfRPObj14Probabil, &data[80], 1);
	memcpy(&DfRPObj15detect, &data[81], 1);
	memcpy(&DfRPObj15Sx1, &data[82], 4);
	memcpy(&DfRPObj15Sy1, &data[86], 4);
	memcpy(&DfRPObj15Sx2, &data[90], 4);
	memcpy(&DfRPObj15Sy2, &data[94], 4);
	memcpy(&DfRPObj15Vx, &data[98], 4);
	memcpy(&DfRPObj15Vy, &data[102], 4);
	memcpy(&DfRPObj15DynamID, &data[106], 1);
	memcpy(&DfRPObj15Probabil, &data[107], 1);
	memcpy(&DfRPObj16detect, &data[108], 1);
	memcpy(&DfRPObj16Sx1, &data[109], 4);
	memcpy(&DfRPObj16Sy1, &data[113], 4);
	memcpy(&DfRPObj16Sx2, &data[117], 4);
	memcpy(&DfRPObj16Sy2, &data[121], 4);
	memcpy(&DfRPObj16Vx, &data[125], 4);
	memcpy(&DfRPObj16Vy, &data[129], 4);
	memcpy(&DfRPObj16DynamID, &data[133], 1);
	memcpy(&DfRPObj16Probabil, &data[134], 1);
	memcpy(&DfRPObj17detect, &data[135], 1);
	memcpy(&DfRPObj17Sx1, &data[136], 4);
	memcpy(&DfRPObj17Sy1, &data[140], 4);
	memcpy(&DfRPObj17Sx2, &data[144], 4);
	memcpy(&DfRPObj17Sy2, &data[148], 4);
	memcpy(&DfRPObj17Vx, &data[152], 4);
	memcpy(&DfRPObj17Vy, &data[156], 4);
	memcpy(&DfRPObj17DynamID, &data[160], 1);
	memcpy(&DfRPObj17Probabil, &data[161], 1);
	memcpy(&DfRPObj18detect, &data[162], 1);
	memcpy(&DfRPObj18Sx1, &data[163], 4);
	memcpy(&DfRPObj18Sy1, &data[167], 4);
	memcpy(&DfRPObj18Sx2, &data[171], 4);
	memcpy(&DfRPObj18Sy2, &data[175], 4);
	memcpy(&DfRPObj18Vx, &data[179], 4);
	memcpy(&DfRPObj18Vy, &data[183], 4);
	memcpy(&DfRPObj18DynamID, &data[187], 1);
	memcpy(&DfRPObj18Probabil, &data[188], 1);
	memcpy(&UDP_RearPass_RC, &data[189], 1);

//	fUdp3Rcv = 1;
}

void UDP_Lane_Handler(uint8* data)
{
	memcpy(&DfLanePFrontLSx0, &data[0], 4);
	memcpy(&DfLanePFrontLSxFA, &data[4], 4);
	memcpy(&DfLanePFrontLSx10, &data[8], 4);
	memcpy(&DfLanePFrontLSx15, &data[12], 4);
	memcpy(&DfLanePFrontLSx20, &data[16], 4);
	memcpy(&DfLanePFrontLSx25, &data[20], 4);
	memcpy(&DfLanePFrontLSx30, &data[24], 4);
	memcpy(&DfLanePFrontLSx40, &data[28], 4);
	memcpy(&DfLanePFrontLSx50, &data[32], 4);
	memcpy(&DfLanePFrontLSx60, &data[36], 4);
	memcpy(&DfLanePFrontLSx70, &data[40], 4);
	memcpy(&DfLanePFrontLSx80, &data[44], 4);
	memcpy(&DfLanePFrontLSx90, &data[48], 4);
	memcpy(&DfLanePFrontLSx100, &data[52], 4);
	memcpy(&DfLanePFrontLColor, &data[56], 1);
	memcpy(&DfLanePFrontLType, &data[57], 1);
	memcpy(&DfLanePFrontRSx0, &data[58], 4);
	memcpy(&DfLanePFrontRSxFA, &data[62], 4);
	memcpy(&DfLanePFrontRSx10 , &data[66], 4);
	memcpy(&DfLanePFrontRSx15 , &data[70], 4);
	memcpy(&DfLanePFrontRSx20, &data[74], 4);
	memcpy(&DfLanePFrontRSx25, &data[78], 4);
	memcpy(&DfLanePFrontRSx30, &data[82], 4);
	memcpy(&DfLanePFrontRSx40, &data[86], 4);
	memcpy(&DfLanePFrontRSx50, &data[90], 4);
	memcpy(&DfLanePFrontRSx60, &data[94], 4);
	memcpy(&DfLanePFrontRSx70, &data[98], 4);
	memcpy(&DfLanePFrontRSx80, &data[102], 4);
	memcpy(&DfLanePFrontRSx90, &data[106], 4);
	memcpy(&DfLanePFrontRSx100, &data[110], 4);
	memcpy(&DfLanePFrontRColor, &data[114], 1);
	memcpy(&DfLanePFrontRType, &data[115], 1);
	memcpy(&DfLanePRearLSx5, &data[116], 4);
	memcpy(&DfLanePRearLSx10, &data[120], 4);
	memcpy(&DfLanePRearLSx20, &data[124], 4);
	memcpy(&DfLanePRearLSx30, &data[128], 4);
	memcpy(&DfLanePRearLSx40, &data[132], 4);
	memcpy(&DfLanePRearLSx50, &data[136], 4);
	memcpy(&DfLanePRearLSx60, &data[140], 4);
	memcpy(&DfLanePRearLSx70, &data[144], 4);
	memcpy(&DfLanePRearLSx80, &data[148], 4);
	memcpy(&DfLanePRearLSx90, &data[152], 4);
	memcpy(&DfLanePRearLSx100, &data[156], 4);
	memcpy(&DfLanePRearRSx5, &data[160], 4);
	memcpy(&DfLanePRearRSx10, &data[164], 4);
	memcpy(&DfLanePRearRSx20, &data[168], 4);
	memcpy(&DfLanePRearRSx30, &data[172], 4);
	memcpy(&DfLanePRearRSx40, &data[176], 4);
	memcpy(&DfLanePRearRSx50, &data[180], 4);
	memcpy(&DfLanePRearRSx60, &data[184], 4);
	memcpy(&DfLanePRearRSx70, &data[188], 4);
	memcpy(&DfLanePRearRSx80, &data[192], 4);
	memcpy(&DfLanePRearRSx90, &data[196], 4);
	memcpy(&DfLanePRearRSx100, &data[200], 4);
	memcpy(&DfLanePTrgtLineS0, &data[204], 4);
	memcpy(&DfLanePTrgtLineS1, &data[208], 4);
	memcpy(&DfLanePTrgtLineS2, &data[212], 4);
	memcpy(&DfLanePTrgtLineS3, &data[216], 4);
	memcpy(&DfLanePTrgtLineS4, &data[220], 4);
	memcpy(&UDP_Lane_RC, &data[224], 1);

	DfLanePFrontLSx0 = (isnan(DfLanePFrontLSx0) || fabs(DfLanePFrontLSx0) > 200.0f) ? 202.0f  : DfLanePFrontLSx0;
	DfLanePFrontLSxFA = (isnan(DfLanePFrontLSxFA) || fabs(DfLanePFrontLSxFA) > 200.0f) ? 202.0f : DfLanePFrontLSxFA;
	DfLanePFrontLSx10 = (isnan(DfLanePFrontLSx10) || fabs(DfLanePFrontLSx10) > 200.0f) ? 202.0f : DfLanePFrontLSx10;
	DfLanePFrontLSx15 = (isnan(DfLanePFrontLSx15) || fabs(DfLanePFrontLSx15) > 200.0f) ? 202.0f : DfLanePFrontLSx15;
	DfLanePFrontLSx20 = (isnan(DfLanePFrontLSx20) || fabs(DfLanePFrontLSx20) > 200.0f) ? 202.0f : DfLanePFrontLSx20;
	DfLanePFrontLSx25 = (isnan(DfLanePFrontLSx25) || fabs(DfLanePFrontLSx25) > 200.0f) ? 202.0f : DfLanePFrontLSx25;
	DfLanePFrontLSx30 = (isnan(DfLanePFrontLSx30) || fabs(DfLanePFrontLSx30) > 200.0f) ? 202.0f : DfLanePFrontLSx30;
	DfLanePFrontLSx40 = (isnan(DfLanePFrontLSx40) || fabs(DfLanePFrontLSx40) > 200.0f) ? 202.0f : DfLanePFrontLSx40;
	DfLanePFrontLSx50 = (isnan(DfLanePFrontLSx50) || fabs(DfLanePFrontLSx50) > 200.0f) ? 202.0f : DfLanePFrontLSx50;
	DfLanePFrontLSx60 = (isnan(DfLanePFrontLSx60) || fabs(DfLanePFrontLSx60) > 200.0f) ? 202.0f : DfLanePFrontLSx60;
	DfLanePFrontLSx70 = (isnan(DfLanePFrontLSx70) || fabs(DfLanePFrontLSx70) > 200.0f) ? 202.0f : DfLanePFrontLSx70;
	DfLanePFrontLSx80 = (isnan(DfLanePFrontLSx80) || fabs(DfLanePFrontLSx80) > 200.0f) ? 202.0f : DfLanePFrontLSx80;
	DfLanePFrontLSx90 = (isnan(DfLanePFrontLSx90) || fabs(DfLanePFrontLSx90) > 200.0f) ? 202.0f : DfLanePFrontLSx90;
	DfLanePFrontLSx100 = (isnan(DfLanePFrontLSx100) || fabs(DfLanePFrontLSx100) > 200.0f) ? 202.0f : DfLanePFrontLSx100;
	DfLanePFrontRSx0 = (isnan(DfLanePFrontRSx0) || fabs(DfLanePFrontRSx0) > 200.0f) ? 202.0f : DfLanePFrontRSx0;
	DfLanePFrontRSxFA = (isnan(DfLanePFrontRSxFA) || fabs(DfLanePFrontRSxFA) > 200.0f) ? 202.0f : DfLanePFrontRSxFA;
	DfLanePFrontRSx10 = (isnan(DfLanePFrontRSx10) || fabs(DfLanePFrontRSx10) > 200.0f) ? 202.0f : DfLanePFrontRSx10;
	DfLanePFrontRSx15 = (isnan(DfLanePFrontRSx15) || fabs(DfLanePFrontRSx15) > 200.0f) ? 202.0f : DfLanePFrontRSx15;
	DfLanePFrontRSx20 = (isnan(DfLanePFrontRSx20) || fabs(DfLanePFrontRSx20) > 200.0f) ? 202.0f : DfLanePFrontRSx20;
	DfLanePFrontRSx25 = (isnan(DfLanePFrontRSx25) || fabs(DfLanePFrontRSx25) > 200.0f) ? 202.0f : DfLanePFrontRSx25;
	DfLanePFrontRSx30 = (isnan(DfLanePFrontRSx30) || fabs(DfLanePFrontRSx30) > 200.0f) ? 202.0f : DfLanePFrontRSx30;
	DfLanePFrontRSx40 = (isnan(DfLanePFrontRSx40) || fabs(DfLanePFrontRSx40) > 200.0f) ? 202.0f : DfLanePFrontRSx40;
	DfLanePFrontRSx50 = (isnan(DfLanePFrontRSx50) || fabs(DfLanePFrontRSx50) > 200.0f) ? 202.0f : DfLanePFrontRSx50;
	DfLanePFrontRSx60 = (isnan(DfLanePFrontRSx60) || fabs(DfLanePFrontRSx60) > 200.0f) ? 202.0f : DfLanePFrontRSx60;
	DfLanePFrontRSx70 = (isnan(DfLanePFrontRSx70) || fabs(DfLanePFrontRSx70) > 200.0f) ? 202.0f : DfLanePFrontRSx70;
	DfLanePFrontRSx80 = (isnan(DfLanePFrontRSx80) || fabs(DfLanePFrontRSx80) > 200.0f) ? 202.0f : DfLanePFrontRSx80;
	DfLanePFrontRSx90 = (isnan(DfLanePFrontRSx90) || fabs(DfLanePFrontRSx90) > 200.0f) ? 202.0f : DfLanePFrontRSx90;
	DfLanePFrontRSx100 = (isnan(DfLanePFrontRSx100) || fabs(DfLanePFrontRSx100) > 200.0f) ? 202.0f : DfLanePFrontRSx100;
	DfLanePRearLSx5 = (isnan(DfLanePRearLSx5) || fabs(DfLanePRearLSx5) > 200.0f) ? 202.0f : DfLanePRearLSx5;
	DfLanePRearLSx10 = (isnan(DfLanePRearLSx10) || fabs(DfLanePRearLSx10) > 200.0f) ? 202.0f : DfLanePRearLSx10;
	DfLanePRearLSx20 = (isnan(DfLanePRearLSx20) || fabs(DfLanePRearLSx20) > 200.0f) ? 202.0f : DfLanePRearLSx20;
	DfLanePRearLSx30 = (isnan(DfLanePRearLSx30) || fabs(DfLanePRearLSx30) > 200.0f) ? 202.0f : DfLanePRearLSx30;
	DfLanePRearLSx40 = (isnan(DfLanePRearLSx40) || fabs(DfLanePRearLSx40) > 200.0f) ? 202.0f : DfLanePRearLSx40;
	DfLanePRearLSx50 = (isnan(DfLanePRearLSx50) || fabs(DfLanePRearLSx50) > 200.0f) ? 202.0f : DfLanePRearLSx50;
	DfLanePRearLSx60 = (isnan(DfLanePRearLSx60) || fabs(DfLanePRearLSx60) > 200.0f) ? 202.0f : DfLanePRearLSx60;
	DfLanePRearLSx70 = (isnan(DfLanePRearLSx70) || fabs(DfLanePRearLSx70) > 200.0f) ? 202.0f : DfLanePRearLSx70;
	DfLanePRearLSx80 = (isnan(DfLanePRearLSx80) || fabs(DfLanePRearLSx80) > 200.0f) ? 202.0f : DfLanePRearLSx80;
	DfLanePRearLSx90 = (isnan(DfLanePRearLSx90) || fabs(DfLanePRearLSx90) > 200.0f) ? 202.0f : DfLanePRearLSx90;
	DfLanePRearLSx100 = (isnan(DfLanePRearLSx100) || fabs(DfLanePRearLSx100) > 200.0f) ? 202.0f : DfLanePRearLSx100;
	DfLanePRearRSx5 = (isnan(DfLanePRearRSx5) || fabs(DfLanePRearRSx5) > 200.0f) ? 202.0f : DfLanePRearRSx5;
	DfLanePRearRSx10 = (isnan(DfLanePRearRSx10) || fabs(DfLanePRearRSx10) > 200.0f) ? 202.0f : DfLanePRearRSx10;
	DfLanePRearRSx20 = (isnan(DfLanePRearRSx20) || fabs(DfLanePRearRSx20) > 200.0f) ? 202.0f : DfLanePRearRSx20;
	DfLanePRearRSx30 = (isnan(DfLanePRearRSx30) || fabs(DfLanePRearRSx30) > 200.0f) ? 202.0f : DfLanePRearRSx30;
	DfLanePRearRSx40 = (isnan(DfLanePRearRSx40) || fabs(DfLanePRearRSx40) > 200.0f) ? 202.0f : DfLanePRearRSx40;
	DfLanePRearRSx50 = (isnan(DfLanePRearRSx50) || fabs(DfLanePRearRSx50) > 200.0f) ? 202.0f : DfLanePRearRSx50;
	DfLanePRearRSx60 = (isnan(DfLanePRearRSx60) || fabs(DfLanePRearRSx60) > 200.0f) ? 202.0f : DfLanePRearRSx60;
	DfLanePRearRSx70 = (isnan(DfLanePRearRSx70) || fabs(DfLanePRearRSx70) > 200.0f) ? 202.0f : DfLanePRearRSx70;
	DfLanePRearRSx80 = (isnan(DfLanePRearRSx80) || fabs(DfLanePRearRSx80) > 200.0f) ? 202.0f : DfLanePRearRSx80;
	DfLanePRearRSx90 = (isnan(DfLanePRearRSx90) || fabs(DfLanePRearRSx90) > 200.0f) ? 202.0f : DfLanePRearRSx90;
	DfLanePRearRSx100 = (isnan(DfLanePRearRSx100) || fabs(DfLanePRearRSx100) > 200.0f) ? 202.0f : DfLanePRearRSx100;
	DfLanePTrgtLineS0 = (isnan(DfLanePTrgtLineS0) || fabs(DfLanePTrgtLineS0) > 200.0f) ? 202.0f : DfLanePTrgtLineS0;
	DfLanePTrgtLineS1 = (isnan(DfLanePTrgtLineS1) || fabs(DfLanePTrgtLineS1) > 200.0f) ? 202.0f : DfLanePTrgtLineS1;
	DfLanePTrgtLineS2 = (isnan(DfLanePTrgtLineS2) || fabs(DfLanePTrgtLineS2) > 200.0f) ? 202.0f : DfLanePTrgtLineS2;
	DfLanePTrgtLineS3 = (isnan(DfLanePTrgtLineS3) || fabs(DfLanePTrgtLineS3) > 200.0f) ? 202.0f : DfLanePTrgtLineS3;
	DfLanePTrgtLineS4 = (isnan(DfLanePTrgtLineS4) || fabs(DfLanePTrgtLineS4) > 200.0f) ? 202.0f : DfLanePTrgtLineS4;

	//	fUdp4Rcv = 1;
}

void UDP_SignPerc_Handler(uint8* data)
{
	memcpy(&DfSignPerc1Obj_detect, &data[0], 1);
	memcpy(&DfSignPerc1Sx, &data[1], 4);
	memcpy(&DfSignPerc1Sy, &data[5], 4);
	memcpy(&DfSignPerc1CurrSpeed, &data[9], 1);
	memcpy(&DfSignPerc1Color, &data[10], 1);
	memcpy(&DfSignPerc1Type, &data[11], 1);
	memcpy(&DfSignPerc2Obj_detect, &data[12], 1);
	memcpy(&DfSignPerc2Sx, &data[13], 4);
	memcpy(&DfSignPerc2Sy, &data[17], 4);
	memcpy(&DfSignPerc2CurrSpeed, &data[21], 1);
	memcpy(&DfSignPerc2Color, &data[22], 1);
	memcpy(&DfSignPerc2Type, &data[23], 1);
	memcpy(&DfSignPerc3Obj_detect, &data[24], 1);
	memcpy(&DfSignPerc3Sx, &data[25], 4);
	memcpy(&DfSignPerc3Sy, &data[29], 4);
	memcpy(&DfSignPerc3CurrSpeed, &data[33], 1);
	memcpy(&DfSignPerc3Color, &data[34], 1);
	memcpy(&DfSignPerc3Type, &data[35], 1);
	memcpy(&DfSignPerc4Obj_detect, &data[36], 1);
	memcpy(&DfSignPerc4Sx, &data[37], 4);
	memcpy(&DfSignPerc4Sy, &data[41], 4);
	memcpy(&DfSignPerc4CurrSpeed, &data[45], 1);
	memcpy(&DfSignPerc4Color, &data[46], 1);
	memcpy(&DfSignPerc4Type, &data[47], 1);
	memcpy(&UDP_SignPerc_RC, &data[48], 1);

//	fUdp5Rcv = 1;
}

void UDP_MliaPerc_Handler(uint8* data)
{
	memcpy(&DfMliaPercStreetLightDetect, &data[0], 1);
	memcpy(&DfMliaPercObj1Detect, &data[1], 1);
	memcpy(&DfMliaPercObj1Sx1, &data[2], 4);
	memcpy(&DfMliaPercObj1Sy1, &data[6], 4);
	memcpy(&DfMliaPercObj1Sx2, &data[10], 4);
	memcpy(&DfMliaPercObj1Sy2, &data[14], 4);
	memcpy(&DfMliaPercObj1Vel, &data[18], 4);
	memcpy(&DfMliaPercObj1Precision, &data[22], 1);
	memcpy(&DfMliaPercObj1LightSts, &data[23], 1);
	memcpy(&DfMliaPercObj1Sz, &data[24], 4);
	memcpy(&DfMliaPercObj2Detect, &data[28], 1);
	memcpy(&DfMliaPercObj2Sx1, &data[29], 4);
	memcpy(&DfMliaPercObj2Sy1, &data[33], 4);
	memcpy(&DfMliaPercObj2Sx2, &data[37], 4);
	memcpy(&DfMliaPercObj2Sy2, &data[41], 4);
	memcpy(&DfMliaPercObj2Vel, &data[45], 4);
	memcpy(&DfMliaPercObj2Precision, &data[49], 1);
	memcpy(&DfMliaPercObj2LightSts, &data[50], 1);
	memcpy(&DfMliaPercObj2Sz, &data[51], 4);
	memcpy(&DfMliaPercObj3Detect, &data[55], 1);
	memcpy(&DfMliaPercObj3Sx1, &data[56], 4);
	memcpy(&DfMliaPercObj3Sy1, &data[60], 4);
	memcpy(&DfMliaPercObj3Sx2, &data[64], 4);
	memcpy(&DfMliaPercObj3Sy2, &data[68], 4);
	memcpy(&DfMliaPercObj3Vel, &data[72], 4);
	memcpy(&DfMliaPercObj3Precision, &data[76], 1);
	memcpy(&DfMliaPercObj3LightSts, &data[77], 1);
	memcpy(&DfMliaPercObj3Sz, &data[78], 4);
	memcpy(&DfMliaPercObj4Detect, &data[82], 1);
	memcpy(&DfMliaPercObj4Sx1, &data[83], 4);
	memcpy(&DfMliaPercObj4Sy1, &data[87], 4);
	memcpy(&DfMliaPercObj4Sx2, &data[91], 4);
	memcpy(&DfMliaPercObj4Sy2, &data[95], 4);
	memcpy(&DfMliaPercObj4Vel, &data[99], 4);
	memcpy(&DfMliaPercObj4Precision, &data[103], 1);
	memcpy(&DfMliaPercObj4LightSts, &data[104], 1);
	memcpy(&DfMliaPercObj4Sz, &data[105], 4);
	memcpy(&DfMliaPercObj5Detect, &data[109], 1);
	memcpy(&DfMliaPercObj5Sx1, &data[110], 4);
	memcpy(&DfMliaPercObj5Sy1, &data[114], 4);
	memcpy(&DfMliaPercObj5Sx2, &data[118], 4);
	memcpy(&DfMliaPercObj5Sy2, &data[122], 4);
	memcpy(&DfMliaPercObj5Vel, &data[126], 4);
	memcpy(&DfMliaPercObj5Precision, &data[130], 1);
	memcpy(&DfMliaPercObj5LightSts, &data[131], 1);
	memcpy(&DfMliaPercObj5Sz, &data[132], 4);
	memcpy(&DfMliaPercObj6Detect, &data[136], 1);
	memcpy(&DfMliaPercObj6Sx1, &data[137], 4);
	memcpy(&DfMliaPercObj6Sy1, &data[141], 4);
	memcpy(&DfMliaPercObj6Sx2, &data[145], 4);
	memcpy(&DfMliaPercObj6Sy2, &data[149], 4);
	memcpy(&DfMliaPercObj6Vel, &data[153], 4);
	memcpy(&DfMliaPercObj6Precision, &data[157], 1);
	memcpy(&DfMliaPercObj6LightSts, &data[158], 1);
	memcpy(&DfMliaPercObj6Sz, &data[159], 4);
	memcpy(&DfMliaPercObj7Detect, &data[163], 1);
	memcpy(&DfMliaPercObj7Sx1, &data[164], 4);
	memcpy(&DfMliaPercObj7Sy1, &data[168], 4);
	memcpy(&DfMliaPercObj7Sx2, &data[172], 4);
	memcpy(&DfMliaPercObj7Sy2, &data[176], 4);
	memcpy(&DfMliaPercObj7Vel, &data[180], 4);
	memcpy(&DfMliaPercObj7Precision, &data[184], 1);
	memcpy(&DfMliaPercObj7LightSts, &data[185], 1);
	memcpy(&DfMliaPercObj7Sz, &data[186], 4);
	memcpy(&DfMliaPercObj8Detect, &data[190], 1);
	memcpy(&DfMliaPercObj8Sx1, &data[191], 4);
	memcpy(&DfMliaPercObj8Sy1, &data[195], 4);
	memcpy(&DfMliaPercObj8Sx2, &data[199], 4);
	memcpy(&DfMliaPercObj8Sy2, &data[203], 4);
	memcpy(&DfMliaPercObj8Vel, &data[207], 4);
	memcpy(&DfMliaPercObj8Precision, &data[211], 1);
	memcpy(&DfMliaPercObj8LightSts, &data[212], 1);
	memcpy(&DfMliaPercObj8Sz, &data[213], 4);
	memcpy(&DfMliaPercObj9Detect, &data[217], 1);
	memcpy(&DfMliaPercObj9Sx1, &data[218], 4);
	memcpy(&DfMliaPercObj9Sy1, &data[222], 4);
	memcpy(&DfMliaPercObj9Sx2, &data[226], 4);
	memcpy(&DfMliaPercObj9Sy2, &data[230], 4);
	memcpy(&DfMliaPercObj9Vel, &data[234], 4);
	memcpy(&DfMliaPercObj9Precision, &data[238], 1);
	memcpy(&DfMliaPercObj9LightSts, &data[239], 1);
	memcpy(&DfMliaPercObj9Sz, &data[240], 4);
	memcpy(&DfMliaPercObj10Detect, &data[244], 1);
	memcpy(&DfMliaPercObj10Sx1, &data[245], 4);
	memcpy(&DfMliaPercObj10Sy1, &data[249], 4);
	memcpy(&DfMliaPercObj10Sx2, &data[253], 4);
	memcpy(&DfMliaPercObj10Sy2, &data[257], 4);
	memcpy(&DfMliaPercObj10Vel, &data[261], 4);
	memcpy(&DfMliaPercObj10Precision, &data[265], 1);
	memcpy(&DfMliaPercObj10LightSts, &data[266], 1);
	memcpy(&DfMliaPercObj10Sz, &data[267], 4);
	memcpy(&DfMliaPercObj11Detect, &data[271], 1);
	memcpy(&DfMliaPercObj11Sx1, &data[272], 4);
	memcpy(&DfMliaPercObj11Sy1, &data[276], 4);
	memcpy(&DfMliaPercObj11Sx2, &data[280], 4);
	memcpy(&DfMliaPercObj11Sy2, &data[284], 4);
	memcpy(&DfMliaPercObj11Vel, &data[288], 4);
	memcpy(&DfMliaPercObj11Precision, &data[292], 1);
	memcpy(&DfMliaPercObj11LightSts, &data[293], 1);
	memcpy(&DfMliaPercObj11Sz, &data[294], 4);
	memcpy(&DfMliaPercObj12Detect, &data[298], 1);
	memcpy(&DfMliaPercObj12Sx1, &data[299], 4);
	memcpy(&DfMliaPercObj12Sy1, &data[303], 4);
	memcpy(&DfMliaPercObj12Sx2, &data[307], 4);
	memcpy(&DfMliaPercObj12Sy2, &data[311], 4);
	memcpy(&DfMliaPercObj12Vel, &data[315], 4);
	memcpy(&DfMliaPercObj12Precision, &data[319], 1);
	memcpy(&DfMliaPercObj12LightSts, &data[320], 1);
	memcpy(&DfMliaPercObj12Sz, &data[321], 4);
	memcpy(&DfMliaPercObj13Detect, &data[325], 1);
	memcpy(&DfMliaPercObj13Sx1, &data[326], 4);
	memcpy(&DfMliaPercObj13Sy1, &data[330], 4);
	memcpy(&DfMliaPercObj13Sx2, &data[334], 4);
	memcpy(&DfMliaPercObj13Sy2, &data[338], 4);
	memcpy(&DfMliaPercObj13Vel, &data[342], 4);
	memcpy(&DfMliaPercObj13Precision, &data[346], 1);
	memcpy(&DfMliaPercObj13LightSts, &data[347], 1);
	memcpy(&DfMliaPercObj13Sz, &data[348], 4);
	memcpy(&DfMliaPercObj14Detect, &data[352], 1);
	memcpy(&DfMliaPercObj14Sx1, &data[353], 4);
	memcpy(&DfMliaPercObj14Sy1, &data[357], 4);
	memcpy(&DfMliaPercObj14Sx2, &data[361], 4);
	memcpy(&DfMliaPercObj14Sy2, &data[365], 4);
	memcpy(&DfMliaPercObj14Vel, &data[369], 4);
	memcpy(&DfMliaPercObj14Precision, &data[373], 1);
	memcpy(&DfMliaPercObj14LightSts, &data[374], 1);
	memcpy(&DfMliaPercObj14Sz, &data[375], 4);
	memcpy(&DfMliaPercObj15Detect, &data[379], 1);
	memcpy(&DfMliaPercObj15Sx1, &data[380], 4);
	memcpy(&DfMliaPercObj15Sy1, &data[384], 4);
	memcpy(&DfMliaPercObj15Sx2, &data[388], 4);
	memcpy(&DfMliaPercObj15Sy2, &data[392], 4);
	memcpy(&DfMliaPercObj15Vel, &data[396], 4);
	memcpy(&DfMliaPercObj15Precision, &data[400], 1);
	memcpy(&DfMliaPercObj15LightSts, &data[401], 1);
	memcpy(&DfMliaPercObj15Sz, &data[402], 4);
	memcpy(&DfMliaPercObj16Detect, &data[406], 1);
	memcpy(&DfMliaPercObj16Sx1, &data[407], 4);
	memcpy(&DfMliaPercObj16Sy1, &data[411], 4);
	memcpy(&DfMliaPercObj16Sx2, &data[415], 4);
	memcpy(&DfMliaPercObj16Sy2, &data[419], 4);
	memcpy(&DfMliaPercObj16Vel, &data[423], 4);
	memcpy(&DfMliaPercObj16Precision, &data[427], 1);
	memcpy(&DfMliaPercObj16LightSts, &data[428], 1);
	memcpy(&DfMliaPercObj16Sz, &data[429], 4);
	memcpy(&DfMliaPercObj17Detect, &data[433], 1);
	memcpy(&DfMliaPercObj17Sx1, &data[434], 4);
	memcpy(&DfMliaPercObj17Sy1, &data[438], 4);
	memcpy(&DfMliaPercObj17Sx2, &data[442], 4);
	memcpy(&DfMliaPercObj17Sy2, &data[446], 4);
	memcpy(&DfMliaPercObj17Vel, &data[450], 4);
	memcpy(&DfMliaPercObj17Precision, &data[454], 1);
	memcpy(&DfMliaPercObj17LightSts, &data[455], 1);
	memcpy(&DfMliaPercObj17Sz, &data[456], 4);
	memcpy(&DfMliaPercObj18Detect, &data[460], 1);
	memcpy(&DfMliaPercObj18Sx1, &data[461], 4);
	memcpy(&DfMliaPercObj18Sy1, &data[465], 4);
	memcpy(&DfMliaPercObj18Sx2, &data[469], 4);
	memcpy(&DfMliaPercObj18Sy2, &data[473], 4);
	memcpy(&DfMliaPercObj18Vel, &data[477], 4);
	memcpy(&DfMliaPercObj18Precision, &data[481], 1);
	memcpy(&DfMliaPercObj18LightSts, &data[482], 1);
	memcpy(&DfMliaPercObj18Sz, &data[483], 4);
	memcpy(&DfMliaPercObj19Detect, &data[487], 1);
	memcpy(&DfMliaPercObj19Sx1, &data[488], 4);
	memcpy(&DfMliaPercObj19Sy1, &data[492], 4);
	memcpy(&DfMliaPercObj19Sx2, &data[496], 4);
	memcpy(&DfMliaPercObj19Sy2, &data[500], 4);
	memcpy(&DfMliaPercObj19Vel, &data[504], 4);
	memcpy(&DfMliaPercObj19Precision, &data[508], 1);
	memcpy(&DfMliaPercObj19LightSts, &data[509], 1);
	memcpy(&DfMliaPercObj19Sz, &data[510], 4);
	memcpy(&DfMliaPercObj20Detect, &data[514], 1);
	memcpy(&DfMliaPercObj20Sx1, &data[515], 4);
	memcpy(&DfMliaPercObj20Sy1, &data[519], 4);
	memcpy(&DfMliaPercObj20Sx2, &data[523], 4);
	memcpy(&DfMliaPercObj20Sy2, &data[527], 4);
	memcpy(&DfMliaPercObj20Vel, &data[531], 4);
	memcpy(&DfMliaPercObj20Precision, &data[535], 1);
	memcpy(&DfMliaPercObj20LightSts, &data[536], 1);
	memcpy(&DfMliaPercObj20Sz, &data[537], 4);
	memcpy(&DfMliaPercObj21Detect, &data[541], 1);
	memcpy(&DfMliaPercObj21Sx1, &data[542], 4);
	memcpy(&DfMliaPercObj21Sy1, &data[546], 4);
	memcpy(&DfMliaPercObj21Sx2, &data[550], 4);
	memcpy(&DfMliaPercObj21Sy2, &data[554], 4);
	memcpy(&DfMliaPercObj21Vel, &data[558], 4);
	memcpy(&DfMliaPercObj21Precision, &data[562], 1);
	memcpy(&DfMliaPercObj21LightSts, &data[563], 1);
	memcpy(&DfMliaPercObj21Sz, &data[564], 4);
	memcpy(&UDP_MliaPerc_RC, &data[568], 1);

//	fUdp6Rcv = 1;
}

void UDP_GPU_States_Handler(uint8* data)
{
	memcpy(&DfGpuTemp, &data[0], 4);
	memcpy(&DfGpuFrcuErrorSts, &data[4], 1);
	memcpy(&DfGpuFcuWErrorSts, &data[5], 1);
	memcpy(&DfGpuFcuNErrorSts, &data[6], 1);
	memcpy(&DfGpuTicuErrorSts, &data[7], 1);
	memcpy(&DfGpuLidarErrorSts, &data[8], 1);
	memcpy(&DfGpuFrcuVirtYaw, &data[9], 4);
	memcpy(&DfGpuFrcuProb, &data[13], 4);
	memcpy(&DfGpuFcuCalibSts, &data[17], 1);
	memcpy(&DfGpuFcuStaticAngYaw, &data[18], 4);
	memcpy(&DfGpuFcuStaticAngPitch, &data[22], 4);
	memcpy(&DfGpuFcuVirtYaw, &data[26], 4);
	memcpy(&DfGpuTicuCalibSts, &data[30], 1);
	memcpy(&DfGpuTicuVirtYaw, &data[31], 4);
	memcpy(&DfGpuTicuStaticYaw, &data[35], 4);
	memcpy(&DfGpuTicuStaticPitch, &data[39], 4);
	memcpy(&DfGpuLidCalibSts, &data[43], 1);
	memcpy(&DfGpuLidVirtYaw, &data[44], 4);
	memcpy(&DfGpuLidStaticYaw, &data[48], 4);
	memcpy(&DfGpuLidStaticPitch, &data[52], 4);
	memcpy(&UDP_GPU_States_RC, &data[56], 1);

//	fUdp7Rcv = 1;
}
