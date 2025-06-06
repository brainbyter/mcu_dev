/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* 0..1 Start from Standby mode 0 - OFF 1- ON intval=realval */
uint8_t DfConfAccAutoStandBy = 0U;

/* 0..1 Colunm Mode Activate (min dist very short) intval=realval */
uint8_t DfConfAccColumnMode = 0U;

/* 0..1 Parade Mode Activate (min set speed = 0) intval=realval */
uint8_t DfConfAccParadMode = 0U;

/* 0..1 Revers order:  0 - СС->ACC->LIM, 1 - СС->LIM->ACC intval=realval */
uint8_t DfConfAccReversOrder = 0U;

/* 0..1 Ignore Seat Belt Status ( 0-no ignore, 1 - Ignore) intval=realval */
uint8_t DfConfAccSeatBeltIgnore = 0U;

/* 0..3 Always run TypeCC from  0 - from memory 1- cc,  2-acc  3-Lim intval=realval */
uint8_t DfConfAccStartFromMem = 0U;

/* 0..1 Aeb Active Every Ignition 0- no activate 1-activate intval=realval */
uint8_t DfConfAebActiveEveryIgnition = 0U;

/* 0..1 Type of AEB from Diagnostic 0 - AEB 1 - CAEB intval=realval */
uint8_t DfConfAebType = 0U;

/* 0..1 0 - do not call an SOS; 1 - to call an SOS intval=realval */
uint8_t DfConfAfsSosMode = 0U;

/* 0..1 0 - ADAS is disabled ; 1 - ADAS is enabled intval=realval */
uint8_t DfConfDasAvail = 0U;

/* 0..1 Independent memory for speed limiter intval=realval */
uint8_t DfConfLimSpeedMemAvail = 0U;

/* 0..2 REC Size video file (0 - 1 min,  1 - 2min,  2 - 5 min) intval=realval */
uint8_t DfConfRecFileSize = 0U;

/* 0..1 REC Resolution (0 - 720,  1 - 1080) intval=realval */
uint8_t DfConfRecResol = 0U;

/* 0..1 Availability Aa 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagAaAvail = 1U;

/* 0..1 Request to "Error" AA 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagAAErReq = 0U;

/* 0..1 Availability ACC 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagAccAvail = 1U;

/* 0..1 Request to "Error" ACC 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagAccErReq = 0U;

/* 0..1 Availability AEB 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagAebAvail = 1U;

/* 0..1 Request to "Error" AEB 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagAebErReq = 0U;

/* 0..1 Availability Afs 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagAfsAvail = 1U;

/* 0..1 Request to "Error" AFS 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagAfsErReq = 0U;

/* 0..1 Availability Alcc 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagAlccAvail = 1U;

/* 0..1 Request to "Error" ALCC 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagAlccErReq = 0U;

/* 0..1 Vehicle armor type (0 - light, 1 - heavy (armored)) intval=realval */
uint8_t DfDiagArmorType = 0U;

/* 0..1 Availability ASLA 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagAslaAvail = 1U;

/* 0..1 Request to "Error" Asla 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagAslaErReq = 0U;

/* 0..5 Vehicle body type (0 - sedan, 1 - limousine, 2 - MPV, 3 - SUV, 4 - cabriolet, 5 - sedan long) intval=realval */
uint8_t DfDiagBodyType = 0U;

/* 0..2 Brake type 0- Bosch 1- Trinova 2 - Trinova armor intval=realval */
uint8_t DfDiagBrakeType = 0U;

/* 0..1 Availability CC 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagCcAvail = 1U;

/* 0..1 Request to "Error" CC 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagCCErReq = 0U;

/* 0..1 Availability DOW 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagDowAvail = 1U;

/* 0..1 Request to "Error" DOW 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagDowErReq = 0U;

/* 0..1 Availability FCW 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagFcwAvail = 1U;

/* 0..1 Request to "Error" FCW 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagFcwErReq = 0U;

/* 0..1 Availability Front Radar 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagFrontRadarAvail = 0U;

/* 0..2 Windshield heating in the camera area  0 - never, 1 - little, 2 - always intval=realval */
uint8_t DfDiagHeatCamera = 0U;

