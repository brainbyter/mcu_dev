/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* 0..1 Start from Standby mode 0 - OFF 1- ON intval=realval */
#define DECLARED_DfConfAccAutoStandBy	DfConfAccAutoStandBy
extern uint8_t DfConfAccAutoStandBy;

/* 0..1 Colunm Mode Activate (min dist very short) intval=realval */
#define DECLARED_DfConfAccColumnMode	DfConfAccColumnMode
extern uint8_t DfConfAccColumnMode;

/* 0..1 Parade Mode Activate (min set speed = 0) intval=realval */
#define DECLARED_DfConfAccParadMode	DfConfAccParadMode
extern uint8_t DfConfAccParadMode;

/* 0..1 Revers order:  0 - СС->ACC->LIM, 1 - СС->LIM->ACC intval=realval */
#define DECLARED_DfConfAccReversOrder	DfConfAccReversOrder
extern uint8_t DfConfAccReversOrder;

/* 0..1 Ignore Seat Belt Status ( 0-no ignore, 1 - Ignore) intval=realval */
#define DECLARED_DfConfAccSeatBeltIgnore	DfConfAccSeatBeltIgnore
extern uint8_t DfConfAccSeatBeltIgnore;

/* 0..3 Always run TypeCC from  0 - from memory 1- cc,  2-acc  3-Lim intval=realval */
#define DECLARED_DfConfAccStartFromMem	DfConfAccStartFromMem
extern uint8_t DfConfAccStartFromMem;

/* 0..1 Aeb Active Every Ignition 0- no activate 1-activate intval=realval */
#define DECLARED_DfConfAebActiveEveryIgnition	DfConfAebActiveEveryIgnition
extern uint8_t DfConfAebActiveEveryIgnition;

/* 0..1 Type of AEB from Diagnostic 0 - AEB 1 - CAEB intval=realval */
#define DECLARED_DfConfAebType	DfConfAebType
extern uint8_t DfConfAebType;

/* 0..1 0 - do not call an SOS; 1 - to call an SOS intval=realval */
#define DECLARED_DfConfAfsSosMode	DfConfAfsSosMode
extern uint8_t DfConfAfsSosMode;

/* 0..1 0 - ADAS is disabled ; 1 - ADAS is enabled intval=realval */
#define DECLARED_DfConfDasAvail	DfConfDasAvail
extern uint8_t DfConfDasAvail;

/* 0..1 Independent memory for speed limiter intval=realval */
#define DECLARED_DfConfLimSpeedMemAvail	DfConfLimSpeedMemAvail
extern uint8_t DfConfLimSpeedMemAvail;

/* 0..2 REC Size video file (0 - 1 min,  1 - 2min,  2 - 5 min) intval=realval */
#define DECLARED_DfConfRecFileSize	DfConfRecFileSize
extern uint8_t DfConfRecFileSize;

/* 0..1 REC Resolution (0 - 720,  1 - 1080) intval=realval */
#define DECLARED_DfConfRecResol	DfConfRecResol
extern uint8_t DfConfRecResol;

/* 0..1 Availability Aa 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagAaAvail	DfDiagAaAvail
extern uint8_t DfDiagAaAvail;

/* 0..1 Request to "Error" AA 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagAAErReq	DfDiagAAErReq
extern uint8_t DfDiagAAErReq;

/* 0..1 Availability ACC 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagAccAvail	DfDiagAccAvail
extern uint8_t DfDiagAccAvail;

/* 0..1 Request to "Error" ACC 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagAccErReq	DfDiagAccErReq
extern uint8_t DfDiagAccErReq;

/* 0..1 Availability AEB 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagAebAvail	DfDiagAebAvail
extern uint8_t DfDiagAebAvail;

/* 0..1 Request to "Error" AEB 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagAebErReq	DfDiagAebErReq
extern uint8_t DfDiagAebErReq;

/* 0..1 Availability Afs 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagAfsAvail	DfDiagAfsAvail
extern uint8_t DfDiagAfsAvail;

/* 0..1 Request to "Error" AFS 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagAfsErReq	DfDiagAfsErReq
extern uint8_t DfDiagAfsErReq;

/* 0..1 Availability Alcc 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagAlccAvail	DfDiagAlccAvail
extern uint8_t DfDiagAlccAvail;

/* 0..1 Request to "Error" ALCC 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagAlccErReq	DfDiagAlccErReq
extern uint8_t DfDiagAlccErReq;

/* 0..1 Vehicle armor type (0 - light, 1 - heavy (armored)) intval=realval */
#define DECLARED_DfDiagArmorType	DfDiagArmorType
extern uint8_t DfDiagArmorType;

