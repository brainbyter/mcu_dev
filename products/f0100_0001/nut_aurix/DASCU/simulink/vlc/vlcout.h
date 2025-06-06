/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* intval=realval*8 */
#define DECLARED_accelerationPedal	accelerationPedal
extern uint16_t accelerationPedal;

/* [Nm] ACC engine torque increase request. intval=realval */
#define DECLARED_ACCMotInc_vlc	ACCMotInc_vlc
extern int16_t ACCMotInc_vlc;

/* 0..3 Status of ACC (0 - inactive, 1 - standby, 2 - active, 3 - overrride) intval=realval */
#define DECLARED_ACCStat	ACCStat
extern uint8_t ACCStat;

/* -1..1 Estimated sinus of road grade intval=realval */
#define DECLARED_AngleEstimation	AngleEstimation
extern float AngleEstimation;

/* [none] intval=realval */
#define DECLARED_ASRinRegulation	ASRinRegulation
extern uint8_t ASRinRegulation;

/* Longitudinal acceleration (MMx sensor) intval=realval */
#define DECLARED_AX_vlc	AX_vlc
extern float AX_vlc;

/* [rad/s] Lateral Acceleration signal routed through ESP intval=realval */
#define DECLARED_AY_vlc	AY_vlc
extern float AY_vlc;

/* integrated flaw intval=realval*1000 */
#define DECLARED_bPID_int	bPID_int
extern int16_t bPID_int;

/* intval=realval */
#define DECLARED_BrakepowerFlg	BrakepowerFlg
extern uint8_t BrakepowerFlg;

/* 0..655.34 [m/c] Speed of output cardan intval=realval*100 */
#define DECLARED_cardanSpeed	cardanSpeed
extern uint16_t cardanSpeed;

/* intval=realval */
#define DECLARED_CddFlag	CddFlag
extern uint8_t CddFlag;

/* intval=realval */
#define DECLARED_Clutched_Status	Clutched_Status
extern uint8_t Clutched_Status;

/* 0..1 Model activation flag for calibrations intval=realval */
#define DECLARED_CrsCtlAndAcc_DBG	CrsCtlAndAcc_DBG
extern uint8_t CrsCtlAndAcc_DBG;

/* 0..22.783 [Nm] Current Transmission Gear Ratio intval=realval*1000 */
#define DECLARED_curTrqRatio	curTrqRatio
extern uint16_t curTrqRatio;

/* intval=realval */
#define DECLARED_decelPlausibility	decelPlausibility
extern uint8_t decelPlausibility;

/* [none] intval=realval */
#define DECLARED_DO_OM_err_tmr	DO_OM_err_tmr
extern uint16_t DO_OM_err_tmr;

/* [none] HUITIMER intval=realval */
#define DECLARED_DO_SSR_err_tmr	DO_SSR_err_tmr
extern uint16_t DO_SSR_err_tmr;

/* 0..255 Approval timer for DriveOff intval=realval */
#define DECLARED_DOV_ApprovalTimer	DOV_ApprovalTimer
extern uint8_t DOV_ApprovalTimer;

/* [Nm] Pedal boost integration trq for driveOff intval=realval*1000 */
#define DECLARED_DOV_bPID_int	DOV_bPID_int
extern int16_t DOV_bPID_int;

/* [Nm] Pedal boost PID trq for driveOff intval=realval */
#define DECLARED_DOV_trqPID	DOV_trqPID
extern int16_t DOV_trqPID;

/* [none] intval=realval */
#define DECLARED_DriveOff_Mode	DriveOff_Mode
extern uint8_t DriveOff_Mode;

/* [Nm] Engine drag intval=realval */
#define DECLARED_EngineDrag	EngineDrag
extern int16_t EngineDrag;

/* [none] Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] intval=realval*100 */
#define DECLARED_EngineInertiaTrq	EngineInertiaTrq
extern int16_t EngineInertiaTrq;

/* [rpm] Engine speed from signal to IC intval=realval */
#define DECLARED_EngineRPM	EngineRPM
extern uint16_t EngineRPM;

/* [Nm] Engine torque at the clutch intval=realval */
#define DECLARED_EngineTorque	EngineTorque
extern int16_t EngineTorque;

/* [m/s^2] AX offset for decel playsibility intval=realval */
#define DECLARED_estAX	estAX
extern float estAX;

