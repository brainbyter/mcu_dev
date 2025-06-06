#ifndef _XCP_H_
#define _XCP_H_



#define XCP_MAX_DAQ             6
#define XCP_MAX_EVENT_CHANNEL   3
#define XCP_MAX_ODT             43
#define XCP_MAX_BS              43
#define XCP_MAX_ODT_ENTRY       6
#define XCP_MAX_ODT_ENTRY_SIZE  6


#define ADDRESS_IN_RANGE(address) (((address >= 0x70000000) && (address < 0x7FFFFFFF)) || ((address >= 0x80000000) && (address < 0x8FFFFFFF)))
#define ADDRESS_AND_SIZE_IN_RANGE(address, size) (ADDRESS_IN_RANGE(address) && ADDRESS_IN_RANGE(address + size - 1))

#include "xcp_typedefs.h"

void XCP_Init();
void XCP_Send(uint8_t* data, uint8_t size);
void XCP_ProcessUploadReq();
void XCP_UpdateEvents();
void XCP_ProcessDAQlist(uint8_t daqListNum);
void XCP_DAQreset(DAQlist_t* daqList);
extern uint8_t XCP_Connected;


#endif /* USRC_XCP_XCP_H_ */
