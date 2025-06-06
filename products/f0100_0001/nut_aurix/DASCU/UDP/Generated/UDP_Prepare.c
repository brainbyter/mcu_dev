#include <Platform_Types.h>
#include <UDP_Typedefs.h>
#include <UDP_Extern_vars.h>
#include <UdpHandlers.h>
#include <Adas.h>
#include <I_PERC_DAS.h>
#include <DiagVars.h>
#include <FD_Vars.h>
#include <bsp_can.h>

void Prepare_UDP_Main_Start()
{
	UDP_Main_Start_RC++;
}

void Prepare_UDP_Climatic()
{
	UDP_Climatic_RC++;
}

void Prepare_UDP_BCM_LGT()
{
	UDP_BCM_LGT_RC++;
}

void Prepare_UDP_BCM_VehState()
{
	UDP_BCM_VehState_RC++;
}

void Prepare_UDP_ESC_Front_Speed()
{
	UDP_ESC_Front_Speed_RC++;
}

void Prepare_UDP_ESC_Rear_Speed()
{
	UDP_ESC_Rear_Speed_RC++;
}

void Prepare_UDP_ESC_Veh_Speed()
{
	UDP_ESC_Veh_Speed_RC++;
}

void Prepare_UDP_ESC_YR()
{
	UDP_ESC_YR_RC++;
}

void Prepare_UDP_ESC_AX()
{
	UDP_ESC_AX_RC++;
}

void Prepare_UDP_SAS()
{
	UDP_SAS_RC++;
}

void Prepare_UDP_MAS_Front_Sensor()
{
	UDP_MAS_Front_Sensor_RC++;
}

void Prepare_UDP_MAS_Rear_Sensor()
{
	UDP_MAS_Rear_Sensor_RC++;
}

void Prepare_UDP_MAS_Side_Sensor()
{
	UDP_MAS_Side_Sensor_RC++;
}

void Prepare_UDP_SCU()
{
	UDP_SCU_RC++;
}

void Prepare_UDP_IC_ABSOLUTE_CLOCK()
{
	UDP_IC_ABSOLUTE_CLOCK_RC++;
}

void Prepare_UDP_IC_HUD_01()
{
	UDP_IC_HUD_01_RC++;
}

void Prepare_UDP_Diag_Config()
{
	UDP_Diag_Config_RC++;
}

void Prepare_UDP_Diag_Calibration()
{
	UDP_Diag_Calibration_RC++;
}

void Prepare_UDP_FanSpeedControl()
{
	UDP_FanSpeedControl_RC++;
}

void Prepare_UDP_ERAG()
{
	UDP_ERAG_RC++;
}

void Prepare_UDP_TCU_R932_1()
{
	UDP_TCU_R932_1_RC++;
}
