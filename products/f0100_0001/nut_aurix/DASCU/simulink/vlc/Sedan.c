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

/* [Nm] intval=realval*100 */
const uint16_t Sedan_accelerationForSpdOffset[13] = { 0U, 30U, 40U, 50U, 60U, 70U, 80U, 90U, 100U, 140U, 150U, 150U, 150U };

/* [m/s^2] AX offset for decel playsibility intval=realval */
const float Sedan_AX_offSet = 2.0;

/* Filter for ax in slope model intval=realval */
const float Sedan_AX_YRS_f = 0.1;

/* 0..300 intval=realval*100 */
const int16_t Sedan_B_MAP[9] = { 260, 399, 593, 798, 1000, 1206, 1412, 1614, 1821 };

/* 0..1 [none] carrent solver step of model intval=realval*10000 */
const int16_t Sedan_B_pidC_h = 100;

/* 0..5 [none] Boost controller I calibration gain intval=realval*100 */
const int16_t Sedan_bki_cal_coef = 0;

/* 0..300 [none] Boost Ki table intval=realval*100 */
const int16_t Sedan_bkit[10] = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 };

/* 0..6 Boost controller P calibration gain intval=realval*100 */
const int16_t Sedan_bkp_cal_coef = 200;

/* -5..5 [m/s] Boost flaw intval=realval*100 */
const int16_t Sedan_bkpf[10] = { -500, -200, -100, -50, -10, 10, 50, 100, 200, 500 };

/* 0..300 [none] Boost Kp table intval=realval*100 */
const int16_t Sedan_bkpt[10] = { 100, 120, 160, 270, 320, 320, 270, 160, 120, 100 };

/* 0..300 [none] Boost Kp table intval=realval*100 */
const int16_t Sedan_bkptForSpeed[10] = { 230, 150, 150, 100, 40, 40, 100, 150, 150, 230 };

/* [none] Calibrated parametr of the boost controller intval=realval*100 */
const int16_t Sedan_boostCalibration = 0;

/* 0..1 [m] Middle half-radius, front disk intval=realval */
const float Sedan_BrakeDiskR_F = 0.0845;

/* 0..1 [m] Middle half-radius, rear disk intval=realval */
const float Sedan_BrakeDiskR_R = 0.0845;

/* 0..1 [m] First front piston radius intval=realval */
const float Sedan_BrakePistonR_F1 = 0.038;

/* 0..1 [m] Second front piston radius intval=realval */
const float Sedan_BrakePistonR_F2 = 0.04;

/* 0..1 [m] Third front piston radius intval=realval */
const float Sedan_BrakePistonR_F3 = 0.044;

/* 0..1 [m] First rear piston radius intval=realval */
const float Sedan_BrakePistonR_R1 = 0.034;

/* 0..1 [m] Second rear piston radius intval=realval */
const float Sedan_BrakePistonR_R2 = 0.038;

/* 0..1 debug switch for engine inertia intval=realval */
const uint8_t Sedan_dbg_eng = 0U;

/* 0..1 debug switch for slope calculation intval=realval */
const uint8_t Sedan_dbg_slope = 1U;

/* 0..1 debug switch for wheels inertia intval=realval */
const uint8_t Sedan_dbg_wheels = 1U;

/* [none] intval=realval */
const uint16_t Sedan_dbg1EngineModel = 0U;

/* [none] intval=realval */
const uint16_t Sedan_dbg2EngineModel = 0U;

/* 0..10 [none] DirectAXControl P calibration coefficient intval=realval */
const float Sedan_directAX_P[16] = { 0.0000000E+000, 0.0000000E+000, 0.1, 0.175, 0.35, 0.35, 0.35, 0.4, 0.4, 0.4, 0.45, 0.45, 0.45, 0.45, 0.45, 0.45 };

/* [none] intval=realval */
const uint16_t Sedan_DO_SSR_err_tmr_max = 9U;

/* 0..1 [none] Drive off factor for approval intval=realval*100 */
const int32_t Sedan_DOV_ApprovTrqFactor = 50;

/* -100..100 [Nm] Drive off offSet for approval intval=realval */
const int32_t Sedan_DOV_ApprovTrqOffSet = -15;

/* 0..5 [none] Pedal boost calibration coef for driveOff intval=realval*100 */
const uint16_t Sedan_DOV_bkiCal = 30U;

/* 0..5 [none] Pedal boost calibration coef for driveOff intval=realval*100 */
const uint16_t Sedan_DOV_bkpCal = 300U;

