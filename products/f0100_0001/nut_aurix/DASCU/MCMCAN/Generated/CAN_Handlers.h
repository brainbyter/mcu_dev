/* THIS FILE WAS GENERATED AUTOMATICALLY 
 * 
 * Source: CodeGenerationSignals.xlsm
 * 
 * CAN_Handlers.h
 * 
 * Generated on: 06.06.2025
 * Author: igor.loginov
*/

#ifndef _CAN_Handlers_h_
#define _CAN_Handlers_h_

#include <Platform_Types.h>


void ACU_01_Handler(uint8* data, uint8 dlc);
void Diag_ACU_01(uint8* data, uint8 dlc);
void SetDefault_ACU_01();

void BCM_CLIMATIC_DATA_Handler(uint8* data, uint8 dlc);
void Diag_BCM_CLIMATIC_DATA(uint8* data, uint8 dlc);
void SetDefault_BCM_CLIMATIC_DATA();

void BCM_EXT_LGT_Handler(uint8* data, uint8 dlc);
void Diag_BCM_EXT_LGT(uint8* data, uint8 dlc);
void SetDefault_BCM_EXT_LGT();

void BCM_IC_Info_Msg_Handler(uint8* data, uint8 dlc);
void Diag_BCM_IC_Info_Msg(uint8* data, uint8 dlc);
void SetDefault_BCM_IC_Info_Msg();

void BCM_Lock_CTR_Handler(uint8* data, uint8 dlc);
void Diag_BCM_Lock_CTR(uint8* data, uint8 dlc);
void SetDefault_BCM_Lock_CTR();

void BCM_RLS_Stat_Handler(uint8* data, uint8 dlc);
void Diag_BCM_RLS_Stat(uint8* data, uint8 dlc);
void SetDefault_BCM_RLS_Stat();

void BCM_VEH_STATE_Handler(uint8* data, uint8 dlc);
void Diag_BCM_VEH_STATE(uint8* data, uint8 dlc);
void SetDefault_BCM_VEH_STATE();

void BCM_Veh_State2_Handler(uint8* data, uint8 dlc);
void Diag_BCM_Veh_State2(uint8* data, uint8 dlc);
void SetDefault_BCM_Veh_State2();

void CCU_Stat1_Handler(uint8* data, uint8 dlc);
void Diag_CCU_Stat1(uint8* data, uint8 dlc);
void SetDefault_CCU_Stat1();

void DMFL_Msg1_Handler(uint8* data, uint8 dlc);
void Diag_DMFL_Msg1(uint8* data, uint8 dlc);
void SetDefault_DMFL_Msg1();

void DMFR_Msg1_Handler(uint8* data, uint8 dlc);
void Diag_DMFR_Msg1(uint8* data, uint8 dlc);
void SetDefault_DMFR_Msg1();

void DMRL_Msg1_Handler(uint8* data, uint8 dlc);
void Diag_DMRL_Msg1(uint8* data, uint8 dlc);
void SetDefault_DMRL_Msg1();

void DMRR_Msg1_Handler(uint8* data, uint8 dlc);
void Diag_DMRR_Msg1(uint8* data, uint8 dlc);
void SetDefault_DMRR_Msg1();

void BCM_DMS_01_Handler(uint8* data, uint8 dlc);
void Diag_BCM_DMS_01(uint8* data, uint8 dlc);
void SetDefault_BCM_DMS_01();

void EMS_14_Handler(uint8* data, uint8 dlc);
void Diag_EMS_14(uint8* data, uint8 dlc);
void SetDefault_EMS_14();

void EMS_3_Handler(uint8* data, uint8 dlc);
void Diag_EMS_3(uint8* data, uint8 dlc);
void SetDefault_EMS_3();

void EMS_4_Handler(uint8* data, uint8 dlc);
void Diag_EMS_4(uint8* data, uint8 dlc);
void SetDefault_EMS_4();

void EPB_Status_Handler(uint8* data, uint8 dlc);
void Diag_EPB_Status(uint8* data, uint8 dlc);
void SetDefault_EPB_Status();

void ESC_02_Handler(uint8* data, uint8 dlc);
void Diag_ESC_02(uint8* data, uint8 dlc);
void SetDefault_ESC_02();

void ESC_03_Handler(uint8* data, uint8 dlc);
void Diag_ESC_03(uint8* data, uint8 dlc);
void SetDefault_ESC_03();

