#include "DiagMrr_typedefs.h"
#include "MRRX_DIAG_MessageObjects.h"
#include "CAN_Extern.h"
#include "CAN_Private.h"
#include "stdlib.h"
#include "DiagMrr_ext_vars.h"
#include "DiagMrr_ext_functions.h"

#define COUNT_DELAYS_2_S 8
#define COUNT_DELAYS_1_S 1

radar_pos_t g_radar_pos;

float TD_MRR_VerticalAlignAngle;
unsigned char TD_MRR_AlignCompFlg;
float TD_MRR_Temp;
float TD_MRR_SuppVolt5;
float TD_MRR_SuppVolt1_5;
float TD_MRR_SuppVolt12;
unsigned char TD_MRR_ResCalibration;
float TD_MRR_RelativeDistRR;
float TD_MRR_RelativeDistFR;
float TD_MRR_HorizontalAlignAngle;
float TD_MRR_HeightInstallRadar;
float TD_MRR_DistRrToRearAxle;
float TD_MRR_DistMirrorToRR;
float TD_MRR_DistFrToRearAxle;
float TD_MRR_CarWidth;
float TD_MRR_CarBase;
float TD_MRR_BetweenDistFR_RR;

state_calib_t state_calib = {.step_calib = CALIB_IDLE_STATE, .last_step_calib = resetedValueServ};

dids_t didss_list[18] = {
        {.did = 0xF180, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=TRUE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .data_did_handler=Boot_SW_Ident_DID_Handler},
        {.did = 0xF187, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .data_did_handler=OEM_Part_Number_Handler},
        {.did = 0xF190, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=TRUE, .data_did_handler=VIN_Handler},
        {.did = 0xF195, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .data_did_handler=Software_Version_Number_Handler},
        {.did = 0xF198, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=TRUE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = TRUE, .supp_sess.flags.writeExtendedSession=TRUE, .data_did_handler=Repair_Shop_Code_Handler},
        {.did = 0xF199, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=TRUE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = TRUE, .supp_sess.flags.writeExtendedSession=TRUE, .data_did_handler=Programming_Data_Handler},
        {.did = 0xF19D, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=TRUE, .data_did_handler=ECU_Installation_Date_Handler},
        {.did = 0x0302, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .data_did_handler=Radar_Alignment_Completion_Flag_Handler},
        {.did = 0x0303, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .data_did_handler=Radar_Alignment_Results_Handler},
        {.did = 0x0305, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .data_did_handler=Radar_Supply_Voltage_12V_Handler},
        {.did = 0x0315, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .data_did_handler=MCU_Supply_Voltage_5V_Handler},
        {.did = 0x0325, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .data_did_handler=RF_Supply_Voltage_1_5V_Handler},
        {.did = 0x0306, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .data_did_handler=Radar_Temperature_Handler},
        {.did = 0x0309, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=TRUE, .data_did_handler=RadarManufactureData_Handler},
        {.did = 0xF1F8, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=TRUE, .data_did_handler=VehiPara_Handler},
        {.did = 0xF1F9, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=TRUE, .data_did_handler=RadarInsParas_Handler},
        {.did = 0x0300, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=TRUE, .data_did_handler=DONTKNOW_Handler},
        {.did = 0x0301, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=TRUE, .data_did_handler=TRIANGLE_REFL_INFO_Handler}
};

uint8 countDelays2s = 0;
uint8 countDelays1s = 0;

uint8_t calibCondition;
uint8_t calibResultFlag;
uint8_t calibAngleShift;
uint8_t calibVAngleShift;

uint8_t radarAlignComplFlag;
uint8_t horizontalAligmentAngle;
uint8_t verticalAligmentAngle;
uint8_t alignmentResult;

uds_state_t uds_state_client_mrr;
uds_state_t uds_state_request_mrr;
diag_process_status_t diag_process_status = {.diag_state_rl = isDisable, .diag_state_rr = isDisable};

void manageStateCalibr()
{
	if (!REQ_MRR_StartCalibration_RL && !REQ_MRR_StartCalibration_RR)
	{

		if (diag_process_status.diag_state_rl==isFinished)
		{
			diag_process_status.diag_state_rl = isDisable;

			if (diag_process_status.diag_state_rr==isQueue)
			{
				diag_process_status.diag_state_rr = isEnable;
			}
		}

		if (diag_process_status.diag_state_rr==isFinished)
		{
			diag_process_status.diag_state_rr = isDisable;

			if (diag_process_status.diag_state_rl==isQueue)
			{
				diag_process_status.diag_state_rl = isEnable;
			}
		}
	}


	if (REQ_MRR_StartCalibration_RL)
	{
		REQ_MRR_StartCalibration_RL = 0;

		if (diag_process_status.diag_state_rr == isDisable)
		{
			diag_process_status.diag_state_rl = isEnable;
		}
		else if (diag_process_status.diag_state_rr == isEnable)
		{
			diag_process_status.diag_state_rl = isQueue;
		}
	}

	if (REQ_MRR_StartCalibration_RR)
	{
		REQ_MRR_StartCalibration_RR = 0;

		if (diag_process_status.diag_state_rl == isDisable)
		{
			diag_process_status.diag_state_rr = isEnable;
		}
		else if (diag_process_status.diag_state_rl == isEnable)
		{
			diag_process_status.diag_state_rr = isQueue;
		}
	}
}

