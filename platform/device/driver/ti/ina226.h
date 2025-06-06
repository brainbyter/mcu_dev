// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef DRIVER_INA226_H_
#define DRIVER_INA226_H_

#include <stdint.h>

typedef struct ina226 {
  uint8_t i2c_bus;
  uint8_t i2c_slave_addr;
  uint16_t config_value;
  uint16_t expect_calibration;
  uint16_t shunt_res_value_mr;  // (mR)
  float voltage_LSB;            // (v)
} ina226_t;

enum Ina226ConfigValue {
  // h'4527 = b'100_010_100_100_111
  // average number:16(b'010)
  // Bus Voltage Conversion Time: 1.1ms(b'100)
  // Shunt Voltage Conversion Time: 1.1ms(b'100)
  // Operation mode: shunt and bus, continuous(b'111)
  kIna226Config = 0x4527,
};

enum Ina226FunctionMask {
  kIna226ShuntOverVoltageMask = 0x8000,
  kIna226AlertLatchEnableMask = 0x0001,
};

extern int WriteIna226Configuration(const ina226_t* ina226);
extern int WriteIna226Calibration(const ina226_t* ina226);
extern int WriteIna226EnableRegister(const ina226_t* ina226, uint16_t bitmask);
extern int WriteIna226AlertRegister(const ina226_t* ina226, uint16_t bitmask);
extern int ReadIna226Busvoltage(const ina226_t* ina226, float* result);
extern int ReadIna226Shuntcurrent(const ina226_t* ina226, float* result);

#endif  // DRIVER_INA226_H_