/* -3000..3000 [Nm] Free Rolling Drag Force intval=realval*10 */
#define DECLARED_FreeRollingDragForce_BC	FreeRollingDragForce_BC
extern int16_t FreeRollingDragForce_BC;

/* 0..34900 [N] Vehicle weight (basic model) intval=realval */
#define DECLARED_Ga_OLBC	Ga_OLBC
extern uint16_t Ga_OLBC;

/* gear number intval=realval */
#define DECLARED_GearLeverPosition	GearLeverPosition
extern uint16_t GearLeverPosition;

/* gear number req intval=realval */
#define DECLARED_GearLeverReq	GearLeverReq
extern uint16_t GearLeverReq;

/* 0..1 Gear changing flag from TCU intval=realval */
#define DECLARED_gearShift	gearShift
extern uint16_t gearShift;

/* 0..510 [km/h]   intval=realval */
#define DECLARED_IC_speed_vlc	IC_speed_vlc
extern uint16_t IC_speed_vlc;

/* -5..5 [m/s^2] All-limited and filtered acceleration intval=realval*512 */
#define DECLARED_jerkAcceleration	jerkAcceleration
extern int16_t jerkAcceleration;

/* 0..1 Requested acceleration is out of physical baunds intval=realval */
#define DECLARED_jerkFault	jerkFault
extern uint8_t jerkFault;

/* 0..10 Jerk fault counter intval=realval */
#define DECLARED_jerkFaultCounter	jerkFaultCounter
extern uint8_t jerkFaultCounter;

/* 0..1 Jerk fault nter activation intval=realval */
#define DECLARED_jerkFlag	jerkFlag
extern uint8_t jerkFlag;

/* [m/s^2] vehicle longitudinal acceleration intval=realval */
#define DECLARED_LongitudinalAccelerationProc	LongitudinalAccelerationProc
extern float LongitudinalAccelerationProc;

/* -30000..30000 [Nm] Direct AX torque intval=realval */
#define DECLARED_M_MotClutch_DirAx	M_MotClutch_DirAx
extern int32_t M_MotClutch_DirAx;

/* -30000..30000 [Nm] Open-Loop boost controller torque intval=realval */
#define DECLARED_M_MotClutch_OLBC	M_MotClutch_OLBC
extern int16_t M_MotClutch_OLBC;

/* -30000..30000 [Nm] Boost PID controller torque intval=realval */
#define DECLARED_M_MotClutch_PID_Boost	M_MotClutch_PID_Boost
extern int16_t M_MotClutch_PID_Boost;

/* -30000..30000 [Nm] Transmission drag torque intval=realval */
#define DECLARED_M_MotClutch_TDM	M_MotClutch_TDM
extern int16_t M_MotClutch_TDM;

/* [Nm] Torque at the clutch intval=realval */
#define DECLARED_M_MotClutch_vlc	M_MotClutch_vlc
extern int16_t M_MotClutch_vlc;

/* [Nm] Wheels inertia comensation torque intval=realval */
#define DECLARED_M_MotClutch_WI	M_MotClutch_WI
extern int16_t M_MotClutch_WI;

/* intval=realval */
#define DECLARED_MotFlag	MotFlag
extern uint8_t MotFlag;

/* [rpm] Engine speed intval=realval */
#define DECLARED_nICEngineSpeed_vlc	nICEngineSpeed_vlc
extern uint16_t nICEngineSpeed_vlc;

/* 0..15 Number of engaged gear intval=realval */
#define DECLARED_numGearEngaged_vlc	numGearEngaged_vlc
extern uint8_t numGearEngaged_vlc;

/* [none] numGearSwitch intval=realval */
#define DECLARED_numGearSwitch	numGearSwitch
extern uint8_t numGearSwitch;

/* 0..15 Number of engaged gear intval=realval */
#define DECLARED_numGearTarget_vlc	numGearTarget_vlc
extern uint8_t numGearTarget_vlc;

/* 0..655.34 [ms] Current vehicle speed calculated as an average between front wheels intval=realval*100 */
#define DECLARED_objectSpeed	objectSpeed
extern uint16_t objectSpeed;

/* intval=realval */
#define DECLARED_Plaussib_down	Plaussib_down
extern uint8_t Plaussib_down;