/* 0..1 Availability Lcc 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagLccAvail = 1U;

/* 0..1 Request to "Error" LCC 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagLccErReq = 0U;

/* 0..1 Availability LDP 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagLdpAvail = 1U;

/* 0..1 Request to "Error" LDP 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagLdpErReq = 0U;

/* 0..1 Availability Ldw 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagLdwAvail = 1U;

/* 0..1 Request to "Error" LDW 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagLdwErReq = 0U;

/* 0..1 Availability Lidar 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagLidarAvail = 0U;

/* 0..2 Washing Lidar  0 - never, 1 - by multimedia, 2 - always intval=realval */
uint8_t DfDiagLidarWash = 0U;

/* 0..1 Availability LIM 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagLimAvail = 1U;

/* 0..1 Request to "Error" LIM 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagLimErReq = 0U;

/* 0..1 Availability Lka Auto 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagLkaAutoStart = 0U;

/* 0..1 Availability Lka 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagLkaAvail = 1U;

/* 0..1 Request to "Error" LKA 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagLkaErReq = 0U;

/* 0..1 Availability Mlia 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagMliaAvail = 1U;

/* 0..5 Turning off HB animation: 0 - without animation, 1 - from center to edge, 2 - from edge to center, 3 - from left to right, 4 - from right to left intval=realval */
uint8_t DfDiagMliaByeType = 2U;

/* 0..1 Request to "Error" MLIA 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagMliaErReq = 0U;

/* 0..1 Limited MLIA functionality - only turning on/off high beams (0 - full MLIA, 1 - limited HBA func) intval=realval */
uint8_t DfDiagMliaHba = 0U;

/* 0..5 Turning on HB animation: 0 - without animation, 1 - from center to edge, 2 - from edge to center, 3 - from left to right, 4 - from right to left intval=realval */
uint8_t DfDiagMliaWelcomeType = 1U;

/* 0..1 Availability Nv 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagNvAvail = 1U;

/* 0..1 Request to "Error" NV 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagNvErReq = 0U;

/* 0..3 Vehicle power type (0 - HEV, 1 - BEV, 2 - PHEV, 3 - PFCV) intval=realval */
uint8_t DfDiagPowerType = 0U;

/* 0..2 Radar Wash  0 - never, 1 - by multimedia, 2 - always intval=realval */
uint8_t DfDiagRadarWash = 0U;

/* 0..1 Availability Rctc 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagRctcAvail = 1U;

/* 0..1 Request to "Error" RCTC 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagRctcErReq = 0U;

/* 0..1 Availability Rcw  0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagRcwAvail = 1U;

/* 0..1 Request to "Error" RCW 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagRcwErReq = 0U;

/* 0..1 Availability Rda 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagRdaAvail = 1U;

/* 0..1 Request to "Error" RDA 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagRdaErReq = 0U;

/* 0..1 Availability Rear Radar 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagRearRadarAvail = 0U;

/* 0..1 Availability Rear Steering Actuator (0-no avail, 1 - Avail) intval=realval */
uint8_t DfDiagRearSteeringActuatorAvail = 0U;

/* 0..1 Availability Rec 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagRecAvail = 1U;

/* 0..1 Request to "Error" REC 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagRecErReq = 0U;

/* 0..1 Steering rack type (0 - hydraulic, 1 - electric) intval=realval */
uint8_t DfDiagSteeringRackType = 0U;

/* 0..1 Steering wheel type (0 - 4 buttons 1- 7 buttons) intval=realval */
uint8_t DfDiagSteeringWheelType = 0U;

/* 0..1 Suspension type (0-spring, 1-air) intval=realval */
uint8_t DfDiagSuspentionType = 0U;

/* 0..1 Availability TiCU 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagThermalCameraAvail = 0U;

/* 0..2 Washing Thermal Camera  0 - never, 1 - by multimedia, 2 - always intval=realval */
uint8_t DfDiagThermalCameraWash = 0U;

/* 0..1 Availability Tsr 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagTsrAvail = 1U;

/* 0..1 Request to "Error" TSR 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagTsrErReq = 0U;

/* 0..1 Valid status of the front MAS intval=realval */
uint8_t DfDiagValidDataMAS_Front = 0U;

/* 0..1 Valid status of the rear MAS intval=realval */
uint8_t DfDiagValidDataMAS_Rear = 0U;

