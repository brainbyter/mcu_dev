// Copyright @2022 Pony AI Inc. All rights reserved.

/// @defgroup lwip_driver lwip driver

/// @defgroup lwip_udp_server_driver lwip udp server driver
/// @ingroup lwip_driver
/// This is lwip udp server driver.

/// @file
/// @ingroup lwip_udp_server_driver
/// @brief the header file for lwip udp server driver

#ifndef PLATFORM_DEVICE_LWIP_UDP_SERVER_H_
#define PLATFORM_DEVICE_LWIP_UDP_SERVER_H_

#include <stdint.h>

#include "lwip/udp.h"

#include "common/mcu/utils/status.h"
#include "platform/product/common/pony_driver.h"

#ifndef LWIP_UDP_SERVER_MAX_NUM
#define LWIP_UDP_SERVER_MAX_NUM 16
#endif

#ifndef UDP_MAX_DATA_LEN
#define UDP_MAX_DATA_LEN 256
#endif

/// @ingroup lwip_udp_server_driver
/// @brief The structure of a UDP frame for lwIP
typedef struct PonyLwipUdpFrame {
  ip_addr_t* addr;                 ///< The pointer to the IP address of the frame
  uint16_t port;                   ///< The port number of the frame
  uint16_t len;                    ///< The length of the data in bytes
  uint8_t data[UDP_MAX_DATA_LEN];  ///< The data buffer of the frame
} __attribute__((packed)) PonyLwipUdpFrame;

/// @ingroup lwip_udp_server_driver
/// @brief Initialize a lwIP UDP server with dev_id.
/// When reading from the server, the data is actually read from a RX ringbuffer.
/// @param dev_id [uint32_t] The device id of the server
/// @param port_num [uint16_t] The port number to listen on
/// @param rx_buf [uint8_t*] The pointer to the RX buffer
/// @param rx_buf_capability [uint32_t] The capability of the RX buffer in bytes
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode InitLwipUdpServer(uint32_t dev_id,
                             uint16_t port_num,
                             uint8_t* rx_buf,
                             uint32_t rx_buf_capability);

/// @ingroup lwip_udp_server_driver
/// @brief Start the server.
/// @param dev_id [uint32_t] The device id of the server
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode LwipUdpServerStart(uint32_t dev_id);

/// @ingroup lwip_udp_server_driver
/// @brief Stop the server.
/// @param dev_id [uint32_t] The device id of the server
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode LwipUdpServerStop(uint32_t dev_id);

/// @ingroup lwip_udp_server_driver
/// @brief Write to the server.
/// @param dev_id [uint32_t] The device id of the server
/// @param data [uint8_t*] The pointer to the data to write
/// @param size [uint32_t] The size of the data to write in bytes
/// @return int32_t: The number of bytes written, or -1 if failed.
int32_t LwipUdpServerWrite(uint32_t dev_id, uint8_t* data, uint32_t size);

/// @ingroup lwip_udp_server_driver
/// @brief Non-blocking read from the server.
/// RX frame will be put into RX ringbuffer first. This function then reads from the RX ringbuffer.
/// @param dev_id [uint32_t] The device id of the server
/// @param data [uint8_t*] The pointer to store the read data
/// @param max_size [uint32_t] The maximum size of the data to read in bytes
/// @return int32_t: The number of bytes read, or -1 if failed.
int32_t LwipUdpServerRead(uint32_t dev_id, uint8_t* data, uint32_t max_size);

/// @ingroup lwip_udp_server_driver
/// @brief Config the destination IP addr and port to send.
/// @param dev_id [uint32_t] The device id of the server
/// @param addr [ip_addr_t*] The pointer to the destination IP address
/// @param port [uint16_t] The destination port number
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode LwipUdpServerConfigDst(uint32_t dev_id, ip_addr_t *addr, uint16_t port);

/// @ingroup lwip_udp_server_driver
/// @brief Join in the Igmp.
/// @param dev_id [uint32_t] The device id of the server
/// @param igmp_ip [ip_addr_t*] The pointer to the Igmp IP address
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode LwipUdpServerJoinIgmp(uint32_t dev_id, ip_addr_t* igmp_ip);

/// @ingroup lwip_udp_server_driver
/// @brief Drop the data in UDP buffer.
/// @param dev_id [uint32_t] The device id of the server
/// @param size [uint32_t] The size to drop.
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode LwipUdpServerDropData(uint32_t dev_id, uint32_t size);

/// @ingroup lwip_udp_server_driver
/// @brief Check the UDP free buffer size.
/// @param dev_id [uint32_t] The device id of the server
/// @param size [int*] The pointer to the free buffer size.
/// @return int: The free buffer size, or -1 if failed.
int LwipUdpServerCheckFreeBufferSize(uint32_t dev_id);

#endif  // PLATFORM_DEVICE_LWIP_UDP_SERVER_H_
