// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_TCP_CLI_PRINT_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_TCP_CLI_PRINT_H_

#include <stdint.h>

void InitEthCli(void);
int32_t AdcuDebugWrite(const uint8_t* buffer, uint32_t len);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_TCP_CLI_PRINT_H_
