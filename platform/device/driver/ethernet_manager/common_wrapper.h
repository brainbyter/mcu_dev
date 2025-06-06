// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_COMMON_WRAPPER_H_
#define PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_COMMON_WRAPPER_H_

#include <stdint.h>
#include <string.h>

enum EthCfgItem {
  kEthunknown,
  kEthHwInfo,
  kEthMcuCfg,
  kEthPhyCfg,
  kEthSwitchCfg,
};

enum EthMcuCfgAttr {
  kEthMcuUnknown,
  kEthMcuGeneralCfg,
};

enum EthPhyCfgAttr {
  kEthPhyUnknown,
  kEthPhyGeneralCfg,
};

enum EthSwitchCfgAttr {
  kEthSwitchUnknown,
  kEthSwitchPortCfg,
  kEthSwitchPortVlanCfg,
};

// Note: If you want to modify the code below, please keep it the same as
// platform/device/driver/ethernet_manager/proto/common.proto

typedef enum EthSpeedType {
  kEthSpeedUnkonwn = 0,
  kEthSpeed100M = 1,
  kEthSpeed1000M = 2,
} EthSpeedType;

#endif  // PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_COMMON_WRAPPER_H_