void ESC_04_Handler(uint8* data, uint8 dlc);
void Diag_ESC_04(uint8* data, uint8 dlc);
void SetDefault_ESC_04();

void ESC_06_Handler(uint8* data, uint8 dlc);
void Diag_ESC_06(uint8* data, uint8 dlc);
void SetDefault_ESC_06();

void ESC_07_Handler(uint8* data, uint8 dlc);
void Diag_ESC_07(uint8* data, uint8 dlc);
void SetDefault_ESC_07();

void ESC_09_Handler(uint8* data, uint8 dlc);
void Diag_ESC_09(uint8* data, uint8 dlc);
void SetDefault_ESC_09();

void ESC_10_Handler(uint8* data, uint8 dlc);
void Diag_ESC_10(uint8* data, uint8 dlc);
void SetDefault_ESC_10();

void ESC_YRS_01_Handler(uint8* data, uint8 dlc);
void Diag_ESC_YRS_01(uint8* data, uint8 dlc);
void SetDefault_ESC_YRS_01();

void ESC_YRS_02_Handler(uint8* data, uint8 dlc);
void Diag_ESC_YRS_02(uint8* data, uint8 dlc);
void SetDefault_ESC_YRS_02();

void IC_DMS_Handler(uint8* data, uint8 dlc);
void Diag_IC_DMS(uint8* data, uint8 dlc);
void SetDefault_IC_DMS();

void IC_ADAS_REST_Handler(uint8* data, uint8 dlc);
void Diag_IC_ADAS_REST(uint8* data, uint8 dlc);
void SetDefault_IC_ADAS_REST();

void IC_HUD_01_Handler(uint8* data, uint8 dlc);
void Diag_IC_HUD_01(uint8* data, uint8 dlc);
void SetDefault_IC_HUD_01();

void IC_ABSOLUTE_CLOCK_Handler(uint8* data, uint8 dlc);
void Diag_IC_ABSOLUTE_CLOCK(uint8* data, uint8 dlc);
void SetDefault_IC_ABSOLUTE_CLOCK();

void MAS_Status_Handler(uint8* data, uint8 dlc);
void Diag_MAS_Status(uint8* data, uint8 dlc);
void SetDefault_MAS_Status();

void MAS_FrontUSS_Handler(uint8* data, uint8 dlc);
void Diag_MAS_FrontUSS(uint8* data, uint8 dlc);
void SetDefault_MAS_FrontUSS();

void MAS_RearUSS_Handler(uint8* data, uint8 dlc);
void Diag_MAS_RearUSS(uint8* data, uint8 dlc);
void SetDefault_MAS_RearUSS();

void MAS_SideUSS_Handler(uint8* data, uint8 dlc);
void Diag_MAS_SideUSS(uint8* data, uint8 dlc);
void SetDefault_MAS_SideUSS();

void HLL_STATE_Handler(uint8* data, uint8 dlc);
void Diag_HLL_STATE(uint8* data, uint8 dlc);
void SetDefault_HLL_STATE();

void HLR_STATE_Handler(uint8* data, uint8 dlc);
void Diag_HLR_STATE(uint8* data, uint8 dlc);
void SetDefault_HLR_STATE();

void SAS_Standard_Handler(uint8* data, uint8 dlc);
void Diag_SAS_Standard(uint8* data, uint8 dlc);
void SetDefault_SAS_Standard();

void SWM_ContrlsState_Old_Handler(uint8* data, uint8 dlc);
void Diag_SWM_ContrlsState_Old(uint8* data, uint8 dlc);
void SetDefault_SWM_ContrlsState_Old();

void SWM_ContrlsState_Handler(uint8* data, uint8 dlc);
void Diag_SWM_ContrlsState(uint8* data, uint8 dlc);
void SetDefault_SWM_ContrlsState();

void SCU_02_Handler(uint8* data, uint8 dlc);
void Diag_SCU_02(uint8* data, uint8 dlc);
void SetDefault_SCU_02();

void TCU_R932_1_Handler(uint8* data, uint8 dlc);
void Diag_TCU_R932_1(uint8* data, uint8 dlc);
void SetDefault_TCU_R932_1();

void FIU_ADAS_Config_Handler(uint8* data, uint8 dlc);

