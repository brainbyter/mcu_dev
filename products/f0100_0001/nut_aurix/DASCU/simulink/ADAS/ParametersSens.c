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
float HcsCycleTime = 1.0;

/* Delta of temperature for low heat intval=realval */
float HcsLowDelta = 20.0;

/* Delta of temperature for medium heat intval=realval */
float HcsMedDelta = 6.0;

/* sec for waiting after washing intval=realval */
float WfsWaitTime = 10.0;

/* limiter of washing counter for blocking the system intval=realval */
uint8_t WfsWashCntLim = 2U;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

