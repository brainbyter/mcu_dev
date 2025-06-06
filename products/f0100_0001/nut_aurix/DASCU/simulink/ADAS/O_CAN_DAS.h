/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* 0..2 Mode of trafic AA 0-Off 1-StandBy 2-Active intval=realval */
#define DECLARED_AaMode	AaMode
extern uint8_t AaMode;

/* 0..1 Notification to wake up intval=realval */
#define DECLARED_AaWarnNotifReq	AaWarnNotifReq
extern uint8_t AaWarnNotifReq;

/* 0..2 ADAS Status 0 - NotAvailable 1 - Degradate 2 - Available intval=realval */
#define DECLARED_AdasAvailMode	AdasAvailMode
extern uint8_t AdasAvailMode;

/* 0..1 AEB is requesting brake boost: 0- No Req 1-Request intval=realval */
#define DECLARED_AebBoostReq	AebBoostReq
extern uint8_t AebBoostReq;

/* 0..1 Notification for IC: Emergency braking is deactivated: 0=Off 1=Active intval=realval */
#define DECLARED_AebDeactivNotif	AebDeactivNotif
extern uint8_t AebDeactivNotif;

/* -20..20 Implement deceleration, ms^2 intval=realval */
#define DECLARED_AebDecelReq	AebDecelReq
extern float AebDecelReq;

/* 0..1 AEB is requesting to implement deceleration: 0- No Req 1-Request intval=realval */
#define DECLARED_AebDecelReqFlag	AebDecelReqFlag
extern uint8_t AebDecelReqFlag;

/* 0..1 Error symbol of AEB 0=Inactive 1=Active intval=realval */
#define DECLARED_AebFuncError	AebFuncError
extern uint8_t AebFuncError;

/* 0..1 Mode of emergency braking intval=realval */
#define DECLARED_AebMode	AebMode
extern uint8_t AebMode;

/* 0..1 Error notification of AEB 0=Inactive 1=Active intval=realval */
#define DECLARED_AebNotifError	AebNotifError
extern uint8_t AebNotifError;

/* 0..1 AEB is inform a potential accident 0-nothing 1-Request intval=realval */
#define DECLARED_AebPreCrash	AebPreCrash
extern uint8_t AebPreCrash;

/* 0..1 AEB is requesting brake prefill: 0- No Req 1-Request intval=realval */
#define DECLARED_AebPrefillReq	AebPrefillReq
extern uint8_t AebPrefillReq;

/* 0..1 AEB or RDA is requestin enable HOLD intval=realval */
#define DECLARED_AebRdaStandReq	AebRdaStandReq
extern uint8_t AebRdaStandReq;

/* 0..1 The function works, but does not see objects due to rain/sunlight. intval=realval */
#define DECLARED_AebUnAvaliable	AebUnAvaliable
extern uint8_t AebUnAvaliable;

/* 0..1 Enable the brake jerk warning functionnality 0 = Disable 1 = Enable intval=realval */
#define DECLARED_AfsBrakeJerkEn	AfsBrakeJerkEn
extern uint8_t AfsBrakeJerkEn;

/* 0..255 Indicates strength of Brake Jerk warning level requested by AFS intval=realval */
#define DECLARED_AfsBrakeJerkLevel	AfsBrakeJerkLevel
extern uint8_t AfsBrakeJerkLevel;

/* 0..1 AFS requests a brake jerk to warn the driver in a hazardous situation intval=realval */
#define DECLARED_AfsBrakeJerkReq	AfsBrakeJerkReq
extern uint8_t AfsBrakeJerkReq;

/* 0..1 AFS is requesting to implement deceleration: 0- No Req 1-Request intval=realval */
#define DECLARED_AfsDecelReqFlag	AfsDecelReqFlag
extern uint8_t AfsDecelReqFlag;

/* 0..1 AFS is requesting open door and emergency lights: 0- No Req 1-Request intval=realval */
#define DECLARED_AfsDoorUnlookReq	AfsDoorUnlookReq
extern uint8_t AfsDoorUnlookReq;

/* 0..1 Error of AFS  0=no Error 1= Error intval=realval */
#define DECLARED_AfsFuncError	AfsFuncError
extern uint8_t AfsFuncError;

/* 0..1 Mode of AFS 0-Off  1-Active intval=realval */
#define DECLARED_AfsMode	AfsMode
extern uint8_t AfsMode;

/* 0..1 Error notification of AFS 0=Inactive 1=Active intval=realval */
#define DECLARED_AfsNotifError	AfsNotifError
extern uint8_t AfsNotifError;

/* 0..1 AFS is requesting call SOS: 0- No Req 1-Request intval=realval */
#define DECLARED_AfsSosReq	AfsSosReq
extern uint8_t AfsSosReq;

/* 0..1 ALCC is requesting to implement angle on steering wheel: 0- No Req 1-Request intval=realval */
#define DECLARED_AlccAngleReqFlag	AlccAngleReqFlag
extern uint8_t AlccAngleReqFlag;

/* 0..1 Mode of Active Lane Change Control  0-Off 1-Active intval=realval */
#define DECLARED_ALccMode	ALccMode
extern uint8_t ALccMode;

/* 0..1 Error notification of ALCC 0=Inactive 1=Active intval=realval */
#define DECLARED_ALccNotifError	ALccNotifError
extern uint8_t ALccNotifError;

/* 0..254 Request to IC  to show notification, kmh 0-no req 1 - 1 kmh… intval=realval */
#define DECLARED_AslaChSpdReq	AslaChSpdReq
extern uint8_t AslaChSpdReq;

/* 0..1 Mode of Active speed limit assist 0= OFF 1=Active intval=realval */
#define DECLARED_AslaMode	AslaMode
extern uint8_t AslaMode;

/* -20..20 Implement deceleration, ms^2 intval=realval */
#define DECLARED_CcAfsDecelReq	CcAfsDecelReq
extern float CcAfsDecelReq;

/* 0..1 CC is requesting the brake light to be turned on: 0-Turn OFF 1-Turn ON intval=realval */
#define DECLARED_CcBrakeLightReq	CcBrakeLightReq
extern uint8_t CcBrakeLightReq;

/* 0..1 Cruise is requesting to start the car: 0- No Req 1-Request intval=realval */
#define DECLARED_CcBrakeReleaseReq	CcBrakeReleaseReq
extern uint8_t CcBrakeReleaseReq;

/* 0..1 Cruise is requesting a car hold: 0- No Req 1-Request intval=realval */
#define DECLARED_CcBrakeStandStReq	CcBrakeStandStReq
extern uint8_t CcBrakeStandStReq;

/* 0..1 Cruise is requesting to implement deceleration: 0- No Req 1-Request intval=realval */
#define DECLARED_CcDecelReqFlag	CcDecelReqFlag
extern uint8_t CcDecelReqFlag;

/* 0..3 _Type of CC: 0=Nothing 1=CC/ACC  2=LIM  3-MAS intval=realval */
#define DECLARED_CcEmsEngagement_Stat	CcEmsEngagement_Stat
extern uint8_t CcEmsEngagement_Stat;

/* -200..1000 Target total torque on engine intval=realval */
#define DECLARED_CcEmsMotInc	CcEmsMotInc
extern float CcEmsMotInc;

/* 0..1 Engine torque increase request flag intval=realval */
#define DECLARED_CcEmsMotIncFlag	CcEmsMotIncFlag
extern uint8_t CcEmsMotIncFlag;

/* 0..1 Mode of CC 0=Off 1=Active intval=realval */
#define DECLARED_CcEmsState_Stat	CcEmsState_Stat
extern uint8_t CcEmsState_Stat;

/* 0..1 Error symbol of CC 0=Inactive (No error) 1=Active (Error) intval=realval */
#define DECLARED_CcFuncError	CcFuncError
extern uint8_t CcFuncError;

/* 0..7 Current set distance to vehicle in front for ACC function 0 - close, 1 - normal, 2 - long away intval=realval */
#define DECLARED_CcHudSetDist	CcHudSetDist
extern uint8_t CcHudSetDist;

/* 0..255 Current set speed in ACC function intval=realval */
#define DECLARED_CcHudSetSpeed	CcHudSetSpeed
extern uint8_t CcHudSetSpeed;

/* 0..1 ACC detection status: 0 - not detected, 1 - detected intval=realval */
#define DECLARED_CcHudTargDetect	CcHudTargDetect
extern uint8_t CcHudTargDetect;

/* 0..3 Mode of CC: 0=Off 1=Standby 2=Active 3=Override intval=realval */
#define DECLARED_CcMode	CcMode
extern uint8_t CcMode;

/* 0..1 Error notification of CC 0=Inactive 1=Active intval=realval */
#define DECLARED_CcNotifError	CcNotifError
extern uint8_t CcNotifError;

