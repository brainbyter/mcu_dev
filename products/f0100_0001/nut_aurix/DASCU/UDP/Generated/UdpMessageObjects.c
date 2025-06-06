#include <UDP_IDs.h>
#include <UdpMessageObjects.h>
#include <UdpHandlers.h>

UdpMessageObject_t UDP_Main_Start_MO = {.ID = UDP_Main_Start_ID, .DLC = 10, .cycle = 50, .dir = ToGpu, .handler = UDP_Main_Start_Handler};
UdpMessageObject_t UDP_Climatic_MO = {.ID = UDP_Climatic_ID, .DLC = 4, .cycle = 250, .dir = ToGpu, .handler = UDP_Climatic_Handler};
UdpMessageObject_t UDP_BCM_LGT_MO = {.ID = UDP_BCM_LGT_ID, .DLC = 4, .cycle = 50, .dir = ToGpu, .handler = UDP_BCM_LGT_Handler};
UdpMessageObject_t UDP_BCM_VehState_MO = {.ID = UDP_BCM_VehState_ID, .DLC = 4, .cycle = 50, .dir = ToGpu, .handler = UDP_BCM_VehState_Handler};
UdpMessageObject_t UDP_ESC_Front_Speed_MO = {.ID = UDP_ESC_Front_Speed_ID, .DLC = 14, .cycle = 10, .dir = ToGpu, .handler = UDP_ESC_Front_Speed_Handler};
UdpMessageObject_t UDP_ESC_Rear_Speed_MO = {.ID = UDP_ESC_Rear_Speed_ID, .DLC = 12, .cycle = 10, .dir = ToGpu, .handler = UDP_ESC_Rear_Speed_Handler};
UdpMessageObject_t UDP_ESC_Veh_Speed_MO = {.ID = UDP_ESC_Veh_Speed_ID, .DLC = 9, .cycle = 20, .dir = ToGpu, .handler = UDP_ESC_Veh_Speed_Handler};
UdpMessageObject_t UDP_ESC_YR_MO = {.ID = UDP_ESC_YR_ID, .DLC = 12, .cycle = 10, .dir = ToGpu, .handler = UDP_ESC_YR_Handler};
UdpMessageObject_t UDP_ESC_AX_MO = {.ID = UDP_ESC_AX_ID, .DLC = 7, .cycle = 10, .dir = ToGpu, .handler = UDP_ESC_AX_Handler};
UdpMessageObject_t UDP_SAS_MO = {.ID = UDP_SAS_ID, .DLC = 12, .cycle = 10, .dir = ToGpu, .handler = UDP_SAS_Handler};
UdpMessageObject_t UDP_MAS_Front_Sensor_MO = {.ID = UDP_MAS_Front_Sensor_ID, .DLC = 6, .cycle = 100, .dir = ToGpu, .handler = UDP_MAS_Front_Sensor_Handler};
UdpMessageObject_t UDP_MAS_Rear_Sensor_MO = {.ID = UDP_MAS_Rear_Sensor_ID, .DLC = 6, .cycle = 100, .dir = ToGpu, .handler = UDP_MAS_Rear_Sensor_Handler};
UdpMessageObject_t UDP_MAS_Side_Sensor_MO = {.ID = UDP_MAS_Side_Sensor_ID, .DLC = 18, .cycle = 100, .dir = ToGpu, .handler = UDP_MAS_Side_Sensor_Handler};
UdpMessageObject_t UDP_SCU_MO = {.ID = UDP_SCU_ID, .DLC = 6, .cycle = 100, .dir = ToGpu, .handler = UDP_SCU_Handler};
UdpMessageObject_t UDP_IC_ABSOLUTE_CLOCK_MO = {.ID = UDP_IC_ABSOLUTE_CLOCK_ID, .DLC = 6, .cycle = 1000, .dir = ToGpu, .handler = UDP_IC_ABSOLUTE_CLOCK_Handler};
UdpMessageObject_t UDP_IC_HUD_01_MO = {.ID = UDP_IC_HUD_01_ID, .DLC = 6, .cycle = 0, .dir = ToGpu, .handler = UDP_IC_HUD_01_Handler};
UdpMessageObject_t UDP_Diag_Config_MO = {.ID = UDP_Diag_Config_ID, .DLC = 24, .cycle = 1000, .dir = ToGpu, .handler = UDP_Diag_Config_Handler};
UdpMessageObject_t UDP_Diag_Calibration_MO = {.ID = UDP_Diag_Calibration_ID, .DLC = 24, .cycle = 100, .dir = ToGpu, .handler = UDP_Diag_Calibration_Handler};
UdpMessageObject_t UDP_FanSpeedControl_MO = {.ID = UDP_FanSpeedControl_ID, .DLC = 3, .cycle = 100, .dir = ToGpu, .handler = UDP_FanSpeedControl_Handler};
UdpMessageObject_t UDP_ERAG_MO = {.ID = UDP_ERAG_ID, .DLC = 32, .cycle = 100, .dir = ToGpu, .handler = UDP_ERAG_Handler};
UdpMessageObject_t UDP_TCU_R932_1_MO = {.ID = UDP_TCU_R932_1_ID, .DLC = 3, .cycle = 10, .dir = ToGpu, .handler = UDP_TCU_R932_1_Handler};
UdpMessageObject_t UDP_MainDataFromPerc_MO = {.ID = UDP_MainDataFromPerc_ID, .DLC = 12, .cycle = 50, .dir = FromGpu, .handler = UDP_MainDataFromPerc_Handler, .countCycleTimeout = 5};
UdpMessageObject_t UDP_FrontPas_MO = {.ID = UDP_FrontPas_ID, .DLC = 354, .cycle = 50, .dir = FromGpu, .handler = UDP_FrontPas_Handler, .countCycleTimeout = 5};
UdpMessageObject_t UDP_RearPass_MO = {.ID = UDP_RearPass_ID, .DLC = 191, .cycle = 50, .dir = FromGpu, .handler = UDP_RearPass_Handler, .countCycleTimeout = 5};
UdpMessageObject_t UDP_Lane_MO = {.ID = UDP_Lane_ID, .DLC = 226, .cycle = 50, .dir = FromGpu, .handler = UDP_Lane_Handler, .countCycleTimeout = 5};
UdpMessageObject_t UDP_SignPerc_MO = {.ID = UDP_SignPerc_ID, .DLC = 50, .cycle = 50, .dir = FromGpu, .handler = UDP_SignPerc_Handler, .countCycleTimeout = 5};
UdpMessageObject_t UDP_MliaPerc_MO = {.ID = UDP_MliaPerc_ID, .DLC = 570, .cycle = 50, .dir = FromGpu, .handler = UDP_MliaPerc_Handler, .countCycleTimeout = 5};
UdpMessageObject_t UDP_GPU_States_MO = {.ID = UDP_GPU_States_ID, .DLC = 58, .cycle = 1000, .dir = FromGpu, .handler = UDP_GPU_States_Handler, .countCycleTimeout = 5};
