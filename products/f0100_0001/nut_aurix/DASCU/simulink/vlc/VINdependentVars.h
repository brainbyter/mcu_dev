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
#define DECLARED_accelerationForSpdOffset	accelerationForSpdOffset
extern uint16_t accelerationForSpdOffset[13];

/* [m/s^2] AX offset for decel playsibility intval=realval */
#define DECLARED_AX_offSet	AX_offSet
extern float AX_offSet;

/* Filter for ax in slope model intval=realval */
#define DECLARED_AX_YRS_f	AX_YRS_f
extern float AX_YRS_f;

/* 0..300 intval=realval*100 */
#define DECLARED_B_MAP	B_MAP
extern int16_t B_MAP[9];

/* 0..1 [none] carrent solver step of model intval=realval*10000 */
#define DECLARED_B_pidC_h	B_pidC_h
extern int16_t B_pidC_h;

/* 0..5 [none] Boost controller I calibration gain intval=realval*100 */
#define DECLARED_bki_cal_coef	bki_cal_coef
extern int16_t bki_cal_coef;

/* 0..300 [none] Boost Ki table intval=realval*100 */
#define DECLARED_bkit	bkit
extern int16_t bkit[10];

/* 0..6 Boost controller P calibration gain intval=realval*100 */
#define DECLARED_bkp_cal_coef	bkp_cal_coef
extern int16_t bkp_cal_coef;

/* -5..5 [m/s] Boost flaw intval=realval*100 */
#define DECLARED_bkpf	bkpf
extern int16_t bkpf[10];

/* 0..300 [none] Boost Kp table intval=realval*100 */
#define DECLARED_bkpt	bkpt
extern int16_t bkpt[10];

/* 0..300 [none] Boost Kp table intval=realval*100 */
#define DECLARED_bkptForSpeed	bkptForSpeed
extern int16_t bkptForSpeed[10];

/* [none] Calibrated parametr of the boost controller intval=realval*100 */
#define DECLARED_boostCalibration	boostCalibration
extern int16_t boostCalibration;

/* 0..1 [m] Middle half-radius, front disk intval=realval */
#define DECLARED_BrakeDiskR_F	BrakeDiskR_F
extern float BrakeDiskR_F;

/* 0..1 [m] Middle half-radius, rear disk intval=realval */
#define DECLARED_BrakeDiskR_R	BrakeDiskR_R
extern float BrakeDiskR_R;

/* 0..1 [m] First front piston radius intval=realval */
#define DECLARED_BrakePistonR_F1	BrakePistonR_F1
extern float BrakePistonR_F1;

/* 0..1 [m] Second front piston radius intval=realval */
#define DECLARED_BrakePistonR_F2	BrakePistonR_F2
extern float BrakePistonR_F2;

/* 0..1 [m] Third front piston radius intval=realval */
#define DECLARED_BrakePistonR_F3	BrakePistonR_F3
extern float BrakePistonR_F3;

/* 0..1 [m] First rear piston radius intval=realval */
#define DECLARED_BrakePistonR_R1	BrakePistonR_R1
extern float BrakePistonR_R1;

/* 0..1 [m] Second rear piston radius intval=realval */
#define DECLARED_BrakePistonR_R2	BrakePistonR_R2
extern float BrakePistonR_R2;

/* 0..1 debug switch for engine inertia intval=realval */
#define DECLARED_dbg_eng	dbg_eng
extern uint8_t dbg_eng;

/* 0..1 debug switch for slope calculation intval=realval */
#define DECLARED_dbg_slope	dbg_slope
extern uint8_t dbg_slope;

/* 0..1 debug switch for wheels inertia intval=realval */
#define DECLARED_dbg_wheels	dbg_wheels
extern uint8_t dbg_wheels;

/* [none] intval=realval */
#define DECLARED_dbg1EngineModel	dbg1EngineModel
extern uint16_t dbg1EngineModel;

/* [none] intval=realval */
#define DECLARED_dbg2EngineModel	dbg2EngineModel
extern uint16_t dbg2EngineModel;

/* 0..10 [none] DirectAXControl P calibration coefficient intval=realval */
#define DECLARED_directAX_P	directAX_P
extern float directAX_P[16];

/* [none] intval=realval */
#define DECLARED_DO_SSR_err_tmr_max	DO_SSR_err_tmr_max
extern uint16_t DO_SSR_err_tmr_max;

/* 0..1 [none] Drive off factor for approval intval=realval*100 */
#define DECLARED_DOV_ApprovTrqFactor	DOV_ApprovTrqFactor
extern int32_t DOV_ApprovTrqFactor;

/* -100..100 [Nm] Drive off offSet for approval intval=realval */
#define DECLARED_DOV_ApprovTrqOffSet	DOV_ApprovTrqOffSet
extern int32_t DOV_ApprovTrqOffSet;