/* 0..6 CC is requesting the notification:  0- nothing 1 - Cruise cannot be activated 2 - Cruise cannot be activated. The seat belt is not fastened. 3 - Cruise cannot be activated due to Off Road mode. 4 - Cruise cannot be activated due to insufficient travel speed. 5 - Cruise Function off (With sound). 6 - Lim is not available. intval=realval */
#define DECLARED_CcReject	CcReject
extern uint8_t CcReject;

/* 0..3 Target distance 0-min, 1-lowmed, 2-med, 3-max intval=realval */
#define DECLARED_CcSetDist	CcSetDist
extern uint8_t CcSetDist;

/* 0..255 Targer Speed kmh intval=realval */
#define DECLARED_CcSetSpeed	CcSetSpeed
extern uint8_t CcSetSpeed;

/* 0..1 CC has fallen asleep  0 - No sleep,   1- Sleep intval=realval */
#define DECLARED_CcSleepSt	CcSleepSt
extern uint8_t CcSleepSt;

/* 0..1 A flag indicating that the car is detected 0 - No Target Car  1 - target car is intval=realval */
#define DECLARED_CcTargetId	CcTargetId
extern uint8_t CcTargetId;

/* 0..3 Type cruis control 0=Nothign 1=CC 2=ACC SG 3=LIM intval=realval */
#define DECLARED_CcType	CcType
extern uint8_t CcType;

/* 0..3 _Type of CC: 0=Nothing 1=CC/ACC  2=LIM  3-MAS intval=realval */
#define DECLARED_CcVcuEngagement_Stat	CcVcuEngagement_Stat
extern uint8_t CcVcuEngagement_Stat;

/* 0..1000 Target total torque on engine intval=realval */
#define DECLARED_CcVcuMotInc	CcVcuMotInc
extern float CcVcuMotInc;

/* 0..1 Engine torque increase request flag intval=realval */
#define DECLARED_CcVcuMotIncFlag	CcVcuMotIncFlag
extern uint8_t CcVcuMotIncFlag;

/* 0..3 Mode of CC 0=Off 1=Standby 2=Active 3=Override intval=realval */
#define DECLARED_CcVcuState_Stat	CcVcuState_Stat
extern uint8_t CcVcuState_Stat;

/* 0..1 Mode of Door Open Warning  0-Off 1-Active intval=realval */
#define DECLARED_DowMode	DowMode
extern uint8_t DowMode;

/* 0..1 Error notification of DOW 0=Inactive 1=Active intval=realval */
#define DECLARED_DowNotifError	DowNotifError
extern uint8_t DowNotifError;

/* 0..1 Notification for IC: Front collision warning is activated: 0=Off 1=Active intval=realval */
#define DECLARED_FcwActivNotif	FcwActivNotif
extern uint8_t FcwActivNotif;

/* 0..1 Mode of front colision warning intval=realval */
#define DECLARED_FcwMode	FcwMode
extern uint8_t FcwMode;

/* 0..1 Error notification of FCW 0=Inactive 1=Active intval=realval */
#define DECLARED_FcwNotifError	FcwNotifError
extern uint8_t FcwNotifError;

/* 0..1 FCW is requesting warning sound 0-nothing 1-Request intval=realval */
#define DECLARED_FcwSoundWarnReq	FcwSoundWarnReq
extern uint8_t FcwSoundWarnReq;

/* 0..1 Error symbol of LCC 0=Inactive 1=Active intval=realval */
#define DECLARED_LccFuncError	LccFuncError
extern uint8_t LccFuncError;

/* 0..1 LCC is requesting activate left LED: 0- No Req 1-light intval=realval */
#define DECLARED_LccLeftLedReq	LccLeftLedReq
extern uint8_t LccLeftLedReq;

/* 0..1 LCC is requesting activate notification left side : 0- No Req 1-Request intval=realval */
#define DECLARED_LccLeftWarnReq	LccLeftWarnReq
extern uint8_t LccLeftWarnReq;

/* 0..2 Mode of Lane Change Control 0-Off  1- StandBy 2-Active intval=realval */
#define DECLARED_LccMode	LccMode
extern uint8_t LccMode;

/* 0..1 Error notification of LCC 0=Inactive 1=Active intval=realval */
#define DECLARED_LccNotifError	LccNotifError
extern uint8_t LccNotifError;

/* 0..1 LCC is requesting activate right LED: 0- No Req 1-light intval=realval */
#define DECLARED_LccRightLedReq	LccRightLedReq
extern uint8_t LccRightLedReq;

/* 0..1 LCC is requesting activate notification right side : 0- No Req 1-Request intval=realval */
#define DECLARED_LccRightWarnReq	LccRightWarnReq
extern uint8_t LccRightWarnReq;

/* 0..1 LCC is requesting sound warning: 0- No Req 1-Request intval=realval */
#define DECLARED_LccSoundReq	LccSoundReq
extern uint8_t LccSoundReq;

/* 0..1 LDP is requesting to implement angle on steering wheel: 0- No Req 1-Request intval=realval */
#define DECLARED_LdpAngleReqFlag	LdpAngleReqFlag
extern uint8_t LdpAngleReqFlag;

/* 0..1 LDP is requesting warning notification Left line: 0- No Req 1-Request intval=realval */
#define DECLARED_LdpLeftLaneWarnReq	LdpLeftLaneWarnReq
extern uint8_t LdpLeftLaneWarnReq;

/* 0..1 Mode of Lane Departure Prevention 0-Off  1- Active intval=realval */
#define DECLARED_LdpMode	LdpMode
extern uint8_t LdpMode;

/* 0..1 Error notification of LDP 0=Inactive 1=Active intval=realval */
#define DECLARED_LdpNotifError	LdpNotifError
extern uint8_t LdpNotifError;

/* 0..1 LDP is requesting warning notification Right line: 0- No Req 1-Request intval=realval */
#define DECLARED_LdpRightLaneWarnReq	LdpRightLaneWarnReq
extern uint8_t LdpRightLaneWarnReq;

/* 0..1 Error symbol of LDW 0=Inactive 1=Active (LDP->LDW) intval=realval */
#define DECLARED_LdwFuncError	LdwFuncError
extern uint8_t LdwFuncError;

/* 0..1 LDW activation status 0- inactive 1- active intval=realval */
#define DECLARED_LdwHudActSt	LdwHudActSt
extern uint8_t LdwHudActSt;

/* 0..1 Multiplexor LDW is requesting FOR HUD intval=realval */
#define DECLARED_LdwHudMultiLaneAddres	LdwHudMultiLaneAddres
extern uint8_t LdwHudMultiLaneAddres;

/* 0..1 LDW is requesting FOR HUD warning notification: 0- No Req 1-Request intval=realval */
#define DECLARED_LdwHudMultiLaneWarnReq	LdwHudMultiLaneWarnReq
extern uint8_t LdwHudMultiLaneWarnReq;

/* 0..1 LDW is requesting warning notification Left line: 0- No Req 1-Request intval=realval */
#define DECLARED_LdwLeftLaneWarnReq	LdwLeftLaneWarnReq
extern uint8_t LdwLeftLaneWarnReq;

/* 0..4 Mode of Lane Departure Warning 0-Off  1- StandBy 2-Active 3 - ActiveLeft 4 - ActiveRight intval=realval */
#define DECLARED_LdwMode	LdwMode
extern uint8_t LdwMode;

/* 0..1 Error notification of LDW 0=Inactive 1=Active intval=realval */
#define DECLARED_LdwNotifError	LdwNotifError
extern uint8_t LdwNotifError;

/* 0..1 LDW is requesting warning notification Right line: 0- No Req 1-Request intval=realval */
#define DECLARED_LdwRightLaneWarnReq	LdwRightLaneWarnReq
extern uint8_t LdwRightLaneWarnReq;

/* 0..1 LDW is requesting warning sound: 0- No Req 1-Request intval=realval */
#define DECLARED_LdwSoundReq	LdwSoundReq
extern uint8_t LdwSoundReq;

/* -540..540 [deg] Angle request intval=realval */
#define DECLARED_LkaAngleReq	LkaAngleReq
extern float LkaAngleReq;

/* 0..1 LKA is requesting to implement angle  on steering wheel:: 0- No Req 1-Request intval=realval */
#define DECLARED_LkaAngleReqFlag	LkaAngleReqFlag
extern uint8_t LkaAngleReqFlag;

/* 0..1 Error symbol of LKA 0=Inactive 1=Active intval=realval */
#define DECLARED_LkaFuncError	LkaFuncError
extern uint8_t LkaFuncError;

/* 0..3 Mode of LKA 0-Off 1-StandBy 2-Active 3-Active+TakeOver intval=realval */
#define DECLARED_LkaMode	LkaMode
extern uint8_t LkaMode;

/* 0..1 Error notification of LKA 0=Inactive 1=Active (AEB->LKA) intval=realval */
#define DECLARED_LkaNotifError	LkaNotifError
extern uint8_t LkaNotifError;

/* 0..1 Sound when function is turned off  0 - no sound  1- sound intval=realval */
#define DECLARED_LkaShotdownSoundReq	LkaShotdownSoundReq
extern uint8_t LkaShotdownSoundReq;

