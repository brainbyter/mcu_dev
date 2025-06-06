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

/* 0..1 Change dimamic Time or Fix predict time intval=realval */
#define DECLARED_ChangePredTimeRCTC	ChangePredTimeRCTC
extern uint8_t ChangePredTimeRCTC;

/* 0..3.5 Time Minimum warning  intval=realval */
#define DECLARED_MinTimeWarnRctc	MinTimeWarnRctc
extern float MinTimeWarnRctc;

/* 0..2 Car Gab length intval=realval */
#define DECLARED_RctcCarGab_length	RctcCarGab_length
extern float RctcCarGab_length;

/* 0..2 Car Gab wigth intval=realval */
#define DECLARED_RctcCarGab_wigth	RctcCarGab_wigth
extern float RctcCarGab_wigth;

/* 0..1 Coefficient of Adhesion intval=realval */
#define DECLARED_RCTCMu	RCTCMu
extern float RCTCMu;

/* 0..100 parameter probability perception intval=realval */
#define DECLARED_RctcParamProbal	RctcParamProbal
extern uint8_t RctcParamProbal;

/* 0..0.5 Minimal Time Warning  intval=realval */
#define DECLARED_RctcTimePhonk	RctcTimePhonk
extern float RctcTimePhonk;

/* 0..1.5 time before collision intval=realval */
#define DECLARED_RctcTimeRes	RctcTimeRes
extern float RctcTimeRes;

/* 0..1.5 Time Reaction Driver intval=realval */
#define DECLARED_RtctTimeReactDriver	RtctTimeReactDriver
extern float RtctTimeReactDriver;

/* 0..1  Fix predict time intval=realval */
#define DECLARED_TimeFixRCTC	TimeFixRCTC
extern uint8_t TimeFixRCTC;

/* 0..3.5 Time Maximum predict intval=realval */
#define DECLARED_timeMaxRCTC	timeMaxRCTC
extern float timeMaxRCTC;

/* 0..3.5 Time Minimum predict  intval=realval */
#define DECLARED_timeMinRCTC	timeMinRCTC
extern float timeMinRCTC;

/* 0..100 Vmax our car  intval=realval */
#define DECLARED_VmaxRCTC	VmaxRCTC
extern float VmaxRCTC;

/* 0..100 Vmin our car intval=realval */
#define DECLARED_VminRCTC	VminRCTC
extern float VminRCTC;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

