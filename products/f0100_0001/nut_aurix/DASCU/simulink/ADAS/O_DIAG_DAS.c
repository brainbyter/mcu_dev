/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* 0..65535 [h] Driving time beetwin 20-80 km/h intval=realval */
float DtAnalyticAccTimeCity = 0.0000000E+000;

/* 0..65535 [h] Driving time above 80 km/h intval=realval */
float DtAnalyticAccTimeHighWay = 0.0000000E+000;

/* 0..65535 [h] Driving time up to 20 km/h intval=realval */
float DtAnalyticAccTimeJam = 0.0000000E+000;

/* 0..65535 [h] Driving time distance above to 40 m intval=realval */
float DtAnalyticAccTimeMaxDist = 0.0000000E+000;

/* 0..65535 [h] Driving time distance  beetwin to 20-30 m intval=realval */
float DtAnalyticAccTimeMedDist = 0.0000000E+000;

/* 0..65535 [h] Driving time distance  beetwin to 30-40 m intval=realval */
float DtAnalyticAccTimeMedMaxDist = 0.0000000E+000;

/* 0..65535 [h] Driving time distance up to 20 m intval=realval */
float DtAnalyticAccTimeMinDist = 0.0000000E+000;

/* 0..65535 [km] Distance traveled with active function AEB intval=realval */
float DtAnalyticAebActvnDst = 0.0000000E+000;

/* 0..65535 [m] Average distance to the target when AEB is activated intval=realval */
float DtAnalyticAebAvgDistToTar = 0.0000000E+000;

/* -1..1 Stored AEB warning correction time: -1, -0.95, -0.9...1 intval=realval */
float DtAnalyticAebCorrnTiWarn = 0.0000000E+000;

/* 0..255 Number of operations AEB intval=realval */
uint8_t DtAnalyticAebNrOfOper = 0U;

/* 0..65535 [km] Distance traveled with active function ALCC intval=realval */
float DtAnalyticAlccActvnDst = 0.0000000E+000;

/* 0..65535 Number of operations ALCC intval=realval */
float DtAnalyticAlccNrOfOper = 0.0000000E+000;

/* 0..65535 [h] Driving hour on CC intval=realval */
float DtAnalyticCcTime = 0.0000000E+000;

/* -1..1 Stored DOW warning correction time: -1, -0.95, -0.9...1 intval=realval */
float DtAnalyticDowCorrnTiWarn = 0.0000000E+000;

/* 0..65535 Number of operations DOW intval=realval */
float DtAnalyticDowNrOfOper = 0.0000000E+000;

/* 0..65535 [h] Time elapsed with active function DOW intval=realval */
float DtAnalyticDowTime = 0.0000000E+000;

/* 0..65535 [km] Distance traveled with active function FCW intval=realval */
float DtAnalyticFcwActvnDst = 0.0000000E+000;

/* 0..255 Number of operations FCW intval=realval */
uint8_t DtAnalyticFcwNrOfOper = 0U;

/* 0..65535 [km] Distance traveled with active function LCC intval=realval */
float DtAnalyticLccActvnDst = 0.0000000E+000;

/* -1..1 Stored LCC warning correction time: -1, -0.95, -0.9...1 intval=realval */
float DtAnalyticLccCorrnTiWarn = 0.0000000E+000;

/* 0..65535 Number of operations LCC intval=realval */
float DtAnalyticLccNrOfOper = 0.0000000E+000;

/* 0..65535 [h] Total LDP working time (StandBy (sufficient speed) + Active) intval=realval */
float DtAnalyticLdpNumOfWarn = 0.0000000E+000;

/* 0..65535 [h] Active LDP working time intval=realval */
float DtAnalyticLdpTimeActive = 0.0000000E+000;

/* 0..65535 [h] Total LDW working time (StandBy (sufficient speed) + Active) intval=realval */
float DtAnalyticLdwNumOfWarn = 0.0000000E+000;

/* 0..65535 [h] Active LDW working time intval=realval */
float DtAnalyticLdwTimeActive = 0.0000000E+000;

/* 0..65535 [h] Active LKA working time intval=realval */
float DtAnalyticLkaTimeActive = 0.0000000E+000;

