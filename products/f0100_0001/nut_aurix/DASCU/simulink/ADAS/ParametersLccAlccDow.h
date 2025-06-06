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

/* 0..3 [s] The period of blinking of the turn signal intval=realval */
#define DECLARED_BlinkPerdTurnSig	BlinkPerdTurnSig
extern float BlinkPerdTurnSig;

/* 0..3 [s] The period of blinking of the led on the side rearview mirror intval=realval */
#define DECLARED_BlinkPeriod	BlinkPeriod
extern float BlinkPeriod;

/* 0..1 CheckMode = 0 - LEDs work normal, = 1 - LEDs always blink intval=realval */
#define DECLARED_BlinkPeriodCheckMode	BlinkPeriodCheckMode
extern uint8_t BlinkPeriodCheckMode;

/* 0..1 [m] Ширина гистерезиса по выходу из зоны BSW через заднюю линию intval=realval */
#define DECLARED_BswBackLineHystWidth	BswBackLineHystWidth
extern float BswBackLineHystWidth;

/* 0..1 [m] Ширина гистерезиса по выходу из зоны BSW через близкую боковую линию intval=realval */
#define DECLARED_BswCloseLineHystWidth	BswCloseLineHystWidth
extern float BswCloseLineHystWidth;

/* 0..1 1 - BSW enable, 0 - BSW disable intval=realval */
#define DECLARED_BswEnableServiceParam	BswEnableServiceParam
extern uint8_t BswEnableServiceParam;

/* 0..1 [m] Ширина гистерезиса по выходу из зоны BSW через дальнюю боковую линию intval=realval */
#define DECLARED_BswFarLineHystWidth	BswFarLineHystWidth
extern float BswFarLineHystWidth;

/* -10..10 [m/s] If main car speed exceeds Vx of the target object by a set value or more, then BSW is not triggered. intval=realval */
#define DECLARED_BswMaxDeltaSpeed	BswMaxDeltaSpeed
extern float BswMaxDeltaSpeed;

/* -10..10 [m] The distance from overall side edge of the car without mirrors to close line of BSW zone intval=realval */
#define DECLARED_BswSideEdgeToCloseLine	BswSideEdgeToCloseLine
extern float BswSideEdgeToCloseLine;

/* -100..100 [m] The length of the BSW zone BEHIND the vehicle in CLOSE mode intval=realval */
#define DECLARED_BswZoneLenClose	BswZoneLenClose
extern float BswZoneLenClose;

/* -100..100 [m] The length of the BSW zone BEHIND the vehicle in FAR mode intval=realval */
#define DECLARED_BswZoneLenFar	BswZoneLenFar
extern float BswZoneLenFar;

/* -100..100 [m] The length of the BSW zone BEHIND the vehicle in MEDIUM mode intval=realval */
#define DECLARED_BswZoneLenMedium	BswZoneLenMedium
extern float BswZoneLenMedium;

/* -100..100 [m] The width of the BSW zone intval=realval */
#define DECLARED_BswZoneWidth	BswZoneWidth
extern float BswZoneWidth;

/* 0..100 [m] Overall length of the Limousine intval=realval */
#define DECLARED_CarLength_Limo	CarLength_Limo
extern float CarLength_Limo;

/* 0..100 [m] Overall length of the Sedan intval=realval */
#define DECLARED_CarLength_Sedan	CarLength_Sedan
extern float CarLength_Sedan;

/* 0..100 [m] Overall width of the car intval=realval */
#define DECLARED_CarWidth	CarWidth
extern float CarWidth;

/* 0..100 [m] Overall width of the car without side mirrors intval=realval */
#define DECLARED_CarWidthWithoutMirrors	CarWidthWithoutMirrors
extern float CarWidthWithoutMirrors;

/* 0..10 [s] The time of the CVW alarm before the collision in CLOSE mode intval=realval */
#define DECLARED_CvwAlarmTimeClose	CvwAlarmTimeClose
extern float CvwAlarmTimeClose;

/* 0..10 [s] The time of the CVW alarm before the collision in FAR mode intval=realval */
#define DECLARED_CvwAlarmTimeFar	CvwAlarmTimeFar
extern float CvwAlarmTimeFar;

/* 0..10 [s] The time of the CVW alarm before the collision in MEDIUM mode intval=realval */
#define DECLARED_CvwAlarmTimeMedium	CvwAlarmTimeMedium
extern float CvwAlarmTimeMedium;

/* 0..1 [m] Ширина гистерезиса по выходу из зоны CVW через близкую боковую линию intval=realval */
#define DECLARED_CvwCloseLineHystWidth	CvwCloseLineHystWidth
extern float CvwCloseLineHystWidth;

/* 0..1 1 - CVW enable, 0 - CVW disable intval=realval */
#define DECLARED_CvwEnableServiceParam	CvwEnableServiceParam
extern uint8_t CvwEnableServiceParam;

/* 0..1 [m] Ширина гистерезиса по выходу из зоны CVW через дальнюю боковую линию intval=realval */
#define DECLARED_CvwFarLineHystWidth	CvwFarLineHystWidth
extern float CvwFarLineHystWidth;

/* 0..200 [m] The distance during which the CVW does not send a warning when switching from curved to straight motion intval=realval */
#define DECLARED_CvwFreezeDistAfterCurv	CvwFreezeDistAfterCurv
extern float CvwFreezeDistAfterCurv;

