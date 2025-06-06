/*
 * CAN_Typedefs.h
 *
 *  Created on: 22 ����. 2023 �.
 *      Author: ivan.gerasimov
 */

#ifndef _CAN_TYPEDEFS_H_
#define _CAN_TYPEDEFS_H_

#include "CAN.h"
#include <Platform_Types.h>

typedef enum
{
    TX = 0,
    RX = 1
} CANDirection_t;

typedef enum
{
	MRRX_DATA = 3,		// (CAN2 on cable)	kCan2
	FD = 0,				// (CAN3 on cable)	kCan3
	MRRXCAN_DIAG = 2,	// (CAN4 on cable)	kCan4
	FRADAR_DATA = 5,	// (CAN5 on cable)	kCan5
	ADASCANFD = 9,		// (CAN6 on cable)	kCan6
    HAVAL = 10,			// (CAN7 on cable)	kCan7
	XCP_CAN	= 11		// (CAN8 on cable)	kCan8
} CANNetworkID_t;

typedef struct
{
    uint8   nodeID;
    uint8   txEn;
    uint8   rxEn;
    uint32  baudrate;
    uint32 lastMessageTime;
    uint32 lastRecoveryTime;
    uint32 recoveryAttempts;
    boolean* pBusOffFlt;
    boolean* pErrorPassivNetwork;
} CANNetwork_t;



typedef struct _CANMessageObject
{
    CANNetworkID_t network;
    uint32_t ID;
    uint32_t mask;
    uint8_t DLC;
    CANDirection_t dir;
    uint32_t cycle;
    boolean FD;
    uint32_t lastMessageTime;
    CANNetwork_t* pNetwork;
    unsigned char* pTimeout;
    uint16_t countCycleTimeout;
    void (*handler)(uint8*, uint8);
    void (*prepareHandler)();
    void (*failHandler)();
    void (*diagHandler)(uint8*, uint8);
    void* prevMessageObj;
    void* prevMessageObjForFilter;
    boolean txOk;
} CanMessageObject_t;




#endif
