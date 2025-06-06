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

/* 0..1 Functioning ADB-module in MLIA: 0-off, 1-active intval=realval */
#define DECLARED_ADB_avail	ADB_avail
extern float ADB_avail;

/* 0..1 ADB-diode filter availability intval=realval */
#define DECLARED_ADB_Filter_avail	ADB_Filter_avail
extern float ADB_Filter_avail;

/* 25..50 Outside border of animation object zone, deg intval=realval */
#define DECLARED_AnimBorder	AnimBorder
extern float AnimBorder;

/* 0..20 Duration of BlinkDetect State (Standby) after blinks, sec intval=realval */
#define DECLARED_BlinkDetectDuration	BlinkDetectDuration
extern float BlinkDetectDuration;

/* 0..1 Blink detector availability intval=realval */
#define DECLARED_BlinkDetector_avail	BlinkDetector_avail
extern float BlinkDetector_avail;

/* 0..10 Turning off HB animation time, s intval=realval */
#define DECLARED_ByeTi	ByeTi
extern float ByeTi;

/* 0..20 Diode filter time (time before diode turns off), sec intval=realval */
#define DECLARED_Filter_delay_OFF	Filter_delay_OFF
extern float Filter_delay_OFF;

/* 0..20 Diode filter time (time before diode turns on), sec intval=realval */
#define DECLARED_Filter_delay_ON	Filter_delay_ON
extern float Filter_delay_ON;