/* 0..1 Notification to take the steering wheel intval=realval */
#define DECLARED_LkaWarnNotifReq	LkaWarnNotifReq
extern uint8_t LkaWarnNotifReq;

/* 0..1 Warning sound to take the steering wheel intval=realval */
#define DECLARED_LkaWarnSoundReq	LkaWarnSoundReq
extern uint8_t LkaWarnSoundReq;

/* 0..1 Error of MLIA  0-Inactive 1-Active intval=realval */
#define DECLARED_MliaFuncError	MliaFuncError
extern uint8_t MliaFuncError;

/* 0..1 Left_ADB LED#10 Control Signal intval=realval */
#define DECLARED_MliaLADBLED10Req	MliaLADBLED10Req
extern uint8_t MliaLADBLED10Req;

/* 0..1 Left_ADB LED#11 Control Signal intval=realval */
#define DECLARED_MliaLADBLED11Req	MliaLADBLED11Req
extern uint8_t MliaLADBLED11Req;

/* 0..1 Left_ADB LED#12 Control Signal intval=realval */
#define DECLARED_MliaLADBLED12Req	MliaLADBLED12Req
extern uint8_t MliaLADBLED12Req;

/* 0..1 Left_ADB LED#13 Control Signal intval=realval */
#define DECLARED_MliaLADBLED13Req	MliaLADBLED13Req
extern uint8_t MliaLADBLED13Req;

/* 0..1 Left_ADB LED#14 Control Signal intval=realval */
#define DECLARED_MliaLADBLED14Req	MliaLADBLED14Req
extern uint8_t MliaLADBLED14Req;

/* 0..1 Left_ADB LED#15 Control Signal intval=realval */
#define DECLARED_MliaLADBLED15Req	MliaLADBLED15Req
extern uint8_t MliaLADBLED15Req;

/* 0..1 Left_ADB LED#16 Control Signal intval=realval */
#define DECLARED_MliaLADBLED16Req	MliaLADBLED16Req
extern uint8_t MliaLADBLED16Req;

/* 0..1 Left_ADB LED#17 Control Signal intval=realval */
#define DECLARED_MliaLADBLED17Req	MliaLADBLED17Req
extern uint8_t MliaLADBLED17Req;

/* 0..1 Left_ADB LED#18 Control Signal intval=realval */
#define DECLARED_MliaLADBLED18Req	MliaLADBLED18Req
extern uint8_t MliaLADBLED18Req;

/* 0..1 Left_ADB LED#1 Control Signal intval=realval */
#define DECLARED_MliaLADBLED1Req	MliaLADBLED1Req
extern uint8_t MliaLADBLED1Req;

/* 0..1 Left_ADB LED#2 Control Signal intval=realval */
#define DECLARED_MliaLADBLED2Req	MliaLADBLED2Req
extern uint8_t MliaLADBLED2Req;

/* 0..1 Left_ADB LED#3 Control Signal intval=realval */
#define DECLARED_MliaLADBLED3Req	MliaLADBLED3Req
extern uint8_t MliaLADBLED3Req;

/* 0..1 Left_ADB LED#4 Control Signal intval=realval */
#define DECLARED_MliaLADBLED4Req	MliaLADBLED4Req
extern uint8_t MliaLADBLED4Req;

/* 0..1 Left_ADB LED#5 Control Signal intval=realval */
#define DECLARED_MliaLADBLED5Req	MliaLADBLED5Req
extern uint8_t MliaLADBLED5Req;

/* 0..1 Left_ADB LED#6 Control Signal intval=realval */
#define DECLARED_MliaLADBLED6Req	MliaLADBLED6Req
extern uint8_t MliaLADBLED6Req;

/* 0..1 Left_ADB LED#7 Control Signal intval=realval */
#define DECLARED_MliaLADBLED7Req	MliaLADBLED7Req
extern uint8_t MliaLADBLED7Req;

/* 0..1 Left_ADB LED#8 Control Signal intval=realval */
#define DECLARED_MliaLADBLED8Req	MliaLADBLED8Req
extern uint8_t MliaLADBLED8Req;

/* 0..1 Left_ADB LED#9 Control Signal intval=realval */
#define DECLARED_MliaLADBLED9Req	MliaLADBLED9Req
extern uint8_t MliaLADBLED9Req;

/* 0..321 Object_10 Horizontal Value_1 intval=realval */
#define DECLARED_MliaLeftObj10Y1Val	MliaLeftObj10Y1Val
extern float MliaLeftObj10Y1Val;

/* 0..321 Object_10 Horizontal Value_2 intval=realval */
#define DECLARED_MliaLeftObj10Y2Val	MliaLeftObj10Y2Val
extern float MliaLeftObj10Y2Val;

/* 0..81 Object_10 Vertical Value_1 intval=realval */
#define DECLARED_MliaLeftObj10Z1Val	MliaLeftObj10Z1Val
extern uint8_t MliaLeftObj10Z1Val;

/* 0..81 Object_10 Vertical  Value_2 intval=realval */
#define DECLARED_MliaLeftObj10Z2Val	MliaLeftObj10Z2Val
extern uint8_t MliaLeftObj10Z2Val;

/* 0..511 Object_1 Horizontal Value_1 intval=realval */
#define DECLARED_MliaLeftObj1Y1Val	MliaLeftObj1Y1Val
extern float MliaLeftObj1Y1Val;

/* 0..321 Object_1 Horizontal Value_2 intval=realval */
#define DECLARED_MliaLeftObj1Y2Val	MliaLeftObj1Y2Val
extern float MliaLeftObj1Y2Val;

/* 0..81 Object_1 Vertical Value_1 intval=realval */
#define DECLARED_MliaLeftObj1Z1Val	MliaLeftObj1Z1Val
extern uint8_t MliaLeftObj1Z1Val;

/* 0..81 Object_1 Vertical  Value_2 intval=realval */
#define DECLARED_MliaLeftObj1Z2Val	MliaLeftObj1Z2Val
extern uint8_t MliaLeftObj1Z2Val;

/* 0..321 Object_2 Horizontal Value_1 intval=realval */
#define DECLARED_MliaLeftObj2Y1Val	MliaLeftObj2Y1Val
extern float MliaLeftObj2Y1Val;

/* 0..321 Object_2 Horizontal Value_2 intval=realval */
#define DECLARED_MliaLeftObj2Y2Val	MliaLeftObj2Y2Val
extern float MliaLeftObj2Y2Val;

/* 0..81 Object_2 Vertical Value_1 intval=realval */
#define DECLARED_MliaLeftObj2Z1Val	MliaLeftObj2Z1Val
extern uint8_t MliaLeftObj2Z1Val;

/* 0..81 Object_2 Vertical  Value_2 intval=realval */
#define DECLARED_MliaLeftObj2Z2Val	MliaLeftObj2Z2Val
extern uint8_t MliaLeftObj2Z2Val;

/* 0..321 Object_3 Horizontal Value_1 intval=realval */
#define DECLARED_MliaLeftObj3Y1Val	MliaLeftObj3Y1Val
extern float MliaLeftObj3Y1Val;

/* 0..321 Object_3 Horizontal Value_2 intval=realval */
#define DECLARED_MliaLeftObj3Y2Val	MliaLeftObj3Y2Val
extern float MliaLeftObj3Y2Val;

/* 0..81 Object_3 Vertical Value_1 intval=realval */
#define DECLARED_MliaLeftObj3Z1Val	MliaLeftObj3Z1Val
extern uint8_t MliaLeftObj3Z1Val;

/* 0..81 Object_3 Vertical  Value_2 intval=realval */
#define DECLARED_MliaLeftObj3Z2Val	MliaLeftObj3Z2Val
extern uint8_t MliaLeftObj3Z2Val;

/* 0..321 Object_4 Horizontal Value_1 intval=realval */
#define DECLARED_MliaLeftObj4Y1Val	MliaLeftObj4Y1Val
extern float MliaLeftObj4Y1Val;

/* 0..321 Object_4 Horizontal Value_2 intval=realval */
#define DECLARED_MliaLeftObj4Y2Val	MliaLeftObj4Y2Val
extern float MliaLeftObj4Y2Val;

/* 0..81 Object_4 Vertical Value_1 intval=realval */
#define DECLARED_MliaLeftObj4Z1Val	MliaLeftObj4Z1Val
extern uint8_t MliaLeftObj4Z1Val;

/* 0..81 Object_4 Vertical  Value_2 intval=realval */
#define DECLARED_MliaLeftObj4Z2Val	MliaLeftObj4Z2Val
extern uint8_t MliaLeftObj4Z2Val;

/* 0..321 Object_5 Horizontal Value_1 intval=realval */
#define DECLARED_MliaLeftObj5Y1Val	MliaLeftObj5Y1Val
extern float MliaLeftObj5Y1Val;

