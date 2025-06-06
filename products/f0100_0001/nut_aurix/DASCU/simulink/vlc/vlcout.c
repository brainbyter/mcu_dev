/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* intval=realval*8 */
uint16_t accelerationPedal = 0U;

/* [Nm] ACC engine torque increase request. intval=realval */
int16_t ACCMotInc_vlc = 0;

/* 0..3 Status of ACC (0 - inactive, 1 - standby, 2 - active, 3 - overrride) intval=realval */
uint8_t ACCStat = 0U;

/* -1..1 Estimated sinus of road grade intval=realval */
float AngleEstimation = 0.0000000E+000;

/* [none] intval=realval */
uint8_t ASRinRegulation = 0U;

/* Longitudinal acceleration (MMx sensor) intval=realval */
float AX_vlc = 0.0000000E+000;

/* [rad/s] Lateral Acceleration signal routed through ESP intval=realval */
float AY_vlc = 0.0000000E+000;

/* integrated flaw intval=realval*1000 */
int16_t bPID_int = 0;

/* intval=realval */
uint8_t BrakepowerFlg = 0U;

/* 0..655.34 [m/c] Speed of output cardan intval=realval*100 */
uint16_t cardanSpeed = 0U;

/* intval=realval */
uint8_t CddFlag = 0U;

/* intval=realval */
uint8_t Clutched_Status = 0U;

/* 0..1 Model activation flag for calibrations intval=realval */
uint8_t CrsCtlAndAcc_DBG = 0U;

/* 0..22.783 [Nm] Current Transmission Gear Ratio intval=realval*1000 */
uint16_t curTrqRatio = 22783U;

/* intval=realval */
uint8_t decelPlausibility = 0U;

/* [none] intval=realval */
uint16_t DO_OM_err_tmr = 9U;

/* [none] HUITIMER intval=realval */
uint16_t DO_SSR_err_tmr = 0U;

/* 0..255 Approval timer for DriveOff intval=realval */
uint8_t DOV_ApprovalTimer = 0U;

/* [Nm] Pedal boost integration trq for driveOff intval=realval*1000 */
int16_t DOV_bPID_int = 0;

/* [Nm] Pedal boost PID trq for driveOff intval=realval */
int16_t DOV_trqPID = 0;

/* [none] intval=realval */
uint8_t DriveOff_Mode = 0U;

/* [Nm] Engine drag intval=realval */
int16_t EngineDrag = 0;

/* [none] Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] intval=realval*100 */
int16_t EngineInertiaTrq = 0;

/* [rpm] Engine speed from signal to IC intval=realval */
uint16_t EngineRPM = 0U;

/* [Nm] Engine torque at the clutch intval=realval */
int16_t EngineTorque = 0;

/* [m/s^2] AX offset for decel playsibility intval=realval */
float estAX = 0.0000000E+000;

/* -3000..3000 [Nm] Free Rolling Drag Force intval=realval*10 */
int16_t FreeRollingDragForce_BC = 0;

/* 0..34900 [N] Vehicle weight (basic model) intval=realval */
uint16_t Ga_OLBC = 0U;

/* gear number intval=realval */
uint16_t GearLeverPosition = 0U;

/* gear number req intval=realval */
uint16_t GearLeverReq = 7U;

/* 0..1 Gear changing flag from TCU intval=realval */
uint16_t gearShift = 0U;

/* 0..510 [km/h]   intval=realval */
uint16_t IC_speed_vlc = 0U;

/* -5..5 [m/s^2] All-limited and filtered acceleration intval=realval*512 */
int16_t jerkAcceleration = 0;

/* 0..1 Requested acceleration is out of physical baunds intval=realval */
uint8_t jerkFault = 0U;

/* 0..10 Jerk fault counter intval=realval */
uint8_t jerkFaultCounter = 0U;

/* 0..1 Jerk fault nter activation intval=realval */
uint8_t jerkFlag = 0U;

/* [m/s^2] vehicle longitudinal acceleration intval=realval */
float LongitudinalAccelerationProc = 0.0000000E+000;

/* -30000..30000 [Nm] Direct AX torque intval=realval */
int32_t M_MotClutch_DirAx = 0;

/* -30000..30000 [Nm] Open-Loop boost controller torque intval=realval */
int16_t M_MotClutch_OLBC = 0;