/* -50..50 Left headlamp ADB segments, LED_1, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L1_L	HLL_ADB_L1_L
extern float HLL_ADB_L1_L;

/* -50..50 Left headlamp ADB segments, LED_1, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L1_R	HLL_ADB_L1_R
extern float HLL_ADB_L1_R;

/* -50..50 Left headlamp ADB segments, LED_10, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L10_L	HLL_ADB_L10_L
extern float HLL_ADB_L10_L;

/* -50..50 Left headlamp ADB segments, LED_10, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L10_R	HLL_ADB_L10_R
extern float HLL_ADB_L10_R;

/* -50..50 Left headlamp ADB segments, LED_11, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L11_L	HLL_ADB_L11_L
extern float HLL_ADB_L11_L;

/* -50..50 Left headlamp ADB segments, LED_11, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L11_R	HLL_ADB_L11_R
extern float HLL_ADB_L11_R;

/* -50..50 Left headlamp ADB segments, LED_12, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L12_L	HLL_ADB_L12_L
extern float HLL_ADB_L12_L;

/* -50..50 Left headlamp ADB segments, LED_12, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L12_R	HLL_ADB_L12_R
extern float HLL_ADB_L12_R;

/* -50..50 Left headlamp ADB segments, LED_13, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L13_L	HLL_ADB_L13_L
extern float HLL_ADB_L13_L;

/* -50..50 Left headlamp ADB segments, LED_13, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L13_R	HLL_ADB_L13_R
extern float HLL_ADB_L13_R;

/* -50..50 Left headlamp ADB segments, LED_14, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L14_L	HLL_ADB_L14_L
extern float HLL_ADB_L14_L;

/* -50..50 Left headlamp ADB segments, LED_14, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L14_R	HLL_ADB_L14_R
extern float HLL_ADB_L14_R;

/* -50..50 Left headlamp ADB segments, LED_15, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L15_L	HLL_ADB_L15_L
extern float HLL_ADB_L15_L;

/* -50..50 Left headlamp ADB segments, LED_15, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L15_R	HLL_ADB_L15_R
extern float HLL_ADB_L15_R;

/* -50..50 Left headlamp ADB segments, LED_16, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L16_L	HLL_ADB_L16_L
extern float HLL_ADB_L16_L;

/* -50..50 Left headlamp ADB segments, LED_16, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L16_R	HLL_ADB_L16_R
extern float HLL_ADB_L16_R;

/* -50..50 Left headlamp ADB segments, LED_17, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L17_L	HLL_ADB_L17_L
extern float HLL_ADB_L17_L;

/* -50..50 Left headlamp ADB segments, LED_17, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L17_R	HLL_ADB_L17_R
extern float HLL_ADB_L17_R;

/* -50..50 Left headlamp ADB segments, LED_18, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L18_L	HLL_ADB_L18_L
extern float HLL_ADB_L18_L;

/* -50..50 Left headlamp ADB segments, LED_18, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L18_R	HLL_ADB_L18_R
extern float HLL_ADB_L18_R;

/* -50..50 Left headlamp ADB segments, LED_2, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L2_L	HLL_ADB_L2_L
extern float HLL_ADB_L2_L;

/* -50..50 Left headlamp ADB segments, LED_2, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L2_R	HLL_ADB_L2_R
extern float HLL_ADB_L2_R;

/* -50..50 Left headlamp ADB segments, LED_3, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L3_L	HLL_ADB_L3_L
extern float HLL_ADB_L3_L;

/* -50..50 Left headlamp ADB segments, LED_3, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L3_R	HLL_ADB_L3_R
extern float HLL_ADB_L3_R;

/* -50..50 Left headlamp ADB segments, LED_4, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L4_L	HLL_ADB_L4_L
extern float HLL_ADB_L4_L;

/* -50..50 Left headlamp ADB segments, LED_4, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L4_R	HLL_ADB_L4_R
extern float HLL_ADB_L4_R;

/* -50..50 Left headlamp ADB segments, LED_5, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L5_L	HLL_ADB_L5_L
extern float HLL_ADB_L5_L;

/* -50..50 Left headlamp ADB segments, LED_5, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L5_R	HLL_ADB_L5_R
extern float HLL_ADB_L5_R;

/* -50..50 Left headlamp ADB segments, LED_6, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L6_L	HLL_ADB_L6_L
extern float HLL_ADB_L6_L;

/* -50..50 Left headlamp ADB segments, LED_6, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L6_R	HLL_ADB_L6_R
extern float HLL_ADB_L6_R;

/* -50..50 Left headlamp ADB segments, LED_7, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L7_L	HLL_ADB_L7_L
extern float HLL_ADB_L7_L;

/* -50..50 Left headlamp ADB segments, LED_7, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L7_R	HLL_ADB_L7_R
extern float HLL_ADB_L7_R;

/* -50..50 Left headlamp ADB segments, LED_8, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L8_L	HLL_ADB_L8_L
extern float HLL_ADB_L8_L;

/* -50..50 Left headlamp ADB segments, LED_8, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L8_R	HLL_ADB_L8_R
extern float HLL_ADB_L8_R;

/* -50..50 Left headlamp ADB segments, LED_9, left side, deg intval=realval */
#define DECLARED_HLL_ADB_L9_L	HLL_ADB_L9_L
extern float HLL_ADB_L9_L;

/* -50..50 Left headlamp ADB segments, LED_9, right side, deg intval=realval */
#define DECLARED_HLL_ADB_L9_R	HLL_ADB_L9_R
extern float HLL_ADB_L9_R;

/* 0..1 Functioning HLL in MLIA: 0-off, 1-active intval=realval */
#define DECLARED_HLL_avail	HLL_avail
extern float HLL_avail;

