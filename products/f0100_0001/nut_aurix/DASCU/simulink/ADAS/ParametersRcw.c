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

/* 0..10 Coefficient Dinamic gab intval=realval */
float CoefDinamGab = 3.5;

/* 0..2 Minimum Dinamic gab intval=realval */
float MinDinamGab = 0.4;

/* 0..10 Minimal Time Warning intval=realval */
float MinTimeWarn = 2.0;

/* 0..100 parameter probability perception intval=realval */
uint8_t ParamProbal = 65U;

/* 0..1 Enable RCW Off or On 12 and 14 object intval=realval */
uint8_t RCW_12_14_Stat = 0U;

/* 0..1 Enable RCW Off or On intval=realval */
uint8_t RCW_Stat = 1U;

/* 0..2 Car Gab intval=realval */
float RCWCarGab = 0.1;

/* 0..1 Coefficient of Adhesion intval=realval */
float RCWMu = 0.9;

/* 0.05..1.5 Driver reaction angular velocity intval=realval */
float RCWWsteer = 0.25;

/* 0..1.5 Time Brakes intval=realval */
float TimeBrake = 0.2;

/* 0..300 Time Over Break Point intval=realval */
float TimeOverBkPoint[21] = { 0.0000000E+000, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0, 110.0, 120.0, 130.0, 140.0, 150.0, 160.0, 170.0, 180.0, 190.0, 200.0 };

/* 0..3 Time Over Table Data intval=realval */
float TimeOverTbData[21] = { 1.54, 1.55, 1.56, 1.57, 1.58, 1.61, 1.64, 1.67, 1.7, 1.725, 1.75, 1.78, 1.81, 1.84, 1.87, 1.91, 1.94, 1.97, 2.0, 2.03, 2.06 };

/* 0..1.5 Time Reaction Driver intval=realval */
float TimeReactDriver = 0.75;

/* 0..4.5 time before collision 12 object intval=realval */
float TimeReq12 = 0.5;

/* 0..4.5 time before collision 13 object intval=realval */
float TimeReq13 = 2.5;

/* 0..4.5 time before collision 14 object intval=realval */
float TimeReq14 = 0.5;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

