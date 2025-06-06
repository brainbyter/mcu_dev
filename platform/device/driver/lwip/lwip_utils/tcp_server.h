// Copyright @2020 Pony AI Inc. All rights reserved.

/// @defgroup lwip_driver lwip driver

/// @defgroup lwip_tcp_server_driver lwip tcp server driver
/// @ingroup lwip_driver
/// This is lwip tcp server driver.

/// @file
/// @ingroup lwip_tcp_server_driver
/// @brief the header file for lwip tcp server driver

#ifndef PLATFORM_DEVICE_LWIP_TCP_SERVER_H_
#define PLATFORM_DEVICE_LWIP_TCP_SERVER_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"
#include "platform/product/common/pony_driver.h"

#ifndef LWIP_TCP_SERVER_MAX_NUM
#define LWIP_TCP_SERVER_MAX_NUM 2
#endif

/// @ingroup lwip_tcp_server_driver
/// @brief Initialize a lwIP TCP server with dev_id.
/// The server will listen on port_num.
/// Note that for current implementation the server can hold ONLY ONE connection at a time.
/// When reading from the server, the data is actually read from a RX ringbuffer.
/// When writing to the server, the data is first written to a TX ringbuffer.
/// @param dev_id [uint32_t] The device id of the server
/// @param port_num [uint16_t] The port number to listen on
/// @param rx_buf [uint8_t*] The pointer to the RX buffer
/// @param rx_buf_capability [uint32_t] The capability of the RX buffer in bytes
/// @param tx_buf [uint8_t*] The pointer to the TX buffer
/// @param tx_buf_capability [uint32_t] The capability of the TX buffer in bytes
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode InitLwipTcpServer(uint32_t dev_id,
                             uint16_t port_num,
                             uint8_t* rx_buf,
                             uint32_t rx_buf_capability,
                             uint8_t* tx_buf,
                             uint32_t tx_buf_capability);

/// @ingroup lwip_tcp_server_driver
/// @brief Start the server listening and allows connection.
/// @param dev_id [uint32_t] The device id of the server
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode LwipTcpServerStart(uint32_t dev_id);

/// @ingroup lwip_tcp_server_driver
/// @brief Stop the server listening and abandon any connected clients.
/// @param dev_id [uint32_t] The device id of the server
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode LwipTcpServerStop(uint32_t dev_id);

/// @ingroup lwip_tcp_server_driver
/// @brief Non-blocking write to the server.
/// If no client is connected, the data will be written to the ringbuffer first,
/// and will be sent out when client connects.
/// @param dev_id [uint32_t] The device id of the server
/// @param data [const uint8_t*] The pointer to the data to write
/// @param len [uint32_t] The length of the data to write in bytes
/// @return int32_t: The number of bytes written, or -1 if failed.
int32_t LwipTcpServerWrite(uint32_t dev_id, const uint8_t* data, uint32_t len);

/// @ingroup lwip_tcp_server_driver
/// @brief Non-blocking read from the server.
/// RX data will be put into RX ringbuffer first. This function then reads from the RX ringbuffer.
/// @param dev_id [uint32_t] The device id of the server
/// @param data [uint8_t*] The pointer to store the read data
/// @param max_size [uint32_t] The maximum size of the data to read in bytes
/// @return int32_t: The number of bytes read, or -1 if failed.
int32_t LwipTcpServerRead(uint32_t dev_id, uint8_t* data, uint32_t max_size);

#endif  // PLATFORM_DEVICE_LWIP_TCP_SERVER_H_
