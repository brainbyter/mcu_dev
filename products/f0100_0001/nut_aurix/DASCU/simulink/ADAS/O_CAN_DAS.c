/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* 0..2 Mode of trafic AA 0-Off 1-StandBy 2-Active intval=realval */
uint8_t AaMode = 0U;

/* 0..1 Notification to wake up intval=realval */
uint8_t AaWarnNotifReq = 0U;

/* 0..2 ADAS Status 0 - NotAvailable 1 - Degradate 2 - Available intval=realval */
uint8_t AdasAvailMode = 2U;

/* 0..1 AEB is requesting brake boost: 0- No Req 1-Request intval=realval */
uint8_t AebBoostReq = 0U;

/* 0..1 Notification for IC: Emergency braking is deactivated: 0=Off 1=Active intval=realval */
uint8_t AebDeactivNotif = 0U;

/* -20..20 Implement deceleration, ms^2 intval=realval */
float AebDecelReq = 0.0000000E+000;

/* 0..1 AEB is requesting to implement deceleration: 0- No Req 1-Request intval=realval */
uint8_t AebDecelReqFlag = 0U;

/* 0..1 Error symbol of AEB 0=Inactive 1=Active intval=realval */
uint8_t AebFuncError = 0U;

/* 0..1 Mode of emergency braking intval=realval */
uint8_t AebMode = 0U;

/* 0..1 Error notification of AEB 0=Inactive 1=Active intval=realval */
uint8_t AebNotifError = 0U;

/* 0..1 AEB is inform a potential accident 0-nothing 1-Request intval=realval */
uint8_t AebPreCrash = 0U;

/* 0..1 AEB is requesting brake prefill: 0- No Req 1-Request intval=realval */
uint8_t AebPrefillReq = 0U;

/* 0..1 AEB or RDA is requestin enable HOLD intval=realval */
uint8_t AebRdaStandReq = 0U;

/* 0..1 The function works, but does not see objects due to rain/sunlight. intval=realval */
uint8_t AebUnAvaliable = 0U;

/* 0..1 Enable the brake jerk warning functionnality 0 = Disable 1 = Enable intval=realval */
uint8_t AfsBrakeJerkEn = 0U;

/* 0..255 Indicates strength of Brake Jerk warning level requested by AFS intval=realval */
uint8_t AfsBrakeJerkLevel = 0U;

/* 0..1 AFS requests a brake jerk to warn the driver in a hazardous situation intval=realval */
uint8_t AfsBrakeJerkReq = 0U;

/* 0..1 AFS is requesting to implement deceleration: 0- No Req 1-Request intval=realval */
uint8_t AfsDecelReqFlag = 0U;

/* 0..1 AFS is requesting open door and emergency lights: 0- No Req 1-Request intval=realval */
uint8_t AfsDoorUnlookReq = 0U;

/* 0..1 Error of AFS  0=no Error 1= Error intval=realval */
uint8_t AfsFuncError = 0U;

/* 0..1 Mode of AFS 0-Off  1-Active intval=realval */
uint8_t AfsMode = 0U;

/* 0..1 Error notification of AFS 0=Inactive 1=Active intval=realval */
uint8_t AfsNotifError = 0U;

/* 0..1 AFS is requesting call SOS: 0- No Req 1-Request intval=realval */
uint8_t AfsSosReq = 0U;

/* 0..1 ALCC is requesting to implement angle on steering wheel: 0- No Req 1-Request intval=realval */
uint8_t AlccAngleReqFlag = 0U;

/* 0..1 Mode of Active Lane Change Control  0-Off 1-Active intval=realval */
uint8_t ALccMode = 0U;

/* 0..1 Error notification of ALCC 0=Inactive 1=Active intval=realval */
uint8_t ALccNotifError = 0U;

/* 0..254 Request to IC  to show notification, kmh 0-no req 1 - 1 kmh… intval=realval */
uint8_t AslaChSpdReq = 0U;

/* 0..1 Mode of Active speed limit assist 0= OFF 1=Active intval=realval */
uint8_t AslaMode = 0U;

/* -20..20 Implement deceleration, ms^2 intval=realval */
float CcAfsDecelReq = 0.0000000E+000;

/* 0..1 CC is requesting the brake light to be turned on: 0-Turn OFF 1-Turn ON intval=realval */
uint8_t CcBrakeLightReq = 0U;

/* 0..1 Cruise is requesting to start the car: 0- No Req 1-Request intval=realval */
uint8_t CcBrakeReleaseReq = 0U;

/* 0..1 Cruise is requesting a car hold: 0- No Req 1-Request intval=realval */
uint8_t CcBrakeStandStReq = 0U;

/* 0..1 Cruise is requesting to implement deceleration: 0- No Req 1-Request intval=realval */
uint8_t CcDecelReqFlag = 0U;

/* 0..3 _Type of CC: 0=Nothing 1=CC/ACC  2=LIM  3-MAS intval=realval */
uint8_t CcEmsEngagement_Stat = 0U;

/* -200..1000 Target total torque on engine intval=realval */
float CcEmsMotInc = 0.0000000E+000;

/* 0..1 Engine torque increase request flag intval=realval */
uint8_t CcEmsMotIncFlag = 0U;

/* 0..1 Mode of CC 0=Off 1=Active intval=realval */
uint8_t CcEmsState_Stat = 0U;

/* 0..1 Error symbol of CC 0=Inactive (No error) 1=Active (Error) intval=realval */
uint8_t CcFuncError = 0U;

/* 0..7 Current set distance to vehicle in front for ACC function 0 - close, 1 - normal, 2 - long away intval=realval */
uint8_t CcHudSetDist = 0U;

/* 0..255 Current set speed in ACC function intval=realval */
uint8_t CcHudSetSpeed = 0U;

/* 0..1 ACC detection status: 0 - not detected, 1 - detected intval=realval */
uint8_t CcHudTargDetect = 0U;

/* 0..3 Mode of CC: 0=Off 1=Standby 2=Active 3=Override intval=realval */
uint8_t CcMode = 0U;

