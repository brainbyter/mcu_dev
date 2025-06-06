#include <UDP_Typedefs.h>
#include <UdpMessageObjects.h>
#include <UDP_Extern_vars.h>
#include <UDP_Extern.h>
#include <UdpHandlers.h>

void UDP_InitMessageObjects()
{
	UDP_Main_Start_MO.pRC = &UDP_Main_Start_RC;
	UDP_Main_Start_MO.prepareHandler = Prepare_UDP_Main_Start;
	UDP_InitMessageObject(&UDP_Main_Start_MO);

	UDP_Climatic_MO.pRC = &UDP_Climatic_RC;
	UDP_Climatic_MO.prepareHandler = Prepare_UDP_Climatic;
	UDP_InitMessageObject(&UDP_Climatic_MO);

	UDP_BCM_LGT_MO.pRC = &UDP_BCM_LGT_RC;
	UDP_BCM_LGT_MO.prepareHandler = Prepare_UDP_BCM_LGT;
	UDP_InitMessageObject(&UDP_BCM_LGT_MO);

	UDP_BCM_VehState_MO.pRC = &UDP_BCM_VehState_RC;
	UDP_BCM_VehState_MO.prepareHandler = Prepare_UDP_BCM_VehState;
	UDP_InitMessageObject(&UDP_BCM_VehState_MO);

	UDP_ESC_Front_Speed_MO.pRC = &UDP_ESC_Front_Speed_RC;
	UDP_ESC_Front_Speed_MO.prepareHandler = Prepare_UDP_ESC_Front_Speed;
	UDP_InitMessageObject(&UDP_ESC_Front_Speed_MO);

	UDP_ESC_Rear_Speed_MO.pRC = &UDP_ESC_Rear_Speed_RC;
	UDP_ESC_Rear_Speed_MO.prepareHandler = Prepare_UDP_ESC_Rear_Speed;
	UDP_InitMessageObject(&UDP_ESC_Rear_Speed_MO);

	UDP_ESC_Veh_Speed_MO.pRC = &UDP_ESC_Veh_Speed_RC;
	UDP_ESC_Veh_Speed_MO.prepareHandler = Prepare_UDP_ESC_Veh_Speed;
	UDP_InitMessageObject(&UDP_ESC_Veh_Speed_MO);

	UDP_ESC_YR_MO.pRC = &UDP_ESC_YR_RC;
	UDP_ESC_YR_MO.prepareHandler = Prepare_UDP_ESC_YR;
	UDP_InitMessageObject(&UDP_ESC_YR_MO);

	UDP_ESC_AX_MO.pRC = &UDP_ESC_AX_RC;
	UDP_ESC_AX_MO.prepareHandler = Prepare_UDP_ESC_AX;
	UDP_InitMessageObject(&UDP_ESC_AX_MO);

	UDP_SAS_MO.pRC = &UDP_SAS_RC;
	UDP_SAS_MO.prepareHandler = Prepare_UDP_SAS;
	UDP_InitMessageObject(&UDP_SAS_MO);

	UDP_MAS_Front_Sensor_MO.pRC = &UDP_MAS_Front_Sensor_RC;
	UDP_MAS_Front_Sensor_MO.prepareHandler = Prepare_UDP_MAS_Front_Sensor;
	UDP_InitMessageObject(&UDP_MAS_Front_Sensor_MO);

	UDP_MAS_Rear_Sensor_MO.pRC = &UDP_MAS_Rear_Sensor_RC;
	UDP_MAS_Rear_Sensor_MO.prepareHandler = Prepare_UDP_MAS_Rear_Sensor;
	UDP_InitMessageObject(&UDP_MAS_Rear_Sensor_MO);

	UDP_MAS_Side_Sensor_MO.pRC = &UDP_MAS_Side_Sensor_RC;
	UDP_MAS_Side_Sensor_MO.prepareHandler = Prepare_UDP_MAS_Side_Sensor;
	UDP_InitMessageObject(&UDP_MAS_Side_Sensor_MO);

	UDP_SCU_MO.pRC = &UDP_SCU_RC;
	UDP_SCU_MO.prepareHandler = Prepare_UDP_SCU;
	UDP_InitMessageObject(&UDP_SCU_MO);

	UDP_IC_ABSOLUTE_CLOCK_MO.pRC = &UDP_IC_ABSOLUTE_CLOCK_RC;
	UDP_IC_ABSOLUTE_CLOCK_MO.prepareHandler = Prepare_UDP_IC_ABSOLUTE_CLOCK;
	UDP_InitMessageObject(&UDP_IC_ABSOLUTE_CLOCK_MO);

	UDP_IC_HUD_01_MO.pRC = &UDP_IC_HUD_01_RC;
	UDP_IC_HUD_01_MO.prepareHandler = Prepare_UDP_IC_HUD_01;
	UDP_InitMessageObject(&UDP_IC_HUD_01_MO);

	UDP_Diag_Config_MO.pRC = &UDP_Diag_Config_RC;
	UDP_Diag_Config_MO.prepareHandler = Prepare_UDP_Diag_Config;
	UDP_InitMessageObject(&UDP_Diag_Config_MO);

	UDP_Diag_Calibration_MO.pRC = &UDP_Diag_Calibration_RC;
	UDP_Diag_Calibration_MO.prepareHandler = Prepare_UDP_Diag_Calibration;
	UDP_InitMessageObject(&UDP_Diag_Calibration_MO);

	UDP_FanSpeedControl_MO.pRC = &UDP_FanSpeedControl_RC;
	UDP_FanSpeedControl_MO.prepareHandler = Prepare_UDP_FanSpeedControl;
	UDP_InitMessageObject(&UDP_FanSpeedControl_MO);

	UDP_ERAG_MO.pRC = &UDP_ERAG_RC;
	UDP_ERAG_MO.prepareHandler = Prepare_UDP_ERAG;
	UDP_InitMessageObject(&UDP_ERAG_MO);

	UDP_TCU_R932_1_MO.pRC = &UDP_TCU_R932_1_RC;
	UDP_TCU_R932_1_MO.prepareHandler = Prepare_UDP_TCU_R932_1;
	UDP_InitMessageObject(&UDP_TCU_R932_1_MO);

	UDP_MainDataFromPerc_MO.failHandler = SetDefault_UDP_MainDataFromPerc;
	UDP_MainDataFromPerc_MO.pTimeout = &ComScl_UDP_MainDataFromPerc_Timeout;
	UDP_MainDataFromPerc_MO.pRC = &UDP_MainDataFromPerc_RC;
	UDP_InitMessageObject(&UDP_MainDataFromPerc_MO);

	UDP_FrontPas_MO.failHandler = SetDefault_UDP_FrontPas;
	UDP_FrontPas_MO.pTimeout = &ComScl_UDP_FrontPas_Timeout;
	UDP_FrontPas_MO.pRC = &UDP_FrontPas_RC;
	UDP_InitMessageObject(&UDP_FrontPas_MO);

	UDP_RearPass_MO.failHandler = SetDefault_UDP_RearPass;
	UDP_RearPass_MO.pTimeout = &ComScl_UDP_RearPass_Timeout;
	UDP_RearPass_MO.pRC = &UDP_RearPass_RC;
	UDP_InitMessageObject(&UDP_RearPass_MO);

	UDP_Lane_MO.failHandler = SetDefault_UDP_Lane;
	UDP_Lane_MO.pTimeout = &ComScl_UDP_Lane_Timeout;
	UDP_Lane_MO.pRC = &UDP_Lane_RC;
	UDP_InitMessageObject(&UDP_Lane_MO);

	UDP_SignPerc_MO.failHandler = SetDefault_UDP_SignPerc;
	UDP_SignPerc_MO.pTimeout = &ComScl_UDP_SignPerc_Timeout;
	UDP_SignPerc_MO.pRC = &UDP_SignPerc_RC;
	UDP_InitMessageObject(&UDP_SignPerc_MO);

	UDP_MliaPerc_MO.failHandler = SetDefault_UDP_MliaPerc;
	UDP_MliaPerc_MO.pTimeout = &ComScl_UDP_MliaPerc_Timeout;
	UDP_MliaPerc_MO.pRC = &UDP_MliaPerc_RC;
	UDP_InitMessageObject(&UDP_MliaPerc_MO);

	UDP_GPU_States_MO.failHandler = SetDefault_UDP_GPU_States;
	UDP_GPU_States_MO.pTimeout = &ComScl_UDP_GPU_States_Timeout;
	UDP_GPU_States_MO.pRC = &UDP_GPU_States_RC;
	UDP_InitMessageObject(&UDP_GPU_States_MO);


	UDP_Diag_Calibration_MO.cycle = 0;
}
