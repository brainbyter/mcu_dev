// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_NUT_AURIX_F0100_03_0001_AURIX_SYSTEM_H_
#define PRODUCTS_F0100_0001_NUT_AURIX_F0100_03_0001_AURIX_SYSTEM_H_

#define PONY_SYSTEM_FREQ_HZ 1000

// D0Flash space is used as the table below:
// |---------|--------------------------|--------|
// |   NVM   |  0xaf000000 ~ 0xaf080000 |  512k  |
// |---------|--------------------------|--------|
// |   LOG   |  0xaf080000 ~ 0xaf0df000 |  380k  |
// |---------|--------------------------|--------|
// | Config1 |  0xaf0df000 ~ 0xaf0e0000 |   4k   |
// |---------|--------------------------|--------|
// |   BIN   |  0xaf0e0000 ~ 0xaf100000 |  128k  |
// |---------|--------------------------|--------|

// MAC address of device.
// 62:80:89:81:1C:60
#define ETHERNET_CONF_ETHADDR0 0x62
#define ETHERNET_CONF_ETHADDR1 0x80
#define ETHERNET_CONF_ETHADDR2 0x89
#define ETHERNET_CONF_ETHADDR3 0x81
#define ETHERNET_CONF_ETHADDR4 0x1C
#define ETHERNET_CONF_ETHADDR5 0x60

// The IP address
#define ETHERNET_CONF_IPADDR0 192
#define ETHERNET_CONF_IPADDR1 168
#define ETHERNET_CONF_IPADDR2 1
#define ETHERNET_CONF_IPADDR3 65

// The gateway address being used.
#define ETHERNET_CONF_GATEWAY_ADDR0 192
#define ETHERNET_CONF_GATEWAY_ADDR1 168
#define ETHERNET_CONF_GATEWAY_ADDR2 1
#define ETHERNET_CONF_GATEWAY_ADDR3 1

// The network mask being used.
#define ETHERNET_CONF_NET_MASK0 255
#define ETHERNET_CONF_NET_MASK1 255
#define ETHERNET_CONF_NET_MASK2 255
#define ETHERNET_CONF_NET_MASK3 0

// Destination of mcu eth packet data.
#define ETHERNET_CONF_REMOTE_IPADDR0 192
#define ETHERNET_CONF_REMOTE_IPADDR1 168
#define ETHERNET_CONF_REMOTE_IPADDR2 1
#define ETHERNET_CONF_REMOTE_IPADDR3 100

#define LOADER_VERSION_ADDRESS 0xaf0f5000
// Loader related
#define USING_LOADER_V2
#define LOADER_FLAG_ADDRESS 0xaf0fc000
#define APP_BANK_NUM 12

#define AB_LOADER_ACTIVE_INFO_ADDRESS 0xaf0fd000
#define AB_LOADER_SLOT_A_INFO_ADDRESS 0xaf0fe000
#define AB_LOADER_SLOT_B_INFO_ADDRESS 0xaf0ff000
// App Addresses
#define SLOT_A_APP_ADDRESS 0xA0100000
#define SLOT_B_APP_ADDRESS 0xA0700000

#if defined(AB_LOADER_FIRMWARE_SLOT_A)
// For Slot A app, we would burn Slot B.
// So we point the APP_INFO_ADDRESS and APP_START_ADDRESS to Slot B.
#define APP_INFO_ADDRESS AB_LOADER_SLOT_B_INFO_ADDRESS
#define APP_START_ADDRESS SLOT_B_APP_ADDRESS
#elif defined(AB_LOADER_FIRMWARE_SLOT_B) || defined(AB_LOADER_FIRMWARE_LOADER)
// For Slot B app and loader, we would burn Slot A.
// So we point the APP_INFO_ADDRESS and APP_START_ADDRESS to Slot A.
#define APP_INFO_ADDRESS AB_LOADER_SLOT_A_INFO_ADDRESS
#define APP_START_ADDRESS SLOT_A_APP_ADDRESS
#else
#define APP_INFO_ADDRESS 0x0
#define APP_START_ADDRESS 0x0
#error "Please specify whether you are building for Slot A, B, or loader."
#endif

#define CONFIG1_MANAGER_START_ADDRESS 0xaf0df000

#define ACTIVE0_INFO_ADDRESS 0xaf0fb000
#define ACTIVE1_INFO_ADDRESS 0xaf0fa000

#define ORINA_SLOTA_INFO_ADDRESS  0xaf0f9000
#define ORINA_SLOTB_INFO_ADDRESS  0xaf0f8000

#ifdef AB_LOADER_FIRMWARE_LOADER
#include "common/mcu/tc39b/tc39b_flash_start_a0080000.h"
#endif

#endif  // PRODUCTS_F0100_0001_NUT_AURIX_F0100_03_0001_AURIX_SYSTEM_H_
