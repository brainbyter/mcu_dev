// Copyright @2021 Pony AI Inc. All rights reserved.

/// @defgroup switch_driver switch driver

/// @defgroup switch_platform_common_driver marvell switch platform common driver
/// @ingroup switch_driver
/// This is marvell switch platform common driver.

/// @file
/// @ingroup switch_platform_common_driver
/// @brief the header file for marvell switch platform common driver

#ifndef PLATFORM_DEVICE_DRIVER_SWITCH_COMMON_H_
#define PLATFORM_DEVICE_DRIVER_SWITCH_COMMON_H_

#include "common/driver/marvell/switch_common.h"
#include "common/mcu/utils/status.h"
#include "platform/device/driver/phy/network_phy.h"

/// @ingroup switch_platform_common_driver
/// @brief A structure to store the common configuration of the switch device.
typedef struct SwitchCommonConfiguration {
  pony_network_phy_t net;  ///< The network PHY configuration of the switch device
  int16_t reset_pin;       ///< The reset pin number of the switch device
  int16_t int_pin;         ///< The interrupt pin number of the switch device
} SwitchCommonConfiguration;

/// @ingroup switch_platform_common_driver
/// @brief A structure to store the Marvell switch device and its common configuration.
typedef struct MarvellSwitchDevice {
  MarvellSwitch dev;                 ///< The Marvell switch device
  SwitchCommonConfiguration config;  ///< The common configuration of the switch
} MarvellSwitchDevice;

/// @ingroup switch_platform_common_driver
/// @brief A macro to initialize a Marvell switch device and its common configuration with given
/// parameters.
#define SWITCH_COMMON(addr, switch_name, num, smi_bus_num, reset_pin_num) \
  {                                                                       \
    .dev.address = addr, .dev.name = switch_name, .dev.dev_num = num,     \
    .config.net.bus_num = smi_bus_num, .config.net.address = addr,        \
    .config.reset_pin = reset_pin_num, .config.int_pin = -1,              \
  }

/// @ingroup switch_platform_common_driver
/// @brief Initialize a Marvell switch device with its common configuration.
/// @param dev [MarvellSwitchDevice*] The pointer to the Marvell switch device and its common
/// configuration
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SwitchCommonInitWithConfiguration(MarvellSwitchDevice* dev);

/// @ingroup switch_platform_common_driver
/// @brief Initialize a Marvell switch device only its common configuration.
/// @param dev [MarvellSwitchDevice*] The pointer to the Marvell switch device and its common
/// configuration
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SwitchCommonInitOnlyConfiguration(MarvellSwitchDevice* dev);

#endif  // PLATFORM_DEVICE_DRIVER_SWITCH_COMMON_H_