/* 0..1 Error notification of CC 0=Inactive 1=Active intval=realval */
uint8_t CcNotifError = 0U;

/* 0..6 CC is requesting the notification:  0- nothing 1 - Cruise cannot be activated 2 - Cruise cannot be activated. The seat belt is not fastened. 3 - Cruise cannot be activated due to Off Road mode. 4 - Cruise cannot be activated due to insufficient travel speed. 5 - Cruise Function off (With sound). 6 - Lim is not available. intval=realval */
uint8_t CcReject = 0U;

/* 0..3 Target distance 0-min, 1-lowmed, 2-med, 3-max intval=realval */
uint8_t CcSetDist = 0U;

/* 0..255 Targer Speed kmh intval=realval */
uint8_t CcSetSpeed = 0U;

/* 0..1 CC has fallen asleep  0 - No sleep,   1- Sleep intval=realval */
uint8_t CcSleepSt = 0U;

/* 0..1 A flag indicating that the car is detected 0 - No Target Car  1 - target car is intval=realval */
uint8_t CcTargetId = 0U;

/* 0..3 Type cruis control 0=Nothign 1=CC 2=ACC SG 3=LIM intval=realval */
uint8_t CcType = 0U;

/* 0..3 _Type of CC: 0=Nothing 1=CC/ACC  2=LIM  3-MAS intval=realval */
uint8_t CcVcuEngagement_Stat = 0U;

/* 0..1000 Target total torque on engine intval=realval */
float CcVcuMotInc = 0.0000000E+000;

/* 0..1 Engine torque increase request flag intval=realval */
uint8_t CcVcuMotIncFlag = 0U;

/* 0..3 Mode of CC 0=Off 1=Standby 2=Active 3=Override intval=realval */
uint8_t CcVcuState_Stat = 0U;

/* 0..1 Mode of Door Open Warning  0-Off 1-Active intval=realval */
uint8_t DowMode = 0U;

/* 0..1 Error notification of DOW 0=Inactive 1=Active intval=realval */
uint8_t DowNotifError = 0U;

/* 0..1 Notification for IC: Front collision warning is activated: 0=Off 1=Active intval=realval */
uint8_t FcwActivNotif = 0U;

/* 0..1 Mode of front colision warning intval=realval */
uint8_t FcwMode = 0U;

/* 0..1 Error notification of FCW 0=Inactive 1=Active intval=realval */
uint8_t FcwNotifError = 0U;

/* 0..1 FCW is requesting warning sound 0-nothing 1-Request intval=realval */
uint8_t FcwSoundWarnReq = 0U;

/* 0..1 Error symbol of LCC 0=Inactive 1=Active intval=realval */
uint8_t LccFuncError = 0U;

/* 0..1 LCC is requesting activate left LED: 0- No Req 1-light intval=realval */
uint8_t LccLeftLedReq = 0U;

/* 0..1 LCC is requesting activate notification left side : 0- No Req 1-Request intval=realval */
uint8_t LccLeftWarnReq = 0U;

/* 0..2 Mode of Lane Change Control 0-Off  1- StandBy 2-Active intval=realval */
uint8_t LccMode = 0U;

/* 0..1 Error notification of LCC 0=Inactive 1=Active intval=realval */
uint8_t LccNotifError = 0U;

/* 0..1 LCC is requesting activate right LED: 0- No Req 1-light intval=realval */
uint8_t LccRightLedReq = 0U;

/* 0..1 LCC is requesting activate notification right side : 0- No Req 1-Request intval=realval */
uint8_t LccRightWarnReq = 0U;

/* 0..1 LCC is requesting sound warning: 0- No Req 1-Request intval=realval */
uint8_t LccSoundReq = 0U;

/* 0..1 LDP is requesting to implement angle on steering wheel: 0- No Req 1-Request intval=realval */
uint8_t LdpAngleReqFlag = 0U;

/* 0..1 LDP is requesting warning notification Left line: 0- No Req 1-Request intval=realval */
uint8_t LdpLeftLaneWarnReq = 0U;

/* 0..1 Mode of Lane Departure Prevention 0-Off  1- Active intval=realval */
uint8_t LdpMode = 0U;

/* 0..1 Error notification of LDP 0=Inactive 1=Active intval=realval */
uint8_t LdpNotifError = 0U;

/* 0..1 LDP is requesting warning notification Right line: 0- No Req 1-Request intval=realval */
uint8_t LdpRightLaneWarnReq = 0U;

/* 0..1 Error symbol of LDW 0=Inactive 1=Active (LDP->LDW) intval=realval */
uint8_t LdwFuncError = 0U;

/* 0..1 LDW activation status 0- inactive 1- active intval=realval */
uint8_t LdwHudActSt = 0U;

/* 0..1 Multiplexor LDW is requesting FOR HUD intval=realval */
uint8_t LdwHudMultiLaneAddres = 0U;

/* 0..1 LDW is requesting FOR HUD warning notification: 0- No Req 1-Request intval=realval */
uint8_t LdwHudMultiLaneWarnReq = 0U;

/* 0..1 LDW is requesting warning notification Left line: 0- No Req 1-Request intval=realval */
uint8_t LdwLeftLaneWarnReq = 0U;

/* 0..4 Mode of Lane Departure Warning 0-Off  1- StandBy 2-Active 3 - ActiveLeft 4 - ActiveRight intval=realval */
uint8_t LdwMode = 0U;

/* 0..1 Error notification of LDW 0=Inactive 1=Active intval=realval */
uint8_t LdwNotifError = 0U;

/* 0..1 LDW is requesting warning notification Right line: 0- No Req 1-Request intval=realval */
uint8_t LdwRightLaneWarnReq = 0U;

/* 0..1 LDW is requesting warning sound: 0- No Req 1-Request intval=realval */
uint8_t LdwSoundReq = 0U;

/* -540..540 [deg] Angle request intval=realval */
float LkaAngleReq = 0.0000000E+000;

/* 0..1 LKA is requesting to implement angle  on steering wheel:: 0- No Req 1-Request intval=realval */
uint8_t LkaAngleReqFlag = 0U;

