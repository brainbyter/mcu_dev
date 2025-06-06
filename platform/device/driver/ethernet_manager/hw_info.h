// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_HW_INFO_H_
#define PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_HW_INFO_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"
#include "platform/device/driver/ethernet_manager/hw_info_wrapper.h"

ReturnCode EncodeHwInfo(uint8_t* serialized_buffer, int* len, int max_len, const HardwareInfo* arg);

#endif  // PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_HW_INFO_H_
