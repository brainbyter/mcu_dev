// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_MCU_GENERAL_WRAPPER_H_
#define PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_MCU_GENERAL_WRAPPER_H_

#include <stdint.h>

#include "platform/product/common/pony_driver.h"

// The version string lengths
#define ERHERNET_MAX_VERSION_LEN 20

// Mac address length
#define ETHERNET_MAC_ADDRESS_LEN 6

// IPv4 address length is supported by default, if you want to
// support ipv6 please define ETHERNET_SUPPORT_IPV6
#ifdef ETHERNET_SUPPORT_IPV6
#define ETHERNET_IP_ADDRESS_LEN 16
#else
#define ETHERNET_IP_ADDRESS_LEN 4
#endif  // ETHERNET_SUPPORT_IPV6

// Note: If you want to modify the code below, please keep it the same as
// platform/device/driver/ethernet_manager/proto/mcu/general_cfg.proto

typedef struct EthMcuFlag {
  // ethernet module support configuration change
  uint32_t support_config_change : 1;
  // the flag controls whether all switches load vlan configurations
  uint32_t switch_support_vlan : 1;
  uint32_t reserved : 30;
} __attribute__((packed)) EthMcuFlag;

typedef struct EthMcuGeneral {
  char version[ERHERNET_MAX_VERSION_LEN];
  EthMcuFlag mcu_flag;
  uint8_t mac[ETHERNET_MAC_ADDRESS_LEN];
  uint8_t ip[ETHERNET_IP_ADDRESS_LEN];
  uint8_t gateway[ETHERNET_IP_ADDRESS_LEN];
  uint8_t netmask[ETHERNET_IP_ADDRESS_LEN];
} EthMcuGeneral;

#endif  // PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_MCU_GENERAL_WRAPPER_H_
