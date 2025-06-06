/* THIS FILE WAS GENERATED AUTOMATICALLY 
 * 
 * Source: CodeGenerationSignals.xlsm
 * 
 * CAN_Diag.c
 * 
 * Generated on: 06.06.2025
 * Author: igor.loginov
*/

#include <Platform_Types.h>
#include <CAN_Private.h>

boolean ComScl_ACU_01_Timeout = 1;
boolean ComScl_ACU_01_DataCorrupt = 0;
boolean ComScl_ACU_01_ChksmError = 0;
boolean ComScl_ACU_01_AlvCntError = 0;
boolean ComScl_BCM_CLIMATIC_DATA_Timeout = 1;
boolean ComScl_BCM_CLIMATIC_DATA_DataCorrupt = 0;
boolean ComScl_BCM_EXT_LGT_Timeout = 1;
boolean ComScl_BCM_EXT_LGT_DataCorrupt = 0;
boolean ComScl_BCM_EXT_LGT_ChksmError = 0;
boolean ComScl_BCM_EXT_LGT_AlvCntError = 0;
boolean ComScl_BCM_IC_Info_Msg_Timeout = 1;
boolean ComScl_BCM_IC_Info_Msg_DataCorrupt = 0;
boolean ComScl_BCM_Lock_CTR_Timeout = 1;
boolean ComScl_BCM_Lock_CTR_DataCorrupt = 0;
boolean ComScl_BCM_RLS_Stat_Timeout = 1;
boolean ComScl_BCM_RLS_Stat_DataCorrupt = 0;
boolean ComScl_BCM_VEH_STATE_Timeout = 1;
boolean ComScl_BCM_VEH_STATE_DataCorrupt = 0;
boolean ComScl_BCM_Veh_State2_Timeout = 1;
boolean ComScl_BCM_Veh_State2_DataCorrupt = 0;
boolean ComScl_CCU_Stat1_Timeout = 1;
boolean ComScl_CCU_Stat1_DataCorrupt = 0;
boolean ComScl_DMFL_Msg1_Timeout = 1;
boolean ComScl_DMFL_Msg1_DataCorrupt = 0;
boolean ComScl_DMFR_Msg1_Timeout = 1;
boolean ComScl_DMFR_Msg1_DataCorrupt = 0;
boolean ComScl_DMRL_Msg1_Timeout = 1;
boolean ComScl_DMRL_Msg1_DataCorrupt = 0;
boolean ComScl_DMRR_Msg1_Timeout = 1;
boolean ComScl_DMRR_Msg1_DataCorrupt = 0;
boolean ComScl_BCM_DMS_01_Timeout = 1;
boolean ComScl_BCM_DMS_01_DataCorrupt = 0;
boolean ComScl_BCM_DMS_01_ChksmError = 0;
boolean ComScl_BCM_DMS_01_AlvCntError = 0;
boolean ComScl_EMS_14_Timeout = 1;
boolean ComScl_EMS_14_DataCorrupt = 0;
boolean ComScl_EMS_14_ChksmError = 0;
boolean ComScl_EMS_14_AlvCntError = 0;
boolean ComScl_EMS_3_Timeout = 1;
boolean ComScl_EMS_3_DataCorrupt = 0;
boolean ComScl_EMS_4_Timeout = 1;
boolean ComScl_EMS_4_DataCorrupt = 0;
boolean ComScl_EPB_Status_Timeout = 1;
boolean ComScl_EPB_Status_DataCorrupt = 0;
boolean ComScl_EPB_Status_ChksmError = 0;
boolean ComScl_EPB_Status_AlvCntError = 0;
boolean ComScl_ESC_02_Timeout = 1;
boolean ComScl_ESC_02_DataCorrupt = 0;
boolean ComScl_ESC_02_ChksmError = 0;
boolean ComScl_ESC_02_AlvCntError = 0;
boolean ComScl_ESC_03_Timeout = 1;
boolean ComScl_ESC_03_DataCorrupt = 0;
boolean ComScl_ESC_03_ChksmError = 0;
boolean ComScl_ESC_03_AlvCntError = 0;
boolean ComScl_ESC_04_Timeout = 1;
boolean ComScl_ESC_04_DataCorrupt = 0;
boolean ComScl_ESC_04_ChksmError = 0;
boolean ComScl_ESC_04_AlvCntError = 0;
boolean ComScl_ESC_06_Timeout = 1;
boolean ComScl_ESC_06_DataCorrupt = 0;
boolean ComScl_ESC_06_ChksmError = 0;
boolean ComScl_ESC_06_AlvCntError = 0;
boolean ComScl_ESC_07_Timeout = 1;
boolean ComScl_ESC_07_DataCorrupt = 0;
boolean ComScl_ESC_07_ChksmError = 0;
boolean ComScl_ESC_07_AlvCntError = 0;
boolean ComScl_ESC_09_Timeout = 1;
boolean ComScl_ESC_09_DataCorrupt = 0;
boolean ComScl_ESC_09_ChksmError = 0;
boolean ComScl_ESC_09_AlvCntError = 0;
boolean ComScl_ESC_10_Timeout = 1;
boolean ComScl_ESC_10_DataCorrupt = 0;
boolean ComScl_ESC_10_ChksmError = 0;
boolean ComScl_ESC_10_AlvCntError = 0;
boolean ComScl_ESC_YRS_01_Timeout = 1;
boolean ComScl_ESC_YRS_01_DataCorrupt = 0;
boolean ComScl_ESC_YRS_01_ChksmError = 0;
boolean ComScl_ESC_YRS_01_AlvCntError = 0;
boolean ComScl_ESC_YRS_02_Timeout = 1;
boolean ComScl_ESC_YRS_02_DataCorrupt = 0;
boolean ComScl_ESC_YRS_02_ChksmError = 0;
boolean ComScl_ESC_YRS_02_AlvCntError = 0;
boolean ComScl_IC_DMS_Timeout = 1;
boolean ComScl_IC_DMS_DataCorrupt = 0;
boolean ComScl_IC_ADAS_REST_Timeout = 1;
boolean ComScl_IC_ADAS_REST_DataCorrupt = 0;
boolean ComScl_IC_HUD_01_Timeout = 1;
boolean ComScl_IC_HUD_01_DataCorrupt = 0;
boolean ComScl_IC_ABSOLUTE_CLOCK_Timeout = 1;
boolean ComScl_IC_ABSOLUTE_CLOCK_DataCorrupt = 0;
boolean ComScl_IC_ABSOLUTE_CLOCK_ChksmError = 0;
boolean ComScl_IC_ABSOLUTE_CLOCK_AlvCntError = 0;
boolean ComScl_MAS_Status_Timeout = 1;
boolean ComScl_MAS_Status_DataCorrupt = 0;
boolean ComScl_MAS_Status_ChksmError = 0;
boolean ComScl_MAS_Status_AlvCntError = 0;
boolean ComScl_MAS_FrontUSS_Timeout = 1;
boolean ComScl_MAS_FrontUSS_DataCorrupt = 0;
boolean ComScl_MAS_FrontUSS_ChksmError = 0;
boolean ComScl_MAS_FrontUSS_AlvCntError = 0;
boolean ComScl_MAS_RearUSS_Timeout = 1;
boolean ComScl_MAS_RearUSS_DataCorrupt = 0;
boolean ComScl_MAS_RearUSS_ChksmError = 0;
boolean ComScl_MAS_RearUSS_AlvCntError = 0;
boolean ComScl_MAS_SideUSS_Timeout = 1;
boolean ComScl_MAS_SideUSS_DataCorrupt = 0;
boolean ComScl_MAS_SideUSS_ChksmError = 0;
boolean ComScl_MAS_SideUSS_AlvCntError = 0;
boolean ComScl_HLL_STATE_Timeout = 1;
boolean ComScl_HLL_STATE_DataCorrupt = 0;
boolean ComScl_HLR_STATE_Timeout = 1;
boolean ComScl_HLR_STATE_DataCorrupt = 0;
boolean ComScl_SAS_Standard_Timeout = 1;
boolean ComScl_SAS_Standard_DataCorrupt = 0;
boolean ComScl_SAS_Standard_ChksmError = 0;
boolean ComScl_SAS_Standard_AlvCntError = 0;
boolean ComScl_SWM_ContrlsState_Old_Timeout = 1;
boolean ComScl_SWM_ContrlsState_Old_DataCorrupt = 0;
boolean ComScl_SWM_ContrlsState_Old_ChksmError = 0;
boolean ComScl_SWM_ContrlsState_Old_AlvCntError = 0;
boolean ComScl_SWM_ContrlsState_Timeout = 1;
boolean ComScl_SWM_ContrlsState_DataCorrupt = 0;
boolean ComScl_SWM_ContrlsState_ChksmError = 0;
boolean ComScl_SWM_ContrlsState_AlvCntError = 0;
boolean ComScl_SCU_02_Timeout = 1;
boolean ComScl_SCU_02_DataCorrupt = 0;
boolean ComScl_SCU_02_ChksmError = 0;
boolean ComScl_SCU_02_AlvCntError = 0;
boolean ComScl_TCU_R932_1_Timeout = 1;
boolean ComScl_TCU_R932_1_DataCorrupt = 0;
boolean ComScl_TCU_R932_1_ChksmError = 0;
boolean ComScl_TCU_R932_1_AlvCntError = 0;
boolean ComScl_FIU_ADAS_Config_Timeout = 1;
boolean ComScl_FIU_ADAS_Config_DataCorrupt = 0;
boolean ComScl_FIU_Msg3_Timeout = 1;
boolean ComScl_FIU_Msg3_DataCorrupt = 0;
boolean ComScl_VCU_ADAS_01_Timeout = 1;
boolean ComScl_VCU_ADAS_01_DataCorrupt = 0;
boolean ComScl_VCU_ADAS_01_ChksmError = 0;
boolean ComScl_VCU_ADAS_01_AlvCntError = 0;
boolean ComScl_Diag_From_ERAG_Timeout = 1;
boolean ComScl_Diag_From_ERAG_DataCorrupt = 0;
boolean ComScl_ERAG_NMEA1_Timeout = 1;
boolean ComScl_ERAG_NMEA1_DataCorrupt = 0;
boolean ComScl_ERAG_NMEA2_Timeout = 1;
boolean ComScl_ERAG_NMEA2_DataCorrupt = 0;
boolean ComScl_ERAG_NMEA3_Timeout = 1;
boolean ComScl_ERAG_NMEA3_DataCorrupt = 0;
boolean ComScl_ERAG_NMEA4_Timeout = 1;
boolean ComScl_ERAG_NMEA4_DataCorrupt = 0;
boolean ComScl_ERAG_NMEA5_Timeout = 1;
boolean ComScl_ERAG_NMEA5_DataCorrupt = 0;
boolean ComScl_ERAG_NMEA6_Timeout = 1;
boolean ComScl_ERAG_NMEA6_DataCorrupt = 0;
boolean ComScl_ERAG_DATA_MSG_Timeout = 1;
boolean ComScl_ERAG_DATA_MSG_DataCorrupt = 0;
boolean ComScl_ATC_TX_Timeout = 1;
boolean ComScl_ATC_TX_DataCorrupt = 0;
boolean ComScl_ATC_TX_ChksmError = 0;
boolean ComScl_ATC_TX_AlvCntError = 0;
boolean ComScl_Diag_Functional_Timeout = 1;
boolean ComScl_Diag_Functional_DataCorrupt = 0;
boolean ComScl_Diag_To_DASCU_Timeout = 1;
boolean ComScl_Diag_To_DASCU_DataCorrupt = 0;
boolean ComScl_EMS_03_Timeout = 1;
boolean ComScl_EMS_03_DataCorrupt = 0;
boolean ComScl_EMS_03_ChksmError = 0;
boolean ComScl_EMS_03_AlvCntError = 0;
boolean ComScl_EMS_04_Timeout = 1;
boolean ComScl_EMS_04_DataCorrupt = 0;
boolean ComScl_EMS_04_ChksmError = 0;
boolean ComScl_EMS_04_AlvCntError = 0;
boolean ComScl_EMS_16_Timeout = 1;
boolean ComScl_EMS_16_DataCorrupt = 0;
boolean ComScl_EMS_16_ChksmError = 0;
boolean ComScl_EMS_16_AlvCntError = 0;
boolean ComScl_mLEDL_STATE_Timeout = 1;
boolean ComScl_mLEDL_STATE_DataCorrupt = 0;
boolean ComScl_mLEDR_STATE_Timeout = 1;
boolean ComScl_mLEDR_STATE_DataCorrupt = 0;
boolean ComScl_RSA_Status_Timeout = 1;
boolean ComScl_RSA_Status_DataCorrupt = 0;
boolean ComScl_RSA_Status_ChksmError = 0;
boolean ComScl_RSA_Status_AlvCntError = 0;
boolean ComScl_TM_Stat_Timeout = 1;
boolean ComScl_TM_Stat_DataCorrupt = 0;
boolean ComScl_VCU_DriverDmd_Timeout = 1;
boolean ComScl_VCU_DriverDmd_DataCorrupt = 0;
boolean ComScl_VCU_DriverDmd_ChksmError = 0;
boolean ComScl_VCU_DriverDmd_AlvCntError = 0;
boolean ComScl_MainStart_Timeout = 1;
boolean ComScl_MainStart_DataCorrupt = 0;
boolean ComScl_Emu_MLIA_Xcp_Timeout = 1;
boolean ComScl_Emu_MLIA_Xcp_DataCorrupt = 0;
boolean ComScl_Emu_Blink_Xcp_Timeout = 1;
boolean ComScl_Emu_Blink_Xcp_DataCorrupt = 0;