/* 0..1 Valid status of the side MAS intval=realval */
uint8_t DfDiagValidDataMAS_Side = 0U;

/* 0..1 Availability Visual 0-no avail, 1 - Avail intval=realval */
uint8_t DfDiagVisualAvail = 1U;

/* 0..1 Request to "Error"Visual 0-no Error, 1 - Error intval=realval */
uint8_t DfDiagVisualErReq = 0U;

/* 0..999.9 Erag Course intval=realval */
float DfEragCourse = 0.0000000E+000;

/* 0..31 Erag Day intval=realval */
uint8_t DfEragDay = 0U;

/* 0..24 Erag Hours intval=realval */
uint8_t DfEragHours = 0U;

/* -90..90 Erag Latitude intval=realval */
float DfEragLatitude = 0.0000000E+000;

/* -180..180 Erag Longitude intval=realval */
float DfEragLongitude = 0.0000000E+000;

/* 0..60 Erag Minutes intval=realval */
uint8_t DfEragMinutes = 0U;

/* 0..12 Erag Month intval=realval */
uint8_t DfEragMonth = 0U;

/* 0..60 Erag Seconds intval=realval */
uint8_t DfEragSeconds = 0U;

/* 0..999.9 Erag Speed intval=realval */
float DfEragSpeed = 0.0000000E+000;

/* 0..255 Erag Year intval=realval */
uint8_t DfEragYear = 0U;

/* 0..20 Attentiveness coefficient from Memory intval=realval */
uint8_t DfMemAaCoeffAtts = 14U;

/* 0..1 Attentiveness coefficient from Memory intval=realval */
uint8_t DfMemAaStTest = 0U;

/* 0..4294967295 Time after turning off the ignition intval=realval */
uint32_t DfMemAaTimeIgn = 0U;

/* 0..4294967295 Time to calculate the attentiveness coefficient intval=realval */
uint32_t DfMemAaTimeSave = 0U;

/* 0..1 Distance to ACC from Memory intval=realval */
uint8_t DfMemAccDist = 0U;

/* 0..255 Speed_kmh to ACC from Memory intval=realval */
uint8_t DfMemAccSpeedKmh = 0U;

/* 0..65535 [h] Driving time beetwin 20-80 km/h intval=realval */
float DfMemAnAccTimeCity = 0.0000000E+000;

/* 0..65535 [h] Driving time above 80 km/h intval=realval */
float DfMemAnAccTimeHighWay = 0.0000000E+000;

/* 0..65535 [h] Driving time up to 20 km/h intval=realval */
float DfMemAnAccTimeJam = 0.0000000E+000;

/* 0..65535 [h] Driving time distance above to 40 m intval=realval */
float DfMemAnAccTimeMaxDist = 0.0000000E+000;

/* 0..65535 [h] Driving time distance  beetwin to 20-30 m intval=realval */
float DfMemAnAccTimeMedDist = 0.0000000E+000;

/* 0..65535 [h] Driving time distance  beetwin to 30-40 m intval=realval */
float DfMemAnAccTimeMedMaxDist = 0.0000000E+000;

/* 0..65535 [h] Driving time distance up to 20 m intval=realval */
float DfMemAnAccTimeMinDist = 0.0000000E+000;

/* 0..65535 [km] Distance traveled with active function AEB intval=realval */
float DfMemAnAebActvnDst = 0.0000000E+000;

/* 0..65535 [m] Average distance to the target when AEB is activated intval=realval */
float DfMemAnAebAvgDistToTar = 0.0000000E+000;

/* -1..1 Stored AEB warning correction time: -1, -0.95, -0.9...1 intval=realval */
float DfMemAnAebCorrnTiWarn = 0.0000000E+000;

/* 0..255 Number of operations AEB intval=realval */
uint8_t DfMemAnAebNrOfOper = 0U;

/* 0..65535 [km] Distance traveled with active function ALCC intval=realval */
float DfMemAnAlccActvnDst = 0.0000000E+000;

/* 0..65535 Number of operations ALCC intval=realval */
float DfMemAnAlccNrOfOper = 0.0000000E+000;

/* 0..65535 [h] Driving hour on CC intval=realval */
float DfMemAnCcTime = 0.0000000E+000;