/* 0..1 Error symbol of LKA 0=Inactive 1=Active intval=realval */
uint8_t LkaFuncError = 0U;

/* 0..3 Mode of LKA 0-Off 1-StandBy 2-Active 3-Active+TakeOver intval=realval */
uint8_t LkaMode = 0U;

/* 0..1 Error notification of LKA 0=Inactive 1=Active (AEB->LKA) intval=realval */
uint8_t LkaNotifError = 0U;

/* 0..1 Sound when function is turned off  0 - no sound  1- sound intval=realval */
uint8_t LkaShotdownSoundReq = 0U;

/* 0..1 Notification to take the steering wheel intval=realval */
uint8_t LkaWarnNotifReq = 0U;

/* 0..1 Warning sound to take the steering wheel intval=realval */
uint8_t LkaWarnSoundReq = 0U;

/* 0..1 Error of MLIA  0-Inactive 1-Active intval=realval */
uint8_t MliaFuncError = 0U;

/* 0..1 Left_ADB LED#10 Control Signal intval=realval */
uint8_t MliaLADBLED10Req = 0U;

/* 0..1 Left_ADB LED#11 Control Signal intval=realval */
uint8_t MliaLADBLED11Req = 0U;

/* 0..1 Left_ADB LED#12 Control Signal intval=realval */
uint8_t MliaLADBLED12Req = 0U;

/* 0..1 Left_ADB LED#13 Control Signal intval=realval */
uint8_t MliaLADBLED13Req = 0U;

/* 0..1 Left_ADB LED#14 Control Signal intval=realval */
uint8_t MliaLADBLED14Req = 0U;

/* 0..1 Left_ADB LED#15 Control Signal intval=realval */
uint8_t MliaLADBLED15Req = 0U;

/* 0..1 Left_ADB LED#16 Control Signal intval=realval */
uint8_t MliaLADBLED16Req = 0U;

/* 0..1 Left_ADB LED#17 Control Signal intval=realval */
uint8_t MliaLADBLED17Req = 0U;

/* 0..1 Left_ADB LED#18 Control Signal intval=realval */
uint8_t MliaLADBLED18Req = 0U;

/* 0..1 Left_ADB LED#1 Control Signal intval=realval */
uint8_t MliaLADBLED1Req = 0U;

/* 0..1 Left_ADB LED#2 Control Signal intval=realval */
uint8_t MliaLADBLED2Req = 0U;

/* 0..1 Left_ADB LED#3 Control Signal intval=realval */
uint8_t MliaLADBLED3Req = 0U;

/* 0..1 Left_ADB LED#4 Control Signal intval=realval */
uint8_t MliaLADBLED4Req = 0U;

/* 0..1 Left_ADB LED#5 Control Signal intval=realval */
uint8_t MliaLADBLED5Req = 0U;

/* 0..1 Left_ADB LED#6 Control Signal intval=realval */
uint8_t MliaLADBLED6Req = 0U;

/* 0..1 Left_ADB LED#7 Control Signal intval=realval */
uint8_t MliaLADBLED7Req = 0U;

/* 0..1 Left_ADB LED#8 Control Signal intval=realval */
uint8_t MliaLADBLED8Req = 0U;

/* 0..1 Left_ADB LED#9 Control Signal intval=realval */
uint8_t MliaLADBLED9Req = 0U;

/* 0..321 Object_10 Horizontal Value_1 intval=realval */
float MliaLeftObj10Y1Val = 0.0000000E+000;

/* 0..321 Object_10 Horizontal Value_2 intval=realval */
float MliaLeftObj10Y2Val = 0.0000000E+000;

/* 0..81 Object_10 Vertical Value_1 intval=realval */
uint8_t MliaLeftObj10Z1Val = 0U;

/* 0..81 Object_10 Vertical  Value_2 intval=realval */
uint8_t MliaLeftObj10Z2Val = 0U;

/* 0..511 Object_1 Horizontal Value_1 intval=realval */
float MliaLeftObj1Y1Val = 0.0000000E+000;

/* 0..321 Object_1 Horizontal Value_2 intval=realval */
float MliaLeftObj1Y2Val = 0.0000000E+000;

/* 0..81 Object_1 Vertical Value_1 intval=realval */
uint8_t MliaLeftObj1Z1Val = 0U;

/* 0..81 Object_1 Vertical  Value_2 intval=realval */
uint8_t MliaLeftObj1Z2Val = 0U;

/* 0..321 Object_2 Horizontal Value_1 intval=realval */
float MliaLeftObj2Y1Val = 0.0000000E+000;

/* 0..321 Object_2 Horizontal Value_2 intval=realval */
float MliaLeftObj2Y2Val = 0.0000000E+000;

/* 0..81 Object_2 Vertical Value_1 intval=realval */
uint8_t MliaLeftObj2Z1Val = 0U;

/* 0..81 Object_2 Vertical  Value_2 intval=realval */
uint8_t MliaLeftObj2Z2Val = 0U;

/* 0..321 Object_3 Horizontal Value_1 intval=realval */
float MliaLeftObj3Y1Val = 0.0000000E+000;

/* 0..321 Object_3 Horizontal Value_2 intval=realval */
float MliaLeftObj3Y2Val = 0.0000000E+000;

/* 0..81 Object_3 Vertical Value_1 intval=realval */
uint8_t MliaLeftObj3Z1Val = 0U;

/* 0..81 Object_3 Vertical  Value_2 intval=realval */
uint8_t MliaLeftObj3Z2Val = 0U;

/* 0..321 Object_4 Horizontal Value_1 intval=realval */
float MliaLeftObj4Y1Val = 0.0000000E+000;

/* 0..321 Object_4 Horizontal Value_2 intval=realval */
float MliaLeftObj4Y2Val = 0.0000000E+000;

/* 0..81 Object_4 Vertical Value_1 intval=realval */
uint8_t MliaLeftObj4Z1Val = 0U;

/* 0..81 Object_4 Vertical  Value_2 intval=realval */
uint8_t MliaLeftObj4Z2Val = 0U;

