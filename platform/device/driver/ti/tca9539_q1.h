// Copyright @2019-2020 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_TI_TCA9539_Q1_H_
#define PLATFORM_DEVICE_DRIVER_TI_TCA9539_Q1_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

// In TCA9539_Q1 datasheet, there is no register address but
// a command byte following I2C address which determine what
// register to read/write. This command byte is equivalent
// to register address.
typedef enum tca9539_q1_reg_addr {
  kInputPort0,
  kInputPort1,
  kOutputPort0,
  kOutputPort1,
  kPolarity0,
  kPolarity1,
  kConfigPort0,
  kConfigPort1
} tca9539_q1_reg_addr_t;

typedef enum tca9539_q1_port { kTcaPort0, kTcaPort1, kTcaPortNum } tca9539_q1_port_t;

typedef struct tca9539 {
  uint16_t i2c_bus;
  uint16_t i2c_slave_addr;
  int16_t reset_pin;
  int16_t interrupt_pin;
} tca9539_t;

#define MAX_TCA9539_DEVICE_NAME_LEN 32

typedef struct Tca9539Device {
  char name[MAX_TCA9539_DEVICE_NAME_LEN];
  tca9539_t dev;
  uint16_t io_bitmap;  // 1 stands for input, 0 stands for output
  uint16_t io_polarity_bitmap;  // 1 stands for input polarity is inverted, 0 stands for retained
} Tca9539Device;

#define TCA9539_DEVICE(dev_name, bus_num, dev_addr, reset, interrupt, dev_io, dev_polarity) \
{                                                                                           \
  .name = dev_name,                                                                         \
  .dev.i2c_bus = bus_num,                                                                   \
  .dev.i2c_slave_addr = dev_addr,                                                           \
  .dev.reset_pin = reset,                                                                   \
  .dev.interrupt_pin = interrupt,                                                           \
  .io_bitmap = dev_io,                                                                      \
  .io_polarity_bitmap = dev_polarity,                                                       \
}

// A reset needs more 550ns before tca9539 is ready to use.
ReturnCode Tca9539Q1Init(const tca9539_t* tca9539);

ReturnCode Tca9539Q1SetIoMode(const tca9539_t* tca9539,
                              uint16_t io_bitmap,
                              uint16_t io_polarity_bitmap);

ReturnCode Tca9539Q1GetAllInputLevel(const tca9539_t* tca9539,
                                     tca9539_q1_port_t port,
                                     uint8_t* level_bitmask);

ReturnCode Tca9539Q1GetSingleInputLevel(const tca9539_t* tca9539,
                                        tca9539_q1_port_t port,
                                        uint8_t channel,
                                        uint8_t* level);

ReturnCode Tca9539Q1GetAllOutputLevel(const tca9539_t* tca9539,
                                      tca9539_q1_port_t port,
                                      uint8_t* level_bitmask);

ReturnCode Tca9539Q1GetSingleOutputLevel(const tca9539_t* tca9539,
                                         tca9539_q1_port_t port,
                                         uint8_t channel,
                                         uint8_t* level);

ReturnCode Tca9539Q1SetAllOutputLevel(const tca9539_t* tca9539,
                                      tca9539_q1_port_t port,
                                      uint8_t level_bitmask);

ReturnCode Tca9539Q1SetSingleOutputLevel(const tca9539_t* tca9539,
                                         tca9539_q1_port_t port,
                                         uint8_t channel,
                                         uint8_t level);

#endif  // PLATFORM_DEVICE_DRIVER_TI_TCA9539_Q1_H_
