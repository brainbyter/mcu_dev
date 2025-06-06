/*
 * File: VLCforADAS_UMP.h
 *
 * Code generated for Simulink model 'VLCforADAS_UMP'.
 *
 * Model version                  : 1.850
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Mon Apr  1 17:55:13 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->TMS570 Cortex-R4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VLCforADAS_UMP_h_
#define RTW_HEADER_VLCforADAS_UMP_h_
#include <stddef.h>
#include <math.h>
#ifndef VLCforADAS_UMP_COMMON_INCLUDES_
# define VLCforADAS_UMP_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* VLCforADAS_UMP_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T Delay1_DSTATE[2];           /* '<S6>/Delay1' */
  real32_T SlopeOutput;                /* '<S6>/Chart' */
  real32_T Delay_DSTATE;               /* '<S133>/Delay' */
  real32_T Delay2_DSTATE;              /* '<S6>/Delay2' */
  real32_T Delay_DSTATE_j;             /* '<S131>/Delay' */
  real32_T Delay8_DSTATE;              /* '<S6>/Delay8' */
  real32_T Delay3_DSTATE;              /* '<S6>/Delay3' */
  real32_T Delay6_DSTATE;              /* '<S6>/Delay6' */
  real32_T Delay5_DSTATE;              /* '<S6>/Delay5' */
  real32_T Delay_DSTATE_p;             /* '<S129>/Delay' */
  real32_T Delay_DSTATE_l;             /* '<S130>/Delay' */
  real32_T Delay_DSTATE_c;             /* '<S132>/Delay' */
  real32_T Delay1_DSTATE_f;            /* '<S135>/Delay1' */
  real32_T Delay2_DSTATE_n;            /* '<S135>/Delay2' */
  real32_T Delay1_DSTATE_p;            /* '<S134>/Delay1' */
  real32_T Delay1_DSTATE_e;            /* '<S67>/Delay1' */
  real32_T Delay2_DSTATE_f;            /* '<S67>/Delay2' */
  real32_T Delay1_DSTATE_j;            /* '<S61>/Delay1' */
  int32_T UnitDelay_DSTATE;            /* '<S156>/Unit Delay' */
  int32_T UnitDelay_DSTATE_a;          /* '<S147>/Unit Delay' */
  int32_T UnitDelay_DSTATE_p;          /* '<S11>/Unit Delay' */
  int32_T UnitDelay_DSTATE_f;          /* '<S10>/Unit Delay' */
  int32_T UnitDelay_DSTATE_j;          /* '<S102>/Unit Delay' */
  int32_T UnitDelay_DSTATE_o;          /* '<S104>/Unit Delay' */
  uint32_T Delay_DSTATE_o[2];          /* '<S2>/Delay' */
  uint32_T Delay1_DSTATE_i;            /* '<S2>/Delay1' */
  uint32_T m_bpIndex;                  /* '<S6>/VehicleSpeed_SlopeGrad' */
  uint32_T m_bpIndex_b;                /* '<S6>/VehicleSpeed_SlopeGrad1' */
  uint32_T m_bpIndex_o;                /* '<S59>/VehicleSpeed_SlopeGrad' */
  uint32_T m_bpIndex_g;                /* '<S63>/Slope_BKP_Gain1' */
  uint32_T m_bpIndex_g5;               /* '<S63>/VehicleSpeed_SlopeGrad1' */
  int16_T Delay_DSTATE_ck;             /* '<S8>/Delay' */
  int16_T Delay1_DSTATE_l;             /* '<S68>/Delay1' */
  int16_T Delay_DSTATE_k;              /* '<S68>/Delay' */
  int16_T Delay_DSTATE_kj;             /* '<S77>/Delay' */
  int16_T UnitDelay_DSTATE_c;          /* '<S60>/Unit Delay' */
  int16_T Delay3_DSTATE_k;             /* '<S85>/Delay3' */
  uint16_T Delay1_DSTATE_c;            /* '<S1>/Delay1' */
  int8_T If3_ActiveSubsystem;          /* '<S1>/If3' */
  int8_T If_ActiveSubsystem;           /* '<S3>/If' */
  int8_T If_ActiveSubsystem_j;         /* '<S49>/If' */
  uint8_T VLC_Mode_n;                  /* '<S3>/MainVestaChart' */
  uint8_T DriveOff_Mode_d;             /* '<S3>/MainVestaChart' */
  uint8_T Delay_DSTATE_o1;             /* '<S137>/Delay' */
  uint8_T Delay_DSTATE_fu;             /* '<S136>/Delay' */
  uint8_T Delay_DSTATE_m;              /* '<S135>/Delay' */
  uint8_T Delay_DSTATE_a;              /* '<S100>/Delay' */
  uint8_T Delay_DSTATE_jl;             /* '<S67>/Delay' */
  uint8_T Delay_DSTATE_az;             /* '<S37>/Delay' */
  uint8_T icLoad;                      /* '<S133>/Delay' */
  uint8_T icLoad_c;                    /* '<S131>/Delay' */
  uint8_T icLoad_m;                    /* '<S6>/Delay8' */
  uint8_T icLoad_mz;                   /* '<S6>/Delay3' */
  uint8_T icLoad_n;                    /* '<S6>/Delay6' */
  uint8_T icLoad_e;                    /* '<S6>/Delay5' */
  uint8_T icLoad_nf;                   /* '<S129>/Delay' */
  uint8_T icLoad_n1;                   /* '<S130>/Delay' */
  uint8_T icLoad_o;                    /* '<S132>/Delay' */
  uint8_T icLoad_g;                    /* '<S137>/Delay1' */
  uint8_T icLoad_ov;                   /* '<S136>/Delay1' */
  uint8_T icLoad_b;                    /* '<S135>/Delay1' */
  uint8_T icLoad_k;                    /* '<S134>/Delay1' */
  uint8_T is_active_c2_VLCforADAS_UMP; /* '<S6>/Chart' */
  uint8_T is_c2_VLCforADAS_UMP;        /* '<S6>/Chart' */
  uint8_T is_active_c1_VLCforADAS_UMP; /* '<S3>/MainVestaChart' */
  uint8_T is_c1_VLCforADAS_UMP;        /* '<S3>/MainVestaChart' */
  uint8_T is_SSM;                      /* '<S3>/MainVestaChart' */
  uint8_T icLoad_kt;                   /* '<S67>/Delay1' */
  uint8_T icLoad_nu;                   /* '<S61>/Delay1' */
  boolean_T Delay1_DSTATE_g;           /* '<S137>/Delay1' */
  boolean_T Delay1_DSTATE_cg;          /* '<S136>/Delay1' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S1>/Triggered Subsystem' */
  ZCSigState TriggeredSubsystem1_Trig_ZCE;/* '<S92>/Triggered Subsystem1' */
  ZCSigState TriggeredSubsystem_Trig_ZCE_j;/* '<S92>/Triggered Subsystem' */
  ZCSigState TriggeredSubsystem1_Trig_ZCE_k;/* '<S24>/Triggered Subsystem1' */
  ZCSigState TriggeredSubsystem_Trig_ZCE_h;/* '<S24>/Triggered Subsystem' */
} PrevZCX;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: JerkMAP_maxIndex
   * Referenced by: '<S59>/JerkMAP'
   */
  uint32_T JerkMAP_maxIndex[2];

  /* Computed Parameter: OLBCLimAccMap_maxIndex
   * Referenced by: '<S19>/OLBCLimAccMap'
   */
  uint32_T OLBCLimAccMap_maxIndex[2];

  /* Computed Parameter: VehicleSpeed_SlopeGrad1_tableDa
   * Referenced by: '<S63>/VehicleSpeed_SlopeGrad1'
   */
  uint16_T VehicleSpeed_SlopeGrad1_tableDa[7];

  /* Computed Parameter: VehicleSpeed_SlopeGrad1_bp01Dat
   * Referenced by: '<S63>/VehicleSpeed_SlopeGrad1'
   */
  uint16_T VehicleSpeed_SlopeGrad1_bp01Dat[7];
} ConstP;

