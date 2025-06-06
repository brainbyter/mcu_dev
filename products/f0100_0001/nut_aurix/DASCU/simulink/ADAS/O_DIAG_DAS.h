/* includes */
/* include directives and so on at begin of file */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIGNALS */
/* all signals' header; (section definitions, #pragma, etc.) */


/* 0..65535 [h] Driving time beetwin 20-80 km/h intval=realval */
#define DECLARED_DtAnalyticAccTimeCity	DtAnalyticAccTimeCity
extern float DtAnalyticAccTimeCity;

/* 0..65535 [h] Driving time above 80 km/h intval=realval */
#define DECLARED_DtAnalyticAccTimeHighWay	DtAnalyticAccTimeHighWay
extern float DtAnalyticAccTimeHighWay;

/* 0..65535 [h] Driving time up to 20 km/h intval=realval */
#define DECLARED_DtAnalyticAccTimeJam	DtAnalyticAccTimeJam
extern float DtAnalyticAccTimeJam;

/* 0..65535 [h] Driving time distance above to 40 m intval=realval */
#define DECLARED_DtAnalyticAccTimeMaxDist	DtAnalyticAccTimeMaxDist
extern float DtAnalyticAccTimeMaxDist;

/* 0..65535 [h] Driving time distance  beetwin to 20-30 m intval=realval */
#define DECLARED_DtAnalyticAccTimeMedDist	DtAnalyticAccTimeMedDist
extern float DtAnalyticAccTimeMedDist;

/* 0..65535 [h] Driving time distance  beetwin to 30-40 m intval=realval */
#define DECLARED_DtAnalyticAccTimeMedMaxDist	DtAnalyticAccTimeMedMaxDist
extern float DtAnalyticAccTimeMedMaxDist;

/* 0..65535 [h] Driving time distance up to 20 m intval=realval */
#define DECLARED_DtAnalyticAccTimeMinDist	DtAnalyticAccTimeMinDist
extern float DtAnalyticAccTimeMinDist;

/* 0..65535 [km] Distance traveled with active function AEB intval=realval */
#define DECLARED_DtAnalyticAebActvnDst	DtAnalyticAebActvnDst
extern float DtAnalyticAebActvnDst;

/* 0..65535 [m] Average distance to the target when AEB is activated intval=realval */
#define DECLARED_DtAnalyticAebAvgDistToTar	DtAnalyticAebAvgDistToTar
extern float DtAnalyticAebAvgDistToTar;

/* -1..1 Stored AEB warning correction time: -1, -0.95, -0.9...1 intval=realval */
#define DECLARED_DtAnalyticAebCorrnTiWarn	DtAnalyticAebCorrnTiWarn
extern float DtAnalyticAebCorrnTiWarn;

/* 0..255 Number of operations AEB intval=realval */
#define DECLARED_DtAnalyticAebNrOfOper	DtAnalyticAebNrOfOper
extern uint8_t DtAnalyticAebNrOfOper;

/* 0..65535 [km] Distance traveled with active function ALCC intval=realval */
#define DECLARED_DtAnalyticAlccActvnDst	DtAnalyticAlccActvnDst
extern float DtAnalyticAlccActvnDst;

/* 0..65535 Number of operations ALCC intval=realval */
#define DECLARED_DtAnalyticAlccNrOfOper	DtAnalyticAlccNrOfOper
extern float DtAnalyticAlccNrOfOper;

/* 0..65535 [h] Driving hour on CC intval=realval */
#define DECLARED_DtAnalyticCcTime	DtAnalyticCcTime
extern float DtAnalyticCcTime;

/* -1..1 Stored DOW warning correction time: -1, -0.95, -0.9...1 intval=realval */
#define DECLARED_DtAnalyticDowCorrnTiWarn	DtAnalyticDowCorrnTiWarn
extern float DtAnalyticDowCorrnTiWarn;

/* 0..65535 Number of operations DOW intval=realval */
#define DECLARED_DtAnalyticDowNrOfOper	DtAnalyticDowNrOfOper
extern float DtAnalyticDowNrOfOper;

