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
#define DECLARED_AAIcOrErag	AAIcOrErag
extern uint8_t AAIcOrErag;

/* 0..1 On/Off plus Time for chash IC absolute time intval=realval */
#define DECLARED_AAIcPastOrNow	AAIcPastOrNow
extern uint8_t AAIcPastOrNow;

/* 0..2 Minimal Time Limiter Warn AA intval=realval */
#define DECLARED_AAMinimalTimeLimiter	AAMinimalTimeLimiter
extern float AAMinimalTimeLimiter;

/* 0..10 Minimal Time Normal Mode intval=realval */
#define DECLARED_AANormalModeTime	AANormalModeTime
extern float AANormalModeTime;

/* 0..10 Minimal Time Sensetive Mode intval=realval */
#define DECLARED_AASensetiveModeTime	AASensetiveModeTime
extern float AASensetiveModeTime;

/* 0..1 Add Dms for AA logic intval=realval */
#define DECLARED_AASwitchDms	AASwitchDms
extern uint8_t AASwitchDms;

/* 0..15 Add Time for fuzzy logic Realise intval=realval */
#define DECLARED_AATimeAddMinTime	AATimeAddMinTime
extern float AATimeAddMinTime;

/* 0..15 Add Time for fuzzy logic Test intval=realval */
#define DECLARED_AATimeAddTest	AATimeAddTest
extern float AATimeAddTest;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