/* 0..65535 [h] Total LKA working time (StandBy (ACC active) + Active) intval=realval */
float DtAnalyticLkaTimeTotal = 0.0000000E+000;

/* 0..65535 [h] Object recognition time intval=realval */
float DtAnalyticMliaTimeObj = 0.0000000E+000;

/* 0..65535 [h] Total MLIA working time intval=realval */
float DtAnalyticMliaTimeTotal = 0.0000000E+000;

/* 0..65535 [km] Distance traveled with active function RCTC intval=realval */
float DtAnalyticRctcaActvnDst = 0.0000000E+000;

/* 0..255 [m] Average distance to the target when RCTC is activated intval=realval */
uint8_t DtAnalyticRctcAvgDistToTar = 0U;

/* 0..255 Number of operations RCTC intval=realval */
uint8_t DtAnalyticRctcNrOfOper = 0U;

/* 0..255 [m] Average distance to the target when RCW is activated intval=realval */
uint8_t DtAnalyticRcwAvgDistToTar = 0U;

/* 0..255 Number of operations RCW intval=realval */
uint8_t DtAnalyticRcwNrOfOper = 0U;

/* 0..65535 [km] Distance traveled with active function RDA intval=realval */
float DtAnalyticRdaActvnDst = 0.0000000E+000;

/* 0..65535 [m] Average distance to the target when RDA is activated intval=realval */
float DtAnalyticRdaAvgDistToTar = 0.0000000E+000;

/* -1..1 Stored RDA warning correction time: -1, -0.45, -0.4…1 intval=realval */
float DtAnalyticRdaCorrnTiWarn = 0.0000000E+000;

/* 0..65535 Number of operations RDA intval=realval */
float DtAnalyticRdaNrOfOper = 0.0000000E+000;

/* 0..255 Dtc to Diagnostic about Radar is glitch intval=realval */
uint8_t DtDiagDtcAccRadarGlitch = 0U;

/* 0..255 Dtc to Diagnostic about Radar is zero distance intval=realval */
uint8_t DtDiagDtcAccRadarZero = 0U;

/* 0..255 Dtc to Diagnostic about SWU is stuck intval=realval */
uint8_t DtDiagDtcAccSwuStuck = 0U;

/* 0..320000 Date Model of ACC intval=realval */
float DtDiagVerDateModelACC = 0.0000000E+000;

/* 0..320000 Date Model of AEB intval=realval */
float DtDiagVerDateModelAEB = 0.0000000E+000;

/* 0..320000 Date Model of AFS intval=realval */
float DtDiagVerDateModelAFS = 0.0000000E+000;

/* 0..320000 Date Model of FIU intval=realval */
float DtDiagVerDateModelFIU = 0.0000000E+000;

/* 0..320000 Date Model of LCC intval=realval */
float DtDiagVerDateModelLCC = 0.0000000E+000;

/* 0..320000 Date Model of LDP intval=realval */
float DtDiagVerDateModelLDP = 0.0000000E+000;

/* 0..320000 Date Model of LDW intval=realval */
float DtDiagVerDateModelLDW = 0.0000000E+000;

/* 0..320000 Date Model of LKA intval=realval */
float DtDiagVerDateModelLKA = 0.0000000E+000;

/* 0..320000 Date Model of MLIA intval=realval */
float DtDiagVerDateModelMLIA = 0.0000000E+000;

/* 0..320000 Date Model of RCW intval=realval */
float DtDiagVerDateModelRCW = 0.0000000E+000;

/* 0..320000 Date Model of RDA intval=realval */
float DtDiagVerDateModelRDA = 0.0000000E+000;

/* 0..320000 Date Model of AEB VISUAL intval=realval */
float DtDiagVerDateModelVisual = 0.0000000E+000;

/* 0..255 Number Model of ACC intval=realval */
uint8_t DtDiagVerNumModelACC = 0U;

/* 0..255 Number Model of AEB intval=realval */
uint8_t DtDiagVerNumModelAEB = 0U;

/* 0..255 Number Model of AFS intval=realval */
uint8_t DtDiagVerNumModelAFS = 0U;

/* 0..255 Number Model of FIU intval=realval */
uint8_t DtDiagVerNumModelFIU = 0U;