/* 0..65535 [h] Time elapsed with active function DOW intval=realval */
#define DECLARED_DtAnalyticDowTime	DtAnalyticDowTime
extern float DtAnalyticDowTime;

/* 0..65535 [km] Distance traveled with active function FCW intval=realval */
#define DECLARED_DtAnalyticFcwActvnDst	DtAnalyticFcwActvnDst
extern float DtAnalyticFcwActvnDst;

/* 0..255 Number of operations FCW intval=realval */
#define DECLARED_DtAnalyticFcwNrOfOper	DtAnalyticFcwNrOfOper
extern uint8_t DtAnalyticFcwNrOfOper;

/* 0..65535 [km] Distance traveled with active function LCC intval=realval */
#define DECLARED_DtAnalyticLccActvnDst	DtAnalyticLccActvnDst
extern float DtAnalyticLccActvnDst;

/* -1..1 Stored LCC warning correction time: -1, -0.95, -0.9...1 intval=realval */
#define DECLARED_DtAnalyticLccCorrnTiWarn	DtAnalyticLccCorrnTiWarn
extern float DtAnalyticLccCorrnTiWarn;

/* 0..65535 Number of operations LCC intval=realval */
#define DECLARED_DtAnalyticLccNrOfOper	DtAnalyticLccNrOfOper
extern float DtAnalyticLccNrOfOper;

/* 0..65535 [h] Total LDP working time (StandBy (sufficient speed) + Active) intval=realval */
#define DECLARED_DtAnalyticLdpNumOfWarn	DtAnalyticLdpNumOfWarn
extern float DtAnalyticLdpNumOfWarn;

/* 0..65535 [h] Active LDP working time intval=realval */
#define DECLARED_DtAnalyticLdpTimeActive	DtAnalyticLdpTimeActive
extern float DtAnalyticLdpTimeActive;

/* 0..65535 [h] Total LDW working time (StandBy (sufficient speed) + Active) intval=realval */
#define DECLARED_DtAnalyticLdwNumOfWarn	DtAnalyticLdwNumOfWarn
extern float DtAnalyticLdwNumOfWarn;

/* 0..65535 [h] Active LDW working time intval=realval */
#define DECLARED_DtAnalyticLdwTimeActive	DtAnalyticLdwTimeActive
extern float DtAnalyticLdwTimeActive;

/* 0..65535 [h] Active LKA working time intval=realval */
#define DECLARED_DtAnalyticLkaTimeActive	DtAnalyticLkaTimeActive
extern float DtAnalyticLkaTimeActive;

/* 0..65535 [h] Total LKA working time (StandBy (ACC active) + Active) intval=realval */
#define DECLARED_DtAnalyticLkaTimeTotal	DtAnalyticLkaTimeTotal
extern float DtAnalyticLkaTimeTotal;

/* 0..65535 [h] Object recognition time intval=realval */
#define DECLARED_DtAnalyticMliaTimeObj	DtAnalyticMliaTimeObj
extern float DtAnalyticMliaTimeObj;

/* 0..65535 [h] Total MLIA working time intval=realval */
#define DECLARED_DtAnalyticMliaTimeTotal	DtAnalyticMliaTimeTotal
extern float DtAnalyticMliaTimeTotal;

/* 0..65535 [km] Distance traveled with active function RCTC intval=realval */
#define DECLARED_DtAnalyticRctcaActvnDst	DtAnalyticRctcaActvnDst
extern float DtAnalyticRctcaActvnDst;

/* 0..255 [m] Average distance to the target when RCTC is activated intval=realval */
#define DECLARED_DtAnalyticRctcAvgDistToTar	DtAnalyticRctcAvgDistToTar
extern uint8_t DtAnalyticRctcAvgDistToTar;

/* 0..255 Number of operations RCTC intval=realval */
#define DECLARED_DtAnalyticRctcNrOfOper	DtAnalyticRctcNrOfOper
extern uint8_t DtAnalyticRctcNrOfOper;

/* 0..255 [m] Average distance to the target when RCW is activated intval=realval */
#define DECLARED_DtAnalyticRcwAvgDistToTar	DtAnalyticRcwAvgDistToTar
extern uint8_t DtAnalyticRcwAvgDistToTar;

