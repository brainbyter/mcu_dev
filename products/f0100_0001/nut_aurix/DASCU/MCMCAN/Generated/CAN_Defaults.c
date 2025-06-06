/* THIS FILE WAS GENERATED AUTOMATICALLY 
 * 
 * Source: CodeGenerationSignals.xlsm
 * 
 * CAN_Defaults.c
 * 
 * Generated on: 06.06.2025
 * Author: igor.loginov
*/

#include <CAN_Private.h>

void SetDefault_ACU_01()
{
   FrontBuckleDriver_L = DEFAULT_FrontBuckleDriver_L;
   ACU_CrashEventDetect_Stat = DEFAULT_ACU_CrashEventDetect_Stat;
}


void SetDefault_BCM_CLIMATIC_DATA()
{
   BCM_Wiper_Stat = DEFAULT_BCM_Wiper_Stat;
   SolarSensLeftVal = DEFAULT_SolarSensLeftVal;
   SolarSensRightVal = DEFAULT_SolarSensRightVal;
   FrontWindowHeating_Status = DEFAULT_FrontWindowHeating_Status;
   WindshieldTemp = DEFAULT_WindshieldTemp;
   WindshieldHumidity = DEFAULT_WindshieldHumidity;
   RainDensity = DEFAULT_RainDensity;
   RainDetected = DEFAULT_RainDetected;
}


void SetDefault_BCM_EXT_LGT()
{
   BCM_Proj_Start_Req = DEFAULT_BCM_Proj_Start_Req;
   BCM_TargetLvlALS_Req = DEFAULT_BCM_TargetLvlALS_Req;
   BCM_MLIA_Start_Req = DEFAULT_BCM_MLIA_Start_Req;
   BCM_HighBeam_Req = DEFAULT_BCM_HighBeam_Req;
   BCM_TurnIndR_Req = DEFAULT_BCM_TurnIndR_Req;
   BCM_TurnIndL_Req = DEFAULT_BCM_TurnIndL_Req;
}


void SetDefault_BCM_IC_Info_Msg()
{
   BCM_WasherFluidLevel = DEFAULT_BCM_WasherFluidLevel;
}


void SetDefault_BCM_Lock_CTR()
{
   VehicleLockState = DEFAULT_VehicleLockState;
}


void SetDefault_BCM_RLS_Stat()
{
   RLS_LightFront_Val = DEFAULT_RLS_LightFront_Val;
   RLS_LightAmbient_Val = DEFAULT_RLS_LightAmbient_Val;
   RLS_LightSwReason_Val = DEFAULT_RLS_LightSwReason_Val;
}


void SetDefault_BCM_VEH_STATE()
{
   BCM_VehicleType_Stat = DEFAULT_BCM_VehicleType_Stat;
   BCM_ADASTerm_Stat = DEFAULT_BCM_ADASTerm_Stat;
   BCM_VehicleMode_Stat = DEFAULT_BCM_VehicleMode_Stat;
   BCM_T15_Stat = DEFAULT_BCM_T15_Stat;
   BCM_VehicleBody_Stat = DEFAULT_BCM_VehicleBody_Stat;
}


void SetDefault_BCM_Veh_State2()
{
   BCM_AmbientTempHMI = DEFAULT_BCM_AmbientTempHMI;
   BCM_AdasSensClear_Stat = DEFAULT_BCM_AdasSensClear_Stat;
   BCM_LccBtn_Stat = DEFAULT_BCM_LccBtn_Stat;
   BCM_LdwBtn_Stat = DEFAULT_BCM_LdwBtn_Stat;
}


void SetDefault_CCU_Stat1()
{
   CCU_BlowerSpeedFL_Stat = DEFAULT_CCU_BlowerSpeedFL_Stat;
}


void SetDefault_DMFL_Msg1()
{
   DMFL_IntDoorHandle_Req = DEFAULT_DMFL_IntDoorHandle_Req;
   DMFL_DoorAjarState = DEFAULT_DMFL_DoorAjarState;
}