/* 0..321 Object_5 Horizontal Value_1 intval=realval */
float MliaLeftObj5Y1Val = 0.0000000E+000;

/* 0..321 Object_5 Horizontal Value_2 intval=realval */
float MliaLeftObj5Y2Val = 0.0000000E+000;

/* 0..81 Object_5 Vertical Value_1 intval=realval */
uint8_t MliaLeftObj5Z1Val = 0U;

/* 0..81 Object_5 Vertical  Value_2 intval=realval */
uint8_t MliaLeftObj5Z2Val = 0U;

/* 0..321 Object_6 Horizontal Value_1 intval=realval */
float MliaLeftObj6Y1Val = 0.0000000E+000;

/* 0..321 Object_6 Horizontal Value_2 intval=realval */
float MliaLeftObj6Y2Val = 0.0000000E+000;

/* 0..81 Object_6 Vertical Value_1 intval=realval */
uint8_t MliaLeftObj6Z1Val = 0U;

/* 0..81 Object_6 Vertical  Value_2 intval=realval */
uint8_t MliaLeftObj6Z2Val = 0U;

/* 0..321 Object_7 Horizontal Value_1 intval=realval */
float MliaLeftObj7Y1Val = 0.0000000E+000;

/* 0..321 Object_7 Horizontal Value_2 intval=realval */
float MliaLeftObj7Y2Val = 0.0000000E+000;

/* 0..81 Object_7 Vertical Value_1 intval=realval */
uint8_t MliaLeftObj7Z1Val = 0U;

/* 0..81 Object_7 Vertical  Value_2 intval=realval */
uint8_t MliaLeftObj7Z2Val = 0U;

/* 0..321 Object_8 Horizontal Value_1 intval=realval */
float MliaLeftObj8Y1Val = 0.0000000E+000;

/* 0..321 Object_8 Horizontal Value_2 intval=realval */
float MliaLeftObj8Y2Val = 0.0000000E+000;

/* 0..81 Object_8 Vertical Value_1 intval=realval */
uint8_t MliaLeftObj8Z1Val = 0U;

/* 0..81 Object_8 Vertical  Value_2 intval=realval */
uint8_t MliaLeftObj8Z2Val = 0U;

/* 0..321 Object_9 Horizontal Value_1 intval=realval */
float MliaLeftObj9Y1Val = 0.0000000E+000;

/* 0..321 Object_9 Horizontal Value_2 intval=realval */
float MliaLeftObj9Y2Val = 0.0000000E+000;

/* 0..81 Object_9 Vertical Value_1 intval=realval */
uint8_t MliaLeftObj9Z1Val = 0U;

/* 0..81 Object_9 Vertical  Value_2 intval=realval */
uint8_t MliaLeftObj9Z2Val = 0U;

/* 0..7 Slot_1 Projection Brightness Control Signal intval=realval */
uint8_t MliaLeftProjBrightSlot1Req = 0U;

/* 0..7 Slot_2 Projection Brightness Control Signal intval=realval */
uint8_t MliaLeftProjBrightSlot2Req = 0U;

/* 0..7 Slot_3 Projection Brightness Control Signal intval=realval */
uint8_t MliaLeftProjBrightSlot3Req = 0U;

/* 0..7 Slot_4 Projection Brightness Control Signal intval=realval */
uint8_t MliaLeftProjBrightSlot4Req = 0U;

/* 0..65 Slot_1 Projection Control Signal intval=realval */
uint8_t MliaLeftProjSlot1Req = 0U;

/* 0..15 Slot_2 Projection Control Signal intval=realval */
uint8_t MliaLeftProjSlot2Req = 0U;

/* 0..7 Slot_3 Projection Control Signal intval=realval */
uint8_t MliaLeftProjSlot3Req = 0U;

/* 0..7 Slot_4 Projection Control Signal intval=realval */
uint8_t MliaLeftProjSlot4Req = 0U;

/* 0..3 Mode of Matrix light assistant  0-Off  1 StandBy(V<30) 2-Active 3- Boost intval=realval */
uint8_t MliaMode = 0U;

/* 0..1 Right_ADB LED#10 Control Signal intval=realval */
uint8_t MliaRADBLED10Req = 0U;

/* 0..1 Right_ADB LED#11 Control Signal intval=realval */
uint8_t MliaRADBLED11Req = 0U;

/* 0..1 Right_ADB LED#12 Control Signal intval=realval */
uint8_t MliaRADBLED12Req = 0U;

/* 0..1 Right_ADB LED#13 Control Signal intval=realval */
uint8_t MliaRADBLED13Req = 0U;

/* 0..1 Right_ADB LED#14 Control Signal intval=realval */
uint8_t MliaRADBLED14Req = 0U;

/* 0..1 Right_ADB LED#15 Control Signal intval=realval */
uint8_t MliaRADBLED15Req = 0U;

/* 0..1 Right_ADB LED#16 Control Signal intval=realval */
uint8_t MliaRADBLED16Req = 0U;

/* 0..1 Right_ADB LED#17 Control Signal intval=realval */
uint8_t MliaRADBLED17Req = 0U;

/* 0..1 Right_ADB LED#18 Control Signal intval=realval */
uint8_t MliaRADBLED18Req = 0U;

/* 0..1 Right_ADB LED#1 Control Signal intval=realval */
uint8_t MliaRADBLED1Req = 0U;

/* 0..1 Right_ADB LED#2 Control Signal intval=realval */
uint8_t MliaRADBLED2Req = 0U;

/* 0..1 Right_ADB LED#3 Control Signal intval=realval */
uint8_t MliaRADBLED3Req = 0U;

/* 0..1 Right_ADB LED#4 Control Signal intval=realval */
uint8_t MliaRADBLED4Req = 0U;

/* 0..1 Right_ADB LED#5 Control Signal intval=realval */
uint8_t MliaRADBLED5Req = 0U;

/* 0..1 Right_ADB LED#6 Control Signal intval=realval */
uint8_t MliaRADBLED6Req = 0U;