/* 0..255 Number of operations RCW intval=realval */
#define DECLARED_DtAnalyticRcwNrOfOper	DtAnalyticRcwNrOfOper
extern uint8_t DtAnalyticRcwNrOfOper;

/* 0..65535 [km] Distance traveled with active function RDA intval=realval */
#define DECLARED_DtAnalyticRdaActvnDst	DtAnalyticRdaActvnDst
extern float DtAnalyticRdaActvnDst;

/* 0..65535 [m] Average distance to the target when RDA is activated intval=realval */
#define DECLARED_DtAnalyticRdaAvgDistToTar	DtAnalyticRdaAvgDistToTar
extern float DtAnalyticRdaAvgDistToTar;

/* -1..1 Stored RDA warning correction time: -1, -0.45, -0.4…1 intval=realval */
#define DECLARED_DtAnalyticRdaCorrnTiWarn	DtAnalyticRdaCorrnTiWarn
extern float DtAnalyticRdaCorrnTiWarn;

/* 0..65535 Number of operations RDA intval=realval */
#define DECLARED_DtAnalyticRdaNrOfOper	DtAnalyticRdaNrOfOper
extern float DtAnalyticRdaNrOfOper;

/* 0..255 Dtc to Diagnostic about Radar is glitch intval=realval */
#define DECLARED_DtDiagDtcAccRadarGlitch	DtDiagDtcAccRadarGlitch
extern uint8_t DtDiagDtcAccRadarGlitch;

/* 0..255 Dtc to Diagnostic about Radar is zero distance intval=realval */
#define DECLARED_DtDiagDtcAccRadarZero	DtDiagDtcAccRadarZero
extern uint8_t DtDiagDtcAccRadarZero;

/* 0..255 Dtc to Diagnostic about SWU is stuck intval=realval */
#define DECLARED_DtDiagDtcAccSwuStuck	DtDiagDtcAccSwuStuck
extern uint8_t DtDiagDtcAccSwuStuck;

/* 0..320000 Date Model of ACC intval=realval */
#define DECLARED_DtDiagVerDateModelACC	DtDiagVerDateModelACC
extern float DtDiagVerDateModelACC;

/* 0..320000 Date Model of AEB intval=realval */
#define DECLARED_DtDiagVerDateModelAEB	DtDiagVerDateModelAEB
extern float DtDiagVerDateModelAEB;

/* 0..320000 Date Model of AFS intval=realval */
#define DECLARED_DtDiagVerDateModelAFS	DtDiagVerDateModelAFS
extern float DtDiagVerDateModelAFS;

/* 0..320000 Date Model of FIU intval=realval */
#define DECLARED_DtDiagVerDateModelFIU	DtDiagVerDateModelFIU
extern float DtDiagVerDateModelFIU;

/* 0..320000 Date Model of LCC intval=realval */
#define DECLARED_DtDiagVerDateModelLCC	DtDiagVerDateModelLCC
extern float DtDiagVerDateModelLCC;

/* 0..320000 Date Model of LDP intval=realval */
#define DECLARED_DtDiagVerDateModelLDP	DtDiagVerDateModelLDP
extern float DtDiagVerDateModelLDP;

/* 0..320000 Date Model of LDW intval=realval */
#define DECLARED_DtDiagVerDateModelLDW	DtDiagVerDateModelLDW
extern float DtDiagVerDateModelLDW;

/* 0..320000 Date Model of LKA intval=realval */
#define DECLARED_DtDiagVerDateModelLKA	DtDiagVerDateModelLKA
extern float DtDiagVerDateModelLKA;

/* 0..320000 Date Model of MLIA intval=realval */
#define DECLARED_DtDiagVerDateModelMLIA	DtDiagVerDateModelMLIA
extern float DtDiagVerDateModelMLIA;

/* 0..320000 Date Model of RCW intval=realval */
#define DECLARED_DtDiagVerDateModelRCW	DtDiagVerDateModelRCW
extern float DtDiagVerDateModelRCW;

/* 0..320000 Date Model of RDA intval=realval */
#define DECLARED_DtDiagVerDateModelRDA	DtDiagVerDateModelRDA
extern float DtDiagVerDateModelRDA;