/* 0..254 Approval timer max for drive-off intval=realval */
const uint8_t Sedan_DOV_TimerMax = 100U;

/* 0..255 Approval timer threshold for drive-off intval=realval */
const uint8_t Sedan_DOV_TimerThreshold = 10U;

/* -100..100 [Nm] Drive off torque offset intval=realval */
const int8_t Sedan_DOV_TrqOffset = 0;

/* 0..655.35 [km/h] min vehicle speed to exit DO mode intval=realval*100 */
const uint16_t Sedan_DOV_VehSpdMax = 700U;

/* 0..655.35 [km/h] min vehicle speed to exit DO mode intval=realval*100 */
const uint16_t Sedan_DOV_VehSpdMin = 200U;

/* [none] Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] intval=realval*100 */
const uint16_t Sedan_EngineAccelFilter = 15U;

/* [none] Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] intval=realval*100 */
const uint16_t Sedan_EngineInertia = 24U;

/* [none] Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] intval=realval*100 */
const uint16_t Sedan_EngineSpdFilter = 50U;

/* [rpm] Threshold for engine speed for drag torque control intval=realval */
const uint16_t Sedan_engRPMThreshold_DTC = 1500U;

/* [m/s] Free Rolling Resistance breakpoints intval=realval*100 */
const uint16_t Sedan_FreeRollingResistanceBP[16] = { 0U, 100U, 500U, 1000U, 1500U, 2000U, 2500U, 3000U, 3500U, 4000U, 4500U, 5000U, 5500U, 6000U, 6500U, 7000U };

/* [none] Free Rolling Resistance table data for light sedan intval=realval*1000 */
const int16_t Sedan_FreeRollingResistanceTD[16] = { -128, -119, -114, -128, -150, -183, -277, -282, -344, -411, -480, -552, -623, -623, -623, -623 };

/* 1..9 intval=realval*100 */
const int16_t Sedan_Gb_MAP[9] = { 100, 200, 300, 400, 500, 600, 700, 800, 900 };

/* 0..300 intval=realval*100 */
const int16_t Sedan_I_boost[9] = { 423, 819, 1215, 1636, 2050, 2472, 2895, 3310, 3735 };

/* 0..5 [kg*(m^2)] Front wheels moment of inertia intval=realval */
const float Sedan_J_Wheel_FA = 3.16;

/* 0..5 [kg*(m^2)] Rear wheels moment of inertia intval=realval */
const float Sedan_J_Wheel_RA = 3.08;

/* -100..100 intval=realval*100 */
const int16_t Sedan_JerFcn[99] = { 
	100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100
};

/* -7..7 intval=realval*100 */
const int16_t Sedan_JerMAP[11] = { -500, -400, -300, -200, -100, 0, 100, 200, 300, 400, 500 };

/* [rad] lateral Loud for side Slip Angle intval=realval */
const float Sedan_lateralLoud[15] = { -8.0, -7.0, -6.0, -5.0, -4.0, -2.0, -1.0, 0.0000000E+000, 1.0, 2.0, 4.0, 5.0, 6.0, 7.0, 8.0 };

/* Filter for longitudinal acceleration in slope model intval=realval */
const float Sedan_LongitudinalAcceleration_f = 0.02;

/* [none] Inertia factor for rotation intval=realval*100 */
const int16_t Sedan_MassFactor_MAP[9] = { 100, 100, 100, 100, 100, 100, 100, 100, 100 };

/* Negative PID border (OLBC_Max-C=MinPID) intval=realval */
const int16_t Sedan_MinimumPIDTrqReq = 100;

/* Brake pads friction coefficient intval=realval*100 */
const uint16_t Sedan_mu_pad = 70U;

/* [none] a table of road mu intval=realval*100 */
const int16_t Sedan_muTable[5] = { -100, -50, 0, 50, 100 };

/* [ms^2] Offset for pitch compensation - accelertions intval=realval */
const float Sedan_Offset_roadgrade_accelerations[11] = { -2.0, -1.5, -1.0, -0.5, -0.2, 0.0000000E+000, 0.2, 0.5, 1.0, 1.5, 2.0 };

/* [gfrac] Offset for pitch compensation - offset intval=realval */
const float Sedan_Offset_roadgrade_table[11] = { -0.25, -0.2, -0.15, -0.1, -0.05, 0.0000000E+000, 0.05, 0.1, 0.15, 0.2, 0.25 };

