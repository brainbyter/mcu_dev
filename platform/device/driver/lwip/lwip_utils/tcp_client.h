// Copyright @2020 Pony AI Inc. All rights reserved.

/// @defgroup lwip_driver lwip driver

/// @defgroup lwip_tcp_client_driver lwip tcp client driver
/// @ingroup lwip_driver
/// This is lwip tcp client driver.

/// @file
/// @ingroup lwip_tcp_client_driver
/// @brief the header file for lwip tcp client driver

#ifndef PLATFORM_DEVICE_LWIP_TCP_CLIENT_H_
#define PLATFORM_DEVICE_LWIP_TCP_CLIENT_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"
#include "platform/product/common/pony_driver.h"

#ifndef LWIP_TCP_CLIENT_MAX_NUM
#define LWIP_TCP_CLIENT_MAX_NUM 2
#endif

/// @ingroup lwip_tcp_client_driver
/// @brief The enumeration of the lwIP TCP client status
typedef enum LwipTcpClientStatus {
  kLwipTcpClientStatusIdle = 0,    ///< The client is idle and not connected
  kLwipTcpClientStatusConnecting,  ///< The client is trying to connect to the server
  kLwipTcpClientStatusConnected,   ///< The client is connected to the server
  kLwipTcpClientStatusRefused,     ///< The client connection is refused by the server
} LwipTcpClientStatus;

/// @ingroup lwip_tcp_client_driver
/// @brief Initialize a lwIP TCP client with dev_id
/// The client will try to connect to remote_ip:remote_port
/// When reading from the client, the data is actually read from a RX ringbuffer.
/// When writing to the client, the data is first written to a TX ringbuffer.
/// @param dev_id [uint32_t] The device id of the client
/// @param remote_ip [const char*] The remote IP address to connect to
/// @param remote_port [uint32_t] The remote port to connect to
/// @param rx_buf [uint8_t*] The pointer to the RX buffer
/// @param rx_buf_capability [uint32_t] The capability of the RX buffer in bytes
/// @param tx_buf [uint8_t*] The pointer to the TX buffer
/// @param tx_buf_capability [uint32_t] The capability of the TX buffer in bytes
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode InitLwipTcpClient(uint32_t dev_id,
                             const char* remote_ip,
                             uint32_t remote_port,
                             uint8_t* rx_buf,
                             uint32_t rx_buf_capability,
                             uint8_t* tx_buf,
                             uint32_t tx_buf_capability);

/// @ingroup lwip_tcp_client_driver
/// @brief Start to try to connect to the remote server.
/// @param dev_id [uint32_t] The device id of the client
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode LwipTcpClientConnect(uint32_t dev_id);

/// @ingroup lwip_tcp_client_driver
/// @brief Get the status of the client. Status codes are listed in LwipTcpClientStatus
/// @param dev_id [uint32_t] The device id of the client
/// @param status [LwipTcpClientStatus*] The pointer to store the status of the client
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode LwipTcpClientGetStatus(uint32_t dev_id, LwipTcpClientStatus* status);

/// @ingroup lwip_tcp_client_driver
/// @brief Close the client connection (if connected) or stop trying to connect to remote server.
/// @param dev_id [uint32_t] The device id of the client
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode LwipTcpClientCloseConnection(uint32_t dev_id);

/// @ingroup lwip_tcp_client_driver
/// @brief Non-blocking write to the client.
/// If LwipTcpClientConnect is not called in ahead, the writing operation will fail.
/// If LwipTcpClientConnect is called ahead, but the client is not connected to a server,
/// the data will be written to the ringbuffer first, and will be sent out when client is connected.
/// @param dev_id [uint32_t] The device id of the client
/// @param data [const uint8_t*] The pointer to the data to write
/// @param len [uint32_t] The length of the data to write in bytes
/// @return int32_t: The number of bytes written, or -1 if failed.
int32_t LwipTcpClientWrite(uint32_t dev_id, const uint8_t* data, uint32_t len);

/// @ingroup lwip_tcp_client_driver
/// @brief Non-blocking read from the client.
/// RX data will be put into RX ringbuffer first. This function then reads from the RX ringbuffer.
/// @param dev_id [uint32_t] The device id of the client
/// @param data [uint8_t*] The pointer to store the read data
/// @param max_size [uint32_t] The maximum size of the data to read in bytes
/// @return int32_t: The number of bytes read, or -1 if failed.
int32_t LwipTcpClientRead(uint32_t dev_id, uint8_t* data, uint32_t max_size);

/// @ingroup lwip_tcp_client_driver
/// @brief Check if the client is connected to the server.
/// @param dev_id [uint32_t] The device id of the client
/// @return bool: True if connected, false otherwise.
bool IsTcpClientConnected(uint32_t dev_id);

#endif  // PLATFORM_DEVICE_LWIP_TCP_CLIENT_H_
