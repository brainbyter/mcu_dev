#include "AATest.h"
#include "FD_Vars.h"
#include "I_DIAG_DAS.h"

AA_State_t AA_State = AA_Test_State_Low;

void AASwitch()
{
	switch (AA_State)
	{
	case AA_Test_State_Low:
		if (TD_DfAnAaStTest == 1)
		{
			DfMemAaStTest ^= 1;
			AA_State = AA_Test_State_High;
		}

		break;

	case AA_Test_State_High:
		if (TD_DfAnAaStTest == 0)
		{
			AA_State = AA_Test_State_Low;
		}

		break;

	default:
		break;
	}
}