/* 0..1 Right_ADB LED#7 Control Signal intval=realval */
uint8_t MliaRADBLED7Req = 0U;

/* 0..1 Right_ADB LED#8 Control Signal intval=realval */
uint8_t MliaRADBLED8Req = 0U;

/* 0..1 Right_ADB LED#9 Control Signal intval=realval */
uint8_t MliaRADBLED9Req = 0U;

/* 0..321 Object_10 Horizontal Value_1 intval=realval */
float MliaRightObj10Y1Val = 0.0000000E+000;

/* 0..321 Object_10 Horizontal Value_2 intval=realval */
float MliaRightObj10Y2Val = 0.0000000E+000;

/* 0..81 Object_10 Vertical Value_1 intval=realval */
uint8_t MliaRightObj10Z1Val = 0U;

/* 0..81 Object_10 Vertical  Value_2 intval=realval */
uint8_t MliaRightObj10Z2Val = 0U;

/* 0..511 Object_1 Horizontal Value_1 intval=realval */
float MliaRightObj1Y1Val = 0.0000000E+000;

/* 0..321 Object_1 Horizontal Value_2 intval=realval */
float MliaRightObj1Y2Val = 0.0000000E+000;

/* 0..81 Object_1 Vertical Value_1 intval=realval */
uint8_t MliaRightObj1Z1Val = 0U;

/* 0..81 Object_1 Vertical  Value_2 intval=realval */
uint8_t MliaRightObj1Z2Val = 0U;

/* 0..321 Object_2 Horizontal Value_1 intval=realval */
float MliaRightObj2Y1Val = 0.0000000E+000;

/* 0..321 Object_2 Horizontal Value_2 intval=realval */
float MliaRightObj2Y2Val = 0.0000000E+000;

/* 0..81 Object_2 Vertical Value_1 intval=realval */
uint8_t MliaRightObj2Z1Val = 0U;

/* 0..81 Object_2 Vertical  Value_2 intval=realval */
uint8_t MliaRightObj2Z2Val = 0U;

/* 0..321 Object_3 Horizontal Value_1 intval=realval */
float MliaRightObj3Y1Val = 0.0000000E+000;

/* 0..321 Object_3 Horizontal Value_2 intval=realval */
float MliaRightObj3Y2Val = 0.0000000E+000;

/* 0..81 Object_3 Vertical Value_1 intval=realval */
uint8_t MliaRightObj3Z1Val = 0U;

/* 0..81 Object_3 Vertical  Value_2 intval=realval */
uint8_t MliaRightObj3Z2Val = 0U;

/* 0..321 Object_4 Horizontal Value_1 intval=realval */
float MliaRightObj4Y1Val = 0.0000000E+000;

/* 0..321 Object_4 Horizontal Value_2 intval=realval */
float MliaRightObj4Y2Val = 0.0000000E+000;

/* 0..81 Object_4 Vertical Value_1 intval=realval */
uint8_t MliaRightObj4Z1Val = 0U;

/* 0..81 Object_4 Vertical  Value_2 intval=realval */
uint8_t MliaRightObj4Z2Val = 0U;

/* 0..321 Object_5 Horizontal Value_1 intval=realval */
float MliaRightObj5Y1Val = 0.0000000E+000;

/* 0..321 Object_5 Horizontal Value_2 intval=realval */
float MliaRightObj5Y2Val = 0.0000000E+000;

/* 0..81 Object_5 Vertical Value_1 intval=realval */
uint8_t MliaRightObj5Z1Val = 0U;

/* 0..81 Object_5 Vertical  Value_2 intval=realval */
uint8_t MliaRightObj5Z2Val = 0U;

/* 0..321 Object_6 Horizontal Value_1 intval=realval */
float MliaRightObj6Y1Val = 0.0000000E+000;

/* 0..321 Object_6 Horizontal Value_2 intval=realval */
float MliaRightObj6Y2Val = 0.0000000E+000;

/* 0..81 Object_6 Vertical Value_1 intval=realval */
uint8_t MliaRightObj6Z1Val = 0U;

/* 0..81 Object_6 Vertical  Value_2 intval=realval */
uint8_t MliaRightObj6Z2Val = 0U;

/* 0..321 Object_7 Horizontal Value_1 intval=realval */
float MliaRightObj7Y1Val = 0.0000000E+000;

/* 0..321 Object_7 Horizontal Value_2 intval=realval */
float MliaRightObj7Y2Val = 0.0000000E+000;

/* 0..81 Object_7 Vertical Value_1 intval=realval */
uint8_t MliaRightObj7Z1Val = 0U;

/* 0..81 Object_7 Vertical  Value_2 intval=realval */
uint8_t MliaRightObj7Z2Val = 0U;

/* 0..321 Object_8 Horizontal Value_1 intval=realval */
float MliaRightObj8Y1Val = 0.0000000E+000;

/* 0..321 Object_8 Horizontal Value_2 intval=realval */
float MliaRightObj8Y2Val = 0.0000000E+000;

/* 0..81 Object_8 Vertical Value_1 intval=realval */
uint8_t MliaRightObj8Z1Val = 0U;

/* 0..81 Object_8 Vertical  Value_2 intval=realval */
uint8_t MliaRightObj8Z2Val = 0U;

/* 0..321 Object_9 Horizontal Value_1 intval=realval */
float MliaRightObj9Y1Val = 0.0000000E+000;

/* 0..321 Object_9 Horizontal Value_2 intval=realval */
float MliaRightObj9Y2Val = 0.0000000E+000;

/* 0..81 Object_9 Vertical Value_1 intval=realval */
uint8_t MliaRightObj9Z1Val = 0U;

/* 0..81 Object_9 Vertical  Value_2 intval=realval */
uint8_t MliaRightObj9Z2Val = 0U;

/* 0..7 Slot_1 Projection Brightness Control Signal intval=realval */
uint8_t MliaRightProjBrightSlot1Req = 0U;

/* 0..7 Slot_2 Projection Brightness Control Signal intval=realval */
uint8_t MliaRightProjBrightSlot2Req = 0U;

