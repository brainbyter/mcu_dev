// Copyright @2023 Pony AI Inc. All rights reserved.

/// @defgroup lwip_driver lwip driver

/// @defgroup lwip_ping_driver lwip ping driver
/// @ingroup lwip_driver
/// This is lwip ping driver.

/// @file
/// @ingroup lwip_ping_driver
/// @brief the header file for lwip ping driver

#ifndef PLATFORM_DEVICE_LWIP_PING_CLIENT_H_
#define PLATFORM_DEVICE_LWIP_PING_CLIENT_H_

#include "lwip/ip_addr.h"

#include "common/mcu/utils/status.h"

/// @ingroup lwip_ping_driver
/// @brief Init lwip ping service, only ping service initialized, then can use LwipPingSend.
/// @param dev_id [uint16_t] The ping identifier of the service
/// @return ReturnCode: if succeed, return ERROR_OK; if fail, return the error code.
ReturnCode InitLwipPingService(uint16_t ping_id);

/// @ingroup lwip_ping_driver
/// @brief Send a ping request to the destination IP address with the specified data and length.
/// @param dest_ip [ip_addr_t] The destination IP address to ping
/// @param data [uint8_t*] The pointer to the data buffer to send
/// @param length [int] The length of the data buffer in bytes
/// @return ReturnCode: if succeed, return ERROR_OK; if fail, return the error code.
ReturnCode LwipPingSend(ip_addr_t dest_ip, uint8_t* data, int length);

/// @ingroup lwip_ping_driver
/// @brief Deinit lwip ping service, free the resources and stop the ping service.
/// @return void
void DeInitLwipPingService(void);

#endif  // PLATFORM_DEVICE_LWIP_PING_CLIENT_H_
