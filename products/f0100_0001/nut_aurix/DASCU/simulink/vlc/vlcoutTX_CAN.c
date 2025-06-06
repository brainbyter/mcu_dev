/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>
#include <vlcoutTX_CAN.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* 0..1 The power plant torque control intval=realval */
uint8_t AccTrqAvailable = 0U;

/* -30000..30000 [Nm] The requested torque to engine intval=realval */
float AccTrqReq = 0.0000000E+000;

/* -2..2 Estimated gsinus of road grade with offset intval=realval */
float AngEstimate = 0.0000000E+000;

/* 0..1 Approval from VLC for DrizveOff intval=realval */
uint8_t BrakeReleaseReq = 0U;

/* 0..100 The plausibility counter of deceleration control by engine intval=realval */
uint8_t DecelPlausblCount = 0U;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

