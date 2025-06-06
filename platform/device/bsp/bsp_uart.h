// Copyright @2019 Pony AI Inc. All rights reserved.

/// @defgroup bsp_interface bsp interface

/// @defgroup bsp_uart bsp uart
/// @ingroup bsp_interface
/// This is the abstract layer of uart. A specific MCU should implement the uart driver based on
/// PonyUartDevice and register them in this layer by RegisterUartDevice. Please define the
/// configurations in product_bsp.h and at least implement the write and read for PonyUartDevice.

/// @file
/// @ingroup bsp_uart
/// @brief the header file for bsp uart driver

#ifndef PLATFORM_DEVICE_BSP_UART_H_
#define PLATFORM_DEVICE_BSP_UART_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "common/mcu/utils/status.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @ingroup bsp_uart
/// @brief The cmd used to control uart. It's the param of IoctlUart. The MCU should adapt these
/// cmds in the MCU layer driver.
enum UartIoctlCmd {
  /// disable a target uart by IoctlUart
  kUartIoctlCmdDisableUart,
  /// enable a target uart by IoctlUart
  kUartIoctlCmdEnableUart,
};

/// @ingroup bsp_uart
/// @brief The unified uart device struct for our Uart devices. The basic MCU driver should
/// implement these parameters in MCU's uart driver.
typedef struct PonyUartDevice {
  /// The uart id is defined in the lower MCU driver. They always keep same with the hardware.
  int32_t uart_id;
  /// A flag to point if the uart is opened. This flag is just defined in bsp interface layer.
  bool enabled;
  /// The buffer used for rx.
  void* uart_rx;
  /// The buffer used for tx.
  void* uart_tx;
  /// The param for the open, close, ioctl, write, read.
  void* param;
  /// @brief open this uart, should implement this API in the MCU driver.
  /// @param param [void*] the param defined in this struct, it's usually a specific McuUartDevice.
  /// @return ReturnCode: if succeed, return ERROR_OK.
  ReturnCode (*open)(void* param);
  /// @brief close this uart, should implement this API in the MCU driver.
  /// @param param [void*] the param defined in this struct, it's usually a specific McuUartDevice.
  /// @return ReturnCode: if succeed, return ERROR_OK.
  ReturnCode (*close)(void* param);
  /// @brief control this uart, should implement this API in the MCU driver, it manipulates the
  /// underlying device parameters of special uart.
  /// @param param [void*] the param defined in this struct, it's usually a specific McuUartDevice.
  /// @param cmd [int] the cmd is defined in enum UartIoctlCmd.
  /// @param arg [void*] the argument for this cmd.
  /// @return ReturnCode: if succeed, return ERROR_OK.
  ReturnCode (*ioctl)(void* param, int cmd, void* arg);
  /// @brief write data to uart, should implement this API in the MCU driver, a requried function.
  /// @param param [void*] the param defined in this struct, it's usually a specific McuUartDevice.
  /// @param buf [uint8_t*] the buf to send.
  /// @param buf_size [uint32_t] the buf's size.
  /// @return uint32_t: return the size of the send data.
  uint32_t (*write)(void* param, const uint8_t* buf, uint32_t buf_size);
  /// @brief read data from uart, should implement this API in the MCU driver, a requried function.
  /// @param param [void*] the param defined in this struct, it's usually a specific McuUartDevice.
  /// @param buf [uint8_t*] the buf to store the data.
  /// @param buf_size [uint32_t] the buf's max size.
  /// @return uint32_t: return the size of the read data.
  uint32_t (*read)(void* param, uint8_t* buf, uint32_t max_buf_size);
} pony_uart_t, *p_pony_uart_t;

/// @ingroup bsp_uart
/// @brief Get uart numbers, based on the definition in product_bsp.h.
/// @return the number of uart num defined by product_bsp.h
uint8_t GetUartNumByBspDefines();
/// @ingroup bsp_uart
/// @brief Open a uart. An API for application and driver.
/// @param uart_id [uint32_t] The uart id is defined in MCU layer driver. It always consists of
/// MCU's definition.
/// @return if succeed, return ERROR_OK.
ReturnCode OpenUart(uint32_t uart_id);
/// @ingroup bsp_uart
/// @brief Close a uart. An API for application and driver.
/// @param uart_id [uint32_t] The uart id is defined in MCU layer driver. It always consists of
/// MCU's definition.
/// @return if succeed, return ERROR_OK.
ReturnCode CloseUart(uint32_t uart_id);
/// @ingroup bsp_uart
/// @brief Read data from a uart. An API for application and driver.
/// @param uart_id [uint32_t] The uart id is defined in MCU layer driver. It always consists of
/// MCU's definition.
/// @param buf [uint8_t*] the buf to store the data.
/// @param max_buf_size [uint32_t] the buf's max size.
/// @return if succeed, return ERROR_OK.
uint32_t ReadUart(uint32_t uart_id, uint8_t* buf, uint32_t max_buf_size);
/// @ingroup bsp_uart
/// @brief Write data to a uart. An API for application and driver.
/// @param uart_id [uint32_t] The uart id is defined in MCU layer driver. It always consists of
/// MCU's definition.
/// @param buf [uint8_t*] the buf to send.
/// @param max_buf_size [uint32_t] the buf's size.
/// @return if succeed, return ERROR_OK.
uint32_t WriteUart(uint32_t uart_id, const uint8_t* buf, uint32_t max_buf_size);
/// @ingroup bsp_uart
/// @brief control this uart, it manipulates the underlying device parameters of special uart.
/// An API for application and driver.
/// @param uart_id [uint32_t] The uart id is defined in MCU layer driver. It always consists of
/// MCU's definition.
/// @param cmd [int] the cmd is defined in enum UartIoctlCmd. Please make sure the MCU driver
/// supports the cmd.
/// @param arg [void*] the argument for this cmd.
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode IoctlUart(uint32_t uart_id, int cmd, void* arg);
/// @ingroup bsp_uart
/// @brief The basic MCU uart driver will call this function to register the real uart to this
/// abstract uart layer. An API for application and driver.
/// @param uart_descriptor [p_pony_uart_t] the pointer to the pony_uart_t defined in the MCU driver.
/// @return if succeed, return ERROR_OK.
ReturnCode RegisterUartDevice(p_pony_uart_t uart_descriptor);
/// @ingroup bsp_uart
/// @brief Print string format in the console uart. An API for lower MCU layer driver.
/// @return On success, the total number of characters written to the console uart is returned.
int PrintfPony(const char* fmt, ...);
/// @ingroup bsp_uart
/// @brief Please use scanf carefully. Because scanf will block the code. An API for application
/// and driver.
/// @return On success, the function returns the number of items of the argument list successfully
/// filled.
int ScanfPony(const char* fmt, ...);
void InitConsoleDebug(uint32_t uart_id);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // PLATFORM_DEVICE_BSP_UART_H_
