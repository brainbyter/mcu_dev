//Copyright @2024 Pony AI Inc. All rights reserved.
#include "common/mcu/system/init.h"
#include "common/mcu/utils/debug.h"
#include "common/mcu/utils/status.h"
#include "platform/device/bsp/bsp_irq.h"
#include "platform/device/bsp/bsp_timer.h"
#include "platform/product/common/pony_bsp.h"
#include "platform/product/common/pony_driver.h"
#include "platform/system/systemtime.h"
#include "products/f0100_0001/aurix_a/sdk/timer.h"

#include "CAN_Extern.h"
#include "FD_Vars.h"
#include "DiagMrr_typedefs.h"
#include <sw_version.h>

/////////////////////////////////////////////Normal///////////////////////////////////////////////
#define MAX_COUNTER_VALUE   65535
/////////////////////////////////ktimer0-1-2///////////////////////////////////

static uint32_t GetTimer012PrescalerPeriod(PonyTimer012Period period, PonyTimerPrescaler prescaler) 
{
    return period * prescaler;
}
/////////////////////////////////kTimer0///////////////////////////////////////
static uint32_t g_timer0_period = 0;
static uint32_t g_timer0_freq   = 0;
static uint32_t g_timer0_reload_value = 0;
static uint32_t cnt = 0;
uint32_t getcnt(void)
{
	return cnt;
}
void setcnt(uint32_t temp)
{
	cnt = temp;
}
static void Timer0Handler(void *info) 
{
  	LOG_IF_ERROR(ConfigTimerTick(kTimer0, g_timer0_freq, g_timer0_reload_value));
    cnt++;     //for APP
}
/////////////////////////////////kTimer1///////////////////////////////////////
static uint32_t g_timer1_period = 0;
static uint32_t g_timer1_freq   = 0;
static uint32_t g_timer1_reload_value = 0;
static uint32_t cnt1 = 0;
uint32_t getcnt1(void)
{
	return cnt1;
}
void setcnt1(uint32_t temp)
{
	cnt1 = temp;
}
static void Timer1Handler(void *info) 
{
	LOG_IF_ERROR(ConfigTimerTick(kTimer1, g_timer1_freq, g_timer1_reload_value));
    SystemTime++;

    fXcpCheck = 1;

	fUdpProcess = 1;

	if ((SystemTime % 10)==0)
	{
		fVlcStep = 1;
	}

	if ((SystemTime % 50)==0)
	{
		fAdasStep = 1;
	}

	if ((SystemTime % 100)==0)
	{
		fAdcStep = 1;
	}

	if ((SystemTime % 250)==0)
	{
		fPowerManagement = 1;
	}

	cntMrrxDataSendUdp++;
	if (((cntMrrxDataSendUdp % 5)==0) && (cntMrrxDataSendUdp > 0))
	{
		cntMrrxDataSendUdp = 0;
		fMrrxDataSendUdp = 1;
	}

	if ((SystemTime % 1000) == 0)
	{
		fDiagCanBusState = 1;
	}

	if ((SystemTime % 3) == 0)
	{
//		fXcpCheck = 1;
	}

/*	if ((SystemTime % 5)==0)
	{
		fMrrxDataSendUdp = 1;
	}
*/
}
/////////////////////////////////kTimer2///////////////////////////////////////
static uint32_t g_timer2_period = 0;
static uint32_t g_timer2_freq   = 0;
static uint32_t g_timer2_reload_value = 0;
static uint32_t cnt2 = 0;
uint32_t getcnt2(void)
{
	return cnt2;
}
void setcnt2(uint32_t temp)
{
	cnt2 = temp;
}
static void Timer2Handler(void *info) 
{
  	LOG_IF_ERROR(ConfigTimerTick(kTimer2, g_timer2_freq, g_timer2_reload_value));
    fUdsProcess = 1;
}


///////////////////////////////////////////////////////////////////////////////////////
ReturnCode InitTimer(void) 
{
    ///////////////////////////kTimer012: kTimer0-1-2////////////////////////////////////////////////
  	RETURN_IF_ERROR(SetTimerPeriod(kTimer012, kTimer012Period320Ns));
	////////////////////////////////////kTimer0////////////////////////////////////////////
  	g_timer0_period = GetTimer012PrescalerPeriod(kTimer012Period320Ns, kTimerPrescaler64);
  	RETURN_IF_ERROR(SetTimerPeriod(kTimer0, g_timer0_period));
  	g_timer0_freq = 1 / (g_timer0_period / (float)NANOSEC_PER_SEC);    					//1s
  	g_timer0_reload_value = MAX_COUNTER_VALUE - g_timer0_freq;
  	RETURN_IF_ERROR(ConfigTimerTick(kTimer0, g_timer0_freq, g_timer0_reload_value));
  	RETURN_IF_ERROR(RequestTimerTimeoutFunction(kTimer0, Timer0Handler, NULL));
  	RETURN_IF_ERROR(EnableTimer(kTimer0));
  	PONY_LOG(DEBUG_INFO, "Init pony timer0 successfully, TimerTick: 1s", );
	////////////////////////////////////kTimer1///////////////////////////////////////////
  	g_timer1_period = g_timer0_period;
  	RETURN_IF_ERROR(SetTimerPeriod(kTimer1, g_timer1_period));
  	g_timer1_freq = 1 / (g_timer1_period / (float)NANOSEC_PER_SEC);
  	g_timer1_reload_value = MAX_COUNTER_VALUE - (g_timer1_freq / MILLISEC_PER_SEC);   	//1ms
  	RETURN_IF_ERROR(ConfigTimerTick(kTimer1, g_timer1_freq, g_timer1_reload_value));
  	RETURN_IF_ERROR(RequestTimerTimeoutFunction(kTimer1, Timer1Handler, NULL));
  	RETURN_IF_ERROR(EnableTimer(kTimer1));
  	PONY_LOG(DEBUG_INFO, "Init pony timer1 successfully, TimerTick: 1ms", );
	////////////////////////////////////kTimer2///////////////////////////////////////////
  	g_timer2_period = g_timer0_period;
  	RETURN_IF_ERROR(SetTimerPeriod(kTimer2, g_timer2_period));
  	g_timer2_freq = 1 / (g_timer2_period / (float)NANOSEC_PER_SEC);
  	// This reload value make TimerTick almost is 1s
  	g_timer2_reload_value = MAX_COUNTER_VALUE - (g_timer2_freq / 10000);     			//100us
  	RETURN_IF_ERROR(ConfigTimerTick(kTimer2, g_timer2_freq, g_timer2_reload_value));
  	RETURN_IF_ERROR(RequestTimerTimeoutFunction(kTimer2, Timer2Handler, NULL));
  	RETURN_IF_ERROR(EnableTimer(kTimer2));
  	PONY_LOG(DEBUG_INFO, "Init pony timer2 successfully, TimerTick: 100us", );
  	return ERROR_OK;
}
