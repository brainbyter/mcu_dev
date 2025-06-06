// Copyright @2020 Pony AI Inc. All rights reserved.

/// @defgroup lwip_driver lwip driver

/// @defgroup lwip_ethernetif_driver lwip ethernetif driver
/// @ingroup lwip_driver
/// This is lwip ethernetif driver.

/// @file
/// @ingroup lwip_ethernetif_driver
/// @brief the header file for lwip ethernetif driver

#ifndef PLATFORM_DEVICE_DRIVER_LWIP_NETIF_ETHERNETIF_H_
#define PLATFORM_DEVICE_DRIVER_LWIP_NETIF_ETHERNETIF_H_

#include "lwip/ip.h"

#include "common/mcu/utils/status.h"

// Call this API before LwipInitEthernetIf. And make sure the length of the 3 arrays are 4bytes.
/// @ingroup lwip_ethernetif_driver
/// @brief Set the IP address, gateway and network mask of the ethernet interface.
/// @param user_ip [uint8_t*] The pointer to the IP address array (4 bytes)
/// @param user_gateway [uint8_t*] The pointer to the gateway array (4 bytes)
/// @param user_mask [uint8_t*] The pointer to the network mask array (4 bytes)
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetEthernetifIpGatewayNetworkMask(uint8_t* user_ip,
                                             uint8_t* user_gateway,
                                             uint8_t* user_mask);

// Call this API before LwipInitEthernetIf. And make sure the length of the array are 6bytes.
/// @ingroup lwip_ethernetif_driver
/// @brief Set the MAC address of the ethernet interface.
/// @param mac_address [uint8_t*] The pointer to the MAC address array (6 bytes)
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetEthernetifMac(uint8_t* mac_address);

/// @ingroup lwip_ethernetif_driver
/// @brief Initialize the lwIP stack and add ethernet interface.
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode LwipInitEthernetIf(void);

/// @ingroup lwip_ethernetif_driver
/// @brief Set link up (called when PHY link up).
/// @return void
void LwipSetLinkUpEthernetIf(void);

/// @ingroup lwip_ethernetif_driver
/// @brief Set link down (called when PHY link down).
/// @return void
void LwipSetLinkDownEthernetIf(void);

/// @ingroup lwip_ethernetif_driver
/// @brief Get local IP address, net mask, and gateway.
/// @param ip [ip_addr_t*] The pointer to store the IP address
/// @param mask [ip_addr_t*] The pointer to store the network mask
/// @param gateway [ip_addr_t*] The pointer to store the gateway
/// @return void
void LwipGetLocalIpConfig(ip_addr_t* ip, ip_addr_t* mask, ip_addr_t* gateway);

/// @ingroup lwip_ethernetif_driver
/// @brief Called in main loop, non-blocking.
/// @return void
void LwipTask(void);

#endif  // PLATFORM_DEVICE_DRIVER_LWIP_NETIF_ETHERNETIF_H_
