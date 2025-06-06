#include "DiagMrr_typedefs.h"
#include "DiagMrr_ext_vars.h"
#include "DiagMrr_ext_functions.h"
#include "MRRX_DIAG_MessageObjects.h"
#include "CAN_Extern.h"
#include "CAN_Private.h"
#include "stdlib.h"


void Boot_SW_Ident_DID_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
}

void OEM_Part_Number_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
}

void VIN_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
}

void Software_Version_Number_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
}

void Repair_Shop_Code_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
}

void Programming_Data_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
}

void ECU_Installation_Date_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
}

void Radar_Alignment_Completion_Flag_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
	TD_MRR_AlignCompFlg = data[4];

	if (pos == MRR_REAR_LEFT)
	{
		TD_MRR_AlignCompFlg_RL = TD_MRR_AlignCompFlg;
		DiagMrrLResp_Handler(txData, 20);
		CAN_TransmitFrame(&DiagMrrLResp_MO, txData);
	}
	else
	{
		TD_MRR_AlignCompFlg_RR = TD_MRR_AlignCompFlg;
		DiagMrrRResp_Handler(txData, 20);
		CAN_TransmitFrame(&DiagMrrRResp_MO, txData);
	}
}

void Radar_Alignment_Results_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
}

void Radar_Supply_Voltage_12V_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
	TD_MRR_SuppVolt12 = (float)((((unsigned short)data[4])<<8) | data[5])*0.1;

	if (pos == MRR_REAR_LEFT)
	{
		TD_MRR_SuppVolt12_RL = TD_MRR_SuppVolt12;
		DiagMrrLResp_Handler(txData, 20);
		CAN_TransmitFrame(&DiagMrrLResp_MO, txData);
	}
	else
	{
		TD_MRR_SuppVolt12_RR = TD_MRR_SuppVolt12;
		DiagMrrRResp_Handler(txData, 20);
		CAN_TransmitFrame(&DiagMrrRResp_MO, txData);
	}
}

void MCU_Supply_Voltage_5V_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
	TD_MRR_SuppVolt5 = (float)((((unsigned short)data[4])<<8) | data[5])*0.01;

	if (pos == MRR_REAR_LEFT)
	{
		TD_MRR_SuppVolt5_RL = TD_MRR_SuppVolt5;
		DiagMrrLResp_Handler(txData, 20);
		CAN_TransmitFrame(&DiagMrrLResp_MO, txData);
	}
	else
	{
		TD_MRR_SuppVolt5_RR = TD_MRR_SuppVolt5;
		DiagMrrRResp_Handler(txData, 20);
		CAN_TransmitFrame(&DiagMrrRResp_MO, txData);
	}
}

void RF_Supply_Voltage_1_5V_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
	TD_MRR_SuppVolt1_5 = (float)((((unsigned short)data[4])<<8) | data[5])*0.01;

	if (pos == MRR_REAR_LEFT)
	{
		TD_MRR_SuppVolt1_5_RL = TD_MRR_SuppVolt1_5;
		DiagMrrLResp_Handler(txData, 20);
		CAN_TransmitFrame(&DiagMrrLResp_MO, txData);
	}
	else
	{
		TD_MRR_SuppVolt1_5_RR = TD_MRR_SuppVolt1_5;
		DiagMrrRResp_Handler(txData, 20);
		CAN_TransmitFrame(&DiagMrrRResp_MO, txData);
	}
}

void Radar_Temperature_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
	TD_MRR_Temp = (float)((signed char)data[4]);	// 49 degree

	if (pos == MRR_REAR_LEFT)
	{
		TD_MRR_Temp_RL = TD_MRR_Temp;
		DiagMrrLResp_Handler(txData, 20);
		CAN_TransmitFrame(&DiagMrrLResp_MO, txData);
	}
	else
	{
		TD_MRR_Temp_RR = TD_MRR_Temp;
		DiagMrrRResp_Handler(txData, 20);
		CAN_TransmitFrame(&DiagMrrRResp_MO, txData);
	}
}

void RadarManufactureData_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
}

