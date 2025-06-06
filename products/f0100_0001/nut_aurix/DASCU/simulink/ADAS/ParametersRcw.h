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

/* 0..10 Coefficient Dinamic gab intval=realval */
#define DECLARED_CoefDinamGab	CoefDinamGab
extern float CoefDinamGab;

/* 0..2 Minimum Dinamic gab intval=realval */
#define DECLARED_MinDinamGab	MinDinamGab
extern float MinDinamGab;

/* 0..10 Minimal Time Warning intval=realval */
#define DECLARED_MinTimeWarn	MinTimeWarn
extern float MinTimeWarn;

/* 0..100 parameter probability perception intval=realval */
#define DECLARED_ParamProbal	ParamProbal
extern uint8_t ParamProbal;

/* 0..1 Enable RCW Off or On 12 and 14 object intval=realval */
#define DECLARED_RCW_12_14_Stat	RCW_12_14_Stat
extern uint8_t RCW_12_14_Stat;

/* 0..1 Enable RCW Off or On intval=realval */
#define DECLARED_RCW_Stat	RCW_Stat
extern uint8_t RCW_Stat;

/* 0..2 Car Gab intval=realval */
#define DECLARED_RCWCarGab	RCWCarGab
extern float RCWCarGab;

/* 0..1 Coefficient of Adhesion intval=realval */
#define DECLARED_RCWMu	RCWMu
extern float RCWMu;

/* 0.05..1.5 Driver reaction angular velocity intval=realval */
#define DECLARED_RCWWsteer	RCWWsteer
extern float RCWWsteer;

/* 0..1.5 Time Brakes intval=realval */
#define DECLARED_TimeBrake	TimeBrake
extern float TimeBrake;

/* 0..300 Time Over Break Point intval=realval */
#define DECLARED_TimeOverBkPoint	TimeOverBkPoint
extern float TimeOverBkPoint[21];

/* 0..3 Time Over Table Data intval=realval */
#define DECLARED_TimeOverTbData	TimeOverTbData
extern float TimeOverTbData[21];

/* 0..1.5 Time Reaction Driver intval=realval */
#define DECLARED_TimeReactDriver	TimeReactDriver
extern float TimeReactDriver;

/* 0..4.5 time before collision 12 object intval=realval */
#define DECLARED_TimeReq12	TimeReq12
extern float TimeReq12;

/* 0..4.5 time before collision 13 object intval=realval */
#define DECLARED_TimeReq13	TimeReq13
extern float TimeReq13;

/* 0..4.5 time before collision 14 object intval=realval */
#define DECLARED_TimeReq14	TimeReq14
extern float TimeReq14;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

