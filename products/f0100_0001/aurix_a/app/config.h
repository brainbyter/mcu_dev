// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_CONFIG_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_CONFIG_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"
#include "platform/device/bsp/bsp_can.h"

typedef enum ProductConfig0ItemIndex {
  kItemHwVersion = 0,             // 2  bytes
  kItemSparePartNumber = 1,       // 10 bytes
  kItemSupplierIdentifier = 2,    // 6  bytes
  kItemSystemName = 3,            // 10 bytes
  kItemEcuSerialNumber = 4,       // 18 bytes
  kItemVin = 5,                   // 17 bytes
  kItemHardwareNumber = 6,        // 10 bytes
  kItemEcuManufactureDate = 7,    // 3  bytes
  kItemVehicleConfiguration = 8,  // 8  bytes
  kItemPcbaSn = 9,                // 27 bytes
  kItemFactorySn = 10,            // 29 bytes
  kItemSwitchFw = 11,             // 32 bytes
  kItemEepromMac = 12,            // 6  bytes
} ProductConfig0ItemIndex;

typedef enum ProductConfig1ItemIndex {
  kItemIndex = 0,
  kItemIp = 1,
  kItemMac = 2,
  kItemGateway = 3,
  kItemNetworkMask = 4,
  kItemUseVlan = 5,
  kItemPortConfig = 6,
  kItemSwitchPort = 7,
  kItemVlanTable = 8,
  kItemEnableRMU = 9,
  // Use this configuration to enable orin B first, and then wait the seconds by this item.
  kItemEnBWaitASecs = 10,
  kItemRemoteIp = 11,
  kItemCanIndexRadarTable = 12,
  kItemCanBaudrateConfigTable = 13,
  kItemPtpConfigTable = 14,
} ProductConfig1ItemIndex;

typedef struct ProductPhyConfig {
  uint8_t eth1_is_100m : 1;
  uint8_t eth1_is_master : 1;
  uint8_t eth2_is_100m : 1;
  uint8_t eth2_is_master : 1;
  uint8_t eth3_is_100m : 1;
  uint8_t eth3_is_master : 1;
  uint8_t eth4_is_100m : 1;
  uint8_t eth4_is_master : 1;
  uint8_t eth5_is_100m : 1;
  uint8_t eth5_is_master : 1;
  uint8_t eth6_is_100m : 1;
  uint8_t eth6_is_master : 1;
  uint8_t reserved : 4;
}  __attribute__((packed)) ProductPhyConfig;

typedef struct SwitchPortVlanNodeConfig {
  uint8_t port_num;
  uint8_t state;
}  __attribute__((packed)) SwitchPortVlanNodeConfig;

#define SWITCH_PORT 12
#define VLAN_TABLE_SIZE 8

typedef struct SwitchVlanNodeTable {
  uint16_t vlan_id;
  SwitchPortVlanNodeConfig node[SWITCH_PORT];
}  __attribute__((packed)) SwitchVlanNodeTable;

typedef struct SwitchVlanTableConfig {
  uint16_t nodes_num;
  SwitchVlanNodeTable vlan[VLAN_TABLE_SIZE];
} __attribute__((packed)) SwitchVlanTableConfig;

typedef struct CanIndexRadarTableNode {
  uint16_t can_index;
  uint16_t radar_id;
} __attribute__((packed)) CanIndexRadarTableNode;

typedef struct CanIndexBaudrateTable {
  uint8_t can_index;
  CanBaudrateConfig can_baudrate_config;
} __attribute__((packed)) CanIndexBaudrateTable;

typedef struct PtpConfigTable {
  // 0: unknown type; 1: ptp master;  2: ptp slave
  uint8_t ptp_role;
  // The interval of ptp master sends sync and follow_up, in milliseconds.
  uint8_t sync_interval;
  uint8_t follow_up_info;
  uint8_t transportSpecific;
  uint8_t reserved_1;
  uint8_t reserved_2;
  uint8_t reserved_3;
  uint8_t reserved_4;
} __attribute__((packed)) PtpConfigTable;

void InitConfigManager(void);
ReturnCode GetConfigValue(uint8_t index, uint16_t id, void* value, int value_length);
ReturnCode SetConfigValue(uint8_t index, uint16_t id, uint8_t* value, int value_length);
ReturnCode SaveConfigValue(uint8_t index);
void PrintAllConfigManagerItem(void);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_CONFIG_H_
