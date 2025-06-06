// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_MICRO_CHIP_PAC1954_H_
#define PLATFORM_DEVICE_DRIVER_MICRO_CHIP_PAC1954_H_

#include "common/driver/micro_chip/pac1954.h"
#include "common/mcu/utils/status.h"

typedef struct Pac1954Configuration {
  int16_t alert_pin;
  uint16_t i2c_bus;
} Pac1954Configuration;

typedef struct Pac1954Device {
  const char* name;
  Pac1954 dev;
  Pac1954Configuration config;
} Pac1954Device;

#define Pac1954_DEVICE(dev_name, bus_num, dev_addr, alert_pin_num, \
                       res0, res1, res2, res3, pac1954_alert)      \
{                                                                  \
  .name = dev_name,                                                \
  .config.i2c_bus = bus_num,                                       \
  .dev.i2c_slave_addr = dev_addr,                                  \
  .config.alert_pin = alert_pin_num,                               \
  .dev.sample_res_val_mohm[0] = res0,                              \
  .dev.sample_res_val_mohm[1] = res1,                              \
  .dev.sample_res_val_mohm[2] = res2,                              \
  .dev.sample_res_val_mohm[3] = res3,                              \
  .dev.alert = pac1954_alert,                                      \
}

#define Pac1954_ALERT(al_alert_bit, al_alert_en,                   \
                      al_assign_gpio_alert, al_assign_slow_alert,  \
                      al_deal_func, al_param)                      \
{                                                                  \
  .alert_bit = al_alert_bit,                                       \
  .alert_en = al_alert_en,                                         \
  .assign_gpio_alert = al_assign_gpio_alert,                       \
  .assign_slow_alert = al_assign_slow_alert,                       \
  .Handler = al_deal_func,                                         \
  .param = (void*)al_param,                                        \
}  

ReturnCode Pac1954Init(Pac1954Device* dev);

#endif  // PLATFORM_DEVICE_DRIVER_MICRO_CHIP_PAC1954_H_