void CalibrationRadar(radar_pos_t radar_pos, diag_state_t *diag_state)
{
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

    uint8 txData[8];	// /??
    memset(txData, (uint8)0x00, 8);

    static uint32 timeDelay = 0;
    static uint8 countDelays2s = 0;
    static uint8 countDelays1s = 0;

    uint8 *ptrData;

    switch (state_calib.step_calib)
    {
    	case CALIB_IDLE_STATE:
            state_calib.step_calib = CALIB_SW_2_CAL_WAVE_ST;
    		break;

    	case CALIB_WAITING_RESP:
            if (uds_state_client_mrr.frame_status.FC_reqEn == 1)
    		{
    			state_calib.step_calib = state_calib.last_step_calib;
    		}
            else if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40)	// 0x50==0x50?
  			{
  				state_calib.step_calib = state_calib.last_step_calib;
    			state_calib.last_step_calib = CALIB_IDLE_STATE;
    			state_calib.countTryRequest = 0;
    			state_calib.lastTimeIncMessage = 0;
  			}
  			else
  			{
                if (((SystemTime - state_calib.lastTimeIncMessage) >= 1000))
  				{
  					if (++state_calib.countTryRequest < 5)
  					{
                        uds_state_client_mrr.frame_type = SINGLE_FRAME;
  						state_calib.step_calib = state_calib.last_step_calib;
  						state_calib.lastTimeIncMessage = SystemTime;
  					}
  					else
  					{
  						udsExitCalibration();
  						*diag_state = isFinished;
  						return;
  					}
  				}
  			}
			
  			break;

    	case CALIB_SW_2_CAL_WAVE_ST:
        	DAS_SwitchCalibWave_Handler(txData, 8);
            CAN_TransmitFrame(&DAS_SwitchCalibWave_MO, txData);
            state_calib.step_calib = CALIB_EXT_SESS_ST;
    		break;
/* UDS */
    	case CALIB_EXT_SESS_ST:
            if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40)
    		{
    			udsPosResponceCibration(CALIB_COMM_CONTROL);
    		}
    		else
    		{
                uds_state_client_mrr.frame_type = SINGLE_FRAME;
    			prepareServChangeSession(uds_data, 0x03);
    			memcpy(txData, uds_data, 8);
    			CAN_TransmitFrame(ptr_UDS_Req_MO, txData);

    			uds_state_client_mrr.lastMessageTime = SystemTime;
                uds_state_client_mrr.frame_status.SID = DiagnosticSessionControlService_0x10;
    			state_calib.step_calib = CALIB_WAITING_RESP;
    			state_calib.last_step_calib = CALIB_EXT_SESS_ST;
    			state_calib.lastTimeIncMessage = SystemTime;
    		}
    		break;

    	case CALIB_COMM_CONTROL:
            if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40)
    		{
    			udsPosResponceCibration(CALIB_WR_VEH_INFO_ST);
    		}
    		else
    		{
                uds_state_client_mrr.frame_type = SINGLE_FRAME;
    			prepareServCommControl(uds_data, 0x03, 0x03, 0x03);
    			memcpy(txData, uds_data, 8);
    			CAN_TransmitFrame(ptr_UDS_Req_MO, txData);

    			uds_state_client_mrr.lastMessageTime = SystemTime;
                uds_state_client_mrr.frame_status.SID = CommunicationalControl_0x28;
    			state_calib.step_calib = CALIB_WAITING_RESP;
    			state_calib.lastTimeIncMessage = SystemTime;
    			state_calib.last_step_calib = CALIB_COMM_CONTROL;
    		}
    		break;

    	case CALIB_WR_VEH_INFO_ST:
            if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40) // 0 != sid+40
    		{
    			udsPosResponceCibration(CALIB_WR_RADAR_INST_INFO);
    		}
    		else
    		{
                if (uds_state_client_mrr.frame_type == SINGLE_FRAME)
    			{
                    prepareUdsData(prepareServWriteData(txData, uds_data, 0xb, MRR_VehiPara, FIRST_FRAME));

    				memcpy(txData, uds_data, 8);
    				CAN_TransmitFrame(ptr_UDS_Req_MO, txData);

                    uds_state_client_mrr.frame_type = FIRST_FRAME;
    				uds_state_client_mrr.p_next_data = (uds_data+8);
    				uds_state_client_mrr.lastMessageTime = SystemTime;
    				uds_state_client_mrr.targetLen = 11;
    				uds_state_client_mrr.reminderLen = uds_state_client_mrr.targetLen-6;
    				uds_state_client_mrr.frameNumber = 0;
                    uds_state_client_mrr.frame_status.SID = WriteDataByIdentifierService_0x2E;

    				state_calib.step_calib = CALIB_WAITING_RESP;
    				state_calib.lastTimeIncMessage = SystemTime;
    				state_calib.last_step_calib = CALIB_WR_VEH_INFO_ST;
    			}
                else if (uds_state_client_mrr.frame_type == FIRST_FRAME)
    			{
                    uds_state_client_mrr.frame_type = CONSECUTIVE_FRAME;
    			}

                if (uds_state_client_mrr.frame_type == CONSECUTIVE_FRAME)
    			{
                    if ((SystemTime - uds_state_client_mrr.lastMessageTime) >= (uds_state_client_mrr.frame_status.FC_ST+10))
    				{
                        ptrData = prepareServWriteData(txData, uds_state_client_mrr.p_next_data, (unsigned int)uds_state_client_mrr.reminderLen, MRR_VehiPara, CONSECUTIVE_FRAME);

    					CAN_TransmitFrame(ptr_UDS_Req_MO, txData);
    					uds_state_client_mrr.p_next_data = ptrData;
    					uds_state_client_mrr.reminderLen -= 7;

    					if ( (uds_state_client_mrr.reminderLen) <= 0)
    					{
                            uds_state_client_mrr.frame_status.PRC = 0x00;
                            uds_state_client_mrr.frame_status.NRC = 0x00;
                            uds_state_client_mrr.frame_status.FC_reqEn = 0;

    						uds_state_client_mrr.frameNumber = 0;
                            uds_state_client_mrr.frame_type = SINGLE_FRAME;
    						uds_state_client_mrr.p_next_data = 0;
							uds_state_client_mrr.reminderLen = 0;
							uds_state_client_mrr.targetLen = 0;

							state_calib.countTryRequest = 0;
							state_calib.step_calib = CALIB_WAITING_RESP;
			    			state_calib.last_step_calib = CALIB_WR_VEH_INFO_ST;
    					}

    					uds_state_client_mrr.lastMessageTime = SystemTime;
    					state_calib.lastTimeIncMessage = SystemTime;
    				}
    			}
    		}
    		break;

    	case CALIB_WR_RADAR_INST_INFO:
            if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40)
    		{
    			udsPosResponceCibration(CALIB_WR_DONT_KNOW_INFO);
    		}
    		else
    		{
                if (uds_state_client_mrr.frame_type == SINGLE_FRAME)
    			{
                    prepareUdsData(prepareServWriteData(txData, uds_data, 31, MRR_RadarInsParas, FIRST_FRAME));

    				memcpy(txData, uds_data, 8);
    				CAN_TransmitFrame(ptr_UDS_Req_MO, txData);

                    uds_state_client_mrr.frame_type = FIRST_FRAME;
    				uds_state_client_mrr.p_next_data = (uds_data+8);
    				uds_state_client_mrr.lastMessageTime = SystemTime;
    				uds_state_client_mrr.targetLen = 31;
    				uds_state_client_mrr.reminderLen = uds_state_client_mrr.targetLen-6;
    				uds_state_client_mrr.frameNumber = 0;
                    uds_state_client_mrr.frame_status.SID = WriteDataByIdentifierService_0x2E;

					state_calib.step_calib = CALIB_WAITING_RESP;
					state_calib.lastTimeIncMessage = SystemTime;
					state_calib.last_step_calib = CALIB_WR_RADAR_INST_INFO;
				}
                else if (uds_state_client_mrr.frame_type == FIRST_FRAME)
    			{
                    uds_state_client_mrr.frame_type = CONSECUTIVE_FRAME;
    			}

                if (uds_state_client_mrr.frame_type == CONSECUTIVE_FRAME)
				{
                    if ((SystemTime - uds_state_client_mrr.lastMessageTime) >= (uds_state_client_mrr.frame_status.FC_ST+10))
					{
                        ptrData = prepareServWriteData(txData, uds_state_client_mrr.p_next_data, (unsigned int)uds_state_client_mrr.reminderLen, MRR_RadarInsParas, CONSECUTIVE_FRAME);

						CAN_TransmitFrame(ptr_UDS_Req_MO, txData);
						uds_state_client_mrr.p_next_data = ptrData;
						uds_state_client_mrr.reminderLen -= 7;

						if ( (uds_state_client_mrr.reminderLen) <= 0)
						{
                            uds_state_client_mrr.frame_status.PRC = 0x00;
                            uds_state_client_mrr.frame_status.NRC = 0xFF;
                            uds_state_client_mrr.frame_status.FC_reqEn = 0;

							uds_state_client_mrr.frameNumber = 0;
                            uds_state_client_mrr.frame_type = SINGLE_FRAME;

							uds_state_client_mrr.p_next_data = 0;
							uds_state_client_mrr.reminderLen = 0;
							uds_state_client_mrr.targetLen = 0;

							state_calib.countTryRequest = 0;
							state_calib.step_calib = CALIB_WAITING_RESP;
							state_calib.last_step_calib = CALIB_WR_RADAR_INST_INFO;
						}

						state_calib.lastTimeIncMessage = SystemTime;
						uds_state_client_mrr.lastMessageTime = SystemTime;
					}
				}
    		}

    		break;

    	case CALIB_WR_DONT_KNOW_INFO:
            if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40)
    		{
    		    udsPosResponceCibration(CALIB_WR_TRIANGLE_REFL_INFO);
    		}
    		else
    		{
                uds_state_client_mrr.frame_type = SINGLE_FRAME;
                prepareUdsData(prepareServWriteData(txData, uds_data, 7, MRR_DONTKNOW, SINGLE_FRAME));
    			memcpy(txData, uds_data, 8);
    			CAN_TransmitFrame(ptr_UDS_Req_MO, txData);

    			state_calib.step_calib = CALIB_WAITING_RESP;
    			state_calib.lastTimeIncMessage = SystemTime;
    			state_calib.last_step_calib = CALIB_WR_DONT_KNOW_INFO;
    			uds_state_client_mrr.lastMessageTime = SystemTime;
                uds_state_client_mrr.frame_status.SID = WriteDataByIdentifierService_0x2E;
    		}

    		break;

    	case CALIB_WR_TRIANGLE_REFL_INFO:
            if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40)
    		{
    		    udsPosResponceCibration(CALIB_SHTDW_DTC);
    		}
    		else
    		{
                uds_state_client_mrr.frame_type = SINGLE_FRAME;
                prepareUdsData(prepareServWriteData(txData, uds_data, 7, MRR_TRIANGLE_REFL_INFO, SINGLE_FRAME));
    			memcpy(txData, uds_data, 8);
    			CAN_TransmitFrame(ptr_UDS_Req_MO, txData);
    			uds_state_client_mrr.lastMessageTime = SystemTime;
                uds_state_client_mrr.frame_status.SID = WriteDataByIdentifierService_0x2E;
    			state_calib.step_calib = CALIB_WAITING_RESP;
    			state_calib.lastTimeIncMessage = SystemTime;
    			state_calib.last_step_calib = CALIB_WR_TRIANGLE_REFL_INFO;
    		}

    		break;

    	case CALIB_SHTDW_DTC:
            if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40)
    		{
    		    udsPosResponceCibration(CALIB_STOP_PERIOD_COMM);
    		}
    		else
    		{
                uds_state_client_mrr.frame_type = SINGLE_FRAME;
    		    ptrData = uds_data;
    		    prepareServClearDTC(uds_data, 0x02, 0x02);
    		    memcpy(txData, uds_data, 8);
    		    CAN_TransmitFrame(ptr_UDS_Req_MO, txData);

    		    uds_state_client_mrr.lastMessageTime = SystemTime;
    		    state_calib.step_calib = CALIB_WAITING_RESP;
    		    state_calib.lastTimeIncMessage = SystemTime;
    		    state_calib.last_step_calib = CALIB_SHTDW_DTC;
                uds_state_client_mrr.frame_status.SID = ControlDTCSettings_0x85;
    		}

    		break;

    	case CALIB_STOP_PERIOD_COMM:
            if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40)
    		{
    		    udsPosResponceCibration(CALIB_START);
    		}
    		else
    		{
                uds_state_client_mrr.frame_type = SINGLE_FRAME;
    		    prepareServCommControl(uds_data, 0x03, 0x03, 0x03);
    		    memcpy(txData, uds_data, 8);
    		    CAN_TransmitFrame(ptr_UDS_Req_MO, txData);

    		    uds_state_client_mrr.lastMessageTime = SystemTime;
    		    state_calib.step_calib = CALIB_WAITING_RESP;
    		    state_calib.lastTimeIncMessage = SystemTime;
    		    state_calib.last_step_calib = CALIB_STOP_PERIOD_COMM;
                uds_state_client_mrr.frame_status.SID = CommunicationalControl_0x28;
    		}

    		break;


    	case CALIB_START:
            if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40)
    		{
    		    udsPosResponceCibration(CALIB_CHECK_CALIB_ST);
    		}
    		else
    		{
                uds_state_client_mrr.frame_type = SINGLE_FRAME;
    		    prepareServRoutineControl(uds_data, 0x04, 0x01, 0x0200);
    		    memcpy(txData, uds_data, 8);
    		    CAN_TransmitFrame(ptr_UDS_Req_MO, txData);

    		    uds_state_client_mrr.lastMessageTime = SystemTime;
    		    state_calib.step_calib = CALIB_WAITING_RESP;
    		    state_calib.lastTimeIncMessage = SystemTime;
    		    state_calib.last_step_calib = CALIB_START;
                uds_state_client_mrr.frame_status.SID = RoutineControlService_0x31;
    		}

            break;


    	case CALIB_CHECK_CALIB_ST:
            if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40)	// 071 = 071
    		{
                if (uds_state_client_mrr.frame_type == FIRST_FRAME)
    			{
                    prepareDiagFlowControlFrame(uds_data, uds_state_client_mrr.frame_status.FC_FLAG, uds_state_client_mrr.frame_status.FC_BS, uds_state_client_mrr.frame_status.FC_ST);
    				memcpy(txData, uds_data, 8);
    				CAN_TransmitFrame(ptr_UDS_Req_MO, txData);

                    uds_state_client_mrr.frame_type = CONSECUTIVE_FRAME;
    				uds_state_client_mrr.lastMessageTime = SystemTime;
                    uds_state_client_mrr.frame_status.SID = RoutineControlService_0x31;
    				state_calib.last_step_calib = CALIB_CHECK_CALIB_ST;
        		    state_calib.step_calib = CALIB_CHECK_CALIB_ST;
        		    state_calib.lastTimeIncMessage = SystemTime;
    			}
                else if (uds_state_client_mrr.frame_type == CONSECUTIVE_FRAME)
    			{
    				if (uds_state_client_mrr.reminderLen <= 0)
    				{
    					state_calib.step_calib = CALIB_DELAY_2S;
                        uds_state_client_mrr.frame_status.SID = 0x00;
                        uds_state_client_mrr.frame_status.PRC = 0x00;
                        uds_state_client_mrr.frame_status.NRC = 0x00;
    					timeDelay = SystemTime;
                        uds_state_client_mrr.frame_type = SINGLE_FRAME;
    				}

                    if (((SystemTime - state_calib.lastTimeIncMessage) >= 5000))
    			    {
    					udsExitCalibration();
    					*diag_state = isFinished;
    					return;
    			    }
    			}
    		}
    		else
    		{
                uds_state_client_mrr.frame_type = SINGLE_FRAME;
    		    prepareServRoutineControl(uds_data, 0x04, 0x03, 0x0200);
    		    memcpy(txData, uds_data, 8);
    		    CAN_TransmitFrame(ptr_UDS_Req_MO, txData);

    		    uds_state_client_mrr.lastMessageTime = SystemTime;
    		    state_calib.step_calib = CALIB_WAITING_RESP;
    		    state_calib.lastTimeIncMessage = SystemTime;
    		    state_calib.last_step_calib = CALIB_CHECK_CALIB_ST;
                uds_state_client_mrr.frame_status.SID = RoutineControlService_0x31;

    		}
    		break;

    	case CALIB_DELAY_2S:
    		if ((SystemTime - timeDelay) >= 2000)
    		{
    			state_calib.step_calib = CALIB_CHECK_CALIB_ST;
                uds_state_client_mrr.frame_type = SINGLE_FRAME;
    		    countDelays2s++;
    		}

    		if (countDelays2s == COUNT_DELAYS_2_S)
    		{
    			state_calib.step_calib = CALIB_END_CALIB;
    			countDelays2s = 0;
    		}

    		break;

    	case CALIB_END_CALIB:
            if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40)
    		{
    			udsPosResponceCibration(CALIB_DELAY_1S);
    			timeDelay = SystemTime;
    		}
    		else
    		{
                uds_state_client_mrr.frame_type = SINGLE_FRAME;
    		    prepareServRoutineControl(uds_data, 0x04, 0x02, 0x0200);
    		    memcpy(txData, uds_data, 8);
    		    CAN_TransmitFrame(ptr_UDS_Req_MO, txData);
    		    uds_state_client_mrr.lastMessageTime = SystemTime;
    		    state_calib.step_calib = CALIB_WAITING_RESP;
    		    state_calib.lastTimeIncMessage = SystemTime;
    		    state_calib.last_step_calib = CALIB_END_CALIB;
                uds_state_client_mrr.frame_status.SID = RoutineControlService_0x31;
    		}

    		break;


    	case CALIB_DELAY_1S:
    		if ((SystemTime - timeDelay) >= 1000)
    		{
    			countDelays1s++;

    			if (countDelays1s == 1)
    			{
    				state_calib.step_calib = CALIB_RST_RADAR;
    			}

    			if (countDelays1s == 2)
    		    {
    				countDelays1s = 0;
    				state_calib.step_calib = CALIB_RD_CALIB_RES_FLG;
    		    }
    		}
    		break;

    	case CALIB_RST_RADAR:
            if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40)
    		{
    		    udsPosResponceCibration(CALIB_DELAY_1S);
    		    timeDelay = SystemTime;
    		}
    		else
    		{
                uds_state_client_mrr.frame_type = SINGLE_FRAME;
    			prepareServECUReset(uds_data, 0x02, 0x01);
    			memcpy(txData, uds_data, 8);
    		    CAN_TransmitFrame(ptr_UDS_Req_MO, txData);
    		    uds_state_client_mrr.lastMessageTime = SystemTime;
    		    state_calib.step_calib = CALIB_WAITING_RESP;
    		    state_calib.lastTimeIncMessage = SystemTime;
    		    state_calib.last_step_calib = CALIB_RST_RADAR;
                uds_state_client_mrr.frame_status.SID = ECUResetService_0x11;
    		}
            break;

    	case CALIB_RD_CALIB_RES_FLG:
            if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40)
    		{
    		    udsPosResponceCibration(CALIB_RD_CALIB_RES);

    		    /* GET DATA */
    			if (radar_pos == MRR_REAR_LEFT)
    			{
    				TD_MRR_AlignCompFlg_RL = uds_data[4];
    			}

    			if (radar_pos == MRR_REAR_RIGHT)
    			{
        		    TD_MRR_AlignCompFlg_RR = uds_data[4];
    			}
    		}
    		else
    		{
                uds_state_client_mrr.frame_type = SINGLE_FRAME;
    		    prepareServReadData(uds_data, 0x0302);	// Read Calibrating Result Flag (0x0302)
    		    memcpy(txData, uds_data, 8);
    		    CAN_TransmitFrame(ptr_UDS_Req_MO, txData);

    		    uds_state_client_mrr.lastMessageTime = SystemTime;
    		    state_calib.lastTimeIncMessage = SystemTime;
    		    state_calib.step_calib = CALIB_WAITING_RESP;
    		    state_calib.last_step_calib = CALIB_RD_CALIB_RES_FLG;
                uds_state_client_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
    		}
    		break;

    	case CALIB_RD_CALIB_RES:
            if (uds_state_client_mrr.frame_status.PRC == uds_state_client_mrr.frame_status.SID+0x40)
    		{
                if (uds_state_client_mrr.frame_status.useDid == 1)
    			{
                    //uds_state_client_mrr.frame_status.useDid = 0;

                    if (uds_state_client_mrr.frame_type == FIRST_FRAME)
    				{
                        prepareDiagFlowControlFrame(txData, uds_state_client_mrr.frame_status.FC_FLAG, uds_state_client_mrr.frame_status.FC_BS, uds_state_client_mrr.frame_status.FC_ST);
    					CAN_TransmitFrame(ptr_UDS_Req_MO, txData);

    					uds_state_client_mrr.reminderLen = uds_state_client_mrr.targetLen - 6;
                        uds_state_client_mrr.frame_type = CONSECUTIVE_FRAME;
        				uds_state_client_mrr.lastMessageTime = SystemTime;
            		    state_calib.lastTimeIncMessage = SystemTime;
    				}
                    else if (uds_state_client_mrr.frame_type == CONSECUTIVE_FRAME)
    				{
    					uds_state_client_mrr.reminderLen -= 7;
    				}

    				if (uds_state_client_mrr.reminderLen <= 0)
    				{
    	    			if (radar_pos == MRR_REAR_LEFT)
    	    			{
    	    				TD_MRR_HorizontalAlignAngle_RL = (float)((signed short)((unsigned short)uds_data[6]<<8 | uds_data[5]))*0.01;
    	    				TD_MRR_VerticalAlignAngle_RL =   (float)((signed short)((unsigned short)uds_data[8]<<8 | uds_data[7]))*0.01;
    	    				TD_MRR_ResCalibration_RL = uds_data[9];

    	    				DiagMrrLResp_Handler(testResultMsg, 64);
    	    				CAN_TransmitFrame(&DiagMrrLResp_MO, testResultMsg);
    	    			}

    	    			if (radar_pos == MRR_REAR_RIGHT)
    	    			{
    	    				TD_MRR_HorizontalAlignAngle_RR = (float)((signed short)((unsigned short)uds_data[6]<<8 | uds_data[5]))*0.01;
    	    				TD_MRR_VerticalAlignAngle_RR =   (float)((signed short)((unsigned short)uds_data[8]<<8 | uds_data[7]))*0.01;
    	    				TD_MRR_ResCalibration_RR = uds_data[9];

    	    				DiagMrrRResp_Handler(testResultMsg, 64);
    	    				CAN_TransmitFrame(&DiagMrrRResp_MO, testResultMsg);
    	    			}

    					udsExitCalibration();
    				  	*diag_state = isFinished;
    				}
    			}
    			else
    			{
                    if (((SystemTime - state_calib.lastTimeIncMessage) >= 5000))
    				{
    					udsExitCalibration();
    				  	*diag_state = isFinished;
    				  	return;
    				}
    			}
    		}
    		else
    		{
                uds_state_client_mrr.frame_type = SINGLE_FRAME;
    		    prepareServReadData(uds_data, 0x0303);
    		    memcpy(txData, uds_data, 8);
    		    CAN_TransmitFrame(ptr_UDS_Req_MO, txData);

    		    uds_state_client_mrr.lastMessageTime = SystemTime;
    		    state_calib.lastTimeIncMessage = SystemTime;
    		    state_calib.step_calib = CALIB_WAITING_RESP;
    		    state_calib.last_step_calib = CALIB_RD_CALIB_RES;
                uds_state_client_mrr.frame_status.SID = ReadDataByIdentifierService_0x22;
    		}

    		break;

    	default:
    		break;
    }
}