Framemonitor_t ACU_01_FM = FRAMEMONITOR_WITH_RC_CS(ACU_01);
Framemonitor_t BCM_CLIMATIC_DATA_FM = FRAMEMONITOR_NO_RC_CS(BCM_CLIMATIC_DATA);
Framemonitor_t BCM_EXT_LGT_FM = FRAMEMONITOR_WITH_RC_CS(BCM_EXT_LGT);
Framemonitor_t BCM_IC_Info_Msg_FM = FRAMEMONITOR_NO_RC_CS(BCM_IC_Info_Msg);
Framemonitor_t BCM_Lock_CTR_FM = FRAMEMONITOR_NO_RC_CS(BCM_Lock_CTR);
Framemonitor_t BCM_RLS_Stat_FM = FRAMEMONITOR_NO_RC_CS(BCM_RLS_Stat);
Framemonitor_t BCM_VEH_STATE_FM = FRAMEMONITOR_NO_RC_CS(BCM_VEH_STATE);
Framemonitor_t BCM_Veh_State2_FM = FRAMEMONITOR_NO_RC_CS(BCM_Veh_State2);
Framemonitor_t CCU_Stat1_FM = FRAMEMONITOR_NO_RC_CS(CCU_Stat1);
Framemonitor_t DMFL_Msg1_FM = FRAMEMONITOR_NO_RC_CS(DMFL_Msg1);
Framemonitor_t DMFR_Msg1_FM = FRAMEMONITOR_NO_RC_CS(DMFR_Msg1);
Framemonitor_t DMRL_Msg1_FM = FRAMEMONITOR_NO_RC_CS(DMRL_Msg1);
Framemonitor_t DMRR_Msg1_FM = FRAMEMONITOR_NO_RC_CS(DMRR_Msg1);
Framemonitor_t BCM_DMS_01_FM = FRAMEMONITOR_WITH_RC_CS(BCM_DMS_01);
Framemonitor_t EMS_14_FM = FRAMEMONITOR_WITH_RC_CS(EMS_14);
Framemonitor_t EMS_3_FM = FRAMEMONITOR_NO_RC_CS(EMS_3);
Framemonitor_t EMS_4_FM = FRAMEMONITOR_NO_RC_CS(EMS_4);
Framemonitor_t EPB_Status_FM = FRAMEMONITOR_WITH_RC_CS(EPB_Status);
Framemonitor_t ESC_02_FM = FRAMEMONITOR_WITH_RC_CS(ESC_02);
Framemonitor_t ESC_03_FM = FRAMEMONITOR_WITH_RC_CS(ESC_03);
Framemonitor_t ESC_04_FM = FRAMEMONITOR_WITH_RC_CS(ESC_04);
Framemonitor_t ESC_06_FM = FRAMEMONITOR_WITH_RC_CS(ESC_06);
Framemonitor_t ESC_07_FM = FRAMEMONITOR_WITH_RC_CS(ESC_07);
Framemonitor_t ESC_09_FM = FRAMEMONITOR_WITH_RC_CS(ESC_09);
Framemonitor_t ESC_10_FM = FRAMEMONITOR_WITH_RC_CS(ESC_10);
Framemonitor_t ESC_YRS_01_FM = FRAMEMONITOR_WITH_RC_CS(ESC_YRS_01);
Framemonitor_t ESC_YRS_02_FM = FRAMEMONITOR_WITH_RC_CS(ESC_YRS_02);
Framemonitor_t IC_DMS_FM = FRAMEMONITOR_NO_RC_CS(IC_DMS);
Framemonitor_t IC_ADAS_REST_FM = FRAMEMONITOR_NO_RC_CS(IC_ADAS_REST);
Framemonitor_t IC_HUD_01_FM = FRAMEMONITOR_NO_RC_CS(IC_HUD_01);
Framemonitor_t IC_ABSOLUTE_CLOCK_FM = FRAMEMONITOR_WITH_RC_CS(IC_ABSOLUTE_CLOCK);
Framemonitor_t MAS_Status_FM = FRAMEMONITOR_WITH_RC_CS(MAS_Status);
Framemonitor_t MAS_FrontUSS_FM = FRAMEMONITOR_WITH_RC_CS(MAS_FrontUSS);
Framemonitor_t MAS_RearUSS_FM = FRAMEMONITOR_WITH_RC_CS(MAS_RearUSS);
Framemonitor_t MAS_SideUSS_FM = FRAMEMONITOR_WITH_RC_CS(MAS_SideUSS);
Framemonitor_t HLL_STATE_FM = FRAMEMONITOR_NO_RC_CS(HLL_STATE);
Framemonitor_t HLR_STATE_FM = FRAMEMONITOR_NO_RC_CS(HLR_STATE);
Framemonitor_t SAS_Standard_FM = FRAMEMONITOR_WITH_RC_CS(SAS_Standard);
Framemonitor_t SWM_ContrlsState_Old_FM = FRAMEMONITOR_WITH_RC_CS(SWM_ContrlsState_Old);
Framemonitor_t SWM_ContrlsState_FM = FRAMEMONITOR_WITH_RC_CS(SWM_ContrlsState);
Framemonitor_t SCU_02_FM = FRAMEMONITOR_WITH_RC_CS(SCU_02);
Framemonitor_t TCU_R932_1_FM = FRAMEMONITOR_WITH_RC_CS(TCU_R932_1);
Framemonitor_t FIU_Msg3_FM = FRAMEMONITOR_NO_RC_CS(FIU_Msg3);
Framemonitor_t VCU_ADAS_01_FM = FRAMEMONITOR_WITH_RC_CS(VCU_ADAS_01);
Framemonitor_t ATC_TX_FM = FRAMEMONITOR_WITH_RC_CS(ATC_TX);
Framemonitor_t Diag_Functional_FM = FRAMEMONITOR_NO_RC_CS(Diag_Functional);
Framemonitor_t EMS_03_FM = FRAMEMONITOR_WITH_RC_CS(EMS_03);
Framemonitor_t EMS_04_FM = FRAMEMONITOR_WITH_RC_CS(EMS_04);
Framemonitor_t EMS_16_FM = FRAMEMONITOR_WITH_RC_CS(EMS_16);
Framemonitor_t mLEDL_STATE_FM = FRAMEMONITOR_NO_RC_CS(mLEDL_STATE);
Framemonitor_t mLEDR_STATE_FM = FRAMEMONITOR_NO_RC_CS(mLEDR_STATE);
Framemonitor_t RSA_Status_FM = FRAMEMONITOR_WITH_RC_CS(RSA_Status);
Framemonitor_t TM_Stat_FM = FRAMEMONITOR_NO_RC_CS(TM_Stat);
Framemonitor_t VCU_DriverDmd_FM = FRAMEMONITOR_WITH_RC_CS(VCU_DriverDmd);



