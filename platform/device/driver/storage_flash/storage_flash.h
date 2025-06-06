// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_STORAGE_FLASH_H_
#define PLATFORM_DEVICE_DRIVER_STORAGE_FLASH_H_

#include "common/mcu/utils/status.h"

typedef struct StorageFlash {
  ReturnCode (*EraseFlash)(uint32_t erase_addr, uint32_t data_len);
  ReturnCode (*WriteFlash)(uint32_t write_addr, const uint8_t* data, uint32_t data_len);
  ReturnCode (*ReadFlash)(uint32_t read_addr, uint8_t* data, uint32_t data_len);
} StorageFlash;

ReturnCode StorageFlashInit(StorageFlash* dev);

#endif  // PLATFORM_DEVICE_DRIVER_STORAGE_FLASH_H_
