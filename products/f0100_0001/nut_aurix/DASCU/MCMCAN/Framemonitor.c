/*
 * Framemonitor.c
 *
 *  Created on: 28 рту. 2020 у.
 *      Author: ivan.gerasimov
 */

#include "FrameMonitor.h"
#include "sw_version.h"

boolean CAN_Debug = TRUE;

void FrameMonitor_CheckRC(Framemonitor_t* fmon, uint8 rc)
{
	fmon->roll_error = (rc != fmon->roll_expect);
    if(fmon->roll_error == 0) { fmon->roll_error_counter = 3; }
    else if(fmon->roll_error_counter > 0) { fmon->roll_error_counter--; }
	fmon->roll_expect = (rc + 1) & 0x0F;
	*fmon->ComScl_Roll = (fmon->roll_error_counter == 0);
}


void FrameMonitor_CheckCS(Framemonitor_t* fmon, uint8 cs1, uint8 cs2)
{
	fmon->checksum_error = (cs1 != cs2);
    if(fmon->checksum_error == 0) { fmon->checksum_error_counter = 3; }
    else if(fmon->checksum_error_counter > 0) { fmon->checksum_error_counter--; }
    *fmon->ComScl_CS = (fmon->checksum_error_counter == 0);
}


void FrameMonitor_CheckDLC(Framemonitor_t* fmon, uint8 dlc1, uint8 dlc2)
{
	fmon->dlc_error = (dlc1 != dlc2);
    if(fmon->dlc_error == 0) { fmon->dlc_error_counter = 3; }
    else if(fmon->dlc_error_counter > 0) { fmon->dlc_error_counter--; }
    *fmon->ComScl_DLC = (fmon->dlc_error_counter == 0);
}


boolean FrameMonitor_IsFaulty(Framemonitor_t* fmon)
{
	return (fmon->dlc_error | fmon->roll_error | fmon->checksum_error) && (CAN_Debug == 0);
}


void InvalidCounter_Update(InvalidCounter_t* ic, boolean invalid)
{
    if(!invalid) { ic->counter = 3; }
    else if(ic->counter > 0) { ic->counter--; }
    *ic->invalid = (ic->counter == 0);
}
