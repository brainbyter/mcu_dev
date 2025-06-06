#include <memfiu.h>
#include "mem.h"
#include <Platform_Types.h>
#include <CAN.h>
#include <I_DIAG_DAS.h>
#include <O_CAN_DAS.h>
#include "CAN_Mapping.h"

#define FIU_MEM_LEN	35

extern uint8 IgnSt;

unsigned char fui_data_write_en = 0;
car_state_t T15_state = T15_idle;


void Watch_T15_state ()
{
	switch (T15_state)
	{
		case T15_idle:
			if (BCM_T15_Stat)
			{
				T15_state = T15_on;
			}

		break;

		case T15_on:
			if (!BCM_T15_Stat)
			{
				T15_state = T15_off;
				fui_data_write_en = 1;
			}
		break;

		case T15_off:
			T15_state = T15_idle;
		break;
	}
	if (fui_data_write_en)
	{

		WriteMemFiuStates();
		fui_data_write_en = 0;
	}
}

void SaveCurrentFiuData()
{
	DfMemFiuAaMode = OSettAaModeSts;
	DfMemFiuAaStat = OSettAaSts;
	DfMemFiuAebStat = OSettAebSts;
	DfMemFiuAfsStat = OSettAfsSts;
	DfMemFiuAlccStat = OSettAlccSts;
	DfMemFiuAslaOver = OSettAslaOverCmd;
	DfMemFiuAslaStat = OSettAslaSts;
	DfMemFiuCcMode = OSettCcModeSts;
	DfMemFiuCcSpdCorrect = OSettCcSpdCorrectSts;
	DfMemFiuCcType = OSettCcTypeSts;
	DfMemFiuDowSound = OSettDowSoundSts;
	DfMemFiuDowStat = OSettDowSts;
	DfMemFiuFcwMode = OSettFcwModeSts;
	DfMemFiuFcwStat = OSettFcwSts;
	DfMemFiuFcwVibration = OSettFcwVibrationSts;
	DfMemFiuLccMode = OSettLccModeSts;
	DfMemFiuLccSound = OSettLccSoundSts;
	DfMemFiuLccStat = OSettLccSts;
	DfMemFiuLccVibration = OSettLccVibrationSts;
	DfMemFiuLdpStat = OSettLdpSts;
	DfMemFiuLdwMode = OSettLdwModeSts;
	DfMemFiuLdwSound = OSettLdwSoundSts;
	DfMemFiuLdwStat = OSettLdwSts;
	DfMemFiuLdwVibration = OSettLdwVibrationSts;
	DfMemFiuLkaStat = OSettLkaSts;
	DfMemFiuNavigStat = OSettNavigSts;
	DfMemFiuOtherObjStat = OSettOtherObjSts;
	DfMemFiuProjectionOnARoadStat = OSettProjectionOnARoadSts;
	DfMemFiuRctcStat = OSettRctcSts;
	DfMemFiuRdaAutoBrakeStat = OSettRdaAutoBrakeSts;
	DfMemFiuRdaStat = OSettRdaSts;
	DfMemFiuRecStat = OSettRecSts;
	DfMemFiuRoadSignStat = OSettRoadSignSts;
	DfMemFiuSensCleanStat = OSettSensCleanSts;
	DfMemFiuTsrStat = OSettTsrSts;
}


void FillFiuData(uint8_t* Data)
{
	Data[0] = 'F';
	Data[1] = 'I';
	Data[2] = 'U';
	Data[3] = 'C';
	Data[4] = OSettAaModeSts;
	Data[5] = OSettAaSts;
	Data[6] = OSettAebSts;
	Data[7] = OSettAfsSts;
	Data[8] = OSettAlccSts;
	Data[9] = OSettAslaOverCmd;
	Data[10] = OSettAslaSts;
	Data[11] = OSettCcModeSts;
	Data[12] = OSettCcSpdCorrectSts;
	Data[13] = OSettCcTypeSts;
	Data[14] = OSettDowSoundSts;
	Data[15] = OSettDowSts;
	Data[16] = OSettFcwModeSts;
	Data[17] = OSettFcwSts;
	Data[18] = OSettFcwVibrationSts;
	Data[19] = OSettLccModeSts;
	Data[20] = OSettLccSoundSts;
	Data[21] = OSettLccSts;
	Data[22] = OSettLccVibrationSts;
	Data[23] = OSettLdpSts;
	Data[24] = OSettLdwModeSts;
	Data[25] = OSettLdwSoundSts;
	Data[26] = OSettLdwSts;
	Data[27] = OSettLdwVibrationSts;
	Data[28] = OSettLkaSts;
	Data[29] = OSettNavigSts;
	Data[30] = OSettOtherObjSts;
	Data[31] = OSettProjectionOnARoadSts;
	Data[32] = OSettRctcSts;
	Data[33] = OSettRdaAutoBrakeSts;
	Data[34] = OSettRdaSts;
	Data[35] = OSettRecSts;
	Data[36] = OSettRoadSignSts;
	Data[37] = OSettSensCleanSts;
	Data[38] = OSettTsrSts;
}

void ParseMemFiuStates(uint8_t* Data)
{
	DfMemFiuAaMode = Data[0];
	DfMemFiuAaStat = Data[1];
	DfMemFiuAebStat = Data[2];
	DfMemFiuAfsStat = Data[3];
	DfMemFiuAlccStat = Data[4];
	DfMemFiuAslaOver = Data[5];
	DfMemFiuAslaStat = Data[6];
	DfMemFiuCcMode = Data[7];
	DfMemFiuCcSpdCorrect = Data[8];
	DfMemFiuCcType = Data[9];
	DfMemFiuDowSound = Data[10];
	DfMemFiuDowStat = Data[11];
	DfMemFiuFcwMode = Data[12];
	DfMemFiuFcwStat = Data[13];
	DfMemFiuFcwVibration = Data[14];
	DfMemFiuLccMode = Data[15];
	DfMemFiuLccSound = Data[16];
	DfMemFiuLccStat = Data[17];
	DfMemFiuLccVibration = Data[18];
	DfMemFiuLdpStat = Data[19];
	DfMemFiuLdwMode = Data[20];
	DfMemFiuLdwSound = Data[21];
	DfMemFiuLdwStat = Data[22];
	DfMemFiuLdwVibration = Data[23];
	DfMemFiuLkaStat = Data[24];
	DfMemFiuNavigStat = Data[25];
	DfMemFiuOtherObjStat = Data[26];
	DfMemFiuProjectionOnARoadStat = Data[27];
	DfMemFiuRctcStat = Data[28];
	DfMemFiuRdaAutoBrakeStat = Data[29];
	DfMemFiuRdaStat = Data[30];
	DfMemFiuRecStat = Data[31];
	DfMemFiuRoadSignStat = Data[32];
	DfMemFiuSensCleanStat = Data[33];
	DfMemFiuTsrStat = Data[34];
}

void ReadMemFiuStates()
{
	uint8_t flashData[FIU_MEM_LEN];
	ReadFlash(FIU_MEM_HEADER + 4, flashData, FIU_MEM_LEN);
	ParseMemFiuStates(flashData);
}

void WriteMemFiuStates()
{
	EraseFlash (FIU_MEM_HEADER, FIU_MEM_LEN + 4);
	uint8_t flashData[FIU_MEM_LEN + 4];
	FillFiuData(flashData);
	SaveCurrentFiuData();
	WriteFlash(FIU_MEM_HEADER, flashData, FIU_MEM_LEN + 4);
}

