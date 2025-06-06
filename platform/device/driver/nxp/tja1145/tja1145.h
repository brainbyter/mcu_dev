// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_NXP_TJA1145_H_
#define PLATFORM_DEVICE_DRIVER_NXP_TJA1145_H_

#include <stdint.h>

#include "common/driver/nxp/tja1145.h"
#include "common/mcu/utils/status.h"

typedef struct Tja1145Configuration {
  uint16_t bus_num;
  uint8_t slave_num;
} Tja1145Configuration;

typedef struct Tja1145Device {
  Tja1145 dev;
  Tja1145Configuration config;
} Tja1145Device;

ReturnCode Tja1145InitWithConfiguration(Tja1145Device* tja1145);

#endif  // PLATFORM_DEVICE_DRIVER_NXP_TJA1145_H_
