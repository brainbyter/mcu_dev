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
#define DECLARED_AebOnOff	AebOnOff
extern uint8_t AebOnOff;

/* 0..1 [rad] Calculation manual intval=realval */
#define DECLARED_AgFromCenAxisToFrntOuterDimSedLi	AgFromCenAxisToFrntOuterDimSedLi
extern float AgFromCenAxisToFrntOuterDimSedLi;

/* 0..10 [m] Calculation manual intval=realval */
#define DECLARED_DistFromRearAxleToCornrOfHood	DistFromRearAxleToCornrOfHood
extern float DistFromRearAxleToCornrOfHood;

/* 0..50 [m] Calculation manual intval=realval */
#define DECLARED_DistHysteresis	DistHysteresis
extern float DistHysteresis;

/* 0..10 [m] Calculation manual intval=realval */
#define DECLARED_DistReserv	DistReserv
extern float DistReserv;

/* 0..2 [m] Calculation manual intval=realval */
#define DECLARED_DistResvCoef	DistResvCoef
extern float DistResvCoef;

/* 0..10 [m] intval=realval */
#define DECLARED_DistXfromRearAxleToCornrOfHood	DistXfromRearAxleToCornrOfHood
extern float DistXfromRearAxleToCornrOfHood;

/* 0..3 [m] intval=realval */
#define DECLARED_DistYfromRearAxleToCornrOfHood	DistYfromRearAxleToCornrOfHood
extern float DistYfromRearAxleToCornrOfHood;

/* 0..100 Response corridor width intval=realval */
#define DECLARED_FcwFOFiltrDataAccumWindow	FcwFOFiltrDataAccumWindow
extern uint8_t FcwFOFiltrDataAccumWindow;

/* 0..100 Response corridor width intval=realval */
#define DECLARED_FcwFOFiltrDataSpdAccumWindow	FcwFOFiltrDataSpdAccumWindow
extern uint8_t FcwFOFiltrDataSpdAccumWindow;

/* 1..2 Response corridor width intval=realval */
#define DECLARED_FcwFrontObj1or3	FcwFrontObj1or3
extern uint8_t FcwFrontObj1or3;

/* 0..1 Response corridor width intval=realval */
#define DECLARED_FcwFrontObjFiltrEnbl	FcwFrontObjFiltrEnbl
extern uint8_t FcwFrontObjFiltrEnbl;

/* 0..100 Response corridor width intval=realval */
#define DECLARED_FcwFrontObjFiltrSize	FcwFrontObjFiltrSize
extern uint8_t FcwFrontObjFiltrSize;

/* 0..100 Response corridor width intval=realval */
#define DECLARED_FcwFrontObjSpdFiltrSize	FcwFrontObjSpdFiltrSize
extern uint8_t FcwFrontObjSpdFiltrSize;

/* 0..100 Response corridor width intval=realval */
#define DECLARED_kI	kI
extern float kI;

/* 0..100 Response corridor width intval=realval */
#define DECLARED_kP	kP
extern float kP;

/* 0..100 Response corridor width intval=realval */
#define DECLARED_Lim_ratAccPed	Lim_ratAccPed
extern float Lim_ratAccPed;

/* 0..10 Response corridor width intval=realval */
#define DECLARED_MinimumDecelFull	MinimumDecelFull
extern float MinimumDecelFull;

/* 0..1 Response corridor width intval=realval */
#define DECLARED_Poly_YawRateRadSLim	Poly_YawRateRadSLim
extern float Poly_YawRateRadSLim;

/* 0..100 Response corridor width intval=realval */
#define DECLARED_ProbabilLim	ProbabilLim
extern uint8_t ProbabilLim;

/* 0..1 Response corridor width intval=realval */
#define DECLARED_ProbabilOnOff	ProbabilOnOff
extern uint8_t ProbabilOnOff;

/* 0..10 Response corridor width intval=realval */
#define DECLARED_ReserveAcceler	ReserveAcceler
extern float ReserveAcceler;

/* 0..10 Response corridor width intval=realval */
#define DECLARED_TargetAccelerFS	TargetAccelerFS
extern float TargetAccelerFS;

/* 0..10 Response corridor width intval=realval */
#define DECLARED_TargetAccelerFull	TargetAccelerFull
extern float TargetAccelerFull;

/* 0..2 Response corridor width intval=realval */
#define DECLARED_TiWarn	TiWarn
extern float TiWarn;

/* 0..5 Response corridor width intval=realval */
#define DECLARED_Width	Width
extern float Width;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

