#include <MRRX_DIAG_MessageObjects.h>
#include <MRRX_DIAG_Handlers.h>
#include <MRRX_DIAG_IDs.h>
#include <CAN_Private.h>

CanMessageObject_t DAS_VehInfo1_MO = { .ID = DAS_VehInfo1_ID,.DLC = 8, .cycle = 50, .dir = TX, .network = MRRXCAN_DIAG, .FD = FALSE, .handler = DAS_VehInfo1_Handler};
CanMessageObject_t DAS_VehInfo2_MO = { .ID = DAS_VehInfo2_ID,.DLC = 8, .cycle = 50, .dir = TX, .network = MRRXCAN_DIAG, .FD = FALSE, .handler = DAS_VehInfo2_Handler};
CanMessageObject_t DAS_VehInfo3_MO = { .ID = DAS_VehInfo3_ID,.DLC = 8, .cycle = 50, .dir = TX, .network = MRRXCAN_DIAG, .FD = FALSE, .handler = DAS_VehInfo3_Handler};

/* DIAG MO*/
CanMessageObject_t DAS_SwitchCalibWave_MO = { .ID = DAS_SwitchCalibWave_ID,.DLC = 8, .cycle = 0, .dir = TX, .network = MRRXCAN_DIAG, .FD = FALSE, .handler = DAS_SwitchCalibWave_Handler};
CanMessageObject_t China_UDS_RL_Phy_Req_MO = { .ID = China_UDS_RL_Phy_Req_ID,.DLC = 8, .cycle = 0, .dir = TX, .network = MRRXCAN_DIAG, .FD = FALSE, .handler = UDS_CALIB_RL_REQ_Handler};
CanMessageObject_t China_UDS_RL_Phy_Resp_MO = { .ID = China_UDS_RL_Phy_Resp_ID,.DLC = 8, .cycle = 0, .dir = RX, .network = MRRXCAN_DIAG, .FD = FALSE, .handler = UDS_CALIB_RL_RESP_Handler};
CanMessageObject_t China_UDS_RR_Phy_Req_MO = { .ID = China_UDS_RR_Phy_Req_ID,.DLC = 8, .cycle = 0, .dir = TX, .network = MRRXCAN_DIAG, .FD = FALSE, .handler = UDS_CALIB_RR_REQ_Handler};
CanMessageObject_t China_UDS_RR_Phy_Resp_MO = { .ID = China_UDS_RR_Phy_Resp_ID,.DLC = 8, .cycle = 0, .dir = RX, .network = MRRXCAN_DIAG, .FD = FALSE, .handler = UDS_CALIB_RR_RESP_Handler};