/* 0..255 Number Model of LCC intval=realval */
uint8_t DtDiagVerNumModelLCC = 0U;

/* 0..255 Number Model of LDP intval=realval */
uint8_t DtDiagVerNumModelLDP = 0U;

/* 0..255 Number Model of LDW intval=realval */
uint8_t DtDiagVerNumModelLDW = 0U;

/* 0..255 Number Model of LKA intval=realval */
uint8_t DtDiagVerNumModelLKA = 0U;

/* 0..255 Number Model of MLIA intval=realval */
uint8_t DtDiagVerNumModelMLIA = 0U;

/* 0..255 Number Model of RCW intval=realval */
uint8_t DtDiagVerNumModelRCW = 0U;

/* 0..255 Number Model of RDA intval=realval */
uint8_t DtDiagVerNumModelRDA = 0U;

/* 0..255 Number Model of VISUAL intval=realval */
uint8_t DtDiagVerNumModelVISUAL = 0U;

/* 0..255 Number Model of ADAS intval=realval */
uint8_t DtDiagVerNumSoftWare = 0U;

/* 0..400000000 [] intval=realval */
float DtLogAaEragDate = 0.0000000E+000;

/* 0..26 [] intval=realval */
float DtLogAaEragTime = 0.0000000E+000;

/* 0..12 [] intval=realval */
float DtLogAaFuzzyScore = 0.0000000E+000;

/* 0..255 [] intval=realval */
uint8_t DtLogAaSolverTrans = 0U;

/* 0..10 [] intval=realval */
float DtLogAaTimeAnalWarn = 0.0000000E+000;

/* 0..3 [] intval=realval */
uint8_t DtLogAaWarnDms = 0U;

/* 0..200 [m] Data to log about  DistReal m intval=realval */
float DtLogAccDistRealm = 0.0000000E+000;

/* 0..100 [m] Data to log about  DistSet m intval=realval */
float DtLogAccDistSetm = 0.0000000E+000;

/* 0..31 Data to log about LeadAccelReal intval=realval */
uint8_t DtLogAccErrCode = 0U;

/* 0..1 Data to log about LeadSpeedReal intval=realval */
uint8_t DtLogAccErrFlag = 0U;

/* -10..5 [m*s^2] Data to log about Accel leader intval=realval */
float DtLogAccLeadAccelReal = 0.0000000E+000;

/* -10..245 [m*s^2] Data to log about Speed leader kmh intval=realval */
float DtLogAccLeadSpeedReal_kmh = 0.0000000E+000;

/* 0..255 Data to log about SpeedIC_ intval=realval */
uint8_t DtLogAccLogicTrans = 0U;

/* 0..127 Data to log about SpeedESP intval=realval */
uint8_t DtLogAccSolverTrans = 0U;

/* 0..15 Data to log about TargetDetect flag intval=realval */
uint8_t DtLogAccTargetDetect = 0U;

/* 0..31 Data to log about VLC State intval=realval */
uint8_t DtLogAccVlcTrans = 0U;

/* 0..200 [m] [] intval=realval */
float DtLogAebDistRealm = 0.0000000E+000;

/* 0..31 [] intval=realval */
uint8_t DtLogAebErrCode = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogAebErrFlag = 0U;

/* -6..5 [m*s^2] [] intval=realval */
float DtLogAebLeadAccelReal = 0.0000000E+000;

/* -10..245 [kmh] [] intval=realval */
float DtLogAebLeadSpeedRealKmh = 0.0000000E+000;

/* 0..127 [] intval=realval */
uint8_t DtLogAebLogicTrans = 0U;

/* 0..127 [] intval=realval */
uint8_t DtLogAebSolverTrans = 0U;

/* 0..15 [] intval=realval */
uint8_t DtLogAebTargetDetect = 0U;

/* 0..1 [] intval=realval */
uint8_t DtLogAlccEnaSts = 0U;

/* 0..1 [] intval=realval */
uint8_t DtLogDowIsObjInLeftZone = 0U;

/* 0..1 [] intval=realval */
uint8_t DtLogDowIsObjInRightZone = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogDowLogicTrans = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogDowWarnReqTransLeft = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogDowWarnReqTransRight = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogFiuLogicTrans = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogFiuSolverTrans = 0U;

