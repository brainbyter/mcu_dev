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
float ADB_avail = 1.0;

/* 0..1 ADB-diode filter availability intval=realval */
float ADB_Filter_avail = 0.0000000E+000;

/* 25..50 Outside border of animation object zone, deg intval=realval */
float AnimBorder = 30.0;

/* 0..20 Duration of BlinkDetect State (Standby) after blinks, sec intval=realval */
float BlinkDetectDuration = 10.0;

/* 0..1 Blink detector availability intval=realval */
float BlinkDetector_avail = 1.0;

/* 0..10 Turning off HB animation time, s intval=realval */
float ByeTi = 0.5;

/* 0..20 Diode filter time (time before diode turns off), sec intval=realval */
float Filter_delay_OFF = 0.0000000E+000;

/* 0..20 Diode filter time (time before diode turns on), sec intval=realval */
float Filter_delay_ON = 0.0000000E+000;

/* -50..50 Left headlamp ADB segments, LED_1, left side, deg intval=realval */
float HLL_ADB_L1_L = -33.0;

/* -50..50 Left headlamp ADB segments, LED_1, right side, deg intval=realval */
float HLL_ADB_L1_R = -20.0;

/* -50..50 Left headlamp ADB segments, LED_10, left side, deg intval=realval */
float HLL_ADB_L10_L = -4.0;

/* -50..50 Left headlamp ADB segments, LED_10, right side, deg intval=realval */
float HLL_ADB_L10_R = 4.0;

/* -50..50 Left headlamp ADB segments, LED_11, left side, deg intval=realval */
float HLL_ADB_L11_L = -1.7;

/* -50..50 Left headlamp ADB segments, LED_11, right side, deg intval=realval */
float HLL_ADB_L11_R = 6.7;

/* -50..50 Left headlamp ADB segments, LED_12, left side, deg intval=realval */
float HLL_ADB_L12_L = 0.7;

/* -50..50 Left headlamp ADB segments, LED_12, right side, deg intval=realval */
float HLL_ADB_L12_R = 9.9;

/* -50..50 Left headlamp ADB segments, LED_13, left side, deg intval=realval */
float HLL_ADB_L13_L = 3.2;

/* -50..50 Left headlamp ADB segments, LED_13, right side, deg intval=realval */
float HLL_ADB_L13_R = 13.0;

/* -50..50 Left headlamp ADB segments, LED_14, left side, deg intval=realval */
float HLL_ADB_L14_L = 5.3;

/* -50..50 Left headlamp ADB segments, LED_14, right side, deg intval=realval */
float HLL_ADB_L14_R = 16.5;

/* -50..50 Left headlamp ADB segments, LED_15, left side, deg intval=realval */
float HLL_ADB_L15_L = 7.6;

/* -50..50 Left headlamp ADB segments, LED_15, right side, deg intval=realval */
float HLL_ADB_L15_R = 20.3;

/* -50..50 Left headlamp ADB segments, LED_16, left side, deg intval=realval */
float HLL_ADB_L16_L = 10.3;

/* -50..50 Left headlamp ADB segments, LED_16, right side, deg intval=realval */
float HLL_ADB_L16_R = 24.5;

/* -50..50 Left headlamp ADB segments, LED_17, left side, deg intval=realval */
float HLL_ADB_L17_L = 13.3;

/* -50..50 Left headlamp ADB segments, LED_17, right side, deg intval=realval */
float HLL_ADB_L17_R = 28.0;

/* -50..50 Left headlamp ADB segments, LED_18, left side, deg intval=realval */
float HLL_ADB_L18_L = 16.6;

/* -50..50 Left headlamp ADB segments, LED_18, right side, deg intval=realval */
float HLL_ADB_L18_R = 30.0;

/* -50..50 Left headlamp ADB segments, LED_2, left side, deg intval=realval */
float HLL_ADB_L2_L = -30.0;

/* -50..50 Left headlamp ADB segments, LED_2, right side, deg intval=realval */
float HLL_ADB_L2_R = -17.0;

/* -50..50 Left headlamp ADB segments, LED_3, left side, deg intval=realval */
float HLL_ADB_L3_L = -28.0;

/* -50..50 Left headlamp ADB segments, LED_3, right side, deg intval=realval */
float HLL_ADB_L3_R = -13.5;

/* -50..50 Left headlamp ADB segments, LED_4, left side, deg intval=realval */
float HLL_ADB_L4_L = -24.0;

/* -50..50 Left headlamp ADB segments, LED_4, right side, deg intval=realval */
float HLL_ADB_L4_R = -10.3;

/* -50..50 Left headlamp ADB segments, LED_5, left side, deg intval=realval */
float HLL_ADB_L5_L = -20.6;

