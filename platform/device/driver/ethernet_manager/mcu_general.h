// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_MCU_GENERAL_H_
#define PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_MCU_GENERAL_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

ReturnCode EncodeEthMcuGeneral(
    uint8_t* serialized_buffer, int* len, int max_len, int dev_index, void* mcu_general_data);
ReturnCode DecodeEthMcuGeneral(const uint8_t* buffer, int buffer_len, int dev_index);

#endif  // PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_MCU_GENERAL_H_