void VehiPara_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
	unsigned int raw = 0x00;
	unsigned char temp[4];

	memcpy(temp, &data[0], 4);
	raw = mrr_reverse_bit32(*(unsigned int*)temp);
	memcpy(&TD_MRR_CarBase, &raw, 4);

	memcpy(temp, &data[4], 4);
	raw = mrr_reverse_bit32(*(unsigned int*)temp);
	memcpy(&TD_MRR_CarWidth, &raw, 4);

	if (pos == MRR_REAR_LEFT)
	{
		TD_MRR_CarBase_RL = TD_MRR_CarBase;
		TD_MRR_CarWidth_RL = TD_MRR_CarWidth;
		DiagMrrLResp_Handler(txData, 20);
		CAN_TransmitFrame(&DiagMrrLResp_MO, txData);
	}
	else
	{
		TD_MRR_CarBase_RR = TD_MRR_CarBase;
		TD_MRR_CarWidth_RR = TD_MRR_CarWidth;
		DiagMrrRResp_Handler(txData, 20);
		CAN_TransmitFrame(&DiagMrrRResp_MO, txData);
	}
}

void RadarInsParas_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
	unsigned int raw = 0x00;
	unsigned char temp[4];

	memcpy(temp, &data[0], 4);
	raw = mrr_reverse_bit32(*(unsigned int*)temp);
	memcpy(&TD_MRR_DistFrToRearAxle, &raw, 4);

	memcpy(temp, &data[4], 4);
	raw = mrr_reverse_bit32(*(unsigned int*)temp);
	memcpy(&TD_MRR_DistRrToRearAxle, &raw, 4);

	memcpy(temp, &data[8], 4);
	raw = mrr_reverse_bit32(*(unsigned int*)temp);
	memcpy(&TD_MRR_RelativeDistFR, &raw, 4);

	memcpy(temp, &data[12], 4);
	raw = mrr_reverse_bit32(*(unsigned int*)temp);
	memcpy(&TD_MRR_RelativeDistRR, &raw, 4);

	memcpy(temp, &data[16], 4);
	raw = mrr_reverse_bit32(*(unsigned int*)temp);
	memcpy(&TD_MRR_BetweenDistFR_RR, &raw, 4);

	memcpy(temp, &data[20], 4);
	raw = mrr_reverse_bit32(*(unsigned int*)temp);
	memcpy(&TD_MRR_HeightInstallRadar, &raw, 4);

	memcpy(temp, &data[24], 4);
	raw = mrr_reverse_bit32(*(unsigned int*)temp);
	memcpy(&TD_MRR_DistMirrorToRR, &raw, 4);

	if (pos == MRR_REAR_LEFT)
	{
		TD_MRR_DistFrToRearAxle_RL = TD_MRR_DistFrToRearAxle;
		TD_MRR_DistRrToRearAxle_RL  = TD_MRR_DistRrToRearAxle;
		TD_MRR_RelativeDistFR_RL  = TD_MRR_RelativeDistFR;
		TD_MRR_RelativeDistRR_RL  = TD_MRR_RelativeDistRR;
		TD_MRR_BetweenDistFR_RR_RL  = TD_MRR_BetweenDistFR_RR;
		TD_MRR_HeightInstallRadar_RL = TD_MRR_HeightInstallRadar;
		TD_MRR_DistMirrorToRR_RL = TD_MRR_DistMirrorToRR;

		DiagMrrLResp_Handler(txData, 20);
		CAN_TransmitFrame(&DiagMrrLResp_MO, txData);
	}
	else
	{
		TD_MRR_DistFrToRearAxle_RR = TD_MRR_DistFrToRearAxle;
		TD_MRR_DistRrToRearAxle_RR  = TD_MRR_DistRrToRearAxle;
		TD_MRR_RelativeDistFR_RR  = TD_MRR_RelativeDistFR;
		TD_MRR_RelativeDistRR_RR  = TD_MRR_RelativeDistRR;
		TD_MRR_BetweenDistFR_RR_RR  = TD_MRR_BetweenDistFR_RR;
		TD_MRR_HeightInstallRadar_RR = TD_MRR_HeightInstallRadar;
		TD_MRR_DistMirrorToRR_RR = TD_MRR_DistMirrorToRR;

		DiagMrrRResp_Handler(txData, 20);
		CAN_TransmitFrame(&DiagMrrRResp_MO, txData);
	}
}

void DONTKNOW_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
}

void TRIANGLE_REFL_INFO_Handler(unsigned char *data, radar_pos_t pos)
{
	uint8 txData[64];
}
