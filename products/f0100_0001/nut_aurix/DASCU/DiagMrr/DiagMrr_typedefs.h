#ifndef _DIAGMRR_TYPEDEFS_H_
#define _DIAGMRR_TYPEDEFS_H_
#include <stdint.h>
#include <string.h>
#include <Platform_Types.h>
#include "bsp_can.h"
#include "..\ext_vars.h"
#include "Diag_typedefs.h"

#define ISOSAEReserved 0x00
#define NUM_DIDS_IN_LIST (sizeof(dids_list)/sizeof(DIDs_t))

typedef enum {MRR_REAR_LEFT, MRR_REAR_RIGHT} radar_pos_t;
typedef enum {isDisable, isEnable, isQueue, isFinished} diag_state_t;

typedef struct
{
	diag_state_t diag_state_rl;
	diag_state_t diag_state_rr;
} diag_process_status_t;

typedef enum {
	NoService_0x00=0x00,
    DiagnosticSessionControlService_0x10=0x10,
    ECUResetService_0x11=0x11,
    CommunicationalControl_0x28=0x28,
    ControlDTCSettings_0x85=0x85,
    SecurityAccessService_0x27=0x27,
    TesterPresentService_0x3E=0x3E,
    ReadDataByIdentifierService_0x22=0x22,
    WriteDataByIdentifierService_0x2E=0x2E,
    ClearDiagnosticSInformationService_0x14=0x14,
    RoutineControlService_0x31=0x31,
    RequestDownloadService_0x34=0x34,
    TransferDataService_0x36=0x36,
    RequestTransferDataService_0x37=0x37,
	resetedValueServ=0xFF
} Mrr_supported_services_t;

typedef enum {
    noError = 0x00,
    SubFunctionNotSupported_0x12 = 0x12,
    incorrectMessaheLenghtOrInvalidFormat_0x13=0x13,
    conditionsNotCorrect=0x22,
    requestOutOfRange = 0x31
} NRC_Codes_t;

typedef enum {
    IDLE_STATE,
    CALIB_STATE,
} State_mrr_t;

typedef enum {
  CALIB_IDLE_STATE,
  CALIB_WAITING_RESP,
  CALIB_COMM_CONTROL,
  CALIB_SW_2_CAL_WAVE_ST,
  CALIB_EXT_SESS_ST,
  CALIB_WR_VEH_INFO_ST,
  CALIB_WR_RADAR_INST_INFO,
  CALIB_WR_DONT_KNOW_INFO,
  CALIB_WR_TRIANGLE_REFL_INFO,
  CALIB_SHTDW_DTC,
  CALIB_STOP_PERIOD_COMM,
  CALIB_START,
  CALIB_CHECK_CALIB_ST,
  CALIB_DELAY_1S,
  CALIB_DELAY_2S,
  CALIB_END_CALIB,
  CALIB_RST_RADAR,
  CALIB_RD_CALIB_RES_FLG,
  CALIB_RD_CALIB_RES,
  CALIB_OVER
} step_calib_t;

typedef enum {
	MRRX_IDLE_STATE,
	MRRX_EXT_SESS_ST,
	MRRX_WAITING_RESP,
	MRRX_WR_VEH_INFO_ST
} state_mrrx_uds_t;

typedef struct
{
	uint32 lastTimeIncMessage;
	uint8 countTryRequest;
	step_calib_t step_calib;
	step_calib_t last_step_calib;
} state_calib_t;

typedef enum
{
	MRR_Boot_Software_Identification_Data_Identifier = 0xF180,
	MRR_OEM_Part_Number = 0xF187,
	MRR_VIN = 0xF190,
	MRR_Software_Version_Number = 0xF195,
	MRR_Repair_Shop_Code = 0xF198,
	MRR_Programming_Data = 0xF199,
	MRR_ECU_Installation_Date = 0xF19D,
	MRR_Radar_Alignment_Completion_Flag = 0x0302,
	MRR_Radar_Alignment_Results = 0x0303,
	MRR_Radar_Supply_Voltage_12V = 0x0305,
	MRR_MCU_Supply_Voltage_5V = 0x0315,
	MRR_RF_Supply_Voltage_1_5V = 0x0325,
	MRR_Radar_Temperature = 0x0306,
	MRR_RadarManufactureData = 0x0309,
	MRR_VehiPara = 0xF1F8,
	MRR_RadarInsParas = 0xF1F9,
	MRR_DONTKNOW = 0x0300,
	MRR_TRIANGLE_REFL_INFO = 0x0301
} did_list_t;

typedef struct
{
    unsigned short did;
    did_support_session_t supp_sess;
    void (*data_did_handler)(unsigned char*, radar_pos_t);
} dids_t;



#endif
