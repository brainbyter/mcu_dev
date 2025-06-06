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
#define DECLARED_AccelPosMax	AccelPosMax
extern float AccelPosMax;

/* 0..1 Availability of AVOID block: 0-off, 1-avail intval=realval */
#define DECLARED_AvoidanceAvail	AvoidanceAvail
extern uint8_t AvoidanceAvail;

/* 1..3 Distance between outer sides of the front axle tires, m intval=realval */
#define DECLARED_B_OutsideFront	B_OutsideFront
extern float B_OutsideFront;

/* 1..200 Maximum brake pressure in the master cylinder at which warning is available, bar intval=realval */
#define DECLARED_BrakePressMax	BrakePressMax
extern float BrakePressMax;

/* 0..1 Availability of CORRECTION_WARN_LINE block: 0-off, 1-avail intval=realval */
#define DECLARED_CorrectionAvail	CorrectionAvail
extern uint8_t CorrectionAvail;

/* 0.1..4 Delay after ABS/VDC/AEB/FCW (increase active danger time), s intval=realval */
#define DECLARED_DealyDangerTime	DealyDangerTime
extern float DealyDangerTime;

/* 0.1..4 Delay after avoid conditions stop (increase active avoid time), s intval=realval */
#define DECLARED_DelayAvoidTime	DelayAvoidTime
extern float DelayAvoidTime;

/* 0.1..4 Delay after blocking conditions stop (increase active blocking time), s intval=realval */
#define DECLARED_DelayBlockTime	DelayBlockTime
extern float DelayBlockTime;

/* 0.1..4 Delay after correction conditions stop (increase active correction time), s intval=realval */
#define DECLARED_DelayCorrTime	DelayCorrTime
extern float DelayCorrTime;

/* 0.1..10 Minimum delay between warnings, s intval=realval */
#define DECLARED_DelayWarnTime	DelayWarnTime
extern float DelayWarnTime;

/* 0..0.5 Hysteresis for IN_LANE_POSITION, m. (! DeltaPos > WarnLine_X !) intval=realval */
#define DECLARED_DeltaPos	DeltaPos
extern float DeltaPos;

/* 0..1 Increase prediction time for PREDICTION block (PredictTime = Ts + IncPredictTime), s intval=realval */
#define DECLARED_IncPredictTime	IncPredictTime
extern float IncPredictTime;

/* 0.1..10 Delay of prohibition of opposite warning, s intval=realval */
#define DECLARED_LdwDelayOppBlockWarnTime	LdwDelayOppBlockWarnTime
extern float LdwDelayOppBlockWarnTime;

/* 0.1..4 Change LdwMode IC indicator delay, s intval=realval */
#define DECLARED_LdwIndicatorDelay	LdwIndicatorDelay
extern float LdwIndicatorDelay;

/* 0..1 Light version LDW - active with 2 lines only intval=realval */
#define DECLARED_LdwLightMode	LdwLightMode
extern uint8_t LdwLightMode;

/* 0..10 SxFA difference Moving average filter reset, % intval=realval */
#define DECLARED_LdwMaDiffResetFilter	LdwMaDiffResetFilter
extern float LdwMaDiffResetFilter;

/* 0..1 Moving average filter available: 0-off, 1-avail intval=realval */
#define DECLARED_LdwMaFilterAvail	LdwMaFilterAvail
extern uint8_t LdwMaFilterAvail;

/* 1..1000 Moving average filter window size (for SxFA point) intval=realval */
#define DECLARED_LdwMaWindowSize	LdwMaWindowSize
extern float LdwMaWindowSize;

/* 0..3 Maximum distance between line and outer side of the front axle tire for IN_LANE_POSITION, m intval=realval */
#define DECLARED_MaxLineDist	MaxLineDist
extern float MaxLineDist;

/* 0..1.5 Maximum distance between line and outer side of the front axle tire at which warning is available, m. (FOR FUNC CALIBRATION) intval=realval */
#define DECLARED_MaxWarnDist	MaxWarnDist
extern float MaxWarnDist;

/* 0.01..2 TTLC at which warning is activated (Before crossing mode + AVOID), s intval=realval */
#define DECLARED_MinTLC_Avoid	MinTLC_Avoid
extern float MinTLC_Avoid;

/* 0.001..2 TTLC at which warning is activated (Before crossing mode), s intval=realval */
#define DECLARED_MinTLC_BeforeCross	MinTLC_BeforeCross
extern float MinTLC_BeforeCross;

/* 0.001..2 TTLC at which warning is activated (While crossing mode), s intval=realval */
#define DECLARED_MinTLC_WhileCross	MinTLC_WhileCross
extern float MinTLC_WhileCross;

/* 0.1..4 Warning duration, s intval=realval */
#define DECLARED_MinWarnTime	MinWarnTime
extern float MinWarnTime;

/* 0..1 Availability of PREDICTION block: 0-off, 1-avail intval=realval */
#define DECLARED_PredictionAvail	PredictionAvail
extern uint8_t PredictionAvail;

/* -0.5..0.5 Zone offset inside the lane for the prediction block, m intval=realval */
#define DECLARED_PredictZone	PredictZone
extern float PredictZone;

/* 1..300 Maximum steering wheel rotation speed at which warning is available, deg/s intval=realval */
#define DECLARED_SasSpdMax	SasSpdMax
extern float SasSpdMax;

/* 0..75 Speed at which LDW state changes to standby, kmh intval=realval */
#define DECLARED_SpeedActiveLdw_off	SpeedActiveLdw_off
extern float SpeedActiveLdw_off;

/* 0..80 Speed at which LDW state changes to active, kmh intval=realval */
#define DECLARED_SpeedActiveLdw_on	SpeedActiveLdw_on
extern float SpeedActiveLdw_on;

/* -0.2..0.5 Offset of the warning line to the inside of the turn (correction), m intval=realval */
#define DECLARED_TurnExtWarnLine	TurnExtWarnLine
extern float TurnExtWarnLine;

/* 0..1000 Turning radius for correction, m intval=realval */
#define DECLARED_TurningRadius	TurningRadius
extern float TurningRadius;

/* 0.1..2 Delay after turn signal off (for TURN_SIGNAL_MANAGER), s intval=realval */
#define DECLARED_TurnSigTime	TurnSigTime
extern float TurnSigTime;

/* 0.1..1000 Maximum lateral departure speed at which warning is available, m/s intval=realval */
#define DECLARED_VdepartMax	VdepartMax
extern float VdepartMax;

/* -0.2..0.5 First warning line (Before crossing mode), m. (! WarnLine_X < DeltaPos !) intval=realval */
#define DECLARED_WarnLine_BeforeCross	WarnLine_BeforeCross
extern float WarnLine_BeforeCross;

/* -0.2..0.5 First warning line (While crossing mode), m. (! WarnLine_X < DeltaPos !) intval=realval */
#define DECLARED_WarnLine_WhileCross	WarnLine_WhileCross
extern float WarnLine_WhileCross;

/* 3..5 Distance between front and rear axles, m intval=realval */
#define DECLARED_Wheelbase	Wheelbase
extern float Wheelbase;

/* -10..0 Minimum rate of change of YawRate at which MinTLC = MinTLC_BeforeCross (if YawRate_dt < YawRate_dtMin_Avoid => MinTLC = MinTLC_Avoid), deg/s^2 intval=realval */
#define DECLARED_YawRate_dtMin_Avoid	YawRate_dtMin_Avoid
extern float YawRate_dtMin_Avoid;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

