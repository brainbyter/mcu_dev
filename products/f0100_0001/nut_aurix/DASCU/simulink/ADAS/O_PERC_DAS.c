/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* 0..1 Request to add file in incedents from REC intval=realval */
uint8_t DtPercRecToInc_Req = 0U;

/* 0..1 Req to Start Front oncoming Obj neural network intval=realval */
uint8_t DtPercStartFrontOncomObj = 0U;

/* 0..1 Req to Start Front passing Obj neural network intval=realval */
uint8_t DtPercStartFrontPasObj = 0U;

/* 0..1 Req to Start Lane neural network intval=realval */
uint8_t DtPercStartLane = 0U;

/* 0..1 Req to Start MLIA neural network intval=realval */
uint8_t DtPercStartMlia = 0U;

/* 0..1 Request to start night vision (NV) intval=realval */
uint8_t DtPercStartNV = 0U;

/* 0..1 Req to Start MLIA neural network intval=realval */
uint8_t DtPercStartRearObj = 0U;

/* 0..1 Request to start recording (REC) intval=realval */
uint8_t DtPercStartRec = 0U;

/* 0..1 Req to Start Sign neural network intval=realval */
uint8_t DtPercStartSign = 0U;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

