/*
 * CAN_BusOff.c
 *
 *  Created on: 28 ����. 2020 �.
 *      Author: ivan.gerasimov
 */

#include <CAN_Private.h>
#include <CAN_Extern.h>
#include <CAN.h>


static void CAN_NetworkDiagnostics(CANNetwork_t* network);
static void CAN_T15Handling();


void CAN_NetworkManagement()
{
	int i;
	for(i = 0; i < CAN_MAX_NETWORKS; i++)
	{
		CAN_NetworkDiagnostics(&CAN_Networks[i]);
	}
	CAN_T15Handling();
}


void CAN_NetworkDiagnostics(CANNetwork_t* network)
{

}


void CAN_T15Handling()
{
/*
	static boolean prevT15 = FALSE;

	if(IgnSt)
	{
		if(IgnSt != prevT15)
		{
            SetCANTXEn(ADASCANFD, TRUE);
            SetCANRXEn(ADASCANFD, TRUE);
		}
	}
	else
	{

		SetCANTXEn(ADASCANFD, FALSE);

	}
	prevT15 = IgnSt;
*/
}