/* 0..320000 Date Model of AEB VISUAL intval=realval */
#define DECLARED_DtDiagVerDateModelVisual	DtDiagVerDateModelVisual
extern float DtDiagVerDateModelVisual;

/* 0..255 Number Model of ACC intval=realval */
#define DECLARED_DtDiagVerNumModelACC	DtDiagVerNumModelACC
extern uint8_t DtDiagVerNumModelACC;

/* 0..255 Number Model of AEB intval=realval */
#define DECLARED_DtDiagVerNumModelAEB	DtDiagVerNumModelAEB
extern uint8_t DtDiagVerNumModelAEB;

/* 0..255 Number Model of AFS intval=realval */
#define DECLARED_DtDiagVerNumModelAFS	DtDiagVerNumModelAFS
extern uint8_t DtDiagVerNumModelAFS;

/* 0..255 Number Model of FIU intval=realval */
#define DECLARED_DtDiagVerNumModelFIU	DtDiagVerNumModelFIU
extern uint8_t DtDiagVerNumModelFIU;

/* 0..255 Number Model of LCC intval=realval */
#define DECLARED_DtDiagVerNumModelLCC	DtDiagVerNumModelLCC
extern uint8_t DtDiagVerNumModelLCC;

/* 0..255 Number Model of LDP intval=realval */
#define DECLARED_DtDiagVerNumModelLDP	DtDiagVerNumModelLDP
extern uint8_t DtDiagVerNumModelLDP;

/* 0..255 Number Model of LDW intval=realval */
#define DECLARED_DtDiagVerNumModelLDW	DtDiagVerNumModelLDW
extern uint8_t DtDiagVerNumModelLDW;

/* 0..255 Number Model of LKA intval=realval */
#define DECLARED_DtDiagVerNumModelLKA	DtDiagVerNumModelLKA
extern uint8_t DtDiagVerNumModelLKA;

/* 0..255 Number Model of MLIA intval=realval */
#define DECLARED_DtDiagVerNumModelMLIA	DtDiagVerNumModelMLIA
extern uint8_t DtDiagVerNumModelMLIA;

/* 0..255 Number Model of RCW intval=realval */
#define DECLARED_DtDiagVerNumModelRCW	DtDiagVerNumModelRCW
extern uint8_t DtDiagVerNumModelRCW;

/* 0..255 Number Model of RDA intval=realval */
#define DECLARED_DtDiagVerNumModelRDA	DtDiagVerNumModelRDA
extern uint8_t DtDiagVerNumModelRDA;

/* 0..255 Number Model of VISUAL intval=realval */
#define DECLARED_DtDiagVerNumModelVISUAL	DtDiagVerNumModelVISUAL
extern uint8_t DtDiagVerNumModelVISUAL;

/* 0..255 Number Model of ADAS intval=realval */
#define DECLARED_DtDiagVerNumSoftWare	DtDiagVerNumSoftWare
extern uint8_t DtDiagVerNumSoftWare;

/* 0..400000000 [] intval=realval */
#define DECLARED_DtLogAaEragDate	DtLogAaEragDate
extern float DtLogAaEragDate;

/* 0..26 [] intval=realval */
#define DECLARED_DtLogAaEragTime	DtLogAaEragTime
extern float DtLogAaEragTime;

/* 0..12 [] intval=realval */
#define DECLARED_DtLogAaFuzzyScore	DtLogAaFuzzyScore
extern float DtLogAaFuzzyScore;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogAaSolverTrans	DtLogAaSolverTrans
extern uint8_t DtLogAaSolverTrans;

/* 0..10 [] intval=realval */
#define DECLARED_DtLogAaTimeAnalWarn	DtLogAaTimeAnalWarn
extern float DtLogAaTimeAnalWarn;

/* 0..3 [] intval=realval */
#define DECLARED_DtLogAaWarnDms	DtLogAaWarnDms
extern uint8_t DtLogAaWarnDms;

/* 0..200 [m] Data to log about  DistReal m intval=realval */
#define DECLARED_DtLogAccDistRealm	DtLogAccDistRealm
extern float DtLogAccDistRealm;