/* 0..7 Slot_3 Projection Brightness Control Signal intval=realval */
uint8_t MliaRightProjBrightSlot3Req = 0U;

/* 0..7 Slot_4 Projection Brightness Control Signal intval=realval */
uint8_t MliaRightProjBrightSlot4Req = 0U;

/* 0..65 Slot_1 Projection Control Signal intval=realval */
uint8_t MliaRightProjSlot1Req = 0U;

/* 0..15 Slot_2 Projection Control Signal intval=realval */
uint8_t MliaRightProjSlot2Req = 0U;

/* 0..7 Slot_3 Projection Control Signal intval=realval */
uint8_t MliaRightProjSlot3Req = 0U;

/* 0..7 Slot_4 Projection Control Signal intval=realval */
uint8_t MliaRightProjSlot4Req = 0U;

/* 0..1 The presence of artificial lighting intval=realval */
uint8_t MliaStreetLightStat = 0U;

/* 0..1 Error of NV  0- no Error 1- Error intval=realval */
uint8_t NvFuncError = 0U;

/* 0..2 Mode of NightVision  0-not Avail  1- Available 2-Active intval=realval */
uint8_t NvMode = 0U;

/* 0..2 AA Sensetive 0x0 - Low mode request 0x1 - High mode request intval=realval */
uint8_t OSettAaModeSts = 0U;

/* 0..1 Attention assist state change request   0x0 -Off   0x1 - Active intval=realval */
uint8_t OSettAaSts = 0U;

/* 0..1 Status of AEB: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettAebSts = 0U;

/* 0..1 Status of AFS: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettAfsSts = 0U;

/* 0..1 Status of ALCC: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettAlccSts = 0U;

/* 0..60 Overtaking speed: 0x0 - 0 kmh   0x1  - 1 kmh  ...0x3C -  60 kmh intval=realval */
uint8_t OSettAslaOverCmd = 0U;

/* 0..1 Status of ASLA: 0x0 -Off   0x1 - On intval=realval */
uint8_t OSettAslaSts = 0U;

/* 0..2 Dynamics of CC: 0x0 - Auto mode  0x1 - Comfort mode  0x2 - Dynamic mode intval=realval */
uint8_t OSettCcModeSts = 0U;

/* 0..1 Change of speed in a turn: 0x0 - Off  0x1 - On intval=realval */
uint8_t OSettCcSpdCorrectSts = 0U;

/* 0..3 Type of CC:  0x0 - Off  0x1 - CC   0x2 - ACC   0x3 - LIM intval=realval */
uint8_t OSettCcTypeSts = 0U;

/* 0..1 Sound on IC when DOW is warningReq: 0x0 - OFF   0x1 - ON intval=realval */
uint8_t OSettDowSoundSts = 0U;

/* 0..1 Status of DOW: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettDowSts = 0U;

/* 0..2 Mode of FCW: 0x0 - Early mode 0x1 - Normal mode  0x2 - Late mode intval=realval */
uint8_t OSettFcwModeSts = 0U;

/* 0..1 Status of FCW: 0x0 - Off  0x1 - On intval=realval */
uint8_t OSettFcwSts = 0U;

/* 0..1 Vibration on steering wheel when FCW is warningReq: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettFcwVibrationSts = 0U;

/* 0..2 Mode of LCC: 0x0 - Close mode 0x1 - Normal mode  0x2 - Far mode intval=realval */
uint8_t OSettLccModeSts = 0U;

/* 0..1 Sound on IC when LCC is warningReq: 0x0 - OFF   0x1 - ON intval=realval */
uint8_t OSettLccSoundSts = 0U;

/* 0..1 Status of LCC : 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettLccSts = 0U;

/* 0..1 Vibration on steering wheel when LCC is warningReq: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettLccVibrationSts = 0U;

/* 0..1 Status of LDP: 0x0 - OFF   0x1 - ON intval=realval */
uint8_t OSettLdpSts = 0U;

/* 0..1 Mode of LDW: 0x0 - before crossing  0x1 - while crossing intval=realval */
uint8_t OSettLdwModeSts = 0U;

/* 0..1 Sound on IC when LDW is warning: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettLdwSoundSts = 0U;

/* 0..1 Status of LDW: 0x0 - OFF   0x1 - ON intval=realval */
uint8_t OSettLdwSts = 0U;

/* 0..1 Vibration on steering wheel when LDW is warningReq: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettLdwVibrationSts = 0U;

/* 0..1 Status of LKA : 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettLkaSts = 0U;

/* 0..1 Status of Navigation: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettNavigSts = 0U;

/* 0..1 Status of Other Objects: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettOtherObjSts = 0U;

/* 0..1 Status of Projection: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettProjectionOnARoadSts = 0U;

/* 0..1 Status of RCTC: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettRctcSts = 0U;

/* 0..1 Status of Auto Brake: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettRdaAutoBrakeSts = 0U;

/* 0..1 Status of RDA: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettRdaSts = 0U;

/* 0..1 Status of REC: 0x0 - OFF   0x1 - ON intval=realval */
uint8_t OSettRecSts = 0U;

/* 0..1 Status of Road Sign: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettRoadSignSts = 0U;

/* 0..1 Status of Sensor clean function: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettSensCleanSts = 0U;

/* 0..1 Status of TSR : 0x0 - OFF  0x1 - ON intval=realval */
uint8_t OSettTsrSts = 0U;

/* 0..1 RCTC is requesting to implement deceleration: 0- No Req 1-Reques intval=realval */
uint8_t RctcDecelReqFalg = 0U;

/* 0..1 Error symbol of RCTC 0=Inactive 1=Active intval=realval */
uint8_t RctcFuncError = 0U;

/* 0..1 Mode of Rear cross traffic control   0-Off  1-Active intval=realval */
uint8_t RctcMode = 0U;

/* 0..1 Error notification of RCTC 0=Inactive 1=Active intval=realval */
uint8_t RctcNotifError = 0U;

/* 0..1 RCTC is requesting warning notification: 0- No Req 1-Request intval=realval */
uint8_t RctcWarnReq = 0U;

