#include <Platform_Types.h>
#include <stdint.h>
#include "xcp_protocol.h"

#define XCP_FIFO_SIZE       32



void XCPProcess();
void SendToFIFO(uint8_t* data, uint8_t size);
void TxInterrupt();

extern uint8_t FIFOdata[XCP_FIFO_SIZE][9];
extern uint8_t fXcpTxIrqEn;

uint32_t Send(uint8_t* data, uint8_t size);
void FIFOsetData(uint8_t* data, uint8_t dlc);
boolean FIFOgetData(uint8_t* data, uint8_t* dlc);

