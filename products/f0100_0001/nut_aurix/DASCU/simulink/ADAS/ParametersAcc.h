/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* [0,1,2,3] intval=realval */
#define DECLARED_CcDistA	CcDistA
extern float CcDistA[4];

/* Angle =[-10,-8,-6,-4,-2,0,2,4,6,7] intval=realval */
#define DECLARED_CcDistAngle	CcDistAngle
extern float CcDistAngle[10];

/* [0,1,2,3] intval=realval */
#define DECLARED_CcDistB	CcDistB
extern float CcDistB[4];

/* [0,1,2,3] intval=realval */
#define DECLARED_CcDistC	CcDistC
extern float CcDistC[4];

/* sec intval=realval */
#define DECLARED_CcDrTakeMinTime	CcDrTakeMinTime
extern float CcDrTakeMinTime;

/* sec intval=realval */
#define DECLARED_CcDrTakeTimeDelay1	CcDrTakeTimeDelay1
extern float CcDrTakeTimeDelay1;

/* sec intval=realval */
#define DECLARED_CcDrTakeTimeDelay2	CcDrTakeTimeDelay2
extern float CcDrTakeTimeDelay2;

/* Error speed = [-10,0,10,20,30,40,50] intval=realval */
#define DECLARED_CcLimGain	CcLimGain
extern float CcLimGain[7];

/* Lower limit of acceleration for LIM, m/s2 intval=realval */
#define DECLARED_CcLimSaturLow	CcLimSaturLow
extern float CcLimSaturLow;

/* Upper limit of acceleration for LIM, m/s2 intval=realval */
#define DECLARED_CcLimSaturUp	CcLimSaturUp
extern float CcLimSaturUp;

/* MaxDist in IC intval=realval */
#define DECLARED_CcMaxDist	CcMaxDist
extern uint8_t CcMaxDist;

/* kmh intval=realval */
#define DECLARED_CcMaxSpeed	CcMaxSpeed
extern float CcMaxSpeed;

/* MinDist in IC intval=realval */
#define DECLARED_CcMinDist	CcMinDist
extern uint8_t CcMinDist;

/* kmh intval=realval */
#define DECLARED_CcMinSpeed	CcMinSpeed
extern float CcMinSpeed;

/* [-10,-8,-6,-4,-2,0,2,4,6,7] intval=realval */
#define DECLARED_CcMMotDovAngle	CcMMotDovAngle
extern float CcMMotDovAngle[10];

/* Lower limit of driver torque and ADAS torque difference, N*m intval=realval */
#define DECLARED_CcMotHysterLow	CcMotHysterLow
extern float CcMotHysterLow;

/* Upper limit of driver torque and ADAS torque difference, N*m intval=realval */
#define DECLARED_CcMotHysterUp	CcMotHysterUp
extern float CcMotHysterUp;

/* 0=0, 1=5, 2=10, 3=15... 7=50, kmh intval=realval */
#define DECLARED_CcRsrConvertSpeed	CcRsrConvertSpeed
extern uint8_t CcRsrConvertSpeed[8];

/* Set Speed offset intval=realval */
#define DECLARED_CcSetSpeedOffset	CcSetSpeedOffset
extern float CcSetSpeedOffset;

/* Error Speed = [-4,-3,-2,-1,0,1,2,3,4,5,6,7,10,13,15,16,17,18,20,22,25] intval=realval */
#define DECLARED_CcSpeedAccelGain	CcSpeedAccelGain
extern float CcSpeedAccelGain[21];

/* Rate Limiter Accel Up intval=realval */
#define DECLARED_CcSpeedAccelRateUp	CcSpeedAccelRateUp
extern float CcSpeedAccelRateUp;

/* Rate Limiter Decel Up intval=realval */
#define DECLARED_CcSpeedDecelRateUp	CcSpeedDecelRateUp
extern float CcSpeedDecelRateUp;

/* Rate Limiter Decel Up Override->Active intval=realval */
#define DECLARED_CcSpeedDecelRateUpOver	CcSpeedDecelRateUpOver
extern float CcSpeedDecelRateUpOver;

/* Error Speed = [-36,-35,-25,-24,-15,-12,-9,-6,-5,-4,-3,-2,-1,-0.2,2,3,4,5,6,7,8,9] intval=realval */
#define DECLARED_CcSpeedDecelVar	CcSpeedDecelVar
extern float CcSpeedDecelVar[22];

/* LaterAccel = [0,1,1.2,1.4,1.6,1.8,2,2.2,2.5,3] intval=realval */
#define DECLARED_CcSpeedDecreaseAccelGain	CcSpeedDecreaseAccelGain
extern float CcSpeedDecreaseAccelGain[10];

/* Gain = [2,2.5,3,3.5] intval=realval */
#define DECLARED_CcSpeedIncreaseDecelAdd	CcSpeedIncreaseDecelAdd
extern float CcSpeedIncreaseDecelAdd[4];

/* StepDist in IC intval=realval */
#define DECLARED_CcStepDist	CcStepDist
extern uint8_t CcStepDist;

/* StepSpeed in IC intval=realval */
#define DECLARED_CcStepSpeed	CcStepSpeed
extern float CcStepSpeed;

/* sec intval=realval */
#define DECLARED_CcTimeCycleSpeed	CcTimeCycleSpeed
extern float CcTimeCycleSpeed;

/* sec intval=realval */
#define DECLARED_CcTimeCycleSpeedStart	CcTimeCycleSpeedStart
extern float CcTimeCycleSpeedStart;

/* Time delay when ABS/ESP=1,sec intval=realval */
#define DECLARED_CcTimeDelayAbs	CcTimeDelayAbs
extern float CcTimeDelayAbs;

/* Angle = [-10,-8,0,2,6,8,10] intval=realval */
#define DECLARED_CcVlcAngleCor	CcVlcAngleCor
extern float CcVlcAngleCor[7];

/* Speed kmh = [0,2,2.5,3,8,10,12,14] intval=realval */
#define DECLARED_CcVlcAngleSpeedCor	CcVlcAngleSpeedCor
extern float CcVlcAngleSpeedCor[8];

/* Speed kmh = [0,5,7,10,15,20,25,30,35] intval=realval */
#define DECLARED_CcVlcSpeedCor	CcVlcSpeedCor
extern float CcVlcSpeedCor[9];

/* Deceleration lead car, at which the warning is activated intval=realval */
#define DECLARED_CcWarnDecelLvl1	CcWarnDecelLvl1
extern float CcWarnDecelLvl1;

/* Deceleration lead car, at which the warning is activated intval=realval */
#define DECLARED_CcWarnDecelLvl2	CcWarnDecelLvl2
extern float CcWarnDecelLvl2;

/* The deceleration that Aurus can implement when Prediction time. intval=realval */
#define DECLARED_CcWarnDecelPrognose	CcWarnDecelPrognose
extern float CcWarnDecelPrognose;

/* V_emp = [0,20,40,60,80,100,120,140] intval=realval */
#define DECLARED_CcWarnDistOffset	CcWarnDistOffset
extern float CcWarnDistOffset[8];

/* Prediction time,sec intval=realval */
#define DECLARED_CcWarnTimePrognose	CcWarnTimePrognose
extern float CcWarnTimePrognose;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