/* 0..1 Mode of Rear collision warning 0-Off  1-Active intval=realval */
uint8_t RcwMode = 0U;

/* 0..1 RCW is requesting yellow alarm light: 0- No Req 1-Request intval=realval */
uint8_t RcwWarnReq = 0U;

/* 0..1 RDA is requesting to implement deceleration: 0- No Req 1-Reques intval=realval */
uint8_t RdaDecelReqFalg = 0U;

/* 0..1 Error symbol of RDA 0=Inactive 1=Active intval=realval */
uint8_t RdaFuncError = 0U;

/* 0..1 Mode of Rear driving assist   0-Off  1-Active intval=realval */
uint8_t RdaMode = 0U;

/* 0..1 Error notification of RDA 0=Inactive 1=Active intval=realval */
uint8_t RdaNotifError = 0U;

/* 0..1 RDA is requesting warning notification: 0- No Req 1-Request intval=realval */
uint8_t RdaWarnReq = 0U;

/* 0..2 Mode of Videos recorder  0-Off 1-On intval=realval */
uint8_t RecMode = 0U;

/* 0..3 Rear steering actuator mode request:: 0- No request, 1-Zero position, 2 - Opposite direction, 3 - Same direction intval=realval */
uint8_t RsaAngleDirect = 0U;

/* 0..1 All Front sensors unit status  0-Clear  1- Dirty intval=realval */
uint8_t SensAllDirty_Stat = 0U;

/* 0..4 ADAS is requesting to clear sensor: 0- No Req 1-FRCU 2-FCU 3-TICU 4-LIDAR intval=realval */
uint8_t SensClearReq = 0U;

/* 0..1 Front radar status  0-Clear  1- Dirty intval=realval */
uint8_t SensFrcuDirty_Stat = 0U;

/* 0..1 LIDAR sensor status  0-Clear  1- Dirty intval=realval */
uint8_t SensLidarDirty_Stat = 0U;

/* 0..3 Rear radar status  0-Clear  1- Dirty left 2-Dirty Right 3 -Dirty both intval=realval */
uint8_t SensMrrxDirty_Stat = 0U;

/* 0..63 Vibration level 0-low… 63 - max intval=realval */
uint8_t SensSteerWhLvl = 0U;

/* 0..1 ADAS is requesting vibration on steering wheel: 0- No Req 1-Request intval=realval */
uint8_t SensSteerWhVibrReq = 0U;

/* 0..1 Termal Image sensor status  0-Clear  1- Dirty intval=realval */
uint8_t SensTicuDirty_Stat = 0U;

/* 0..3 ADAS is requesting heat on wind sheeld: 0- No Req 1-Low Req 2-Med Req 3-Max Req intval=realval */
uint8_t SensWSHeatReq = 0U;

/* 0..20 Sign _Type: 0-no sign 1-No overtaking, 2-End of overtake prohibition, 3-speed limit, 4-end of speed limit, 5-No entry, 6-End of prohibitions, 7-Pedesrtian crossing, 8-Bumpy road, 9-Main road, 10-Give way, 11-Crosswalk, 12-Stop intval=realval */
uint8_t TsrHudMultiSign = 0U;

/* 0..1 Multiplexor TSR is requesting FOR HUD intval=realval */
uint8_t TsrHudMultSignAddres = 0U;

/* 0..1 Mode of trafic sign recognition 0-Off 1-Active intval=realval */
uint8_t TsrMode = 0U;

/* 0..1 Error of TSR  0=no Error 1=Error (req sing on IC) intval=realval */
uint8_t TsrSignError = 0U;

/* 0..1 Error notification of TSR 0=Inactive 1=Active intval=realval */
uint8_t TsrSignNotifError = 0U;

/* 0..11 Overtaking sign _Type  0 - Nothing 1 - OverTaking  2 - Overtaking cancellation 3 - Cancel all 4 - CrossWalkFar 5 - SpeedBumpFar 6 - Stop 7 - NoEntry 8 - CrosswalkNear 9 - SpeedBumpNear 10 - MainRoad 11 - SecondRoad intval=realval */
uint8_t TsrSignOverTaking = 0U;

/* 0..20 Speed sign _Type: 0-no sign; 1-5kmh; 2-10kmh; 3-20kmh … 16-150kmh; 17-CancelSpdLim; 18-reserved; 19-reserved; 20-reserved intval=realval */
uint8_t TsrSignSpeed = 0U;

/* 0..1 Request from ADAS. If the signal = 1 MAS should turn on the parking sensors and display the message MAS_FrontUSS in the CAN intval=realval */
uint8_t USSFrontReq = 0U;

/* 0..1 Request from ADAS. If the signal = 1 MAS should turn on the parking sensors and display the message MAS_RearUSS in the CAN intval=realval */
uint8_t USSRearReq = 0U;

/* 0..1 Request from ADAS. If the signal = 1 MAS should turn on the parking sensors and display the message MAS_SideUSS in the CAN intval=realval */
uint8_t USSSideReq = 0U;

/* 0..3 ACC target distance intval=realval */
uint8_t VisAccSetDist = 0U;

/* 0..20 ACC target lock to obj with dynam ID: 0 - no object, 1, 2, ... 20 intval=realval */
uint8_t VisAccTargetObj = 0U;

/* 0..20 AEB target lock to obj with dynam ID: 0 - no object, 1, 2, ... 20 intval=realval */
uint8_t VisAebTargetObj = 0U;

/* 0..4 Ego car trajectory in center lane. 0 - Left edge zone, 1 - Left offset zone, 2 - Center zone, 3 - Right offset zone, 4 - Right edge zone intval=realval */
uint8_t VisEgoZone = 2U;

/* 0..20 FCW target lock to obj with dynam ID: 0 - no object, 1, 2, ... 20 intval=realval */
uint8_t VisFcwTargetObj = 0U;

/* 0..1 Left edge lane status 0 - lane does not exist, 1 - lane exists intval=realval */
uint8_t VisLaneLLType = 0U;

