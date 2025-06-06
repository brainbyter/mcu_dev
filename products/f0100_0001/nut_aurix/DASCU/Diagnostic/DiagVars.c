#include "DiagVars.h"

float DfGpuTemp;
uint8 DfGpuFrcuErrorSts;
uint8 DfGpuFcuWErrorSts;
uint8 DfGpuFcuNErrorSts;
uint8 DfGpuTicuErrorSts;
uint8 DfGpuLidarErrorSts;
float DfGpuFrcuVirtYaw;
float DfGpuFrcuProb;
uint8 DfGpuFcuCalibSts;
float DfGpuFcuStaticAngYaw;
float DfGpuFcuStaticAngPitch;
float DfGpuFcuVirtYaw;
uint8 DfGpuTicuCalibSts;
float DfGpuTicuVirtYaw;
float DfGpuTicuStaticYaw;
float DfGpuTicuStaticPitch;
uint8 DfGpuLidCalibSts;
float DfGpuLidVirtYaw;
float DfGpuLidStaticYaw;
float DfGpuLidStaticPitch;

uint8 McuDiagSession;
uint8 McuFrcuInstalSts;
uint8 McuFcuInstalSts;
uint8 McuTicuInstalSts;
uint8 McuLidarInstalSts;
uint8 McuRrInstalSts;

uint8 McuRRCalibSts;
float McuRRL_AngVal;
float McuRRR_AngVal;
uint8 McuRRErrorSts;
uint8 McuFrcuVirtAngReset;
uint8 McuFrcuGetImg;
uint8 McuFrcuAngRead;
uint8 McuFcuVirtAngReset;
float McuFcuSetYawfAngle;
float McuFcuSetPitchAngle;
uint8 McuFcuCalibStart;
uint8 McuFcuCalibStop;
uint8 McuFcuGetWideImg;
uint8 McuFcuGetNarrImg;
uint8 McuTicuCalibStart;
uint8 McuTicuCalibStop;
uint8 McuTicuGetThermImg;
uint8 McuLidCalibStart;
uint8 McuLidCalibStop;
uint8 McuLidGetLidarImg;


uint8 SettRecResol;
uint8 SettRecFileSize;

unsigned char step_counter;
unsigned char get_req;
unsigned char temp_REQ_GPU_FrcuVirtAngReset;
unsigned char temp_REQ_GPU_FrcuGetImg;
unsigned char temp_REQ_GPU_FcuVirtAngReset;
float temp_REQ_GPU_FcuSetYawAngle;
float temp_REQ_GPU_FcuSetPitchAngle;
unsigned char temp_REQ_GPU_FcuCalibStart;
unsigned char temp_REQ_GPU_FcuCalibStop;
unsigned char temp_REQ_GPU_FcuGetWideImg;
unsigned char temp_REQ_GPU_FcuGetNarrowImg;
unsigned char temp_REQ_GPU_TicuCalibStart;
unsigned char temp_REQ_GPU_TicuCalibStop;
unsigned char temp_REQ_GPU_TicuGetImg;
unsigned char temp_REQ_GPU_LidCalibStart;
unsigned char temp_REQ_GPU_LidCalibStop;
unsigned char temp_REQ_GPU_LidGetImg;

//unsigned char DfMemAaStTest;