/* [rad/s] Yaw rate signal routed through ESP intval=realval */
#define DECLARED_PSIP	PSIP
extern float PSIP;

/* [0]..[425] Estimated brake pressure at front left wheel intval=realval */
#define DECLARED_pWheelFL_vlc	pWheelFL_vlc
extern float pWheelFL_vlc;

/* [0]..[425] Estimated brake pressure at front left wheel intval=realval */
#define DECLARED_pWheelFR_vlc	pWheelFR_vlc
extern float pWheelFR_vlc;

/* [0]..[425] Estimated brake pressure at front left wheel intval=realval */
#define DECLARED_pWheelRL_vlc	pWheelRL_vlc
extern float pWheelRL_vlc;

/* [0]..[425] Estimated brake pressure at front left wheel intval=realval */
#define DECLARED_pWheelRR_vlc	pWheelRR_vlc
extern float pWheelRR_vlc;

/* 0..71 [m/s] Ref speed intval=realval*524287,999999863 */
#define DECLARED_refSpeed	refSpeed
extern uint32_t refSpeed;

/* -5..5 [m/s^2] Requested acceleration intval=realval*100 */
#define DECLARED_reqAcceleration	reqAcceleration
extern int16_t reqAcceleration;

/* 0..65535 Acceleration request for calibrations intval=realval */
#define DECLARED_reqAcceleration_DBG	reqAcceleration_DBG
extern uint16_t reqAcceleration_DBG;

/* -5..5 [m/s^2] Speed-limited request intval=realval*512 */
#define DECLARED_reqAccelerationLimited	reqAccelerationLimited
extern int16_t reqAccelerationLimited;

/* -5..5 [m/s^2] Requested acceleration MAX grade intval=realval*512 */
#define DECLARED_reqAccelerationMAX	reqAccelerationMAX
extern int16_t reqAccelerationMAX;

/* -5..5 [m/s^2] Requested acceleration MIN grade intval=realval*512 */
#define DECLARED_reqAccelerationMIN	reqAccelerationMIN
extern int16_t reqAccelerationMIN;

/* intval=realval*10000 */
#define DECLARED_resultOfIntPID	resultOfIntPID
extern int16_t resultOfIntPID;

/* [deg] Steering wheel angle intval=realval */
#define DECLARED_SAS_angle_vlc	SAS_angle_vlc
extern float SAS_angle_vlc;

/* 0..100 [empty] Coefficient for slope for PI intval=realval */
#define DECLARED_SlopeCoef	SlopeCoef
extern float SlopeCoef;

/* 0..100 [empty] Coefficient for slope for PI from protection timer intval=realval */
#define DECLARED_SlopeCoefProt	SlopeCoefProt
extern float SlopeCoefProt;

/* [Nm] Slope drag torque intval=realval */
#define DECLARED_SlopeDragTorque	SlopeDragTorque
extern int16_t SlopeDragTorque;

/* 0..20 [pc] Slope for PID controller intval=realval */
#define DECLARED_SlopeForPID	SlopeForPID
extern uint32_t SlopeForPID;

/* [none] intval=realval */
#define DECLARED_SSR_timer	SSR_timer
extern uint32_t SSR_timer;

/* 0..1 [none]   intval=realval */
#define DECLARED_st	st
extern uint8_t st;

/* intval=realval */
#define DECLARED_targetSlipSt	targetSlipSt
extern uint8_t targetSlipSt;

/* 0..250 [m/s] Target speed intval=realval*100 */
#define DECLARED_targetSpeed	targetSpeed
extern uint16_t targetSpeed;

/* 0..65535 Target speed for calibrations intval=realval */
#define DECLARED_targetSpeed_DBG	targetSpeed_DBG
extern uint16_t targetSpeed_DBG;

/* 0..250 [m/s] Target speed intval=realval*100 */
#define DECLARED_targetSpeedDelay	targetSpeedDelay
extern uint16_t targetSpeedDelay;

/* 0..250 [m/s] Target speed intval=realval*100 */
#define DECLARED_targetSpeedTemp	targetSpeedTemp
extern uint16_t targetSpeedTemp;

/* 0..250 [none] Timer to hold tirget speed intval=realval */
#define DECLARED_targetSpeedTmr	targetSpeedTmr
extern uint8_t targetSpeedTmr;