/* 0..1 Availability ASLA 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagAslaAvail	DfDiagAslaAvail
extern uint8_t DfDiagAslaAvail;

/* 0..1 Request to "Error" Asla 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagAslaErReq	DfDiagAslaErReq
extern uint8_t DfDiagAslaErReq;

/* 0..5 Vehicle body type (0 - sedan, 1 - limousine, 2 - MPV, 3 - SUV, 4 - cabriolet, 5 - sedan long) intval=realval */
#define DECLARED_DfDiagBodyType	DfDiagBodyType
extern uint8_t DfDiagBodyType;

/* 0..2 Brake type 0- Bosch 1- Trinova 2 - Trinova armor intval=realval */
#define DECLARED_DfDiagBrakeType	DfDiagBrakeType
extern uint8_t DfDiagBrakeType;

/* 0..1 Availability CC 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagCcAvail	DfDiagCcAvail
extern uint8_t DfDiagCcAvail;

/* 0..1 Request to "Error" CC 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagCCErReq	DfDiagCCErReq
extern uint8_t DfDiagCCErReq;

/* 0..1 Availability DOW 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagDowAvail	DfDiagDowAvail
extern uint8_t DfDiagDowAvail;

/* 0..1 Request to "Error" DOW 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagDowErReq	DfDiagDowErReq
extern uint8_t DfDiagDowErReq;

/* 0..1 Availability FCW 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagFcwAvail	DfDiagFcwAvail
extern uint8_t DfDiagFcwAvail;

/* 0..1 Request to "Error" FCW 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagFcwErReq	DfDiagFcwErReq
extern uint8_t DfDiagFcwErReq;

/* 0..1 Availability Front Radar 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagFrontRadarAvail	DfDiagFrontRadarAvail
extern uint8_t DfDiagFrontRadarAvail;

/* 0..2 Windshield heating in the camera area  0 - never, 1 - little, 2 - always intval=realval */
#define DECLARED_DfDiagHeatCamera	DfDiagHeatCamera
extern uint8_t DfDiagHeatCamera;

/* 0..1 Availability Lcc 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagLccAvail	DfDiagLccAvail
extern uint8_t DfDiagLccAvail;

/* 0..1 Request to "Error" LCC 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagLccErReq	DfDiagLccErReq
extern uint8_t DfDiagLccErReq;

/* 0..1 Availability LDP 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagLdpAvail	DfDiagLdpAvail
extern uint8_t DfDiagLdpAvail;

/* 0..1 Request to "Error" LDP 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagLdpErReq	DfDiagLdpErReq
extern uint8_t DfDiagLdpErReq;

/* 0..1 Availability Ldw 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagLdwAvail	DfDiagLdwAvail
extern uint8_t DfDiagLdwAvail;

/* 0..1 Request to "Error" LDW 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagLdwErReq	DfDiagLdwErReq
extern uint8_t DfDiagLdwErReq;

/* 0..1 Availability Lidar 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagLidarAvail	DfDiagLidarAvail
extern uint8_t DfDiagLidarAvail;

/* 0..2 Washing Lidar  0 - never, 1 - by multimedia, 2 - always intval=realval */
#define DECLARED_DfDiagLidarWash	DfDiagLidarWash
extern uint8_t DfDiagLidarWash;

/* 0..1 Availability LIM 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagLimAvail	DfDiagLimAvail
extern uint8_t DfDiagLimAvail;

/* 0..1 Request to "Error" LIM 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagLimErReq	DfDiagLimErReq
extern uint8_t DfDiagLimErReq;

/* 0..1 Availability Lka Auto 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagLkaAutoStart	DfDiagLkaAutoStart
extern uint8_t DfDiagLkaAutoStart;

/* 0..1 Availability Lka 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagLkaAvail	DfDiagLkaAvail
extern uint8_t DfDiagLkaAvail;

/* 0..1 Request to "Error" LKA 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagLkaErReq	DfDiagLkaErReq
extern uint8_t DfDiagLkaErReq;

/* 0..1 Availability Mlia 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagMliaAvail	DfDiagMliaAvail
extern uint8_t DfDiagMliaAvail;

/* 0..5 Turning off HB animation: 0 - without animation, 1 - from center to edge, 2 - from edge to center, 3 - from left to right, 4 - from right to left intval=realval */
#define DECLARED_DfDiagMliaByeType	DfDiagMliaByeType
extern uint8_t DfDiagMliaByeType;

