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

/* Time for holding the speed sign when vehicle speed more, sec intval=realval */
float TsrLeftPotTime = 10.0;

/* 20..50 Lower limit for speed offset of start timer TsrLeftPotTime on speed sign keeping intval=realval */
float TsrLowLimit = 25.0;

/* 2..8 Time for display all signs except for OverTakeTaboo in right pot, sec intval=realval */
float TsrRightPotTime = 3.0;

/* 20..50 Upper limit for speed offset on speed sign dumping intval=realval */
float TsrUpLimit = 50.0;

/* Signal imitate from message IC_ADAS_REST of signal VisualActReq intval=realval */
uint8_t VisActReq = 1U;

/* Meters intval=realval */
float VisCarWidth = 1.9;

/* Number of microzones for traffic zones in the center of the marking line intval=realval */
float VisEdgeZones = 6.0;

/* Minimal value of objects probability intval=realval */
uint8_t VisMinObjProb = 60U;

/* Number of microzones in one traffic lane, only an even number!!! intval=realval */
float VisNumMicroZone = 30.0;

/* 0..4 Hysteresis for object intval=realval */
float VisObjHyster = 3.0;

/* Number of microzones for offset traffic areas intval=realval */
float VisOffsetZones = 5.0;

/* Meters intval=realval */
float VisPedWidth = 0.4;

/* Meters intval=realval */
float VisTruckWidth = 2.6;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

