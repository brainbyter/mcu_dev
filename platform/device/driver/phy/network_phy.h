// Copyright @2020 Pony AI Inc. All rights reserved.

/// @defgroup phy_driver phy driver

/// @defgroup network_phy_platform_driver network phy platform driver
/// @ingroup phy_driver
/// This is network phy platform driver.

/// @file
/// @ingroup network_phy_platform_driver
/// @brief the header file for network phy platform driver.

#ifndef PLATFORM_DEVICE_DRIVER_PHY_NETWORK_PHY_H_
#define PLATFORM_DEVICE_DRIVER_PHY_NETWORK_PHY_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

// Usually network PHYs have these registers
#define PHY_REGADDR_CONTROL 0
#define PHY_REGADDR_STATUS 1
#define PHY_REGADDR_ID_1 2
#define PHY_REGADDR_ID_2 3

/// @ingroup network_phy_platform_driver
/// @brief A structure to store the network PHY configuration.
typedef struct PonyNetworkPhy {
  uint16_t bus_num;  // mdio / i2c bus number
  uint8_t address;   // slave address
} pony_network_phy_t;

/// @ingroup network_phy_platform_driver
/// @brief Transfer data to or from a network PHY register.
/// @param dev [pony_network_phy_t*] The pointer to the network PHY configuration
/// @param is_read [uint8_t] Whether to read or write data (0 for write, 1 for read)
/// @param reg_addr [uint8_t] The register address to transfer data
/// @param value [uint16_t*] The pointer to the data to write or read
/// @return ReturnCode: if succeed, return ERROR_OK.
extern ReturnCode NetworkPhyTransfer(pony_network_phy_t* dev,
                                     uint8_t is_read,
                                     uint8_t reg_addr,
                                     uint16_t* value);

/// @ingroup network_phy_platform_driver
/// @brief Read data from a network PHY register.
/// @param dev [pony_network_phy_t*] The pointer to the network PHY configuration
/// @param reg_addr [uint8_t] The register address to read data
/// @param value [uint16_t*] The pointer to store the data read
/// @return ReturnCode: if succeed, return ERROR_OK.
extern ReturnCode NetworkPhyRead(pony_network_phy_t* dev, uint8_t reg_addr, uint16_t* value);

/// @ingroup network_phy_platform_driver
/// @brief Write data to a network PHY register.
/// @param dev [pony_network_phy_t*] The pointer to the network PHY configuration
/// @param reg_addr [uint8_t] The register address to write data
/// @param value [uint16_t] The data to write
/// @return ReturnCode: if succeed, return ERROR_OK.
extern ReturnCode NetworkPhyWrite(pony_network_phy_t* dev, uint8_t reg_addr, uint16_t value);

/// @ingroup network_phy_platform_driver
/// @brief Write bits to a network PHY register.
/// @param dev [pony_network_phy_t*] The pointer to the network PHY configuration
/// @param reg_addr [uint8_t] The register address to write bits
/// @param offset [uint8_t] The bit offset to write bits
/// @param length [uint8_t] The bit length to write bits
/// @param value [uint16_t] The bits to write
/// @return ReturnCode: if succeed, return ERROR_OK.
extern ReturnCode NetworkPhyWriteBits(
    pony_network_phy_t* dev, uint8_t reg_addr, uint8_t offset, uint8_t length, uint16_t value);

/// @ingroup network_phy_platform_driver
/// @brief Probe all network PHY devices on a bus.
/// @param bus_num [uint16_t] The bus number to probe
/// @return ReturnCode: if succeed, return ERROR_OK.
extern ReturnCode NetworkPhyProbeAllDevOnBus(uint16_t bus_num);

#endif  // PLATFORM_DEVICE_DRIVER_PHY_NETWORK_PHY_H_
