// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef COMMON_DRIVER_MPS_MPQ8875_H_
#define COMMON_DRIVER_MPS_MPQ8875_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

typedef enum Mpq8875RegList {
  kMpq8875Reg00,
  kMpq8875Reg01,
  kMpq8875Reg02,
  kMpq8875Reg03,
  kMpq8875Reg04,
  kMpq8875Reg05,
  kMpq8875Reg06,
  kMpq8875Reg07,
  kMpq8875Reg08,
  kMpq8875Reg09,
  kMpq8875Reg0a,
  kMpq8875Reg0b,
  kMpq8875Reg0c,
  kMpq8875Reg0d,
  kMpq8875Reg0e,
  kMpq8875Reg0f,
  kMpq8875Reg10,
} Mpq8875RegList;

typedef enum Mpq8875OperationMode { 
  kMpq8875PowerOn,
  kMpq8875PowerOff,
} Mpq8875OperationMode;

typedef enum Mpq8875SettingList {
  kMpq8875SettingFbdr = 0,
  kMpq8875SettingVref,
  kMpq8875SettingMax,
} Mpq8875SettingList;

typedef struct Mpq8875Settings {
  Mpq8875SettingList setting;
  Mpq8875RegList reg_addr;
  uint8_t reg_msb;
  uint8_t reg_lsb;
} Mpq8875Settings;

typedef struct Mpq8875 {
  uint16_t i2c_slave_addr;
  ReturnCode (*Write)(uint16_t slave_addr, uint8_t reg_addr, 
                      uint8_t* data, void* user_data);
  ReturnCode (*Read)(uint16_t slave_addr, uint8_t reg_addr, 
                     uint8_t* data, void* user_data);
  ReturnCode (*PowerOn)(void* user_data);
  ReturnCode (*PowerOff)(void* user_data);
  ReturnCode (*GetStatus)(int* status, void* user_data);
  void* user_data;
} Mpq8875;

ReturnCode Mpq8875SetVoltage(Mpq8875* mpq8875, float voltage);
ReturnCode Mpq8875Operating(Mpq8875* mpq8875, Mpq8875OperationMode operating);
ReturnCode Mpq8875GetStatus(Mpq8875* dev, Mpq8875SettingList setting, uint8_t* val);
ReturnCode Mpq8875RegConfig(Mpq8875* dev, Mpq8875SettingList setting, uint8_t val);

#endif  // COMMON_DRIVER_MPS_MPQ8875_H_
