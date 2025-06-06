// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_EEPROM_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_EEPROM_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

ReturnCode ReadFromEeprom(uint16_t offset, uint8_t* buffer, uint16_t read_length);
ReturnCode WriteToEeprom(uint16_t offset, const uint8_t* buffer, uint16_t write_length);
ReturnCode InitEeprom(void);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_EEPROM_H_