/* 0..321 Object_5 Horizontal Value_2 intval=realval */
#define DECLARED_MliaLeftObj5Y2Val	MliaLeftObj5Y2Val
extern float MliaLeftObj5Y2Val;

/* 0..81 Object_5 Vertical Value_1 intval=realval */
#define DECLARED_MliaLeftObj5Z1Val	MliaLeftObj5Z1Val
extern uint8_t MliaLeftObj5Z1Val;

/* 0..81 Object_5 Vertical  Value_2 intval=realval */
#define DECLARED_MliaLeftObj5Z2Val	MliaLeftObj5Z2Val
extern uint8_t MliaLeftObj5Z2Val;

/* 0..321 Object_6 Horizontal Value_1 intval=realval */
#define DECLARED_MliaLeftObj6Y1Val	MliaLeftObj6Y1Val
extern float MliaLeftObj6Y1Val;

/* 0..321 Object_6 Horizontal Value_2 intval=realval */
#define DECLARED_MliaLeftObj6Y2Val	MliaLeftObj6Y2Val
extern float MliaLeftObj6Y2Val;

/* 0..81 Object_6 Vertical Value_1 intval=realval */
#define DECLARED_MliaLeftObj6Z1Val	MliaLeftObj6Z1Val
extern uint8_t MliaLeftObj6Z1Val;

/* 0..81 Object_6 Vertical  Value_2 intval=realval */
#define DECLARED_MliaLeftObj6Z2Val	MliaLeftObj6Z2Val
extern uint8_t MliaLeftObj6Z2Val;

/* 0..321 Object_7 Horizontal Value_1 intval=realval */
#define DECLARED_MliaLeftObj7Y1Val	MliaLeftObj7Y1Val
extern float MliaLeftObj7Y1Val;

/* 0..321 Object_7 Horizontal Value_2 intval=realval */
#define DECLARED_MliaLeftObj7Y2Val	MliaLeftObj7Y2Val
extern float MliaLeftObj7Y2Val;

/* 0..81 Object_7 Vertical Value_1 intval=realval */
#define DECLARED_MliaLeftObj7Z1Val	MliaLeftObj7Z1Val
extern uint8_t MliaLeftObj7Z1Val;

/* 0..81 Object_7 Vertical  Value_2 intval=realval */
#define DECLARED_MliaLeftObj7Z2Val	MliaLeftObj7Z2Val
extern uint8_t MliaLeftObj7Z2Val;

/* 0..321 Object_8 Horizontal Value_1 intval=realval */
#define DECLARED_MliaLeftObj8Y1Val	MliaLeftObj8Y1Val
extern float MliaLeftObj8Y1Val;

/* 0..321 Object_8 Horizontal Value_2 intval=realval */
#define DECLARED_MliaLeftObj8Y2Val	MliaLeftObj8Y2Val
extern float MliaLeftObj8Y2Val;

/* 0..81 Object_8 Vertical Value_1 intval=realval */
#define DECLARED_MliaLeftObj8Z1Val	MliaLeftObj8Z1Val
extern uint8_t MliaLeftObj8Z1Val;

/* 0..81 Object_8 Vertical  Value_2 intval=realval */
#define DECLARED_MliaLeftObj8Z2Val	MliaLeftObj8Z2Val
extern uint8_t MliaLeftObj8Z2Val;

/* 0..321 Object_9 Horizontal Value_1 intval=realval */
#define DECLARED_MliaLeftObj9Y1Val	MliaLeftObj9Y1Val
extern float MliaLeftObj9Y1Val;

/* 0..321 Object_9 Horizontal Value_2 intval=realval */
#define DECLARED_MliaLeftObj9Y2Val	MliaLeftObj9Y2Val
extern float MliaLeftObj9Y2Val;

/* 0..81 Object_9 Vertical Value_1 intval=realval */
#define DECLARED_MliaLeftObj9Z1Val	MliaLeftObj9Z1Val
extern uint8_t MliaLeftObj9Z1Val;

/* 0..81 Object_9 Vertical  Value_2 intval=realval */
#define DECLARED_MliaLeftObj9Z2Val	MliaLeftObj9Z2Val
extern uint8_t MliaLeftObj9Z2Val;

/* 0..7 Slot_1 Projection Brightness Control Signal intval=realval */
#define DECLARED_MliaLeftProjBrightSlot1Req	MliaLeftProjBrightSlot1Req
extern uint8_t MliaLeftProjBrightSlot1Req;

/* 0..7 Slot_2 Projection Brightness Control Signal intval=realval */
#define DECLARED_MliaLeftProjBrightSlot2Req	MliaLeftProjBrightSlot2Req
extern uint8_t MliaLeftProjBrightSlot2Req;

/* 0..7 Slot_3 Projection Brightness Control Signal intval=realval */
#define DECLARED_MliaLeftProjBrightSlot3Req	MliaLeftProjBrightSlot3Req
extern uint8_t MliaLeftProjBrightSlot3Req;

/* 0..7 Slot_4 Projection Brightness Control Signal intval=realval */
#define DECLARED_MliaLeftProjBrightSlot4Req	MliaLeftProjBrightSlot4Req
extern uint8_t MliaLeftProjBrightSlot4Req;

/* 0..65 Slot_1 Projection Control Signal intval=realval */
#define DECLARED_MliaLeftProjSlot1Req	MliaLeftProjSlot1Req
extern uint8_t MliaLeftProjSlot1Req;

/* 0..15 Slot_2 Projection Control Signal intval=realval */
#define DECLARED_MliaLeftProjSlot2Req	MliaLeftProjSlot2Req
extern uint8_t MliaLeftProjSlot2Req;

/* 0..7 Slot_3 Projection Control Signal intval=realval */
#define DECLARED_MliaLeftProjSlot3Req	MliaLeftProjSlot3Req
extern uint8_t MliaLeftProjSlot3Req;

/* 0..7 Slot_4 Projection Control Signal intval=realval */
#define DECLARED_MliaLeftProjSlot4Req	MliaLeftProjSlot4Req
extern uint8_t MliaLeftProjSlot4Req;

/* 0..3 Mode of Matrix light assistant  0-Off  1 StandBy(V<30) 2-Active 3- Boost intval=realval */
#define DECLARED_MliaMode	MliaMode
extern uint8_t MliaMode;

/* 0..1 Right_ADB LED#10 Control Signal intval=realval */
#define DECLARED_MliaRADBLED10Req	MliaRADBLED10Req
extern uint8_t MliaRADBLED10Req;

/* 0..1 Right_ADB LED#11 Control Signal intval=realval */
#define DECLARED_MliaRADBLED11Req	MliaRADBLED11Req
extern uint8_t MliaRADBLED11Req;

/* 0..1 Right_ADB LED#12 Control Signal intval=realval */
#define DECLARED_MliaRADBLED12Req	MliaRADBLED12Req
extern uint8_t MliaRADBLED12Req;

/* 0..1 Right_ADB LED#13 Control Signal intval=realval */
#define DECLARED_MliaRADBLED13Req	MliaRADBLED13Req
extern uint8_t MliaRADBLED13Req;

/* 0..1 Right_ADB LED#14 Control Signal intval=realval */
#define DECLARED_MliaRADBLED14Req	MliaRADBLED14Req
extern uint8_t MliaRADBLED14Req;

/* 0..1 Right_ADB LED#15 Control Signal intval=realval */
#define DECLARED_MliaRADBLED15Req	MliaRADBLED15Req
extern uint8_t MliaRADBLED15Req;

/* 0..1 Right_ADB LED#16 Control Signal intval=realval */
#define DECLARED_MliaRADBLED16Req	MliaRADBLED16Req
extern uint8_t MliaRADBLED16Req;

/* 0..1 Right_ADB LED#17 Control Signal intval=realval */
#define DECLARED_MliaRADBLED17Req	MliaRADBLED17Req
extern uint8_t MliaRADBLED17Req;

/* 0..1 Right_ADB LED#18 Control Signal intval=realval */
#define DECLARED_MliaRADBLED18Req	MliaRADBLED18Req
extern uint8_t MliaRADBLED18Req;

/* 0..1 Right_ADB LED#1 Control Signal intval=realval */
#define DECLARED_MliaRADBLED1Req	MliaRADBLED1Req
extern uint8_t MliaRADBLED1Req;

/* 0..1 Right_ADB LED#2 Control Signal intval=realval */
#define DECLARED_MliaRADBLED2Req	MliaRADBLED2Req
extern uint8_t MliaRADBLED2Req;

/* 0..1 Right_ADB LED#3 Control Signal intval=realval */
#define DECLARED_MliaRADBLED3Req	MliaRADBLED3Req
extern uint8_t MliaRADBLED3Req;

/* 0..1 Right_ADB LED#4 Control Signal intval=realval */
#define DECLARED_MliaRADBLED4Req	MliaRADBLED4Req
extern uint8_t MliaRADBLED4Req;

/* 0..1 Right_ADB LED#5 Control Signal intval=realval */
#define DECLARED_MliaRADBLED5Req	MliaRADBLED5Req
extern uint8_t MliaRADBLED5Req;