/* -1..1 Stored DOW warning correction time: -1, -0.95, -0.9...1 intval=realval */
float DfMemAnDowCorrnTiWarn = 0.0000000E+000;

/* 0..65535 Number of operations DOW intval=realval */
float DfMemAnDowNrOfOper = 0.0000000E+000;

/* 0..65535 [h] Time elapsed with active function DOW intval=realval */
float DfMemAnDowTime = 0.0000000E+000;

/* 0..65535 [km] Distance traveled with active function FCW intval=realval */
float DfMemAnFcwActvnDst = 0.0000000E+000;

/* 0..255 Number of operations FCW intval=realval */
uint8_t DfMemAnFcwNrOfOper = 0U;

/* 0..65535 [km] Distance traveled with active function LCC intval=realval */
float DfMemAnLccActvnDst = 0.0000000E+000;

/* -1..1 Stored LCC warning correction time: -1, -0.95, -0.9...1 intval=realval */
float DfMemAnLccCorrnTiWarn = 0.0000000E+000;

/* 0..65535 Number of operations LCC intval=realval */
float DfMemAnLccNrOfOper = 0.0000000E+000;

/* 0..65535 [h] Number of warnings LDP intval=realval */
float DfMemAnLdpNumOfWarn = 0.0000000E+000;

/* 0..65535 [h] Active LDP working time intval=realval */
float DfMemAnLdpTimeActive = 0.0000000E+000;

/* 0..65535 [h] Number of warnings LDW intval=realval */
float DfMemAnLdwNumOfWarn = 0.0000000E+000;

/* 0..65535 [h] Active LDW working time intval=realval */
float DfMemAnLdwTimeActive = 0.0000000E+000;

/* 0..65535 [h] Active LKA working time intval=realval */
float DfMemAnLkaTimeActive = 0.0000000E+000;

/* 0..65535 [h] Total LKA working time (StandBy (ACC active) + Active) intval=realval */
float DfMemAnLkaTimeTotal = 0.0000000E+000;

/* 0..65535 [h] Object recognition time intval=realval */
float DfMemAnMliaTimeObj = 0.0000000E+000;

/* 0..65535 [h] Total MLIA working time intval=realval */
float DfMemAnMliaTimeTotal = 0.0000000E+000;

/* 0..65535 [km] Distance traveled with active function RCTC intval=realval */
float DfMemAnRctcaActvnDst = 0.0000000E+000;

/* 0..255 [m] Average distance to the target when RCTC is activated intval=realval */
uint8_t DfMemAnRctcAvgDistToTar = 0U;

/* 0..255 Number of operations RCTC intval=realval */
uint8_t DfMemAnRctcNrOfOper = 0U;

/* 0..255 [m] Average distance to the target when RCW is activated intval=realval */
uint8_t DfMemAnRcwAvgDistToTar = 0U;

/* 0..255 Number of operations RCW intval=realval */
uint8_t DfMemAnRcwNrOfOper = 0U;

/* 0..65535 [km] Distance traveled with active function RDA intval=realval */
float DfMemAnRdaActvnDst = 0.0000000E+000;

/* 0..65535 [m] Average distance to the target when RDA is activated intval=realval */
float DfMemAnRdaAvgDistToTar = 0.0000000E+000;

/* -1..1 Stored RDA warning correction time: -1, -0.45, -0.4…1 intval=realval */
float DfMemAnRdaCorrnTiWarn = 0.0000000E+000;

/* 0..65535 Number of operations RDA intval=realval */
float DfMemAnRdaNrOfOper = 0.0000000E+000;

/* 0..2 Mode of AA 0x0 - No   0x1 - Low sensitivity mode 0x2 - High sensitivity mode intval=realval */
uint8_t DfMemFiuAaMode = 1U;

/* 0..1 Status of AA 0x0 - OFF   0x1 - ON intval=realval */
uint8_t DfMemFiuAaStat = 1U;

/* 0..1 Status of AEB 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuAebStat = 1U;

/* 0..1 Status of AFS 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuAfsStat = 1U;

/* 0..1 Status of ALCC  0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuAlccStat = 1U;

/* 0..60 Overtaking speed 0x0 - 0 kmh   0x1  - 1 kmh  ...0x3C -  60 kmh intval=realval */
uint8_t DfMemFiuAslaOver = 0U;