static boolean invalid = FALSE;


void Diag_ACU_01(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateXOR8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&ACU_01_FM, ACU_01_CS, checksum);
   FrameMonitor_CheckRC(&ACU_01_FM, ACU_01_RC);
   FrameMonitor_CheckDLC(&ACU_01_FM, dlc, 3);

   if(FrameMonitor_IsFaulty(&ACU_01_FM))
   {
      SetDefault_ACU_01();
   }
}


void Diag_BCM_CLIMATIC_DATA(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&BCM_CLIMATIC_DATA_FM, dlc, 6);

   if(FrameMonitor_IsFaulty(&BCM_CLIMATIC_DATA_FM))
   {
      SetDefault_BCM_CLIMATIC_DATA();
   }
}


void Diag_BCM_EXT_LGT(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateXOR8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&BCM_EXT_LGT_FM, BCM_EXT_LGT_CS, checksum);
   FrameMonitor_CheckRC(&BCM_EXT_LGT_FM, BCM_EXT_LGT_RC);
   FrameMonitor_CheckDLC(&BCM_EXT_LGT_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&BCM_EXT_LGT_FM))
   {
      SetDefault_BCM_EXT_LGT();
   }
}


void Diag_BCM_IC_Info_Msg(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&BCM_IC_Info_Msg_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&BCM_IC_Info_Msg_FM))
   {
      SetDefault_BCM_IC_Info_Msg();
   }
}


