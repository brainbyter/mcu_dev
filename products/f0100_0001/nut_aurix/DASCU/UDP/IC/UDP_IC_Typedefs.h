#ifndef _UDP_IC_TYPEDEFS_H_
#define _UDP_IC_TYPEDEFS_H_

#include <Platform_Types.h>
#include <stdint.h>


typedef struct
{
	unsigned short DLC;
	unsigned int cycle;
	unsigned int lastMessageTime;
	unsigned char* pRC;
	void (*handler)(unsigned char*);
} UdpIcMessageObject_t;

#endif