/* -50..50 Left headlamp ADB segments, LED_5, right side, deg intval=realval */
float HLL_ADB_L5_R = -7.7;

/* -50..50 Left headlamp ADB segments, LED_6, left side, deg intval=realval */
float HLL_ADB_L6_L = -16.6;

/* -50..50 Left headlamp ADB segments, LED_6, right side, deg intval=realval */
float HLL_ADB_L6_R = -5.5;

/* -50..50 Left headlamp ADB segments, LED_7, left side, deg intval=realval */
float HLL_ADB_L7_L = -13.2;

/* -50..50 Left headlamp ADB segments, LED_7, right side, deg intval=realval */
float HLL_ADB_L7_R = -3.2;

/* -50..50 Left headlamp ADB segments, LED_8, left side, deg intval=realval */
float HLL_ADB_L8_L = -10.0;

/* -50..50 Left headlamp ADB segments, LED_8, right side, deg intval=realval */
float HLL_ADB_L8_R = -0.7;

/* -50..50 Left headlamp ADB segments, LED_9, left side, deg intval=realval */
float HLL_ADB_L9_L = -6.8;

/* -50..50 Left headlamp ADB segments, LED_9, right side, deg intval=realval */
float HLL_ADB_L9_R = 1.7;

/* 0..1 Functioning HLL in MLIA: 0-off, 1-active intval=realval */
float HLL_avail = 1.0;

/* -50..50 Right headlamp ADB segments, LED_1, left side, deg intval=realval */
float HLR_ADB_L1_L = -30.0;

/* -50..50 Right headlamp ADB segments, LED_1, right side, deg intval=realval */
float HLR_ADB_L1_R = -16.6;

/* -50..50 Right headlamp ADB segments, LED_10, left side, deg intval=realval */
float HLR_ADB_L10_L = -1.7;

/* -50..50 Right headlamp ADB segments, LED_10, right side, deg intval=realval */
float HLR_ADB_L10_R = 6.8;

/* -50..50 Right headlamp ADB segments, LED_11, left side, deg intval=realval */
float HLR_ADB_L11_L = 0.7;

/* -50..50 Right headlamp ADB segments, LED_11, right side, deg intval=realval */
float HLR_ADB_L11_R = 10.0;

/* -50..50 Right headlamp ADB segments, LED_12, left side, deg intval=realval */
float HLR_ADB_L12_L = 3.2;

/* -50..50 Right headlamp ADB segments, LED_12, right side, deg intval=realval */
float HLR_ADB_L12_R = 13.2;

/* -50..50 Right headlamp ADB segments, LED_13, left side, deg intval=realval */
float HLR_ADB_L13_L = 5.5;

/* -50..50 Right headlamp ADB segments, LED_13, right side, deg intval=realval */
float HLR_ADB_L13_R = 16.6;

/* -50..50 Right headlamp ADB segments, LED_14, left side, deg intval=realval */
float HLR_ADB_L14_L = 7.7;

/* -50..50 Right headlamp ADB segments, LED_14, right side, deg intval=realval */
float HLR_ADB_L14_R = 20.6;

/* -50..50 Right headlamp ADB segments, LED_15, left side, deg intval=realval */
float HLR_ADB_L15_L = 10.3;

/* -50..50 Right headlamp ADB segments, LED_15, right side, deg intval=realval */
float HLR_ADB_L15_R = 24.0;

/* -50..50 Right headlamp ADB segments, LED_16, left side, deg intval=realval */
float HLR_ADB_L16_L = 13.5;

/* -50..50 Right headlamp ADB segments, LED_16, right side, deg intval=realval */
float HLR_ADB_L16_R = 28.0;

/* -50..50 Right headlamp ADB segments, LED_17, left side, deg intval=realval */
float HLR_ADB_L17_L = 17.0;

/* -50..50 Right headlamp ADB segments, LED_17, right side, deg intval=realval */
float HLR_ADB_L17_R = 30.0;

/* -50..50 Right headlamp ADB segments, LED_18, left side, deg intval=realval */
float HLR_ADB_L18_L = 20.0;

/* -50..50 Right headlamp ADB segments, LED_18, right side, deg intval=realval */
float HLR_ADB_L18_R = 33.0;

/* -50..50 Right headlamp ADB segments, LED_2, left side, deg intval=realval */
float HLR_ADB_L2_L = -28.0;

/* -50..50 Right headlamp ADB segments, LED_2, right side, deg intval=realval */
float HLR_ADB_L2_R = -13.3;

/* -50..50 Right headlamp ADB segments, LED_3, left side, deg intval=realval */
float HLR_ADB_L3_L = -24.5;

/* -50..50 Right headlamp ADB segments, LED_3, right side, deg intval=realval */
float HLR_ADB_L3_R = -10.3;

