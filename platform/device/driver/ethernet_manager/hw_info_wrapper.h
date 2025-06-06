// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_HW_INFO_WRAPPER_H_
#define PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_HW_INFO_WRAPPER_H_

#include <stdint.h>
#include <string.h>

// Note: If you want to modify the code below, please keep it the same as
// platform/device/driver/ethernet_manager/proto/hw_info.proto

typedef enum HwDeviceType {
  kNetDeviceUnknown = 0,
  kNetDeviceMcu = 1,
  kNetDeviceSoc = 2,
  kNetDeviceExternal = 3,
  kNetDeviceCascade = 4,
} HwDeviceType;

typedef struct SwitchPort {
  uint8_t switch_index;
  uint8_t switch_port_index;
} SwitchPort;

typedef struct HwDeviceInfo {
  char* name;
  HwDeviceType type;
  uint8_t mcu_index;
  uint8_t phy_index;
  SwitchPort port_index;
  SwitchPort cascade_port;
} HwDeviceInfo;

typedef enum HwMcuType {
  kNetMcuUnknown = 0,
  kNetMcuTc39x,
} HwMcuType;

typedef struct HwMcuInfo {
  uint8_t index;
  HwMcuType type;
} HwMcuInfo;

typedef enum HwPhyType {
  kNetPhyUnknown = 0,
  kNetPhy88Q2112,
} HwPhyType;

typedef struct HwPhyInfo {
  uint8_t index;
  HwPhyType type;
} HwPhyInfo;

typedef enum HwSwitchType {
  kNetSwitchUnknown = 0,
  kNetSwitch88Q5072,
  kNetSwitch88Q6113,
} HwSwitchType;

typedef struct HwSwitchInfo {
  uint8_t index;
  HwSwitchType type;
} HwSwitchInfo;

typedef struct HardwareInfo {
  const HwDeviceInfo* device_info;
  const HwMcuInfo* mcu_info;
  const HwPhyInfo* phy_info;
  const HwSwitchInfo* switch_info;
} HardwareInfo;

#endif  // PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_HW_INFO_WRAPPER_H_
