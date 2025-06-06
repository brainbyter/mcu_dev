#include <XCPCAN_MessageObjects.h>
#include <XCPCAN_Handlers.h>
#include <XCPCAN_IDs.h>
#include <CAN_Private.h>

CanMessageObject_t XCP_CAN_TX_MO = { .ID = XCP_CAN_TX_ID, .DLC = 8, .cycle = 0,  .dir = TX, .network = XCP_CAN, .FD = FALSE};
CanMessageObject_t XCP_CAN_RX_MO = { .ID = XCP_CAN_RX_ID, .DLC = 8, .cycle = 10, .dir = RX, .network = XCP_CAN, .FD = FALSE, .handler = XCP_ProcessMessageTest};