/* 0..1 Status of ASLA 0x0 -Off   0x1 - On intval=realval */
uint8_t DfMemFiuAslaStat = 1U;

/* 0..1 Status of Assist1 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuAssistActive1Stat = 1U;

/* 0..1 Status of Assist2 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuAssistActive2Stat = 1U;

/* 0..1 Status of Assist3 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuAssistActive3Stat = 1U;

/* 0..1 Status of Assist4 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuAssistActive4Stat = 1U;

/* 0..1 Dynamics of СС  0x0 - Auto mode  0x1 - Comfort mode  0x2 - Dynamic mode intval=realval */
uint8_t DfMemFiuCcMode = 1U;

/* 0..1 Change of speed in a turn  0x0 - Off  0x1 - On intval=realval */
uint8_t DfMemFiuCcSpdCorrect = 1U;

/* 0..3 Type of СС 0x0 -  Off 0x1 -  CC   0x2 - ACC   0x3 - LIM intval=realval */
uint8_t DfMemFiuCcType = 1U;

/* 0..1 Sound on IC when DOW is warningReq 0x0 - OFF   0x1 - ON intval=realval */
uint8_t DfMemFiuDowSound = 1U;

/* 0..1 Status of DOW 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuDowStat = 1U;

/* 0..2 Mode of FCW 0x0 - Early mode 0x1 - Normal mode  0x2 - Late mode intval=realval */
uint8_t DfMemFiuFcwMode = 1U;

/* 0..1 Status of FCW 0x0 - Off  0x1 - On intval=realval */
uint8_t DfMemFiuFcwStat = 1U;

/* 0..1 Vibration on steering wheel when FCW is warningReq 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuFcwVibration = 1U;

/* 0..2 Mode of LCC 0x0 - Early mode  0x1 - Normal mode  0x2 - Late mode intval=realval */
uint8_t DfMemFiuLccMode = 1U;

/* 0..1 Sound on IC when LCC is warningReq 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuLccSound = 1U;

/* 0..1 Status of LCC 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuLccStat = 1U;

/* 0..1 Vibration on steering wheel when LCC is warningReq 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuLccVibration = 1U;

/* 0..1 Status of LDP 0x0 - OFF   0x1 - ON intval=realval */
uint8_t DfMemFiuLdpStat = 1U;

/* 0..1 Mode of LDW 0x0 - before crossing  0x1 - while crossing intval=realval */
uint8_t DfMemFiuLdwMode = 1U;

/* 0..1 Sound on IC when LDW is warningReq 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuLdwSound = 1U;

/* 0..1 Status of LDW 0x0 - OFF   0x1 - ON intval=realval */
uint8_t DfMemFiuLdwStat = 1U;

/* 0..1 Vibration on steering wheel when LDW is warningReq 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuLdwVibration = 1U;

/* 0..1 Status of LKA 0x0 - Off 0x1 - On intval=realval */
uint8_t DfMemFiuLkaStat = 1U;

/* 0..1 Status of Navigation: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuNavigStat = 1U;

/* 0..1 Status of Other Objects: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuOtherObjStat = 1U;

/* 0..1 Status of Projection: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuProjectionOnARoadStat = 0U;

/* 0..1 Status of RCTC 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuRctcStat = 1U;

/* 0..3 Status of RCW 0x0 - OFF   0x1 - ON intval=realval */
uint8_t DfMemFiuRcwStat = 1U;

/* 0..1 Status of RDA Auto Brake 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuRdaAutoBrakeStat = 1U;

/* 0..1 Status of RDA 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuRdaStat = 1U;

/* 0..1 Status of REC 0x0 - OFF   0x1 - ON intval=realval */
uint8_t DfMemFiuRecStat = 1U;

/* 0..1 Status of Road Sign: 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuRoadSignStat = 1U;

/* 0..1 Status of Sensor clean function 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuSensCleanStat = 1U;

/* 0..1 Status of TSR 0x0 - OFF  0x1 - ON intval=realval */
uint8_t DfMemFiuTsrStat = 1U;

/* 0..3 Type CC-ACC-LIM from Memory. 0 - nothing, 1-CC, 2-ACC, 3-LIM intval=realval */
uint8_t DfMemTypeCC = 0U;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

