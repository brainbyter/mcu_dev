#include <memfiu.h>
#include "mem.h"
#include <Platform_Types.h>
#include <CAN.h>
#include <I_DIAG_DAS.h>
#include <O_CAN_DAS.h>
#include "CAN_Mapping.h"



void ReadMemData()
{
	unsigned char flashDataHeader[MEM_HEADER];
	ReadFlash(FIU_MEM_HEADER, flashDataHeader, MEM_HEADER);

	if (strncmp(flashDataHeader, "FIUC", MEM_HEADER) == 0)
	{
		ReadMemFiuStates();
	}
}

