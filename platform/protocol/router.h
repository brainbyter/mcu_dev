// Copyright @2019 Pony AI Inc. All rights reserved.

/// @defgroup protocol protocol

/// @defgroup router hwprotocol router
/// @ingroup protocol
/// This is router of hwprotocol. Router will receive hwprotocol cmds and send hwprotocol cmd based
/// on the product_comm.h's router table. The router table should define local device id:
/// PONY_LOCAL_DEVICE_ID (means the MCU device runs the router)、
/// interface table:PONY_INTERFACE_TABLE and route table: PONY_ROUTE_TABLE.
/// PONY_INTERFACE_TABLE is a list of the communication ports to outside devices. Now support uart
/// CAN、Tcp、Udp. PONY_ROUTE_TABLE is a list of the routes to the hwprotocol device.

/// @file
/// @ingroup router
/// @brief the header file for hwprotocol router

#ifndef PROTOCOL_ROUTER_H_
#define PROTOCOL_ROUTER_H_

#include <stdbool.h>

#include "common/utilities/hwprotocol.h"
#include "platform/component/ringbuffer.h"

/// @file
/// @ingroup router
/// @brief the interface now router support.
enum InterfaceType {
  /// the port is a uart based on bsp_uart
  kInterfaceUart,
  /// the port is a CAN 
  kInterfaceCan,
  /// the port is a tcp server based on lwip
  kInterfaceLwipTcpSever,
  /// the port is a tcp client based on lwip
  kInterfaceLwipTcpClient,
  /// the port is a udp port, based on FreeRTOS TCP/IP stack
  kInterfaceFreeRtosUdp,
  /// the port is a TCP port, based on FreeRTOS TCP/IP stack
  kInterfaceFreeRtosTcp,
  kInterfaceIdle,
};

/// @ingroup router
/// @brief Initial the router, the user should call this API before using the hwprotocol router.
/// @param device_cmd_table [protocol_cmd_node_t*] The cmd table added by user, the router will
/// handle the cmd by calling it's callback. Please make sure device_cmd_table is a static table.
/// It will call InitLocalProtocol defined in hwprotocol.h.
/// @param table_size [uint16_t] the length of device_cmd_table.
/// @return if succeed, return ERROR_OK.
extern ReturnCode InitLocalRouter(protocol_cmd_node_t* device_cmd_table, uint16_t table_size);
/// @ingroup router
/// @brief Send a hwprotocol cmd.
/// @param sender [uint16_t] The sender's device id.
/// @param receiver [uint16_t] The receiver's device id.
/// @param command [uint16_t] The cmd id.
/// @param type [uint8_t] The cmd's type. defined in hwprotocol.h, including post\response\request.
/// @param sequence [uint16_t] The sequence of the cmd.
/// @param data_length [uint16_t] The length of the data.
/// @param data [uint8_t*] The data to send.
/// @return return the data length that successfully sends.
extern int RouterSend(uint16_t sender, uint16_t receiver, uint16_t command, uint8_t type,
                      uint16_t sequence, uint16_t data_length, uint8_t* data);
/// @ingroup router
/// @brief Read and handle hwprotocol cmd from the hwprotocol interfaces. The user should call this
/// function periodically. This API will call CheckPacket\UnpackPacket\HandleCmd defined in
/// hwprotocol.h. The cmd will be handle dby call HandleCmd if the cmd is for the local hwprotocol
/// node. Otherwise the hwprotocol node will try to transfer it to the  target device based on
/// the PONY_ROUTE_TABLE defined in product_comm.h.
extern void HandleRouterTask(void);
/// @ingroup router
/// @brief In HandleRouterTask, router will record the counter of the data that dropped in every
/// interface. This API will print the dropped counter list.
extern void PrintDroppedCount(void);
/// @ingroup router
/// @brief Enable or disable a interface of router, if it's disabled, then HandleRouterTask will
/// not read data from this interface.
/// @param interface_type [uint8_t] The interface type defined in PONY_INTERFACE_TABLE.
/// @param interface_id [uint8_t] The interface id defined in PONY_INTERFACE_TABLE.
/// @param en [bool] True if enable, otherwise false.
/// @return true if successfully, otherwise false.
extern bool EnableInterface(uint8_t interface_type, uint8_t interface_id, bool en);
/// @ingroup router
/// @brief Check if a device id is included in PONY_ROUTE_TABLE.
/// @param router_node_device_id [uint16_t] The device id to check.
/// @return true if in PONY_ROUTE_TABLE, otherwise false.
extern bool IsDeviceInRouterTable(uint16_t router_node_device_id);

#endif  // PROTOCOL_ROUTER_H_
