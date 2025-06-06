#include <Platform_Types.h>
#include <stdint.h>
#include "DiagMrr_typedefs.h"

extern state_calib_t state_calib;
extern state_calib_t state_mrrx;
extern dids_t didss_list[18];

extern uint8_t calibCondition;
extern uint8_t calibResultFlag;
extern uint8_t calibAngleShift;
extern uint8_t calibVAngleShift;

extern uint8_t radarAlignComplFlag;
extern uint8_t horizontalAligmentAngle;
extern uint8_t verticalAligmentAngle;
extern uint8_t alignmentResult;

extern radar_pos_t g_radar_pos;
extern uds_state_t uds_state_client_mrr;
extern uds_state_t uds_state_request_mrr;
extern diag_process_status_t diag_process_status;

extern float TD_MRR_VerticalAlignAngle;
extern unsigned char TD_MRR_AlignCompFlg;
extern float TD_MRR_Temp;
extern float TD_MRR_SuppVolt5;
extern float TD_MRR_SuppVolt1_5;
extern float TD_MRR_SuppVolt12;
extern unsigned char TD_MRR_ResCalibration;
extern float TD_MRR_RelativeDistRR;
extern float TD_MRR_RelativeDistFR;
extern float TD_MRR_HorizontalAlignAngle;
extern float TD_MRR_HeightInstallRadar;
extern float TD_MRR_DistRrToRearAxle;
extern float TD_MRR_DistMirrorToRR;
extern float TD_MRR_DistFrToRearAxle;
extern float TD_MRR_CarWidth;
extern float TD_MRR_CarBase;
extern float TD_MRR_BetweenDistFR_RR;