/* 0..1 Request to "Error" MLIA 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagMliaErReq	DfDiagMliaErReq
extern uint8_t DfDiagMliaErReq;

/* 0..1 Limited MLIA functionality - only turning on/off high beams (0 - full MLIA, 1 - limited HBA func) intval=realval */
#define DECLARED_DfDiagMliaHba	DfDiagMliaHba
extern uint8_t DfDiagMliaHba;

/* 0..5 Turning on HB animation: 0 - without animation, 1 - from center to edge, 2 - from edge to center, 3 - from left to right, 4 - from right to left intval=realval */
#define DECLARED_DfDiagMliaWelcomeType	DfDiagMliaWelcomeType
extern uint8_t DfDiagMliaWelcomeType;

/* 0..1 Availability Nv 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagNvAvail	DfDiagNvAvail
extern uint8_t DfDiagNvAvail;

/* 0..1 Request to "Error" NV 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagNvErReq	DfDiagNvErReq
extern uint8_t DfDiagNvErReq;

/* 0..3 Vehicle power type (0 - HEV, 1 - BEV, 2 - PHEV, 3 - PFCV) intval=realval */
#define DECLARED_DfDiagPowerType	DfDiagPowerType
extern uint8_t DfDiagPowerType;

/* 0..2 Radar Wash  0 - never, 1 - by multimedia, 2 - always intval=realval */
#define DECLARED_DfDiagRadarWash	DfDiagRadarWash
extern uint8_t DfDiagRadarWash;

/* 0..1 Availability Rctc 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagRctcAvail	DfDiagRctcAvail
extern uint8_t DfDiagRctcAvail;

/* 0..1 Request to "Error" RCTC 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagRctcErReq	DfDiagRctcErReq
extern uint8_t DfDiagRctcErReq;

/* 0..1 Availability Rcw  0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagRcwAvail	DfDiagRcwAvail
extern uint8_t DfDiagRcwAvail;

/* 0..1 Request to "Error" RCW 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagRcwErReq	DfDiagRcwErReq
extern uint8_t DfDiagRcwErReq;

/* 0..1 Availability Rda 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagRdaAvail	DfDiagRdaAvail
extern uint8_t DfDiagRdaAvail;

/* 0..1 Request to "Error" RDA 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagRdaErReq	DfDiagRdaErReq
extern uint8_t DfDiagRdaErReq;

/* 0..1 Availability Rear Radar 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagRearRadarAvail	DfDiagRearRadarAvail
extern uint8_t DfDiagRearRadarAvail;

/* 0..1 Availability Rear Steering Actuator (0-no avail, 1 - Avail) intval=realval */
#define DECLARED_DfDiagRearSteeringActuatorAvail	DfDiagRearSteeringActuatorAvail
extern uint8_t DfDiagRearSteeringActuatorAvail;

/* 0..1 Availability Rec 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagRecAvail	DfDiagRecAvail
extern uint8_t DfDiagRecAvail;

/* 0..1 Request to "Error" REC 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagRecErReq	DfDiagRecErReq
extern uint8_t DfDiagRecErReq;

/* 0..1 Steering rack type (0 - hydraulic, 1 - electric) intval=realval */
#define DECLARED_DfDiagSteeringRackType	DfDiagSteeringRackType
extern uint8_t DfDiagSteeringRackType;

/* 0..1 Steering wheel type (0 - 4 buttons 1- 7 buttons) intval=realval */
#define DECLARED_DfDiagSteeringWheelType	DfDiagSteeringWheelType
extern uint8_t DfDiagSteeringWheelType;

/* 0..1 Suspension type (0-spring, 1-air) intval=realval */
#define DECLARED_DfDiagSuspentionType	DfDiagSuspentionType
extern uint8_t DfDiagSuspentionType;

