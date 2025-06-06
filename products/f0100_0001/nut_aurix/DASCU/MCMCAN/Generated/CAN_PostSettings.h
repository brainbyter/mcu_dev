#include <CAN_Private.h>

#define TestDataOut_Cycle_Value      (uint32_t)50
#define DEFAULT_MainStart_MO   0

extern unsigned char FIU_ADAS_Config_Handler_dtd;

extern void CAN_PostSettings();
extern void MainStart_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void SetDefault_MainStart_Mod();
extern void SetDefault_DiagMrrDidReq_Mod();

extern void SetDefault_DiagMrrL_DidReq_Mod();
extern void SetDefault_DiagMrrR_DidReq_Mod();

extern void SetDefault_DiagPanelConn_Mod();
extern void DiagPanelConn_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void ESC_04_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void SetDefault_Emu_EMS_Mod();
extern void SetDefault_Emu_Spd_Mod();
extern void SetDefault_Emu_Blink_Xcp_Mod();
/* FUCKING! */
extern void FillCS_DASCU_HLL_Object_Mod(uint8* data, uint8 dlc);
extern void FillCS_DASCU_HLR_Object_Mod(uint8* data, uint8 dlc);

extern void ERAG_NMEA6_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void ERAG_NMEA5_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void ERAG_NMEA4_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void ERAG_NMEA3_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void ERAG_NMEA2_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void ERAG_NMEA1_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void SetDefault_ERAG_NMEA();

extern void DAS_04_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void FIU_ADAS_Config_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void DAS_HUD_02_Handler_Mod(uint8_t *data, uint8_t dlc);

/* HAVAL Handlers-mods */
extern void ABM1_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void ABM2_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void ABS1_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void ABS2_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void ABS3_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void ACC_FD2_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void AEB_FD1_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void CSA1_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void CSA2_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void ESP1_Handler_Mod(uint8_t *data, uint8_t dlc);
extern void IFC_FD2_Handler_Mod(uint8_t *data, uint8_t dlc);