/* 0..100 [m] Data to log about  DistSet m intval=realval */
#define DECLARED_DtLogAccDistSetm	DtLogAccDistSetm
extern float DtLogAccDistSetm;

/* 0..31 Data to log about LeadAccelReal intval=realval */
#define DECLARED_DtLogAccErrCode	DtLogAccErrCode
extern uint8_t DtLogAccErrCode;

/* 0..1 Data to log about LeadSpeedReal intval=realval */
#define DECLARED_DtLogAccErrFlag	DtLogAccErrFlag
extern uint8_t DtLogAccErrFlag;

/* -10..5 [m*s^2] Data to log about Accel leader intval=realval */
#define DECLARED_DtLogAccLeadAccelReal	DtLogAccLeadAccelReal
extern float DtLogAccLeadAccelReal;

/* -10..245 [m*s^2] Data to log about Speed leader kmh intval=realval */
#define DECLARED_DtLogAccLeadSpeedReal_kmh	DtLogAccLeadSpeedReal_kmh
extern float DtLogAccLeadSpeedReal_kmh;

/* 0..255 Data to log about SpeedIC_ intval=realval */
#define DECLARED_DtLogAccLogicTrans	DtLogAccLogicTrans
extern uint8_t DtLogAccLogicTrans;

/* 0..127 Data to log about SpeedESP intval=realval */
#define DECLARED_DtLogAccSolverTrans	DtLogAccSolverTrans
extern uint8_t DtLogAccSolverTrans;

/* 0..15 Data to log about TargetDetect flag intval=realval */
#define DECLARED_DtLogAccTargetDetect	DtLogAccTargetDetect
extern uint8_t DtLogAccTargetDetect;

/* 0..31 Data to log about VLC State intval=realval */
#define DECLARED_DtLogAccVlcTrans	DtLogAccVlcTrans
extern uint8_t DtLogAccVlcTrans;

/* 0..200 [m] [] intval=realval */
#define DECLARED_DtLogAebDistRealm	DtLogAebDistRealm
extern float DtLogAebDistRealm;

/* 0..31 [] intval=realval */
#define DECLARED_DtLogAebErrCode	DtLogAebErrCode
extern uint8_t DtLogAebErrCode;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogAebErrFlag	DtLogAebErrFlag
extern uint8_t DtLogAebErrFlag;

/* -6..5 [m*s^2] [] intval=realval */
#define DECLARED_DtLogAebLeadAccelReal	DtLogAebLeadAccelReal
extern float DtLogAebLeadAccelReal;

/* -10..245 [kmh] [] intval=realval */
#define DECLARED_DtLogAebLeadSpeedRealKmh	DtLogAebLeadSpeedRealKmh
extern float DtLogAebLeadSpeedRealKmh;

/* 0..127 [] intval=realval */
#define DECLARED_DtLogAebLogicTrans	DtLogAebLogicTrans
extern uint8_t DtLogAebLogicTrans;

/* 0..127 [] intval=realval */
#define DECLARED_DtLogAebSolverTrans	DtLogAebSolverTrans
extern uint8_t DtLogAebSolverTrans;

