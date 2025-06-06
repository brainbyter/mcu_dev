/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* 0..3 Status of Cruise Control: 0-OFF 1-StandBy 2-Active 3-Override intval=realval */
#define DECLARED_AccActive	AccActive
extern uint8_t AccActive;

/* -5..4 [m*s^2] Acceleration request from the ACC function intval=realval */
#define DECLARED_AccelReq	AccelReq
extern float AccelReq;

/* 0..4 Type cruis control 0=Nothign 1=CC 2=ACC SG 3=LIM intval=realval */
#define DECLARED_CruiseControlType	CruiseControlType
extern uint8_t CruiseControlType;

/* 0..1 DriveOff request intval=realval */
#define DECLARED_DriveOffReq	DriveOffReq
extern uint8_t DriveOffReq;

/* 0..250 [kmh] Скорость целевая в КМЧ приведенная к реальной скорости intval=realval */
#define DECLARED_SpeedTarget	SpeedTarget
extern float SpeedTarget;

/* 0..1 Standstill request intval=realval */
#define DECLARED_StandStillReq	StandStillReq
extern uint8_t StandStillReq;

/* 0..1 Флаг запуска рассчета момента intval=realval */
#define DECLARED_VlcActive	VlcActive
extern uint8_t VlcActive;

/* 0..1 Флаг активации запроса момента intval=realval */
#define DECLARED_VlcTrqActive	VlcTrqActive
extern uint8_t VlcTrqActive;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

