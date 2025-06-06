#include <UDP_PostSettings.h>
#include <sw_version.h>

#define AURUS
//#define HAVAL

#include <UDP_Extern_vars.h>
#include <UdpMessageObjects.h>
#include <FD_Vars.h>
#include <ADASCANFD_Vars.h>
#include <DiagVars.h>
#include <O_PERC_DAS.h>
#include <I_PERC_DAS.h>
#include <UDP_Extern.h>

void UDP_PostSettings()
{
	UDP_Diag_Calibration_MO.prepareHandler = Prepare_UDP_Diag_Calibration_Mod;
	UDP_Main_Start_MO.handler = UDP_Main_Start_Handler_Mod;
	UDP_BCM_VehState_MO.handler = UDP_BCM_VehState_Handler_Mod;
	//UDP_MainDataFromPerc_MO.handler = UDP_MainDataFromPerc_Handler_Mod;
	//UDP_FanSpeedControl_MO.prepareHandler = Prepare_UDP_FanSpeedControl_Mod;
}

/*
void Prepare_UDP_FanSpeedControl_Mod()
{
    UDP_FanSpeedControl_RC++;
    FanSpeedReq = REQ_GPU_FanSpeedReq;
}
*/

void Prepare_UDP_Diag_Calibration_Mod()
{
    UDP_Diag_Calibration_RC++;

    if (get_req == 1)
    {
    	if (--step_counter <= 0)
    	{
    		temp_REQ_GPU_FrcuVirtAngReset = 0;
    		temp_REQ_GPU_FrcuGetImg = 0;
    		temp_REQ_GPU_FcuVirtAngReset = 0;
    		temp_REQ_GPU_FcuSetYawAngle = 0;
    		temp_REQ_GPU_FcuSetPitchAngle = 0;
    		temp_REQ_GPU_FcuCalibStart = 0;
    		temp_REQ_GPU_FcuCalibStop = 0;
    		temp_REQ_GPU_FcuGetWideImg = 0;
    		temp_REQ_GPU_FcuGetNarrowImg = 0;
    		temp_REQ_GPU_TicuCalibStart = 0;
    		temp_REQ_GPU_TicuCalibStop = 0;
    		temp_REQ_GPU_TicuGetImg = 0;
    		temp_REQ_GPU_LidCalibStart = 0;
    		temp_REQ_GPU_LidCalibStop = 0;
    		temp_REQ_GPU_LidGetImg = 0;

    		get_req = 0;
    	}
    }
    else if (get_req == 0 && \
    		 (REQ_GPU_FcuVirtAngReset | REQ_GPU_FcuCalibStart | REQ_GPU_FcuCalibStop | REQ_GPU_FcuGetWideImg | REQ_GPU_FcuGetNarrowImg | \
    				 REQ_GPU_FrcuVirtAngReset | REQ_GPU_FrcuGetImg | \
					 REQ_GPU_TicuCalibStart | REQ_GPU_TicuCalibStop | REQ_GPU_TicuGetImg | \
					 REQ_GPU_LidCalibStart | REQ_GPU_LidCalibStop | REQ_GPU_LidGetImg))
    {
    	get_req = 1;

    	step_counter = 5;

    	temp_REQ_GPU_FrcuVirtAngReset = REQ_GPU_FrcuVirtAngReset;
    	temp_REQ_GPU_FrcuGetImg = REQ_GPU_FrcuGetImg;
    	temp_REQ_GPU_FcuVirtAngReset = REQ_GPU_FcuVirtAngReset;
    	temp_REQ_GPU_FcuSetYawAngle = REQ_GPU_FcuSetYawAngle;
    	temp_REQ_GPU_FcuSetPitchAngle = REQ_GPU_FcuSetPitchAngle;
    	temp_REQ_GPU_FcuCalibStart = REQ_GPU_FcuCalibStart;
    	temp_REQ_GPU_FcuCalibStop = REQ_GPU_FcuCalibStop;
    	temp_REQ_GPU_FcuGetWideImg = REQ_GPU_FcuGetWideImg;
    	temp_REQ_GPU_FcuGetNarrowImg = REQ_GPU_FcuGetNarrowImg;
    	temp_REQ_GPU_TicuCalibStart = REQ_GPU_TicuCalibStart;
    	temp_REQ_GPU_TicuCalibStop = REQ_GPU_TicuCalibStop;
    	temp_REQ_GPU_TicuGetImg = REQ_GPU_TicuGetImg;
    	temp_REQ_GPU_LidCalibStart = REQ_GPU_LidCalibStart;
    	temp_REQ_GPU_LidCalibStop = REQ_GPU_LidCalibStop;
    	temp_REQ_GPU_LidGetImg = REQ_GPU_LidGetImg;
    }

    McuFrcuVirtAngReset = temp_REQ_GPU_FrcuVirtAngReset;
    McuFrcuGetImg = temp_REQ_GPU_FrcuGetImg;
    McuFcuVirtAngReset = temp_REQ_GPU_FcuVirtAngReset;
    McuFcuSetYawfAngle = temp_REQ_GPU_FcuSetYawAngle;
    McuFcuSetPitchAngle = temp_REQ_GPU_FcuSetPitchAngle;
    McuFcuCalibStart = temp_REQ_GPU_FcuCalibStart;
    McuFcuCalibStop = temp_REQ_GPU_FcuCalibStop;
    McuFcuGetWideImg = temp_REQ_GPU_FcuGetWideImg;
    McuFcuGetNarrImg = temp_REQ_GPU_FcuGetNarrowImg;
    McuTicuCalibStart = temp_REQ_GPU_TicuCalibStart;
    McuTicuCalibStop = temp_REQ_GPU_TicuCalibStop;
    McuTicuGetThermImg = temp_REQ_GPU_TicuGetImg;
    McuLidCalibStart = temp_REQ_GPU_LidCalibStart;
    McuLidCalibStop = temp_REQ_GPU_LidCalibStop;
    McuLidGetLidarImg = temp_REQ_GPU_LidGetImg;
}