/* 0..4 0 - line not found  1 - solid 2- broken  3- Virtual   4 - Edge of the road intval=realval */
uint8_t VisLaneLType = 0U;

/* 0..1 Right edge lane status 0 - lane does not exist, 1 - lane exists intval=realval */
uint8_t VisLaneRRType = 0U;

/* 0..4 0 - line not found  1 - solid 2- broken  3- Virtual  4 - Edge of the road intval=realval */
uint8_t VisLaneRType = 0U;

/* 0..1 LCC warning notification for left lane. 0- No Req 1-Request intval=realval */
uint8_t VisLccLeftLane = 0U;

/* 0..1 LCC warning notification for right lane. 0- No Req 1-Request intval=realval */
uint8_t VisLccRightLane = 0U;

/* 0..1 LDP warning for left line. 0 - No req 1 - Request intval=realval */
uint8_t VisLdpLeftLine = 0U;

/* 0..1 LDP warning for right line. 0 - No req 1 - Request intval=realval */
uint8_t VisLdpRightLine = 0U;

/* 0..1 LDW warning notification for left line. 0- No Req 1-Request intval=realval */
uint8_t VisLdwLeftLine = 0U;

/* 0..1 LDW warning notification for right line. 0- No Req 1-Request intval=realval */
uint8_t VisLdwRightLine = 0U;

/* 0..1 LKA mode status. 0 - Inactive, 1 - Active intval=realval */
uint8_t VisLkaAct = 0U;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
uint8_t VisObj1_Type = 0U;

/* 0..100 [m] Longitudinal distance to object №1, m intval=realval */
float VisObj1DistLong = 0.0000000E+000;

/* 0..3 Orientation of object №1. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
uint8_t VisObj1Orient = 0U;

/* 0..9 Number zone for object №1. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
uint8_t VisObj1Zone = 0U;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
uint8_t VisObj2_Type = 0U;

/* 0..100 [m] Longitudinal distance to object №2, m intval=realval */
float VisObj2DistLong = 0.0000000E+000;

/* 0..3 Orientation of object №2. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
uint8_t VisObj2Orient = 0U;

/* 0..9 Number zone for object №2. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
uint8_t VisObj2Zone = 0U;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
uint8_t VisObj3_Type = 0U;

/* 0..100 [m] Longitudinal distance to object №3, m intval=realval */
float VisObj3DistLong = 0.0000000E+000;

/* 0..3 Orientation of object №3. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
uint8_t VisObj3Orient = 0U;

/* 0..9 Number zone for object №3. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
uint8_t VisObj3Zone = 0U;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
uint8_t VisObj4_Type = 0U;

/* 0..100 [m] Longitudinal distance to object №4, m intval=realval */
float VisObj4DistLong = 0.0000000E+000;

/* 0..3 Orientation of object №4. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
uint8_t VisObj4Orient = 0U;

/* 0..9 Number zone for object №4. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
uint8_t VisObj4Zone = 0U;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
uint8_t VisObj5_Type = 0U;

/* 0..100 [m] Longitudinal distance to object №5, m intval=realval */
float VisObj5DistLong = 0.0000000E+000;

/* 0..3 Orientation of object №5. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
uint8_t VisObj5Orient = 0U;

/* 0..9 Number zone for object №5. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
uint8_t VisObj5Zone = 0U;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
uint8_t VisObj6_Type = 0U;

/* 0..100 [m] Longitudinal distance to object №6, m intval=realval */
float VisObj6DistLong = 0.0000000E+000;

/* 0..3 Orientation of object №6. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
uint8_t VisObj6Orient = 0U;

/* 0..9 Number zone for object №6. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
uint8_t VisObj6Zone = 0U;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
uint8_t VisObj7_Type = 0U;

/* 0..100 [m] Longitudinal distance to object №7, m intval=realval */
float VisObj7DistLong = 0.0000000E+000;

/* 0..3 Orientation of object №7. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
uint8_t VisObj7Orient = 0U;

/* 0..9 Number zone for object №7. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
uint8_t VisObj7Zone = 0U;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
uint8_t VisObj8_Type = 0U;

/* 0..100 [m] Longitudinal distance to object №8, m intval=realval */
float VisObj8DistLong = 0.0000000E+000;

/* 0..3 Orientation of object №8. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
uint8_t VisObj8Orient = 0U;

/* 0..9 Number zone for object №8. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
uint8_t VisObj8Zone = 0U;

/* 0..7 Type of Obj 0- Not object 1-Car 2-Wall 3-Truck 4-Bus 5-Person 6-Moto 7-Animals intval=realval */
uint8_t VisObj9_Type = 0U;

/* 0..100 [m] Longitudinal distance to object №9, m intval=realval */
float VisObj9DistLong = 0.0000000E+000;

/* 0..3 Orientation of object №9. 0 - 0 deg, 1 - 90 deg, 2 - (-90) deg, 3 - 180 deg intval=realval */
uint8_t VisObj9Orient = 0U;

/* 0..9 Number zone for object №9. 0 - nothing, 1 - center of left lane, 2 - offset of left lane, 3 - left line, 4 - left offset of center lane, 5 - center lane, 6 - right offset of center lane, 7 - right line, 8 - offset of right lane, 9 - center of right lane intval=realval */
uint8_t VisObj9Zone = 0U;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
uint8_t VisObjDynam1ID = 0U;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
uint8_t VisObjDynam2ID = 0U;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
uint8_t VisObjDynam3ID = 0U;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
uint8_t VisObjDynam4ID = 0U;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
uint8_t VisObjDynam5ID = 0U;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
uint8_t VisObjDynam6ID = 0U;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
uint8_t VisObjDynam7ID = 0U;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
uint8_t VisObjDynam8ID = 0U;

/* 0..20 0 - no object, 1, 2, ... 20 intval=realval */
uint8_t VisObjDynam9ID = 0U;

/* 0..4 0-straight road, 1-smooth left turn, 2-sharp left turn, 3-smooth right turn, 4-sharp right turn intval=realval */
uint8_t VisRoadAngleLvl = 0U;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

