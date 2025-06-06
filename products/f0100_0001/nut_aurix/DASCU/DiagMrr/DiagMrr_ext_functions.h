#include <Platform_Types.h>
#include <stdint.h>
#include "DiagMrr_typedefs.h"

extern void prepareMrrxNRCFrame(uint8* data);
extern void answerMrrxFrame();
extern void CalibrationRadar(radar_pos_t radar_pos, diag_state_t *diag_state);
extern void manageStateCalibr();
extern void manageRequest();
extern void manageStateMrrx();

extern int find_did(uint16 did);
extern void Boot_SW_Ident_DID_Handler(unsigned char *data, radar_pos_t pos);
extern void OEM_Part_Number_Handler(unsigned char *data, radar_pos_t pos);
extern void VIN_Handler(unsigned char *data, radar_pos_t pos);
extern void Software_Version_Number_Handler(unsigned char *data, radar_pos_t pos);
extern void Repair_Shop_Code_Handler(unsigned char *data, radar_pos_t pos);
extern void Programming_Data_Handler(unsigned char *data, radar_pos_t pos);
extern void ECU_Installation_Date_Handler(unsigned char *data, radar_pos_t pos);
extern void Radar_Alignment_Completion_Flag_Handler(unsigned char *data, radar_pos_t pos);
extern void Radar_Alignment_Results_Handler(unsigned char *data, radar_pos_t pos);
extern void Radar_Supply_Voltage_12V_Handler(unsigned char *data, radar_pos_t pos);
extern void MCU_Supply_Voltage_5V_Handler(unsigned char *data, radar_pos_t pos);
extern void RF_Supply_Voltage_1_5V_Handler(unsigned char *data, radar_pos_t pos);
extern void Radar_Temperature_Handler(unsigned char *data, radar_pos_t pos);
extern void RadarManufactureData_Handler(unsigned char *data, radar_pos_t pos);
extern void VehiPara_Handler(unsigned char *data, radar_pos_t pos);
extern void RadarInsParas_Handler(unsigned char *data, radar_pos_t pos);
extern void DONTKNOW_Handler(unsigned char *data, radar_pos_t pos);
extern void TRIANGLE_REFL_INFO_Handler(unsigned char *data, radar_pos_t pos);

extern void prepareServChangeSession(unsigned char *data, unsigned char subFunc);
extern unsigned char* prepareServWriteData(unsigned char *txData, unsigned char *buff, unsigned short len, unsigned short did, frame_t frame);
extern void prepareServReadData(unsigned char *data, unsigned short did);
extern void prepareServCommControl(unsigned char *data, unsigned short len, unsigned char subFunc, unsigned char commType);
extern void prepareServClearDTC(unsigned char *data, unsigned short len, unsigned char subFunc);
extern void prepareServRoutineControl(unsigned char *data, unsigned short len, unsigned char subFunc, unsigned short did);
extern void prepareServECUReset(unsigned char *data, unsigned short len, unsigned char subFunc);
extern void prepareDiagSingleFrame(unsigned char *data, unsigned short did, unsigned char subFunc);
extern void prepareDiagFlowControlFrame(unsigned char *data, unsigned char flag, unsigned char blockSize, unsigned char sepTime);
extern void prepareUdsData(unsigned char *data);
extern void udsExitCalibration();
extern void udsPosResponceCibration(step_calib_t target_step_calib);
extern uint32 mrr_reverse_bit32(uint32 x);
extern uint16 mrr_reverse_bit16(uint16 x);
