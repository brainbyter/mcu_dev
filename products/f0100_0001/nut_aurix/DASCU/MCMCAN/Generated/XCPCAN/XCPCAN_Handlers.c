#include <CAN_Private.h>
#include <XCPCAN_Vars.h>
#include <string.h>

void XCP_ProcessMessageTest(uint8_t *data, uint8_t dlc)
{
    XCP_ProcessMessage(data, dlc);
}
