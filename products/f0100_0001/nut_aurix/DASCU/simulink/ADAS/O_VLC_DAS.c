/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* 0..3 Status of Cruise Control: 0-OFF 1-StandBy 2-Active 3-Override intval=realval */
uint8_t AccActive = 0U;

/* -5..4 [m*s^2] Acceleration request from the ACC function intval=realval */
float AccelReq = 0.0000000E+000;

/* 0..4 Type cruis control 0=Nothign 1=CC 2=ACC SG 3=LIM intval=realval */
uint8_t CruiseControlType = 0U;

/* 0..1 DriveOff request intval=realval */
uint8_t DriveOffReq = 0U;

/* 0..250 [kmh] Скорость целевая в КМЧ приведенная к реальной скорости intval=realval */
float SpeedTarget = 0.0000000E+000;

/* 0..1 Standstill request intval=realval */
uint8_t StandStillReq = 0U;

/* 0..1 Флаг запуска рассчета момента intval=realval */
uint8_t VlcActive = 0U;

/* 0..1 Флаг активации запроса момента intval=realval */
uint8_t VlcTrqActive = 0U;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