void Diag_BCM_Lock_CTR(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&BCM_Lock_CTR_FM, dlc, 7);

   if(FrameMonitor_IsFaulty(&BCM_Lock_CTR_FM))
   {
      SetDefault_BCM_Lock_CTR();
   }
}


void Diag_BCM_RLS_Stat(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&BCM_RLS_Stat_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&BCM_RLS_Stat_FM))
   {
      SetDefault_BCM_RLS_Stat();
   }
}


void Diag_BCM_VEH_STATE(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&BCM_VEH_STATE_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&BCM_VEH_STATE_FM))
   {
      SetDefault_BCM_VEH_STATE();
   }
}


void Diag_BCM_Veh_State2(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&BCM_Veh_State2_FM, dlc, 6);

   if(FrameMonitor_IsFaulty(&BCM_Veh_State2_FM))
   {
      SetDefault_BCM_Veh_State2();
   }
}


void Diag_CCU_Stat1(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&CCU_Stat1_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&CCU_Stat1_FM))
   {
      SetDefault_CCU_Stat1();
   }
}


void Diag_DMFL_Msg1(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&DMFL_Msg1_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&DMFL_Msg1_FM))
   {
      SetDefault_DMFL_Msg1();
   }
}


void Diag_DMFR_Msg1(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&DMFR_Msg1_FM, dlc, 4);

   if(FrameMonitor_IsFaulty(&DMFR_Msg1_FM))
   {
      SetDefault_DMFR_Msg1();
   }
}