void FIU_Msg3_Handler(uint8* data, uint8 dlc);
void Diag_FIU_Msg3(uint8* data, uint8 dlc);
void SetDefault_FIU_Msg3();

void VCU_ADAS_01_Handler(uint8* data, uint8 dlc);
void Diag_VCU_ADAS_01(uint8* data, uint8 dlc);
void SetDefault_VCU_ADAS_01();

void Diag_From_ERAG_Handler(uint8* data, uint8 dlc);

void ERAG_NMEA1_Handler(uint8* data, uint8 dlc);

void ERAG_NMEA2_Handler(uint8* data, uint8 dlc);

void ERAG_NMEA3_Handler(uint8* data, uint8 dlc);

void ERAG_NMEA4_Handler(uint8* data, uint8 dlc);

void ERAG_NMEA5_Handler(uint8* data, uint8 dlc);

void ERAG_NMEA6_Handler(uint8* data, uint8 dlc);

void ERAG_DATA_MSG_Handler(uint8* data, uint8 dlc);

void ATC_TX_Handler(uint8* data, uint8 dlc);
void Diag_ATC_TX(uint8* data, uint8 dlc);
void SetDefault_ATC_TX();

void Diag_Functional_Handler(uint8* data, uint8 dlc);
void Diag_Diag_Functional(uint8* data, uint8 dlc);
void SetDefault_Diag_Functional();

void Diag_To_DASCU_Handler(uint8* data, uint8 dlc);

void EMS_03_Handler(uint8* data, uint8 dlc);
void Diag_EMS_03(uint8* data, uint8 dlc);
void SetDefault_EMS_03();

void EMS_04_Handler(uint8* data, uint8 dlc);
void Diag_EMS_04(uint8* data, uint8 dlc);
void SetDefault_EMS_04();

void EMS_16_Handler(uint8* data, uint8 dlc);
void Diag_EMS_16(uint8* data, uint8 dlc);
void SetDefault_EMS_16();

void mLEDL_STATE_Handler(uint8* data, uint8 dlc);
void Diag_mLEDL_STATE(uint8* data, uint8 dlc);
void SetDefault_mLEDL_STATE();

void mLEDR_STATE_Handler(uint8* data, uint8 dlc);
void Diag_mLEDR_STATE(uint8* data, uint8 dlc);
void SetDefault_mLEDR_STATE();

void RSA_Status_Handler(uint8* data, uint8 dlc);
void Diag_RSA_Status(uint8* data, uint8 dlc);
void SetDefault_RSA_Status();

void TM_Stat_Handler(uint8* data, uint8 dlc);
void Diag_TM_Stat(uint8* data, uint8 dlc);
void SetDefault_TM_Stat();

void VCU_DriverDmd_Handler(uint8* data, uint8 dlc);
void Diag_VCU_DriverDmd(uint8* data, uint8 dlc);
void SetDefault_VCU_DriverDmd();

void Emu_Spd_Handler(uint8* data, uint8 dlc);

void NeuralNetwork_Switch_Handler(uint8* data, uint8 dlc);

void DiagGpuReq_Handler(uint8* data, uint8 dlc);

void DiagMrrDidReq_Handler(uint8* data, uint8 dlc);

void DiagPanelConn_Handler(uint8* data, uint8 dlc);

void DiagMrrCalibrationReq_Handler(uint8* data, uint8 dlc);

void MainStart_Handler(uint8* data, uint8 dlc);
void SetDefault_MainStart();

void DiagToolFake_Handler(uint8* data, uint8 dlc);

void Emu_EMS_Handler(uint8* data, uint8 dlc);

void Emu_MLIA_Xcp_Handler(uint8* data, uint8 dlc);
void SetDefault_Emu_MLIA_Xcp();

void Emu_Blink_Xcp_Handler(uint8* data, uint8 dlc);
void SetDefault_Emu_Blink_Xcp();

void TestData_SOS_Button_Handler(uint8* data, uint8 dlc);

void Emu_AfsExecuteReq_Handler(uint8* data, uint8 dlc);

void PrepareToFirmware_Handler(uint8* data, uint8 dlc);

void EmergOrinResetRequest_Handler(uint8* data, uint8 dlc);

void TestJerkBrake_Handler(uint8* data, uint8 dlc);

void AA_SwitchTest_Handler(uint8* data, uint8 dlc);

void Radar_Rear_ADAS_Handler(uint8* data, uint8 dlc);
void SetDefault_Radar_Rear_ADAS();