/* -50..50 Right headlamp ADB segments, LED_1, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L1_L	HLR_ADB_L1_L
extern float HLR_ADB_L1_L;

/* -50..50 Right headlamp ADB segments, LED_1, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L1_R	HLR_ADB_L1_R
extern float HLR_ADB_L1_R;

/* -50..50 Right headlamp ADB segments, LED_10, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L10_L	HLR_ADB_L10_L
extern float HLR_ADB_L10_L;

/* -50..50 Right headlamp ADB segments, LED_10, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L10_R	HLR_ADB_L10_R
extern float HLR_ADB_L10_R;

/* -50..50 Right headlamp ADB segments, LED_11, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L11_L	HLR_ADB_L11_L
extern float HLR_ADB_L11_L;

/* -50..50 Right headlamp ADB segments, LED_11, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L11_R	HLR_ADB_L11_R
extern float HLR_ADB_L11_R;

/* -50..50 Right headlamp ADB segments, LED_12, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L12_L	HLR_ADB_L12_L
extern float HLR_ADB_L12_L;

/* -50..50 Right headlamp ADB segments, LED_12, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L12_R	HLR_ADB_L12_R
extern float HLR_ADB_L12_R;

/* -50..50 Right headlamp ADB segments, LED_13, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L13_L	HLR_ADB_L13_L
extern float HLR_ADB_L13_L;

/* -50..50 Right headlamp ADB segments, LED_13, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L13_R	HLR_ADB_L13_R
extern float HLR_ADB_L13_R;

/* -50..50 Right headlamp ADB segments, LED_14, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L14_L	HLR_ADB_L14_L
extern float HLR_ADB_L14_L;

/* -50..50 Right headlamp ADB segments, LED_14, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L14_R	HLR_ADB_L14_R
extern float HLR_ADB_L14_R;

/* -50..50 Right headlamp ADB segments, LED_15, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L15_L	HLR_ADB_L15_L
extern float HLR_ADB_L15_L;

/* -50..50 Right headlamp ADB segments, LED_15, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L15_R	HLR_ADB_L15_R
extern float HLR_ADB_L15_R;

/* -50..50 Right headlamp ADB segments, LED_16, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L16_L	HLR_ADB_L16_L
extern float HLR_ADB_L16_L;

/* -50..50 Right headlamp ADB segments, LED_16, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L16_R	HLR_ADB_L16_R
extern float HLR_ADB_L16_R;

/* -50..50 Right headlamp ADB segments, LED_17, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L17_L	HLR_ADB_L17_L
extern float HLR_ADB_L17_L;

/* -50..50 Right headlamp ADB segments, LED_17, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L17_R	HLR_ADB_L17_R
extern float HLR_ADB_L17_R;

/* -50..50 Right headlamp ADB segments, LED_18, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L18_L	HLR_ADB_L18_L
extern float HLR_ADB_L18_L;

/* -50..50 Right headlamp ADB segments, LED_18, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L18_R	HLR_ADB_L18_R
extern float HLR_ADB_L18_R;

/* -50..50 Right headlamp ADB segments, LED_2, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L2_L	HLR_ADB_L2_L
extern float HLR_ADB_L2_L;

/* -50..50 Right headlamp ADB segments, LED_2, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L2_R	HLR_ADB_L2_R
extern float HLR_ADB_L2_R;

/* -50..50 Right headlamp ADB segments, LED_3, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L3_L	HLR_ADB_L3_L
extern float HLR_ADB_L3_L;

/* -50..50 Right headlamp ADB segments, LED_3, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L3_R	HLR_ADB_L3_R
extern float HLR_ADB_L3_R;

/* -50..50 Right headlamp ADB segments, LED_4, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L4_L	HLR_ADB_L4_L
extern float HLR_ADB_L4_L;

/* -50..50 Right headlamp ADB segments, LED_4, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L4_R	HLR_ADB_L4_R
extern float HLR_ADB_L4_R;

/* -50..50 Right headlamp ADB segments, LED_5, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L5_L	HLR_ADB_L5_L
extern float HLR_ADB_L5_L;

/* -50..50 Right headlamp ADB segments, LED_5, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L5_R	HLR_ADB_L5_R
extern float HLR_ADB_L5_R;

/* -50..50 Right headlamp ADB segments, LED_6, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L6_L	HLR_ADB_L6_L
extern float HLR_ADB_L6_L;

/* -50..50 Right headlamp ADB segments, LED_6, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L6_R	HLR_ADB_L6_R
extern float HLR_ADB_L6_R;

/* -50..50 Right headlamp ADB segments, LED_7, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L7_L	HLR_ADB_L7_L
extern float HLR_ADB_L7_L;

/* -50..50 Right headlamp ADB segments, LED_7, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L7_R	HLR_ADB_L7_R
extern float HLR_ADB_L7_R;

/* -50..50 Right headlamp ADB segments, LED_8, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L8_L	HLR_ADB_L8_L
extern float HLR_ADB_L8_L;

/* -50..50 Right headlamp ADB segments, LED_8, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L8_R	HLR_ADB_L8_R
extern float HLR_ADB_L8_R;

/* -50..50 Right headlamp ADB segments, LED_9, left side, deg intval=realval */
#define DECLARED_HLR_ADB_L9_L	HLR_ADB_L9_L
extern float HLR_ADB_L9_L;

