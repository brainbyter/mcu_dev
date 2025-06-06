// Copyright @2021 Pony AI Inc. All rights reserved.

/// @defgroup phy_driver phy driver

/// @defgroup phy88q2112_platform_driver phy88q2112 platform driver
/// @ingroup phy_driver
/// This is phy88q2112 platform driver.

/// @file
/// @ingroup phy88q2112_platform_driver
/// @brief the header file for phy88q2112 platform driver

#ifndef PLATFORM_DEVICE_DRIVER_PHY_MARVELL_PHY_88Q2112_H_
#define PLATFORM_DEVICE_DRIVER_PHY_MARVELL_PHY_88Q2112_H_

#include "common/driver/phy/phy_88q2112.h"
#include "common/driver/phy/phy_def.h"
#include "common/mcu/utils/status.h"
#include "platform/device/driver/phy/network_phy.h"

/// @ingroup phy88q2112_platform_driver
/// @brief phy88q2112 configuraion refers to the board level
/// hardware configuration of phy88q2112
typedef struct Phy88q2112Configuraion {
  pony_network_phy_t net;
  int16_t reset_pin;
  int16_t int_pin;
} Phy88q2112Configuraion;

/// @ingroup phy88q2112_platform_driver
/// @brief phy88q2112 device can be used as a parameter for Phy88Q2112InitWithConfiguraion
/// This struct should be effectively defined
typedef struct Phy88q2112Device {
  Phy88q2112 dev;
  Phy88q2112Configuraion config;
} Phy88q2112Device;

/// @ingroup phy88q2112_platform_driver
/// @brief The macro PHY_88Q2112 used to define Phy88q2112Device
#define PHY_88Q2112(phy_name, bus, addr, c45_flag, phy_reset_pin, role, set_speed)             \
  {                                                                                            \
    .dev.name = phy_name, .dev.speed = set_speed, .dev.is_c45 = c45_flag, .dev.address = addr, \
    .dev.device_role = role, .config.net.bus_num = bus, .config.net.address = addr,            \
    .config.reset_pin = phy_reset_pin, .config.int_pin = -1,                                   \
  }

/// @ingroup phy88q2112_platform_driver
/// @brief Initialize Phy88Q2112 device with configuration, On success,
/// the basic functions of device will be initialized, such as speed, role.
/// @param dev [Phy88q2112Device*] the device need be initialize.
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112InitWithConfiguraion(Phy88q2112Device* dev);

/// @ingroup phy88q2112_platform_driver
/// @brief Initialize Phy88Q2112 device only configuration.
/// @param dev [Phy88q2112Device*] The device config needs to be initialized.
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112InitOnlyConfiguraion(Phy88q2112Device* dev);

#endif  // PLATFORM_DEVICE_DRIVER_PHY_MARVELL_PHY_88Q2112_H_