void LeftRadarSynMessage_Handler(uint8* data, uint8 dlc);

void Monitor_Time_L_1_Handler(uint8* data, uint8 dlc);

void Monitor_Time_L_2_Handler(uint8* data, uint8 dlc);

void Monitor_Time_R_1_Handler(uint8* data, uint8 dlc);

void Monitor_Time_R_2_Handler(uint8* data, uint8 dlc);

void Obj_0_Status_RL_Handler(uint8* data, uint8 dlc);

void Obj_0_Status_RR_Handler(uint8* data, uint8 dlc);

void Obj_Collision_Info_RL_Handler(uint8* data, uint8 dlc);

void Obj_Collision_Info_RR_Handler(uint8* data, uint8 dlc);

void Obj_End_Msg_RL_Handler(uint8* data, uint8 dlc);

void Obj_End_Msg_RR_Handler(uint8* data, uint8 dlc);

void Obj_Extended_Info_RL_Handler(uint8* data, uint8 dlc);

void Obj_Extended_Info_RR_Handler(uint8* data, uint8 dlc);

void Obj_General_Info_RL_Handler(uint8* data, uint8 dlc);

void Obj_General_Info_RR_Handler(uint8* data, uint8 dlc);

void Obj_Quality_Info_RL_Handler(uint8* data, uint8 dlc);

void Obj_Quality_Info_RR_Handler(uint8* data, uint8 dlc);

void RightRadarSynMessage_Handler(uint8* data, uint8 dlc);

void VehInfo_Left_Radar_Handler(uint8* data, uint8 dlc);

void VehInfo_Right_Radar_Handler(uint8* data, uint8 dlc);

void China_UDS_RL_Phy_Resp_Handler(uint8* data, uint8 dlc);

void China_UDS_RR_Phy_Resp_Handler(uint8* data, uint8 dlc);

void CSA1_Handler(uint8* data, uint8 dlc);

void CSA2_Handler(uint8* data, uint8 dlc);

void ABS1_Handler(uint8* data, uint8 dlc);

void ABS2_Handler(uint8* data, uint8 dlc);

void ABS3_Handler(uint8* data, uint8 dlc);

void ESP1_Handler(uint8* data, uint8 dlc);

void ABM1_Handler(uint8* data, uint8 dlc);

void ABM2_Handler(uint8* data, uint8 dlc);

void ACC_FD2_Handler(uint8* data, uint8 dlc);

void AEB_FD1_Handler(uint8* data, uint8 dlc);

void IFC_FD2_Handler(uint8* data, uint8 dlc);

void XCP_CAN_RX_Handler(uint8* data, uint8 dlc);

void DAS_01_Handler(uint8* data, uint8 dlc);
void Prepare_DAS_01();
void FillCS_DAS_01(uint8* data, uint8 dlc);

void DAS_02_Handler(uint8* data, uint8 dlc);
void Prepare_DAS_02();
void FillCS_DAS_02(uint8* data, uint8 dlc);

void DAS_03_Handler(uint8* data, uint8 dlc);
void Prepare_DAS_03();
void FillCS_DAS_03(uint8* data, uint8 dlc);

void DAS_04_Handler(uint8* data, uint8 dlc);
void Prepare_DAS_04();
void FillCS_DAS_04(uint8* data, uint8 dlc);

void DAS_07_Handler(uint8* data, uint8 dlc);
void Prepare_DAS_07();
void FillCS_DAS_07(uint8* data, uint8 dlc);

void DAS_08_Handler(uint8* data, uint8 dlc);

void DAS_Configure_Handler(uint8* data, uint8 dlc);
void Prepare_DAS_Configure();
void FillCS_DAS_Configure(uint8* data, uint8 dlc);

void DAS_EMS_Handler(uint8* data, uint8 dlc);
void Prepare_DAS_EMS();
void FillCS_DAS_EMS(uint8* data, uint8 dlc);

void DAS_FIU_Settings_Handler(uint8* data, uint8 dlc);
void Prepare_DAS_FIU_Settings();
void FillCS_DAS_FIU_Settings(uint8* data, uint8 dlc);

void DAS_HUD_01_Handler(uint8* data, uint8 dlc);

void DAS_HUD_02_Handler(uint8* data, uint8 dlc);

