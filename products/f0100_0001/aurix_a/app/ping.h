// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_PING_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_PING_H_

#include "common/mcu/utils/status.h"

ReturnCode InitPing(void);
ReturnCode PingSend(uint8_t addr1, uint8_t addr2, uint8_t addr3, uint8_t addr4);
void StopPing(void);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_PING_H_
