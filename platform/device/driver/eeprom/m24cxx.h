// Copyright @2021 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_EEPROM_M24CXX_H_
#define PLATFORM_DEVICE_DRIVER_EEPROM_M24CXX_H_

#include <stdint.h>

#include "common/driver/eeprom/m24cxx.h"
#include "common/mcu/utils/status.h"

// As long as the device exists, this configuration will always exist.
typedef struct M24cxxConfiguration {
  uint8_t bus_num;
  int16_t wp_en_pin;
} M24cxxConfiguration;

typedef struct M24cxxDevice {
  M24cxx dev;
  M24cxxConfiguration config;
} M24cxxDevice;

ReturnCode M24cxxInitWithConfiguration(M24cxxDevice* m24cxx);

#endif  // PLATFORM_DEVICE_DRIVER_EEPROM_M24CXX_H_