/* 0..1 Availability TiCU 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagThermalCameraAvail	DfDiagThermalCameraAvail
extern uint8_t DfDiagThermalCameraAvail;

/* 0..2 Washing Thermal Camera  0 - never, 1 - by multimedia, 2 - always intval=realval */
#define DECLARED_DfDiagThermalCameraWash	DfDiagThermalCameraWash
extern uint8_t DfDiagThermalCameraWash;

/* 0..1 Availability Tsr 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagTsrAvail	DfDiagTsrAvail
extern uint8_t DfDiagTsrAvail;

/* 0..1 Request to "Error" TSR 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagTsrErReq	DfDiagTsrErReq
extern uint8_t DfDiagTsrErReq;

/* 0..1 Valid status of the front MAS intval=realval */
#define DECLARED_DfDiagValidDataMAS_Front	DfDiagValidDataMAS_Front
extern uint8_t DfDiagValidDataMAS_Front;

/* 0..1 Valid status of the rear MAS intval=realval */
#define DECLARED_DfDiagValidDataMAS_Rear	DfDiagValidDataMAS_Rear
extern uint8_t DfDiagValidDataMAS_Rear;

/* 0..1 Valid status of the side MAS intval=realval */
#define DECLARED_DfDiagValidDataMAS_Side	DfDiagValidDataMAS_Side
extern uint8_t DfDiagValidDataMAS_Side;

/* 0..1 Availability Visual 0-no avail, 1 - Avail intval=realval */
#define DECLARED_DfDiagVisualAvail	DfDiagVisualAvail
extern uint8_t DfDiagVisualAvail;

/* 0..1 Request to "Error"Visual 0-no Error, 1 - Error intval=realval */
#define DECLARED_DfDiagVisualErReq	DfDiagVisualErReq
extern uint8_t DfDiagVisualErReq;

/* 0..999.9 Erag Course intval=realval */
#define DECLARED_DfEragCourse	DfEragCourse
extern float DfEragCourse;

/* 0..31 Erag Day intval=realval */
#define DECLARED_DfEragDay	DfEragDay
extern uint8_t DfEragDay;

/* 0..24 Erag Hours intval=realval */
#define DECLARED_DfEragHours	DfEragHours
extern uint8_t DfEragHours;

/* -90..90 Erag Latitude intval=realval */
#define DECLARED_DfEragLatitude	DfEragLatitude
extern float DfEragLatitude;

/* -180..180 Erag Longitude intval=realval */
#define DECLARED_DfEragLongitude	DfEragLongitude
extern float DfEragLongitude;

/* 0..60 Erag Minutes intval=realval */
#define DECLARED_DfEragMinutes	DfEragMinutes
extern uint8_t DfEragMinutes;

/* 0..12 Erag Month intval=realval */
#define DECLARED_DfEragMonth	DfEragMonth
extern uint8_t DfEragMonth;

/* 0..60 Erag Seconds intval=realval */
#define DECLARED_DfEragSeconds	DfEragSeconds
extern uint8_t DfEragSeconds;

/* 0..999.9 Erag Speed intval=realval */
#define DECLARED_DfEragSpeed	DfEragSpeed
extern float DfEragSpeed;

/* 0..255 Erag Year intval=realval */
#define DECLARED_DfEragYear	DfEragYear
extern uint8_t DfEragYear;

/* 0..20 Attentiveness coefficient from Memory intval=realval */
#define DECLARED_DfMemAaCoeffAtts	DfMemAaCoeffAtts
extern uint8_t DfMemAaCoeffAtts;

/* 0..1 Attentiveness coefficient from Memory intval=realval */
#define DECLARED_DfMemAaStTest	DfMemAaStTest
extern uint8_t DfMemAaStTest;

/* 0..4294967295 Time after turning off the ignition intval=realval */
#define DECLARED_DfMemAaTimeIgn	DfMemAaTimeIgn
extern uint32_t DfMemAaTimeIgn;

/* 0..4294967295 Time to calculate the attentiveness coefficient intval=realval */
#define DECLARED_DfMemAaTimeSave	DfMemAaTimeSave
extern uint32_t DfMemAaTimeSave;

/* 0..1 Distance to ACC from Memory intval=realval */
#define DECLARED_DfMemAccDist	DfMemAccDist
extern uint8_t DfMemAccDist;

