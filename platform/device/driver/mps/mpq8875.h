// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_MPS_MPQ8875_H_
#define PLATFORM_DEVICE_DRIVER_MPS_MPQ8875_H_

#include "common/driver/mps/mpq8875.h"
#include "common/mcu/utils/status.h"

typedef struct PmicMpq8875Configuration{
  int16_t poweron_pin;
  int16_t pg_pin;
  uint16_t i2c_bus;
} PmicMpq8875Configuration;

typedef struct Mpq8875Device {
  const char* name;
  Mpq8875 dev;
  PmicMpq8875Configuration config;
} Mpq8875Device;

#define MPQ8875_DEVICE(dev_name, bus_num, dev_addr, pg, poweron)     \
{                                                                    \
  .name = dev_name,                                                  \
  .config.i2c_bus = bus_num,                                         \
  .dev.i2c_slave_addr = dev_addr,                                    \
  .config.pg_pin = pg,                                               \
  .config.poweron_pin = poweron,                                     \
}

ReturnCode PmicMpq8875Init(Mpq8875Device* dev);

#endif  // PLATFORM_DEVICE_DRIVER_MPS_MPQ8875_H_