void answerMrrxFrame()
{
	uint8 txd[8];
	memset(txd, 0x00, 8);

    CanMessageObject_t *MRRX_MO = g_radar_pos == MRR_REAR_LEFT ? &China_UDS_RL_Phy_Req_MO : &China_UDS_RR_Phy_Req_MO;

    if (uds_state_request_mrr.frame_status.NRC != 0x00)
	{
		prepareMrrxNRCFrame(txd);
		CAN_TransmitFrame(MRRX_MO, txd);
		return;
	}

    if (uds_state_request_mrr.frame_status.flg_request == isRequest)
	{
        uds_state_request_mrr.frame_status.flg_request = isIdle;

        if (uds_state_request_mrr.frame_type == SINGLE_FRAME)
		{
			//prepareDiagSingleFrame(txd);
		}

        if (uds_state_request_mrr.frame_type == FLOW_CONTROL_FRAME)
		{
			prepareDiagFlowControlFrame(txd, 0, 0, 0);
		}

		CAN_TransmitFrame(MRRX_MO, txd);
    }
}

void prepareMrrxNRCFrame(uint8* data)
{
	data[0] = 0x03;
	data[1] = NRC_0x7F;
    data[2] = uds_state_request_mrr.frame_status.SID;
    data[3] = uds_state_request_mrr.frame_status.NRC;
	memset(&data[4], 0xAA, 4);
}

