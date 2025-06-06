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

/* 0..1 Enable AEB intval=realval */
uint8_t AebOnOff = 0U;

/* 0..1 [rad] Calculation manual intval=realval */
float AgFromCenAxisToFrntOuterDimSedLi = 0.1998;

/* 0..10 [m] Calculation manual intval=realval */
float DistFromRearAxleToCornrOfHood = 4.3;

/* 0..50 [m] Calculation manual intval=realval */
float DistHysteresis = 5.0;

/* 0..10 [m] Calculation manual intval=realval */
float DistReserv = 3.5;

/* 0..2 [m] Calculation manual intval=realval */
float DistResvCoef = 0.64;

/* 0..10 [m] intval=realval */
float DistXfromRearAxleToCornrOfHood = 3.95;

/* 0..3 [m] intval=realval */
float DistYfromRearAxleToCornrOfHood = 0.8;

/* 0..100 Response corridor width intval=realval */
uint8_t FcwFOFiltrDataAccumWindow = 20U;

/* 0..100 Response corridor width intval=realval */
uint8_t FcwFOFiltrDataSpdAccumWindow = 20U;

/* 1..2 Response corridor width intval=realval */
uint8_t FcwFrontObj1or3 = 1U;

/* 0..1 Response corridor width intval=realval */
uint8_t FcwFrontObjFiltrEnbl = 1U;

/* 0..100 Response corridor width intval=realval */
uint8_t FcwFrontObjFiltrSize = 10U;

/* 0..100 Response corridor width intval=realval */
uint8_t FcwFrontObjSpdFiltrSize = 10U;

/* 0..100 Response corridor width intval=realval */
float kI = 0.2;

/* 0..100 Response corridor width intval=realval */
float kP = 0.1;

/* 0..100 Response corridor width intval=realval */
float Lim_ratAccPed = 90.0;

/* 0..10 Response corridor width intval=realval */
float MinimumDecelFull = 1.0;

/* 0..1 Response corridor width intval=realval */
float Poly_YawRateRadSLim = 4.9999999E-003;

/* 0..100 Response corridor width intval=realval */
uint8_t ProbabilLim = 99U;

/* 0..1 Response corridor width intval=realval */
uint8_t ProbabilOnOff = 1U;

/* 0..10 Response corridor width intval=realval */
float ReserveAcceler = 1.0;

/* 0..10 Response corridor width intval=realval */
float TargetAccelerFS = 5.0;

/* 0..10 Response corridor width intval=realval */
float TargetAccelerFull = 9.0;

/* 0..2 Response corridor width intval=realval */
float TiWarn = 0.5;

/* 0..5 Response corridor width intval=realval */
float Width = 2.0;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

