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

/* 1..120 Maximum acceleration pedal position at which warning is available, % intval=realval */
float AccelPosMax = 90.0;

/* 0..1 Availability of AVOID block: 0-off, 1-avail intval=realval */
uint8_t AvoidanceAvail = 0U;

/* 1..3 Distance between outer sides of the front axle tires, m intval=realval */
float B_OutsideFront = 1.955;

/* 1..200 Maximum brake pressure in the master cylinder at which warning is available, bar intval=realval */
float BrakePressMax = 80.0;

/* 0..1 Availability of CORRECTION_WARN_LINE block: 0-off, 1-avail intval=realval */
uint8_t CorrectionAvail = 0U;

/* 0.1..4 Delay after ABS/VDC/AEB/FCW (increase active danger time), s intval=realval */
float DealyDangerTime = 1.0;

/* 0.1..4 Delay after avoid conditions stop (increase active avoid time), s intval=realval */
float DelayAvoidTime = 0.9;

/* 0.1..4 Delay after blocking conditions stop (increase active blocking time), s intval=realval */
float DelayBlockTime = 0.5;

/* 0.1..4 Delay after correction conditions stop (increase active correction time), s intval=realval */
float DelayCorrTime = 0.5;

/* 0.1..10 Minimum delay between warnings, s intval=realval */
float DelayWarnTime = 2.5;

/* 0..0.5 Hysteresis for IN_LANE_POSITION, m. (! DeltaPos > WarnLine_X !) intval=realval */
float DeltaPos = 0.25;

/* 0..1 Increase prediction time for PREDICTION block (PredictTime = Ts + IncPredictTime), s intval=realval */
float IncPredictTime = 0.5;

/* 0.1..10 Delay of prohibition of opposite warning, s intval=realval */
float LdwDelayOppBlockWarnTime = 3.0;

/* 0.1..4 Change LdwMode IC indicator delay, s intval=realval */
float LdwIndicatorDelay = 0.5;

/* 0..1 Light version LDW - active with 2 lines only intval=realval */
uint8_t LdwLightMode = 0U;

/* 0..10 SxFA difference Moving average filter reset, % intval=realval */
float LdwMaDiffResetFilter = 0.6;

/* 0..1 Moving average filter available: 0-off, 1-avail intval=realval */
uint8_t LdwMaFilterAvail = 1U;

/* 1..1000 Moving average filter window size (for SxFA point) intval=realval */
float LdwMaWindowSize = 5.0;

/* 0..3 Maximum distance between line and outer side of the front axle tire for IN_LANE_POSITION, m intval=realval */
float MaxLineDist = 2.0;

/* 0..1.5 Maximum distance between line and outer side of the front axle tire at which warning is available, m. (FOR FUNC CALIBRATION) intval=realval */
float MaxWarnDist = 1.5;

/* 0.01..2 TTLC at which warning is activated (Before crossing mode + AVOID), s intval=realval */
float MinTLC_Avoid = 0.2;

/* 0.001..2 TTLC at which warning is activated (Before crossing mode), s intval=realval */
float MinTLC_BeforeCross = 0.5;

/* 0.001..2 TTLC at which warning is activated (While crossing mode), s intval=realval */
float MinTLC_WhileCross = 0.01;

/* 0.1..4 Warning duration, s intval=realval */
float MinWarnTime = 1.5;

/* 0..1 Availability of PREDICTION block: 0-off, 1-avail intval=realval */
uint8_t PredictionAvail = 0U;

/* -0.5..0.5 Zone offset inside the lane for the prediction block, m intval=realval */
float PredictZone = 0.0000000E+000;

/* 1..300 Maximum steering wheel rotation speed at which warning is available, deg/s intval=realval */
float SasSpdMax = 100.0;

/* 0..75 Speed at which LDW state changes to standby, kmh intval=realval */
float SpeedActiveLdw_off = 55.0;

/* 0..80 Speed at which LDW state changes to active, kmh intval=realval */
float SpeedActiveLdw_on = 60.0;

/* -0.2..0.5 Offset of the warning line to the inside of the turn (correction), m intval=realval */
float TurnExtWarnLine = 0.2;

/* 0..1000 Turning radius for correction, m intval=realval */
float TurningRadius = 270.0;

/* 0.1..2 Delay after turn signal off (for TURN_SIGNAL_MANAGER), s intval=realval */
float TurnSigTime = 0.5;

/* 0.1..1000 Maximum lateral departure speed at which warning is available, m/s intval=realval */
float VdepartMax = 1.5;

/* -0.2..0.5 First warning line (Before crossing mode), m. (! WarnLine_X < DeltaPos !) intval=realval */
float WarnLine_BeforeCross = 0.18;

/* -0.2..0.5 First warning line (While crossing mode), m. (! WarnLine_X < DeltaPos !) intval=realval */
float WarnLine_WhileCross = 0.12;

/* 3..5 Distance between front and rear axles, m intval=realval */
float Wheelbase = 3.3;

/* -10..0 Minimum rate of change of YawRate at which MinTLC = MinTLC_BeforeCross (if YawRate_dt < YawRate_dtMin_Avoid => MinTLC = MinTLC_Avoid), deg/s^2 intval=realval */
float YawRate_dtMin_Avoid = -5.0;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