/* Calibrated parametr for compensation vehicle mass in OLBC intval=realval*100 */
const uint16_t Sedan_parametrOLBC_mdlCompensation = 15U;

/* Pedal filter coef intval=realval*100 */
const int16_t Sedan_Pedal_f = 1;

/* [none] intval=realval*10 */
const uint16_t Sedan_PlausibilityDec = 10U;

/* [none] intval=realval */
const uint16_t Sedan_PlausibilityInc_ax = 1U;

/* [none] intval=realval */
const uint16_t Sedan_PlausibilityInc_trq = 2U;

/* [none] intval=realval */
const uint16_t Sedan_PlausibilitySum = 5U;

/* [none] intval=realval*100 */
const uint16_t Sedan_PlaussibFltCnst = 1U;

/* [m] radius effective front intval=realval*100000 */
const uint16_t Sedan_RadiusEffF = 10175U;

/* [m] radius effective front intval=realval*10000 */
const uint16_t Sedan_RadiusEffR = 1065U;

/* [percent] intval=realval */
const uint8_t Sedan_RawSensor[12] = { 0U, 5U, 10U, 15U, 20U, 25U, 30U, 36U, 41U, 47U, 50U, 100U };

/* [m] Dinamic radius intval=realval*100 */
const uint16_t Sedan_rd = 39U;

/* Final filter for slope model intval=realval */
const float Sedan_RoadangleAcceleration_f = 0.09;

/* 0..1 [none] carrent solver step of model intval=realval*10000 */
const int16_t Sedan_S_pidC_h = 100;

/* [none] intval=realval*8 */
const uint16_t Sedan_setPointAcclPedal = 160U;

/* intval=realval*100 */
const uint16_t Sedan_sideslip_angle_koef = 50U;

/* [rad] side Slip Angle intval=realval */
const float Sedan_sideSlipAngle[15] = { -0.14, -0.14, -0.14, -0.14, -0.16, -0.18, -0.22, -0.24, -0.22, -0.18, -0.16, -0.14, -0.14, -0.14, -0.14 };

/* [none] target wheel slip intval=realval*100 */
const int16_t Sedan_slipSpeedOffset[16] = { 200, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

/* 0..20 [pc] Slope in percent for speed and boost slope-based gain intval=realval */
const float Sedan_Slope_BP[10] = { 0.0000000E+000, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0, 20.0 };

/* 0..5 [none] Slope-dependent gain for speedCalibration intval=realval */
const float Sedan_Slope_KI_Gain[10] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

/* 0..5 [none] Slope-dependent gain for bkp_cal_coef intval=realval */
const float Sedan_Slope_KP_Gain = 1.0;

/* 0..255 [ticks] Approval timer for slope change intval=realval */
const float Sedan_SlopeApproveTmr[7] = { 35.0, 35.0, 35.0, 35.0, 35.0, 30.0, 30.0 };

/* -1..1 [1] Slope change threshold (SlopeTarget - SlopeHystDec) intval=realval */
const float Sedan_SlopeHystDec = -0.12;

/* -1..1 [1] Slope change threshold (SlopeTarget - SlopeHystInc) intval=realval */
const float Sedan_SlopeHystInc = 0.15;

/* [none] intval=realval*100 */
const int16_t Sedan_SP_I_ACC_MAP[5] = { 10, 12, 15, 20, 35 };

/* [none] intval=realval*100 */
const int16_t Sedan_SP_I_MAX_MAP[5] = { 100, 93, 80, 60, 0 };

/* Calibrated parametr of the speed controller intval=realval*100 */
const int16_t Sedan_speedCalibration = 150;

/* Speed I integration satureation intval=realval */
const int16_t Sedan_SpeedIntegrationLowerSat = -1;

/* Speed I integration satureation intval=realval */
const int16_t Sedan_SpeedIntegrationUpperSat = 1;

/* [Nm] intval=realval*100 */
const uint16_t Sedan_speedOffset[13] = { 0U, 10U, 20U, 30U, 40U, 50U, 60U, 70U, 80U, 90U, 100U, 110U, 120U };

/* [m/s] start speed for slip control intval=realval*100 */
const int16_t Sedan_speedOffsetSlipCntrl = 100;

/* Factor for speed slip dependent on speed intval=realval*100 */
const int16_t Sedan_SpeedSlipFactor[16] = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 };

/* [ms] Factor for speed slip breakpoints intval=realval*100 */
const int16_t Sedan_SpeedSlipFactorSpd[16] = { 0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500 };

