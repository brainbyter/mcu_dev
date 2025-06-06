#include "DiagMrr_typedefs.h"
#include "DiagMrr_ext_vars.h"
#include "DiagMrr_ext_functions.h"
#include "MRRX_DIAG_MessageObjects.h"
#include "CAN_Extern.h"
#include "CAN_Private.h"
#include "stdlib.h"


state_calib_t state_mrrx;

void nullVisualDiagVariables();

void manageRequest()
{
	if (REQ_MRR_DID_Volt12_RL)
	{
		REQ_MRR_DID_Volt12_RL = 0;
        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = 0x0305;
        g_radar_pos = MRR_REAR_LEFT;
		prepareServReadData(uds_data, 0x0305);
		CAN_TransmitFrame(&China_UDS_RL_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_Volt5_RL)
	{
		REQ_MRR_DID_Volt5_RL = 0;
        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = 0x0315;
        g_radar_pos = MRR_REAR_LEFT;
		prepareServReadData(uds_data, 0x0315);
		CAN_TransmitFrame(&China_UDS_RL_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_Volt1_5_RL)
	{
		REQ_MRR_DID_Volt1_5_RL = 0;
        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid= 1;
        uds_state_request_mrr.frame_status.DID = 0x0325;
        g_radar_pos = MRR_REAR_LEFT;
		prepareServReadData(uds_data, 0x0325);
		CAN_TransmitFrame(&China_UDS_RL_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_Temp_RL)
	{
		REQ_MRR_DID_Temp_RL = 0;
        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = 0x0306;
        g_radar_pos = MRR_REAR_LEFT;
		prepareServReadData(uds_data, 0x0306);
		CAN_TransmitFrame(&China_UDS_RL_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_VehParams_RL)
	{
		REQ_MRR_DID_VehParams_RL = 0;

        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = 0xF1F8;
        g_radar_pos = MRR_REAR_LEFT;
        uds_state_request_mrr.frame_type = SINGLE_FRAME;
		prepareServReadData(uds_data, 0xF1F8);
		CAN_TransmitFrame(&China_UDS_RL_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_RadarInsParams_RL)
	{
		REQ_MRR_DID_RadarInsParams_RL = 0;

        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = MRR_RadarInsParas;	// F1F9
        g_radar_pos = MRR_REAR_LEFT;
		prepareServReadData(uds_data, MRR_RadarInsParas);
		CAN_TransmitFrame(&China_UDS_RL_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_AlignCompFlg_RL)
	{
		REQ_MRR_DID_AlignCompFlg_RL = 0;

        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = 0x0302;
        g_radar_pos = MRR_REAR_LEFT;
		prepareServReadData(uds_data, 0x0302);
		CAN_TransmitFrame(&China_UDS_RL_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_Alignresult_RL)
	{
		REQ_MRR_DID_Alignresult_RL = 0;

        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = 0x0303;
        g_radar_pos = MRR_REAR_LEFT;
		prepareServReadData(uds_data, 0x0303);
		CAN_TransmitFrame(&China_UDS_RL_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_VehParams_WR_RL)
	{
		REQ_MRR_DID_VehParams_WR_RL = 0;
		/*uds_state_request_mrr.frame_status.SID = WriteDataByIdentifierService_0x2E;
		uds_state_request_mrr.frame_status.useDid = 1;
		uds_state_request_mrr.frame_status.DID = 0x0303;
		g_radar_pos = MRR_REAR_LEFT;
		prepareServWriteData(uds_data, 0x0303);
		CAN_TransmitFrame(&China_UDS_RL_Phy_Req_MO, uds_data);
		*/
	}



	if (REQ_MRR_DID_Volt12_RR)
	{
		REQ_MRR_DID_Volt12_RR = 0;
        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = 0x0305;
        g_radar_pos = MRR_REAR_RIGHT;
		prepareServReadData(uds_data, 0x0305);
		CAN_TransmitFrame(&China_UDS_RR_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_Volt5_RR)
	{
		REQ_MRR_DID_Volt5_RR = 0;
        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = 0x0315;
        g_radar_pos = MRR_REAR_RIGHT;
		prepareServReadData(uds_data, 0x0315);
		CAN_TransmitFrame(&China_UDS_RR_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_Volt1_5_RR)
	{
		REQ_MRR_DID_Volt1_5_RR = 0;
        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = 0x0325;
        g_radar_pos = MRR_REAR_RIGHT;
		prepareServReadData(uds_data, 0x0325);
		CAN_TransmitFrame(&China_UDS_RR_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_Temp_RR)
	{
		REQ_MRR_DID_Temp_RR = 0;
        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = 0x0306;
        g_radar_pos = MRR_REAR_RIGHT;
		prepareServReadData(uds_data, 0x0306);
		CAN_TransmitFrame(&China_UDS_RR_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_VehParams_RR)
	{
		REQ_MRR_DID_VehParams_RR = 0;

        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = 0xF1F8;
        g_radar_pos = MRR_REAR_RIGHT;
        uds_state_request_mrr.frame_type = SINGLE_FRAME;
		prepareServReadData(uds_data, 0xF1F8);
		CAN_TransmitFrame(&China_UDS_RR_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_RadarInsParams_RR)
	{
		REQ_MRR_DID_RadarInsParams_RR = 0;

        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = MRR_RadarInsParas;	// F1F9
        g_radar_pos = MRR_REAR_RIGHT;
		prepareServReadData(uds_data, MRR_RadarInsParas);
		CAN_TransmitFrame(&China_UDS_RR_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_AlignCompFlg_RR)
	{
		REQ_MRR_DID_AlignCompFlg_RR = 0;

        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = 0x0302;
        g_radar_pos = MRR_REAR_RIGHT;
		prepareServReadData(uds_data, 0x0302);
		CAN_TransmitFrame(&China_UDS_RR_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}

	if (REQ_MRR_DID_Alignresult_RR)
	{
		REQ_MRR_DID_Alignresult_RR = 0;
        uds_state_request_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
        uds_state_request_mrr.frame_status.useDid = 1;
        uds_state_request_mrr.frame_status.DID = 0x0303;
        g_radar_pos = MRR_REAR_RIGHT;
		prepareServReadData(uds_data, 0x0303);
		CAN_TransmitFrame(&China_UDS_RR_Phy_Req_MO, uds_data);
		nullVisualDiagVariables();
		return;
	}
}

void nullVisualDiagVariables()
{
	if (g_radar_pos == MRR_REAR_LEFT)
	{
		TD_MRR_Temp_RL = 0;
		TD_MRR_SuppVolt5_RL = 0;
		TD_MRR_SuppVolt1_5_RL = 0;
		TD_MRR_SuppVolt12_RL = 0;
		TD_MRR_DistFrToRearAxle_RL = 0;
		TD_MRR_DistRrToRearAxle_RL  = 0;
		TD_MRR_RelativeDistFR_RL = 0;
		TD_MRR_RelativeDistRR_RL = 0;
		TD_MRR_BetweenDistFR_RR_RL = 0;
		TD_MRR_HeightInstallRadar_RL  = 0;
		TD_MRR_DistMirrorToRR_RL = 0;
		TD_MRR_CarBase_RL = 0;
		TD_MRR_CarWidth_RL = 0;
	}

	if (g_radar_pos == MRR_REAR_RIGHT)
	{
		TD_MRR_Temp_RR = 0;
		TD_MRR_SuppVolt5_RR = 0;
		TD_MRR_SuppVolt1_5_RR = 0;
		TD_MRR_SuppVolt12_RR = 0;
		TD_MRR_DistFrToRearAxle_RR = 0;
		TD_MRR_DistRrToRearAxle_RR  = 0;
		TD_MRR_RelativeDistFR_RR = 0;
		TD_MRR_RelativeDistRR_RR = 0;
		TD_MRR_BetweenDistFR_RR_RR = 0;
		TD_MRR_HeightInstallRadar_RR  = 0;
		TD_MRR_DistMirrorToRR_RR = 0;
		TD_MRR_CarBase_RR = 0;
		TD_MRR_CarWidth_RR = 0;
	}
}

void manageStateMrrx()
{
	/*
	CanMessageObject_t *ptr_UDS_Req_MO;
	uint8 testResultMsg[64];
	memset(testResultMsg, 0x00, 64);

	if (radar_pos == MRR_REAR_LEFT)
	{
		ptr_UDS_Req_MO = &China_UDS_RL_Phy_Req_MO;
	}

	if (radar_pos == MRR_REAR_RIGHT)
	{
		ptr_UDS_Req_MO = &China_UDS_RR_Phy_Req_MO;
	}

	uint8 txData[8];
	memset(txData, (uint8)0x00, 8);

	uint8 *ptrData;
	*/
}