void SetDefault_DMFR_Msg1()
{
   DMFR_IntDoorHandle_Req = DEFAULT_DMFR_IntDoorHandle_Req;
   DMFR_DoorAjarState = DEFAULT_DMFR_DoorAjarState;
}


void SetDefault_DMRL_Msg1()
{
   DMRL_IntDoorHandle_Req = DEFAULT_DMRL_IntDoorHandle_Req;
   DMRL_DoorAjarState = DEFAULT_DMRL_DoorAjarState;
}


void SetDefault_DMRR_Msg1()
{
   DMRR_IntDoorHandle_Req = DEFAULT_DMRR_IntDoorHandle_Req;
   DMRR_DoorAjarState = DEFAULT_DMRR_DoorAjarState;
}


void SetDefault_BCM_DMS_01()
{
   DrivingMode_Sig = DEFAULT_DrivingMode_Sig;
}


void SetDefault_EMS_14()
{
   EMS_MotDrag_Val = DEFAULT_EMS_MotDrag_Val;
   EMS_MotClutch_Val = DEFAULT_EMS_MotClutch_Val;
}


void SetDefault_EMS_3()
{
   EMS_tqDriverTorqueDmd = DEFAULT_EMS_tqDriverTorqueDmd;
   EMS_ratAccPed_Val = DEFAULT_EMS_ratAccPed_Val;
   EMS_stKickDown = DEFAULT_EMS_stKickDown;
}


void SetDefault_EMS_4()
{
   EMS_nICEngineSpeed1 = DEFAULT_EMS_nICEngineSpeed1;
}


void SetDefault_EPB_Status()
{
   EPB_CurrParkBrake_Stat = DEFAULT_EPB_CurrParkBrake_Stat;
   EPB_DynamicEmergencyApply_Stat = DEFAULT_EPB_DynamicEmergencyApply_Stat;
}


void SetDefault_ESC_02()
{
   ESC_WheelSpeed_ValueError_FR = DEFAULT_ESC_WheelSpeed_ValueError_FR;
   ESC_WheelSpeed_ValueError_FL = DEFAULT_ESC_WheelSpeed_ValueError_FL;
   ESC_WheelDirectionInfo_FR = DEFAULT_ESC_WheelDirectionInfo_FR;
   ESC_WheelDirectionInfo_FL = DEFAULT_ESC_WheelDirectionInfo_FL;
   ESC_WheelSpeed_FR = DEFAULT_ESC_WheelSpeed_FR;
   ESC_WheelSpeed_FL = DEFAULT_ESC_WheelSpeed_FL;
}


void SetDefault_ESC_03()
{
   ESC_WheelSpeed_ValueError_RR = DEFAULT_ESC_WheelSpeed_ValueError_RR;
   ESC_WheelSpeed_ValueError_RL = DEFAULT_ESC_WheelSpeed_ValueError_RL;
   ESC_WheelSpeed_RR = DEFAULT_ESC_WheelSpeed_RR;
   ESC_WheelSpeed_RL = DEFAULT_ESC_WheelSpeed_RL;
}


void SetDefault_ESC_04()
{
   ESC_CtlActiveEbd = DEFAULT_ESC_CtlActiveEbd;
   ESC_VehicleSpeed_ValueError = DEFAULT_ESC_VehicleSpeed_ValueError;
   ESC_VehicleSpeed = DEFAULT_ESC_VehicleSpeed;
   ESC_CtlActiveVdc = DEFAULT_ESC_CtlActiveVdc;
   ESC_HDC_Activated = DEFAULT_ESC_HDC_Activated;
   ESC_Bla = DEFAULT_ESC_Bla;
   ESC_Bls_Out = DEFAULT_ESC_Bls_Out;
   ESC_CtlActiveTcs = DEFAULT_ESC_CtlActiveTcs;
   ESC_CtlActiveAbs = DEFAULT_ESC_CtlActiveAbs;
}


