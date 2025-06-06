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
uint16_t accelerationForSpdOffset[13] = { 0U, 30U, 40U, 50U, 60U, 70U, 80U, 90U, 100U, 140U, 150U, 150U, 150U };

/* [m/s^2] AX offset for decel playsibility intval=realval */
float AX_offSet = 2.0;

/* Filter for ax in slope model intval=realval */
float AX_YRS_f = 0.03;

/* 0..300 intval=realval*100 */
int16_t B_MAP[9] = { 206, 399, 593, 798, 1000, 1206, 1412, 1614, 1821 };

/* 0..1 [none] carrent solver step of model intval=realval*10000 */
int16_t B_pidC_h = 100;

/* 0..5 [none] Boost controller I calibration gain intval=realval*100 */
int16_t bki_cal_coef = 0;

/* 0..300 [none] Boost Ki table intval=realval*100 */
int16_t bkit[10] = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 };

/* 0..6 Boost controller P calibration gain intval=realval*100 */
int16_t bkp_cal_coef = 220;

/* -5..5 [m/s] Boost flaw intval=realval*100 */
int16_t bkpf[10] = { -500, -200, -100, -50, -10, 10, 50, 100, 200, 500 };

/* 0..300 [none] Boost Kp table intval=realval*100 */
int16_t bkpt[10] = { 30, 50, 80, 130, 140, 280, 260, 160, 80, 40 };

/* 0..300 [none] Boost Kp table intval=realval*100 */
int16_t bkptForSpeed[10] = { 230, 150, 150, 100, 40, 40, 100, 150, 150, 230 };

/* [none] Calibrated parametr of the boost controller intval=realval*100 */
int16_t boostCalibration = 0;

/* 0..1 [m] Middle half-radius, front disk intval=realval */
float BrakeDiskR_F = 0.0845;

/* 0..1 [m] Middle half-radius, rear disk intval=realval */
float BrakeDiskR_R = 0.0845;

/* 0..1 [m] First front piston radius intval=realval */
float BrakePistonR_F1 = 0.038;

/* 0..1 [m] Second front piston radius intval=realval */
float BrakePistonR_F2 = 0.04;

/* 0..1 [m] Third front piston radius intval=realval */
float BrakePistonR_F3 = 0.044;

/* 0..1 [m] First rear piston radius intval=realval */
float BrakePistonR_R1 = 0.034;

/* 0..1 [m] Second rear piston radius intval=realval */
float BrakePistonR_R2 = 0.038;

/* 0..1 debug switch for engine inertia intval=realval */
uint8_t dbg_eng = 0U;

/* 0..1 debug switch for slope calculation intval=realval */
uint8_t dbg_slope = 1U;

/* 0..1 debug switch for wheels inertia intval=realval */
uint8_t dbg_wheels = 1U;

/* [none] intval=realval */
uint16_t dbg1EngineModel = 0U;

/* [none] intval=realval */
uint16_t dbg2EngineModel = 0U;

/* 0..10 [none] DirectAXControl P calibration coefficient intval=realval */
float directAX_P[16] = { 0.0000000E+000, 0.0000000E+000, 0.1, 0.18, 0.225, 0.225, 0.225, 0.45, 0.45, 0.45, 0.45, 0.45, 0.45, 0.45, 0.45, 0.45 };

/* [none] intval=realval */
uint16_t DO_SSR_err_tmr_max = 9U;

/* 0..1 [none] Drive off factor for approval intval=realval*100 */
int32_t DOV_ApprovTrqFactor = 50;

/* -100..100 [Nm] Drive off offSet for approval intval=realval */
int32_t DOV_ApprovTrqOffSet = -15;

/* 0..5 [none] Pedal boost calibration coef for driveOff intval=realval*100 */
uint16_t DOV_bkiCal = 0U;

/* 0..5 [none] Pedal boost calibration coef for driveOff intval=realval*100 */
uint16_t DOV_bkpCal = 300U;

/* 0..254 Approval timer max for drive-off intval=realval */
uint8_t DOV_TimerMax = 100U;

/* 0..255 Approval timer threshold for drive-off intval=realval */
uint8_t DOV_TimerThreshold = 80U;

/* -100..100 [Nm] Drive off torque offset intval=realval */
int8_t DOV_TrqOffset = 0;

/* 0..655.35 [km/h] min vehicle speed to exit DO mode intval=realval*100 */
uint16_t DOV_VehSpdMax = 700U;

/* 0..655.35 [km/h] min vehicle speed to exit DO mode intval=realval*100 */
uint16_t DOV_VehSpdMin = 200U;

/* [none] Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] intval=realval*100 */
uint16_t EngineAccelFilter = 15U;

/* [none] Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] intval=realval*100 */
uint16_t EngineInertia = 24U;

/* [none] Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] intval=realval*100 */
uint16_t EngineSpdFilter = 50U;

/* [rpm] Threshold for engine speed for drag torque control intval=realval */
uint16_t engRPMThreshold_DTC = 1500U;