/* -50..50 Right headlamp ADB segments, LED_9, right side, deg intval=realval */
#define DECLARED_HLR_ADB_L9_R	HLR_ADB_L9_R
extern float HLR_ADB_L9_R;

/* 0..1 Functioning HLR in MLIA: 0-off, 1-active intval=realval */
#define DECLARED_HLR_avail	HLR_avail
extern float HLR_avail;

/* 0..1 Zone expansion coefficient of each diode for turn-on hysteresis for HLx_ADB_TargetLed_Obj intval=realval */
#define DECLARED_HysterCoef	HysterCoef
extern float HysterCoef;

/* 0..20 Number of blinks to go to BlinkDetect State (Standby) intval=realval */
#define DECLARED_MaxBlinkCount	MaxBlinkCount
extern float MaxBlinkCount;

/* 0..1 Functioning mLED-module in MLIA: 0-off, 1-active intval=realval */
#define DECLARED_mLED_avail	mLED_avail
extern float mLED_avail;

/* 0..1 mLED-zones filter availability intval=realval */
#define DECLARED_mLED_Filter_avail	mLED_Filter_avail
extern float mLED_Filter_avail;

/* 0.08..1.2 Coefficient for converting horizontal angles to pixels (mLedHorAngle/mLedHorPix = 30/320) intval=realval */
#define DECLARED_mLedHorAngleCoef	mLedHorAngleCoef
extern float mLedHorAngleCoef;

/* 10..20 Horizontal lighting range between V-V and left/right border of mLED module (mLedHorAngle/2), deg intval=realval */
#define DECLARED_mLedHorBordAngle	mLedHorBordAngle
extern float mLedHorBordAngle;

/* 319..320 Number of pixels on the mLED module, horizontally intval=realval */
#define DECLARED_mLedHorPix	mLedHorPix
extern float mLedHorPix;

/* 0..80 Pixel number corresponding to LowBeam on the mLED module, vertically intval=realval */
#define DECLARED_mLedLowBeamPix	mLedLowBeamPix
extern float mLedLowBeamPix;

/* 0.08..1.2 Coefficient for converting vertical angles to pixels (mLedVerAngle/mLedVerPix = 7.5/80) intval=realval */
#define DECLARED_mLedVerAngleCoef	mLedVerAngleCoef
extern float mLedVerAngleCoef;

/* 2..7 Vertical lighting range between H-H and bottom border of mLED module, deg intval=realval */
#define DECLARED_mLedVerLowAngle	mLedVerLowAngle
extern float mLedVerLowAngle;

/* 79..80 Number of pixels on the mLED module, vertically intval=realval */
#define DECLARED_mLedVerPix	mLedVerPix
extern float mLedVerPix;

/* 1..7 Vertical lighting range between H-H and upper border of mLED module, deg intval=realval */
#define DECLARED_mLedVerUpAngle	mLedVerUpAngle
extern float mLedVerUpAngle;

/* 0..1 Contraction ratio for ADB_Bord_array_Modif intval=realval */
#define DECLARED_NarrCoef	NarrCoef
extern float NarrCoef;

/* 0..1 Objects (object angles) filter availability intval=realval */
#define DECLARED_Obj_Filter_avail	Obj_Filter_avail
extern float Obj_Filter_avail;

