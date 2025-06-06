#include "stdint.h"
#include "Platform_Types.h"
#include "CAN_Extern.h"
#include "../MCMCAN/Generated/CAN.h"
#include "TurnInd_Event.h"

TurnInd_Dir_t TurnInd_Dir = NO_TURN_IND;
TurnInd_state_t TurnIndLeft_state = TurnIsOff;
TurnInd_state_t TurnIndRight_state = TurnIsOff;
TurnIndTimeControl_state_t TurnIndTimeControlLeft_state = TurnIndIdle;
TurnIndTimeControl_state_t TurnIndTimeControlRight_state = TurnIndIdle;
TurnPeriodState_t TurnPeriodStateLeft = {CalcPeriodIdle, 0, 0};
TurnPeriodState_t TurnPeriodStateRight = {CalcPeriodIdle, 0, 0};

unsigned char fResetTimerLeft = 0;
unsigned char fResetTimerRight = 0;

volatile unsigned int turnCounterLeft = 0;
volatile unsigned int turnCounterRight = 0;

volatile uint8 leftFormingState = 0;
volatile uint8 rightFormingState = 0;

void TurnChangeState(TurnInd_Dir_t dir, TurnIndTimeControl_state_t TimeControl_State, unsigned char flagReset, unsigned int counterValue)
{
	if (dir == TURN_IND_LEFT)
	{
		TurnIndTimeControlLeft_state = TimeControl_State;  
		fResetTimerLeft = flagReset;
		turnCounterLeft = counterValue;
	}
	else if (dir == TURN_IND_RIGHT)
	{
		TurnIndTimeControlRight_state = TimeControl_State;  
		fResetTimerRight = flagReset;
		turnCounterRight = counterValue;
	}
}

void TurnIndLeft_process()
{
	if (TurnLeftSt)
	{
		if (TurnIndLeft_state == TurnIsOff)
		{
			TurnIndLeft_state = TurnIsOn;
			TurnChangeState(TURN_IND_LEFT, TurnIndCounting, 1, 0);
			TurnPeriodStateLeft.firstTurnInputTime = SystemTime;
			TurnPeriodStateLeft.currentMsValueLevel = 0;
			TurnPeriodStateLeft.CheckPeriodValue = CalculatingValue;
		}
		else
		{
			if (!fResetTimerLeft)
			{
				TurnChangeState(TURN_IND_LEFT, TurnIndCounting, 1, 0);
			}
		}
	}
	else
	{
		if (TurnIndLeft_state == TurnIsOn)
		{
			if (fResetTimerLeft && TurnIndTimeControlLeft_state == TurnIndCounting)
			{
				if (TurnPeriodStateLeft.CheckPeriodValue == CalculatingValue)
				{
					TurnPeriodStateLeft.CheckPeriodValue = ValueIsOk;
					TurnPeriodStateLeft.currentMsValueLevel = SystemTime - TurnPeriodStateLeft.firstTurnInputTime;

					if (TurnPeriodStateLeft.currentMsValueLevel > 1000)
					{
						TurnPeriodStateLeft.currentMsValueLevel = 500;
					}
				}
				else if (TurnPeriodStateLeft.CheckPeriodValue == ValueIsOk)
				{
					if (turnCounterLeft < (unsigned int)(TurnPeriodStateLeft.currentMsValueLevel*0.66))
					{
						TurnIndLeft_state = TurnIsOff;
						TurnChangeState(TURN_IND_LEFT, TurnIndIdle, 0, 0);
						TurnPeriodStateLeft.currentMsValueLevel = 0;
						TurnPeriodStateLeft.firstTurnInputTime = 0;
						TurnPeriodStateLeft.CheckPeriodValue = CalcPeriodIdle;

					}
					else
					{
						TurnChangeState(TURN_IND_LEFT, TurnIndCheckLevel, 0, 0);
					}
				}
			}
			else if (TurnIndTimeControlLeft_state == TurnIndCheckLevel && turnCounterLeft >= (TurnPeriodStateLeft.currentMsValueLevel + 100))
			{	
				TurnIndLeft_state = TurnIsOff;
				TurnChangeState(TURN_IND_LEFT, TurnIndIdle, 0, 0);
				TurnPeriodStateLeft.currentMsValueLevel = 0;
				TurnPeriodStateLeft.firstTurnInputTime = 0;
				TurnPeriodStateLeft.CheckPeriodValue = CalcPeriodIdle;
			}
		}
	}
}


void TurnIndRight_process()
{
	if (TurnRightSt)
	{
		if (TurnIndRight_state == TurnIsOff)
		{
			TurnIndRight_state = TurnIsOn;
			TurnChangeState(TURN_IND_RIGHT, TurnIndCounting, 1, 0);
			TurnPeriodStateRight.firstTurnInputTime = SystemTime;
			TurnPeriodStateRight.currentMsValueLevel = 0;
			TurnPeriodStateRight.CheckPeriodValue = CalculatingValue;
		}
		else
		{
			if (!fResetTimerRight)
			{
				TurnChangeState(TURN_IND_RIGHT, TurnIndCounting, 1, 0);
			}
		}
	}
	else
	{
		if (TurnIndRight_state == TurnIsOn)
		{
			if (fResetTimerRight && TurnIndTimeControlRight_state == TurnIndCounting)
			{
				if (TurnPeriodStateRight.CheckPeriodValue == CalculatingValue)
				{
					TurnPeriodStateRight.CheckPeriodValue = ValueIsOk;
					TurnPeriodStateRight.currentMsValueLevel = SystemTime - TurnPeriodStateRight.firstTurnInputTime;

					if (TurnPeriodStateRight.currentMsValueLevel > 1000)
					{
						TurnPeriodStateRight.currentMsValueLevel = 500;
					}
				}
				else if (TurnPeriodStateRight.CheckPeriodValue == ValueIsOk)
				{
					if (turnCounterRight < (unsigned int)(TurnPeriodStateRight.currentMsValueLevel*0.66))
					{
						TurnIndRight_state = TurnIsOff;
						TurnChangeState(TURN_IND_RIGHT, TurnIndIdle, 0, 0);
						TurnPeriodStateRight.currentMsValueLevel = 0;
						TurnPeriodStateRight.firstTurnInputTime = 0;
						TurnPeriodStateRight.CheckPeriodValue = CalcPeriodIdle;

					}
					else
					{
						TurnChangeState(TURN_IND_RIGHT, TurnIndCheckLevel, 0, 0);
					}
				}
			}
			else if (TurnIndTimeControlRight_state == TurnIndCheckLevel && turnCounterRight >= (TurnPeriodStateRight.currentMsValueLevel + 100))
			{	
				TurnIndRight_state = TurnIsOff;
				TurnChangeState(TURN_IND_RIGHT, TurnIndIdle, 0, 0);
				TurnPeriodStateRight.currentMsValueLevel = 0;
				TurnPeriodStateRight.firstTurnInputTime = 0;
				TurnPeriodStateRight.CheckPeriodValue = CalcPeriodIdle;
			}
		}
	}
}

void refreshTurnState()
{
	leftFormingState = TurnIndLeft_state == TurnIsOff ? 0 : 1;
	rightFormingState = TurnIndRight_state == TurnIsOff ? 0 : 1;
}
