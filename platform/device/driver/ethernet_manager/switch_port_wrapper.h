// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_SWITCH_PORT_WRAPPER_H_
#define PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_SWITCH_PORT_WRAPPER_H_

#include <stdint.h>

#include "platform/device/driver/ethernet_manager/common_wrapper.h"
#include "platform/product/common/pony_driver.h"

// Note: If you want to modify the code below, please keep it the same as
// platform/device/driver/ethernet_manager/proto/switch/port_cfg.proto

typedef enum EthSwitchVlanStrategy {
  kEthSwitch8021qDisable = 0,
  kEthSwitch8021qFallback = 1,
  kEthSwitch8021qCheck = 2,
  kEthSwitch8021qSecure = 3,
} EthSwitchVlanStrategy;

typedef struct EthSwitchPort {
  uint8_t port_index;
  // When 8021.Q is enabled on this port that the default_vlan_id is assigned to untagged frames
  uint32_t default_vlan_id;
  // When this is set to a one that each ingress frame's VID is ignored and
  // the default_vlan_id is assigned and replaced into the frame.
  bool force_default_vlan_id;
  // When this is set to a one, the ingress frame's with a VID of 0x000 will get an initial vlan_id
  bool allow_vlan_id_zero;
  EthSwitchVlanStrategy vlan_strategy;
  EthSpeedType speed;
} EthSwitchPort;

typedef struct EthSwitchPortTable {
  uint8_t port_count;
  EthSwitchPort port[ETHERNET_MAX_SWITCH_PORT_NUM];
} EthSwitchPortTable;

#endif  // PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_SWITCH_PORT_WRAPPER_H_