/* [none] intval=realval */
const uint16_t Sedan_speedVariant = 0U;

/* [none] intval=realval */
const uint32_t Sedan_SSR_tmr_max = 3800U;

/* ratio of the steering gear intval=realval*100 */
const uint16_t Sedan_steerGearRat = 1780U;

/* [Nm] intval=realval */
const uint16_t Sedan_TargetEngTorque[12] = { 0U, 3U, 6U, 8U, 15U, 25U, 31U, 70U, 99U, 112U, 120U, 153U };

/* [none] target wheel slip intval=realval*100 */
const int16_t Sedan_targetSlip[5] = { 10, 10, 10, 10, 10 };

/* [none] factor for deactiwation target wheel slip logic intval=realval*100 */
const int16_t Sedan_targetSlipFactor = 95;

/* 0..250 [kmph] Offset for Target speed intval=realval*100 */
const uint16_t Sedan_TargetSpdOffSet = 60U;

/* [none] Torque filter coef intval=realval*100 */
const int16_t Sedan_trq_f = 5;

/* [none] intval=realval */
const uint16_t Sedan_TrqDwnCntrMax = 3U;

/* 0..1000 [Hm] intval=realval */
const int16_t Sedan_trqLimits_PI_Boost[9] = { 550, 650, 750, 880, 880, 880, 880, 880, 880 };

/* [none] intval=realval*100 */
const int16_t Sedan_tS_f_MAP[3] = { -100, -200, -400 };

/* [none] intval=realval*100 */
const int16_t Sedan_tS_f_reqAcceleration_MAP[3] = { 10, 30, 50 };

/* Vehicle base intval=realval*10 */
const uint8_t Sedan_vehicleBase = 33U;

/* 0..56 [m/s] Breakpoints for slope grad control intval=realval*100 */
const uint16_t Sedan_VehicleSpeed_BKPGradBP[8] = { 0U, 278U, 556U, 833U, 1389U, 1944U, 2500U, 3333U };

/* 0..2 [m/cs] Coefficients for BP grad control intval=realval*100 */
const uint16_t Sedan_VehicleSpeed_BKPGradTD[8] = { 15U, 15U, 21U, 28U, 48U, 67U, 88U, 122U };

/* Filter for VehicleSpeed in slope model intval=realval */
const float Sedan_VehicleSpeed_f = 0.1;

/* 0..56 [m/s] Breakpoints for slope grad control intval=realval */
const float Sedan_VehicleSpeed_SlopeGradBP[7] = { 0.0000000E+000, 5.56, 8.33, 11.11, 13.89, 16.67, 19.44 };

/* 0..2 [gfrac/sec] Coefficients for slope grad control intval=realval */
const float Sedan_VehicleSpeed_SlopeGradTD[7] = { 0.1, 0.1, 0.13, 0.16, 0.19, 0.22, 0.25 };

/* [none] intval=realval */
const uint16_t Sedan_VehSpd_tmr_max = 1000U;

/* [kg] Free vehicle mass intval=realval */
const uint16_t Sedan_WghtCurb = 3235U;

/* [kg] Loaded vehicle mass intval=realval */
const uint16_t Sedan_WghtFull = 3490U;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif


#include "VINdependentVars.h"

