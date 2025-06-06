// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_LED_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_LED_H_

#include "common/mcu/utils/status.h"

typedef enum LedLevel {
  kLedNormal,
  kLedWarning,
  kLedError,
  kLedInLoader,
  kLedIsUpdating,
} LedLevel;

ReturnCode SetLedLevel(LedLevel target_level);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_LED_H_
