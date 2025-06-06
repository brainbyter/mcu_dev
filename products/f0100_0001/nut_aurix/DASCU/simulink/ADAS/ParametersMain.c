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
uint8_t FrontRadarAvail = 1U;

/* 0..1 Lidar installed intval=realval */
uint8_t LidarAvail = 1U;

/* 0..2000 BCM_LightAmbient_Val border to switch to DAY intval=realval */
float LightAmbientBorder = 800.0;

/* 0..2000 BCM_LightFront_Val border to switch to DAY intval=realval */
float LightFrontBorder = 200.0;

/* 0..1 Start FrontOncomObj Perception intval=realval */
uint8_t PercStartFrontOncomObj = 1U;

/* 0..1 Start FrontPasObj Perception intval=realval */
uint8_t PercStartFrontPasObj = 1U;

/* 0..1 Start Lane Perception intval=realval */
uint8_t PercStartLane = 1U;

/* 0..1 Start MLIA Perception intval=realval */
uint8_t PercStartMlia = 1U;

/* 0..3 Mode of start MLIA Perception: 0 - always=1, 1 - by XCP (PercStartMlia), 2 - by MliaStartReq+RLS, 3 - by RLS only intval=realval */
uint8_t PercStartMlia_Mode = 1U;

/* 0..1 Start RearObj Perception intval=realval */
uint8_t PercStartRearObj = 1U;

/* 0..1 Start Sign Perception intval=realval */
uint8_t PercStartSign = 1U;

/* 0..1 MRRx installed intval=realval */
uint8_t RearRadarAvail = 1U;

/* 0..1 TICU installed intval=realval */
uint8_t ThermalCameraAvail = 1U;

/* 0..10 [m] Wheel base of the Limousine intval=realval */
float WheelBaseLimo = 4.3;

/* 0..10 [m] Wheel base of the Sedan intval=realval */
float WheelBaseSedan = 3.3;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

