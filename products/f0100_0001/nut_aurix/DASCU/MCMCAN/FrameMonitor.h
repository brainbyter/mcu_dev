/*
 * FrameMonitor.h
 *
 *  Created on: 28 ���. 2020 �.
 *      Author: ivan.gerasimov
 */

#ifndef _FRAMEMONITOR_H_
#define _FRAMEMONITOR_H_


#include "Platform_Types.h"

#define DEFAULT_FM_PARAMS	.roll_error = FALSE, .checksum_error = FALSE, .dlc_error = FALSE, .roll_expect = 0, .roll_error_counter = 3, .checksum_error_counter = 3, .dlc_error_counter = 3
#define DEFAULT_IC_PARAMS	.counter = 3,

#define FRAMEMONITOR_WITH_RC_CS(x) { &ComScl_##x##_DataCorrupt, &ComScl_##x##_AlvCntError, &ComScl_##x##_ChksmError, &ComScl_##x##_Timeout, DEFAULT_FM_PARAMS };
#define FRAMEMONITOR_NO_RC_CS(x)   { &ComScl_##x##_DataCorrupt, 0, 0, &ComScl_##x##_Timeout, DEFAULT_FM_PARAMS };


typedef struct
{
	boolean* ComScl_DLC;
	boolean* ComScl_Roll;
	boolean* ComScl_CS;
	boolean* ComScl_Timeout;

	boolean roll_error;
	boolean checksum_error;
	boolean dlc_error;
	uint8 roll_expect;
	uint8 roll_error_counter;
	uint8 checksum_error_counter;
	uint8 dlc_error_counter;
} Framemonitor_t;


typedef struct
{
	boolean* invalid;
	uint8 counter;
} InvalidCounter_t;


void FrameMonitor_CheckRC(Framemonitor_t* fmon, uint8 rc);
void FrameMonitor_CheckCS(Framemonitor_t* fmon, uint8 cs1, uint8 cs2);
void FrameMonitor_CheckDLC(Framemonitor_t* fmon, uint8 dlc1, uint8 dlc2);
boolean FrameMonitor_IsFaulty(Framemonitor_t* fmon);
void InvalidCounter_Update(InvalidCounter_t* ic, boolean invalid);


#endif /* 0_SRC_0_APPSW_TRICORE_CAN_FRAMEMONITOR_H_ */

