#include "Platform_Types.h"
#include "UDP_Typedefs.h"

#define UDP_DIAG_CONFIG_CYCLE_TYME  1000
#define UDP_DIAG_CALIBRATION_CYCLE_TYME  100

extern UdpMessageObject_t *lastUdpMessageObject;
extern void readUdpPacket(uint8 id, uint8 *data, uint8 len);
extern void UDP_InitMessageObjects();
extern void UDP_InitMessageObject(UdpMessageObject_t* UdpMessageObj);
extern void UDP_Process();
extern void UDP_TransmitPeriodicalFrame(UdpMessageObject_t* UdpMessageObj);
extern void UDP_TransmitFrame(UdpMessageObject_t* UdpMessageObj);
extern void UDP_ReceivePacket(UdpMessageObject_t* UdpMessageObj);

extern float udpIsNan();

//IC
extern void UDP_TransmitPeriodicalPacketIC();
