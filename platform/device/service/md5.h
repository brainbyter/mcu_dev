// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_SERVICE_MD5_H_
#define PLATFORM_DEVICE_SERVICE_MD5_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

ReturnCode Md5ServiceInit(void* param);
ReturnCode Md5ServiceUpdate(const uint8_t* data, uint32_t data_len, void* param);
ReturnCode Md5ServiceFinalize(uint8_t* result, uint32_t result_len, void* param);
ReturnCode Md5ServiceCalculateFromAddress(uint8_t* result,
                                          uint32_t result_len,
                                          uint32_t start_address,
                                          uint32_t len,
                                          void* param);

#endif  // PLATFORM_DEVICE_SERVICE_MD5_H_
