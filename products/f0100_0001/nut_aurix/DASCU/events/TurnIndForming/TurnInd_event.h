#ifndef _TURN_IND_EVENT_H_
#define _TURN_IND_EVENT_H_
#include "stdint.h"
#include "Platform_Types.h"

typedef enum {NO_TURN_IND, TURN_IND_LEFT, TURN_IND_RIGHT, BOTH_TURN} TurnInd_Dir_t;
typedef enum {TurnIsOff, TurnIsOn} TurnInd_state_t;
typedef enum {TurnIndIdle, TurnIndCounting, TurnIndCheckLevel} TurnIndTimeControl_state_t;

typedef enum {CalcPeriodIdle, CalculatingValue, ValueIsOk} CheckPeriodValue_t;

typedef struct
{
	CheckPeriodValue_t CheckPeriodValue;
	unsigned int firstTurnInputTime;
	unsigned int currentMsValueLevel;
} TurnPeriodState_t;


extern TurnInd_Dir_t TurnInd_Dir;
extern TurnInd_state_t TurnIndLeft_state;
extern TurnInd_state_t TurnIndRight_state;
extern TurnIndTimeControl_state_t TurnIndTimeControlLeft_state;
extern TurnIndTimeControl_state_t TurnIndTimeControlRight_state;
extern volatile unsigned int turnCounterLeft;
extern volatile unsigned int turnCounterRight;
extern TurnPeriodState_t TurnPeriodStateLeft;
extern TurnPeriodState_t TurnPeriodStateRight;

extern volatile uint8 leftFormingState;
extern volatile uint8 rightFormingState;

void TurnChangeState(TurnInd_Dir_t dir, TurnIndTimeControl_state_t TimeControl_State, unsigned char flagReset, unsigned int counterValue);
void TurnIndLeft_process();
void TurnIndRight_process();
void refreshTurnState();

#endif