/* 0..1 [] intval=realval */
uint8_t DtLogLccEnaSts = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogLccErrCode = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogLccErrFlag = 0U;

/* 0..1 [] intval=realval */
uint8_t DtLogLccIsObjInLeftCvwZone = 0U;

/* 0..1 [] intval=realval */
uint8_t DtLogLccIsObjInRightCvwZone = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogLccLogicTrans = 0U;

/* 0..2 [] intval=realval */
uint8_t DtLogLccSetMode = 0U;

/* 0..1 [] intval=realval */
uint8_t DtLogLccSetSound = 0U;

/* 0..1 [] intval=realval */
uint8_t DtLogLccSetVibration = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogLccWarnReqTransLeft = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogLccWarnReqTransRight = 0U;

/* 0..31 [] intval=realval */
uint8_t DtLogLdwLogicTrans = 0U;

/* 0..31 [] intval=realval */
uint8_t DtLogLdwSolverTransLeft = 0U;

/* 0..31 [] intval=realval */
uint8_t DtLogLdwSolverTransRight = 0U;

/* 0..5 [] intval=realval */
float DtLogLdwTTLCLeft = 0.0000000E+000;

/* 0..15 [] intval=realval */
uint8_t DtLogLdwTTLCTransLeft = 0U;

/* 0..1275 [] intval=realval */
float DtLogLdwTurnRadiusLeft = 0.0000000E+000;

/* -3..3 [] intval=realval */
float DtLogLdwVdepartureLeft = 0.0000000E+000;

/* 0..15 [] intval=realval */
uint8_t DtLogLdwWarnBlockTransLeft = 0U;

/* 0..1 [] intval=realval */
uint8_t DtLogLdwWarnDistLeft = 0U;

/* 0..1 [] intval=realval */
uint8_t DtLogLdwWarnDistRight = 0U;

/* 0..1 [] intval=realval */
uint8_t DtLogLdwWarnPredictLeft = 0U;

/* 0..1 [] intval=realval */
uint8_t DtLogLdwWarnPredictRight = 0U;

/* 0..1 [] intval=realval */
uint8_t DtLogLdwWarnTimeLeft = 0U;

/* 0..1 [] intval=realval */
uint8_t DtLogLdwWarnTimeRight = 0U;

/* -10..10 [] intval=realval */
float DtLogLdwYawRate_dtLeft = 0.0000000E+000;

/* 0..255 [] intval=realval */
uint8_t DtLogLkaErrCode = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogLkaErrFlag = 0U;

/* 0..255 [deg] [] intval=realval */
uint8_t DtLogLkaLogicTrans = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogLkaSolverTrans = 0U;

/* -180..180 [deg] [] intval=realval */
float DtLogLkaTargetAngle = 0.0000000E+000;

/* 0..255 [] intval=realval */
uint8_t DtLogMliaDistToObj1 = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogMliaDistToObj2 = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogMliaDistToObj3 = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogMliaDistToObj4 = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogMliaErrCode = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogMliaErrFlag = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogMliaLogicTrans = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogMliaSolverTrans = 0U;

/* 0..255 [m] [] intval=realval */
float DtLogRcwDimanWh = 0.0000000E+000;

/* 0..255 [m] [] intval=realval */
float DtLogRcwDistToObjRear = 0.0000000E+000;

/* -255..255 [m] [] intval=realval */
float DtLogRcwLatObj = 0.0000000E+000;

/* 0..255 [] intval=realval */
uint8_t DtLogRcwLogicTrans = 0U;

/* 0..255 [] intval=realval */
float DtLogRcwTimeCrash = 0.0000000E+000;

/* 0..1 [] intval=realval */
uint8_t DtLogRcwVelRel = 0U;

/* 0..25 [] intval=realval */
float DtLogRdaDistToObjRear = 0.0000000E+000;

/* 0..255 [] intval=realval */
uint8_t DtLogRdaErrCode = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogRdaErrFlag = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogRdaLogicTrans = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogRdaSolverTrans = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogVisualErrCode = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogVisualErrFlag = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogVisualLogicTrans = 0U;

/* 0..255 [] intval=realval */
uint8_t DtLogVisualSolverTrans = 0U;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

