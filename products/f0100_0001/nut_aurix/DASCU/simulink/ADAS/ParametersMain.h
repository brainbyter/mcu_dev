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

/* 0..1 FRCU installed intval=realval */
#define DECLARED_FrontRadarAvail	FrontRadarAvail
extern uint8_t FrontRadarAvail;

/* 0..1 Lidar installed intval=realval */
#define DECLARED_LidarAvail	LidarAvail
extern uint8_t LidarAvail;

/* 0..2000 BCM_LightAmbient_Val border to switch to DAY intval=realval */
#define DECLARED_LightAmbientBorder	LightAmbientBorder
extern float LightAmbientBorder;

/* 0..2000 BCM_LightFront_Val border to switch to DAY intval=realval */
#define DECLARED_LightFrontBorder	LightFrontBorder
extern float LightFrontBorder;

/* 0..1 Start FrontOncomObj Perception intval=realval */
#define DECLARED_PercStartFrontOncomObj	PercStartFrontOncomObj
extern uint8_t PercStartFrontOncomObj;

/* 0..1 Start FrontPasObj Perception intval=realval */
#define DECLARED_PercStartFrontPasObj	PercStartFrontPasObj
extern uint8_t PercStartFrontPasObj;

/* 0..1 Start Lane Perception intval=realval */
#define DECLARED_PercStartLane	PercStartLane
extern uint8_t PercStartLane;

/* 0..1 Start MLIA Perception intval=realval */
#define DECLARED_PercStartMlia	PercStartMlia
extern uint8_t PercStartMlia;

/* 0..3 Mode of start MLIA Perception: 0 - always=1, 1 - by XCP (PercStartMlia), 2 - by MliaStartReq+RLS, 3 - by RLS only intval=realval */
#define DECLARED_PercStartMlia_Mode	PercStartMlia_Mode
extern uint8_t PercStartMlia_Mode;

/* 0..1 Start RearObj Perception intval=realval */
#define DECLARED_PercStartRearObj	PercStartRearObj
extern uint8_t PercStartRearObj;

/* 0..1 Start Sign Perception intval=realval */
#define DECLARED_PercStartSign	PercStartSign
extern uint8_t PercStartSign;

/* 0..1 MRRx installed intval=realval */
#define DECLARED_RearRadarAvail	RearRadarAvail
extern uint8_t RearRadarAvail;

/* 0..1 TICU installed intval=realval */
#define DECLARED_ThermalCameraAvail	ThermalCameraAvail
extern uint8_t ThermalCameraAvail;

/* 0..10 [m] Wheel base of the Limousine intval=realval */
#define DECLARED_WheelBaseLimo	WheelBaseLimo
extern float WheelBaseLimo;

/* 0..10 [m] Wheel base of the Sedan intval=realval */
#define DECLARED_WheelBaseSedan	WheelBaseSedan
extern float WheelBaseSedan;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

