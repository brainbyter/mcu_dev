/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* 0..1 The power plant torque control intval=realval */
#define DECLARED_AccTrqAvailable	AccTrqAvailable
extern uint8_t AccTrqAvailable;

/* -30000..30000 [Nm] The requested torque to engine intval=realval */
#define DECLARED_AccTrqReq	AccTrqReq
extern float AccTrqReq;

/* -2..2 Estimated gsinus of road grade with offset intval=realval */
#define DECLARED_AngEstimate	AngEstimate
extern float AngEstimate;

/* 0..1 Approval from VLC for DrizveOff intval=realval */
#define DECLARED_BrakeReleaseReq	BrakeReleaseReq
extern uint8_t BrakeReleaseReq;

/* 0..100 The plausibility counter of deceleration control by engine intval=realval */
#define DECLARED_DecelPlausblCount	DecelPlausblCount
extern uint8_t DecelPlausblCount;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

