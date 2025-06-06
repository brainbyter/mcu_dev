// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_PHY_GENERAL_H_
#define PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_PHY_GENERAL_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

ReturnCode EncodeEthPhyGeneral(
    uint8_t* serialized_buffer, int* len, int max_len, int dev_index, void* phy_general_data);
ReturnCode DecodeEthPhyGeneral(const uint8_t* buffer, int buffer_len, int dev_index);

#endif  // PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_PHY_GENERAL_H_