void Diag_DMRL_Msg1(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&DMRL_Msg1_FM, dlc, 5);

   if(FrameMonitor_IsFaulty(&DMRL_Msg1_FM))
   {
      SetDefault_DMRL_Msg1();
   }
}


void Diag_DMRR_Msg1(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&DMRR_Msg1_FM, dlc, 5);

   if(FrameMonitor_IsFaulty(&DMRR_Msg1_FM))
   {
      SetDefault_DMRR_Msg1();
   }
}


void Diag_BCM_DMS_01(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateXOR8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&BCM_DMS_01_FM, BCM_DMS_01_RC, checksum);
   FrameMonitor_CheckRC(&BCM_DMS_01_FM, BCM_DMS_01_RC);
   FrameMonitor_CheckDLC(&BCM_DMS_01_FM, dlc, 3);

   if(FrameMonitor_IsFaulty(&BCM_DMS_01_FM))
   {
      SetDefault_BCM_DMS_01();
   }
}


void Diag_EMS_14(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&EMS_14_FM, EMS_14_CS, checksum);
   FrameMonitor_CheckRC(&EMS_14_FM, EMS_14_RC);
   FrameMonitor_CheckDLC(&EMS_14_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&EMS_14_FM))
   {
      SetDefault_EMS_14();
   }
}


void Diag_EMS_3(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&EMS_3_FM, dlc, 7);

   if(FrameMonitor_IsFaulty(&EMS_3_FM))
   {
      SetDefault_EMS_3();
   }
}


void Diag_EMS_4(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&EMS_4_FM, dlc, 7);

   if(FrameMonitor_IsFaulty(&EMS_4_FM))
   {
      SetDefault_EMS_4();
   }
}


void Diag_EPB_Status(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&EPB_Status_FM, EPB_Status_CS, checksum);
   FrameMonitor_CheckRC(&EPB_Status_FM, EPB_Status_RC);
   FrameMonitor_CheckDLC(&EPB_Status_FM, dlc, 5);

   if(FrameMonitor_IsFaulty(&EPB_Status_FM))
   {
      SetDefault_EPB_Status();
   }
}


