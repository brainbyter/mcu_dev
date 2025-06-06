// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_NUT_AURIX_APP_ADC_MONITOR_H_
#define PRODUCTS_F0100_0001_NUT_AURIX_APP_ADC_MONITOR_H_

#include "common/mcu/utils/status.h"

#define ADC_NAME(channel) #channel

enum AdcChannels {
  kKl30In1Flt,	//
  kVdd11v5,		// 11.95
  kVdd5v,		// 4.98
  kEth1v5,
  kEth1v05,
  kAurixA1v3,
  kAurixA3v3,	// 3.35
  kEth3v3,
  kEth1v8,
  kEth0v9,
  kAurixAVeWakein1Adc,
  kAurixAVeWakein2Adc,
  kRtcTlfWakeAdc,
  kHwVersion,
  kOrinAPgVrs11,
  kOrinAPgLcvr,
  kOrinAPgLcvrA0,
  kOrinAPgLcvrFsi,
  kOrinASafe3v3Pg,
  kOrinAPg1v0Core,
  kOrinAVdd1v0Core,
  kKl30In2Flt,
  kOrinAVccUfs2v5,
  kOrinASafe3v3,
  kOrinAVccVrs11,
  kVbat1Soc1,
  kOrinA16vPreReg,
  kOrinA5vPreReg,
  kSys12v,
  kSys5v,
  kSys3v3,
  kSys1v8,
  kSys1v2,
};

ReturnCode GetAdcVoltageById(int channel, float* value);
ReturnCode GetAdcValueByName(char* name, float* value);
void PrintAllAdcVoltage(void);

#endif  // PRODUCTS_F0100_0001_NUT_AURIX_APP_ADC_MONITOR_H_
