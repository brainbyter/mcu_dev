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
#define DECLARED_TsrLeftPotTime	TsrLeftPotTime
extern float TsrLeftPotTime;

/* 20..50 Lower limit for speed offset of start timer TsrLeftPotTime on speed sign keeping intval=realval */
#define DECLARED_TsrLowLimit	TsrLowLimit
extern float TsrLowLimit;

/* 2..8 Time for display all signs except for OverTakeTaboo in right pot, sec intval=realval */
#define DECLARED_TsrRightPotTime	TsrRightPotTime
extern float TsrRightPotTime;

/* 20..50 Upper limit for speed offset on speed sign dumping intval=realval */
#define DECLARED_TsrUpLimit	TsrUpLimit
extern float TsrUpLimit;

/* Signal imitate from message IC_ADAS_REST of signal VisualActReq intval=realval */
#define DECLARED_VisActReq	VisActReq
extern uint8_t VisActReq;

/* Meters intval=realval */
#define DECLARED_VisCarWidth	VisCarWidth
extern float VisCarWidth;

/* Number of microzones for traffic zones in the center of the marking line intval=realval */
#define DECLARED_VisEdgeZones	VisEdgeZones
extern float VisEdgeZones;

/* Minimal value of objects probability intval=realval */
#define DECLARED_VisMinObjProb	VisMinObjProb
extern uint8_t VisMinObjProb;

/* Number of microzones in one traffic lane, only an even number!!! intval=realval */
#define DECLARED_VisNumMicroZone	VisNumMicroZone
extern float VisNumMicroZone;

/* 0..4 Hysteresis for object intval=realval */
#define DECLARED_VisObjHyster	VisObjHyster
extern float VisObjHyster;

/* Number of microzones for offset traffic areas intval=realval */
#define DECLARED_VisOffsetZones	VisOffsetZones
extern float VisOffsetZones;

/* Meters intval=realval */
#define DECLARED_VisPedWidth	VisPedWidth
extern float VisPedWidth;

/* Meters intval=realval */
#define DECLARED_VisTruckWidth	VisTruckWidth
extern float VisTruckWidth;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