/* -30000..30000 [Nm] Boost PID controller torque intval=realval */
int16_t M_MotClutch_PID_Boost = 0;

/* -30000..30000 [Nm] Transmission drag torque intval=realval */
int16_t M_MotClutch_TDM = 0;

/* [Nm] Torque at the clutch intval=realval */
int16_t M_MotClutch_vlc = 0;

/* [Nm] Wheels inertia comensation torque intval=realval */
int16_t M_MotClutch_WI = 0;

/* intval=realval */
uint8_t MotFlag = 0U;

/* [rpm] Engine speed intval=realval */
uint16_t nICEngineSpeed_vlc = 0U;

/* 0..15 Number of engaged gear intval=realval */
uint8_t numGearEngaged_vlc = 15U;

/* [none] numGearSwitch intval=realval */
uint8_t numGearSwitch = 0U;

/* 0..15 Number of engaged gear intval=realval */
uint8_t numGearTarget_vlc = 15U;

/* 0..655.34 [ms] Current vehicle speed calculated as an average between front wheels intval=realval*100 */
uint16_t objectSpeed = 0U;

/* intval=realval */
uint8_t Plaussib_down = 0U;

/* [rad/s] Yaw rate signal routed through ESP intval=realval */
float PSIP = 0.0000000E+000;

/* [0]..[425] Estimated brake pressure at front left wheel intval=realval */
float pWheelFL_vlc = 0.0000000E+000;

/* [0]..[425] Estimated brake pressure at front left wheel intval=realval */
float pWheelFR_vlc = 0.0000000E+000;

/* [0]..[425] Estimated brake pressure at front left wheel intval=realval */
float pWheelRL_vlc = 0.0000000E+000;

/* [0]..[425] Estimated brake pressure at front left wheel intval=realval */
float pWheelRR_vlc = 0.0000000E+000;

/* 0..71 [m/s] Ref speed intval=realval*524287,999999863 */
uint32_t refSpeed = 0U;

/* -5..5 [m/s^2] Requested acceleration intval=realval*100 */
int16_t reqAcceleration = 0;

/* 0..65535 Acceleration request for calibrations intval=realval */
uint16_t reqAcceleration_DBG = 0U;

/* -5..5 [m/s^2] Speed-limited request intval=realval*512 */
int16_t reqAccelerationLimited = 0;

/* -5..5 [m/s^2] Requested acceleration MAX grade intval=realval*512 */
int16_t reqAccelerationMAX = 0;

/* -5..5 [m/s^2] Requested acceleration MIN grade intval=realval*512 */
int16_t reqAccelerationMIN = 0;

/* intval=realval*10000 */
int16_t resultOfIntPID = 0;

/* [deg] Steering wheel angle intval=realval */
float SAS_angle_vlc = 0.0000000E+000;

/* 0..100 [empty] Coefficient for slope for PI intval=realval */
float SlopeCoef = 0.0000000E+000;

/* 0..100 [empty] Coefficient for slope for PI from protection timer intval=realval */
float SlopeCoefProt = 0.0000000E+000;

/* [Nm] Slope drag torque intval=realval */
int16_t SlopeDragTorque = 0;

/* 0..20 [pc] Slope for PID controller intval=realval */
uint32_t SlopeForPID = 0U;

/* [none] intval=realval */
uint32_t SSR_timer = 0U;

/* 0..1 [none]   intval=realval */
uint8_t st = 0U;

/* intval=realval */
uint8_t targetSlipSt = 0U;

/* 0..250 [m/s] Target speed intval=realval*100 */
uint16_t targetSpeed = 0U;

/* 0..65535 Target speed for calibrations intval=realval */
uint16_t targetSpeed_DBG = 0U;

/* 0..250 [m/s] Target speed intval=realval*100 */
uint16_t targetSpeedDelay = 0U;

/* 0..250 [m/s] Target speed intval=realval*100 */
uint16_t targetSpeedTemp = 0U;

/* 0..250 [none] Timer to hold tirget speed intval=realval */
uint8_t targetSpeedTmr = 0U;

/* 0..250 [none] Timer to hold tirget speed intval=realval */
uint8_t targetSpeedTmrFlag = 0U;

/* 0..1 Engine test enabled flag. intval=realval */
int16_t testFlaw = 0;