/* 0..250 [none] Timer to hold tirget speed intval=realval */
#define DECLARED_targetSpeedTmrFlag	targetSpeedTmrFlag
extern uint8_t targetSpeedTmrFlag;

/* 0..1 Engine test enabled flag. intval=realval */
#define DECLARED_testFlaw	testFlaw
extern int16_t testFlaw;

/* 0..1 Flag: stop torque request intval=realval */
#define DECLARED_torqueCutOff	torqueCutOff
extern uint8_t torqueCutOff;

/* intval=realval*1000 */
#define DECLARED_TorqueRatio	TorqueRatio
extern uint32_t TorqueRatio;

/* Trq time intval=realval */
#define DECLARED_TorqueRatioTmr	TorqueRatioTmr
extern uint32_t TorqueRatioTmr;

/* Curent transmission engaged gear intval=realval */
#define DECLARED_transmRangeEngaged_Curent	transmRangeEngaged_Curent
extern uint16_t transmRangeEngaged_Curent;

/* intval=realval */
#define DECLARED_TrqDwnCntr	TrqDwnCntr
extern uint16_t TrqDwnCntr;

/* [Nm] Torque at the clutch from Speed controller intval=realval */
#define DECLARED_trqI_PID	trqI_PID
extern int16_t trqI_PID;

/* [Nm] Torque at the clutch from Boost controller intval=realval */
#define DECLARED_trqP_PID	trqP_PID
extern int16_t trqP_PID;

/* 0..655.34 [km/h] Current vehicle speed intval=realval*100 */
#define DECLARED_VehicleSpeed_VLCInt	VehicleSpeed_VLCInt
extern uint16_t VehicleSpeed_VLCInt;

/* [none] intval=realval */
#define DECLARED_VehSpd_timer	VehSpd_timer
extern uint16_t VehSpd_timer;

/* [none] intval=realval */
#define DECLARED_VehSpd_tmr_flg	VehSpd_tmr_flg
extern uint8_t VehSpd_tmr_flg;

/* 0..1 VLC availibility flag intval=realval */
#define DECLARED_VLC_Available	VLC_Available
extern uint8_t VLC_Available;

/* intval=realval */
#define DECLARED_VLC_DecelPlausibilityCounter	VLC_DecelPlausibilityCounter
extern uint16_t VLC_DecelPlausibilityCounter;

/* [none] intval=realval */
#define DECLARED_VLC_Mode	VLC_Mode
extern uint8_t VLC_Mode;

/* -30000..30000 [Nm] Torque request (internal) intval=realval */
#define DECLARED_VLC_TargetEngTorque	VLC_TargetEngTorque
extern int16_t VLC_TargetEngTorque;

/* [Nm] Front wheels inertia comensation torque intval=realval */
#define DECLARED_WheelInertia_FA	WheelInertia_FA
extern float WheelInertia_FA;

/* [Nm] Rear wheels inertia comensation torque intval=realval */
#define DECLARED_WheelInertia_RA	WheelInertia_RA
extern float WheelInertia_RA;

/* intval=realval*100 */
#define DECLARED_WheelPressure	WheelPressure
extern uint16_t WheelPressure;

/* [rad/s] calc steady-state vehicle rotational motion of OZ intval=realval */
#define DECLARED_yawRateSS	yawRateSS
extern float yawRateSS;

/* [rad/s] calc steady-state vehicle rotational motion with side slip of OZ intval=realval */
#define DECLARED_yawRateSSwithSlip	yawRateSSwithSlip
extern float yawRateSSwithSlip;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* [m/s^2] Dead zone for speed acceleration limitation intval=realval */
#define DECLARED_AZ5	AZ5
extern float AZ5;

/* [none] Boost PI integration satureation intval=realval */
#define DECLARED_BoostIntegrationLowerSat	BoostIntegrationLowerSat
extern int16_t BoostIntegrationLowerSat;

/* [none] Boost PI integration satureation intval=realval */
#define DECLARED_BoostIntegrationUpperSat	BoostIntegrationUpperSat
extern int16_t BoostIntegrationUpperSat;

/* intval=realval */
#define DECLARED_c_0	c_0
extern uint16_t c_0;

/* [none] intval=realval*100 */
#define DECLARED_c_0_01	c_0_01
extern uint16_t c_0_01;