/* 0..20 Object dietime (time before stop solver for object), sec intval=realval */
#define DECLARED_ObjLifetime_OFF	ObjLifetime_OFF
extern float ObjLifetime_OFF;

/* 0..20 Object lifetime (time before start solver for object), sec intval=realval */
#define DECLARED_ObjLifetime_ON	ObjLifetime_ON
extern float ObjLifetime_ON;

/* 0..6 Projection Brightness Control Signal (0-off, 1-10%, 2-25%, 3-40%, 4-60%, 5-85%, 6-100% intval=realval */
#define DECLARED_Proj_bright	Proj_bright
extern uint8_t Proj_bright;

/* 0..10 Minimum delay between different pictures, s intval=realval */
#define DECLARED_ProjDelay	ProjDelay
extern float ProjDelay;

/* 0..1 Сorrespondence of mLED zones to ADB diodes availability intval=realval */
#define DECLARED_R48_Filter_avail	R48_Filter_avail
extern float R48_Filter_avail;

/* 0..300 Lower limit for zone expansion saturation (1) intval=realval */
#define DECLARED_Satur_Exp_mled_1	Satur_Exp_mled_1
extern float Satur_Exp_mled_1;

/* 0..1000 Upper limit for zone expansion saturation (500) intval=realval */
#define DECLARED_Satur_Exp_mled_2	Satur_Exp_mled_2
extern float Satur_Exp_mled_2;

/* 0..300 Lower limit for zone expansion saturation (1) intval=realval */
#define DECLARED_Satur_Exp_obj_1	Satur_Exp_obj_1
extern float Satur_Exp_obj_1;

/* 0..1000 Upper limit for zone expansion saturation (500) intval=realval */
#define DECLARED_Satur_Exp_obj_2	Satur_Exp_obj_2
extern float Satur_Exp_obj_2;

/* 0..300 Lower limit for zone narrowing saturation (1) intval=realval */
#define DECLARED_Satur_Nar_mled_1	Satur_Nar_mled_1
extern float Satur_Nar_mled_1;

/* 0..1000 Upper limit for zone narrowing saturation (500) intval=realval */
#define DECLARED_Satur_Nar_mled_2	Satur_Nar_mled_2
extern float Satur_Nar_mled_2;

/* 0..300 Lower limit for zone narrowing saturation (1) intval=realval */
#define DECLARED_Satur_Nar_obj_1	Satur_Nar_obj_1
extern float Satur_Nar_obj_1;

/* 0..1000 Upper limit for zone narrowing saturation (500) intval=realval */
#define DECLARED_Satur_Nar_obj_2	Satur_Nar_obj_2
extern float Satur_Nar_obj_2;

/* 0..10 Duration of sign display, s intval=realval */
#define DECLARED_SignDuration	SignDuration
extern float SignDuration;

/* 0..2 Switching period between speed limit value and circle (50/50), s intval=realval */
#define DECLARED_SpdLimSignPeriod	SpdLimSignPeriod
extern double SpdLimSignPeriod;

/* 0..45 Speed at which the HB turns off, kmh intval=realval */
#define DECLARED_SpeedActiveMlia_off	SpeedActiveMlia_off
extern float SpeedActiveMlia_off;

/* 0..50 Speed at which the HB turns on, kmh intval=realval */
#define DECLARED_SpeedActiveMlia_on	SpeedActiveMlia_on
extern float SpeedActiveMlia_on;

/* 60..110 Speed at which the HB_boost turns off, kmh intval=realval */
#define DECLARED_SpeedMliaBoost_off	SpeedMliaBoost_off
extern float SpeedMliaBoost_off;

/* 90..250 Speed at which the HB_boost turns on, kmh intval=realval */
#define DECLARED_SpeedMliaBoost_on	SpeedMliaBoost_on
extern float SpeedMliaBoost_on;

/* 0..100 Obj Speed at which MLIA doesn`t blur vehicle with off-headlamps, kmh intval=realval */
#define DECLARED_SpeedMliaDark_off	SpeedMliaDark_off
extern float SpeedMliaDark_off;