void prepareServChangeSession(unsigned char *data, unsigned char subFunc)
{
	data[0] = 0x00 | 0x02;
	data[1] = 0x10;
	data[2] = subFunc;
	memset(&data[3], 0x00, 5);
}

unsigned char* prepareServWriteData(unsigned char *txData, unsigned char *buff, unsigned short len, unsigned short did, frame_t frame)
{
	unsigned char *ret;

    if (frame == SINGLE_FRAME)
	{
		buff[0] = (frame&0x03)<<4;
		buff[0] |= (unsigned char)len & 0x07;
		buff[1] = 0x2E;
		buff[2] = did >>8;
		buff[3] = (unsigned char)did;
		ret = &buff[4];
	}

    if (frame == FIRST_FRAME)
	{
		buff[0] = (frame&0x03)<<4;
		buff[0] |= (len>>8)& 0x0F;
		buff[1] = (unsigned char)len;
		buff[2] = 0x2E;
		buff[3] = did>>8;
		buff[4] = (unsigned char)did;
		ret = &buff[5];
	}

    if (frame == CONSECUTIVE_FRAME)
	{
		uds_state_client_mrr.frameNumber = (uds_state_client_mrr.frameNumber+1)&0x0F;

		if (uds_state_client_mrr.frameNumber == 0)
		{
			uds_state_client_mrr.frameNumber = 1;
		}

        txData[0] = CONSECUTIVE_FRAME<<4;
		txData[0] |= uds_state_client_mrr.frameNumber;
		memcpy(&txData[1], buff, 7);
		ret = buff+7;
	}

	return ret;
}