/* [m/s] Free Rolling Resistance breakpoints intval=realval*100 */
uint16_t FreeRollingResistanceBP[16] = { 0U, 100U, 500U, 1000U, 1500U, 2000U, 2500U, 3000U, 3500U, 4000U, 4500U, 5000U, 5500U, 6000U, 6500U, 7000U };

/* [none] Free Rolling Resistance table data for light sedan intval=realval*1000 */
int16_t FreeRollingResistanceTD[16] = { -100, -94, -99, -129, -164, -213, -275, -347, -423, -504, -586, -670, -670, -670, -670, -670 };

/* 1..9 intval=realval*100 */
int16_t Gb_MAP[9] = { 100, 200, 300, 400, 500, 600, 700, 800, 900 };

/* 0..300 intval=realval*100 */
int16_t I_boost[9] = { 423, 819, 1215, 1636, 2050, 2472, 2895, 3310, 3735 };

/* 0..5 [kg*(m^2)] Front wheels moment of inertia intval=realval */
float J_Wheel_FA = 3.16;

/* 0..5 [kg*(m^2)] Rear wheels moment of inertia intval=realval */
float J_Wheel_RA = 3.08;

/* -100..100 intval=realval*100 */
int16_t JerFcn[99] = { 
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
int16_t JerMAP[11] = { -500, -400, -300, -200, -100, 0, 100, 200, 300, 400, 500 };

/* [rad] lateral Loud for side Slip Angle intval=realval */
float lateralLoud[15] = { -8.0, -7.0, -6.0, -5.0, -4.0, -2.0, -1.0, 0.0000000E+000, 1.0, 2.0, 4.0, 5.0, 6.0, 7.0, 8.0 };

/* Filter for longitudinal acceleration in slope model intval=realval */
float LongitudinalAcceleration_f = 0.02;

/* [none] Inertia factor for rotation intval=realval*100 */
int16_t MassFactor_MAP[9] = { 100, 100, 100, 100, 100, 100, 100, 100, 100 };

/* Negative PID border (OLBC_Max-C=MinPID) intval=realval */
int16_t MinimumPIDTrqReq = 100;

/* Brake pads friction coefficient intval=realval*100 */
uint16_t mu_pad = 70U;

/* [none] a table of road mu intval=realval*100 */
int16_t muTable[5] = { -100, -50, 0, 50, 100 };

/* [ms^2] Offset for pitch compensation - accelertions intval=realval */
float Offset_roadgrade_accelerations[11] = { -2.0, -1.5, -1.0, -0.5, -0.2, 0.0000000E+000, 0.2, 0.5, 1.0, 1.5, 2.0 };

/* [gfrac] Offset for pitch compensation - offset intval=realval */
float Offset_roadgrade_table[11] = { -0.5, -0.4, -0.3, -0.2, -0.1, 0.0000000E+000, 0.1, 0.2, 0.3, 0.4, 0.5 };

/* Calibrated parametr for compensation vehicle mass in OLBC intval=realval*100 */
uint16_t parametrOLBC_mdlCompensation = 15U;

/* Pedal filter coef intval=realval*100 */
int16_t Pedal_f = 1;

/* [none] intval=realval*10 */
uint16_t PlausibilityDec = 10U;

/* [none] intval=realval */
uint16_t PlausibilityInc_ax = 1U;

/* [none] intval=realval */
uint16_t PlausibilityInc_trq = 2U;

/* [none] intval=realval */
uint16_t PlausibilitySum = 5U;

/* [none] intval=realval*100 */
uint16_t PlaussibFltCnst = 1U;

/* [m] radius effective front intval=realval*100000 */
uint16_t RadiusEffF = 10175U;

/* [m] radius effective front intval=realval*10000 */
uint16_t RadiusEffR = 1065U;

/* [percent] intval=realval */
uint8_t RawSensor[12] = { 0U, 5U, 10U, 15U, 20U, 25U, 30U, 36U, 41U, 47U, 50U, 100U };

/* [m] Dinamic radius intval=realval*100 */
uint16_t rd = 39U;

/* Final filter for slope model intval=realval */
float RoadangleAcceleration_f = 0.09;

/* 0..1 [none] carrent solver step of model intval=realval*10000 */
int16_t S_pidC_h = 100;

/* [none] intval=realval*8 */
uint16_t setPointAcclPedal = 160U;

/* intval=realval*100 */
uint16_t sideslip_angle_koef = 50U;

/* [rad] side Slip Angle intval=realval */
float sideSlipAngle[15] = { -0.14, -0.14, -0.14, -0.14, -0.16, -0.18, -0.22, -0.24, -0.22, -0.18, -0.16, -0.14, -0.14, -0.14, -0.14 };

/* [none] target wheel slip intval=realval*100 */
int16_t slipSpeedOffset[16] = { 200, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

/* 0..20 [pc] Slope in percent for speed and boost slope-based gain intval=realval */
float Slope_BP[10] = { 0.0000000E+000, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0, 20.0 };

/* 0..5 [none] Slope-dependent gain for speedCalibration intval=realval */
float Slope_KI_Gain[10] = { 1.0, 1.0, 1.2, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

/* 0..5 [none] Slope-dependent gain for bkp_cal_coef intval=realval */
float Slope_KP_Gain = 1.0;

/* 0..255 [ticks] Approval timer for slope change intval=realval */
float SlopeApproveTmr[7] = { 35.0, 35.0, 35.0, 35.0, 35.0, 35.0, 35.0 };

/* -1..1 [1] Slope change threshold (SlopeTarget - SlopeHystDec) intval=realval */
float SlopeHystDec = -0.12;

/* -1..1 [1] Slope change threshold (SlopeTarget - SlopeHystInc) intval=realval */
float SlopeHystInc = 0.15;

/* [none] intval=realval*100 */
int16_t SP_I_ACC_MAP[5] = { 10, 12, 15, 20, 35 };

/* [none] intval=realval*100 */
int16_t SP_I_MAX_MAP[5] = { 100, 93, 80, 50, 0 };

/* Calibrated parametr of the speed controller intval=realval*100 */
int16_t speedCalibration = 160;

/* Speed I integration satureation intval=realval */
int16_t SpeedIntegrationLowerSat = -1;

/* Speed I integration satureation intval=realval */
int16_t SpeedIntegrationUpperSat = 1;

/* [Nm] intval=realval*100 */
uint16_t speedOffset[13] = { 0U, 10U, 20U, 30U, 40U, 50U, 60U, 70U, 80U, 90U, 100U, 110U, 120U };

/* [m/s] start speed for slip control intval=realval*100 */
int16_t speedOffsetSlipCntrl = 100;

/* Factor for speed slip dependent on speed intval=realval*100 */
int16_t SpeedSlipFactor[16] = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 };

/* [ms] Factor for speed slip breakpoints intval=realval*100 */
int16_t SpeedSlipFactorSpd[16] = { 0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500 };

/* [none] intval=realval */
uint16_t speedVariant = 0U;

/* [none] intval=realval */
uint32_t SSR_tmr_max = 3800U;

/* ratio of the steering gear intval=realval*100 */
uint16_t steerGearRat = 1780U;

/* [Nm] intval=realval */
uint16_t TargetEngTorque[12] = { 0U, 3U, 6U, 8U, 15U, 25U, 31U, 70U, 99U, 112U, 120U, 153U };

/* [none] target wheel slip intval=realval*100 */
int16_t targetSlip[5] = { 4, 4, 4, 4, 4 };

/* [none] factor for deactiwation target wheel slip logic intval=realval*100 */
int16_t targetSlipFactor = 95;

/* 0..250 [kmph] Offset for Target speed intval=realval*100 */
uint16_t TargetSpdOffSet = 60U;

/* [none] Torque filter coef intval=realval*100 */
int16_t trq_f = 15;

/* [none] intval=realval */
uint16_t TrqDwnCntrMax = 3U;

/* 0..1000 [Hm] intval=realval */
int16_t trqLimits_PI_Boost[9] = { 550, 650, 750, 880, 880, 880, 880, 880, 880 };

/* [none] intval=realval*100 */
int16_t tS_f_MAP[3] = { -100, -200, -400 };

/* [none] intval=realval*100 */
int16_t tS_f_reqAcceleration_MAP[3] = { 10, 30, 50 };

/* Vehicle base intval=realval*10 */
uint8_t vehicleBase = 31U;

/* 0..56 [m/s] Breakpoints for slope grad control intval=realval*100 */
uint16_t VehicleSpeed_BKPGradBP[8] = { 0U, 278U, 556U, 833U, 1389U, 1944U, 2500U, 3333U };

/* 0..2 [m/cs] Coefficients for BP grad control intval=realval*100 */
uint16_t VehicleSpeed_BKPGradTD[8] = { 15U, 15U, 21U, 35U, 53U, 68U, 88U, 122U };

/* Filter for VehicleSpeed in slope model intval=realval */
float VehicleSpeed_f = 0.17;

/* 0..56 [m/s] Breakpoints for slope grad control intval=realval */
float VehicleSpeed_SlopeGradBP[7] = { 0.0000000E+000, 5.56, 8.33, 11.11, 13.89, 16.67, 19.44 };

/* 0..2 [gfrac/sec] Coefficients for slope grad control intval=realval */
float VehicleSpeed_SlopeGradTD[7] = { 0.1, 0.1, 0.13, 0.16, 0.19, 0.22, 0.25 };

/* [none] intval=realval */
uint16_t VehSpd_tmr_max = 1000U;

/* [kg] Free vehicle mass intval=realval */
uint16_t WghtCurb = 3175U;

/* [kg] Loaded vehicle mass intval=realval */
uint16_t WghtFull = 3490U;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

