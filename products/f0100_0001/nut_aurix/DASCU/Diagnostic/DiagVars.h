#include "stdint.h"
#include "Platform_Types.h"

extern float DfGpuTemp;
extern uint8 DfGpuFrcuErrorSts;
extern uint8 DfGpuFcuWErrorSts;
extern uint8 DfGpuFcuNErrorSts;
extern uint8 DfGpuTicuErrorSts;
extern uint8 DfGpuLidarErrorSts;
extern float DfGpuFrcuVirtYaw;
extern float DfGpuFrcuProb;
extern uint8 DfGpuFcuCalibSts;
extern float DfGpuFcuStaticAngYaw;
extern float DfGpuFcuStaticAngPitch;
extern float DfGpuFcuVirtYaw;
extern uint8 DfGpuTicuCalibSts;
extern float DfGpuTicuVirtYaw;
extern float DfGpuTicuStaticYaw;
extern float DfGpuTicuStaticPitch;
extern uint8 DfGpuLidCalibSts;
extern float DfGpuLidVirtYaw;
extern float DfGpuLidStaticYaw;
extern float DfGpuLidStaticPitch;

extern uint8 McuDiagSession;
extern uint8 McuFrcuInstalSts;
extern uint8 McuFcuInstalSts;
extern uint8 McuTicuInstalSts;
extern uint8 McuLidarInstalSts;
extern uint8 McuRrInstalSts;
extern uint8 McuRRCalibSts;
extern float McuRRL_AngVal;
extern float McuRRR_AngVal;
extern uint8 McuRRErrorSts;
extern uint8 McuFrcuVirtAngReset;
extern uint8 McuFrcuGetImg;
extern uint8 McuFrcuAngRead;
extern uint8 McuFcuVirtAngReset;
extern float McuFcuSetYawfAngle;
extern float McuFcuSetPitchAngle;
extern uint8 McuFcuCalibStart;
extern uint8 McuFcuCalibStop;
extern uint8 McuFcuGetWideImg;
extern uint8 McuFcuGetNarrImg;
extern uint8 McuTicuCalibStart;
extern uint8 McuTicuCalibStop;
extern uint8 McuTicuGetThermImg;
extern uint8 McuLidCalibStart;
extern uint8 McuLidCalibStop;
extern uint8 McuLidGetLidarImg;

//extern uint8 FanSpeedReq;



extern uint8 DfDiagFrontRadarAvail;
extern uint8 DfDiagThermalCameraAvail;
extern uint8 DfDiagLidarAvail;
extern uint8 DfDiagRearRadarAvail;
extern uint8 DfDiagRearSteeringActuatorAvail;


extern uint8 SettRecResol;
extern uint8 SettRecFileSize;

extern unsigned char step_counter;
extern unsigned char get_req;
extern unsigned char temp_REQ_GPU_FrcuVirtAngReset;
extern unsigned char temp_REQ_GPU_FrcuGetImg;
extern unsigned char temp_REQ_GPU_FcuVirtAngReset;
extern float temp_REQ_GPU_FcuSetYawAngle;
extern float temp_REQ_GPU_FcuSetPitchAngle;
extern unsigned char temp_REQ_GPU_FcuCalibStart;
extern unsigned char temp_REQ_GPU_FcuCalibStop;
extern unsigned char temp_REQ_GPU_FcuGetWideImg;
extern unsigned char temp_REQ_GPU_FcuGetNarrowImg;
extern unsigned char temp_REQ_GPU_TicuCalibStart;
extern unsigned char temp_REQ_GPU_TicuCalibStop;
extern unsigned char temp_REQ_GPU_TicuGetImg;
extern unsigned char temp_REQ_GPU_LidCalibStart;
extern unsigned char temp_REQ_GPU_LidCalibStop;
extern unsigned char temp_REQ_GPU_LidGetImg;

extern uint8_t TD_PercStartMlia;
extern uint8_t TD_PercStartFrontPasObj;
extern uint8_t TD_PercStartFrontOncomObj;
extern uint8_t TD_PercStartSign;
extern uint8_t TD_PercStartLane;
extern uint8_t TD_PercStartRearObj;

//extern unsigned char DfMemAaStTest;