/* 0..1 Flag: stop torque request intval=realval */
uint8_t torqueCutOff = 0U;

/* intval=realval*1000 */
uint32_t TorqueRatio = 0U;

/* Trq time intval=realval */
uint32_t TorqueRatioTmr = 0U;

/* Curent transmission engaged gear intval=realval */
uint16_t transmRangeEngaged_Curent = 1U;

/* intval=realval */
uint16_t TrqDwnCntr = 0U;

/* [Nm] Torque at the clutch from Speed controller intval=realval */
int16_t trqI_PID = 0;

/* [Nm] Torque at the clutch from Boost controller intval=realval */
int16_t trqP_PID = 0;

/* 0..655.34 [km/h] Current vehicle speed intval=realval*100 */
uint16_t VehicleSpeed_VLCInt = 0U;

/* [none] intval=realval */
uint16_t VehSpd_timer = 0U;

/* [none] intval=realval */
uint8_t VehSpd_tmr_flg = 0U;

/* 0..1 VLC availibility flag intval=realval */
uint8_t VLC_Available = 1U;

/* intval=realval */
uint16_t VLC_DecelPlausibilityCounter = 0U;

/* [none] intval=realval */
uint8_t VLC_Mode = 1U;

/* -30000..30000 [Nm] Torque request (internal) intval=realval */
int16_t VLC_TargetEngTorque = 0;

/* [Nm] Front wheels inertia comensation torque intval=realval */
float WheelInertia_FA = 0.0000000E+000;

/* [Nm] Rear wheels inertia comensation torque intval=realval */
float WheelInertia_RA = 0.0000000E+000;

/* intval=realval*100 */
uint16_t WheelPressure = 0U;

/* [rad/s] calc steady-state vehicle rotational motion of OZ intval=realval */
float yawRateSS = 0.0000000E+000;

/* [rad/s] calc steady-state vehicle rotational motion with side slip of OZ intval=realval */
float yawRateSSwithSlip = 0.0000000E+000;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* [m/s^2] Dead zone for speed acceleration limitation intval=realval */
float AZ5 = 0.1;

/* [none] Boost PI integration satureation intval=realval */
int16_t BoostIntegrationLowerSat = -2;

/* [none] Boost PI integration satureation intval=realval */
int16_t BoostIntegrationUpperSat = 2;

/* intval=realval */
uint16_t c_0 = 0U;

/* [none] intval=realval*100 */
uint16_t c_0_01 = 1U;

/* [none] intval=realval*100 */
uint16_t c_0_02 = 2U;

/* [none] intval=realval*100 */
uint16_t c_0_03 = 3U;

/* [none] intval=realval*100 */
uint16_t c_0_04 = 4U;

/* [none] intval=realval*100 */
uint16_t c_0_05 = 5U;

/* [none] intval=realval*10 */
uint16_t c_0_1 = 1U;

/* [none] intval=realval*10000 */
uint16_t c_0_1274 = 1274U;

/* [none] intval=realval*100 */
uint16_t c_0_28 = 28U;

/* [none] intval=realval*100 */
uint16_t c_0_97 = 97U;

/* [none] intval=realval */
uint16_t c_1 = 1U;

/* [none] intval=realval*100 */
uint16_t c_1_02 = 102U;

/* [none] intval=realval*100 */
uint16_t c_1_04 = 104U;

/* [none] intval=realval*100 */
uint16_t c_1_05 = 105U;

/* [none] intval=realval*10 */
uint16_t c_1_4 = 14U;

/* [none] intval=realval */
uint16_t c_10 = 10U;

/* [none] intval=realval */
uint16_t c_100 = 100U;

/* [none] intval=realval */
uint16_t c_1000 = 1000U;

/* [none] intval=realval */
uint16_t c_11 = 11U;

/* [none] intval=realval */
uint16_t c_15 = 15U;

/* [none] intval=realval */
uint16_t c_2 = 2U;

/* [none] intval=realval */
uint16_t c_3 = 3U;

/* [none] intval=realval*10 */
uint16_t c_3_6 = 36U;

/* [none] intval=realval */
uint16_t c_30000 = 30000U;

/* [none] intval=realval */
int16_t c_300n = -300;

/* [none] intval=realval */
uint16_t c_4 = 4U;

/* [none] intval=realval*10000 */
uint16_t c_4_1745 = 41745U;

