#include "pwr_mngmnt.h"
#include <CAN.h>
#include <ADASCANFD_Vars.h>
#include "CAN_Mapping.h"
#include "CAN_Extern.h"
#include "power.h"

extern uint8 IgnSt;
extern uint8 SensTermSt;

unsigned char state = 0; //default state
unsigned char prepareToMcuSBYTick = 0; //default state
unsigned char prepareToMcuSBY = 0; //default state
unsigned int dt = 0;
unsigned int dtT15 = 0;

void pwr_mngmnt_state()
{
	switch (state)
	{
	case 0x00:
		if (BCM_T15_Stat)
		{
			state = 1;
			prepareToMcuSBYTick = 0;
			prepareToMcuSBY = 0;
			PowerOnOrinA();
		}
		else
		{
			if (BCM_ADASTerm_Stat == 0x00 && prepareToMcuSBY == 0)
			{
				dt = SystemTime;
				prepareToMcuSBY = 1;
			}
			else
			{
				if (BCM_ADASTerm_Stat)
				{
					prepareToMcuSBY = 0;
					prepareToMcuSBYTick = 0;
					dt = SystemTime;
				}
				else
				{
					if ((SystemTime-dt) >= 3000)
					{
						prepareToMcuSBY = 0;
						prepareToMcuSBYTick = 0;
						SetPowerSystemStandby();
					}
				}
			}
		}

		break;

	case 0x01:
		if (BCM_T15_Stat == 0)
		{
			state = 2;
			dtT15 = SystemTime;
		}
		break;

	case 0x02:
		if (BCM_T15_Stat == 0)
		{
			if ((SystemTime-dtT15)>=5000)
			{
				PowerOffOrinA();
				state = 0;
				prepareToMcuSBYTick = 1;
			}
		}
		else
		{
			state = 1;
			dtT15 = 0;
		}

		break;

	default:
		break;
	}
}
