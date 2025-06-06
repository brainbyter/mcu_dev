// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_I2C_TEST_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_I2C_TEST_H_

#include "common/mcu/utils/status.h"

ReturnCode I2cTestWrite(uint8_t i2c_bus,
                        uint16_t slave_addr, 
                        uint8_t reg_addr, 
                        uint8_t data);

ReturnCode I2cTestRead(uint8_t i2c_bus,
                       uint16_t slave_addr,
                       uint8_t reg_addr);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_I2C_TEST_H_
