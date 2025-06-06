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
float CcDistA[4] = { 2.8129001E-004, 3.8079999E-004, 4.8079999E-004, 4.8079999E-004 };

/* Angle =[-10,-8,-6,-4,-2,0,2,4,6,7] intval=realval */
float CcDistAngle[10] = { 3.0, 2.8155, 2.5223, 1.8034, 0.98986, 0.28243, -0.033784, -0.27365, -0.48986, -0.5 };

/* [0,1,2,3] intval=realval */
float CcDistB[4] = { 0.1852874, 0.2748062, 0.3722819, 0.4722819 };

/* [0,1,2,3] intval=realval */
float CcDistC[4] = { 8.0, 8.0, 9.0, 10.0 };

/* sec intval=realval */
float CcDrTakeMinTime = 2.0;

/* sec intval=realval */
float CcDrTakeTimeDelay1 = 0.3;

/* sec intval=realval */
float CcDrTakeTimeDelay2 = 0.5;

/* Error speed = [-10,0,10,20,30,40,50] intval=realval */
float CcLimGain[7] = { 1.0, 1.0, 1.0, 2.0, 3.0, 4.0, 4.0 };

/* Lower limit of acceleration for LIM, m/s2 intval=realval */
float CcLimSaturLow = -1.0;

/* Upper limit of acceleration for LIM, m/s2 intval=realval */
float CcLimSaturUp = 7.0;

/* MaxDist in IC intval=realval */
uint8_t CcMaxDist = 3U;

/* kmh intval=realval */
float CcMaxSpeed = 250.0;

/* MinDist in IC intval=realval */
uint8_t CcMinDist = 0U;

/* kmh intval=realval */
float CcMinSpeed = 20.0;

/* [-10,-8,-6,-4,-2,0,2,4,6,7] intval=realval */
float CcMMotDovAngle[10] = { 3.0, 2.8155, 2.5223, 1.8034, 0.98986, 0.28243, -0.033784, -0.27365, -0.48986, -0.5 };

/* Lower limit of driver torque and ADAS torque difference, N*m intval=realval */
float CcMotHysterLow = 0.0000000E+000;

/* Upper limit of driver torque and ADAS torque difference, N*m intval=realval */
float CcMotHysterUp = 50.0;

/* 0=0, 1=5, 2=10, 3=15... 7=50, kmh intval=realval */
uint8_t CcRsrConvertSpeed[8] = { 0U, 5U, 10U, 15U, 20U, 30U, 40U, 50U };

/* Set Speed offset intval=realval */
float CcSetSpeedOffset = 0.5;

/* Error Speed = [-4,-3,-2,-1,0,1,2,3,4,5,6,7,10,13,15,16,17,18,20,22,25] intval=realval */
float CcSpeedAccelGain[21] = { 0.0000000E+000, 0.0000000E+000, 0.0000000E+000, 0.0000000E+000, 0.023142, 0.12197, 0.21765, 0.30121, 0.35782, 0.40633, 0.44811, 0.49259, 0.6031, 0.75611, 0.84434, 0.88247, 0.91236, 0.9409, 0.97911, 1.0, 1.0 };

/* Rate Limiter Accel Up intval=realval */
float CcSpeedAccelRateUp = 0.7;

/* Rate Limiter Decel Up intval=realval */
float CcSpeedDecelRateUp = 0.4;

/* Rate Limiter Decel Up Override->Active intval=realval */
float CcSpeedDecelRateUpOver = 0.03;

/* Error Speed = [-36,-35,-25,-24,-15,-12,-9,-6,-5,-4,-3,-2,-1,-0.2,2,3,4,5,6,7,8,9] intval=realval */
float CcSpeedDecelVar[22] = { 1.3, 1.3, 1.0651, 1.0357, 0.83601, 0.75802, 0.6572, 0.50503, 0.44635, 0.39171, 0.32338, 0.24075, 0.15335, 0.0000000E+000, 0.0000000E+000, 0.0000000E+000, 0.0000000E+000, 0.0000000E+000, 0.0000000E+000, 0.0000000E+000, 0.0000000E+000, 0.0000000E+000 };

/* LaterAccel = [0,1,1.2,1.4,1.6,1.8,2,2.2,2.5,3] intval=realval */
float CcSpeedDecreaseAccelGain[10] = { 1.0, 1.0, 0.79517, 0.65, 0.51216, 0.38784, 0.26892, 0.15, 0.0000000E+000, 0.0000000E+000 };

/* Gain = [2,2.5,3,3.5] intval=realval */
float CcSpeedIncreaseDecelAdd[4] = { 0.0000000E+000, 0.0000000E+000, 0.5, 0.5 };

/* StepDist in IC intval=realval */
uint8_t CcStepDist = 1U;

/* StepSpeed in IC intval=realval */
float CcStepSpeed = 10.0;

/* sec intval=realval */
float CcTimeCycleSpeed = 0.6;

/* sec intval=realval */
float CcTimeCycleSpeedStart = 0.7;

/* Time delay when ABS/ESP=1,sec intval=realval */
float CcTimeDelayAbs = 0.2;

/* Angle = [-10,-8,0,2,6,8,10] intval=realval */
float CcVlcAngleCor[7] = { 0.0000000E+000, 0.0000000E+000, 0.0000000E+000, 0.2, 0.6, 0.8, 1.0 };

/* Speed kmh = [0,2,2.5,3,8,10,12,14] intval=realval */
float CcVlcAngleSpeedCor[8] = { 0.3, 0.19984, 0.16887, 0.13403, 0.016539, 2.7989999E-003, 0.0000000E+000, 0.0000000E+000 };

/* Speed kmh = [0,5,7,10,15,20,25,30,35] intval=realval */
float CcVlcSpeedCor[9] = { 0.0000000E+000, 0.10858, 0.11206, 0.11361, 0.11516, 0.11323, 0.05671, 0.0000000E+000, 0.0000000E+000 };

/* Deceleration lead car, at which the warning is activated intval=realval */
float CcWarnDecelLvl1 = -3.3;

/* Deceleration lead car, at which the warning is activated intval=realval */
float CcWarnDecelLvl2 = -3.7;

/* The deceleration that Aurus can implement when Prediction time. intval=realval */
float CcWarnDecelPrognose = -1.15;

/* V_emp = [0,20,40,60,80,100,120,140] intval=realval */
float CcWarnDistOffset[8] = { 2.5081, 2.5242, 3.0355, 3.771, 5.019, 6.0034, 8.0, 8.0 };

/* Prediction time,sec intval=realval */
float CcWarnTimePrognose = 3.0;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