void UDP_Main_Start_Handler_Mod(uint8* data)
{
	data[0] = DtPercStartMlia;
	data[1] = DtPercStartFrontPasObj;
	data[2] = DtPercStartFrontOncomObj;
	data[3] = DtPercStartSign;
	data[4] = DtPercStartLane;
	data[5] = DtPercStartRearObj;
	data[6] = DtPercRecToInc_Req;
	data[7] = DtPercStartRec;
	data[8] = UDP_Main_Start_RC;
}

/*
void UDP_MainDataFromPerc_Handler_Mod(uint8* data)
{
	memcpy(&DfPercFcuDirtSts, &data[0], 1);
	memcpy(&DfPercFrcuDirtSts, &data[1], 1);
	memcpy(&DfPercTicuDirtSts, &data[2], 1);
	memcpy(&DfPercMrrxDirtSts, &data[3], 1);
	memcpy(&DfPercLidarDirtSts, &data[4], 1);
	memcpy(&DfPercValidDataFront, &data[5], 1);
	memcpy(&DfPercValidDataRear, &data[6], 1);
	memcpy(&DfPercValidDataLane, &data[7], 1);
	memcpy(&DfPercValidDataSign, &data[8], 1);
	memcpy(&DfPercValidDataMlia, &data[9], 1);
	memcpy(&UDP_MainDataFromPerc_RC, &data[10], 1);

	fUdp1Rcv = 1;
}
*/
void UDP_BCM_VehState_Handler_Mod(uint8* data)
{

#ifdef SW_HAVAL
	data[0] = BCM_VehicleType_Stat = 0x00;	//
	data[1] = BCM_VehicleBody_Stat = 0x0F;	// Haval
#endif

#ifdef SW_AURUS
	data[0] = BCM_VehicleType_Stat = 0x00;
	data[1] = BCM_VehicleBody_Stat = 0x01;
#endif
}
