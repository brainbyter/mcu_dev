// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_SWITCH_PORT_VLAN_WRAPPER_H_
#define PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_SWITCH_PORT_VLAN_WRAPPER_H_

#include <stdint.h>

#include "platform/product/common/pony_driver.h"

// Note: If you want to modify the code below, please keep it the same as
// platform/device/driver/ethernet_manager/proto/switch/port_vlan_cfg.proto

typedef enum EthSwitchVlanMemberMode {
  kEthSwitchMemberUnmodified = 0,
  kEthSwitchMemberUntagged = 1,
  kEthSwitchMembertagged = 2,
  kEthSwitchNotMember = 3,
} EthSwitchVlanMemberMode;

typedef struct EthSwitchPortVlanMode {
  uint8_t port_index;
  EthSwitchVlanMemberMode port_mode;
} EthSwitchPortVlanMode;

typedef struct EthSwitchPortVlanNode {
  uint32_t vlan_id;
  uint32_t port_num;
  EthSwitchPortVlanMode port_vlan[ETHERNET_MAX_SWITCH_PORT_NUM];
} EthSwitchPortVlanNode;

typedef struct EthSwitchPortVlanTable {
  uint8_t port_vlan_node_num;
  EthSwitchPortVlanNode port_vlan_node[ETHERNET_MAX_SWITCH_PORT_VLAN_NUM];
} EthSwitchPortVlanTable;

#endif  // PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_SWITCH_PORT_VLAN_WRAPPER_H_
