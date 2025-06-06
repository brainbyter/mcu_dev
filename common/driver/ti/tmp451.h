// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef COMMON_DRIVER_TI_TMP451_H_
#define COMMON_DRIVER_TI_TMP451_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

typedef struct Tmp451 {
  void* i2c_bus;
  uint8_t i2c_slave_addr;
  ReturnCode (*i2c_write)(void* i2c_bus, uint8_t slave_addr, uint8_t reg_addr, uint8_t data);
  ReturnCode (*i2c_read)(void* i2c_bus, uint8_t slave_addr, uint8_t reg_addr, uint8_t* data);
} Tmp451;

ReturnCode InitTmp451(Tmp451* tmp451);
ReturnCode GetTmp451RemoteTemperature(Tmp451* tmp451, float* temperature);
ReturnCode GetTmp451LocalTemperature(Tmp451* tmp451, float* temperature);

#endif  // COMMON_DRIVER_TI_TMP451_H_
