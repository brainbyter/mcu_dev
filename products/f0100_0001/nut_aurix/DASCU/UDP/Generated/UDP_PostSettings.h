#include <stdint.h>
#include <Platform_Types.h>

extern void UDP_PostSettings();
extern void Prepare_UDP_Diag_Calibration_Mod();
extern void UDP_Main_Start_Handler_Mod(uint8* data);
extern void UDP_BCM_VehState_Handler_Mod(uint8* data);
//extern void Prepare_UDP_FanSpeedControl_Mod();
//extern void Prepare_UDP_MainDataFromPerc_Handler_Mod();
//extern void UDP_MainDataFromPerc_Handler_Mod(uint8* data);
