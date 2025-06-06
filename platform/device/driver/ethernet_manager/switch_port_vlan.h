// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_SWITCH_PORT_VLAN_H_
#define PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_SWITCH_PORT_VLAN_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

ReturnCode EncodeEthSwitchPortVlanTable(uint8_t* serialized_buffer,
                                        int* len,
                                        int max_len,
                                        int dev_index,
                                        void* switch_port_vlan_table_data);
ReturnCode DecodeEthSwitchPortVlanTable(const uint8_t* buffer, int buffer_len, int dev_index);

#endif  // PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_SWITCH_PORT_VLAN_H_
