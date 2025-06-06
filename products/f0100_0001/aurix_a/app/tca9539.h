// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_TCA9539_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_TCA9539_H_

#include "common/mcu/utils/status.h"

#define TCA9539_NAME(channel) #channel

enum Tca9539OutputPins {
  kAurixAVbat1PwrEn = 0,
  kOrinAFsiCanForceOff,
  kOrinABootchain1,
  kOrinABootchain0,
  KOrinAIstReq,
  kOrinASc7Entry,
  kOrinAPreRegEn,
  kOrinAVrs10Sleep,
  kOrinAStbyReq,
  kOrinACvmReset,
  kOrinAPowerBtn,
  kOrinAVrs10PwrOn,
  kOrinANvDbgSel,
  kOrinAForceRecovery,
  kOrinBFsiCanForceOff,
  kOrinBBootchain1,
  kOrinBBootchain0,
  KOrinBIstReq,
  kOrinBSc7Entry,
  kOrinBPreRegEn,
  kOrinBVrs10Sleep,
  kOrinBStbyReq,
  kOrinBCvmReset,
  kOrinBPowerBtn,
  kOrinBVrs10PwrOn,
  kOrinBNvDbgSel,
  kOrinBForceRecovery,
};

enum Tca9539InputPins {
  kOrinAThermAlert = 0,
  KOrinAStbyAck,
  kGmslPwrPg,
  kOrinBThermAlert,
  KOrinBStbyAck,
};

ReturnCode InitTca9539(void);
ReturnCode WriteTca9539Pin(int channel, uint8_t value);
ReturnCode ReadTca9539PinValue(int channel, uint8_t* value);

void Tca9539High(int channel);
void Tca9539Low(int channel);
void Tca9539Reset(int channel);
void Tca9539SquareWave(int channel);
void Tca9539Read(int channel);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_TCA9539_H_
