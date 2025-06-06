/* THIS FILE WAS GENERATED AUTOMATICALLY 
 * 
 * Source: CodeGenerationSignals.xlsm
 * 
 * CAN_InitMessageObjects.c
 * 
 * Generated on: 06.06.2025
 * Author: igor.loginov
*/

#include <CAN_Private.h>


void CAN_InitMessageObjects()
{
#ifdef SW_AURUS
   ACU_01_MO.failHandler = SetDefault_ACU_01;
   ACU_01_MO.diagHandler = Diag_ACU_01;
   ACU_01_MO.pTimeout = &ComScl_ACU_01_Timeout;
   CAN_InitMessageObject(&ACU_01_MO);

#endif
#ifdef SW_AURUS
   BCM_CLIMATIC_DATA_MO.failHandler = SetDefault_BCM_CLIMATIC_DATA;
   BCM_CLIMATIC_DATA_MO.diagHandler = Diag_BCM_CLIMATIC_DATA;
   BCM_CLIMATIC_DATA_MO.pTimeout = &ComScl_BCM_CLIMATIC_DATA_Timeout;
   CAN_InitMessageObject(&BCM_CLIMATIC_DATA_MO);

#endif
#ifdef SW_AURUS
   BCM_EXT_LGT_MO.failHandler = SetDefault_BCM_EXT_LGT;
   BCM_EXT_LGT_MO.diagHandler = Diag_BCM_EXT_LGT;
   BCM_EXT_LGT_MO.pTimeout = &ComScl_BCM_EXT_LGT_Timeout;
   CAN_InitMessageObject(&BCM_EXT_LGT_MO);

#endif
#ifdef SW_AURUS
   BCM_IC_Info_Msg_MO.failHandler = SetDefault_BCM_IC_Info_Msg;
   BCM_IC_Info_Msg_MO.diagHandler = Diag_BCM_IC_Info_Msg;
   BCM_IC_Info_Msg_MO.pTimeout = &ComScl_BCM_IC_Info_Msg_Timeout;
   CAN_InitMessageObject(&BCM_IC_Info_Msg_MO);

#endif
#ifdef SW_AURUS
   BCM_Lock_CTR_MO.failHandler = SetDefault_BCM_Lock_CTR;
   BCM_Lock_CTR_MO.diagHandler = Diag_BCM_Lock_CTR;
   BCM_Lock_CTR_MO.pTimeout = &ComScl_BCM_Lock_CTR_Timeout;
   CAN_InitMessageObject(&BCM_Lock_CTR_MO);

#endif
#ifdef SW_AURUS
   BCM_RLS_Stat_MO.failHandler = SetDefault_BCM_RLS_Stat;
   BCM_RLS_Stat_MO.diagHandler = Diag_BCM_RLS_Stat;
   BCM_RLS_Stat_MO.pTimeout = &ComScl_BCM_RLS_Stat_Timeout;
   CAN_InitMessageObject(&BCM_RLS_Stat_MO);

#endif
#ifdef SW_AURUS
   BCM_VEH_STATE_MO.failHandler = SetDefault_BCM_VEH_STATE;
   BCM_VEH_STATE_MO.diagHandler = Diag_BCM_VEH_STATE;
   BCM_VEH_STATE_MO.pTimeout = &ComScl_BCM_VEH_STATE_Timeout;
   CAN_InitMessageObject(&BCM_VEH_STATE_MO);

#endif
#ifdef SW_AURUS
   BCM_Veh_State2_MO.failHandler = SetDefault_BCM_Veh_State2;
   BCM_Veh_State2_MO.diagHandler = Diag_BCM_Veh_State2;
   BCM_Veh_State2_MO.pTimeout = &ComScl_BCM_Veh_State2_Timeout;
   CAN_InitMessageObject(&BCM_Veh_State2_MO);

#endif
#ifdef SW_AURUS
   CCU_Stat1_MO.failHandler = SetDefault_CCU_Stat1;
   CCU_Stat1_MO.diagHandler = Diag_CCU_Stat1;
   CCU_Stat1_MO.pTimeout = &ComScl_CCU_Stat1_Timeout;
   CAN_InitMessageObject(&CCU_Stat1_MO);

#endif
#ifdef SW_AURUS
   DMFL_Msg1_MO.failHandler = SetDefault_DMFL_Msg1;
   DMFL_Msg1_MO.diagHandler = Diag_DMFL_Msg1;
   DMFL_Msg1_MO.pTimeout = &ComScl_DMFL_Msg1_Timeout;
   CAN_InitMessageObject(&DMFL_Msg1_MO);

#endif
#ifdef SW_AURUS
   DMFR_Msg1_MO.failHandler = SetDefault_DMFR_Msg1;
   DMFR_Msg1_MO.diagHandler = Diag_DMFR_Msg1;
   DMFR_Msg1_MO.pTimeout = &ComScl_DMFR_Msg1_Timeout;
   CAN_InitMessageObject(&DMFR_Msg1_MO);

#endif
#ifdef SW_AURUS
   DMRL_Msg1_MO.failHandler = SetDefault_DMRL_Msg1;
   DMRL_Msg1_MO.diagHandler = Diag_DMRL_Msg1;
   DMRL_Msg1_MO.pTimeout = &ComScl_DMRL_Msg1_Timeout;
   CAN_InitMessageObject(&DMRL_Msg1_MO);

#endif
#ifdef SW_AURUS
   DMRR_Msg1_MO.failHandler = SetDefault_DMRR_Msg1;
   DMRR_Msg1_MO.diagHandler = Diag_DMRR_Msg1;
   DMRR_Msg1_MO.pTimeout = &ComScl_DMRR_Msg1_Timeout;
   CAN_InitMessageObject(&DMRR_Msg1_MO);

#endif
#ifdef SW_AURUS
   BCM_DMS_01_MO.failHandler = SetDefault_BCM_DMS_01;
   BCM_DMS_01_MO.diagHandler = Diag_BCM_DMS_01;
   BCM_DMS_01_MO.pTimeout = &ComScl_BCM_DMS_01_Timeout;
   CAN_InitMessageObject(&BCM_DMS_01_MO);

#endif
#ifdef SW_AURUS
   EMS_14_MO.failHandler = SetDefault_EMS_14;
   EMS_14_MO.diagHandler = Diag_EMS_14;
   EMS_14_MO.pTimeout = &ComScl_EMS_14_Timeout;
   CAN_InitMessageObject(&EMS_14_MO);

#endif
#ifdef SW_AURUS
   EMS_3_MO.failHandler = SetDefault_EMS_3;
   EMS_3_MO.diagHandler = Diag_EMS_3;
   EMS_3_MO.pTimeout = &ComScl_EMS_3_Timeout;
   CAN_InitMessageObject(&EMS_3_MO);

#endif
#ifdef SW_AURUS
   EMS_4_MO.failHandler = SetDefault_EMS_4;
   EMS_4_MO.diagHandler = Diag_EMS_4;
   EMS_4_MO.pTimeout = &ComScl_EMS_4_Timeout;
   CAN_InitMessageObject(&EMS_4_MO);

#endif
#ifdef SW_AURUS
   EPB_Status_MO.failHandler = SetDefault_EPB_Status;
   EPB_Status_MO.diagHandler = Diag_EPB_Status;
   EPB_Status_MO.pTimeout = &ComScl_EPB_Status_Timeout;
   CAN_InitMessageObject(&EPB_Status_MO);

#endif
#ifdef SW_AURUS
   ESC_02_MO.failHandler = SetDefault_ESC_02;
   ESC_02_MO.diagHandler = Diag_ESC_02;
   ESC_02_MO.pTimeout = &ComScl_ESC_02_Timeout;
   CAN_InitMessageObject(&ESC_02_MO);

#endif
#ifdef SW_AURUS
   ESC_03_MO.failHandler = SetDefault_ESC_03;
   ESC_03_MO.diagHandler = Diag_ESC_03;
   ESC_03_MO.pTimeout = &ComScl_ESC_03_Timeout;
   CAN_InitMessageObject(&ESC_03_MO);

#endif
#ifdef SW_AURUS
   ESC_04_MO.failHandler = SetDefault_ESC_04;
   ESC_04_MO.diagHandler = Diag_ESC_04;
   ESC_04_MO.pTimeout = &ComScl_ESC_04_Timeout;
   CAN_InitMessageObject(&ESC_04_MO);

#endif
#ifdef SW_AURUS
   ESC_06_MO.failHandler = SetDefault_ESC_06;
   ESC_06_MO.diagHandler = Diag_ESC_06;
   ESC_06_MO.pTimeout = &ComScl_ESC_06_Timeout;
   CAN_InitMessageObject(&ESC_06_MO);

#endif
#ifdef SW_AURUS
   ESC_07_MO.failHandler = SetDefault_ESC_07;
   ESC_07_MO.diagHandler = Diag_ESC_07;
   ESC_07_MO.pTimeout = &ComScl_ESC_07_Timeout;
   CAN_InitMessageObject(&ESC_07_MO);

#endif
#ifdef SW_AURUS
   ESC_09_MO.failHandler = SetDefault_ESC_09;
   ESC_09_MO.diagHandler = Diag_ESC_09;
   ESC_09_MO.pTimeout = &ComScl_ESC_09_Timeout;
   CAN_InitMessageObject(&ESC_09_MO);

#endif
#ifdef SW_AURUS
   ESC_10_MO.failHandler = SetDefault_ESC_10;
   ESC_10_MO.diagHandler = Diag_ESC_10;
   ESC_10_MO.pTimeout = &ComScl_ESC_10_Timeout;
   CAN_InitMessageObject(&ESC_10_MO);

#endif
#ifdef SW_AURUS
   ESC_YRS_01_MO.failHandler = SetDefault_ESC_YRS_01;
   ESC_YRS_01_MO.diagHandler = Diag_ESC_YRS_01;
   ESC_YRS_01_MO.pTimeout = &ComScl_ESC_YRS_01_Timeout;
   CAN_InitMessageObject(&ESC_YRS_01_MO);

#endif
#ifdef SW_AURUS
   ESC_YRS_02_MO.failHandler = SetDefault_ESC_YRS_02;
   ESC_YRS_02_MO.diagHandler = Diag_ESC_YRS_02;
   ESC_YRS_02_MO.pTimeout = &ComScl_ESC_YRS_02_Timeout;
   CAN_InitMessageObject(&ESC_YRS_02_MO);

#endif
#ifdef SW_AURUS
   IC_DMS_MO.failHandler = SetDefault_IC_DMS;
   IC_DMS_MO.diagHandler = Diag_IC_DMS;
   IC_DMS_MO.pTimeout = &ComScl_IC_DMS_Timeout;
   CAN_InitMessageObject(&IC_DMS_MO);

#endif
#ifdef SW_AURUS
   IC_ADAS_REST_MO.failHandler = SetDefault_IC_ADAS_REST;
   IC_ADAS_REST_MO.diagHandler = Diag_IC_ADAS_REST;
   IC_ADAS_REST_MO.pTimeout = &ComScl_IC_ADAS_REST_Timeout;
   CAN_InitMessageObject(&IC_ADAS_REST_MO);

#endif
#ifdef SW_AURUS
   IC_HUD_01_MO.failHandler = SetDefault_IC_HUD_01;
   IC_HUD_01_MO.diagHandler = Diag_IC_HUD_01;
   IC_HUD_01_MO.pTimeout = &ComScl_IC_HUD_01_Timeout;
   CAN_InitMessageObject(&IC_HUD_01_MO);

#endif
#ifdef SW_AURUS
   IC_ABSOLUTE_CLOCK_MO.failHandler = SetDefault_IC_ABSOLUTE_CLOCK;
   IC_ABSOLUTE_CLOCK_MO.diagHandler = Diag_IC_ABSOLUTE_CLOCK;
   IC_ABSOLUTE_CLOCK_MO.pTimeout = &ComScl_IC_ABSOLUTE_CLOCK_Timeout;
   CAN_InitMessageObject(&IC_ABSOLUTE_CLOCK_MO);

#endif
#ifdef SW_AURUS
   MAS_Status_MO.failHandler = SetDefault_MAS_Status;
   MAS_Status_MO.diagHandler = Diag_MAS_Status;
   MAS_Status_MO.pTimeout = &ComScl_MAS_Status_Timeout;
   CAN_InitMessageObject(&MAS_Status_MO);

#endif
#ifdef SW_AURUS
   MAS_FrontUSS_MO.failHandler = SetDefault_MAS_FrontUSS;
   MAS_FrontUSS_MO.diagHandler = Diag_MAS_FrontUSS;
   MAS_FrontUSS_MO.pTimeout = &ComScl_MAS_FrontUSS_Timeout;
   CAN_InitMessageObject(&MAS_FrontUSS_MO);

#endif
#ifdef SW_AURUS
   MAS_RearUSS_MO.failHandler = SetDefault_MAS_RearUSS;
   MAS_RearUSS_MO.diagHandler = Diag_MAS_RearUSS;
   MAS_RearUSS_MO.pTimeout = &ComScl_MAS_RearUSS_Timeout;
   CAN_InitMessageObject(&MAS_RearUSS_MO);

#endif
#ifdef SW_AURUS
   MAS_SideUSS_MO.failHandler = SetDefault_MAS_SideUSS;
   MAS_SideUSS_MO.diagHandler = Diag_MAS_SideUSS;
   MAS_SideUSS_MO.pTimeout = &ComScl_MAS_SideUSS_Timeout;
   CAN_InitMessageObject(&MAS_SideUSS_MO);

#endif
#ifdef SW_AURUS
   HLL_STATE_MO.failHandler = SetDefault_HLL_STATE;
   HLL_STATE_MO.diagHandler = Diag_HLL_STATE;
   HLL_STATE_MO.pTimeout = &ComScl_HLL_STATE_Timeout;
   CAN_InitMessageObject(&HLL_STATE_MO);

#endif
#ifdef SW_AURUS
   HLR_STATE_MO.failHandler = SetDefault_HLR_STATE;
   HLR_STATE_MO.diagHandler = Diag_HLR_STATE;
   HLR_STATE_MO.pTimeout = &ComScl_HLR_STATE_Timeout;
   CAN_InitMessageObject(&HLR_STATE_MO);

#endif
#ifdef SW_AURUS
   SAS_Standard_MO.failHandler = SetDefault_SAS_Standard;
   SAS_Standard_MO.diagHandler = Diag_SAS_Standard;
   SAS_Standard_MO.pTimeout = &ComScl_SAS_Standard_Timeout;
   CAN_InitMessageObject(&SAS_Standard_MO);

#endif
#ifdef SW_AURUS
   SWM_ContrlsState_Old_MO.failHandler = SetDefault_SWM_ContrlsState_Old;
   SWM_ContrlsState_Old_MO.diagHandler = Diag_SWM_ContrlsState_Old;
   SWM_ContrlsState_Old_MO.pTimeout = &ComScl_SWM_ContrlsState_Old_Timeout;
   CAN_InitMessageObject(&SWM_ContrlsState_Old_MO);

#endif
#ifdef SW_AURUS
   SWM_ContrlsState_MO.failHandler = SetDefault_SWM_ContrlsState;
   SWM_ContrlsState_MO.diagHandler = Diag_SWM_ContrlsState;
   SWM_ContrlsState_MO.pTimeout = &ComScl_SWM_ContrlsState_Timeout;
   CAN_InitMessageObject(&SWM_ContrlsState_MO);

#endif
#ifdef SW_AURUS
   SCU_02_MO.failHandler = SetDefault_SCU_02;
   SCU_02_MO.diagHandler = Diag_SCU_02;
   SCU_02_MO.pTimeout = &ComScl_SCU_02_Timeout;
   CAN_InitMessageObject(&SCU_02_MO);

#endif
#ifdef SW_AURUS
   TCU_R932_1_MO.failHandler = SetDefault_TCU_R932_1;
   TCU_R932_1_MO.diagHandler = Diag_TCU_R932_1;
   TCU_R932_1_MO.pTimeout = &ComScl_TCU_R932_1_Timeout;
   CAN_InitMessageObject(&TCU_R932_1_MO);

#endif
#ifdef SW_AURUS
   FIU_ADAS_Config_MO.pTimeout = &ComScl_FIU_ADAS_Config_Timeout;
   CAN_InitMessageObject(&FIU_ADAS_Config_MO);

#endif
#ifdef SW_AURUS
   FIU_Msg3_MO.failHandler = SetDefault_FIU_Msg3;
   FIU_Msg3_MO.diagHandler = Diag_FIU_Msg3;
   FIU_Msg3_MO.pTimeout = &ComScl_FIU_Msg3_Timeout;
   CAN_InitMessageObject(&FIU_Msg3_MO);

#endif
#ifdef SW_AURUS
   VCU_ADAS_01_MO.failHandler = SetDefault_VCU_ADAS_01;
   VCU_ADAS_01_MO.diagHandler = Diag_VCU_ADAS_01;
   VCU_ADAS_01_MO.pTimeout = &ComScl_VCU_ADAS_01_Timeout;
   CAN_InitMessageObject(&VCU_ADAS_01_MO);

#endif
#ifdef SW_AURUS
   Diag_From_ERAG_MO.pTimeout = &ComScl_Diag_From_ERAG_Timeout;
   CAN_InitMessageObject(&Diag_From_ERAG_MO);

#endif
#ifdef SW_AURUS
   ERAG_NMEA1_MO.pTimeout = &ComScl_ERAG_NMEA1_Timeout;
   CAN_InitMessageObject(&ERAG_NMEA1_MO);

#endif
#ifdef SW_AURUS
   ERAG_NMEA2_MO.pTimeout = &ComScl_ERAG_NMEA2_Timeout;
   CAN_InitMessageObject(&ERAG_NMEA2_MO);

#endif
#ifdef SW_AURUS
   ERAG_NMEA3_MO.pTimeout = &ComScl_ERAG_NMEA3_Timeout;
   CAN_InitMessageObject(&ERAG_NMEA3_MO);

#endif
#ifdef SW_AURUS
   ERAG_NMEA4_MO.pTimeout = &ComScl_ERAG_NMEA4_Timeout;
   CAN_InitMessageObject(&ERAG_NMEA4_MO);

#endif
#ifdef SW_AURUS
   ERAG_NMEA5_MO.pTimeout = &ComScl_ERAG_NMEA5_Timeout;
   CAN_InitMessageObject(&ERAG_NMEA5_MO);

#endif
#ifdef SW_AURUS
   ERAG_NMEA6_MO.pTimeout = &ComScl_ERAG_NMEA6_Timeout;
   CAN_InitMessageObject(&ERAG_NMEA6_MO);

#endif
#ifdef SW_AURUS
   ERAG_DATA_MSG_MO.pTimeout = &ComScl_ERAG_DATA_MSG_Timeout;
   CAN_InitMessageObject(&ERAG_DATA_MSG_MO);

#endif
#ifdef SW_AURUS
   ATC_TX_MO.failHandler = SetDefault_ATC_TX;
   ATC_TX_MO.diagHandler = Diag_ATC_TX;
   ATC_TX_MO.pTimeout = &ComScl_ATC_TX_Timeout;
   CAN_InitMessageObject(&ATC_TX_MO);

#endif
#ifdef SW_AURUS
   Diag_Functional_MO.failHandler = SetDefault_Diag_Functional;
   Diag_Functional_MO.diagHandler = Diag_Diag_Functional;
   Diag_Functional_MO.pTimeout = &ComScl_Diag_Functional_Timeout;
   CAN_InitMessageObject(&Diag_Functional_MO);

#endif
#ifdef SW_AURUS
   Diag_To_DASCU_MO.pTimeout = &ComScl_Diag_To_DASCU_Timeout;
   CAN_InitMessageObject(&Diag_To_DASCU_MO);

#endif
#ifdef SW_AURUS
   EMS_03_MO.failHandler = SetDefault_EMS_03;
   EMS_03_MO.diagHandler = Diag_EMS_03;
   EMS_03_MO.pTimeout = &ComScl_EMS_03_Timeout;
   CAN_InitMessageObject(&EMS_03_MO);

#endif
#ifdef SW_AURUS
   EMS_04_MO.failHandler = SetDefault_EMS_04;
   EMS_04_MO.diagHandler = Diag_EMS_04;
   EMS_04_MO.pTimeout = &ComScl_EMS_04_Timeout;
   CAN_InitMessageObject(&EMS_04_MO);

#endif
#ifdef SW_AURUS
   EMS_16_MO.failHandler = SetDefault_EMS_16;
   EMS_16_MO.diagHandler = Diag_EMS_16;
   EMS_16_MO.pTimeout = &ComScl_EMS_16_Timeout;
   CAN_InitMessageObject(&EMS_16_MO);

#endif
#ifdef SW_AURUS
   mLEDL_STATE_MO.failHandler = SetDefault_mLEDL_STATE;
   mLEDL_STATE_MO.diagHandler = Diag_mLEDL_STATE;
   mLEDL_STATE_MO.pTimeout = &ComScl_mLEDL_STATE_Timeout;
   CAN_InitMessageObject(&mLEDL_STATE_MO);

#endif
#ifdef SW_AURUS
   mLEDR_STATE_MO.failHandler = SetDefault_mLEDR_STATE;
   mLEDR_STATE_MO.diagHandler = Diag_mLEDR_STATE;
   mLEDR_STATE_MO.pTimeout = &ComScl_mLEDR_STATE_Timeout;
   CAN_InitMessageObject(&mLEDR_STATE_MO);

#endif
#ifdef SW_AURUS
   RSA_Status_MO.failHandler = SetDefault_RSA_Status;
   RSA_Status_MO.diagHandler = Diag_RSA_Status;
   RSA_Status_MO.pTimeout = &ComScl_RSA_Status_Timeout;
   CAN_InitMessageObject(&RSA_Status_MO);

#endif
#ifdef SW_AURUS
   TM_Stat_MO.failHandler = SetDefault_TM_Stat;
   TM_Stat_MO.diagHandler = Diag_TM_Stat;
   TM_Stat_MO.pTimeout = &ComScl_TM_Stat_Timeout;
   CAN_InitMessageObject(&TM_Stat_MO);

#endif
#ifdef SW_AURUS
   VCU_DriverDmd_MO.failHandler = SetDefault_VCU_DriverDmd;
   VCU_DriverDmd_MO.diagHandler = Diag_VCU_DriverDmd;
   VCU_DriverDmd_MO.pTimeout = &ComScl_VCU_DriverDmd_Timeout;
   CAN_InitMessageObject(&VCU_DriverDmd_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&Emu_Spd_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&NeuralNetwork_Switch_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&DiagGpuReq_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&DiagMrrDidReq_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&DiagPanelConn_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&DiagMrrCalibrationReq_MO);

#endif
#ifdef HW_DEBUG
   MainStart_MO.failHandler = SetDefault_MainStart;
   MainStart_MO.pTimeout = &ComScl_MainStart_Timeout;
   CAN_InitMessageObject(&MainStart_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&DiagToolFake_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&Emu_EMS_MO);

#endif
#ifdef HW_DEBUG
   Emu_MLIA_Xcp_MO.failHandler = SetDefault_Emu_MLIA_Xcp;
   Emu_MLIA_Xcp_MO.pTimeout = &ComScl_Emu_MLIA_Xcp_Timeout;
   CAN_InitMessageObject(&Emu_MLIA_Xcp_MO);

#endif
#ifdef HW_DEBUG
   Emu_Blink_Xcp_MO.failHandler = SetDefault_Emu_Blink_Xcp;
   Emu_Blink_Xcp_MO.pTimeout = &ComScl_Emu_Blink_Xcp_Timeout;
   CAN_InitMessageObject(&Emu_Blink_Xcp_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_SOS_Button_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&Emu_AfsExecuteReq_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&PrepareToFirmware_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&EmergOrinResetRequest_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestJerkBrake_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&AA_SwitchTest_MO);

#endif
   Radar_Rear_ADAS_MO.failHandler = SetDefault_Radar_Rear_ADAS;
   CAN_InitMessageObject(&Radar_Rear_ADAS_MO);

   CAN_InitMessageObject(&LeftRadarSynMessage_MO);

   CAN_InitMessageObject(&Monitor_Time_L_1_MO);

   CAN_InitMessageObject(&Monitor_Time_L_2_MO);

   CAN_InitMessageObject(&Monitor_Time_R_1_MO);

   CAN_InitMessageObject(&Monitor_Time_R_2_MO);

   CAN_InitMessageObject(&Obj_0_Status_RL_MO);

   CAN_InitMessageObject(&Obj_0_Status_RR_MO);

   CAN_InitMessageObject(&Obj_Collision_Info_RL_MO);

   CAN_InitMessageObject(&Obj_Collision_Info_RR_MO);

   CAN_InitMessageObject(&Obj_End_Msg_RL_MO);

   CAN_InitMessageObject(&Obj_End_Msg_RR_MO);

   CAN_InitMessageObject(&Obj_Extended_Info_RL_MO);

   CAN_InitMessageObject(&Obj_Extended_Info_RR_MO);

   CAN_InitMessageObject(&Obj_General_Info_RL_MO);

   CAN_InitMessageObject(&Obj_General_Info_RR_MO);

   CAN_InitMessageObject(&Obj_Quality_Info_RL_MO);

   CAN_InitMessageObject(&Obj_Quality_Info_RR_MO);

   CAN_InitMessageObject(&RightRadarSynMessage_MO);

   CAN_InitMessageObject(&VehInfo_Left_Radar_MO);

   CAN_InitMessageObject(&VehInfo_Right_Radar_MO);

   CAN_InitMessageObject(&China_UDS_RL_Phy_Resp_MO);

   CAN_InitMessageObject(&China_UDS_RR_Phy_Resp_MO);

#ifdef SW_HAVAL
   CAN_InitMessageObject(&CSA1_MO);

#endif
#ifdef SW_HAVAL
   CAN_InitMessageObject(&CSA2_MO);

#endif
#ifdef SW_HAVAL
   CAN_InitMessageObject(&ABS1_MO);

#endif
#ifdef SW_HAVAL
   CAN_InitMessageObject(&ABS2_MO);

#endif
#ifdef SW_HAVAL
   CAN_InitMessageObject(&ABS3_MO);

#endif
#ifdef SW_HAVAL
   CAN_InitMessageObject(&ESP1_MO);

#endif
#ifdef SW_HAVAL
   CAN_InitMessageObject(&ABM1_MO);

#endif
#ifdef SW_HAVAL
   CAN_InitMessageObject(&ABM2_MO);

#endif
#ifdef SW_HAVAL
   CAN_InitMessageObject(&ACC_FD2_MO);

#endif
#ifdef SW_HAVAL
   CAN_InitMessageObject(&AEB_FD1_MO);

#endif
#ifdef SW_HAVAL
   CAN_InitMessageObject(&IFC_FD2_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&XCP_CAN_RX_MO);

#endif
#ifdef SW_AURUS
   DAS_01_MO.prepareHandler = Prepare_DAS_01;
   DAS_01_MO.diagHandler = FillCS_DAS_01;
   CAN_InitMessageObject(&DAS_01_MO);

#endif
#ifdef SW_AURUS
   DAS_02_MO.prepareHandler = Prepare_DAS_02;
   DAS_02_MO.diagHandler = FillCS_DAS_02;
   CAN_InitMessageObject(&DAS_02_MO);

#endif
#ifdef SW_AURUS
   DAS_03_MO.prepareHandler = Prepare_DAS_03;
   DAS_03_MO.diagHandler = FillCS_DAS_03;
   CAN_InitMessageObject(&DAS_03_MO);

#endif
#ifdef SW_AURUS
   DAS_04_MO.prepareHandler = Prepare_DAS_04;
   DAS_04_MO.diagHandler = FillCS_DAS_04;
   CAN_InitMessageObject(&DAS_04_MO);

#endif
#ifdef SW_AURUS
   DAS_07_MO.prepareHandler = Prepare_DAS_07;
   DAS_07_MO.diagHandler = FillCS_DAS_07;
   CAN_InitMessageObject(&DAS_07_MO);

#endif
#ifdef SW_AURUS
   CAN_InitMessageObject(&DAS_08_MO);

#endif
#ifdef SW_AURUS
   DAS_Configure_MO.prepareHandler = Prepare_DAS_Configure;
   DAS_Configure_MO.diagHandler = FillCS_DAS_Configure;
   CAN_InitMessageObject(&DAS_Configure_MO);

#endif
#ifdef SW_AURUS
   DAS_EMS_MO.prepareHandler = Prepare_DAS_EMS;
   DAS_EMS_MO.diagHandler = FillCS_DAS_EMS;
   CAN_InitMessageObject(&DAS_EMS_MO);

#endif
#ifdef SW_AURUS
   DAS_FIU_Settings_MO.prepareHandler = Prepare_DAS_FIU_Settings;
   DAS_FIU_Settings_MO.diagHandler = FillCS_DAS_FIU_Settings;
   CAN_InitMessageObject(&DAS_FIU_Settings_MO);

#endif
#ifdef SW_AURUS
   CAN_InitMessageObject(&DAS_HUD_01_MO);

#endif
#ifdef SW_AURUS
   CAN_InitMessageObject(&DAS_HUD_02_MO);

#endif
#ifdef SW_AURUS
   DAS_Main_MO.prepareHandler = Prepare_DAS_Main;
   DAS_Main_MO.diagHandler = FillCS_DAS_Main;
   CAN_InitMessageObject(&DAS_Main_MO);

#endif
#ifdef SW_AURUS
   DAS_VCU_MO.prepareHandler = Prepare_DAS_VCU;
   DAS_VCU_MO.diagHandler = FillCS_DAS_VCU;
   CAN_InitMessageObject(&DAS_VCU_MO);

#endif
#ifdef SW_AURUS
   DASCU_HLL_Object_MO.prepareHandler = Prepare_DASCU_HLL_Object;
   DASCU_HLL_Object_MO.diagHandler = FillCS_DASCU_HLL_Object;
   CAN_InitMessageObject(&DASCU_HLL_Object_MO);

#endif
#ifdef SW_AURUS
   DASCU_HLR_Object_MO.prepareHandler = Prepare_DASCU_HLR_Object;
   DASCU_HLR_Object_MO.diagHandler = FillCS_DASCU_HLR_Object;
   CAN_InitMessageObject(&DASCU_HLR_Object_MO);

#endif
#ifdef SW_AURUS
   CAN_InitMessageObject(&DASCU_Proj_MO);

#endif
#ifdef SW_AURUS
   CAN_InitMessageObject(&Diag_From_DASCU_MO);

#endif
#ifdef SW_AURUS
   CAN_InitMessageObject(&Diag_To_ERAG_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_ACC_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_AEB_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_FIU_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_LKA_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_LDW_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_LCC_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_ALCC_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_DOW_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_RCW_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_RDA_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_MLIA_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_VISUAL_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&MainDataFromPerc_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&FrontPercData1_3_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&FrontPercData4_6_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&OncomeCrossPercData_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&RearPercData12_14_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&RearPercData15_16_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&RearPercData17_18_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&LaneFrontPercData_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&LaneRearPercData_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&SignPercData_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&MliaPercData01_05_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&MliaPercData06_11_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&MliaPercData12_19_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&MliaPercData20_21_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&DiagGpuResp_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_GPU_States_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&DiagMrrLResp_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&DiagMrrRResp_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_FromMRRs_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_ToMRRs_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&VersionInfo_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_SOS_Status_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&UdpPacketsStat_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&ADASCANFD_Timeouts_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&ERAG_Data_MO);

#endif
#ifdef HW_DEBUG
   CAN_InitMessageObject(&TestData_AA_MO);

#endif
   CAN_InitMessageObject(&DAS_VehInfo1_MO);

   CAN_InitMessageObject(&DAS_VehInfo2_MO);

   CAN_InitMessageObject(&DAS_VehInfo3_MO);

   CAN_InitMessageObject(&DAS_SwitchCalibWave_MO);

   CAN_InitMessageObject(&China_UDS_RL_Phy_Req_MO);

   CAN_InitMessageObject(&China_UDS_RR_Phy_Req_MO);

#ifdef HW_DEBUG
   CAN_InitMessageObject(&XCP_CAN_TX_MO);

#endif
}