/* 0..255 Speed_kmh to ACC from Memory intval=realval */
#define DECLARED_DfMemAccSpeedKmh	DfMemAccSpeedKmh
extern uint8_t DfMemAccSpeedKmh;

/* 0..65535 [h] Driving time beetwin 20-80 km/h intval=realval */
#define DECLARED_DfMemAnAccTimeCity	DfMemAnAccTimeCity
extern float DfMemAnAccTimeCity;

/* 0..65535 [h] Driving time above 80 km/h intval=realval */
#define DECLARED_DfMemAnAccTimeHighWay	DfMemAnAccTimeHighWay
extern float DfMemAnAccTimeHighWay;

/* 0..65535 [h] Driving time up to 20 km/h intval=realval */
#define DECLARED_DfMemAnAccTimeJam	DfMemAnAccTimeJam
extern float DfMemAnAccTimeJam;

/* 0..65535 [h] Driving time distance above to 40 m intval=realval */
#define DECLARED_DfMemAnAccTimeMaxDist	DfMemAnAccTimeMaxDist
extern float DfMemAnAccTimeMaxDist;

/* 0..65535 [h] Driving time distance  beetwin to 20-30 m intval=realval */
#define DECLARED_DfMemAnAccTimeMedDist	DfMemAnAccTimeMedDist
extern float DfMemAnAccTimeMedDist;

/* 0..65535 [h] Driving time distance  beetwin to 30-40 m intval=realval */
#define DECLARED_DfMemAnAccTimeMedMaxDist	DfMemAnAccTimeMedMaxDist
extern float DfMemAnAccTimeMedMaxDist;

/* 0..65535 [h] Driving time distance up to 20 m intval=realval */
#define DECLARED_DfMemAnAccTimeMinDist	DfMemAnAccTimeMinDist
extern float DfMemAnAccTimeMinDist;

/* 0..65535 [km] Distance traveled with active function AEB intval=realval */
#define DECLARED_DfMemAnAebActvnDst	DfMemAnAebActvnDst
extern float DfMemAnAebActvnDst;

/* 0..65535 [m] Average distance to the target when AEB is activated intval=realval */
#define DECLARED_DfMemAnAebAvgDistToTar	DfMemAnAebAvgDistToTar
extern float DfMemAnAebAvgDistToTar;

/* -1..1 Stored AEB warning correction time: -1, -0.95, -0.9...1 intval=realval */
#define DECLARED_DfMemAnAebCorrnTiWarn	DfMemAnAebCorrnTiWarn
extern float DfMemAnAebCorrnTiWarn;

/* 0..255 Number of operations AEB intval=realval */
#define DECLARED_DfMemAnAebNrOfOper	DfMemAnAebNrOfOper
extern uint8_t DfMemAnAebNrOfOper;

/* 0..65535 [km] Distance traveled with active function ALCC intval=realval */
#define DECLARED_DfMemAnAlccActvnDst	DfMemAnAlccActvnDst
extern float DfMemAnAlccActvnDst;

/* 0..65535 Number of operations ALCC intval=realval */
#define DECLARED_DfMemAnAlccNrOfOper	DfMemAnAlccNrOfOper
extern float DfMemAnAlccNrOfOper;

/* 0..65535 [h] Driving hour on CC intval=realval */
#define DECLARED_DfMemAnCcTime	DfMemAnCcTime
extern float DfMemAnCcTime;

/* -1..1 Stored DOW warning correction time: -1, -0.95, -0.9...1 intval=realval */
#define DECLARED_DfMemAnDowCorrnTiWarn	DfMemAnDowCorrnTiWarn
extern float DfMemAnDowCorrnTiWarn;

/* 0..65535 Number of operations DOW intval=realval */
#define DECLARED_DfMemAnDowNrOfOper	DfMemAnDowNrOfOper
extern float DfMemAnDowNrOfOper;

/* 0..65535 [h] Time elapsed with active function DOW intval=realval */
#define DECLARED_DfMemAnDowTime	DfMemAnDowTime
extern float DfMemAnDowTime;

/* 0..65535 [km] Distance traveled with active function FCW intval=realval */
#define DECLARED_DfMemAnFcwActvnDst	DfMemAnFcwActvnDst
extern float DfMemAnFcwActvnDst;