/* Real-time Model Data Structure */
struct tag_RTM {
  char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Constant parameters (default storage) */
extern ConstP rtConstP;

/* Model entry point functions */
extern void VLCforADAS_UMP_initialize(void);
extern void VLCforADAS_UMP_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: ImportedExternFar */
extern int16_T ACCMotInc_vlc;          /* synthesized block */

/* ACC engine torque increase request. */
extern uint8_T ACCStat;                /* synthesized block */

/* Status of ACC (0 - inactive, 1 - standby, 2 - active, 3 - overrride) */
extern uint8_T ASRinRegulation;        /* synthesized block */

/* - */
extern real32_T AY_vlc;                /* synthesized block */

/* Lateral Acceleration signal routed through ESP */
extern uint8_T AccActive;              /* synthesized block */

/* The ACC activation status  */
extern uint8_T AccTrqAvailable;        /* synthesized block */

/* The power plant torque control */
extern real32_T AccTrqReq;             /* synthesized block */

/* The requested torque to engine */
extern real32_T AccelPedalPos;         /* synthesized block */

/* The acceleration pedal position  */
extern real32_T AccelReq;              /* synthesized block */

/* Acceleration request from the ACC function */
extern real32_T AngEstimate;           /* synthesized block */

/* Estimated gsinus of road grade with offset */
extern real32_T AngleEstimation;       /* synthesized block */

/* Estimated sinus of road grade */
extern uint8_T BrakeReleaseReq;        /* synthesized block */

/* Approval from VLC for DrizveOff */
extern uint8_T Clutched_Status;        /* synthesized block */

/* - */
extern uint8_T CruiseControlType;      /* synthesized block */

/* Type cruise control 0=Nothing 1=CC 2=ACC SG 3=LIM */
extern uint8_T DOV_ApprovalTimer;      /* synthesized block */

/* Approval timer for DriveOff */
extern int16_T DOV_bPID_int;           /* synthesized block */

/* Pedal boost integration trq for driveOff */
extern int16_T DOV_trqPID;             /* synthesized block */

/* Pedal boost PID trq for driveOff */
extern uint16_T DO_SSR_err_tmr;        /* synthesized block */

/* HUITIMER */
extern uint8_T DecelPlausblCount;      /* synthesized block */

/* The plausibility counter of deceleration control by engine */
extern real32_T DragTrq;               /* synthesized block */

/* The current drag torque of engine (combustion engine+e-machine) */
extern uint8_T DriveOffReq;            /* synthesized block */

/* DriveOff request */
extern uint8_T DriveOff_Mode;          /* synthesized block */

/* - */
extern int16_T EngineDrag;             /* synthesized block */

/* Engine drag */
extern int16_T EngineInertiaTrq;       /* synthesized block */

/* Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] */
extern uint16_T EngineRPM;             /* synthesized block */

/* Engine speed from signal to IC */
extern real32_T EngineSpeed;           /* synthesized block */

/* Engine speed */
extern int16_T EngineTorque;           /* synthesized block */

/* Engine torque at the clutch */
extern int16_T FreeRollingDragForce_BC;/* synthesized block */

/* Free Rolling Drag Force */
extern uint16_T Ga_OLBC;               /* synthesized block */

/* Vehicle weight (basic model) */
extern uint8_T GearChange;             /* synthesized block */

/* The flag of active phase of gears change */
extern uint8_T GearEngNum;             /* synthesized block */

/* The actual engaged gear */
extern uint8_T GearTargetNum;          /* synthesized block */

/* The target gear of GearBox */
extern real32_T LateralAccel;          /* synthesized block */

/* The lateral acceleration (AY) data  */
extern real32_T LongAccel;             /* synthesized block */

/* The longitudinal acceleration (AX) data  */
extern real32_T LongitudinalAccelerationProc;/* synthesized block */

/* vehicle longitudinal acceleration */
extern int32_T M_MotClutch_DirAx;      /* synthesized block */

/* Direct AX torque */
extern int16_T M_MotClutch_OLBC;       /* synthesized block */

/* Open-Loop boost controller torque */
extern int16_T M_MotClutch_PID_Boost;  /* synthesized block */

/* Boost PID controller torque */
extern int16_T M_MotClutch_TDM;        /* synthesized block */

/* Transmission drag torque */
extern int16_T M_MotClutch_WI;         /* synthesized block */

/* Wheels inertia comensation torque */
extern uint8_T MotFlag;                /* synthesized block */
extern real32_T PSIP;                  /* synthesized block */

/* Yaw rate signal routed through ESP */
extern uint8_T Plaussib_down;          /* synthesized block */
extern real32_T SAS_angle_vlc;         /* synthesized block */

/* Steering wheel angle */
extern uint32_T SSR_timer;             /* synthesized block */

/* - */
extern real32_T SasAng;                /* synthesized block */

/* The SW angle from the SAS  */
extern real32_T SlopeCoef;             /* synthesized block */

/* Coefficient for slope for PI */
extern real32_T SlopeCoefProt;         /* synthesized block */

/* Coefficient for slope for PI from protection timer */
extern int16_T SlopeDragTorque;        /* synthesized block */

/* Slope drag torque */
extern uint32_T SlopeForPID;           /* synthesized block */

/* Slope for PID controller */
extern real32_T SpeedTarget;           /* synthesized block */

/* Target speed */
extern uint8_T StandStillReq;          /* synthesized block */

/* Standstill request */
extern uint32_T TorqueRatio;           /* synthesized block */

/* - */
extern uint32_T TorqueRatioTmr;        /* synthesized block */

/* Trq time */
extern real32_T TrqClutch;             /* synthesized block */

/* The torque at the clutch */
extern uint16_T TrqDwnCntr;            /* synthesized block */

/* - */
extern uint8_T VLC_Available;          /* synthesized block */

/* VLC availibility flag */
extern uint16_T VLC_DecelPlausibilityCounter;/* synthesized block */

/* - */
extern uint8_T VLC_Mode;               /* synthesized block */

/* - */
extern int16_T VLC_TargetEngTorque;    /* synthesized block */

/* Torque request (internal) */
extern uint16_T VehSpd_timer;          /* synthesized block */

/* - */
extern uint8_T VehSpd_tmr_flg;         /* synthesized block */

/* - */
extern real32_T VehicleSpd;            /* synthesized block */

/* The vehicle speed data  */
extern uint16_T VehicleSpeed_VLCInt;   /* synthesized block */

/* Current vehicle speed */
extern uint8_T VlcActive;              /* synthesized block */

/* - */
extern uint8_T VlcTrqActive;           /* synthesized block */

/* The VLC torque control activation status */
extern real32_T WheelBrakePressureFrontLeft;/* synthesized block */

/* The FL wheel brake pressure data  */
extern real32_T WheelBrakePressureFrontRight;/* synthesized block */

/* The FR wheel brake pressure data  */
extern real32_T WheelBrakePressureRearLeft;/* synthesized block */

/* The RL wheel brake pressure data  */
extern real32_T WheelBrakePressureRearRight;/* synthesized block */

/* The RR wheel brake pressure data  */
extern real32_T WheelInertia_FA;       /* synthesized block */

/* Front wheels inertia comensation torque */
extern real32_T WheelInertia_RA;       /* synthesized block */

/* Rear wheels inertia comensation torque */
extern real32_T WheelSpdFrontLeft;     /* synthesized block */

/* The FL wheel speed data  */
extern real32_T WheelSpdFrontRight;    /* synthesized block */

/* The FR wheel speed data  */
extern real32_T WheelSpdRearLeft;      /* synthesized block */

/* The RL wheel speed data  */
extern real32_T WheelSpdRearRight;     /* synthesized block */

/* The RR wheel speed data  */
extern real32_T YawRate;               /* synthesized block */

/* The YRS data  */
extern uint16_T accelerationPedal;     /* synthesized block */

/* - */
extern int16_T bPID_int;               /* synthesized block */

/* integrated flaw */
extern uint16_T cardanSpeed;           /* synthesized block */

/* Speed of output cardan */
extern uint16_T curTrqRatio;           /* synthesized block */

/* Current Transmission Gear Ratio */
extern uint8_T decelPlausibility;      /* synthesized block */

/* - */
extern real32_T estAX;                 /* synthesized block */

/* AX offset for decel playsibility */
extern uint16_T gearShift;             /* synthesized block */

/* Gear changing flag from TCU */
extern int16_T jerkAcceleration;       /* synthesized block */

/* All-limited and filtered acceleration */
extern uint8_T jerkFlag;               /* synthesized block */

/* Jerk fault nter activation */
extern uint16_T nICEngineSpeed_vlc;    /* synthesized block */

/* Engine speed */
extern uint8_T numGearEngaged_vlc;     /* synthesized block */

/* Number of engaged gear */
extern uint8_T numGearSwitch;          /* synthesized block */

/* numGearSwitch */
extern uint8_T numGearTarget_vlc;      /* synthesized block */

/* Number of engaged gear */
extern uint16_T objectSpeed;           /* synthesized block */

/* Current vehicle speed calculated as an average between front wheels */
extern real32_T pWheelFL_vlc;          /* synthesized block */

/* Estimated brake pressure at front left wheel */
extern real32_T pWheelFR_vlc;          /* synthesized block */

/* Estimated brake pressure at front left wheel */
extern real32_T pWheelRL_vlc;          /* synthesized block */

/* Estimated brake pressure at front left wheel */
extern real32_T pWheelRR_vlc;          /* synthesized block */

/* Estimated brake pressure at front left wheel */
extern uint32_T refSpeed;              /* synthesized block */

/* Ref speed */
extern int16_T reqAcceleration;        /* synthesized block */

/* Requested acceleration */
extern int16_T reqAccelerationLimited; /* synthesized block */

/* Speed-limited request */
extern int16_T reqAccelerationMAX;     /* synthesized block */

/* Requested acceleration MAX grade */
extern int16_T reqAccelerationMIN;     /* synthesized block */

/* Requested acceleration MIN grade */
extern int16_T resultOfIntPID;         /* synthesized block */

/* - */
extern uint8_T targetSlipSt;           /* synthesized block */

/* - */
extern uint16_T targetSpeed;           /* synthesized block */

/* Target speed */
extern uint16_T targetSpeedDelay;      /* synthesized block */

/* Target speed */
extern uint16_T targetSpeedTemp;       /* synthesized block */

/* Target speed */
extern uint8_T targetSpeedTmr;         /* synthesized block */

/* Timer to hold tirget speed */
extern uint8_T targetSpeedTmrFlag;     /* synthesized block */

/* Timer to hold tirget speed */
extern uint8_T torqueCutOff;           /* synthesized block */

/* Flag: stop torque request */
extern int16_T trqI_PID;               /* synthesized block */

/* Torque at the clutch from Speed controller */
extern int16_T trqP_PID;               /* synthesized block */

/* Torque at the clutch from Boost controller */
extern real32_T yawRateSS;             /* synthesized block */

/* calc steady-state vehicle rotational motion of OZ */
extern real32_T yawRateSSwithSlip;     /* synthesized block */

/* calc steady-state vehicle rotational motion with side slip of OZ */
#pragma section ".calibr"

/* Declaration for custom storage class: ImportedExternConst */
extern real32_T AX_YRS_f;        /* Referenced by: '<S129>/Constant4' */

/* Filter for ax in slope model */
extern real32_T AX_offSet;       /* Referenced by: '<S8>/AX_offSet' */

/* AX offset for decel playsibility */
extern real32_T AZ5;             /* Referenced by: '<S98>/Constant' */

/* Dead zone for speed acceleration limitation */
extern int16_T B_MAP[9];         /* Referenced by:
                                        * '<S68>/Boost_map'
                                        * '<S75>/Boost_map'
                                        * '<S59>/Boost_map'
                                        */

/* - */
extern int16_T B_pidC_h;         /* Referenced by:
                                        * '<S77>/Constant'
                                        * '<S85>/B_pidC_h'
                                        */

/* carrent solver step of model */
extern int16_T BoostIntegrationLowerSat;/* Referenced by: '<S77>/Saturation1' */

/* Boost PI integration satureation */
extern int16_T BoostIntegrationUpperSat;/* Referenced by: '<S77>/Saturation1' */

/* Boost PI integration satureation */
extern real32_T BrakeDiskR_F;    /* Referenced by:
                                        * '<S121>/BrakeDiskR_F'
                                        * '<S122>/BrakeDiskR_F'
                                        */

/* Middle half-radius, front disk */
extern real32_T BrakeDiskR_R;    /* Referenced by:
                                        * '<S123>/BrakeDiskR_R'
                                        * '<S124>/BrakeDiskR_R'
                                        */

/* Middle half-radius, rear disk */
extern real32_T BrakePistonR_F1; /* Referenced by:
                                        * '<S121>/Front_pistons_1'
                                        * '<S122>/Front_pistons_1'
                                        */

/* First front piston radius */
extern real32_T BrakePistonR_F2; /* Referenced by:
                                        * '<S121>/Front_pistons_2'
                                        * '<S122>/Front_pistons_2'
                                        */

/* Second front piston radius */
extern real32_T BrakePistonR_F3; /* Referenced by:
                                        * '<S121>/Front_pistons_3'
                                        * '<S122>/Front_pistons_3'
                                        */

/* Third front piston radius */
extern real32_T BrakePistonR_R1; /* Referenced by:
                                        * '<S123>/Rear_pistons_1'
                                        * '<S124>/Rear_pistons_1'
                                        */

/* First rear piston radius */
extern real32_T BrakePistonR_R2; /* Referenced by:
                                        * '<S123>/Rear_pistons_2'
                                        * '<S124>/Rear_pistons_2'
                                        */

/* Second rear piston radius */
extern int32_T DOV_ApprovTrqFactor;
                                /* Referenced by: '<S17>/DOV_ApprovTrqFactor' */

/* Drive off factor for approval */
extern int32_T DOV_ApprovTrqOffSet;
                                /* Referenced by: '<S17>/DOV_ApprovTrqOffSet' */

/* Drive off offSet for approval */
extern uint8_T DOV_TimerMax;     /* Referenced by:
                                        * '<S81>/Saturation'
                                        * '<S82>/Saturation'
                                        */

/* Approval timer max for drive-off */
extern uint8_T DOV_TimerThreshold;
                                 /* Referenced by: '<S71>/DOV_TimerThreshold' */

/* Approval timer threshold for drive-off */
extern int8_T DOV_TrqOffset;    /* Referenced by: '<S72>/DOV_TrqOffset' */

/* Drive off torque offset */
extern uint16_T DOV_VehSpdMax;  /* Referenced by: '<S3>/MainVestaChart' */

/* min vehicle speed to exit DO mode */
extern uint16_T DOV_VehSpdMin;  /* Referenced by: '<S3>/MainVestaChart' */

/* min vehicle speed to exit DO mode */
extern uint16_T DOV_bkiCal;      /* Referenced by: '<S75>/DOV_bkiCal' */

/* Pedal boost calibration coef for driveOff */
extern uint16_T DOV_bkpCal;      /* Referenced by: '<S68>/DOV_bkpCal' */

/* Pedal boost calibration coef for driveOff */
extern uint16_T DO_SSR_err_tmr_max;
                                      /* Referenced by: '<S3>/MainVestaChart' */

/* - */
extern uint16_T EngineAccelFilter;
                                  /* Referenced by: '<S11>/EngineAccelFilter' */

/* Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] */
extern uint16_T EngineInertia;   /* Referenced by: '<S2>/EngineInertia' */

/* Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] */
extern uint16_T EngineSPDmin;    /* Referenced by: '<S41>/EngineSPDmin' */

/* Engine idle speed */
extern uint16_T EngineSpdFilter;
                                    /* Referenced by: '<S10>/EngineSpdFilter' */

/* Current ACC mode (0 - Error, 1 - Adaptive [Light sedan], 2 - Regular [Heavy sedan and Limousine] */
extern uint16_T FreeRollingResistanceBP[16];/* Referenced by:
                                                   * '<S5>/FreeRollingModel1'
                                                   * '<S20>/FreeRollingModel1'
                                                   * '<S86>/1-D Lookup Table2'
                                                   * '<S55>/Bost_map2'
                                                   */

/* Free Rolling Resistance breakpoints */
extern int16_T FreeRollingResistanceTD[16];/* Referenced by:
                                                  * '<S5>/FreeRollingModel1'
                                                  * '<S20>/FreeRollingModel1'
                                                  */

/* Free Rolling Resistance table data for light sedan */
extern int16_T Gb_MAP[9];        /* Referenced by:
                                        * '<S68>/Boost_map'
                                        * '<S75>/Boost_map'
                                        * '<S59>/Boost_map'
                                        * '<S59>/JerkMAP'
                                        * '<S59>/SpeedControllerLT'
                                        */

/* - */
extern int16_T GearNumber[9];    /* Referenced by:
                                        * '<S9>/Gear_ratio_LT'
                                        * '<S24>/Gear_ratio_LT'
                                        * '<S76>/trqLimits1'
                                        * '<S30>/Gear MASS factor'
                                        * '<S32>/trqLimits'
                                        * '<S33>/trqLimits'
                                        * '<S56>/trqLimits'
                                        * '<S62>/trqLimits1'
                                        */

/* Gear numbers */
extern int16_T GearRatio[9];     /* Referenced by:
                                        * '<S9>/Gear_ratio_LT'
                                        * '<S24>/Gear_ratio_LT'
                                        * '<S41>/GearRatio'
                                        */

/* Gear ratios of the gearbox */
extern uint8_T GearTimerThreshold;/* Referenced by: '<S37>/GearTimer' */

/* Timer threshold for gear change logic */
extern int16_T I_boost[9];  /* Referenced by: '<S59>/SpeedControllerLT' */

/* - */
extern real32_T J_Wheel_FA;      /* Referenced by: '<S25>/J_Wheel_FA' */

/* Front wheels moment of inertia */
extern real32_T J_Wheel_RA;      /* Referenced by: '<S25>/J_Wheel_RA' */

/* Rear wheels moment of inertia */
extern int16_T JerFcn[99];       /* Referenced by: '<S59>/JerkMAP' */

/* - */
extern int16_T JerMAP[11];       /* Referenced by: '<S59>/JerkMAP' */

/* - */
extern real32_T LongitudinalAcceleration_f;/* Referenced by: '<S130>/Constant4' */

/* Filter for longitudinal acceleration in slope model */
extern uint16_T MainGearRatio;   /* Referenced by:
                                        * '<S9>/MainGearRatio'
                                        * '<S115>/Constant1'
                                        * '<S24>/Constant1'
                                        * '<S24>/Gain1'
                                        */

/* Gear ration of the main gear */
extern int16_T MassFactor_MAP[9];
                                   /* Referenced by: '<S30>/Gear MASS factor' */

/* Inertia factor for rotation */
extern int16_T MinimumPIDTrqReq;
                                   /* Referenced by: '<S76>/MinimumPIDTrqReq' */

/* Negative PID border (OLBC_Max-C=MinPID) */
extern uint8_T NewAccStatReqs;   /* Referenced by:
                                        * '<S8>/OLD_NEW_ACCSTAT'
                                        * '<S17>/OLD_NEW_ACCSTAT'
                                        */

/* What algo for AccStat checks to use. 0 - old, ==2; 1 - new, >=2 */
extern int32_T OLBCAccLim[6];   /* Referenced by: '<S19>/OLBCLimAccMap' */

/* Acceleration limitation ot OLBC */
extern int32_T OLBCAccSpd[3];   /* Referenced by: '<S19>/OLBCLimAccMap' */

/* Speed difference for reqAcceleration limitation to OLBC */
extern real32_T Offset_roadgrade_accelerations[11];
                                /* Referenced by: '<S138>/RoadgradeOffset_LT' */

/* Offset for pitch compensation - accelertions */
extern real32_T Offset_roadgrade_table[11];
                                /* Referenced by: '<S138>/RoadgradeOffset_LT' */

/* Offset for pitch compensation - offset */
extern uint16_T PlausibilityDec; /* Referenced by: '<S152>/c_0_1' */

/* - */
extern uint16_T PlausibilityInc_ax;
                                /* Referenced by: '<S153>/PlausibilityInc_ax' */

/* - */
extern uint16_T PlausibilityInc_trq;
                               /* Referenced by: '<S153>/PlausibilityInc_trq' */

/* - */
extern uint16_T PlaussibFltCnst;
                                   /* Referenced by: '<S147>/PlaussibFltCnst' */

/* - */
extern real32_T RoadangleAcceleration_f;/* Referenced by: '<S132>/Constant4' */

/* Final filter for slope model */
extern int16_T SP_I_ACC_MAP[5];  /* Referenced by:
                                        * '<S55>/Bost_map1'
                                        * '<S60>/Bost_map1'
                                        */

/* - */
extern int16_T SP_I_MAX_MAP[5];  /* Referenced by:
                                        * '<S55>/Bost_map1'
                                        * '<S60>/Bost_map1'
                                        */

/* - */
extern uint32_T SSR_tmr_max;    /* Referenced by: '<S3>/MainVestaChart' */

/* - */
extern int16_T S_pidC_h;         /* Referenced by: '<S60>/Constant1' */

/* carrent solver step of model */
extern real32_T SlopeApproveTmr[7];
                             /* Referenced by: '<S6>/VehicleSpeed_SlopeGrad1' */

/* Approval timer for slope change */
extern real32_T SlopeHystDec;    /* Referenced by: '<S6>/SlopeHystDec' */

/* Slope change threshold (SlopeTarget - SlopeHystDec) */
extern real32_T SlopeHystInc;    /* Referenced by: '<S6>/SlopeHystInc' */

/* Slope change threshold (SlopeTarget - SlopeHystInc) */
extern real32_T Slope_BP[10]; /* Referenced by: '<S63>/Slope_BKP_Gain1' */

/* Slope in percent for speed and boost slope-based gain */
extern real32_T Slope_KI_Gain[10];
                                    /* Referenced by: '<S63>/Slope_BKP_Gain1' */

/* Slope-dependent gain for speedCalibration */
extern real32_T Slope_KP_Gain;  /* Referenced by: '<S59>/Slope_KP_Gain' */

/* Slope-dependent gain for bkp_cal_coef */
extern int16_T SpeedSlipFactor[16];
                                  /* Referenced by: '<S86>/1-D Lookup Table3' */

/* Factor for speed slip dependent on speed */
extern int16_T SpeedSlipFactorSpd[16];
                                  /* Referenced by: '<S86>/1-D Lookup Table3' */

/* Factor for speed slip breakpoints */
extern uint16_T TargetSpdOffSet; /* Referenced by: '<S114>/Constant3' */

/* Offset for Target speed */
extern uint16_T TorqueRatioThreshold;
                               /* Referenced by: '<S41>/TorqueRatioThreshold' */

/* Threshold for clutched status */
extern uint8_T TorqueRatioTmrMax;/* Referenced by:
                                        * '<S41>/TorqueRatioTmrMax'
                                        * '<S42>/Saturation'
                                        */

/* Threshold for timer for clutched status */
extern uint16_T TrqDwnCntrMax; /* Referenced by: '<S149>/TrqDwnCntrMax' */

/* - */
extern uint16_T VehSpd_tmr_max;  /* Referenced by:
                                        * '<S3>/MainVestaChart'
                                        * '<S18>/VehSpd_tmr_max'
                                        */

/* - */
extern uint16_T VehicleSpeed_BKPGradBP[8];
                             /* Referenced by: '<S59>/VehicleSpeed_SlopeGrad' */

/* Breakpoints for slope grad control */
extern uint16_T VehicleSpeed_BKPGradTD[8];
                             /* Referenced by: '<S59>/VehicleSpeed_SlopeGrad' */

/* Coefficients for BP grad control */
extern real32_T VehicleSpeed_SlopeGradBP[7];/* Referenced by:
                                                   * '<S6>/VehicleSpeed_SlopeGrad'
                                                   * '<S6>/VehicleSpeed_SlopeGrad1'
                                                   */

/* Breakpoints for slope grad control */
extern real32_T VehicleSpeed_SlopeGradMaxSpd;/* Referenced by: '<S6>/Saturation' */

/* Maximum speed for slope grad control */
extern real32_T VehicleSpeed_SlopeGradTD[7];
                              /* Referenced by: '<S6>/VehicleSpeed_SlopeGrad' */

/* Coefficients for slope grad control */
extern real32_T VehicleSpeed_f;  /* Referenced by: '<S133>/Constant4' */

/* Filter for VehicleSpeed in slope model */
extern uint16_T WghtCurb;        /* Referenced by:
                                        * '<S115>/WghtCurb'
                                        * '<S20>/WghtCurb'
                                        * '<S22>/WghtCurb'
                                        * '<S31>/WghtCurb'
                                        */

/* Free vehicle mass */
extern uint16_T WghtFull;        /* Referenced by:
                                        * '<S115>/WghtFull'
                                        * '<S31>/WghtFull'
                                        */

/* Loaded vehicle mass */
extern int16_T bkp_cal_coef;/* Referenced by: '<S59>/boostCalibration1' */

/* Boost controller P calibration gain */
extern int16_T bkpf[10];         /* Referenced by: '<S59>/FlawSignMap' */

/* Boost flaw */
extern int16_T bkpt[10];         /* Referenced by: '<S59>/FlawSignMap' */

/* Boost Kp table */
extern int16_T boostCalibration;
                                   /* Referenced by: '<S59>/boostCalibration' */

/* Calibrated parametr of the boost controller */
extern uint16_T c_0;             /* Referenced by:
                                        * '<S45>/0'
                                        * '<S97>/0'
                                        * '<S28>/Constant'
                                        * '<S59>/Constant2'
                                        */

/* - */
extern uint16_T c_1;             /* Referenced by:
                                        * '<S147>/1'
                                        * '<S44>/1'
                                        * '<S96>/1'
                                        * '<S156>/Constant1'
                                        * '<S102>/Constant1'
                                        * '<S30>/c_1'
                                        * '<S104>/Constant1'
                                        */

/* - */
extern uint16_T c_2;             /* Referenced by:
                                        * '<S77>/Constant2'
                                        * '<S85>/C_2'
                                        * '<S60>/Constant3'
                                        */

/* - */
extern int16_T c_n_1;            /* Referenced by:
                                        * '<S76>/Constant1'
                                        * '<S60>/Constant'
                                        */

/* - */
extern uint16_T dbg1EngineModel;
                                     /* Referenced by: '<S8>/dbg1EngineModel' */

/* - */
extern uint16_T dbg2EngineModel; /* Referenced by:
                                        * '<S9>/dbg2EngineModel'
                                        * '<S48>/dbg2EngineModel'
                                        * '<S52>/dbg2EngineModel'
                                        */

/* - */
extern uint8_T dbg_eng;          /* Referenced by: '<S2>/dbg_eng' */

/* debug switch for engine inertia */
extern uint8_T dbg_slope;        /* Referenced by: '<S22>/dbg_slope' */

/* debug switch for slope calculation */
extern uint8_T dbg_wheels;       /* Referenced by: '<S25>/dbg_wheels' */

/* debug switch for wheels inertia */
extern real32_T directAX_P[16];  /* Referenced by: '<S55>/Bost_map2' */

/* DirectAXControl P calibration coefficient */
extern int16_T engDTCLimits[13]; /* Referenced by: '<S8>/engTrqLimits' */

/* Engine drag torque limits */
extern int16_T engDTCrpm[13];    /* Referenced by: '<S8>/engTrqLimits' */

/* Engine RPM for DTC limits */
extern uint16_T engRPMThreshold_DTC;/* Referenced by: '<S8>/Constant' */

/* Threshold for engine speed for drag torque control */
extern int16_T engTrqLimits[13]; /* Referenced by: '<S56>/engTrqLimits' */

/* - */
extern uint16_T g;               /* Referenced by:
                                        * '<S115>/g1'
                                        * '<S115>/g2'
                                        * '<S115>/Gain1'
                                        * '<S115>/Gain2'
                                        */

/* Gravity */
extern int16_T jrk_fmax;         /* Referenced by: '<S104>/Constant' */

/* Jerk min filter coef */
extern int16_T jrk_fmin;         /* Referenced by: '<S102>/Constant' */

/* Jerk min filter coef */
extern real32_T lateralLoud[15];
                                 /* Referenced by: '<S116>/1-D Lookup Table2' */

/* lateral Loud for side Slip Angle */
extern int16_T muTable[5];       /* Referenced by:
                                        * '<S84>/1-D Lookup Table1'
                                        * '<S86>/1-D Lookup Table1'
                                        */

/* a table of road mu */
extern uint16_T mu_pad;          /* Referenced by: '<S120>/mu_pad' */

/* Brake pads friction coefficient */
extern uint16_T parametrOLBC_mdlCompensation;/* Referenced by:
                                                    * '<S119>/parametrOLBC_mdlCompensation'
                                                    * '<S30>/parametrOLBC_mdlCompensation'
                                                    */

/* Calibrated parametr for compensation vehicle mass in OLBC */
extern uint16_T rd;              /* Referenced by:
                                        * '<S115>/rd1'
                                        * '<S115>/rd2'
                                        * '<S20>/rd'
                                        * '<S22>/rd'
                                        * '<S24>/Constant'
                                        * '<S25>/rd'
                                        * '<S31>/rd'
                                        * '<S55>/Gain'
                                        */

/* Dinamic radius */
extern int16_T rpm[13];          /* Referenced by: '<S56>/engTrqLimits' */

/* - */
extern real32_T sideSlipAngle[15];
                                 /* Referenced by: '<S116>/1-D Lookup Table2' */

/* side Slip Angle */
extern uint16_T sideslip_angle_koef;/* Referenced by: '<S116>/slip_koef' */

/* - */
extern int16_T slipSpeedOffset[16];
                                  /* Referenced by: '<S86>/1-D Lookup Table2' */

/* target wheel slip */
extern int16_T speedCalibration;
                                  /* Referenced by: '<S59>/boostCalibration2' */

/* Calibrated parametr of the speed controller */
extern int16_T speedOffsetSlipCntrl;
                               /* Referenced by: '<S84>/speedOffsetSlipCntrl' */

/* start speed for slip control */
extern uint16_T speedVariant;    /* Referenced by:
                                        * '<S55>/speedVariant'
                                        * '<S60>/speedVariant'
                                        */

/* - */
extern uint16_T steerGearRat;   /* Referenced by: '<S116>/steerGearRat' */

/* ratio of the steering gear */
extern int16_T targetSlip[5];    /* Referenced by:
                                        * '<S84>/1-D Lookup Table1'
                                        * '<S86>/1-D Lookup Table1'
                                        */

/* target wheel slip */
extern int16_T targetSlipFactor;
                                   /* Referenced by: '<S84>/targetSlipFactor' */

/* factor for deactiwation target wheel slip logic */
extern int16_T trqLimits[9];     /* Referenced by:
                                        * '<S32>/trqLimits'
                                        * '<S33>/trqLimits'
                                        * '<S56>/trqLimits'
                                        */

/* - */
extern int16_T trqLimits_PI_Boost[9];/* Referenced by:
                                            * '<S76>/trqLimits1'
                                            * '<S62>/trqLimits1'
                                            */

/* - */
extern int16_T trq_f;            /* Referenced by: '<S156>/Constant2' */

/* Torque filter coef */
extern int32_T vehSpeed[2];     /* Referenced by: '<S19>/OLBCLimAccMap' */

/* Vehicle speed */
extern uint8_T vehicleBase;      /* Referenced by:
                                        * '<S116>/vehicleBase2'
                                        * '<S125>/vehicleBase'
                                        */

/* Vehicle base */
#pragma section

/* Real-time Model object */
extern RT_MODEL *rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Conversion2' : Unused code path elimination
 * Block '<S2>/Scope1' : Unused code path elimination
 * Block '<S2>/Scope4' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Propagation' : Unused code path elimination
 * Block '<S20>/Scope' : Unused code path elimination
 * Block '<S20>/Scope1' : Unused code path elimination
 * Block '<S20>/Scope2' : Unused code path elimination
 * Block '<S30>/Scope' : Unused code path elimination
 * Block '<S30>/Scope1' : Unused code path elimination
 * Block '<S30>/Scope2' : Unused code path elimination
 * Block '<S30>/Scope3' : Unused code path elimination
 * Block '<S30>/Scope4' : Unused code path elimination
 * Block '<S30>/Scope5' : Unused code path elimination
 * Block '<S30>/Scope6' : Unused code path elimination
 * Block '<S30>/Scope7' : Unused code path elimination
 * Block '<S30>/Scope8' : Unused code path elimination
 * Block '<S30>/Scope9' : Unused code path elimination
 * Block '<S31>/Scope' : Unused code path elimination
 * Block '<S31>/Scope1' : Unused code path elimination
 * Block '<S31>/Scope2' : Unused code path elimination
 * Block '<S31>/Scope3' : Unused code path elimination
 * Block '<S31>/Scope4' : Unused code path elimination
 * Block '<S31>/Scope5' : Unused code path elimination
 * Block '<S31>/Scope6' : Unused code path elimination
 * Block '<S31>/Scope7' : Unused code path elimination
 * Block '<S21>/Scope1' : Unused code path elimination
 * Block '<S22>/Scope2' : Unused code path elimination
 * Block '<S22>/Scope3' : Unused code path elimination
 * Block '<S22>/Scope4' : Unused code path elimination
 * Block '<S22>/Scope5' : Unused code path elimination
 * Block '<S22>/Scope6' : Unused code path elimination
 * Block '<S22>/Scope7' : Unused code path elimination
 * Block '<S22>/Scope8' : Unused code path elimination
 * Block '<S24>/Scope1' : Unused code path elimination
 * Block '<S41>/Scope' : Unused code path elimination
 * Block '<S41>/Scope1' : Unused code path elimination
 * Block '<S41>/Scope2' : Unused code path elimination
 * Block '<S14>/Scope' : Unused code path elimination
 * Block '<S15>/Scope' : Unused code path elimination
 * Block '<S49>/Scope' : Unused code path elimination
 * Block '<S49>/Scope1' : Unused code path elimination
 * Block '<S49>/Scope2' : Unused code path elimination
 * Block '<S55>/Scope8' : Unused code path elimination
 * Block '<S55>/Scope9' : Unused code path elimination
 * Block '<S53>/Scope' : Unused code path elimination
 * Block '<S56>/Scope2' : Unused code path elimination
 * Block '<S56>/Scope3' : Unused code path elimination
 * Block '<S56>/Scope4' : Unused code path elimination
 * Block '<S56>/Scope5' : Unused code path elimination
 * Block '<S58>/Data Type Conversion2' : Unused code path elimination
 * Block '<S58>/Data Type Conversion3' : Unused code path elimination
 * Block '<S58>/Scope3' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate' : Unused code path elimination
 * Block '<S64>/Data Type Propagation' : Unused code path elimination
 * Block '<S60>/Scope1' : Unused code path elimination
 * Block '<S60>/Scope10' : Unused code path elimination
 * Block '<S60>/Scope11' : Unused code path elimination
 * Block '<S60>/Scope2' : Unused code path elimination
 * Block '<S60>/Scope3' : Unused code path elimination
 * Block '<S60>/Scope4' : Unused code path elimination
 * Block '<S60>/Scope5' : Unused code path elimination
 * Block '<S60>/Scope7' : Unused code path elimination
 * Block '<S60>/Scope8' : Unused code path elimination
 * Block '<S60>/Scope9' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S61>/Scope' : Unused code path elimination
 * Block '<S61>/Scope1' : Unused code path elimination
 * Block '<S59>/Scope' : Unused code path elimination
 * Block '<S59>/Scope2' : Unused code path elimination
 * Block '<S59>/Scope3' : Unused code path elimination
 * Block '<S59>/Scope5' : Unused code path elimination
 * Block '<S59>/Scope6' : Unused code path elimination
 * Block '<S59>/Scope7' : Unused code path elimination
 * Block '<S57>/Scope3' : Unused code path elimination
 * Block '<S51>/Scope' : Unused code path elimination
 * Block '<S51>/Scope1' : Unused code path elimination
 * Block '<S52>/Scope' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S3>/Scope1' : Unused code path elimination
 * Block '<S3>/Scope3' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Data Type Propagation' : Unused code path elimination
 * Block '<S79>/Scope3' : Unused code path elimination
 * Block '<S68>/Scope' : Unused code path elimination
 * Block '<S68>/Scope1' : Unused code path elimination
 * Block '<S68>/Scope2' : Unused code path elimination
 * Block '<S68>/Scope3' : Unused code path elimination
 * Block '<S68>/Scope4' : Unused code path elimination
 * Block '<S68>/Scope5' : Unused code path elimination
 * Block '<S68>/Scope6' : Unused code path elimination
 * Block '<S68>/Scope7' : Unused code path elimination
 * Block '<S68>/Scope8' : Unused code path elimination
 * Block '<S68>/Scope9' : Unused code path elimination
 * Block '<S83>/Scope1' : Unused code path elimination
 * Block '<S83>/Scope3' : Unused code path elimination
 * Block '<S84>/Scope' : Unused code path elimination
 * Block '<S84>/Scope1' : Unused code path elimination
 * Block '<S84>/Scope10' : Unused code path elimination
 * Block '<S84>/Scope11' : Unused code path elimination
 * Block '<S84>/Scope12' : Unused code path elimination
 * Block '<S84>/Scope13' : Unused code path elimination
 * Block '<S84>/Scope14' : Unused code path elimination
 * Block '<S84>/Scope15' : Unused code path elimination
 * Block '<S84>/Scope2' : Unused code path elimination
 * Block '<S84>/Scope3' : Unused code path elimination
 * Block '<S84>/Scope4' : Unused code path elimination
 * Block '<S84>/Scope5' : Unused code path elimination
 * Block '<S84>/Scope6' : Unused code path elimination
 * Block '<S84>/Scope7' : Unused code path elimination
 * Block '<S84>/Scope8' : Unused code path elimination
 * Block '<S84>/Scope9' : Unused code path elimination
 * Block '<S86>/1-D Lookup Table' : Unused code path elimination
 * Block '<S91>/Compare' : Unused code path elimination
 * Block '<S91>/Constant' : Unused code path elimination
 * Block '<S86>/Logical Operator1' : Unused code path elimination
 * Block '<S86>/Relational Operator' : Unused code path elimination
 * Block '<S86>/Scope' : Unused code path elimination
 * Block '<S86>/Scope1' : Unused code path elimination
 * Block '<S86>/Scope2' : Unused code path elimination
 * Block '<S86>/Scope3' : Unused code path elimination
 * Block '<S86>/Scope4' : Unused code path elimination
 * Block '<S86>/Scope5' : Unused code path elimination
 * Block '<S86>/Scope6' : Unused code path elimination
 * Block '<S92>/Scope' : Unused code path elimination
 * Block '<S92>/Scope1' : Unused code path elimination
 * Block '<S92>/Scope10' : Unused code path elimination
 * Block '<S92>/Scope11' : Unused code path elimination
 * Block '<S92>/Scope12' : Unused code path elimination
 * Block '<S92>/Scope13' : Unused code path elimination
 * Block '<S92>/Scope2' : Unused code path elimination
 * Block '<S92>/Scope3' : Unused code path elimination
 * Block '<S92>/Scope4' : Unused code path elimination
 * Block '<S92>/Scope5' : Unused code path elimination
 * Block '<S92>/Scope6' : Unused code path elimination
 * Block '<S92>/Scope7' : Unused code path elimination
 * Block '<S92>/Scope8' : Unused code path elimination
 * Block '<S92>/Scope9' : Unused code path elimination
 * Block '<S86>/Subtract1' : Unused code path elimination
 * Block '<S17>/Scope' : Unused code path elimination
 * Block '<S17>/Scope1' : Unused code path elimination
 * Block '<S17>/Scope2' : Unused code path elimination
 * Block '<S17>/Scope3' : Unused code path elimination
 * Block '<S17>/Scope4' : Unused code path elimination
 * Block '<S17>/Scope5' : Unused code path elimination
 * Block '<S17>/Scope6' : Unused code path elimination
 * Block '<S17>/Scope7' : Unused code path elimination
 * Block '<S17>/Scope8' : Unused code path elimination
 * Block '<S17>/Scope9' : Unused code path elimination
 * Block '<S19>/Saturation1' : Unused code path elimination
 * Block '<S19>/Scope' : Unused code path elimination
 * Block '<S19>/Scope1' : Unused code path elimination
 * Block '<S19>/Scope2' : Unused code path elimination
 * Block '<S19>/Scope3' : Unused code path elimination
 * Block '<S19>/Scope4' : Unused code path elimination
 * Block '<S19>/Scope5' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<S4>/Scope1' : Unused code path elimination
 * Block '<S111>/Scope' : Unused code path elimination
 * Block '<S115>/Scope' : Unused code path elimination
 * Block '<S115>/Scope1' : Unused code path elimination
 * Block '<S115>/Scope10' : Unused code path elimination
 * Block '<S115>/Scope3' : Unused code path elimination
 * Block '<S115>/Scope4' : Unused code path elimination
 * Block '<S115>/Scope5' : Unused code path elimination
 * Block '<S115>/Scope6' : Unused code path elimination
 * Block '<S115>/Scope7' : Unused code path elimination
 * Block '<S115>/Scope8' : Unused code path elimination
 * Block '<S115>/Scope9' : Unused code path elimination
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<S5>/Scope1' : Unused code path elimination
 * Block '<S139>/Data Type Duplicate' : Unused code path elimination
 * Block '<S140>/Data Type Duplicate' : Unused code path elimination
 * Block '<S137>/Scope' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S6>/Scope1' : Unused code path elimination
 * Block '<S6>/Scope10' : Unused code path elimination
 * Block '<S6>/Scope11' : Unused code path elimination
 * Block '<S6>/Scope12' : Unused code path elimination
 * Block '<S6>/Scope17' : Unused code path elimination
 * Block '<S6>/Scope2' : Unused code path elimination
 * Block '<S6>/Scope3' : Unused code path elimination
 * Block '<S6>/Scope4' : Unused code path elimination
 * Block '<S6>/Scope5' : Unused code path elimination
 * Block '<S6>/Scope6' : Unused code path elimination
 * Block '<S6>/Scope7' : Unused code path elimination
 * Block '<S6>/Scope8' : Unused code path elimination
 * Block '<S6>/Scope9' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope8' : Unused code path elimination
 * Block '<S7>/Scope' : Unused code path elimination
 * Block '<S8>/Constant3' : Unused code path elimination
 * Block '<S8>/Relational Operator4' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S8>/Scope1' : Unused code path elimination
 * Block '<S8>/Scope10' : Unused code path elimination
 * Block '<S8>/Scope11' : Unused code path elimination
 * Block '<S8>/Scope12' : Unused code path elimination
 * Block '<S8>/Scope13' : Unused code path elimination
 * Block '<S8>/Scope14' : Unused code path elimination
 * Block '<S8>/Scope15' : Unused code path elimination
 * Block '<S8>/Scope16' : Unused code path elimination
 * Block '<S8>/Scope2' : Unused code path elimination
 * Block '<S8>/Scope3' : Unused code path elimination
 * Block '<S8>/Scope4' : Unused code path elimination
 * Block '<S8>/Scope5' : Unused code path elimination
 * Block '<S8>/Scope6' : Unused code path elimination
 * Block '<S8>/Scope7' : Unused code path elimination
 * Block '<S8>/Scope8' : Unused code path elimination
 * Block '<S8>/Scope9' : Unused code path elimination
 * Block '<S148>/Scope' : Unused code path elimination
 * Block '<S9>/Data Type Conversion12' : Unused code path elimination
 * Block '<S9>/Data Type Conversion13' : Unused code path elimination
 * Block '<S11>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S48>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S60>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S60>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S60>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S65>/Conversion' : Eliminate redundant data type conversion
 * Block '<S66>/Conversion' : Eliminate redundant data type conversion
 * Block '<S52>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion13' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion15' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion17' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion18' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion9' : Eliminate redundant data type conversion
 * Block '<S106>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S107>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S109>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S113>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S139>/Conversion' : Eliminate redundant data type conversion
 * Block '<S140>/Conversion' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S147>/Saturation' : Eliminated Saturate block
 * Block '<S9>/Data Type Conversion25' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'VLCforADAS_UMP'
 * '<S1>'   : 'VLCforADAS_UMP/andrukhe'
 * '<S2>'   : 'VLCforADAS_UMP/andrukhe/Engine Model Subsystem'
 * '<S3>'   : 'VLCforADAS_UMP/andrukhe/If Action Subsystem'
 * '<S4>'   : 'VLCforADAS_UMP/andrukhe/Input Processing1'
 * '<S5>'   : 'VLCforADAS_UMP/andrukhe/Observers'
 * '<S6>'   : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation'
 * '<S7>'   : 'VLCforADAS_UMP/andrukhe/Triggered Subsystem'
 * '<S8>'   : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine'
 * '<S9>'   : 'VLCforADAS_UMP/andrukhe/VLC_Inactive'
 * '<S10>'  : 'VLCforADAS_UMP/andrukhe/Engine Model Subsystem/Discrete filter'
 * '<S11>'  : 'VLCforADAS_UMP/andrukhe/Engine Model Subsystem/Discrete filter3'
 * '<S12>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel'
 * '<S13>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/DO SSR timer'
 * '<S14>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem'
 * '<S15>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1'
 * '<S16>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/MainVestaChart'
 * '<S17>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem'
 * '<S18>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/VehSpd timer'
 * '<S19>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/reqAccelerationLimitation'
 * '<S20>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/FreeRollingDragModel'
 * '<S21>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/PreControl'
 * '<S22>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/SlopeDragTorque'
 * '<S23>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/TransmissionDragModel-01'
 * '<S24>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/TrqRatio'
 * '<S25>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/WheelsInertia'
 * '<S26>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/FreeRollingDragModel/Saturation Dynamic'
 * '<S27>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/PreControl/Basic calculation'
 * '<S28>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/PreControl/Compare To Constant1'
 * '<S29>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/PreControl/Drag forces'
 * '<S30>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/PreControl/Basic calculation/Adaptation'
 * '<S31>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/PreControl/Basic calculation/TrqLimits'
 * '<S32>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/PreControl/Basic calculation/TrqLimits/Subsystem1'
 * '<S33>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/PreControl/Basic calculation/TrqLimits/Subsystem2'
 * '<S34>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/TrqRatio/Compare To Zero'
 * '<S35>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/TrqRatio/Compare To Zero1'
 * '<S36>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/TrqRatio/Compare To Zero2'
 * '<S37>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/TrqRatio/GearChangeThreshold'
 * '<S38>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/TrqRatio/Triggered Subsystem'
 * '<S39>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/TrqRatio/Triggered Subsystem1'
 * '<S40>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/TrqRatio/TrqRatio'
 * '<S41>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/TrqRatio/TrqRatio/TorqueRatio calc'
 * '<S42>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/TrqRatio/TrqRatio/TorqueRatio calc/TorqueRatioTmr_inc'
 * '<S43>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/BasicModel/TrqRatio/TrqRatio/TorqueRatio calc/TorqueRatioTmr_nul'
 * '<S44>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/DO SSR timer/START DO SSR trm'
 * '<S45>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/DO SSR timer/ZERO DO SSR trm'
 * '<S46>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem/Compare To Constant'
 * '<S47>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem/DriveOff'
 * '<S48>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem/NoDriveOff'
 * '<S49>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1'
 * '<S50>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/Compare To Constant'
 * '<S51>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active'
 * '<S52>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Inactive'
 * '<S53>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1'
 * '<S54>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1/Compare To Constant'
 * '<S55>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1/DirectAX'
 * '<S56>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1/Torque_request_subsystem'
 * '<S57>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1/Torque_request_subsystem1'
 * '<S58>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1/Torque_request_subsystem1/CLBC_Flaw1'
 * '<S59>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1/Torque_request_subsystem1/CLBC_PI_2.0'
 * '<S60>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1/Torque_request_subsystem1/CLBC_PI_2.0/Integrator_v02'
 * '<S61>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1/Torque_request_subsystem1/CLBC_PI_2.0/LinearGradeControl'
 * '<S62>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1/Torque_request_subsystem1/CLBC_PI_2.0/Subsystem'
 * '<S63>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1/Torque_request_subsystem1/CLBC_PI_2.0/Subsystem1'
 * '<S64>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1/Torque_request_subsystem1/CLBC_PI_2.0/Integrator_v02/Saturation Dynamic'
 * '<S65>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1/Torque_request_subsystem1/CLBC_PI_2.0/LinearGradeControl/Data Type Conversion Inherited'
 * '<S66>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1/Torque_request_subsystem1/CLBC_PI_2.0/LinearGradeControl/Data Type Conversion Inherited1'
 * '<S67>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/If Action Subsystem1/VLC_BL0.0.1/VLC_Active/BoostController1/Torque_request_subsystem1/CLBC_PI_2.0/Subsystem1/Protection timer'
 * '<S68>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/CLBC_PI_2.0'
 * '<S69>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/Compare To Constant2'
 * '<S70>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/Compare To Constant3'
 * '<S71>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/DOV_ApprovalTimer'
 * '<S72>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/DOV_TrqOffset'
 * '<S73>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem'
 * '<S74>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem1'
 * '<S75>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/CLBC_PI_2.0/Boost_I'
 * '<S76>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/CLBC_PI_2.0/Subsystem'
 * '<S77>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/CLBC_PI_2.0/Boost_I/Integration'
 * '<S78>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/CLBC_PI_2.0/Boost_I/Saturation Dynamic'
 * '<S79>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/CLBC_PI_2.0/Boost_I/Upper_SAT'
 * '<S80>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/CLBC_PI_2.0/Boost_I/Upper_SAT1'
 * '<S81>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/DOV_ApprovalTimer/If Action Subsystem'
 * '<S82>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/DOV_ApprovalTimer/If Action Subsystem1'
 * '<S83>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem/CLBC_Flaw1'
 * '<S84>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem/CLBC_Flaw1/Subsystem'
 * '<S85>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem/CLBC_Flaw1/refSpeedCalculation'
 * '<S86>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem/CLBC_Flaw1/refSpeedSubsystem'
 * '<S87>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem/CLBC_Flaw1/refSpeedSubsystem/Compare To Constant1'
 * '<S88>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem/CLBC_Flaw1/refSpeedSubsystem/Compare To Constant2'
 * '<S89>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem/CLBC_Flaw1/refSpeedSubsystem/Compare To Constant3'
 * '<S90>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem/CLBC_Flaw1/refSpeedSubsystem/Compare To Constant4'
 * '<S91>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem/CLBC_Flaw1/refSpeedSubsystem/Compare To Zero'
 * '<S92>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem/CLBC_Flaw1/refSpeedSubsystem/Subsystem1'
 * '<S93>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem/CLBC_Flaw1/refSpeedSubsystem/Subsystem1/Compare To Zero1'
 * '<S94>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem/CLBC_Flaw1/refSpeedSubsystem/Subsystem1/Triggered Subsystem'
 * '<S95>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/Subsystem/If Action Subsystem/CLBC_Flaw1/refSpeedSubsystem/Subsystem1/Triggered Subsystem1'
 * '<S96>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/VehSpd timer/START V0 trm'
 * '<S97>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/VehSpd timer/ZERO V0  trm'
 * '<S98>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/reqAccelerationLimitation/AZ5'
 * '<S99>'  : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/reqAccelerationLimitation/reqAccelerationFiltered'
 * '<S100>' : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/reqAccelerationLimitation/AZ5/ProtectionTimer'
 * '<S101>' : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/reqAccelerationLimitation/reqAccelerationFiltered/Discrete filter max'
 * '<S102>' : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/reqAccelerationLimitation/reqAccelerationFiltered/Discrete filter min'
 * '<S103>' : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/reqAccelerationLimitation/reqAccelerationFiltered/Jerk filter'
 * '<S104>' : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/reqAccelerationLimitation/reqAccelerationFiltered/Discrete filter max/Discrete filter'
 * '<S105>' : 'VLCforADAS_UMP/andrukhe/If Action Subsystem/reqAccelerationLimitation/reqAccelerationFiltered/Jerk filter/Compare To Zero'
 * '<S106>' : 'VLCforADAS_UMP/andrukhe/Input Processing1/LateralAccelerationProc_Processing'
 * '<S107>' : 'VLCforADAS_UMP/andrukhe/Input Processing1/LongitudinalAccelerationProc_Processing'
 * '<S108>' : 'VLCforADAS_UMP/andrukhe/Input Processing1/M_MotDrug_Processing'
 * '<S109>' : 'VLCforADAS_UMP/andrukhe/Input Processing1/PSIP_Processing'
 * '<S110>' : 'VLCforADAS_UMP/andrukhe/Input Processing1/Subsystem1'
 * '<S111>' : 'VLCforADAS_UMP/andrukhe/Input Processing1/VehicleSpeed_Processing1'
 * '<S112>' : 'VLCforADAS_UMP/andrukhe/Input Processing1/VehicleSpeed_Processing2'
 * '<S113>' : 'VLCforADAS_UMP/andrukhe/Input Processing1/targetSpeed_Processing'
 * '<S114>' : 'VLCforADAS_UMP/andrukhe/Input Processing1/targetSpeed_Processing/targetSpeed_ICrecalculation'
 * '<S115>' : 'VLCforADAS_UMP/andrukhe/Observers/Ax'
 * '<S116>' : 'VLCforADAS_UMP/andrukhe/Observers/VTB'
 * '<S117>' : 'VLCforADAS_UMP/andrukhe/Observers/Ax/ComparConst'
 * '<S118>' : 'VLCforADAS_UMP/andrukhe/Observers/Ax/Compare To Constant1'
 * '<S119>' : 'VLCforADAS_UMP/andrukhe/Observers/Ax/Ga_OLDC'
 * '<S120>' : 'VLCforADAS_UMP/andrukhe/Observers/Ax/brake caliper model'
 * '<S121>' : 'VLCforADAS_UMP/andrukhe/Observers/Ax/brake caliper model/Brake system FR'
 * '<S122>' : 'VLCforADAS_UMP/andrukhe/Observers/Ax/brake caliper model/Brake system FR1'
 * '<S123>' : 'VLCforADAS_UMP/andrukhe/Observers/Ax/brake caliper model/Brake system RR'
 * '<S124>' : 'VLCforADAS_UMP/andrukhe/Observers/Ax/brake caliper model/Brake system RR1'
 * '<S125>' : 'VLCforADAS_UMP/andrukhe/Observers/VTB/Kinematic tirn1'
 * '<S126>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/Chart'
 * '<S127>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/Compare To Constant1'
 * '<S128>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/Compare To Constant2'
 * '<S129>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/DiscreteFilter_LA_YRS'
 * '<S130>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/DiscreteFilter_LA_YRS1'
 * '<S131>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/DiscreteFilter_LA_YRS2'
 * '<S132>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/DiscreteFilter_VA_YRS'
 * '<S133>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/DiscreteFilter_VS_YRS'
 * '<S134>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/LinearGradeControl2'
 * '<S135>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/Protection timer1'
 * '<S136>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/Protection timer2'
 * '<S137>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/Protection timer3'
 * '<S138>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/reqAccelerationOffset'
 * '<S139>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/LinearGradeControl2/Data Type Conversion Inherited'
 * '<S140>' : 'VLCforADAS_UMP/andrukhe/Road Grade Calculation/LinearGradeControl2/Data Type Conversion Inherited1'
 * '<S141>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/Compare To Constant'
 * '<S142>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/Compare To Constant1'
 * '<S143>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/Compare To Constant2'
 * '<S144>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/Compare To Constant3'
 * '<S145>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/Compare To Zero'
 * '<S146>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/Compare To Zero1'
 * '<S147>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/Discrete filter1'
 * '<S148>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/Subsystem'
 * '<S149>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/Trq is Down'
 * '<S150>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/Trq isn't down'
 * '<S151>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/VLC_TargetEngTorque processing1'
 * '<S152>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/Subsystem/SubsystemPlausibilityDec'
 * '<S153>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/Subsystem/SubsystemPlausibilityInc'
 * '<S154>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/Trq is Down/Else Plaussib_down'
 * '<S155>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/Trq is Down/If Plaussib_down'
 * '<S156>' : 'VLCforADAS_UMP/andrukhe/VLC Decision making machine/VLC_TargetEngTorque processing1/Discrete filter'
 */

/*-
 * Requirements for '<Root>': VLCforADAS_UMP
 */
#endif                                 /* RTW_HEADER_VLCforADAS_UMP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