void ApplyParameters_Sedan()
{
   int i = 0;
   for(i = 0; i < 13; i++)
   {
      accelerationForSpdOffset[i] = Sedan_accelerationForSpdOffset[i];
   }
   AX_offSet = Sedan_AX_offSet;
   AX_YRS_f = Sedan_AX_YRS_f;
   for(i = 0; i < 9; i++)
   {
      B_MAP[i] = Sedan_B_MAP[i];
   }
   B_pidC_h = Sedan_B_pidC_h;
   bki_cal_coef = Sedan_bki_cal_coef;
   for(i = 0; i < 10; i++)
   {
      bkit[i] = Sedan_bkit[i];
   }
   bkp_cal_coef = Sedan_bkp_cal_coef;
   for(i = 0; i < 10; i++)
   {
      bkpf[i] = Sedan_bkpf[i];
   }
   for(i = 0; i < 10; i++)
   {
      bkpt[i] = Sedan_bkpt[i];
   }
   for(i = 0; i < 10; i++)
   {
      bkptForSpeed[i] = Sedan_bkptForSpeed[i];
   }
   boostCalibration = Sedan_boostCalibration;
   BrakeDiskR_F = Sedan_BrakeDiskR_F;
   BrakeDiskR_R = Sedan_BrakeDiskR_R;
   BrakePistonR_F1 = Sedan_BrakePistonR_F1;
   BrakePistonR_F2 = Sedan_BrakePistonR_F2;
   BrakePistonR_F3 = Sedan_BrakePistonR_F3;
   BrakePistonR_R1 = Sedan_BrakePistonR_R1;
   BrakePistonR_R2 = Sedan_BrakePistonR_R2;
   dbg_eng = Sedan_dbg_eng;
   dbg_slope = Sedan_dbg_slope;
   dbg_wheels = Sedan_dbg_wheels;
   dbg1EngineModel = Sedan_dbg1EngineModel;
   dbg2EngineModel = Sedan_dbg2EngineModel;
   for(i = 0; i < 16; i++)
   {
      directAX_P[i] = Sedan_directAX_P[i];
   }
   DO_SSR_err_tmr_max = Sedan_DO_SSR_err_tmr_max;
   DOV_ApprovTrqFactor = Sedan_DOV_ApprovTrqFactor;
   DOV_ApprovTrqOffSet = Sedan_DOV_ApprovTrqOffSet;
   DOV_bkiCal = Sedan_DOV_bkiCal;
   DOV_bkpCal = Sedan_DOV_bkpCal;
   DOV_TimerMax = Sedan_DOV_TimerMax;
   DOV_TimerThreshold = Sedan_DOV_TimerThreshold;
   DOV_TrqOffset = Sedan_DOV_TrqOffset;
   DOV_VehSpdMax = Sedan_DOV_VehSpdMax;
   DOV_VehSpdMin = Sedan_DOV_VehSpdMin;
   EngineAccelFilter = Sedan_EngineAccelFilter;
   EngineInertia = Sedan_EngineInertia;
   EngineSpdFilter = Sedan_EngineSpdFilter;
   engRPMThreshold_DTC = Sedan_engRPMThreshold_DTC;
   for(i = 0; i < 16; i++)
   {
      FreeRollingResistanceBP[i] = Sedan_FreeRollingResistanceBP[i];
   }
   for(i = 0; i < 16; i++)
   {
      FreeRollingResistanceTD[i] = Sedan_FreeRollingResistanceTD[i];
   }
   for(i = 0; i < 9; i++)
   {
      Gb_MAP[i] = Sedan_Gb_MAP[i];
   }
   for(i = 0; i < 9; i++)
   {
      I_boost[i] = Sedan_I_boost[i];
   }
   J_Wheel_FA = Sedan_J_Wheel_FA;
   J_Wheel_RA = Sedan_J_Wheel_RA;
   for(i = 0; i < 99; i++)
   {
      JerFcn[i] = Sedan_JerFcn[i];
   }
   for(i = 0; i < 11; i++)
   {
      JerMAP[i] = Sedan_JerMAP[i];
   }
   for(i = 0; i < 15; i++)
   {
      lateralLoud[i] = Sedan_lateralLoud[i];
   }
   LongitudinalAcceleration_f = Sedan_LongitudinalAcceleration_f;
   for(i = 0; i < 9; i++)
   {
      MassFactor_MAP[i] = Sedan_MassFactor_MAP[i];
   }
   MinimumPIDTrqReq = Sedan_MinimumPIDTrqReq;
   mu_pad = Sedan_mu_pad;
   for(i = 0; i < 5; i++)
   {
      muTable[i] = Sedan_muTable[i];
   }
   for(i = 0; i < 11; i++)
   {
      Offset_roadgrade_accelerations[i] = Sedan_Offset_roadgrade_accelerations[i];
   }
   for(i = 0; i < 11; i++)
   {
      Offset_roadgrade_table[i] = Sedan_Offset_roadgrade_table[i];
   }
   parametrOLBC_mdlCompensation = Sedan_parametrOLBC_mdlCompensation;
   Pedal_f = Sedan_Pedal_f;
   PlausibilityDec = Sedan_PlausibilityDec;
   PlausibilityInc_ax = Sedan_PlausibilityInc_ax;
   PlausibilityInc_trq = Sedan_PlausibilityInc_trq;
   PlausibilitySum = Sedan_PlausibilitySum;
   PlaussibFltCnst = Sedan_PlaussibFltCnst;
   RadiusEffF = Sedan_RadiusEffF;
   RadiusEffR = Sedan_RadiusEffR;
   for(i = 0; i < 12; i++)
   {
      RawSensor[i] = Sedan_RawSensor[i];
   }
   rd = Sedan_rd;
   RoadangleAcceleration_f = Sedan_RoadangleAcceleration_f;
   S_pidC_h = Sedan_S_pidC_h;
   setPointAcclPedal = Sedan_setPointAcclPedal;
   sideslip_angle_koef = Sedan_sideslip_angle_koef;
   for(i = 0; i < 15; i++)
   {
      sideSlipAngle[i] = Sedan_sideSlipAngle[i];
   }
   for(i = 0; i < 16; i++)
   {
      slipSpeedOffset[i] = Sedan_slipSpeedOffset[i];
   }
   for(i = 0; i < 10; i++)
   {
      Slope_BP[i] = Sedan_Slope_BP[i];
   }
   for(i = 0; i < 10; i++)
   {
      Slope_KI_Gain[i] = Sedan_Slope_KI_Gain[i];
   }
   Slope_KP_Gain = Sedan_Slope_KP_Gain;
   for(i = 0; i < 7; i++)
   {
      SlopeApproveTmr[i] = Sedan_SlopeApproveTmr[i];
   }
   SlopeHystDec = Sedan_SlopeHystDec;
   SlopeHystInc = Sedan_SlopeHystInc;
   for(i = 0; i < 5; i++)
   {
      SP_I_ACC_MAP[i] = Sedan_SP_I_ACC_MAP[i];
   }
   for(i = 0; i < 5; i++)
   {
      SP_I_MAX_MAP[i] = Sedan_SP_I_MAX_MAP[i];
   }
   speedCalibration = Sedan_speedCalibration;
   SpeedIntegrationLowerSat = Sedan_SpeedIntegrationLowerSat;
   SpeedIntegrationUpperSat = Sedan_SpeedIntegrationUpperSat;
   for(i = 0; i < 13; i++)
   {
      speedOffset[i] = Sedan_speedOffset[i];
   }
   speedOffsetSlipCntrl = Sedan_speedOffsetSlipCntrl;
   for(i = 0; i < 16; i++)
   {
      SpeedSlipFactor[i] = Sedan_SpeedSlipFactor[i];
   }
   for(i = 0; i < 16; i++)
   {
      SpeedSlipFactorSpd[i] = Sedan_SpeedSlipFactorSpd[i];
   }
   speedVariant = Sedan_speedVariant;
   SSR_tmr_max = Sedan_SSR_tmr_max;
   steerGearRat = Sedan_steerGearRat;
   for(i = 0; i < 12; i++)
   {
      TargetEngTorque[i] = Sedan_TargetEngTorque[i];
   }
   for(i = 0; i < 5; i++)
   {
      targetSlip[i] = Sedan_targetSlip[i];
   }
   targetSlipFactor = Sedan_targetSlipFactor;
   TargetSpdOffSet = Sedan_TargetSpdOffSet;
   trq_f = Sedan_trq_f;
   TrqDwnCntrMax = Sedan_TrqDwnCntrMax;
   for(i = 0; i < 9; i++)
   {
      trqLimits_PI_Boost[i] = Sedan_trqLimits_PI_Boost[i];
   }
   for(i = 0; i < 3; i++)
   {
      tS_f_MAP[i] = Sedan_tS_f_MAP[i];
   }
   for(i = 0; i < 3; i++)
   {
      tS_f_reqAcceleration_MAP[i] = Sedan_tS_f_reqAcceleration_MAP[i];
   }
   vehicleBase = Sedan_vehicleBase;
   for(i = 0; i < 8; i++)
   {
      VehicleSpeed_BKPGradBP[i] = Sedan_VehicleSpeed_BKPGradBP[i];
   }
   for(i = 0; i < 8; i++)
   {
      VehicleSpeed_BKPGradTD[i] = Sedan_VehicleSpeed_BKPGradTD[i];
   }
   VehicleSpeed_f = Sedan_VehicleSpeed_f;
   for(i = 0; i < 7; i++)
   {
      VehicleSpeed_SlopeGradBP[i] = Sedan_VehicleSpeed_SlopeGradBP[i];
   }
   for(i = 0; i < 7; i++)
   {
      VehicleSpeed_SlopeGradTD[i] = Sedan_VehicleSpeed_SlopeGradTD[i];
   }
   VehSpd_tmr_max = Sedan_VehSpd_tmr_max;
   WghtCurb = Sedan_WghtCurb;
   WghtFull = Sedan_WghtFull;
}