void prepareServCommControl(unsigned char *data, unsigned short len, unsigned char subFunc, unsigned char commType)
{
	data[0] = 0x00 | (len&0x07);
	data[1] = 0x28;
	data[2] = subFunc;
	data[3] = commType;
	memset(&data[4], 0x00, 4);
}

void prepareServClearDTC(unsigned char *data, unsigned short len, unsigned char subFunc)
{
	data[0] = 0x00 | ((unsigned char)len&0x07);
	data[1] = 0x85;
	data[2] = subFunc;
	memset(&data[3], 0x00, 5);
}

void prepareServRoutineControl(unsigned char *data, unsigned short len, unsigned char subFunc, unsigned short did)
{
	data[0] = 0x00 | ((unsigned char)len&0x07);
	data[1] = 0x31;
	data[2] = subFunc;
	data[3] = did>>8;
	data[4] = did;
	memset(&data[5], 0x00, 3);
}

void prepareServECUReset(unsigned char *data, unsigned short len, unsigned char subFunc)
{
	data[0] = 0x02;
	data[1] = 0x11;
	data[2] = subFunc;
	memset(&data[3], 0x00, 5);
}

void prepareServReadData(unsigned char *data, unsigned short did)
{
	data[0] = 0x03;
	data[1] = 0x22;
	data[2] = did>>8;
	data[3] = (unsigned char)did;
	memset(&data[4], 0x00, 4);
}