/* 0..15 [] intval=realval */
#define DECLARED_DtLogAebTargetDetect	DtLogAebTargetDetect
extern uint8_t DtLogAebTargetDetect;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogAlccEnaSts	DtLogAlccEnaSts
extern uint8_t DtLogAlccEnaSts;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogDowIsObjInLeftZone	DtLogDowIsObjInLeftZone
extern uint8_t DtLogDowIsObjInLeftZone;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogDowIsObjInRightZone	DtLogDowIsObjInRightZone
extern uint8_t DtLogDowIsObjInRightZone;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogDowLogicTrans	DtLogDowLogicTrans
extern uint8_t DtLogDowLogicTrans;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogDowWarnReqTransLeft	DtLogDowWarnReqTransLeft
extern uint8_t DtLogDowWarnReqTransLeft;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogDowWarnReqTransRight	DtLogDowWarnReqTransRight
extern uint8_t DtLogDowWarnReqTransRight;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogFiuLogicTrans	DtLogFiuLogicTrans
extern uint8_t DtLogFiuLogicTrans;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogFiuSolverTrans	DtLogFiuSolverTrans
extern uint8_t DtLogFiuSolverTrans;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogLccEnaSts	DtLogLccEnaSts
extern uint8_t DtLogLccEnaSts;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogLccErrCode	DtLogLccErrCode
extern uint8_t DtLogLccErrCode;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogLccErrFlag	DtLogLccErrFlag
extern uint8_t DtLogLccErrFlag;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogLccIsObjInLeftCvwZone	DtLogLccIsObjInLeftCvwZone
extern uint8_t DtLogLccIsObjInLeftCvwZone;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogLccIsObjInRightCvwZone	DtLogLccIsObjInRightCvwZone
extern uint8_t DtLogLccIsObjInRightCvwZone;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogLccLogicTrans	DtLogLccLogicTrans
extern uint8_t DtLogLccLogicTrans;

/* 0..2 [] intval=realval */
#define DECLARED_DtLogLccSetMode	DtLogLccSetMode
extern uint8_t DtLogLccSetMode;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogLccSetSound	DtLogLccSetSound
extern uint8_t DtLogLccSetSound;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogLccSetVibration	DtLogLccSetVibration
extern uint8_t DtLogLccSetVibration;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogLccWarnReqTransLeft	DtLogLccWarnReqTransLeft
extern uint8_t DtLogLccWarnReqTransLeft;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogLccWarnReqTransRight	DtLogLccWarnReqTransRight
extern uint8_t DtLogLccWarnReqTransRight;

/* 0..31 [] intval=realval */
#define DECLARED_DtLogLdwLogicTrans	DtLogLdwLogicTrans
extern uint8_t DtLogLdwLogicTrans;

/* 0..31 [] intval=realval */
#define DECLARED_DtLogLdwSolverTransLeft	DtLogLdwSolverTransLeft
extern uint8_t DtLogLdwSolverTransLeft;

/* 0..31 [] intval=realval */
#define DECLARED_DtLogLdwSolverTransRight	DtLogLdwSolverTransRight
extern uint8_t DtLogLdwSolverTransRight;

/* 0..5 [] intval=realval */
#define DECLARED_DtLogLdwTTLCLeft	DtLogLdwTTLCLeft
extern float DtLogLdwTTLCLeft;

/* 0..15 [] intval=realval */
#define DECLARED_DtLogLdwTTLCTransLeft	DtLogLdwTTLCTransLeft
extern uint8_t DtLogLdwTTLCTransLeft;

/* 0..1275 [] intval=realval */
#define DECLARED_DtLogLdwTurnRadiusLeft	DtLogLdwTurnRadiusLeft
extern float DtLogLdwTurnRadiusLeft;

/* -3..3 [] intval=realval */
#define DECLARED_DtLogLdwVdepartureLeft	DtLogLdwVdepartureLeft
extern float DtLogLdwVdepartureLeft;

/* 0..15 [] intval=realval */
#define DECLARED_DtLogLdwWarnBlockTransLeft	DtLogLdwWarnBlockTransLeft
extern uint8_t DtLogLdwWarnBlockTransLeft;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogLdwWarnDistLeft	DtLogLdwWarnDistLeft
extern uint8_t DtLogLdwWarnDistLeft;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogLdwWarnDistRight	DtLogLdwWarnDistRight
extern uint8_t DtLogLdwWarnDistRight;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogLdwWarnPredictLeft	DtLogLdwWarnPredictLeft
extern uint8_t DtLogLdwWarnPredictLeft;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogLdwWarnPredictRight	DtLogLdwWarnPredictRight
extern uint8_t DtLogLdwWarnPredictRight;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogLdwWarnTimeLeft	DtLogLdwWarnTimeLeft
extern uint8_t DtLogLdwWarnTimeLeft;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogLdwWarnTimeRight	DtLogLdwWarnTimeRight
extern uint8_t DtLogLdwWarnTimeRight;