/* 0..1 Right_ADB LED#6 Control Signal intval=realval */
#define DECLARED_MliaRADBLED6Req	MliaRADBLED6Req
extern uint8_t MliaRADBLED6Req;

/* 0..1 Right_ADB LED#7 Control Signal intval=realval */
#define DECLARED_MliaRADBLED7Req	MliaRADBLED7Req
extern uint8_t MliaRADBLED7Req;

/* 0..1 Right_ADB LED#8 Control Signal intval=realval */
#define DECLARED_MliaRADBLED8Req	MliaRADBLED8Req
extern uint8_t MliaRADBLED8Req;

/* 0..1 Right_ADB LED#9 Control Signal intval=realval */
#define DECLARED_MliaRADBLED9Req	MliaRADBLED9Req
extern uint8_t MliaRADBLED9Req;

/* 0..321 Object_10 Horizontal Value_1 intval=realval */
#define DECLARED_MliaRightObj10Y1Val	MliaRightObj10Y1Val
extern float MliaRightObj10Y1Val;

/* 0..321 Object_10 Horizontal Value_2 intval=realval */
#define DECLARED_MliaRightObj10Y2Val	MliaRightObj10Y2Val
extern float MliaRightObj10Y2Val;

/* 0..81 Object_10 Vertical Value_1 intval=realval */
#define DECLARED_MliaRightObj10Z1Val	MliaRightObj10Z1Val
extern uint8_t MliaRightObj10Z1Val;

/* 0..81 Object_10 Vertical  Value_2 intval=realval */
#define DECLARED_MliaRightObj10Z2Val	MliaRightObj10Z2Val
extern uint8_t MliaRightObj10Z2Val;

/* 0..511 Object_1 Horizontal Value_1 intval=realval */
#define DECLARED_MliaRightObj1Y1Val	MliaRightObj1Y1Val
extern float MliaRightObj1Y1Val;

/* 0..321 Object_1 Horizontal Value_2 intval=realval */
#define DECLARED_MliaRightObj1Y2Val	MliaRightObj1Y2Val
extern float MliaRightObj1Y2Val;

/* 0..81 Object_1 Vertical Value_1 intval=realval */
#define DECLARED_MliaRightObj1Z1Val	MliaRightObj1Z1Val
extern uint8_t MliaRightObj1Z1Val;

/* 0..81 Object_1 Vertical  Value_2 intval=realval */
#define DECLARED_MliaRightObj1Z2Val	MliaRightObj1Z2Val
extern uint8_t MliaRightObj1Z2Val;

/* 0..321 Object_2 Horizontal Value_1 intval=realval */
#define DECLARED_MliaRightObj2Y1Val	MliaRightObj2Y1Val
extern float MliaRightObj2Y1Val;

/* 0..321 Object_2 Horizontal Value_2 intval=realval */
#define DECLARED_MliaRightObj2Y2Val	MliaRightObj2Y2Val
extern float MliaRightObj2Y2Val;

/* 0..81 Object_2 Vertical Value_1 intval=realval */
#define DECLARED_MliaRightObj2Z1Val	MliaRightObj2Z1Val
extern uint8_t MliaRightObj2Z1Val;

/* 0..81 Object_2 Vertical  Value_2 intval=realval */
#define DECLARED_MliaRightObj2Z2Val	MliaRightObj2Z2Val
extern uint8_t MliaRightObj2Z2Val;

/* 0..321 Object_3 Horizontal Value_1 intval=realval */
#define DECLARED_MliaRightObj3Y1Val	MliaRightObj3Y1Val
extern float MliaRightObj3Y1Val;

/* 0..321 Object_3 Horizontal Value_2 intval=realval */
#define DECLARED_MliaRightObj3Y2Val	MliaRightObj3Y2Val
extern float MliaRightObj3Y2Val;

/* 0..81 Object_3 Vertical Value_1 intval=realval */
#define DECLARED_MliaRightObj3Z1Val	MliaRightObj3Z1Val
extern uint8_t MliaRightObj3Z1Val;

/* 0..81 Object_3 Vertical  Value_2 intval=realval */
#define DECLARED_MliaRightObj3Z2Val	MliaRightObj3Z2Val
extern uint8_t MliaRightObj3Z2Val;

/* 0..321 Object_4 Horizontal Value_1 intval=realval */
#define DECLARED_MliaRightObj4Y1Val	MliaRightObj4Y1Val
extern float MliaRightObj4Y1Val;

/* 0..321 Object_4 Horizontal Value_2 intval=realval */
#define DECLARED_MliaRightObj4Y2Val	MliaRightObj4Y2Val
extern float MliaRightObj4Y2Val;

/* 0..81 Object_4 Vertical Value_1 intval=realval */
#define DECLARED_MliaRightObj4Z1Val	MliaRightObj4Z1Val
extern uint8_t MliaRightObj4Z1Val;

/* 0..81 Object_4 Vertical  Value_2 intval=realval */
#define DECLARED_MliaRightObj4Z2Val	MliaRightObj4Z2Val
extern uint8_t MliaRightObj4Z2Val;

/* 0..321 Object_5 Horizontal Value_1 intval=realval */
#define DECLARED_MliaRightObj5Y1Val	MliaRightObj5Y1Val
extern float MliaRightObj5Y1Val;

/* 0..321 Object_5 Horizontal Value_2 intval=realval */
#define DECLARED_MliaRightObj5Y2Val	MliaRightObj5Y2Val
extern float MliaRightObj5Y2Val;

/* 0..81 Object_5 Vertical Value_1 intval=realval */
#define DECLARED_MliaRightObj5Z1Val	MliaRightObj5Z1Val
extern uint8_t MliaRightObj5Z1Val;

/* 0..81 Object_5 Vertical  Value_2 intval=realval */
#define DECLARED_MliaRightObj5Z2Val	MliaRightObj5Z2Val
extern uint8_t MliaRightObj5Z2Val;

/* 0..321 Object_6 Horizontal Value_1 intval=realval */
#define DECLARED_MliaRightObj6Y1Val	MliaRightObj6Y1Val
extern float MliaRightObj6Y1Val;

/* 0..321 Object_6 Horizontal Value_2 intval=realval */
#define DECLARED_MliaRightObj6Y2Val	MliaRightObj6Y2Val
extern float MliaRightObj6Y2Val;

/* 0..81 Object_6 Vertical Value_1 intval=realval */
#define DECLARED_MliaRightObj6Z1Val	MliaRightObj6Z1Val
extern uint8_t MliaRightObj6Z1Val;

/* 0..81 Object_6 Vertical  Value_2 intval=realval */
#define DECLARED_MliaRightObj6Z2Val	MliaRightObj6Z2Val
extern uint8_t MliaRightObj6Z2Val;

/* 0..321 Object_7 Horizontal Value_1 intval=realval */
#define DECLARED_MliaRightObj7Y1Val	MliaRightObj7Y1Val
extern float MliaRightObj7Y1Val;

/* 0..321 Object_7 Horizontal Value_2 intval=realval */
#define DECLARED_MliaRightObj7Y2Val	MliaRightObj7Y2Val
extern float MliaRightObj7Y2Val;

/* 0..81 Object_7 Vertical Value_1 intval=realval */
#define DECLARED_MliaRightObj7Z1Val	MliaRightObj7Z1Val
extern uint8_t MliaRightObj7Z1Val;

/* 0..81 Object_7 Vertical  Value_2 intval=realval */
#define DECLARED_MliaRightObj7Z2Val	MliaRightObj7Z2Val
extern uint8_t MliaRightObj7Z2Val;

/* 0..321 Object_8 Horizontal Value_1 intval=realval */
#define DECLARED_MliaRightObj8Y1Val	MliaRightObj8Y1Val
extern float MliaRightObj8Y1Val;

/* 0..321 Object_8 Horizontal Value_2 intval=realval */
#define DECLARED_MliaRightObj8Y2Val	MliaRightObj8Y2Val
extern float MliaRightObj8Y2Val;

/* 0..81 Object_8 Vertical Value_1 intval=realval */
#define DECLARED_MliaRightObj8Z1Val	MliaRightObj8Z1Val
extern uint8_t MliaRightObj8Z1Val;

/* 0..81 Object_8 Vertical  Value_2 intval=realval */
#define DECLARED_MliaRightObj8Z2Val	MliaRightObj8Z2Val
extern uint8_t MliaRightObj8Z2Val;

/* 0..321 Object_9 Horizontal Value_1 intval=realval */
#define DECLARED_MliaRightObj9Y1Val	MliaRightObj9Y1Val
extern float MliaRightObj9Y1Val;

/* 0..321 Object_9 Horizontal Value_2 intval=realval */
#define DECLARED_MliaRightObj9Y2Val	MliaRightObj9Y2Val
extern float MliaRightObj9Y2Val;

