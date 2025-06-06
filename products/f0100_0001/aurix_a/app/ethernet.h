// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_ETHERNET_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_ETHERNET_H_

#include <stdint.h>

#include "platform/device/driver/phy/marvell/phy_88q2112.h"
#include "platform/device/driver/switch/switch_common.h"

// When not using state machine to manage the network, this API can be used to initialize switch
// and phys.
void InitSwitchsAndPhys(void);
// Only use configuration to configure Switch and Phys device structs.
void ConifgSwitchsAndPhys(void);
void InitExtendSwitchsAndPhys(void);
void PrintPhyStatus(void);
void PrintSwitchStatus(void);
void PrintSwitchCounters(void);
void SetPortTestMode(uint8_t port_num, uint8_t test_mode);
void Set88q2112Reg(uint8_t dev_num, uint8_t dev_addr, uint16_t reg_addr, uint16_t value);
void Get88q2112Reg(uint8_t dev_num, uint8_t dev_addr, uint16_t reg_addr);

void SetRmuMode(uint16_t mode);
void ResetSwitchPort(uint8_t port_num);
void ResetSwitchPortPtpTimestamp(uint8_t port_num, uint8_t timestamp_to_reset);

MarvellSwitchDevice* GetSwitchInstance(int dev_index);
Phy88q2112Device* GetPhyInstance(int dev_index);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_ETHERNET_H_
