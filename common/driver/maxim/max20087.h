// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef COMMON_DRIVER_MAXIM_MAX20087_H_
#define COMMON_DRIVER_MAXIM_MAX20087_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

// Interrupt Mask Register (MASK) Setting Bits
#define MAX20087_MASK_OVTST (1 << 0)
#define MAX20087_MASK_ACCM  (1 << 1)
#define MAX20087_MASK_TSM   (1 << 2)
#define MAX20087_MASK_VDDM  (1 << 3)
#define MAX20087_MASK_VINM  (1 << 4)
#define MAX20087_MASK_OCM   (1 << 5)
#define MAX20087_MASK_OVM   (1 << 6)
#define MAX20087_MASK_UVM   (1 << 7)

typedef enum Max20087RegList {
  kMax20087RegMask = 0,
  kMax20087RegConfig,
  kMax20087RegId,
  kMax20087RegStat1,
  kMax20087RegStat2a,
  kMax20087RegStat2b,
  kMax20087RegAdc1,
  kMax20087RegAdc2,
  kMax20087RegAdc3,
  kMax20087RegAdc4,
} Max20087RegList;

typedef enum Max20087AdcMux {
  kMax20087AdcMuxCurrent = 0x0,
  kMax20087AdcMuxOutputVoltage = 0x1,
  kMax20087AdcMuxSourceVoltage = 0x2,
} Max20087AdcMux;

typedef enum Max20087AdcMode {
  kMax20087AdcModeStartWithCh1 = 0x0,
  kMax20087AdcModeContinue = 0x1,
} Max20087AdcMode;

typedef enum Max20087PowerStatus {
  kMax20087PowerOff = 0x0,
  kMax20087PowerOn = 0x1,
} Max20087PowerStatus;

typedef enum Max20087ChNum {
  kMax20087Ch0,
  kMax20087Ch1,
  kMax20087Ch2,
  kMax20087Ch3,
  kMax20087MaxCh,
} Max20087ChNum;

typedef enum Max20087SettingList {
  kMax20087SettingMux = 0,
  kMax20087SettingEnc,
  kMax20087SettingEn,
  kMax20087SettingId,
  kMax20087SettingAdc1,
  kMax20087SettingAdc2,
  kMax20087SettingAdc3,
  kMax20087SettingAdc4,
  kMax20087SettingMax,
} Max20087SettingList;

typedef struct Max20087 {
  uint16_t i2c_slave_addr;
  ReturnCode (*Write)(uint16_t slave_addr, uint8_t reg_addr, 
                      uint8_t* data, void* user_data);
  ReturnCode (*Read)(uint16_t slave_addr, uint8_t reg_addr, 
                     uint8_t* data, void* user_data);
  ReturnCode (*PowerOn)(void* user_data);
  ReturnCode (*PowerOff)(void* user_data);
  ReturnCode (*GetPgStatus)(int* status, void* user_data);
  void* user_data;
} Max20087;

typedef struct Max20087Settings {
  Max20087SettingList setting;
  Max20087RegList reg_addr;
  uint8_t reg_msb;
  uint8_t reg_lsb;
} Max20087Settings;

ReturnCode Max20087Init(Max20087* dev);
ReturnCode Max20087Operate(Max20087* dev, Max20087ChNum ch_num, Max20087PowerStatus status);
ReturnCode Max20087SetAdcMux(Max20087* dev, Max20087AdcMux mode);
ReturnCode Max20087SetAdcMode(Max20087* dev, Max20087AdcMode mode);
// Use Max20087SetAdcMux & Max20087SetAdcMode to set ADC mode before calling MAx20087GetAdcValue.
ReturnCode MAx20087GetAdcValue(Max20087* dev, Max20087ChNum ch_num, float* value);
ReturnCode Max20087GetRegStatus(Max20087* dev, Max20087SettingList setting, uint8_t* val);
ReturnCode Max20087RegConfig(Max20087* dev, Max20087SettingList setting, uint8_t val);
ReturnCode Max20087PowerConfig(Max20087* dev, Max20087PowerStatus status);
ReturnCode Max20087GetPgStatus(Max20087* dev, int* level);
ReturnCode Max20087WriteReg(Max20087* dev, uint8_t reg_addr, uint8_t value);
ReturnCode Max20087ReadReg(Max20087* dev, uint8_t reg_addr, uint8_t* data);
ReturnCode Max20087SetRegOneBit(Max20087* dev, uint8_t reg_addr, uint8_t offset, uint8_t value);

#endif  // COMMON_DRIVER_MAXIM_MAX20087_H_
