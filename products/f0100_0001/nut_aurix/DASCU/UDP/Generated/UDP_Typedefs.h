#ifndef _UDP_TYPEDEFS_H_
#define _UDP_TYPEDEFS_H_

#include <Platform_Types.h>
#include <stdint.h>

typedef enum {ToGpu = 0x00, FromGpu} UdpDirection_t;

typedef struct UdpMessageObject
{
	unsigned char ID;
	unsigned short DLC;
	UdpDirection_t dir;
	unsigned int cycle;
	unsigned int lastMessageTime;
	unsigned char* pTimeout;
	unsigned char* pRC;
	unsigned short countCycleTimeout;
	void (*handler)(unsigned char*);
	void (*prepareHandler)();
	void (*failHandler)();
	void* prevUdpMessageObj;
} UdpMessageObject_t;

#endif
