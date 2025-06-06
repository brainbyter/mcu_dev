// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_RTC_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_RTC_H_

#include "common/mcu/utils/status.h"

void PrintRtcTime(void);
void TestRtcAccuracy(void);
ReturnCode InitialRtcTime(void);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_RTC_H_