void Diag_ESC_02(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&ESC_02_FM, ESC_02_CS, checksum);
   FrameMonitor_CheckRC(&ESC_02_FM, ESC_02_RC);
   FrameMonitor_CheckDLC(&ESC_02_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&ESC_02_FM))
   {
      SetDefault_ESC_02();
   }
}


void Diag_ESC_03(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&ESC_03_FM, ESC_03_CS, checksum);
   FrameMonitor_CheckRC(&ESC_03_FM, ESC_03_RC);
   FrameMonitor_CheckDLC(&ESC_03_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&ESC_03_FM))
   {
      SetDefault_ESC_03();
   }
}


void Diag_ESC_04(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&ESC_04_FM, ESC_04_CS, checksum);
   FrameMonitor_CheckRC(&ESC_04_FM, ESC_04_RC);
   FrameMonitor_CheckDLC(&ESC_04_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&ESC_04_FM))
   {
      SetDefault_ESC_04();
   }
}


void Diag_ESC_06(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&ESC_06_FM, ESC_06_CS, checksum);
   FrameMonitor_CheckRC(&ESC_06_FM, ESC_06_RC);
   FrameMonitor_CheckDLC(&ESC_06_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&ESC_06_FM))
   {
      SetDefault_ESC_06();
   }
}


void Diag_ESC_07(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&ESC_07_FM, ESC_07_CS, checksum);
   FrameMonitor_CheckRC(&ESC_07_FM, ESC_07_RC);
   FrameMonitor_CheckDLC(&ESC_07_FM, dlc, 6);

   if(FrameMonitor_IsFaulty(&ESC_07_FM))
   {
      SetDefault_ESC_07();
   }
}


void Diag_ESC_09(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&ESC_09_FM, ESC_09_CS, checksum);
   FrameMonitor_CheckRC(&ESC_09_FM, ESC_09_RC);
   FrameMonitor_CheckDLC(&ESC_09_FM, dlc, 4);

   if(FrameMonitor_IsFaulty(&ESC_09_FM))
   {
      SetDefault_ESC_09();
   }
}


void Diag_ESC_10(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&ESC_10_FM, ESC_10_CS, checksum);
   FrameMonitor_CheckRC(&ESC_10_FM, ESC_10_RC);
   FrameMonitor_CheckDLC(&ESC_10_FM, dlc, 4);

   if(FrameMonitor_IsFaulty(&ESC_10_FM))
   {
      SetDefault_ESC_10();
   }
}


void Diag_ESC_YRS_01(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&ESC_YRS_01_FM, ESC_YRS_01_CS, checksum);
   FrameMonitor_CheckRC(&ESC_YRS_01_FM, ESC_YRS_01_RC);
   FrameMonitor_CheckDLC(&ESC_YRS_01_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&ESC_YRS_01_FM))
   {
      SetDefault_ESC_YRS_01();
   }
}


void Diag_ESC_YRS_02(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&ESC_YRS_02_FM, ESC_YRS_02_CS, checksum);
   FrameMonitor_CheckRC(&ESC_YRS_02_FM, ESC_YRS_02_RC);
   FrameMonitor_CheckDLC(&ESC_YRS_02_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&ESC_YRS_02_FM))
   {
      SetDefault_ESC_YRS_02();
   }
}


void Diag_IC_DMS(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&IC_DMS_FM, dlc, 3);

   if(FrameMonitor_IsFaulty(&IC_DMS_FM))
   {
      SetDefault_IC_DMS();
   }
}


void Diag_IC_ADAS_REST(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&IC_ADAS_REST_FM, dlc, 7);

   if(FrameMonitor_IsFaulty(&IC_ADAS_REST_FM))
   {
      SetDefault_IC_ADAS_REST();
   }
}


void Diag_IC_HUD_01(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&IC_HUD_01_FM, dlc, 4);

   if(FrameMonitor_IsFaulty(&IC_HUD_01_FM))
   {
      SetDefault_IC_HUD_01();
   }
}


void Diag_IC_ABSOLUTE_CLOCK(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&IC_ABSOLUTE_CLOCK_FM, IC_ABSOLUTE_CLOCK_CS, checksum);
   FrameMonitor_CheckRC(&IC_ABSOLUTE_CLOCK_FM, IC_ABSOLUTE_CLOCK_RC);
   FrameMonitor_CheckDLC(&IC_ABSOLUTE_CLOCK_FM, dlc, 6);

   if(FrameMonitor_IsFaulty(&IC_ABSOLUTE_CLOCK_FM))
   {
      SetDefault_IC_ABSOLUTE_CLOCK();
   }
}


void Diag_MAS_Status(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&MAS_Status_FM, MAS_Status_CS, checksum);
   FrameMonitor_CheckRC(&MAS_Status_FM, MAS_Status_RC);
   FrameMonitor_CheckDLC(&MAS_Status_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&MAS_Status_FM))
   {
      SetDefault_MAS_Status();
   }
}


void Diag_MAS_FrontUSS(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&MAS_FrontUSS_FM, MAS_FrontUSS_CS, checksum);
   FrameMonitor_CheckRC(&MAS_FrontUSS_FM, MAS_FrontUSS_RC);
   FrameMonitor_CheckDLC(&MAS_FrontUSS_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&MAS_FrontUSS_FM))
   {
      SetDefault_MAS_FrontUSS();
   }
}