void DAS_Main_Handler(uint8* data, uint8 dlc);
void Prepare_DAS_Main();
void FillCS_DAS_Main(uint8* data, uint8 dlc);

void DAS_VCU_Handler(uint8* data, uint8 dlc);
void Prepare_DAS_VCU();
void FillCS_DAS_VCU(uint8* data, uint8 dlc);

void DASCU_HLL_Object_Handler(uint8* data, uint8 dlc);
void Prepare_DASCU_HLL_Object();
void FillCS_DASCU_HLL_Object(uint8* data, uint8 dlc);

void DASCU_HLR_Object_Handler(uint8* data, uint8 dlc);
void Prepare_DASCU_HLR_Object();
void FillCS_DASCU_HLR_Object(uint8* data, uint8 dlc);

void DASCU_Proj_Handler(uint8* data, uint8 dlc);

void Diag_From_DASCU_Handler(uint8* data, uint8 dlc);

void Diag_To_ERAG_Handler(uint8* data, uint8 dlc);

void TestData_ACC_Handler(uint8* data, uint8 dlc);

void TestData_AEB_Handler(uint8* data, uint8 dlc);

void TestData_FIU_Handler(uint8* data, uint8 dlc);

void TestData_LKA_Handler(uint8* data, uint8 dlc);

void TestData_LDW_Handler(uint8* data, uint8 dlc);

void TestData_LCC_Handler(uint8* data, uint8 dlc);

void TestData_ALCC_Handler(uint8* data, uint8 dlc);

void TestData_DOW_Handler(uint8* data, uint8 dlc);

void TestData_RCW_Handler(uint8* data, uint8 dlc);

void TestData_RDA_Handler(uint8* data, uint8 dlc);

void TestData_MLIA_Handler(uint8* data, uint8 dlc);

void TestData_VISUAL_Handler(uint8* data, uint8 dlc);

void MainDataFromPerc_Handler(uint8* data, uint8 dlc);

void FrontPercData1_3_Handler(uint8* data, uint8 dlc);

void FrontPercData4_6_Handler(uint8* data, uint8 dlc);

void OncomeCrossPercData_Handler(uint8* data, uint8 dlc);

void RearPercData12_14_Handler(uint8* data, uint8 dlc);

void RearPercData15_16_Handler(uint8* data, uint8 dlc);

void RearPercData17_18_Handler(uint8* data, uint8 dlc);

void LaneFrontPercData_Handler(uint8* data, uint8 dlc);

void LaneRearPercData_Handler(uint8* data, uint8 dlc);

void SignPercData_Handler(uint8* data, uint8 dlc);

void MliaPercData01_05_Handler(uint8* data, uint8 dlc);

void MliaPercData06_11_Handler(uint8* data, uint8 dlc);

void MliaPercData12_19_Handler(uint8* data, uint8 dlc);

void MliaPercData20_21_Handler(uint8* data, uint8 dlc);

void DiagGpuResp_Handler(uint8* data, uint8 dlc);

void TestData_GPU_States_Handler(uint8* data, uint8 dlc);

void DiagMrrLResp_Handler(uint8* data, uint8 dlc);

void DiagMrrRResp_Handler(uint8* data, uint8 dlc);

void TestData_FromMRRs_Handler(uint8* data, uint8 dlc);

void TestData_ToMRRs_Handler(uint8* data, uint8 dlc);

void VersionInfo_Handler(uint8* data, uint8 dlc);

void TestData_SOS_Status_Handler(uint8* data, uint8 dlc);

void UdpPacketsStat_Handler(uint8* data, uint8 dlc);

void ADASCANFD_Timeouts_Handler(uint8* data, uint8 dlc);

void ERAG_Data_Handler(uint8* data, uint8 dlc);

void TestData_AA_Handler(uint8* data, uint8 dlc);

void DAS_VehInfo1_Handler(uint8* data, uint8 dlc);

void DAS_VehInfo2_Handler(uint8* data, uint8 dlc);

void DAS_VehInfo3_Handler(uint8* data, uint8 dlc);

void DAS_SwitchCalibWave_Handler(uint8* data, uint8 dlc);

void China_UDS_RL_Phy_Req_Handler(uint8* data, uint8 dlc);

void China_UDS_RR_Phy_Req_Handler(uint8* data, uint8 dlc);

void XCP_CAN_TX_Handler(uint8* data, uint8 dlc);


#endif