/* 0..5 [none] Pedal boost calibration coef for driveOff intval=realval*100 */
#define DECLARED_DOV_bkiCal	DOV_bkiCal
extern uint16_t DOV_bkiCal;

/* 0..5 [none] Pedal boost calibration coef for driveOff intval=realval*100 */
#define DECLARED_DOV_bkpCal	DOV_bkpCal
extern uint16_t DOV_bkpCal;

/* 0..254 Approval timer max for drive-off intval=realval */
#define DECLARED_DOV_TimerMax	DOV_TimerMax
extern uint8_t DOV_TimerMax;

/* 0..255 Approval timer threshold for drive-off intval=realval */
#define DECLARED_DOV_TimerThreshold	DOV_TimerThreshold
extern uint8_t DOV_TimerThreshold;

/* -100..100 [Nm] Drive off torque offset intval=realval */
#define DECLARED_DOV_TrqOffset	DOV_TrqOffset
extern int8_t DOV_TrqOffset;

/* 0..655.35 [km/h] min vehicle speed to exit DO mode intval=realval*100 */
#define DECLARED_DOV_VehSpdMax	DOV_VehSpdMax
extern uint16_t DOV_VehSpdMax;

/* 0..655.35 [km/h] min vehicle speed to exit DO mode intval=realval*100 */
#define DECLARED_DOV_VehSpdMin	DOV_VehSpdMin
extern uint16_t DOV_VehSpdMin;

/* [none] Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] intval=realval*100 */
#define DECLARED_EngineAccelFilter	EngineAccelFilter
extern uint16_t EngineAccelFilter;

/* [none] Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] intval=realval*100 */
#define DECLARED_EngineInertia	EngineInertia
extern uint16_t EngineInertia;

/* [none] Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] intval=realval*100 */
#define DECLARED_EngineSpdFilter	EngineSpdFilter
extern uint16_t EngineSpdFilter;

/* [rpm] Threshold for engine speed for drag torque control intval=realval */
#define DECLARED_engRPMThreshold_DTC	engRPMThreshold_DTC
extern uint16_t engRPMThreshold_DTC;

/* [m/s] Free Rolling Resistance breakpoints intval=realval*100 */
#define DECLARED_FreeRollingResistanceBP	FreeRollingResistanceBP
extern uint16_t FreeRollingResistanceBP[16];

/* [none] Free Rolling Resistance table data for light sedan intval=realval*1000 */
#define DECLARED_FreeRollingResistanceTD	FreeRollingResistanceTD
extern int16_t FreeRollingResistanceTD[16];

/* 1..9 intval=realval*100 */
#define DECLARED_Gb_MAP	Gb_MAP
extern int16_t Gb_MAP[9];

/* 0..300 intval=realval*100 */
#define DECLARED_I_boost	I_boost
extern int16_t I_boost[9];

/* 0..5 [kg*(m^2)] Front wheels moment of inertia intval=realval */
#define DECLARED_J_Wheel_FA	J_Wheel_FA
extern float J_Wheel_FA;

/* 0..5 [kg*(m^2)] Rear wheels moment of inertia intval=realval */
#define DECLARED_J_Wheel_RA	J_Wheel_RA
extern float J_Wheel_RA;

/* -100..100 intval=realval*100 */
#define DECLARED_JerFcn	JerFcn
extern int16_t JerFcn[99];

/* -7..7 intval=realval*100 */
#define DECLARED_JerMAP	JerMAP
extern int16_t JerMAP[11];

/* [rad] lateral Loud for side Slip Angle intval=realval */
#define DECLARED_lateralLoud	lateralLoud
extern float lateralLoud[15];

/* Filter for longitudinal acceleration in slope model intval=realval */
#define DECLARED_LongitudinalAcceleration_f	LongitudinalAcceleration_f
extern float LongitudinalAcceleration_f;

/* [none] Inertia factor for rotation intval=realval*100 */
#define DECLARED_MassFactor_MAP	MassFactor_MAP
extern int16_t MassFactor_MAP[9];

/* Negative PID border (OLBC_Max-C=MinPID) intval=realval */
#define DECLARED_MinimumPIDTrqReq	MinimumPIDTrqReq
extern int16_t MinimumPIDTrqReq;

/* Brake pads friction coefficient intval=realval*100 */
#define DECLARED_mu_pad	mu_pad
extern uint16_t mu_pad;

/* [none] a table of road mu intval=realval*100 */
#define DECLARED_muTable	muTable
extern int16_t muTable[5];

/* [ms^2] Offset for pitch compensation - accelertions intval=realval */
#define DECLARED_Offset_roadgrade_accelerations	Offset_roadgrade_accelerations
extern float Offset_roadgrade_accelerations[11];