void SetDefault_ESC_06()
{
   ESC_pWheelFL_Val = DEFAULT_ESC_pWheelFL_Val;
   ESC_pWheelFR_Val = DEFAULT_ESC_pWheelFR_Val;
}


void SetDefault_ESC_07()
{
   ESC_pWheelRR_Val = DEFAULT_ESC_pWheelRR_Val;
   ESC_pWheelRL_Val = DEFAULT_ESC_pWheelRL_Val;
}


void SetDefault_ESC_09()
{
   ESC_BrakePressureMC_Val = DEFAULT_ESC_BrakePressureMC_Val;
}


void SetDefault_ESC_10()
{
   CddVehicleStandstill = DEFAULT_CddVehicleStandstill;
   AebAvailable = DEFAULT_AebAvailable;
   CddActive = DEFAULT_CddActive;
   CddAvailable = DEFAULT_CddAvailable;
   CddTempOff = DEFAULT_CddTempOff;
   CddSkiddingDetected = DEFAULT_CddSkiddingDetected;
}


void SetDefault_ESC_YRS_01()
{
   ESC_PSIP1_Stat = DEFAULT_ESC_PSIP1_Stat;
   ESC_PSIP1_Val = DEFAULT_ESC_PSIP1_Val;
   ESC_AY_Stat = DEFAULT_ESC_AY_Stat;
   ESC_AY_Val = DEFAULT_ESC_AY_Val;
}


void SetDefault_ESC_YRS_02()
{
   ESC_AX_Stat = DEFAULT_ESC_AX_Stat;
   ESC_AX = DEFAULT_ESC_AX;
}


void SetDefault_IC_DMS()
{
   IC_FaceRecognition_Stat = DEFAULT_IC_FaceRecognition_Stat;
   IC_DataReliability_Stat = DEFAULT_IC_DataReliability_Stat;
   IC_GazeOther_Stat = DEFAULT_IC_GazeOther_Stat;
   IC_GazeMedia_Stat = DEFAULT_IC_GazeMedia_Stat;
   IC_GazeDashboard_Stat = DEFAULT_IC_GazeDashboard_Stat;
   IC_GazeCeiling_Stat = DEFAULT_IC_GazeCeiling_Stat;
   IC_GazeRightSideViewMirror_Stat = DEFAULT_IC_GazeRightSideViewMirror_Stat;
   IC_GazeLeftSideViewMirror_Stat = DEFAULT_IC_GazeLeftSideViewMirror_Stat;
   IC_GazeRearViewMirror_Stat = DEFAULT_IC_GazeRearViewMirror_Stat;
   IC_GazeWindshieldRight_Stat = DEFAULT_IC_GazeWindshieldRight_Stat;
   IC_GazeWindshieldLeft_Stat = DEFAULT_IC_GazeWindshieldLeft_Stat;
   IC_GazeWindshieldCentral_Stat = DEFAULT_IC_GazeWindshieldCentral_Stat;
   IC_LvlDistractions_Stat = DEFAULT_IC_LvlDistractions_Stat;
   IC_LvlFatigues_Stat = DEFAULT_IC_LvlFatigues_Stat;
}


void SetDefault_IC_ADAS_REST()
{
   IC_DistBar_Stat = DEFAULT_IC_DistBar_Stat;
   IC_VisualAct_Req = DEFAULT_IC_VisualAct_Req;
   IC_NvAct_Req = DEFAULT_IC_NvAct_Req;
}


void SetDefault_IC_HUD_01()
{
   IC_Speed = DEFAULT_IC_Speed;
}


void SetDefault_IC_ABSOLUTE_CLOCK()
{
   IC_AbsoluteDateAndTime = DEFAULT_IC_AbsoluteDateAndTime;
}