/* -50..50 Right headlamp ADB segments, LED_4, left side, deg intval=realval */
float HLR_ADB_L4_L = -20.3;

/* -50..50 Right headlamp ADB segments, LED_4, right side, deg intval=realval */
float HLR_ADB_L4_R = -7.6;

/* -50..50 Right headlamp ADB segments, LED_5, left side, deg intval=realval */
float HLR_ADB_L5_L = -16.5;

/* -50..50 Right headlamp ADB segments, LED_5, right side, deg intval=realval */
float HLR_ADB_L5_R = -5.3;

/* -50..50 Right headlamp ADB segments, LED_6, left side, deg intval=realval */
float HLR_ADB_L6_L = -13.0;

/* -50..50 Right headlamp ADB segments, LED_6, right side, deg intval=realval */
float HLR_ADB_L6_R = -3.2;

/* -50..50 Right headlamp ADB segments, LED_7, left side, deg intval=realval */
float HLR_ADB_L7_L = -9.9;

/* -50..50 Right headlamp ADB segments, LED_7, right side, deg intval=realval */
float HLR_ADB_L7_R = -0.7;

/* -50..50 Right headlamp ADB segments, LED_8, left side, deg intval=realval */
float HLR_ADB_L8_L = -6.7;

/* -50..50 Right headlamp ADB segments, LED_8, right side, deg intval=realval */
float HLR_ADB_L8_R = 1.7;

/* -50..50 Right headlamp ADB segments, LED_9, left side, deg intval=realval */
float HLR_ADB_L9_L = -4.0;

/* -50..50 Right headlamp ADB segments, LED_9, right side, deg intval=realval */
float HLR_ADB_L9_R = 4.0;

/* 0..1 Functioning HLR in MLIA: 0-off, 1-active intval=realval */
float HLR_avail = 1.0;

/* 0..1 Zone expansion coefficient of each diode for turn-on hysteresis for HLx_ADB_TargetLed_Obj intval=realval */
float HysterCoef = 0.2;

/* 0..20 Number of blinks to go to BlinkDetect State (Standby) intval=realval */
float MaxBlinkCount = 2.0;

/* 0..1 Functioning mLED-module in MLIA: 0-off, 1-active intval=realval */
float mLED_avail = 1.0;

/* 0..1 mLED-zones filter availability intval=realval */
float mLED_Filter_avail = 0.0000000E+000;

/* 0.08..1.2 Coefficient for converting horizontal angles to pixels (mLedHorAngle/mLedHorPix = 30/320) intval=realval */
float mLedHorAngleCoef = 0.09375;

/* 10..20 Horizontal lighting range between V-V and left/right border of mLED module (mLedHorAngle/2), deg intval=realval */
float mLedHorBordAngle = 15.0;

/* 319..320 Number of pixels on the mLED module, horizontally intval=realval */
float mLedHorPix = 320.0;

/* 0..80 Pixel number corresponding to LowBeam on the mLED module, vertically intval=realval */
float mLedLowBeamPix = 33.0;

/* 0.08..1.2 Coefficient for converting vertical angles to pixels (mLedVerAngle/mLedVerPix = 7.5/80) intval=realval */
float mLedVerAngleCoef = 0.09375;

/* 2..7 Vertical lighting range between H-H and bottom border of mLED module, deg intval=realval */
float mLedVerLowAngle = 5.0;

/* 79..80 Number of pixels on the mLED module, vertically intval=realval */
float mLedVerPix = 80.0;

/* 1..7 Vertical lighting range between H-H and upper border of mLED module, deg intval=realval */
float mLedVerUpAngle = 2.5;

/* 0..1 Contraction ratio for ADB_Bord_array_Modif intval=realval */
float NarrCoef = 0.6;

/* 0..1 Objects (object angles) filter availability intval=realval */
float Obj_Filter_avail = 0.0000000E+000;

/* 0..20 Object dietime (time before stop solver for object), sec intval=realval */
float ObjLifetime_OFF = 0.0000000E+000;

/* 0..20 Object lifetime (time before start solver for object), sec intval=realval */
float ObjLifetime_ON = 0.0000000E+000;

/* 0..6 Projection Brightness Control Signal (0-off, 1-10%, 2-25%, 3-40%, 4-60%, 5-85%, 6-100% intval=realval */
uint8_t Proj_bright = 6U;

/* 0..10 Minimum delay between different pictures, s intval=realval */
float ProjDelay = 2.0;

/* 0..1 Сorrespondence of mLED zones to ADB diodes availability intval=realval */
float R48_Filter_avail = 0.0000000E+000;

/* 0..300 Lower limit for zone expansion saturation (1) intval=realval */
float Satur_Exp_mled_1 = 1.0;