/* 0..20 [s] The time during which the CVW does not send a warning when switching from curved to straight motion intval=realval */
#define DECLARED_CvwFreezeTimeAfterCurv	CvwFreezeTimeAfterCurv
extern float CvwFreezeTimeAfterCurv;

/* 0..500000 [m] The minimum radius of curvature at which the CVW algorithm for straight-line movement is used intval=realval */
#define DECLARED_CvwMinRCurvForStraightAlg	CvwMinRCurvForStraightAlg
extern float CvwMinRCurvForStraightAlg;

/* -5..5 [m] The distance from overall side edge of the car without mirrors to close line of CVW zone intval=realval */
#define DECLARED_CvwSideEdgeToCloseLine	CvwSideEdgeToCloseLine
extern float CvwSideEdgeToCloseLine;

/* 0..10 [m] The width of the CVW zone intval=realval */
#define DECLARED_CvwZoneWidth	CvwZoneWidth
extern float CvwZoneWidth;

/* 0..20 [s] The time of the DOW alarm before the collision intval=realval */
#define DECLARED_DowAlarmTime	DowAlarmTime
extern float DowAlarmTime;

/* 0..10 [s] The time during which sending DOW warning signal is blocked after falling edge of DOW warning signal intval=realval */
#define DECLARED_DowBlockWarnTime	DowBlockWarnTime
extern float DowBlockWarnTime;

/* 0..2 [s] Time delay on falling edge of warning from DOW. At this time, the notification continues to be requested, but DOW do not have warning. intval=realval */
#define DECLARED_DowDelayTimeOnFallEdge	DowDelayTimeOnFallEdge
extern float DowDelayTimeOnFallEdge;

/* 0..2 [s] Time delay on rising edge of warning from DOW. At this time, the notification does not request, but DOW do have warning. intval=realval */
#define DECLARED_DowDelayTimeOnRisingEdge	DowDelayTimeOnRisingEdge
extern float DowDelayTimeOnRisingEdge;

/* 0..255 [km/h] The maximum vehicle speed at which DOW active intval=realval */
#define DECLARED_DowMaxSpd	DowMaxSpd
extern float DowMaxSpd;

/* 0..10 [s] Minimum DOW warning signal time intval=realval */
#define DECLARED_DowMinWarnTime	DowMinWarnTime
extern float DowMinWarnTime;

/* -5..5 [m] The distance from overall side edge of the car without mirrors to close line of DOW zone. If the value increases, the line goes farther from X axis. intval=realval */
#define DECLARED_DowSideEdgeToCloseLine	DowSideEdgeToCloseLine
extern float DowSideEdgeToCloseLine;

/* -5..10 [m] The distance from trailing edge of the car to DOW front line. If the value increases, the line goes back. intval=realval */
#define DECLARED_DowTrailingEdgeToFrontLineDist	DowTrailingEdgeToFrontLineDist
extern float DowTrailingEdgeToFrontLineDist;

/* 0..10 [m] The width of the DOW zone intval=realval */
#define DECLARED_DowZoneWidth	DowZoneWidth
extern float DowZoneWidth;

/* 0..10 [s] The time during which sending LCC warning signal is blocked after falling edge of LCC warning signal intval=realval */
#define DECLARED_LccBlockWarnTime	LccBlockWarnTime
extern float LccBlockWarnTime;

/* 0..2 [s] Time delay on falling edge of warning from BSW or CVW. At this time, the notification continues to be requested, but BSW and CVW do not have warning. intval=realval */
#define DECLARED_LccDelayTimeOnFallEdge	LccDelayTimeOnFallEdge
extern float LccDelayTimeOnFallEdge;

/* 0..2 [s] Time delay on rising edge of warning from BSW or CVW. At this time, the notification does not request, but BSW or CVW do have warning. intval=realval */
#define DECLARED_LccDelayTimeOnRisingEdge	LccDelayTimeOnRisingEdge
extern float LccDelayTimeOnRisingEdge;

/* 0..100 [%] The minimum probability that an object exists for LCC and DOW intval=realval */
#define DECLARED_LccMinProblty	LccMinProblty
extern uint8_t LccMinProblty;

/* 0..255 [km/h] The minimum vehicle speed at which LCC active intval=realval */
#define DECLARED_LccMinSpd	LccMinSpd
extern uint8_t LccMinSpd;

/* 0..10 [s] Minimum LCC warning signal time intval=realval */
#define DECLARED_LccMinWarnTime	LccMinWarnTime
extern float LccMinWarnTime;

/* 0..209 [m] Marking line y coordinate value which means marking line not found. If LCC get this value +- 0.1, LCC assumes that the marking line has not been detected at concrete distance. intval=realval */
#define DECLARED_markLineNotExistValue	markLineNotExistValue
extern float markLineNotExistValue;

/* [m] x coordinates array of marking line intval=realval */
#define DECLARED_X_MarkLineRear	X_MarkLineRear
extern float X_MarkLineRear[7];

/* -100..100 [m] The x coordinate of the point SgRP on the Limousine intval=realval */
#define DECLARED_x_Sgrp_Limo	x_Sgrp_Limo
extern float x_Sgrp_Limo;

/* -100..100 [m] The x coordinate of the point SgRP on the Sedan intval=realval */
#define DECLARED_x_Sgrp_Sedan	x_Sgrp_Sedan
extern float x_Sgrp_Sedan;

/* -100..100 [m] The x coordinate of the trailing edge of the car intval=realval */
#define DECLARED_x_TrailEdge	x_TrailEdge
extern float x_TrailEdge;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