/* 0..255 Number of operations FCW intval=realval */
#define DECLARED_DfMemAnFcwNrOfOper	DfMemAnFcwNrOfOper
extern uint8_t DfMemAnFcwNrOfOper;

/* 0..65535 [km] Distance traveled with active function LCC intval=realval */
#define DECLARED_DfMemAnLccActvnDst	DfMemAnLccActvnDst
extern float DfMemAnLccActvnDst;

/* -1..1 Stored LCC warning correction time: -1, -0.95, -0.9...1 intval=realval */
#define DECLARED_DfMemAnLccCorrnTiWarn	DfMemAnLccCorrnTiWarn
extern float DfMemAnLccCorrnTiWarn;

/* 0..65535 Number of operations LCC intval=realval */
#define DECLARED_DfMemAnLccNrOfOper	DfMemAnLccNrOfOper
extern float DfMemAnLccNrOfOper;

/* 0..65535 [h] Number of warnings LDP intval=realval */
#define DECLARED_DfMemAnLdpNumOfWarn	DfMemAnLdpNumOfWarn
extern float DfMemAnLdpNumOfWarn;

/* 0..65535 [h] Active LDP working time intval=realval */
#define DECLARED_DfMemAnLdpTimeActive	DfMemAnLdpTimeActive
extern float DfMemAnLdpTimeActive;

/* 0..65535 [h] Number of warnings LDW intval=realval */
#define DECLARED_DfMemAnLdwNumOfWarn	DfMemAnLdwNumOfWarn
extern float DfMemAnLdwNumOfWarn;

/* 0..65535 [h] Active LDW working time intval=realval */
#define DECLARED_DfMemAnLdwTimeActive	DfMemAnLdwTimeActive
extern float DfMemAnLdwTimeActive;

/* 0..65535 [h] Active LKA working time intval=realval */
#define DECLARED_DfMemAnLkaTimeActive	DfMemAnLkaTimeActive
extern float DfMemAnLkaTimeActive;

/* 0..65535 [h] Total LKA working time (StandBy (ACC active) + Active) intval=realval */
#define DECLARED_DfMemAnLkaTimeTotal	DfMemAnLkaTimeTotal
extern float DfMemAnLkaTimeTotal;

/* 0..65535 [h] Object recognition time intval=realval */
#define DECLARED_DfMemAnMliaTimeObj	DfMemAnMliaTimeObj
extern float DfMemAnMliaTimeObj;

/* 0..65535 [h] Total MLIA working time intval=realval */
#define DECLARED_DfMemAnMliaTimeTotal	DfMemAnMliaTimeTotal
extern float DfMemAnMliaTimeTotal;

/* 0..65535 [km] Distance traveled with active function RCTC intval=realval */
#define DECLARED_DfMemAnRctcaActvnDst	DfMemAnRctcaActvnDst
extern float DfMemAnRctcaActvnDst;

/* 0..255 [m] Average distance to the target when RCTC is activated intval=realval */
#define DECLARED_DfMemAnRctcAvgDistToTar	DfMemAnRctcAvgDistToTar
extern uint8_t DfMemAnRctcAvgDistToTar;

/* 0..255 Number of operations RCTC intval=realval */
#define DECLARED_DfMemAnRctcNrOfOper	DfMemAnRctcNrOfOper
extern uint8_t DfMemAnRctcNrOfOper;

/* 0..255 [m] Average distance to the target when RCW is activated intval=realval */
#define DECLARED_DfMemAnRcwAvgDistToTar	DfMemAnRcwAvgDistToTar
extern uint8_t DfMemAnRcwAvgDistToTar;

/* 0..255 Number of operations RCW intval=realval */
#define DECLARED_DfMemAnRcwNrOfOper	DfMemAnRcwNrOfOper
extern uint8_t DfMemAnRcwNrOfOper;

/* 0..65535 [km] Distance traveled with active function RDA intval=realval */
#define DECLARED_DfMemAnRdaActvnDst	DfMemAnRdaActvnDst
extern float DfMemAnRdaActvnDst;

/* 0..65535 [m] Average distance to the target when RDA is activated intval=realval */
#define DECLARED_DfMemAnRdaAvgDistToTar	DfMemAnRdaAvgDistToTar
extern float DfMemAnRdaAvgDistToTar;