/* [gfrac] Offset for pitch compensation - offset intval=realval */
#define DECLARED_Offset_roadgrade_table	Offset_roadgrade_table
extern float Offset_roadgrade_table[11];

/* Calibrated parametr for compensation vehicle mass in OLBC intval=realval*100 */
#define DECLARED_parametrOLBC_mdlCompensation	parametrOLBC_mdlCompensation
extern uint16_t parametrOLBC_mdlCompensation;

/* Pedal filter coef intval=realval*100 */
#define DECLARED_Pedal_f	Pedal_f
extern int16_t Pedal_f;

/* [none] intval=realval*10 */
#define DECLARED_PlausibilityDec	PlausibilityDec
extern uint16_t PlausibilityDec;

/* [none] intval=realval */
#define DECLARED_PlausibilityInc_ax	PlausibilityInc_ax
extern uint16_t PlausibilityInc_ax;

/* [none] intval=realval */
#define DECLARED_PlausibilityInc_trq	PlausibilityInc_trq
extern uint16_t PlausibilityInc_trq;

/* [none] intval=realval */
#define DECLARED_PlausibilitySum	PlausibilitySum
extern uint16_t PlausibilitySum;

/* [none] intval=realval*100 */
#define DECLARED_PlaussibFltCnst	PlaussibFltCnst
extern uint16_t PlaussibFltCnst;

/* [m] radius effective front intval=realval*100000 */
#define DECLARED_RadiusEffF	RadiusEffF
extern uint16_t RadiusEffF;

/* [m] radius effective front intval=realval*10000 */
#define DECLARED_RadiusEffR	RadiusEffR
extern uint16_t RadiusEffR;

/* [percent] intval=realval */
#define DECLARED_RawSensor	RawSensor
extern uint8_t RawSensor[12];

/* [m] Dinamic radius intval=realval*100 */
#define DECLARED_rd	rd
extern uint16_t rd;

/* Final filter for slope model intval=realval */
#define DECLARED_RoadangleAcceleration_f	RoadangleAcceleration_f
extern float RoadangleAcceleration_f;

/* 0..1 [none] carrent solver step of model intval=realval*10000 */
#define DECLARED_S_pidC_h	S_pidC_h
extern int16_t S_pidC_h;

/* [none] intval=realval*8 */
#define DECLARED_setPointAcclPedal	setPointAcclPedal
extern uint16_t setPointAcclPedal;

/* intval=realval*100 */
#define DECLARED_sideslip_angle_koef	sideslip_angle_koef
extern uint16_t sideslip_angle_koef;

/* [rad] side Slip Angle intval=realval */
#define DECLARED_sideSlipAngle	sideSlipAngle
extern float sideSlipAngle[15];

/* [none] target wheel slip intval=realval*100 */
#define DECLARED_slipSpeedOffset	slipSpeedOffset
extern int16_t slipSpeedOffset[16];

/* 0..20 [pc] Slope in percent for speed and boost slope-based gain intval=realval */
#define DECLARED_Slope_BP	Slope_BP
extern float Slope_BP[10];

/* 0..5 [none] Slope-dependent gain for speedCalibration intval=realval */
#define DECLARED_Slope_KI_Gain	Slope_KI_Gain
extern float Slope_KI_Gain[10];

/* 0..5 [none] Slope-dependent gain for bkp_cal_coef intval=realval */
#define DECLARED_Slope_KP_Gain	Slope_KP_Gain
extern float Slope_KP_Gain;

/* 0..255 [ticks] Approval timer for slope change intval=realval */
#define DECLARED_SlopeApproveTmr	SlopeApproveTmr
extern float SlopeApproveTmr[7];

/* -1..1 [1] Slope change threshold (SlopeTarget - SlopeHystDec) intval=realval */
#define DECLARED_SlopeHystDec	SlopeHystDec
extern float SlopeHystDec;

/* -1..1 [1] Slope change threshold (SlopeTarget - SlopeHystInc) intval=realval */
#define DECLARED_SlopeHystInc	SlopeHystInc
extern float SlopeHystInc;

/* [none] intval=realval*100 */
#define DECLARED_SP_I_ACC_MAP	SP_I_ACC_MAP
extern int16_t SP_I_ACC_MAP[5];

/* [none] intval=realval*100 */
#define DECLARED_SP_I_MAX_MAP	SP_I_MAX_MAP
extern int16_t SP_I_MAX_MAP[5];

/* Calibrated parametr of the speed controller intval=realval*100 */
#define DECLARED_speedCalibration	speedCalibration
extern int16_t speedCalibration;

/* Speed I integration satureation intval=realval */
#define DECLARED_SpeedIntegrationLowerSat	SpeedIntegrationLowerSat
extern int16_t SpeedIntegrationLowerSat;

