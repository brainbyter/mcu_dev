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
float BlinkPerdTurnSig = 0.8;

/* 0..3 [s] The period of blinking of the led on the side rearview mirror intval=realval */
float BlinkPeriod = 0.4;

/* 0..1 CheckMode = 0 - LEDs work normal, = 1 - LEDs always blink intval=realval */
uint8_t BlinkPeriodCheckMode = 0U;

/* 0..1 [m] Ширина гистерезиса по выходу из зоны BSW через заднюю линию intval=realval */
float BswBackLineHystWidth = 0.4;

/* 0..1 [m] Ширина гистерезиса по выходу из зоны BSW через близкую боковую линию intval=realval */
float BswCloseLineHystWidth = 0.4;

/* 0..1 1 - BSW enable, 0 - BSW disable intval=realval */
uint8_t BswEnableServiceParam = 1U;

/* 0..1 [m] Ширина гистерезиса по выходу из зоны BSW через дальнюю боковую линию intval=realval */
float BswFarLineHystWidth = 0.2;

/* -10..10 [m/s] If main car speed exceeds Vx of the target object by a set value or more, then BSW is not triggered. intval=realval */
float BswMaxDeltaSpeed = 2.0;

/* -10..10 [m] The distance from overall side edge of the car without mirrors to close line of BSW zone intval=realval */
float BswSideEdgeToCloseLine = 0.0000000E+000;

/* -100..100 [m] The length of the BSW zone BEHIND the vehicle in CLOSE mode intval=realval */
float BswZoneLenClose = 2.0;

/* -100..100 [m] The length of the BSW zone BEHIND the vehicle in FAR mode intval=realval */
float BswZoneLenFar = 4.0;

/* -100..100 [m] The length of the BSW zone BEHIND the vehicle in MEDIUM mode intval=realval */
float BswZoneLenMedium = 3.0;

/* -100..100 [m] The width of the BSW zone intval=realval */
float BswZoneWidth = 3.14;

/* 0..100 [m] Overall length of the Limousine intval=realval */
float CarLength_Limo = 6.653;

/* 0..100 [m] Overall length of the Sedan intval=realval */
float CarLength_Sedan = 5.631;

/* 0..100 [m] Overall width of the car intval=realval */
float CarWidth = 2.326;

/* 0..100 [m] Overall width of the car without side mirrors intval=realval */
float CarWidthWithoutMirrors = 2.02;

/* 0..10 [s] The time of the CVW alarm before the collision in CLOSE mode intval=realval */
float CvwAlarmTimeClose = 2.5;

/* 0..10 [s] The time of the CVW alarm before the collision in FAR mode intval=realval */
float CvwAlarmTimeFar = 4.5;

/* 0..10 [s] The time of the CVW alarm before the collision in MEDIUM mode intval=realval */
float CvwAlarmTimeMedium = 3.5;

/* 0..1 [m] Ширина гистерезиса по выходу из зоны CVW через близкую боковую линию intval=realval */
float CvwCloseLineHystWidth = 0.4;

/* 0..1 1 - CVW enable, 0 - CVW disable intval=realval */
uint8_t CvwEnableServiceParam = 1U;

/* 0..1 [m] Ширина гистерезиса по выходу из зоны CVW через дальнюю боковую линию intval=realval */
float CvwFarLineHystWidth = 0.2;

/* 0..200 [m] The distance during which the CVW does not send a warning when switching from curved to straight motion intval=realval */
float CvwFreezeDistAfterCurv = 10.0;

/* 0..20 [s] The time during which the CVW does not send a warning when switching from curved to straight motion intval=realval */
float CvwFreezeTimeAfterCurv = 3.0;

/* 0..500000 [m] The minimum radius of curvature at which the CVW algorithm for straight-line movement is used intval=realval */
float CvwMinRCurvForStraightAlg = 500.0;

/* -5..5 [m] The distance from overall side edge of the car without mirrors to close line of CVW zone intval=realval */
float CvwSideEdgeToCloseLine = 0.0000000E+000;

/* 0..10 [m] The width of the CVW zone intval=realval */
float CvwZoneWidth = 3.14;

/* 0..20 [s] The time of the DOW alarm before the collision intval=realval */
float DowAlarmTime = 4.5;

/* 0..10 [s] The time during which sending DOW warning signal is blocked after falling edge of DOW warning signal intval=realval */
float DowBlockWarnTime = 1.0;

/* 0..2 [s] Time delay on falling edge of warning from DOW. At this time, the notification continues to be requested, but DOW do not have warning. intval=realval */
float DowDelayTimeOnFallEdge = 0.399;

/* 0..2 [s] Time delay on rising edge of warning from DOW. At this time, the notification does not request, but DOW do have warning. intval=realval */
float DowDelayTimeOnRisingEdge = 0.199;

/* 0..255 [km/h] The maximum vehicle speed at which DOW active intval=realval */
float DowMaxSpd = 1.1;

/* 0..10 [s] Minimum DOW warning signal time intval=realval */
float DowMinWarnTime = 1.0;

/* -5..5 [m] The distance from overall side edge of the car without mirrors to close line of DOW zone. If the value increases, the line goes farther from X axis. intval=realval */
float DowSideEdgeToCloseLine = -0.01;

/* -5..10 [m] The distance from trailing edge of the car to DOW front line. If the value increases, the line goes back. intval=realval */
float DowTrailingEdgeToFrontLineDist = 1.0;

/* 0..10 [m] The width of the DOW zone intval=realval */
float DowZoneWidth = 3.15;

/* 0..10 [s] The time during which sending LCC warning signal is blocked after falling edge of LCC warning signal intval=realval */
float LccBlockWarnTime = 1.0;

/* 0..2 [s] Time delay on falling edge of warning from BSW or CVW. At this time, the notification continues to be requested, but BSW and CVW do not have warning. intval=realval */
float LccDelayTimeOnFallEdge = 0.199;

/* 0..2 [s] Time delay on rising edge of warning from BSW or CVW. At this time, the notification does not request, but BSW or CVW do have warning. intval=realval */
float LccDelayTimeOnRisingEdge = 0.199;

/* 0..100 [%] The minimum probability that an object exists for LCC and DOW intval=realval */
uint8_t LccMinProblty = 60U;

/* 0..255 [km/h] The minimum vehicle speed at which LCC active intval=realval */
uint8_t LccMinSpd = 15U;

/* 0..10 [s] Minimum LCC warning signal time intval=realval */
float LccMinWarnTime = 1.5;

/* 0..209 [m] Marking line y coordinate value which means marking line not found. If LCC get this value +- 0.1, LCC assumes that the marking line has not been detected at concrete distance. intval=realval */
float markLineNotExistValue = 202.0;

/* [m] x coordinates array of marking line intval=realval */
float X_MarkLineRear[7] = { 0.0000000E+000, -5.0, -10.0, -20.0, -30.0, -40.0, -50.0 };

/* -100..100 [m] The x coordinate of the point SgRP on the Limousine intval=realval */
float x_Sgrp_Limo = 2.729;

/* -100..100 [m] The x coordinate of the point SgRP on the Sedan intval=realval */
float x_Sgrp_Sedan = 1.726;

/* -100..100 [m] The x coordinate of the trailing edge of the car intval=realval */
float x_TrailEdge = -1.35;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