void SetDefault_MAS_Status()
{
   MAS_NegativeTorque_Req = DEFAULT_MAS_NegativeTorque_Req;
   MAS_PostiveTorque_Req = DEFAULT_MAS_PostiveTorque_Req;
   MAS_AutomaticPark_Stat = DEFAULT_MAS_AutomaticPark_Stat;
   MAS_TransmissionState_Req = DEFAULT_MAS_TransmissionState_Req;
   MAS_APADistance_Req = DEFAULT_MAS_APADistance_Req;
   MAS_Activation = DEFAULT_MAS_Activation;
   MAS_Err_Stat = DEFAULT_MAS_Err_Stat;
   MAS_DrivingState_Stat = DEFAULT_MAS_DrivingState_Stat;
}


void SetDefault_MAS_FrontUSS()
{
   MAS_Sensor5_Distance_Val = DEFAULT_MAS_Sensor5_Distance_Val;
   MAS_Sensor4_Distance_Val = DEFAULT_MAS_Sensor4_Distance_Val;
   MAS_Sensor3_Distance_Val = DEFAULT_MAS_Sensor3_Distance_Val;
   MAS_Sensor2_Distance_Val = DEFAULT_MAS_Sensor2_Distance_Val;
}


void SetDefault_MAS_RearUSS()
{
   MAS_Sensor8_Distance_Val = DEFAULT_MAS_Sensor8_Distance_Val;
   MAS_Sensor9_Distance_Val = DEFAULT_MAS_Sensor9_Distance_Val;
   MAS_Sensor10_Distance_Val = DEFAULT_MAS_Sensor10_Distance_Val;
   MAS_Sensor11_Distance_Val = DEFAULT_MAS_Sensor11_Distance_Val;
}


void SetDefault_MAS_SideUSS()
{
   MAS_Sensor7_Distance_Val = DEFAULT_MAS_Sensor7_Distance_Val;
   MAS_Sensor12_Distance_Val = DEFAULT_MAS_Sensor12_Distance_Val;
   MAS_Sensor6_Distance_Val = DEFAULT_MAS_Sensor6_Distance_Val;
   MAS_Sensor1_Distance_Val = DEFAULT_MAS_Sensor1_Distance_Val;
}


void SetDefault_HLL_STATE()
{
   HLL_CorrectorActual_Val = DEFAULT_HLL_CorrectorActual_Val;
}


void SetDefault_HLR_STATE()
{
   HLR_CorrectorActual_Val = DEFAULT_HLR_CorrectorActual_Val;
}


void SetDefault_SAS_Standard()
{
   SAS_OK_Stat = DEFAULT_SAS_OK_Stat;
   SAS_CAL_Stat = DEFAULT_SAS_CAL_Stat;
   SAS_Speed = DEFAULT_SAS_Speed;
   SAS_Angle = DEFAULT_SAS_Angle;
}


void SetDefault_SWM_ContrlsState_Old()
{
   SWM_SETSpeed_Req = DEFAULT_SWM_SETSpeed_Req;
   SWM_UserFunc_Req = DEFAULT_SWM_UserFunc_Req;
   SWM_RES_Req = DEFAULT_SWM_RES_Req;
   SWM_CNCL_Req = DEFAULT_SWM_CNCL_Req;
   SWM_ACC_SpeedIncrease_Stat = DEFAULT_SWM_ACC_SpeedIncrease_Stat;
   SWM_PosHand_Stat = DEFAULT_SWM_PosHand_Stat;
   SWM_ACCDistanceChange_Stat = DEFAULT_SWM_ACCDistanceChange_Stat;
   SWM_ACCactivate_Stat = DEFAULT_SWM_ACCactivate_Stat;
   SWM_ACCSpeedDecrease_Stat = DEFAULT_SWM_ACCSpeedDecrease_Stat;
}


void SetDefault_SWM_ContrlsState()
{
}


void SetDefault_SCU_02()
{
   SCU_RightRearHeight = DEFAULT_SCU_RightRearHeight;
   SCU_LeftRearHeight = DEFAULT_SCU_LeftRearHeight;
   SCU_RightFrHeight = DEFAULT_SCU_RightFrHeight;
   SCU_LeftFrHeight = DEFAULT_SCU_LeftFrHeight;
}