/* [none] intval=realval*100 */
#define DECLARED_c_0_02	c_0_02
extern uint16_t c_0_02;

/* [none] intval=realval*100 */
#define DECLARED_c_0_03	c_0_03
extern uint16_t c_0_03;

/* [none] intval=realval*100 */
#define DECLARED_c_0_04	c_0_04
extern uint16_t c_0_04;

/* [none] intval=realval*100 */
#define DECLARED_c_0_05	c_0_05
extern uint16_t c_0_05;

/* [none] intval=realval*10 */
#define DECLARED_c_0_1	c_0_1
extern uint16_t c_0_1;

/* [none] intval=realval*10000 */
#define DECLARED_c_0_1274	c_0_1274
extern uint16_t c_0_1274;

/* [none] intval=realval*100 */
#define DECLARED_c_0_28	c_0_28
extern uint16_t c_0_28;

/* [none] intval=realval*100 */
#define DECLARED_c_0_97	c_0_97
extern uint16_t c_0_97;

/* [none] intval=realval */
#define DECLARED_c_1	c_1
extern uint16_t c_1;

/* [none] intval=realval*100 */
#define DECLARED_c_1_02	c_1_02
extern uint16_t c_1_02;

/* [none] intval=realval*100 */
#define DECLARED_c_1_04	c_1_04
extern uint16_t c_1_04;

/* [none] intval=realval*100 */
#define DECLARED_c_1_05	c_1_05
extern uint16_t c_1_05;

/* [none] intval=realval*10 */
#define DECLARED_c_1_4	c_1_4
extern uint16_t c_1_4;

/* [none] intval=realval */
#define DECLARED_c_10	c_10
extern uint16_t c_10;

/* [none] intval=realval */
#define DECLARED_c_100	c_100
extern uint16_t c_100;

/* [none] intval=realval */
#define DECLARED_c_1000	c_1000
extern uint16_t c_1000;

/* [none] intval=realval */
#define DECLARED_c_11	c_11
extern uint16_t c_11;

/* [none] intval=realval */
#define DECLARED_c_15	c_15
extern uint16_t c_15;

/* [none] intval=realval */
#define DECLARED_c_2	c_2
extern uint16_t c_2;

/* [none] intval=realval */
#define DECLARED_c_3	c_3
extern uint16_t c_3;

/* [none] intval=realval*10 */
#define DECLARED_c_3_6	c_3_6
extern uint16_t c_3_6;

/* [none] intval=realval */
#define DECLARED_c_30000	c_30000
extern uint16_t c_30000;

/* [none] intval=realval */
#define DECLARED_c_300n	c_300n
extern int16_t c_300n;

/* [none] intval=realval */
#define DECLARED_c_4	c_4
extern uint16_t c_4;

/* [none] intval=realval*10000 */
#define DECLARED_c_4_1745	c_4_1745
extern uint16_t c_4_1745;

/* [none] intval=realval */
#define DECLARED_c_4095	c_4095
extern uint16_t c_4095;

/* [none] intval=realval */
#define DECLARED_c_5	c_5
extern uint16_t c_5;

/* [none] intval=realval */
#define DECLARED_c_512	c_512
extern uint16_t c_512;

/* [none] intval=realval */
#define DECLARED_c_6	c_6
extern uint16_t c_6;

/* [none] intval=realval */
#define DECLARED_c_65	c_65
extern uint16_t c_65;

/* [none] intval=realval */
#define DECLARED_c_7	c_7
extern uint16_t c_7;

/* [none] intval=realval */
#define DECLARED_c_8	c_8
extern uint16_t c_8;

/* [none] intval=realval */
#define DECLARED_c_9	c_9
extern uint16_t c_9;

/* intval=realval*100 */
#define DECLARED_c_9_81	c_9_81
extern uint16_t c_9_81;

/* [none] intval=realval */
#define DECLARED_c_n_1	c_n_1
extern int16_t c_n_1;

/* [none] intval=realval */
#define DECLARED_c_n_100	c_n_100
extern int16_t c_n_100;

/* [none] MAP intval=realval */
#define DECLARED_DbgSwSpfOffset	DbgSwSpfOffset
extern uint8_t DbgSwSpfOffset;

/* [none] MAP intval=realval */
#define DECLARED_DebugSw1	DebugSw1
extern int8_t DebugSw1;

