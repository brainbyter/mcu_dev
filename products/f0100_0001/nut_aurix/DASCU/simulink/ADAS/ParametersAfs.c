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

/* 0..1 On/Off Erag Time intval=realval */
uint8_t AAIcOrErag = 0U;

/* 0..1 On/Off plus Time for chash IC absolute time intval=realval */
uint8_t AAIcPastOrNow = 1U;

/* 0..2 Minimal Time Limiter Warn AA intval=realval */
float AAMinimalTimeLimiter = 1.5;

/* 0..10 Minimal Time Normal Mode intval=realval */
float AANormalModeTime = 5.5;

/* 0..10 Minimal Time Sensetive Mode intval=realval */
float AASensetiveModeTime = 4.5;

/* 0..1 Add Dms for AA logic intval=realval */
uint8_t AASwitchDms = 0U;

/* 0..15 Add Time for fuzzy logic Realise intval=realval */
float AATimeAddMinTime = 0.0000000E+000;

/* 0..15 Add Time for fuzzy logic Test intval=realval */
float AATimeAddTest = 6.0;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