void Diag_MAS_RearUSS(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&MAS_RearUSS_FM, MAS_RearUSS_CS, checksum);
   FrameMonitor_CheckRC(&MAS_RearUSS_FM, MAS_RearUSS_RC);
   FrameMonitor_CheckDLC(&MAS_RearUSS_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&MAS_RearUSS_FM))
   {
      SetDefault_MAS_RearUSS();
   }
}


void Diag_MAS_SideUSS(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&MAS_SideUSS_FM, MAS_SideUSS_CS, checksum);
   FrameMonitor_CheckRC(&MAS_SideUSS_FM, MAS_SideUSS_RC);
   FrameMonitor_CheckDLC(&MAS_SideUSS_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&MAS_SideUSS_FM))
   {
      SetDefault_MAS_SideUSS();
   }
}


void Diag_HLL_STATE(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&HLL_STATE_FM, dlc, 5);

   if(FrameMonitor_IsFaulty(&HLL_STATE_FM))
   {
      SetDefault_HLL_STATE();
   }
}


void Diag_HLR_STATE(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&HLR_STATE_FM, dlc, 5);

   if(FrameMonitor_IsFaulty(&HLR_STATE_FM))
   {
      SetDefault_HLR_STATE();
   }
}


void Diag_SAS_Standard(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateXOR4(data, dlc, (dlc - 1) * 8 + 4);
   FrameMonitor_CheckCS(&SAS_Standard_FM, SAS_Standard_CS, checksum);
   FrameMonitor_CheckRC(&SAS_Standard_FM, SAS_Standard_RC);
   FrameMonitor_CheckDLC(&SAS_Standard_FM, dlc, 5);

   if(FrameMonitor_IsFaulty(&SAS_Standard_FM))
   {
      SetDefault_SAS_Standard();
   }
}


void Diag_SWM_ContrlsState_Old(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateXOR8(data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&SWM_ContrlsState_Old_FM, SWM_ContrlsState_Old_CS, checksum);
   FrameMonitor_CheckRC(&SWM_ContrlsState_Old_FM, SWM_ContrlsState_Old_RC);
   FrameMonitor_CheckDLC(&SWM_ContrlsState_Old_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&SWM_ContrlsState_Old_FM))
   {
      SetDefault_SWM_ContrlsState_Old();
   }
}


void Diag_SWM_ContrlsState(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateXOR8(data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&SWM_ContrlsState_FM, SWM_ContrlsState_CS, checksum);
   FrameMonitor_CheckRC(&SWM_ContrlsState_FM, SWM_ContrlsState_RC);
   FrameMonitor_CheckDLC(&SWM_ContrlsState_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&SWM_ContrlsState_FM))
   {
      SetDefault_SWM_ContrlsState();
   }
}


void Diag_SCU_02(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateXOR8(data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&SCU_02_FM, SCU_02_CS, checksum);
   FrameMonitor_CheckRC(&SCU_02_FM, SCU_02_RC);
   FrameMonitor_CheckDLC(&SCU_02_FM, dlc, 6);

   if(FrameMonitor_IsFaulty(&SCU_02_FM))
   {
      SetDefault_SCU_02();
   }
}


void Diag_TCU_R932_1(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateXOR8(data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&TCU_R932_1_FM, TCU_R932_1_CS, checksum);
   FrameMonitor_CheckRC(&TCU_R932_1_FM, TCU_R932_1_RC);
   FrameMonitor_CheckDLC(&TCU_R932_1_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&TCU_R932_1_FM))
   {
      SetDefault_TCU_R932_1();
   }
}


void Diag_FIU_Msg3(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&FIU_Msg3_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&FIU_Msg3_FM))
   {
      SetDefault_FIU_Msg3();
   }
}


void Diag_VCU_ADAS_01(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&VCU_ADAS_01_FM, VCU_ADAS_01_CS, checksum);
   FrameMonitor_CheckRC(&VCU_ADAS_01_FM, VCU_ADAS_01_RC);
   FrameMonitor_CheckDLC(&VCU_ADAS_01_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&VCU_ADAS_01_FM))
   {
      SetDefault_VCU_ADAS_01();
   }
}


void Diag_ATC_TX(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&ATC_TX_FM, CRC_DT3_2, checksum);
   FrameMonitor_CheckRC(&ATC_TX_FM, MessageCounter_DT3_2_RC);
   FrameMonitor_CheckDLC(&ATC_TX_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&ATC_TX_FM))
   {
      SetDefault_ATC_TX();
   }
}


void Diag_Diag_Functional(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&Diag_Functional_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&Diag_Functional_FM))
   {
      SetDefault_Diag_Functional();
   }
}


void Diag_EMS_03(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateXOR8(data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&EMS_03_FM, EMS_03_CS, checksum);
   FrameMonitor_CheckRC(&EMS_03_FM, EMS_03_RC);
   FrameMonitor_CheckDLC(&EMS_03_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&EMS_03_FM))
   {
      SetDefault_EMS_03();
   }
}