/* [none] bShiftInProgress intval=realval */
#define DECLARED_DebugSw2	DebugSw2
extern int8_t DebugSw2;

/* [m/s] Tolerance for drag Trq intval=realval*100 */
#define DECLARED_dragTrqTolerance	dragTrqTolerance
extern uint16_t dragTrqTolerance;

/* -50..880 [Nm] Engine drag torque limits intval=realval */
#define DECLARED_engDTCLimits	engDTCLimits
extern int16_t engDTCLimits[13];

/* 500..6000 [rpm] Engine RPM for DTC limits intval=realval */
#define DECLARED_engDTCrpm	engDTCrpm
extern int16_t engDTCrpm[13];

/* [rad/s] Engine idle speed intval=realval */
#define DECLARED_EngineSPDmin	EngineSPDmin
extern uint16_t EngineSPDmin;

/* 0..880 [Nm] intval=realval */
#define DECLARED_engTrqLimits	engTrqLimits
extern int16_t engTrqLimits[13];

/* [m/s^2] Gravity intval=realval*100 */
#define DECLARED_g	g
extern uint16_t g;

/* [none] Gear numbers intval=realval */
#define DECLARED_GearNumber	GearNumber
extern int16_t GearNumber[9];

/* [none] Gear ratios of the gearbox intval=realval*1000 */
#define DECLARED_GearRatio	GearRatio
extern int16_t GearRatio[9];

/* 0..255 [ss] Timer threshold for gear change logic intval=realval */
#define DECLARED_GearTimerThreshold	GearTimerThreshold
extern uint8_t GearTimerThreshold;

/* [none] Jerk min filter coef intval=realval*100 */
#define DECLARED_jrk_fmax	jrk_fmax
extern int16_t jrk_fmax;

/* [none] Jerk min filter coef intval=realval*100 */
#define DECLARED_jrk_fmin	jrk_fmin
extern int16_t jrk_fmin;

/* 0..60000 [Nm] Current virtual engine (combustion engine + e-machine) torque losses intval=realval */
#define DECLARED_M_MotDrag_par	M_MotDrag_par
extern uint16_t M_MotDrag_par;

/* Gear ration of the main gear intval=realval*64 */
#define DECLARED_MainGearRatio	MainGearRatio
extern uint16_t MainGearRatio;

/* 0..1 What algo for AccStat checks to use. 0 - old, ==2; 1 - new, >=2 intval=realval */
#define DECLARED_NewAccStatReqs	NewAccStatReqs
extern uint8_t NewAccStatReqs;

/* 0..4 [m/s^2] Acceleration limitation ot OLBC intval=realval*100 */
#define DECLARED_OLBCAccLim	OLBCAccLim
extern int32_t OLBCAccLim[6];

/* 0..10 [m/s] Speed difference for reqAcceleration limitation to OLBC intval=realval*100 */
#define DECLARED_OLBCAccSpd	OLBCAccSpd
extern int32_t OLBCAccSpd[3];

/* [m] radius pistons front intval=realval*10000 */
#define DECLARED_PistonsF	PistonsF
extern uint16_t PistonsF;

/* [m] radius pistons right intval=realval*10000 */
#define DECLARED_PistonsR	PistonsR
extern uint16_t PistonsR;

/* 0..6000 [Nm] intval=realval */
#define DECLARED_rpm	rpm
extern int16_t rpm[13];

/* Threshold for clutched status intval=realval*1000 */
#define DECLARED_TorqueRatioThreshold	TorqueRatioThreshold
extern uint16_t TorqueRatioThreshold;

/* Threshold for timer for clutched status intval=realval */
#define DECLARED_TorqueRatioTmrMax	TorqueRatioTmrMax
extern uint8_t TorqueRatioTmrMax;

/* 0..880 [Hm] intval=realval */
#define DECLARED_trqLimits	trqLimits
extern int16_t trqLimits[9];

/* 0..56 [m/s] Maximum speed for slope grad control intval=realval */
#define DECLARED_VehicleSpeed_SlopeGradMaxSpd	VehicleSpeed_SlopeGradMaxSpd
extern float VehicleSpeed_SlopeGradMaxSpd;

/* [m/s] Vehicle speed intval=realval*100 */
#define DECLARED_vehSpeed	vehSpeed
extern int32_t vehSpeed[2];

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