void SetDefault_TCU_R932_1()
{
   numGearTarget = DEFAULT_numGearTarget;
   numGearEngaged = DEFAULT_numGearEngaged;
   gearChangeSPDphase = DEFAULT_gearChangeSPDphase;
   stManualGbxMode = DEFAULT_stManualGbxMode;
   stGearLvr = DEFAULT_stGearLvr;
}


void SetDefault_FIU_Msg3()
{
   FIU_ProjectionOnARoad_Req = DEFAULT_FIU_ProjectionOnARoad_Req;
   FIU_ProjectionLiveObj_Req = DEFAULT_FIU_ProjectionLiveObj_Req;
   FIU_ProjectionNavigation_Req = DEFAULT_FIU_ProjectionNavigation_Req;
   FIU_ProjectionRoadSigns_Req = DEFAULT_FIU_ProjectionRoadSigns_Req;
}


void SetDefault_VCU_ADAS_01()
{
}


void SetDefault_ATC_TX()
{
}


void SetDefault_Diag_Functional()
{
}


void SetDefault_EMS_03()
{
}


void SetDefault_EMS_04()
{
}


void SetDefault_EMS_16()
{
}


void SetDefault_mLEDL_STATE()
{
}


void SetDefault_mLEDR_STATE()
{
}


void SetDefault_RSA_Status()
{
}


void SetDefault_TM_Stat()
{
}


void SetDefault_VCU_DriverDmd()
{
}


void SetDefault_MainStart()
{
}


void SetDefault_Emu_MLIA_Xcp()
{
   Emu_MLIA_HysterCoef = DEFAULT_Emu_MLIA_HysterCoef;
   Emu_MLIA_NarrCoef = DEFAULT_Emu_MLIA_NarrCoef;
   Emu_MLIA_mLED_avail = DEFAULT_Emu_MLIA_mLED_avail;
   Emu_MLIA_ADB_avail = DEFAULT_Emu_MLIA_ADB_avail;
   Emu_MLIA_HLR_avail = DEFAULT_Emu_MLIA_HLR_avail;
   Emu_MLIA_HLL_avail = DEFAULT_Emu_MLIA_HLL_avail;
   Emu_MLIA_Y_ext_500 = DEFAULT_Emu_MLIA_Y_ext_500;
   Emu_MLIA_Y_ext_25 = DEFAULT_Emu_MLIA_Y_ext_25;
   Emu_MLIA_Filter_delay_ON = DEFAULT_Emu_MLIA_Filter_delay_ON;
   Emu_MLIA_Filter_delay_OFF = DEFAULT_Emu_MLIA_Filter_delay_OFF;
   Emu_MLIA_DfDiagMliaHba = DEFAULT_Emu_MLIA_DfDiagMliaHba;
}


void SetDefault_Emu_Blink_Xcp()
{
   Emu_BlinkPeriod = DEFAULT_Emu_BlinkPeriod;
   Emu_BlinkPeriodCheckMode = DEFAULT_Emu_BlinkPeriodCheckMode;
}


void SetDefault_Radar_Rear_ADAS()
{
   ADAS_RCTB_L_W = DEFAULT_ADAS_RCTB_L_W;
   ADAS_DOW_L_W = DEFAULT_ADAS_DOW_L_W;
   ADAS_RCTA_L_W = DEFAULT_ADAS_RCTA_L_W;
   ADAS_BSD_L_W = DEFAULT_ADAS_BSD_L_W;
   ADAS_LCA_L_W = DEFAULT_ADAS_LCA_L_W;
   ADAS_RCTB_R_W = DEFAULT_ADAS_RCTB_R_W;
   ADAS_DOW_R_W = DEFAULT_ADAS_DOW_R_W;
   ADAS_RCTA_R_W = DEFAULT_ADAS_RCTA_R_W;
   ADAS_BSD_R_W = DEFAULT_ADAS_BSD_R_W;
   ADAS_LCA_R_W = DEFAULT_ADAS_LCA_R_W;
   ADAS_RCW_W = DEFAULT_ADAS_RCW_W;
}



