// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_MAXIM_MAX20087_H_
#define PLATFORM_DEVICE_DRIVER_MAXIM_MAX20087_H_

#include "common/driver/maxim/max20087.h"
#include "common/mcu/utils/status.h"

typedef struct Max20087Configuration {
  int16_t en_pin;
  int16_t status_pin;
  uint16_t i2c_bus;
} Max20087Configuration;

typedef struct Max20087Device {
  const char* name;
  Max20087 dev;
  Max20087Configuration config;
} Max20087Device;

#define MAX20087_DEVICE(dev_name, bus_num, dev_addr, enpin, stapin) \
{                                                                   \
  .name = dev_name,                                                 \
  .config.i2c_bus = bus_num,                                        \
  .dev.i2c_slave_addr = dev_addr,                                   \
  .config.en_pin = enpin,                                           \
  .config.status_pin = stapin                                       \
}

ReturnCode Max20087DevInit(Max20087Device* dev);

#endif  // PLATFORM_DEVICE_DRIVER_MAXIM_MAX20087_H_
