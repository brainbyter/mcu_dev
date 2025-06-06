#include "DiagErag_typedefs.h"
#include "FD_MessageObjects.h"
#include "CAN_Extern.h"
#include "CAN_Private.h"
#include "stdlib.h"
#include "DiagErag_ext_vars.h"
#include "DiagErag_ext_functions.h"


void manageEragRequest()
{
	if (TD_SOS_Req)
	{
		TD_SOS_Req = 0;
		TD_SOS_Hardcore_CANCEL = 0;

		if (ERAG_SOS_FSM.SOS_State == SOS_Idle)
		{
			ERAG_SOS_FSM.SOS_State = SOS_SendExtSess;

			printf("Here!(1)\n");
		}
	}

	if (TD_SOS_Hardcore_CANCEL)
	{
		TD_SOS_Req = 0;
		TD_SOS_Hardcore_CANCEL = 0;
		ERAG_SOS_FSM.SOS_State = SOS_Idle;
		udsExitSos();
	}
}
