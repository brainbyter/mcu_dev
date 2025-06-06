#include "CAN.h"
#include "CAN_Private.h"

boolean LocalDACANCANBusOff = 1;
boolean LocalDACANCANPassiveNetworkFlt = 1;
boolean DACANCANBusOff = 1;
boolean DACANCANPassiveNetworkFlt = 1;
boolean XCPCANBusOff = 1;
boolean XCPCANPassiveNetworkFlt = 1;

CANNetwork_t CAN_Networks[] =
{
 /* LocalDACAN */  { .baudrate = 500000, .pBusOffFlt = &LocalDACANCANBusOff,  .pErrorPassivNetwork = &LocalDACANCANPassiveNetworkFlt},
 /* DACAN */       { .baudrate = 500000, .pBusOffFlt = &DACANCANBusOff,       .pErrorPassivNetwork = &DACANCANPassiveNetworkFlt},
 /* XCPCAN */      { .baudrate = 1000000, .pBusOffFlt = &XCPCANBusOff,         .pErrorPassivNetwork = &XCPCANPassiveNetworkFlt},
};

const uint8 CAN_MAX_NETWORKS = (sizeof(CAN_Networks) / sizeof(CAN_Networks[0]));