/* -1..1 Stored RDA warning correction time: -1, -0.45, -0.4…1 intval=realval */
#define DECLARED_DfMemAnRdaCorrnTiWarn	DfMemAnRdaCorrnTiWarn
extern float DfMemAnRdaCorrnTiWarn;

/* 0..65535 Number of operations RDA intval=realval */
#define DECLARED_DfMemAnRdaNrOfOper	DfMemAnRdaNrOfOper
extern float DfMemAnRdaNrOfOper;

/* 0..2 Mode of AA 0x0 - No   0x1 - Low sensitivity mode 0x2 - High sensitivity mode intval=realval */
#define DECLARED_DfMemFiuAaMode	DfMemFiuAaMode
extern uint8_t DfMemFiuAaMode;

/* 0..1 Status of AA 0x0 - OFF   0x1 - ON intval=realval */
#define DECLARED_DfMemFiuAaStat	DfMemFiuAaStat
extern uint8_t DfMemFiuAaStat;

/* 0..1 Status of AEB 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuAebStat	DfMemFiuAebStat
extern uint8_t DfMemFiuAebStat;

/* 0..1 Status of AFS 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuAfsStat	DfMemFiuAfsStat
extern uint8_t DfMemFiuAfsStat;

/* 0..1 Status of ALCC  0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuAlccStat	DfMemFiuAlccStat
extern uint8_t DfMemFiuAlccStat;

/* 0..60 Overtaking speed 0x0 - 0 kmh   0x1  - 1 kmh  ...0x3C -  60 kmh intval=realval */
#define DECLARED_DfMemFiuAslaOver	DfMemFiuAslaOver
extern uint8_t DfMemFiuAslaOver;

/* 0..1 Status of ASLA 0x0 -Off   0x1 - On intval=realval */
#define DECLARED_DfMemFiuAslaStat	DfMemFiuAslaStat
extern uint8_t DfMemFiuAslaStat;

/* 0..1 Status of Assist1 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuAssistActive1Stat	DfMemFiuAssistActive1Stat
extern uint8_t DfMemFiuAssistActive1Stat;

/* 0..1 Status of Assist2 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuAssistActive2Stat	DfMemFiuAssistActive2Stat
extern uint8_t DfMemFiuAssistActive2Stat;

/* 0..1 Status of Assist3 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuAssistActive3Stat	DfMemFiuAssistActive3Stat
extern uint8_t DfMemFiuAssistActive3Stat;

/* 0..1 Status of Assist4 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuAssistActive4Stat	DfMemFiuAssistActive4Stat
extern uint8_t DfMemFiuAssistActive4Stat;

/* 0..1 Dynamics of СС  0x0 - Auto mode  0x1 - Comfort mode  0x2 - Dynamic mode intval=realval */
#define DECLARED_DfMemFiuCcMode	DfMemFiuCcMode
extern uint8_t DfMemFiuCcMode;

/* 0..1 Change of speed in a turn  0x0 - Off  0x1 - On intval=realval */
#define DECLARED_DfMemFiuCcSpdCorrect	DfMemFiuCcSpdCorrect
extern uint8_t DfMemFiuCcSpdCorrect;

/* 0..3 Type of СС 0x0 -  Off 0x1 -  CC   0x2 - ACC   0x3 - LIM intval=realval */
#define DECLARED_DfMemFiuCcType	DfMemFiuCcType
extern uint8_t DfMemFiuCcType;

/* 0..1 Sound on IC when DOW is warningReq 0x0 - OFF   0x1 - ON intval=realval */
#define DECLARED_DfMemFiuDowSound	DfMemFiuDowSound
extern uint8_t DfMemFiuDowSound;

/* 0..1 Status of DOW 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuDowStat	DfMemFiuDowStat
extern uint8_t DfMemFiuDowStat;

/* 0..2 Mode of FCW 0x0 - Early mode 0x1 - Normal mode  0x2 - Late mode intval=realval */
#define DECLARED_DfMemFiuFcwMode	DfMemFiuFcwMode
extern uint8_t DfMemFiuFcwMode;

/* 0..1 Status of FCW 0x0 - Off  0x1 - On intval=realval */
#define DECLARED_DfMemFiuFcwStat	DfMemFiuFcwStat
extern uint8_t DfMemFiuFcwStat;

