// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_TI_TMP451_H_
#define PLATFORM_DEVICE_DRIVER_TI_TMP451_H_

#include "common/driver/ti/tmp451.h"
#include "common/mcu/utils/status.h"

typedef struct Tmp451Configuration {
  uint16_t bus_num;
  uint8_t address;
} Tmp451Configuration;

typedef struct Tmp451Device {
  Tmp451 dev;
  Tmp451Configuration config;
} Tmp451Device;

ReturnCode Tmp451InitWithConfiguration(Tmp451Device* tmp451);

#endif  // PLATFORM_DEVICE_DRIVER_TI_TMP451_H_