/* 0..81 Object_9 Vertical Value_1 intval=realval */
#define DECLARED_MliaRightObj9Z1Val	MliaRightObj9Z1Val
extern uint8_t MliaRightObj9Z1Val;

/* 0..81 Object_9 Vertical  Value_2 intval=realval */
#define DECLARED_MliaRightObj9Z2Val	MliaRightObj9Z2Val
extern uint8_t MliaRightObj9Z2Val;

/* 0..7 Slot_1 Projection Brightness Control Signal intval=realval */
#define DECLARED_MliaRightProjBrightSlot1Req	MliaRightProjBrightSlot1Req
extern uint8_t MliaRightProjBrightSlot1Req;

/* 0..7 Slot_2 Projection Brightness Control Signal intval=realval */
#define DECLARED_MliaRightProjBrightSlot2Req	MliaRightProjBrightSlot2Req
extern uint8_t MliaRightProjBrightSlot2Req;

/* 0..7 Slot_3 Projection Brightness Control Signal intval=realval */
#define DECLARED_MliaRightProjBrightSlot3Req	MliaRightProjBrightSlot3Req
extern uint8_t MliaRightProjBrightSlot3Req;

/* 0..7 Slot_4 Projection Brightness Control Signal intval=realval */
#define DECLARED_MliaRightProjBrightSlot4Req	MliaRightProjBrightSlot4Req
extern uint8_t MliaRightProjBrightSlot4Req;

/* 0..65 Slot_1 Projection Control Signal intval=realval */
#define DECLARED_MliaRightProjSlot1Req	MliaRightProjSlot1Req
extern uint8_t MliaRightProjSlot1Req;

/* 0..15 Slot_2 Projection Control Signal intval=realval */
#define DECLARED_MliaRightProjSlot2Req	MliaRightProjSlot2Req
extern uint8_t MliaRightProjSlot2Req;

/* 0..7 Slot_3 Projection Control Signal intval=realval */
#define DECLARED_MliaRightProjSlot3Req	MliaRightProjSlot3Req
extern uint8_t MliaRightProjSlot3Req;

/* 0..7 Slot_4 Projection Control Signal intval=realval */
#define DECLARED_MliaRightProjSlot4Req	MliaRightProjSlot4Req
extern uint8_t MliaRightProjSlot4Req;

/* 0..1 The presence of artificial lighting intval=realval */
#define DECLARED_MliaStreetLightStat	MliaStreetLightStat
extern uint8_t MliaStreetLightStat;

/* 0..1 Error of NV  0- no Error 1- Error intval=realval */
#define DECLARED_NvFuncError	NvFuncError
extern uint8_t NvFuncError;

/* 0..2 Mode of NightVision  0-not Avail  1- Available 2-Active intval=realval */
#define DECLARED_NvMode	NvMode
extern uint8_t NvMode;

/* 0..2 AA Sensetive 0x0 - Low mode request 0x1 - High mode request intval=realval */
#define DECLARED_OSettAaModeSts	OSettAaModeSts
extern uint8_t OSettAaModeSts;

/* 0..1 Attention assist state change request   0x0 -Off   0x1 - Active intval=realval */
#define DECLARED_OSettAaSts	OSettAaSts
extern uint8_t OSettAaSts;

/* 0..1 Status of AEB: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettAebSts	OSettAebSts
extern uint8_t OSettAebSts;

/* 0..1 Status of AFS: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettAfsSts	OSettAfsSts
extern uint8_t OSettAfsSts;

/* 0..1 Status of ALCC: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettAlccSts	OSettAlccSts
extern uint8_t OSettAlccSts;

/* 0..60 Overtaking speed: 0x0 - 0 kmh   0x1  - 1 kmh  ...0x3C -  60 kmh intval=realval */
#define DECLARED_OSettAslaOverCmd	OSettAslaOverCmd
extern uint8_t OSettAslaOverCmd;

/* 0..1 Status of ASLA: 0x0 -Off   0x1 - On intval=realval */
#define DECLARED_OSettAslaSts	OSettAslaSts
extern uint8_t OSettAslaSts;

/* 0..2 Dynamics of CC: 0x0 - Auto mode  0x1 - Comfort mode  0x2 - Dynamic mode intval=realval */
#define DECLARED_OSettCcModeSts	OSettCcModeSts
extern uint8_t OSettCcModeSts;

/* 0..1 Change of speed in a turn: 0x0 - Off  0x1 - On intval=realval */
#define DECLARED_OSettCcSpdCorrectSts	OSettCcSpdCorrectSts
extern uint8_t OSettCcSpdCorrectSts;

/* 0..3 Type of CC:  0x0 - Off  0x1 - CC   0x2 - ACC   0x3 - LIM intval=realval */
#define DECLARED_OSettCcTypeSts	OSettCcTypeSts
extern uint8_t OSettCcTypeSts;

/* 0..1 Sound on IC when DOW is warningReq: 0x0 - OFF   0x1 - ON intval=realval */
#define DECLARED_OSettDowSoundSts	OSettDowSoundSts
extern uint8_t OSettDowSoundSts;

/* 0..1 Status of DOW: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettDowSts	OSettDowSts
extern uint8_t OSettDowSts;

/* 0..2 Mode of FCW: 0x0 - Early mode 0x1 - Normal mode  0x2 - Late mode intval=realval */
#define DECLARED_OSettFcwModeSts	OSettFcwModeSts
extern uint8_t OSettFcwModeSts;

/* 0..1 Status of FCW: 0x0 - Off  0x1 - On intval=realval */
#define DECLARED_OSettFcwSts	OSettFcwSts
extern uint8_t OSettFcwSts;

/* 0..1 Vibration on steering wheel when FCW is warningReq: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettFcwVibrationSts	OSettFcwVibrationSts
extern uint8_t OSettFcwVibrationSts;

/* 0..2 Mode of LCC: 0x0 - Close mode 0x1 - Normal mode  0x2 - Far mode intval=realval */
#define DECLARED_OSettLccModeSts	OSettLccModeSts
extern uint8_t OSettLccModeSts;

/* 0..1 Sound on IC when LCC is warningReq: 0x0 - OFF   0x1 - ON intval=realval */
#define DECLARED_OSettLccSoundSts	OSettLccSoundSts
extern uint8_t OSettLccSoundSts;

/* 0..1 Status of LCC : 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettLccSts	OSettLccSts
extern uint8_t OSettLccSts;

/* 0..1 Vibration on steering wheel when LCC is warningReq: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettLccVibrationSts	OSettLccVibrationSts
extern uint8_t OSettLccVibrationSts;

/* 0..1 Status of LDP: 0x0 - OFF   0x1 - ON intval=realval */
#define DECLARED_OSettLdpSts	OSettLdpSts
extern uint8_t OSettLdpSts;

/* 0..1 Mode of LDW: 0x0 - before crossing  0x1 - while crossing intval=realval */
#define DECLARED_OSettLdwModeSts	OSettLdwModeSts
extern uint8_t OSettLdwModeSts;

/* 0..1 Sound on IC when LDW is warning: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettLdwSoundSts	OSettLdwSoundSts
extern uint8_t OSettLdwSoundSts;

/* 0..1 Status of LDW: 0x0 - OFF   0x1 - ON intval=realval */
#define DECLARED_OSettLdwSts	OSettLdwSts
extern uint8_t OSettLdwSts;

/* 0..1 Vibration on steering wheel when LDW is warningReq: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettLdwVibrationSts	OSettLdwVibrationSts
extern uint8_t OSettLdwVibrationSts;

/* 0..1 Status of LKA : 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettLkaSts	OSettLkaSts
extern uint8_t OSettLkaSts;

/* 0..1 Status of Navigation: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettNavigSts	OSettNavigSts
extern uint8_t OSettNavigSts;

/* 0..1 Status of Other Objects: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettOtherObjSts	OSettOtherObjSts
extern uint8_t OSettOtherObjSts;

/* 0..1 Status of Projection: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettProjectionOnARoadSts	OSettProjectionOnARoadSts
extern uint8_t OSettProjectionOnARoadSts;

/* 0..1 Status of RCTC: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettRctcSts	OSettRctcSts
extern uint8_t OSettRctcSts;

/* 0..1 Status of Auto Brake: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettRdaAutoBrakeSts	OSettRdaAutoBrakeSts
extern uint8_t OSettRdaAutoBrakeSts;

/* 0..1 Status of RDA: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettRdaSts	OSettRdaSts
extern uint8_t OSettRdaSts;

/* 0..1 Status of REC: 0x0 - OFF   0x1 - ON intval=realval */
#define DECLARED_OSettRecSts	OSettRecSts
extern uint8_t OSettRecSts;

/* 0..1 Status of Road Sign: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettRoadSignSts	OSettRoadSignSts
extern uint8_t OSettRoadSignSts;

/* 0..1 Status of Sensor clean function: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettSensCleanSts	OSettSensCleanSts
extern uint8_t OSettSensCleanSts;

/* 0..1 Status of TSR : 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_OSettTsrSts	OSettTsrSts
extern uint8_t OSettTsrSts;

/* 0..1 RCTC is requesting to implement deceleration: 0- No Req 1-Reques intval=realval */
#define DECLARED_RctcDecelReqFalg	RctcDecelReqFalg
extern uint8_t RctcDecelReqFalg;