/* 0..1 Vibration on steering wheel when FCW is warningReq 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuFcwVibration	DfMemFiuFcwVibration
extern uint8_t DfMemFiuFcwVibration;

/* 0..2 Mode of LCC 0x0 - Early mode  0x1 - Normal mode  0x2 - Late mode intval=realval */
#define DECLARED_DfMemFiuLccMode	DfMemFiuLccMode
extern uint8_t DfMemFiuLccMode;

/* 0..1 Sound on IC when LCC is warningReq 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuLccSound	DfMemFiuLccSound
extern uint8_t DfMemFiuLccSound;

/* 0..1 Status of LCC 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuLccStat	DfMemFiuLccStat
extern uint8_t DfMemFiuLccStat;

/* 0..1 Vibration on steering wheel when LCC is warningReq 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuLccVibration	DfMemFiuLccVibration
extern uint8_t DfMemFiuLccVibration;

/* 0..1 Status of LDP 0x0 - OFF   0x1 - ON intval=realval */
#define DECLARED_DfMemFiuLdpStat	DfMemFiuLdpStat
extern uint8_t DfMemFiuLdpStat;

/* 0..1 Mode of LDW 0x0 - before crossing  0x1 - while crossing intval=realval */
#define DECLARED_DfMemFiuLdwMode	DfMemFiuLdwMode
extern uint8_t DfMemFiuLdwMode;

/* 0..1 Sound on IC when LDW is warningReq 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuLdwSound	DfMemFiuLdwSound
extern uint8_t DfMemFiuLdwSound;

/* 0..1 Status of LDW 0x0 - OFF   0x1 - ON intval=realval */
#define DECLARED_DfMemFiuLdwStat	DfMemFiuLdwStat
extern uint8_t DfMemFiuLdwStat;

/* 0..1 Vibration on steering wheel when LDW is warningReq 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuLdwVibration	DfMemFiuLdwVibration
extern uint8_t DfMemFiuLdwVibration;

/* 0..1 Status of LKA 0x0 - Off 0x1 - On intval=realval */
#define DECLARED_DfMemFiuLkaStat	DfMemFiuLkaStat
extern uint8_t DfMemFiuLkaStat;

/* 0..1 Status of Navigation: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuNavigStat	DfMemFiuNavigStat
extern uint8_t DfMemFiuNavigStat;

/* 0..1 Status of Other Objects: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuOtherObjStat	DfMemFiuOtherObjStat
extern uint8_t DfMemFiuOtherObjStat;

/* 0..1 Status of Projection: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuProjectionOnARoadStat	DfMemFiuProjectionOnARoadStat
extern uint8_t DfMemFiuProjectionOnARoadStat;

/* 0..1 Status of RCTC 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuRctcStat	DfMemFiuRctcStat
extern uint8_t DfMemFiuRctcStat;

/* 0..3 Status of RCW 0x0 - OFF   0x1 - ON intval=realval */
#define DECLARED_DfMemFiuRcwStat	DfMemFiuRcwStat
extern uint8_t DfMemFiuRcwStat;

/* 0..1 Status of RDA Auto Brake 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuRdaAutoBrakeStat	DfMemFiuRdaAutoBrakeStat
extern uint8_t DfMemFiuRdaAutoBrakeStat;

/* 0..1 Status of RDA 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuRdaStat	DfMemFiuRdaStat
extern uint8_t DfMemFiuRdaStat;

/* 0..1 Status of REC 0x0 - OFF   0x1 - ON intval=realval */
#define DECLARED_DfMemFiuRecStat	DfMemFiuRecStat
extern uint8_t DfMemFiuRecStat;

/* 0..1 Status of Road Sign: 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuRoadSignStat	DfMemFiuRoadSignStat
extern uint8_t DfMemFiuRoadSignStat;

/* 0..1 Status of Sensor clean function 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuSensCleanStat	DfMemFiuSensCleanStat
extern uint8_t DfMemFiuSensCleanStat;

/* 0..1 Status of TSR 0x0 - OFF  0x1 - ON intval=realval */
#define DECLARED_DfMemFiuTsrStat	DfMemFiuTsrStat
extern uint8_t DfMemFiuTsrStat;

/* 0..3 Type CC-ACC-LIM from Memory. 0 - nothing, 1-CC, 2-ACC, 3-LIM intval=realval */
#define DECLARED_DfMemTypeCC	DfMemTypeCC
extern uint8_t DfMemTypeCC;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

