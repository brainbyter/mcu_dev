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
uint8_t ChangePredTimeRCTC = 1U;

/* 0..3.5 Time Minimum warning  intval=realval */
float MinTimeWarnRctc = 1.5;

/* 0..2 Car Gab length intval=realval */
float RctcCarGab_length = 0.1;

/* 0..2 Car Gab wigth intval=realval */
float RctcCarGab_wigth = 0.0000000E+000;

/* 0..1 Coefficient of Adhesion intval=realval */
float RCTCMu = 0.9;

/* 0..100 parameter probability perception intval=realval */
uint8_t RctcParamProbal = 80U;

/* 0..0.5 Minimal Time Warning  intval=realval */
float RctcTimePhonk = 0.15;

/* 0..1.5 time before collision intval=realval */
float RctcTimeRes = 0.1;

/* 0..1.5 Time Reaction Driver intval=realval */
float RtctTimeReactDriver = 1.0;

/* 0..1  Fix predict time intval=realval */
uint8_t TimeFixRCTC = 1U;

/* 0..3.5 Time Maximum predict intval=realval */
float timeMaxRCTC = 3.0;

/* 0..3.5 Time Minimum predict  intval=realval */
float timeMinRCTC = 1.5;

/* 0..100 Vmax our car  intval=realval */
float VmaxRCTC = 15.0;

/* 0..100 Vmin our car intval=realval */
float VminRCTC = 0.0000000E+000;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