/* [none] intval=realval */
uint16_t c_4095 = 4095U;

/* [none] intval=realval */
uint16_t c_5 = 5U;

/* [none] intval=realval */
uint16_t c_512 = 512U;

/* [none] intval=realval */
uint16_t c_6 = 6U;

/* [none] intval=realval */
uint16_t c_65 = 65U;

/* [none] intval=realval */
uint16_t c_7 = 7U;

/* [none] intval=realval */
uint16_t c_8 = 8U;

/* [none] intval=realval */
uint16_t c_9 = 9U;

/* intval=realval*100 */
uint16_t c_9_81 = 981U;

/* [none] intval=realval */
int16_t c_n_1 = -1;

/* [none] intval=realval */
int16_t c_n_100 = -100;

/* [none] MAP intval=realval */
uint8_t DbgSwSpfOffset = 1U;

/* [none] MAP intval=realval */
int8_t DebugSw1 = 1;

/* [none] bShiftInProgress intval=realval */
int8_t DebugSw2 = 0;

/* [m/s] Tolerance for drag Trq intval=realval*100 */
uint16_t dragTrqTolerance = 120U;

/* -50..880 [Nm] Engine drag torque limits intval=realval */
int16_t engDTCLimits[13] = { 11, 8, 5, 2, -45, -45, -45, -45, -45, -45, -45, -45, -45 };

/* 500..6000 [rpm] Engine RPM for DTC limits intval=realval */
int16_t engDTCrpm[13] = { 600, 800, 1000, 1300, 1500, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000 };

/* [rad/s] Engine idle speed intval=realval */
uint16_t EngineSPDmin = 62U;

/* 0..880 [Nm] intval=realval */
int16_t engTrqLimits[13] = { 350, 380, 590, 775, 850, 880, 880, 880, 880, 880, 840, 780, 590 };

/* [m/s^2] Gravity intval=realval*100 */
uint16_t g = 981U;

/* [none] Gear numbers intval=realval */
int16_t GearNumber[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

/* [none] Gear ratios of the gearbox intval=realval*1000 */
int16_t GearRatio[9] = { 5850, 3019, 2035, 1511, 1206, 1000, 854, 747, 662 };

/* 0..255 [ss] Timer threshold for gear change logic intval=realval */
uint8_t GearTimerThreshold = 100U;

/* [none] Jerk min filter coef intval=realval*100 */
int16_t jrk_fmax = 2;

/* [none] Jerk min filter coef intval=realval*100 */
int16_t jrk_fmin = 4;

/* 0..60000 [Nm] Current virtual engine (combustion engine + e-machine) torque losses intval=realval */
uint16_t M_MotDrag_par = 0U;

/* Gear ration of the main gear intval=realval*64 */
uint16_t MainGearRatio = 261U;

/* 0..1 What algo for AccStat checks to use. 0 - old, ==2; 1 - new, >=2 intval=realval */
uint8_t NewAccStatReqs = 0U;

/* 0..4 [m/s^2] Acceleration limitation ot OLBC intval=realval*100 */
int32_t OLBCAccLim[6] = { 
	10, 10,
	400, 200,
	400, 200
};

/* 0..10 [m/s] Speed difference for reqAcceleration limitation to OLBC intval=realval*100 */
int32_t OLBCAccSpd[3] = { 0, 500, 1000 };

/* [m] radius pistons front intval=realval*10000 */
uint16_t PistonsF = 537U;

/* [m] radius pistons right intval=realval*10000 */
uint16_t PistonsR = 312U;

/* 0..6000 [Nm] intval=realval */
int16_t rpm[13] = { 800, 1000, 1500, 2000, 2200, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000 };

/* Threshold for clutched status intval=realval*1000 */
uint16_t TorqueRatioThreshold = 40U;

/* Threshold for timer for clutched status intval=realval */
uint8_t TorqueRatioTmrMax = 100U;

/* 0..880 [Hm] intval=realval */
int16_t trqLimits[9] = { 550, 650, 750, 880, 880, 880, 880, 880, 880 };

/* 0..56 [m/s] Maximum speed for slope grad control intval=realval */
float VehicleSpeed_SlopeGradMaxSpd = 19.44;

/* [m/s] Vehicle speed intval=realval*100 */
int32_t vehSpeed[2] = { 139, 556 };

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

