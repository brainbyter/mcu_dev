// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_ETHERNET_MANAGER_H_
#define PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_ETHERNET_MANAGER_H_

#include <stdbool.h>
#include <stdint.h>

#include "common/mcu/utils/status.h"
#include "platform/device/driver/ethernet_manager/common.h"
#include "platform/device/driver/ethernet_manager/hw_info_wrapper.h"

// All EthernetManagerOps apis cannot be invoked by the application layer
typedef struct EthernetManagerOps {
  ReturnCode (*encode_hw_info)(uint8_t* serialized_buffer,
                               int* len,
                               int max_len,
                               const HardwareInfo* arg);
  bool support_mcu_general_func;
  ReturnCode (*encode_mcu_general)(uint8_t* serialized_buffer,
                                   int* len,
                                   int max_len,
                                   int dev_index,
                                   void* data);
  ReturnCode (*decode_mcu_general)(const uint8_t* buffer, int buffer_len, int dev_index);
  void* (*get_mcu_general)(int dev_index);
  bool support_phy_general_func;
  ReturnCode (*encode_phy_general)(uint8_t* serialized_buffer,
                                   int* len,
                                   int max_len,
                                   int dev_index,
                                   void* data);
  ReturnCode (*decode_phy_general)(const uint8_t* buffer, int buffer_len, int dev_index);
  void* (*get_phy_general)(int dev_index);
  bool support_switch_port_func;
  ReturnCode (*encode_switch_port)(uint8_t* serialized_buffer,
                                   int* len,
                                   int max_len,
                                   int dev_index,
                                   void* data);
  ReturnCode (*decode_switch_port)(const uint8_t* buffer, int buffer_len, int dev_index);
  void* (*get_switch_port)(int dev_index);
  bool support_switch_port_vlan_func;
  ReturnCode (*encode_switch_port_vlan)(uint8_t* serialized_buffer,
                                        int* len,
                                        int max_len,
                                        int dev_index,
                                        void* data);
  ReturnCode (*decode_switch_port_vlan)(const uint8_t* buffer, int buffer_len, int dev_index);
  void* (*get_switch_port_vlan)(int dev_index);
} EthernetManagerOps;

typedef struct EthernetManagerCfg {
  const HardwareInfo* hw_info;
  ReturnCode (*read_config)(
      int item, int attr, int dev_index, uint8_t* data, int* data_len, int max_len);
  ReturnCode (*write_config)(int item, int attr, int dev_index, uint8_t* data, int len);
  ReturnCode (*save_config)(void);
  ReturnCode (*load_config)(int item, int attr, int dev_index, const void* data);
} EthernetManagerCfg;

// The following apis are public methods that can be invoked from application
ReturnCode EthernetManagerInit(EthernetManagerCfg* cfg);
ReturnCode ReloadEthSpecificCfg(int item, int attr, int dev_index);
ReturnCode ReloadEthAllCfg(void);
void* GetEthSpecificCfg(int item, int attr, int dev_index);
bool GetEthSwitchPortVlanFlag(void);

// The following apis are private methods can only be called by other APIs of the ethernet module
ReturnCode EncodeEthCfg(int item, int attr, int dev_index, void* data, int* len, int max_len);
ReturnCode DecodeEthCfg(int item, int attr, int dev_index, const void* data, int len);
ReturnCode SaveEthCfg(void);
ReturnCode UpdateEthManagerOps(EthernetManagerOps* ops);
void UpdateEthSwitchPortVlanFlag(bool value);

#endif  // PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_ETHERNET_MANAGER_H_
