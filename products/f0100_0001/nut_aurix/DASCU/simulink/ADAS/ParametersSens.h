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

/* Time to refresh the request intval=realval */
#define DECLARED_HcsCycleTime	HcsCycleTime
extern float HcsCycleTime;

/* Delta of temperature for low heat intval=realval */
#define DECLARED_HcsLowDelta	HcsLowDelta
extern float HcsLowDelta;

/* Delta of temperature for medium heat intval=realval */
#define DECLARED_HcsMedDelta	HcsMedDelta
extern float HcsMedDelta;

/* sec for waiting after washing intval=realval */
#define DECLARED_WfsWaitTime	WfsWaitTime
extern float WfsWaitTime;

/* limiter of washing counter for blocking the system intval=realval */
#define DECLARED_WfsWashCntLim	WfsWashCntLim
extern uint8_t WfsWashCntLim;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

