// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef COMMON_DRIVER_MICRO_CHIP_PAC1954_H_
#define COMMON_DRIVER_MICRO_CHIP_PAC1954_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"
#include "common/driver/micro_chip/pac1954_def.h"
#include "common/driver/micro_chip/pac1954_regdefs.h"

#define PAC1954_CH_NUM (4)

typedef struct Pac1954Alert {
  uint32_t alert_bit;
  bool alert_en;
  bool assign_gpio_alert;
  bool assign_slow_alert;
  void (*Handler)(void* param);
  void* param;
} Pac1954Alert;

typedef struct Pac1954 {
  uint16_t i2c_slave_addr;
  float sample_res_val_mohm[PAC1954_CH_NUM];
  ReturnCode (*Write)(uint16_t slave_addr, uint8_t reg_addr, 
                      uint8_t* data, int8_t data_len, void* user_data);
  ReturnCode (*Read)(uint16_t slave_addr, uint8_t reg_addr, 
                     uint8_t* data, int8_t data_len, void* user_data);
  ReturnCode (*GereralCall)(uint16_t slave_addr, uint8_t reg_addr, 
                            void* user_data);
  Pac1954Alert* alert;
  void* user_data;
} Pac1954;

#define PAC1954_REG_BYTES(reg_name, reg_addr, reg_bytes)  \
  { (reg_name), (reg_addr), (reg_bytes) }

#define PAC1954_SETTING(setting, reg_name, reg_msb, reg_lsb)  \
  { (setting), (reg_name), (reg_msb), (reg_lsb) }

#define PAC1954_STATUS(status, reg_name, reg_msb, reg_lsb)  \
  { (status), (reg_name), (reg_msb), (reg_lsb) }

ReturnCode Pac1954Refresh(Pac1954* pac1954, 
                          Pac1954RefreshSetting setting);
ReturnCode Pac1954Config(Pac1954* pac1954,
                         Pac1954SettingList setting,
                         uint64_t set_val);
ReturnCode Pac1954GetStatus(Pac1954* pac1954,
                            Pac1954StatusList status,
                            uint64_t* sta_val);
ReturnCode Pac1954CheckEqual(Pac1954* pac1954,
                             Pac1954SettingList setting,
                             Pac1954StatusList status,
                             bool* sta);
ReturnCode Pac1954GetChVoltage(Pac1954* pac1954,
                               Pac1954ChNum ch_num,
                               float* vol_val);
ReturnCode Pac1954GetChCurrent(Pac1954* pac1954,
                               Pac1954ChNum ch_num,
                               float* cur_val);
ReturnCode Pac1954GetChPower(Pac1954* pac1954,
                             Pac1954ChNum ch_num,
                             float* pow_val);
ReturnCode Pac1954SetOcValue(Pac1954* pac1954,
                             Pac1954ChNum ch_num,
                             float cur_val);
ReturnCode Pac1954SetUcValue(Pac1954* pac1954,
                             Pac1954ChNum ch_num,
                             float cur_val);
ReturnCode Pac1954SetOvValue(Pac1954* pac1954,
                             Pac1954ChNum ch_num,
                             float vol_val);
ReturnCode Pac1954SetUvValue(Pac1954* pac1954,
                             Pac1954ChNum ch_num,
                             float vol_val);
ReturnCode Pac1954SetOpValue(Pac1954* pac1954,
                             Pac1954ChNum ch_num,
                             float pwr_val);
ReturnCode Pac1954InitAlert(Pac1954* pac1954);
void Pac1954DealAlert(void* args);
ReturnCode Pac1954DumpReg(Pac1954* pac1954);

#endif  // COMMON_DRIVER_MICRO_CHIP_PAC1954_H_
