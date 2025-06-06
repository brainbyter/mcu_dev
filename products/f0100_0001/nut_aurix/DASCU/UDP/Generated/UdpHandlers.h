#include <Platform_Types.h>

extern void UDP_Main_Start_Handler(unsigned char* data);
void Prepare_UDP_Main_Start();

extern void UDP_Climatic_Handler(unsigned char* data);
void Prepare_UDP_Climatic();

extern void UDP_BCM_LGT_Handler(unsigned char* data);
void Prepare_UDP_BCM_LGT();

extern void UDP_BCM_VehState_Handler(unsigned char* data);
void Prepare_UDP_BCM_VehState();

extern void UDP_ESC_Front_Speed_Handler(unsigned char* data);
void Prepare_UDP_ESC_Front_Speed();

extern void UDP_ESC_Rear_Speed_Handler(unsigned char* data);
void Prepare_UDP_ESC_Rear_Speed();

extern void UDP_ESC_Veh_Speed_Handler(unsigned char* data);
void Prepare_UDP_ESC_Veh_Speed();

extern void UDP_ESC_YR_Handler(unsigned char* data);
void Prepare_UDP_ESC_YR();

extern void UDP_ESC_AX_Handler(unsigned char* data);
void Prepare_UDP_ESC_AX();

extern void UDP_SAS_Handler(unsigned char* data);
void Prepare_UDP_SAS();

extern void UDP_MAS_Front_Sensor_Handler(unsigned char* data);
void Prepare_UDP_MAS_Front_Sensor();

extern void UDP_MAS_Rear_Sensor_Handler(unsigned char* data);
void Prepare_UDP_MAS_Rear_Sensor();

extern void UDP_MAS_Side_Sensor_Handler(unsigned char* data);
void Prepare_UDP_MAS_Side_Sensor();

extern void UDP_SCU_Handler(unsigned char* data);
void Prepare_UDP_SCU();

extern void UDP_IC_ABSOLUTE_CLOCK_Handler(unsigned char* data);
void Prepare_UDP_IC_ABSOLUTE_CLOCK();

extern void UDP_IC_HUD_01_Handler(unsigned char* data);
void Prepare_UDP_IC_HUD_01();

extern void UDP_Diag_Config_Handler(unsigned char* data);
void Prepare_UDP_Diag_Config();

extern void UDP_Diag_Calibration_Handler(unsigned char* data);
void Prepare_UDP_Diag_Calibration();

extern void UDP_FanSpeedControl_Handler(unsigned char* data);
void Prepare_UDP_FanSpeedControl();

extern void UDP_ERAG_Handler(unsigned char* data);
void Prepare_UDP_ERAG();

extern void UDP_TCU_R932_1_Handler(unsigned char* data);
void Prepare_UDP_TCU_R932_1();

extern void UDP_MainDataFromPerc_Handler(unsigned char* data);
void SetDefault_UDP_MainDataFromPerc();

extern void UDP_FrontPas_Handler(unsigned char* data);
void SetDefault_UDP_FrontPas();

extern void UDP_RearPass_Handler(unsigned char* data);
void SetDefault_UDP_RearPass();

extern void UDP_Lane_Handler(unsigned char* data);
void SetDefault_UDP_Lane();

extern void UDP_SignPerc_Handler(unsigned char* data);
void SetDefault_UDP_SignPerc();

extern void UDP_MliaPerc_Handler(unsigned char* data);
void SetDefault_UDP_MliaPerc();

extern void UDP_GPU_States_Handler(unsigned char* data);
void SetDefault_UDP_GPU_States();
