// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_COMMON_H_
#define PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_COMMON_H_

#include "platform/device/driver/ethernet_manager/common_wrapper.h"
#include "platform/device/driver/ethernet_manager/proto/common.pb.h"

platform_ethernet_common_EthSpeedType EthSpeedTypeToProto(EthSpeedType type);
EthSpeedType ProtoToEthSpeedType(platform_ethernet_common_EthSpeedType type);

#endif  // PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_COMMON_H_