/* 0..1 Error symbol of RCTC 0=Inactive 1=Active intval=realval */
#define DECLARED_RctcFuncError	RctcFuncError
extern uint8_t RctcFuncError;

/* 0..1 Mode of Rear cross traffic control   0-Off  1-Active intval=realval */
#define DECLARED_RctcMode	RctcMode
extern uint8_t RctcMode;

/* 0..1 Error notification of RCTC 0=Inactive 1=Active intval=realval */
#define DECLARED_RctcNotifError	RctcNotifError
extern uint8_t RctcNotifError;

/* 0..1 RCTC is requesting warning notification: 0- No Req 1-Request intval=realval */
#define DECLARED_RctcWarnReq	RctcWarnReq
extern uint8_t RctcWarnReq;

/* 0..1 Mode of Rear collision warning 0-Off  1-Active intval=realval */
#define DECLARED_RcwMode	RcwMode
extern uint8_t RcwMode;

/* 0..1 RCW is requesting yellow alarm light: 0- No Req 1-Request intval=realval */
#define DECLARED_RcwWarnReq	RcwWarnReq
extern uint8_t RcwWarnReq;

/* 0..1 RDA is requesting to implement deceleration: 0- No Req 1-Reques intval=realval */
#define DECLARED_RdaDecelReqFalg	RdaDecelReqFalg
extern uint8_t RdaDecelReqFalg;

/* 0..1 Error symbol of RDA 0=Inactive 1=Active intval=realval */
#define DECLARED_RdaFuncError	RdaFuncError
extern uint8_t RdaFuncError;

/* 0..1 Mode of Rear driving assist   0-Off  1-Active intval=realval */
#define DECLARED_RdaMode	RdaMode
extern uint8_t RdaMode;

/* 0..1 Error notification of RDA 0=Inactive 1=Active intval=realval */
#define DECLARED_RdaNotifError	RdaNotifError
extern uint8_t RdaNotifError;

/* 0..1 RDA is requesting warning notification: 0- No Req 1-Request intval=realval */
#define DECLARED_RdaWarnReq	RdaWarnReq
extern uint8_t RdaWarnReq;

/* 0..2 Mode of Videos recorder  0-Off 1-On intval=realval */
#define DECLARED_RecMode	RecMode
extern uint8_t RecMode;

/* 0..3 Rear steering actuator mode request:: 0- No request, 1-Zero position, 2 - Opposite direction, 3 - Same direction intval=realval */
#define DECLARED_RsaAngleDirect	RsaAngleDirect
extern uint8_t RsaAngleDirect;

/* 0..1 All Front sensors unit status  0-Clear  1- Dirty intval=realval */
#define DECLARED_SensAllDirty_Stat	SensAllDirty_Stat
extern uint8_t SensAllDirty_Stat;

/* 0..4 ADAS is requesting to clear sensor: 0- No Req 1-FRCU 2-FCU 3-TICU 4-LIDAR intval=realval */
#define DECLARED_SensClearReq	SensClearReq
extern uint8_t SensClearReq;

/* 0..1 Front radar status  0-Clear  1- Dirty intval=realval */
#define DECLARED_SensFrcuDirty_Stat	SensFrcuDirty_Stat
extern uint8_t SensFrcuDirty_Stat;

/* 0..1 LIDAR sensor status  0-Clear  1- Dirty intval=realval */
#define DECLARED_SensLidarDirty_Stat	SensLidarDirty_Stat
extern uint8_t SensLidarDirty_Stat;

/* 0..3 Rear radar status  0-Clear  1- Dirty left 2-Dirty Right 3 -Dirty both intval=realval */
#define DECLARED_SensMrrxDirty_Stat	SensMrrxDirty_Stat
extern uint8_t SensMrrxDirty_Stat;

/* 0..63 Vibration level 0-low… 63 - max intval=realval */
#define DECLARED_SensSteerWhLvl	SensSteerWhLvl
extern uint8_t SensSteerWhLvl;

/* 0..1 ADAS is requesting vibration on steering wheel: 0- No Req 1-Request intval=realval */
#define DECLARED_SensSteerWhVibrReq	SensSteerWhVibrReq
extern uint8_t SensSteerWhVibrReq;

/* 0..1 Termal Image sensor status  0-Clear  1- Dirty intval=realval */
#define DECLARED_SensTicuDirty_Stat	SensTicuDirty_Stat
extern uint8_t SensTicuDirty_Stat;

/* 0..3 ADAS is requesting heat on wind sheeld: 0- No Req 1-Low Req 2-Med Req 3-Max Req intval=realval */
#define DECLARED_SensWSHeatReq	SensWSHeatReq
extern uint8_t SensWSHeatReq;

/* 0..20 Sign _Type: 0-no sign 1-No overtaking, 2-End of overtake prohibition, 3-speed limit, 4-end of speed limit, 5-No entry, 6-End of prohibitions, 7-Pedesrtian crossing, 8-Bumpy road, 9-Main road, 10-Give way, 11-Crosswalk, 12-Stop intval=realval */
#define DECLARED_TsrHudMultiSign	TsrHudMultiSign
extern uint8_t TsrHudMultiSign;

/* 0..1 Multiplexor TSR is requesting FOR HUD intval=realval */
#define DECLARED_TsrHudMultSignAddres	TsrHudMultSignAddres
extern uint8_t TsrHudMultSignAddres;

/* 0..1 Mode of trafic sign recognition 0-Off 1-Active intval=realval */
#define DECLARED_TsrMode	TsrMode
extern uint8_t TsrMode;

/* 0..1 Error of TSR  0=no Error 1=Error (req sing on IC) intval=realval */
#define DECLARED_TsrSignError	TsrSignError
extern uint8_t TsrSignError;

/* 0..1 Error notification of TSR 0=Inactive 1=Active intval=realval */
#define DECLARED_TsrSignNotifError	TsrSignNotifError
extern uint8_t TsrSignNotifError;

/* 0..11 Overtaking sign _Type  0 - Nothing 1 - OverTaking  2 - Overtaking cancellation 3 - Cancel all 4 - CrossWalkFar 5 - SpeedBumpFar 6 - Stop 7 - NoEntry 8 - CrosswalkNear 9 - SpeedBumpNear 10 - MainRoad 11 - SecondRoad intval=realval */
#define DECLARED_TsrSignOverTaking	TsrSignOverTaking
extern uint8_t TsrSignOverTaking;

/* 0..20 Speed sign _Type: 0-no sign; 1-5kmh; 2-10kmh; 3-20kmh … 16-150kmh; 17-CancelSpdLim; 18-reserved; 19-reserved; 20-reserved intval=realval */
#define DECLARED_TsrSignSpeed	TsrSignSpeed
extern uint8_t TsrSignSpeed;

/* 0..1 Request from ADAS. If the signal = 1 MAS should turn on the parking sensors and display the message MAS_FrontUSS in the CAN intval=realval */
#define DECLARED_USSFrontReq	USSFrontReq
extern uint8_t USSFrontReq;

/* 0..1 Request from ADAS. If the signal = 1 MAS should turn on the parking sensors and display the message MAS_RearUSS in the CAN intval=realval */
#define DECLARED_USSRearReq	USSRearReq
extern uint8_t USSRearReq;

/* 0..1 Request from ADAS. If the signal = 1 MAS should turn on the parking sensors and display the message MAS_SideUSS in the CAN intval=realval */
#define DECLARED_USSSideReq	USSSideReq
extern uint8_t USSSideReq;

/* 0..3 ACC target distance intval=realval */
#define DECLARED_VisAccSetDist	VisAccSetDist
extern uint8_t VisAccSetDist;

/* 0..20 ACC target lock to obj with dynam ID: 0 - no object, 1, 2, ... 20 intval=realval */
#define DECLARED_VisAccTargetObj	VisAccTargetObj
extern uint8_t VisAccTargetObj;

/* 0..20 AEB target lock to obj with dynam ID: 0 - no object, 1, 2, ... 20 intval=realval */
#define DECLARED_VisAebTargetObj	VisAebTargetObj
extern uint8_t VisAebTargetObj;

/* 0..4 Ego car trajectory in center lane. 0 - Left edge zone, 1 - Left offset zone, 2 - Center zone, 3 - Right offset zone, 4 - Right edge zone intval=realval */
#define DECLARED_VisEgoZone	VisEgoZone
extern uint8_t VisEgoZone;

/* 0..20 FCW target lock to obj with dynam ID: 0 - no object, 1, 2, ... 20 intval=realval */
#define DECLARED_VisFcwTargetObj	VisFcwTargetObj
extern uint8_t VisFcwTargetObj;