/* 0..1000 Upper limit for zone expansion saturation (500) intval=realval */
float Satur_Exp_mled_2 = 500.0;

/* 0..300 Lower limit for zone expansion saturation (1) intval=realval */
float Satur_Exp_obj_1 = 1.0;

/* 0..1000 Upper limit for zone expansion saturation (500) intval=realval */
float Satur_Exp_obj_2 = 500.0;

/* 0..300 Lower limit for zone narrowing saturation (1) intval=realval */
float Satur_Nar_mled_1 = 1.0;

/* 0..1000 Upper limit for zone narrowing saturation (500) intval=realval */
float Satur_Nar_mled_2 = 500.0;

/* 0..300 Lower limit for zone narrowing saturation (1) intval=realval */
float Satur_Nar_obj_1 = 1.0;

/* 0..1000 Upper limit for zone narrowing saturation (500) intval=realval */
float Satur_Nar_obj_2 = 500.0;

/* 0..10 Duration of sign display, s intval=realval */
float SignDuration = 4.0;

/* 0..2 Switching period between speed limit value and circle (50/50), s intval=realval */
double SpdLimSignPeriod = 1.0;

/* 0..45 Speed at which the HB turns off, kmh intval=realval */
float SpeedActiveMlia_off = 25.0;

/* 0..50 Speed at which the HB turns on, kmh intval=realval */
float SpeedActiveMlia_on = 30.0;

/* 60..110 Speed at which the HB_boost turns off, kmh intval=realval */
float SpeedMliaBoost_off = 70.0;

/* 90..250 Speed at which the HB_boost turns on, kmh intval=realval */
float SpeedMliaBoost_on = 120.0;

/* 0..100 Obj Speed at which MLIA doesn`t blur vehicle with off-headlamps, kmh intval=realval */
float SpeedMliaDark_off = 20.0;

/* 0..100 Obj Speed at which MLIA blurs vehicle with off-headlamps, kmh intval=realval */
float SpeedMliaDark_on = 30.0;

/* Expansion Lookup Table 0-60-320-pixels step difference (mled) intval=realval */
float Table_Exp_mled[3] = { 10.0, 20.0, 30.0 };

/* Expansion Lookup Table 0-30-angles step difference (obj) intval=realval */
float Table_Exp_obj[2] = { 10.0, 30.0 };

/* Narrow Lookup Table 0-60-320-pixels step difference (mled) intval=realval */
float Table_Nar_mled[3] = { 0.1, 2.0, 20.0 };

/* Narrow Lookup Table 0-30-angles step difference (obj) intval=realval */
float Table_Nar_obj[2] = { 0.1, 20.0 };

/* 0..20 Time to stop blink counter (Total time = TiToSafe + Filter_delay_OFF(ON)), sec intval=realval */
float TiToSafe = 0.5;

/* 0..1 Vertical angle accounting in mLED-module in MLIA: 0-off, 1-active intval=realval */
float Vangle_avail = 0.0000000E+000;

/* 0..10 Turning on HB animation time, s intval=realval */
float WelcomeTi = 0.5;

/* 0..400 Distance at which MLIA doesn`t blur vehicle with off-headlamps, m intval=realval */
float X_dark_off = 50.0;

/* 0..400 Distance at which MLIA blurs vehicle with off-headlamps, m intval=realval */
float X_dark_on = 40.0;

/* 0..10 X-Distance between rear axle and HL ((X_ADB+X_mLED)/2), limousine, m intval=realval */
float X_HL_Limo = 4.934;

/* 0..10 X-Distance between rear axle and HL ((X_ADB+X_mLED)/2), sedan, m intval=realval */
float X_HL_Sedan = 3.934;

/* 0..10 X-Distance between rear axle and HL ((X_ADB+X_mLED)/2), sedan long, m intval=realval */
float X_HL_SedanLong = 4.434;

/* 0..20 Object zone expansion from each side at distance <=25 m, m intval=realval */
float Y_ext_25 = 0.0000000E+000;

/* 0..20 Object zone expansion from each side at distance >=500 m, m intval=realval */
float Y_ext_500 = 0.0000000E+000;

/* 0.5..1.5 Y-Distance between longitudinal axis and HL ((Y_ADB+Y_mLED)/2), m intval=realval */
float Y_HL = 0.7;

/* 0..1 Using the derivative of the YawRate to calculate the zone displacement availability intval=realval */
float YawRateDerivativeCoef_avail = 0.0000000E+000;

/* 0..1 YawRate predict availability intval=realval */
float YawRatePredict_avail = 1.0;

/* -1000..1000 YawRate predict coefficient intval=realval */
float YawRatePredict_coef = 0.0000000E+000;

/* 0..2 Z-Distance between rear axle and HL, m intval=realval */
float Z_HL = 0.462;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