/* 0..100 Obj Speed at which MLIA blurs vehicle with off-headlamps, kmh intval=realval */
#define DECLARED_SpeedMliaDark_on	SpeedMliaDark_on
extern float SpeedMliaDark_on;

/* Expansion Lookup Table 0-60-320-pixels step difference (mled) intval=realval */
#define DECLARED_Table_Exp_mled	Table_Exp_mled
extern float Table_Exp_mled[3];

/* Expansion Lookup Table 0-30-angles step difference (obj) intval=realval */
#define DECLARED_Table_Exp_obj	Table_Exp_obj
extern float Table_Exp_obj[2];

/* Narrow Lookup Table 0-60-320-pixels step difference (mled) intval=realval */
#define DECLARED_Table_Nar_mled	Table_Nar_mled
extern float Table_Nar_mled[3];

/* Narrow Lookup Table 0-30-angles step difference (obj) intval=realval */
#define DECLARED_Table_Nar_obj	Table_Nar_obj
extern float Table_Nar_obj[2];

/* 0..20 Time to stop blink counter (Total time = TiToSafe + Filter_delay_OFF(ON)), sec intval=realval */
#define DECLARED_TiToSafe	TiToSafe
extern float TiToSafe;

/* 0..1 Vertical angle accounting in mLED-module in MLIA: 0-off, 1-active intval=realval */
#define DECLARED_Vangle_avail	Vangle_avail
extern float Vangle_avail;

/* 0..10 Turning on HB animation time, s intval=realval */
#define DECLARED_WelcomeTi	WelcomeTi
extern float WelcomeTi;

/* 0..400 Distance at which MLIA doesn`t blur vehicle with off-headlamps, m intval=realval */
#define DECLARED_X_dark_off	X_dark_off
extern float X_dark_off;

/* 0..400 Distance at which MLIA blurs vehicle with off-headlamps, m intval=realval */
#define DECLARED_X_dark_on	X_dark_on
extern float X_dark_on;

/* 0..10 X-Distance between rear axle and HL ((X_ADB+X_mLED)/2), limousine, m intval=realval */
#define DECLARED_X_HL_Limo	X_HL_Limo
extern float X_HL_Limo;

/* 0..10 X-Distance between rear axle and HL ((X_ADB+X_mLED)/2), sedan, m intval=realval */
#define DECLARED_X_HL_Sedan	X_HL_Sedan
extern float X_HL_Sedan;

/* 0..10 X-Distance between rear axle and HL ((X_ADB+X_mLED)/2), sedan long, m intval=realval */
#define DECLARED_X_HL_SedanLong	X_HL_SedanLong
extern float X_HL_SedanLong;

/* 0..20 Object zone expansion from each side at distance <=25 m, m intval=realval */
#define DECLARED_Y_ext_25	Y_ext_25
extern float Y_ext_25;

/* 0..20 Object zone expansion from each side at distance >=500 m, m intval=realval */
#define DECLARED_Y_ext_500	Y_ext_500
extern float Y_ext_500;

/* 0.5..1.5 Y-Distance between longitudinal axis and HL ((Y_ADB+Y_mLED)/2), m intval=realval */
#define DECLARED_Y_HL	Y_HL
extern float Y_HL;

/* 0..1 Using the derivative of the YawRate to calculate the zone displacement availability intval=realval */
#define DECLARED_YawRateDerivativeCoef_avail	YawRateDerivativeCoef_avail
extern float YawRateDerivativeCoef_avail;

/* 0..1 YawRate predict availability intval=realval */
#define DECLARED_YawRatePredict_avail	YawRatePredict_avail
extern float YawRatePredict_avail;

/* -1000..1000 YawRate predict coefficient intval=realval */
#define DECLARED_YawRatePredict_coef	YawRatePredict_coef
extern float YawRatePredict_coef;

/* 0..2 Z-Distance between rear axle and HL, m intval=realval */
#define DECLARED_Z_HL	Z_HL
extern float Z_HL;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