void prepareDiagSingleFrame(unsigned char *data, unsigned short did, unsigned char subFunc)
{
	data[0] = 0x03;
    data[1] = uds_state_request_mrr.frame_status.SID + 0x40;
    data[2] = uds_state_request_mrr.frame_status.DID>>8;
    data[3] = (unsigned char)uds_state_request_mrr.frame_status.DID;
	memset(&data[4], 0x00, 4);
}

void prepareDiagFlowControlFrame(unsigned char *data, unsigned char flag, unsigned char blockSize, unsigned char sepTime)
{
	data[0] = 0x30 | (flag&0x0F);
	data[1] = blockSize;
	data[2] = sepTime;
	memset(&data[3], 0x00, 5);
}

void prepareUdsData(unsigned char *data)
{
	uint32 d;
	uint16 fake_value1 = 0x0000;
	uint16 fake_value2 = 0x0057;

	uint16 raw_val = 0;

	if (state_calib.step_calib == CALIB_WR_VEH_INFO_ST)
	{
		d = mrr_reverse_bit32(*(unsigned int*)&REQ_MRR_CarBase_Val);
		memcpy(&data[0], &d, 4);
		d = mrr_reverse_bit32(*(unsigned int*)&REQ_MRR_CarWidth_Val);
		memcpy(&data[4], &d, 4);
	}

	if (state_calib.step_calib == CALIB_WR_RADAR_INST_INFO)
	{
		d = mrr_reverse_bit32(*(unsigned int*)&REQ_MRR_DistFrToRearAxle_Val);
		memcpy(&data[0], &d, 4);
		d = mrr_reverse_bit32(*(unsigned int*)&REQ_MRR_DistRrToRearAxle_Val);
		memcpy(&data[4], &d, 4);
		d = mrr_reverse_bit32(*(unsigned int*)&REQ_MRR_RelativeDistFR_Val);
		memcpy(&data[8], &d, 4);
		d = mrr_reverse_bit32(*(unsigned int*)&REQ_MRR_RelativeDistRR_Val);
		memcpy(&data[12], &d, 4);
		d = mrr_reverse_bit32(*(unsigned int*)&REQ_MRR_RelativeDistToFR_RR_Val);
		memcpy(&data[16], &d, 4);
		d = mrr_reverse_bit32(*(unsigned int*)&REQ_MRR_HeightInstallRadar_Val);
		memcpy(&data[20], &d, 4);
		d = mrr_reverse_bit32(*(unsigned int*)&REQ_MRR_DistMirrorToRR_Val);
		memcpy(&data[24], &d, 4);
	}

	if (state_calib.step_calib == CALIB_WR_DONT_KNOW_INFO)
	{
		d = mrr_reverse_bit16(*(unsigned short*)&fake_value1);	// ??
		memcpy(&data[0], &d, 2);
		d = mrr_reverse_bit16(*(unsigned short*)&fake_value2);	// ??
		memcpy(&data[2], &d, 2);
	}

	if (state_calib.step_calib == CALIB_WR_TRIANGLE_REFL_INFO)
	{
		raw_val = (unsigned short)(REQ_MRR_TgtOffsetAngle_Val *100);
		d = mrr_reverse_bit16(raw_val);
		memcpy(&data[0], &d, 2);

		raw_val = (unsigned short)(REQ_MRR_TgtDistance_Val *100);
		d = mrr_reverse_bit16(raw_val);
		memcpy(&data[2], &d, 2);
	}
}

