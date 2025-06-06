/*
 * VIN.c
 *
 *  Created on: 25 ����. 2023 �.
 *      Author: ivan.gerasimov
 */

#include "Platform_Types.h"
#include "CAN_Private.h"
//#include "VMCAN_MessageObjects.h"
//#include "VMCAN_Vars.h"

#define VIN_ALL_PARTS_RECEIVED		0x07

void Diag_VEH_VIN(uint8* data, uint8 dlc);

boolean VIN_FromCAN_OK = FALSE;
uint8 VIN_FromCAN[17] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static uint8 VIN_ReceivedParts = 0;


void VIN_InitCAN()
{
    /*
	VEH_VIN_MO.diagHandler = Diag_VEH_VIN;
	CAN_InitMessageObject(&VEH_VIN_MO);
	*/
}


void Diag_VEH_VIN(uint8* data, uint8 dlc)
{
    /*
	if(dlc == 8)
	{
		VIN_ReceivedParts |= (1 << VIN_Addressing);

		if((VIN_ReceivedParts == VIN_ALL_PARTS_RECEIVED) && !VIN_FromCAN_OK)
		{
			VIN_FromCAN_OK = TRUE;

			VIN_FromCAN[0] = VIN_Char1;
			VIN_FromCAN[1] = VIN_Char2;
			VIN_FromCAN[2] = VIN_Char3;
			VIN_FromCAN[3] = VIN_Char4;
			VIN_FromCAN[4] = VIN_Char5;
			VIN_FromCAN[5] = VIN_Char6;
			VIN_FromCAN[6] = VIN_Char7;
			VIN_FromCAN[7] = VIN_Char8;
			VIN_FromCAN[8] = VIN_Char9;
			VIN_FromCAN[9] = VIN_Char10;
			VIN_FromCAN[10] = VIN_Char11;
			VIN_FromCAN[11] = VIN_Char12;
			VIN_FromCAN[12] = VIN_Char13;
			VIN_FromCAN[13] = VIN_Char14;
			VIN_FromCAN[14] = VIN_Char15;
			VIN_FromCAN[15] = VIN_Char16;
			VIN_FromCAN[16] = VIN_Char17;
		}
	}
	*/
}


void ResetVINReceiver()
{
	int i;
	for(i = 0; i < 17; i++)
	{
		VIN_FromCAN[i] = 0;
	}
	VIN_ReceivedParts = 0;
	VIN_FromCAN_OK = FALSE;
}