/* -10..10 [] intval=realval */
#define DECLARED_DtLogLdwYawRate_dtLeft	DtLogLdwYawRate_dtLeft
extern float DtLogLdwYawRate_dtLeft;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogLkaErrCode	DtLogLkaErrCode
extern uint8_t DtLogLkaErrCode;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogLkaErrFlag	DtLogLkaErrFlag
extern uint8_t DtLogLkaErrFlag;

/* 0..255 [deg] [] intval=realval */
#define DECLARED_DtLogLkaLogicTrans	DtLogLkaLogicTrans
extern uint8_t DtLogLkaLogicTrans;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogLkaSolverTrans	DtLogLkaSolverTrans
extern uint8_t DtLogLkaSolverTrans;

/* -180..180 [deg] [] intval=realval */
#define DECLARED_DtLogLkaTargetAngle	DtLogLkaTargetAngle
extern float DtLogLkaTargetAngle;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogMliaDistToObj1	DtLogMliaDistToObj1
extern uint8_t DtLogMliaDistToObj1;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogMliaDistToObj2	DtLogMliaDistToObj2
extern uint8_t DtLogMliaDistToObj2;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogMliaDistToObj3	DtLogMliaDistToObj3
extern uint8_t DtLogMliaDistToObj3;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogMliaDistToObj4	DtLogMliaDistToObj4
extern uint8_t DtLogMliaDistToObj4;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogMliaErrCode	DtLogMliaErrCode
extern uint8_t DtLogMliaErrCode;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogMliaErrFlag	DtLogMliaErrFlag
extern uint8_t DtLogMliaErrFlag;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogMliaLogicTrans	DtLogMliaLogicTrans
extern uint8_t DtLogMliaLogicTrans;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogMliaSolverTrans	DtLogMliaSolverTrans
extern uint8_t DtLogMliaSolverTrans;

/* 0..255 [m] [] intval=realval */
#define DECLARED_DtLogRcwDimanWh	DtLogRcwDimanWh
extern float DtLogRcwDimanWh;

/* 0..255 [m] [] intval=realval */
#define DECLARED_DtLogRcwDistToObjRear	DtLogRcwDistToObjRear
extern float DtLogRcwDistToObjRear;

/* -255..255 [m] [] intval=realval */
#define DECLARED_DtLogRcwLatObj	DtLogRcwLatObj
extern float DtLogRcwLatObj;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogRcwLogicTrans	DtLogRcwLogicTrans
extern uint8_t DtLogRcwLogicTrans;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogRcwTimeCrash	DtLogRcwTimeCrash
extern float DtLogRcwTimeCrash;

/* 0..1 [] intval=realval */
#define DECLARED_DtLogRcwVelRel	DtLogRcwVelRel
extern uint8_t DtLogRcwVelRel;

/* 0..25 [] intval=realval */
#define DECLARED_DtLogRdaDistToObjRear	DtLogRdaDistToObjRear
extern float DtLogRdaDistToObjRear;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogRdaErrCode	DtLogRdaErrCode
extern uint8_t DtLogRdaErrCode;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogRdaErrFlag	DtLogRdaErrFlag
extern uint8_t DtLogRdaErrFlag;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogRdaLogicTrans	DtLogRdaLogicTrans
extern uint8_t DtLogRdaLogicTrans;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogRdaSolverTrans	DtLogRdaSolverTrans
extern uint8_t DtLogRdaSolverTrans;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogVisualErrCode	DtLogVisualErrCode
extern uint8_t DtLogVisualErrCode;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogVisualErrFlag	DtLogVisualErrFlag
extern uint8_t DtLogVisualErrFlag;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogVisualLogicTrans	DtLogVisualLogicTrans
extern uint8_t DtLogVisualLogicTrans;

/* 0..255 [] intval=realval */
#define DECLARED_DtLogVisualSolverTrans	DtLogVisualSolverTrans
extern uint8_t DtLogVisualSolverTrans;

/* all signals' footer */

/* PARAMETERS */
/* all parameters' header; (section definitions, #pragma, etc.) */

/* all parameters' footer */

#ifdef __cplusplus
}
#endif

