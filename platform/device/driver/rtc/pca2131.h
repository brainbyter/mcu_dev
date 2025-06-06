// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_RTC_PCA2131_H_
#define PLATFORM_DEVICE_DRIVER_RTC_PCA2131_H_

#include "common/driver/rtc/pca2131.h"
#include "common/mcu/utils/status.h"

typedef struct Pca2131Configuration {
  uint16_t bus_num;
  uint8_t address;
} Pca2131Configuration;

typedef struct Pca2131Device {
  Pca2131 dev;
  Pca2131Configuration config;
} Pca2131Device;

ReturnCode Pca2131InitWithConfiguration(Pca2131Device* pca2131);

#endif  // PLATFORM_DEVICE_DRIVER_RTC_PCA2131_H_