void udsPosResponceCibration(step_calib_t target_step_calib)
{
	state_calib.step_calib = target_step_calib;
    uds_state_client_mrr.frame_status.NRC = 0x00;
    uds_state_client_mrr.frame_status.PRC = 0x00;
    uds_state_client_mrr.frame_status.SID = 0x00;
    uds_state_client_mrr.frame_status.LEN = 0x0000;
    uds_state_client_mrr.frame_status.DID = 0x0000;
    uds_state_client_mrr.frame_type = SINGLE_FRAME;
}

void udsExitCalibration()
{
	state_calib.countTryRequest = 0;
	state_calib.lastTimeIncMessage = 0;
	state_calib.last_step_calib = CALIB_IDLE_STATE;
	state_calib.step_calib = CALIB_IDLE_STATE;

    uds_state_client_mrr.frame_status.LEN = 0;
    uds_state_client_mrr.frame_status.NRC = 0;
    uds_state_client_mrr.frame_status.PRC = 0;
    uds_state_client_mrr.frame_status.DID = 0;
    uds_state_client_mrr.frame_status.SID = 0;
    uds_state_client_mrr.frame_status.flg_request = 0;
    uds_state_client_mrr.frame_status.useDid = 0;
    uds_state_client_mrr.frame_status.subfunc_code= 0;
    uds_state_client_mrr.frame_status.FC_BS = 0;
    uds_state_client_mrr.frame_status.FC_FLAG = 0;
    uds_state_client_mrr.frame_status.FC_reqEn = 0;
    uds_state_client_mrr.frame_status.FC_ST = 0;
    uds_state_client_mrr.frame_type = SINGLE_FRAME;
	uds_state_client_mrr.frameNumber = 0;
	uds_state_client_mrr.lastMessageTime = 0;
	uds_state_client_mrr.p_next_data = 0;
	uds_state_client_mrr.reminderLen = 0;
	uds_state_client_mrr.targetLen = 0;
}

uint32 mrr_reverse_bit32(uint32 x)
{
	return (x&0xFF000000)>>24 | (x&0x000000FF)<<24 | (x&0x00FF0000)>>8 | (x&0x0000FF00)<<8;
}

uint16 mrr_reverse_bit16(uint16 x)
{
	return (x&0xFF00)>>8 | (x&0x00FF)<<8 ;
}

int find_did(uint16 did)
{
	int ret = -1;
	int i=0;

	for (i=0; i < 18; i++)
	{
		if (did == didss_list[i].did)
		{
			ret = i;
			break;
		}
	}

	return ret;
}