/* Speed I integration satureation intval=realval */
#define DECLARED_SpeedIntegrationUpperSat	SpeedIntegrationUpperSat
extern int16_t SpeedIntegrationUpperSat;

/* [Nm] intval=realval*100 */
#define DECLARED_speedOffset	speedOffset
extern uint16_t speedOffset[13];

/* [m/s] start speed for slip control intval=realval*100 */
#define DECLARED_speedOffsetSlipCntrl	speedOffsetSlipCntrl
extern int16_t speedOffsetSlipCntrl;

/* Factor for speed slip dependent on speed intval=realval*100 */
#define DECLARED_SpeedSlipFactor	SpeedSlipFactor
extern int16_t SpeedSlipFactor[16];

/* [ms] Factor for speed slip breakpoints intval=realval*100 */
#define DECLARED_SpeedSlipFactorSpd	SpeedSlipFactorSpd
extern int16_t SpeedSlipFactorSpd[16];

/* [none] intval=realval */
#define DECLARED_speedVariant	speedVariant
extern uint16_t speedVariant;

/* [none] intval=realval */
#define DECLARED_SSR_tmr_max	SSR_tmr_max
extern uint32_t SSR_tmr_max;

/* ratio of the steering gear intval=realval*100 */
#define DECLARED_steerGearRat	steerGearRat
extern uint16_t steerGearRat;

/* [Nm] intval=realval */
#define DECLARED_TargetEngTorque	TargetEngTorque
extern uint16_t TargetEngTorque[12];

/* [none] target wheel slip intval=realval*100 */
#define DECLARED_targetSlip	targetSlip
extern int16_t targetSlip[5];

/* [none] factor for deactiwation target wheel slip logic intval=realval*100 */
#define DECLARED_targetSlipFactor	targetSlipFactor
extern int16_t targetSlipFactor;

/* 0..250 [kmph] Offset for Target speed intval=realval*100 */
#define DECLARED_TargetSpdOffSet	TargetSpdOffSet
extern uint16_t TargetSpdOffSet;

/* [none] Torque filter coef intval=realval*100 */
#define DECLARED_trq_f	trq_f
extern int16_t trq_f;

/* [none] intval=realval */
#define DECLARED_TrqDwnCntrMax	TrqDwnCntrMax
extern uint16_t TrqDwnCntrMax;

/* 0..1000 [Hm] intval=realval */
#define DECLARED_trqLimits_PI_Boost	trqLimits_PI_Boost
extern int16_t trqLimits_PI_Boost[9];

/* [none] intval=realval*100 */
#define DECLARED_tS_f_MAP	tS_f_MAP
extern int16_t tS_f_MAP[3];

/* [none] intval=realval*100 */
#define DECLARED_tS_f_reqAcceleration_MAP	tS_f_reqAcceleration_MAP
extern int16_t tS_f_reqAcceleration_MAP[3];

/* Vehicle base intval=realval*10 */
#define DECLARED_vehicleBase	vehicleBase
extern uint8_t vehicleBase;

/* 0..56 [m/s] Breakpoints for slope grad control intval=realval*100 */
#define DECLARED_VehicleSpeed_BKPGradBP	VehicleSpeed_BKPGradBP
extern uint16_t VehicleSpeed_BKPGradBP[8];

/* 0..2 [m/cs] Coefficients for BP grad control intval=realval*100 */
#define DECLARED_VehicleSpeed_BKPGradTD	VehicleSpeed_BKPGradTD
extern uint16_t VehicleSpeed_BKPGradTD[8];

/* Filter for VehicleSpeed in slope model intval=realval */
#define DECLARED_VehicleSpeed_f	VehicleSpeed_f
extern float VehicleSpeed_f;

/* 0..56 [m/s] Breakpoints for slope grad control intval=realval */
#define DECLARED_VehicleSpeed_SlopeGradBP	VehicleSpeed_SlopeGradBP
extern float VehicleSpeed_SlopeGradBP[7];

/* 0..2 [gfrac/sec] Coefficients for slope grad control intval=realval */
#define DECLARED_VehicleSpeed_SlopeGradTD	VehicleSpeed_SlopeGradTD
extern float VehicleSpeed_SlopeGradTD[7];

/* [none] intval=realval */
#define DECLARED_VehSpd_tmr_max	VehSpd_tmr_max
extern uint16_t VehSpd_tmr_max;

/* [kg] Free vehicle mass intval=realval */
#define DECLARED_WghtCurb	WghtCurb
extern uint16_t WghtCurb;

/* [kg] Loaded vehicle mass intval=realval */
#define DECLARED_WghtFull	WghtFull
extern uint16_t WghtFull;

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

