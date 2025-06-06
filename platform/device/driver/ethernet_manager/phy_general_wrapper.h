// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_PHY_GENERAL_WRAPPER_H_
#define PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_PHY_GENERAL_WRAPPER_H_

#include <stdint.h>

#include "platform/device/driver/ethernet_manager/common_wrapper.h"
#include "platform/product/common/pony_driver.h"

// Note: If you want to modify the code below, please keep it the same as
// platform/device/driver/ethernet_manager/proto/phy/general_cfg.proto

typedef enum EthPhyRoleType {
  kEthPhyRoleUnkonwn = 0,
  kEthPhyRoleSlave = 1,
  kEthPhyRoleMaster = 2,
} EthPhyRoleType;

typedef struct EthPhyGeneral {
  EthSpeedType speed;
  EthPhyRoleType role;
} EthPhyGeneral;

#endif  // PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_PHY_GENERAL_WRAPPER_H_
