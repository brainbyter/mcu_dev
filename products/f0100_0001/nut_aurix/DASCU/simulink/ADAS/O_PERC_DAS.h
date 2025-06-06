/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* 0..1 Request to add file in incedents from REC intval=realval */
#define DECLARED_DtPercRecToInc_Req	DtPercRecToInc_Req
extern uint8_t DtPercRecToInc_Req;

/* 0..1 Req to Start Front oncoming Obj neural network intval=realval */
#define DECLARED_DtPercStartFrontOncomObj	DtPercStartFrontOncomObj
extern uint8_t DtPercStartFrontOncomObj;

/* 0..1 Req to Start Front passing Obj neural network intval=realval */
#define DECLARED_DtPercStartFrontPasObj	DtPercStartFrontPasObj
extern uint8_t DtPercStartFrontPasObj;

/* 0..1 Req to Start Lane neural network intval=realval */
#define DECLARED_DtPercStartLane	DtPercStartLane
extern uint8_t DtPercStartLane;

/* 0..1 Req to Start MLIA neural network intval=realval */
#define DECLARED_DtPercStartMlia	DtPercStartMlia
extern uint8_t DtPercStartMlia;

/* 0..1 Request to start night vision (NV) intval=realval */
#define DECLARED_DtPercStartNV	DtPercStartNV
extern uint8_t DtPercStartNV;

/* 0..1 Req to Start MLIA neural network intval=realval */
#define DECLARED_DtPercStartRearObj	DtPercStartRearObj
extern uint8_t DtPercStartRearObj;

/* 0..1 Request to start recording (REC) intval=realval */
#define DECLARED_DtPercStartRec	DtPercStartRec
extern uint8_t DtPercStartRec;

/* 0..1 Req to Start Sign neural network intval=realval */
#define DECLARED_DtPercStartSign	DtPercStartSign
extern uint8_t DtPercStartSign;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