/* 0..1 Left edge lane status 0 - lane does not exist, 1 - lane exists intval=realval */
#define DECLARED_VisLaneLLType	VisLaneLLType
extern uint8_t VisLaneLLType;

/* 0..4 0 - line not found  1 - solid 2- broken  3- Virtual   4 - Edge of the road intval=realval */
#define DECLARED_VisLaneLType	VisLaneLType
extern uint8_t VisLaneLType;

/* 0..1 Right edge lane status 0 - lane does not exist, 1 - lane exists intval=realval */
#define DECLARED_VisLaneRRType	VisLaneRRType
extern uint8_t VisLaneRRType;

/* 0..4 0 - line not found  1 - solid 2- broken  3- Virtual  4 - Edge of the road intval=realval */
#define DECLARED_VisLaneRType	VisLaneRType
extern uint8_t VisLaneRType;

/* 0..1 LCC warning notification for left lane. 0- No Req 1-Request intval=realval */
#define DECLARED_VisLccLeftLane	VisLccLeftLane
extern uint8_t VisLccLeftLane;

/* 0..1 LCC warning notification for right lane. 0- No Req 1-Request intval=realval */
#define DECLARED_VisLccRightLane	VisLccRightLane
extern uint8_t VisLccRightLane;

/* 0..1 LDP warning for left line. 0 - No req 1 - Request intval=realval */
#define DECLARED_VisLdpLeftLine	VisLdpLeftLine
extern uint8_t VisLdpLeftLine;

/* 0..1 LDP warning for right line. 0 - No req 1 - Request intval=realval */
#define DECLARED_VisLdpRightLine	VisLdpRightLine
extern uint8_t VisLdpRightLine;

/* 0..1 LDW warning notification for left line. 0- No Req 1-Request intval=realval */
#define DECLARED_VisLdwLeftLine	VisLdwLeftLine
extern uint8_t VisLdwLeftLine;

/* 0..1 LDW warning notification for right line. 0- No Req 1-Request intval=realval */
#define DECLARED_VisLdwRightLine	VisLdwRightLine
extern uint8_t VisLdwRightLine;

/* 0..1 LKA mode status. 0 - Inactive, 1 - Active intval=realval */
#define DECLARED_VisLkaAct	VisLkaAct
extern uint8_t VisLkaAct;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
#define DECLARED_VisObj1_Type	VisObj1_Type
extern uint8_t VisObj1_Type;

/* 0..100 [m] Longitudinal distance to object №1, m intval=realval */
#define DECLARED_VisObj1DistLong	VisObj1DistLong
extern float VisObj1DistLong;

/* 0..3 Orientation of object №1. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
#define DECLARED_VisObj1Orient	VisObj1Orient
extern uint8_t VisObj1Orient;

/* 0..9 Number zone for object №1. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
#define DECLARED_VisObj1Zone	VisObj1Zone
extern uint8_t VisObj1Zone;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
#define DECLARED_VisObj2_Type	VisObj2_Type
extern uint8_t VisObj2_Type;

/* 0..100 [m] Longitudinal distance to object №2, m intval=realval */
#define DECLARED_VisObj2DistLong	VisObj2DistLong
extern float VisObj2DistLong;

/* 0..3 Orientation of object №2. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
#define DECLARED_VisObj2Orient	VisObj2Orient
extern uint8_t VisObj2Orient;

/* 0..9 Number zone for object №2. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
#define DECLARED_VisObj2Zone	VisObj2Zone
extern uint8_t VisObj2Zone;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
#define DECLARED_VisObj3_Type	VisObj3_Type
extern uint8_t VisObj3_Type;

/* 0..100 [m] Longitudinal distance to object №3, m intval=realval */
#define DECLARED_VisObj3DistLong	VisObj3DistLong
extern float VisObj3DistLong;

/* 0..3 Orientation of object №3. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
#define DECLARED_VisObj3Orient	VisObj3Orient
extern uint8_t VisObj3Orient;

/* 0..9 Number zone for object №3. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
#define DECLARED_VisObj3Zone	VisObj3Zone
extern uint8_t VisObj3Zone;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
#define DECLARED_VisObj4_Type	VisObj4_Type
extern uint8_t VisObj4_Type;

/* 0..100 [m] Longitudinal distance to object №4, m intval=realval */
#define DECLARED_VisObj4DistLong	VisObj4DistLong
extern float VisObj4DistLong;

/* 0..3 Orientation of object №4. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
#define DECLARED_VisObj4Orient	VisObj4Orient
extern uint8_t VisObj4Orient;

/* 0..9 Number zone for object №4. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
#define DECLARED_VisObj4Zone	VisObj4Zone
extern uint8_t VisObj4Zone;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
#define DECLARED_VisObj5_Type	VisObj5_Type
extern uint8_t VisObj5_Type;

/* 0..100 [m] Longitudinal distance to object №5, m intval=realval */
#define DECLARED_VisObj5DistLong	VisObj5DistLong
extern float VisObj5DistLong;

/* 0..3 Orientation of object №5. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
#define DECLARED_VisObj5Orient	VisObj5Orient
extern uint8_t VisObj5Orient;

/* 0..9 Number zone for object №5. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
#define DECLARED_VisObj5Zone	VisObj5Zone
extern uint8_t VisObj5Zone;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
#define DECLARED_VisObj6_Type	VisObj6_Type
extern uint8_t VisObj6_Type;

/* 0..100 [m] Longitudinal distance to object №6, m intval=realval */
#define DECLARED_VisObj6DistLong	VisObj6DistLong
extern float VisObj6DistLong;

/* 0..3 Orientation of object №6. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
#define DECLARED_VisObj6Orient	VisObj6Orient
extern uint8_t VisObj6Orient;

/* 0..9 Number zone for object №6. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
#define DECLARED_VisObj6Zone	VisObj6Zone
extern uint8_t VisObj6Zone;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
#define DECLARED_VisObj7_Type	VisObj7_Type
extern uint8_t VisObj7_Type;

/* 0..100 [m] Longitudinal distance to object №7, m intval=realval */
#define DECLARED_VisObj7DistLong	VisObj7DistLong
extern float VisObj7DistLong;

/* 0..3 Orientation of object №7. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
#define DECLARED_VisObj7Orient	VisObj7Orient
extern uint8_t VisObj7Orient;

/* 0..9 Number zone for object №7. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
#define DECLARED_VisObj7Zone	VisObj7Zone
extern uint8_t VisObj7Zone;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
#define DECLARED_VisObj8_Type	VisObj8_Type
extern uint8_t VisObj8_Type;

/* 0..100 [m] Longitudinal distance to object №8, m intval=realval */
#define DECLARED_VisObj8DistLong	VisObj8DistLong
extern float VisObj8DistLong;

/* 0..3 Orientation of object №8. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
#define DECLARED_VisObj8Orient	VisObj8Orient
extern uint8_t VisObj8Orient;

/* 0..9 Number zone for object №8. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
#define DECLARED_VisObj8Zone	VisObj8Zone
extern uint8_t VisObj8Zone;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
#define DECLARED_VisObj9_Type	VisObj9_Type
extern uint8_t VisObj9_Type;

/* 0..100 [m] Longitudinal distance to object №9, m intval=realval */
#define DECLARED_VisObj9DistLong	VisObj9DistLong
extern float VisObj9DistLong;

/* 0..3 Orientation of object №9. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
#define DECLARED_VisObj9Orient	VisObj9Orient
extern uint8_t VisObj9Orient;

/* 0..9 Number zone for object №9. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
#define DECLARED_VisObj9Zone	VisObj9Zone
extern uint8_t VisObj9Zone;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
#define DECLARED_VisObjDynam1ID	VisObjDynam1ID
extern uint8_t VisObjDynam1ID;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
#define DECLARED_VisObjDynam2ID	VisObjDynam2ID
extern uint8_t VisObjDynam2ID;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
#define DECLARED_VisObjDynam3ID	VisObjDynam3ID
extern uint8_t VisObjDynam3ID;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
#define DECLARED_VisObjDynam4ID	VisObjDynam4ID
extern uint8_t VisObjDynam4ID;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
#define DECLARED_VisObjDynam5ID	VisObjDynam5ID
extern uint8_t VisObjDynam5ID;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
#define DECLARED_VisObjDynam6ID	VisObjDynam6ID
extern uint8_t VisObjDynam6ID;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
#define DECLARED_VisObjDynam7ID	VisObjDynam7ID
extern uint8_t VisObjDynam7ID;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
#define DECLARED_VisObjDynam8ID	VisObjDynam8ID
extern uint8_t VisObjDynam8ID;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
#define DECLARED_VisObjDynam9ID	VisObjDynam9ID
extern uint8_t VisObjDynam9ID;

/* 0..4 0-straight road, 1-smooth left turn, 2-sharp left turn, 3-smooth right turn, 4-sharp right turn intval=realval */
#define DECLARED_VisRoadAngleLvl	VisRoadAngleLvl
extern uint8_t VisRoadAngleLvl;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