void Diag_EMS_04(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateXOR8(data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&EMS_04_FM, EMS_04_CS, checksum);
   FrameMonitor_CheckRC(&EMS_04_FM, EMS_04_RC);
   FrameMonitor_CheckDLC(&EMS_04_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&EMS_04_FM))
   {
      SetDefault_EMS_04();
   }
}


void Diag_EMS_16(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&EMS_16_FM, EMS_16_CS, checksum);
   FrameMonitor_CheckRC(&EMS_16_FM, EMS_16_RC);
   FrameMonitor_CheckDLC(&EMS_16_FM, dlc, 6);

   if(FrameMonitor_IsFaulty(&EMS_16_FM))
   {
      SetDefault_EMS_16();
   }
}


void Diag_mLEDL_STATE(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&mLEDL_STATE_FM, dlc, 5);

   if(FrameMonitor_IsFaulty(&mLEDL_STATE_FM))
   {
      SetDefault_mLEDL_STATE();
   }
}


void Diag_mLEDR_STATE(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&mLEDR_STATE_FM, dlc, 5);

   if(FrameMonitor_IsFaulty(&mLEDR_STATE_FM))
   {
      SetDefault_mLEDR_STATE();
   }
}


void Diag_RSA_Status(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&RSA_Status_FM, RSA_Status_CS, checksum);
   FrameMonitor_CheckRC(&RSA_Status_FM, RSA_Status_RC);
   FrameMonitor_CheckDLC(&RSA_Status_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&RSA_Status_FM))
   {
      SetDefault_RSA_Status();
   }
}


void Diag_TM_Stat(uint8* data, uint8 dlc)
{
   FrameMonitor_CheckDLC(&TM_Stat_FM, dlc, 4);

   if(FrameMonitor_IsFaulty(&TM_Stat_FM))
   {
      SetDefault_TM_Stat();
   }
}


void Diag_VCU_DriverDmd(uint8* data, uint8 dlc)
{
   uint8 checksum = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
   FrameMonitor_CheckCS(&VCU_DriverDmd_FM, VCU_DriverDmd_CS, checksum);
   FrameMonitor_CheckRC(&VCU_DriverDmd_FM, VCU_DriverDmd_RC);
   FrameMonitor_CheckDLC(&VCU_DriverDmd_FM, dlc, 8);

   if(FrameMonitor_IsFaulty(&VCU_DriverDmd_FM))
   {
      SetDefault_VCU_DriverDmd();
   }
}


void Prepare_DAS_01()
{
   DAS_01_RC++;
}


void Prepare_DAS_02()
{
   DAS_02_RC++;
}


void Prepare_DAS_03()
{
   DAS_03_RC++;
}


void Prepare_DAS_04()
{
   DAS_04_RC++;
}


void Prepare_DAS_07()
{
   DAS_07_RC++;
}


void Prepare_DAS_Configure()
{
   DAS_Conf_RC++;
}


void Prepare_DAS_EMS()
{
   DAS_EMS_RC++;
}


void Prepare_DAS_FIU_Settings()
{
   DAS_FIU_Settings_RC++;
}


void Prepare_DAS_Main()
{
   DAS_Main_RC++;
}


void Prepare_DAS_VCU()
{
   DAS_VCU_RC++;
}


void Prepare_DASCU_HLL_Object()
{
   DAS_HLL_Object_RC++;
}


void Prepare_DASCU_HLR_Object()
{
   DAS_HLR_Object_RC++;
}


void FillCS_DAS_01(uint8* data, uint8 dlc)
{
   data[dlc - 1] = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
}


void FillCS_DAS_02(uint8* data, uint8 dlc)
{
   data[dlc - 1] = CAN_CalculateXOR8(data, dlc, (dlc - 1) * 8);
}


void FillCS_DAS_03(uint8* data, uint8 dlc)
{
   data[dlc - 1] = CAN_CalculateXOR8(data, dlc, (dlc - 1) * 8);
}


void FillCS_DAS_04(uint8* data, uint8 dlc)
{
   data[dlc - 1] = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
}


void FillCS_DAS_07(uint8* data, uint8 dlc)
{
   data[dlc - 1] = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
}


void FillCS_DAS_Configure(uint8* data, uint8 dlc)
{
   data[dlc - 1] = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
}


void FillCS_DAS_EMS(uint8* data, uint8 dlc)
{
   data[dlc - 1] = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
}


void FillCS_DAS_FIU_Settings(uint8* data, uint8 dlc)
{
   data[dlc - 1] = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
}


void FillCS_DAS_Main(uint8* data, uint8 dlc)
{
   data[dlc - 1] = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
}


void FillCS_DAS_VCU(uint8* data, uint8 dlc)
{
   data[dlc - 1] = CAN_CalculateCRC8 (data, dlc, (dlc - 1) * 8);
}


void FillCS_DASCU_HLL_Object(uint8* data, uint8 dlc)
{
   data[dlc - 1] = CAN_CalculateXOR8(data, dlc, (dlc - 1) * 8);
}


void FillCS_DASCU_HLR_Object(uint8* data, uint8 dlc)
{
   data[dlc - 1] = CAN_CalculateXOR8(data, dlc, (dlc - 1) * 8);
}



