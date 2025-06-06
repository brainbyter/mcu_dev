/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* 0..3 The ACC activation status  intval=realval */
#define DECLARED_AccActive	AccActive
extern uint8_t AccActive;

/* 0..99.45 The acceleration pedal position  intval=realval */
#define DECLARED_AccelPedalPos	AccelPedalPos
extern float AccelPedalPos;

/* -5..4 [m/s^2] Acceleration request from the ACC function intval=realval */
#define DECLARED_AccelReq	AccelReq
extern float AccelReq;

/* 0..3 Type cruise control 0=Nothing 1=CC 2=ACC SG 3=LIM intval=realval */
#define DECLARED_CruiseControlType	CruiseControlType
extern uint8_t CruiseControlType;

/* -30000..30000 [Nm] The current drag torque of engine (combustion engine+e-machine) intval=realval */
#define DECLARED_DragTrq	DragTrq
extern float DragTrq;

/* 0..1 DriveOff request intval=realval */
#define DECLARED_DriveOffReq	DriveOffReq
extern uint8_t DriveOffReq;

/* 0..16383.8 [rpm] Engine speed intval=realval */
#define DECLARED_EngineSpeed	EngineSpeed
extern float EngineSpeed;

/* 0..1 The flag of active phase of gears change intval=realval */
#define DECLARED_GearChange	GearChange
extern uint8_t GearChange;

/* 0..15 The actual engaged gear intval=realval */
#define DECLARED_GearEngNum	GearEngNum
extern uint8_t GearEngNum;

/* 0..15 The target gear of GearBox intval=realval */
#define DECLARED_GearTargetNum	GearTargetNum
extern uint8_t GearTargetNum;

/* -4.18..4.18 The lateral acceleration (AY) data  intval=realval */
#define DECLARED_LateralAccel	LateralAccel
extern float LateralAccel;

/* -4.18..4.18 The longitudinal acceleration (AX) data  intval=realval */
#define DECLARED_LongAccel	LongAccel
extern float LongAccel;

/* -780..780 [deg] The SW angle from the SAS  intval=realval */
#define DECLARED_SasAng	SasAng
extern float SasAng;

/* 0..250 [km/h] Target speed intval=realval */
#define DECLARED_SpeedTarget	SpeedTarget
extern float SpeedTarget;

/* 0..1 Standstill request intval=realval */
#define DECLARED_StandStillReq	StandStillReq
extern uint8_t StandStillReq;

/* -30000..30000 [Nm] The torque at the clutch intval=realval */
#define DECLARED_TrqClutch	TrqClutch
extern float TrqClutch;

/* 0..655.34 [km/h] The vehicle speed data  intval=realval */
#define DECLARED_VehicleSpd	VehicleSpd
extern float VehicleSpd;

/* 0..1 intval=realval */
#define DECLARED_VlcActive	VlcActive
extern uint8_t VlcActive;

/* 0..1 The VLC torque control activation status intval=realval */
#define DECLARED_VlcTrqActive	VlcTrqActive
extern uint8_t VlcTrqActive;

/* 0..425 [bar] The FL wheel brake pressure data  intval=realval */
#define DECLARED_WheelBrakePressureFrontLeft	WheelBrakePressureFrontLeft
extern float WheelBrakePressureFrontLeft;

/* 0..425 [bar] The FR wheel brake pressure data  intval=realval */
#define DECLARED_WheelBrakePressureFrontRight	WheelBrakePressureFrontRight
extern float WheelBrakePressureFrontRight;

/* 0..425 [bar] The RL wheel brake pressure data  intval=realval */
#define DECLARED_WheelBrakePressureRearLeft	WheelBrakePressureRearLeft
extern float WheelBrakePressureRearLeft;

/* 0..425 [bar] The RR wheel brake pressure data  intval=realval */
#define DECLARED_WheelBrakePressureRearRight	WheelBrakePressureRearRight
extern float WheelBrakePressureRearRight;

/* 0..655.34 [km/h] The FL wheel speed data  intval=realval */
#define DECLARED_WheelSpdFrontLeft	WheelSpdFrontLeft
extern float WheelSpdFrontLeft;

/* 0..655.34 [km/h] The FR wheel speed data  intval=realval */
#define DECLARED_WheelSpdFrontRight	WheelSpdFrontRight
extern float WheelSpdFrontRight;

/* 0..655.34 [km/h] The RL wheel speed data  intval=realval */
#define DECLARED_WheelSpdRearLeft	WheelSpdRearLeft
extern float WheelSpdRearLeft;

/* 0..655.34 [km/h] The RR wheel speed data  intval=realval */
#define DECLARED_WheelSpdRearRight	WheelSpdRearRight
extern float WheelSpdRearRight;

/* -164..164 The YRS data  intval=realval */
#define DECLARED_YawRate	YawRate
extern float YawRate;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

