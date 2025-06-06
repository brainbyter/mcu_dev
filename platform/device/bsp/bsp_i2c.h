// Copyright @2019 Pony AI Inc. All rights reserved.

/// @defgroup bsp_interface bsp interface

/// @defgroup bsp_i2c bsp i2c
/// @ingroup bsp_interface
/// This is the implementation of the I2C interface. By calling relevant API functions, 
/// users can conveniently communicate between devices.

/// @file
/// @ingroup bsp_i2c
/// @brief the header file for bsp i2c driver

#ifndef PLATFORM_DEVICE_BSP_BSP_I2C_H_
#define PLATFORM_DEVICE_BSP_BSP_I2C_H_

#include <stdio.h>

#include "common/mcu/utils/status.h"

/// @ingroup bsp_i2c
/// @brief The write flag, one of the possible values of flags in PonyI2cMsg.
#define PONY_I2C_WR 0x0000
/// @ingroup bsp_i2c
/// @brief The read flag, one of the possible values of flags in PonyI2cMsg.
#define PONY_I2C_RD (1u << 0)
/// @ingroup bsp_i2c
/// @brief 10 bit address mode, this is a ten bit chip address, one of the possible values of flags in PonyI2cMsg.
#define PONY_I2C_ADDR_10BIT (1u << 2)  // this is a ten bit chip address  
/// @ingroup bsp_i2c
/// @brief No start signal, meaning that the current PonyI2cMsg does not send a start signal, one of the possible values of flags in PonyI2cMsg.
#define PONY_I2C_NO_START (1u << 4)
/// @ingroup bsp_i2c
/// @brief Ignoring NACK, one of the possible values of flags in PonyI2cMsg.
#define PONY_I2C_IGNORE_NACK (1u << 5)
/// @ingroup bsp_i2c
/// @brief When I2C reading, we do not ACK, one of the possible values of flags in PonyI2cMsg.
#define PONY_I2C_NO_READ_ACK (1u << 6)  // when I2C reading, we do not ACK
#define PONY_MDIO_C45_EN (1u << 15)

/// @ingroup bsp_i2c
/// @brief The cmd used to control i2c transmission. It's the param of IoctlI2c. The MCU should adapt these
/// cmds in the MCU layer driver.
typedef enum I2cIoctlCmd {
  /// Represents holding SDA for several nanoseconds.
  kI2cSetHoldSdaNs,
} I2cIoctlCmd;

/// @ingroup bsp_i2c
/// @brief Describe the structure of an I2C message, used to describe a message on the I2C bus.
typedef struct PonyI2cMsg {
  /// Slave address.
  uint16_t addr;
  /// Reading and writing symbols, etc.
  uint16_t flags;
  /// The address of the register to be read and written.
  uint32_t regaddr;
  /// The length of the address of the register.
  uint16_t regaddrlen;
  /// Msg length.
  uint16_t datalen;
  /// Pointer to msg data.
  uint8_t *data;
} pony_i2c_msg_t, *p_pony_i2c_msg_t;

typedef struct PonyI2cBus pony_i2c_bus_t, *p_pony_i2c_bus_t;

/// @ingroup bsp_i2c
/// @brief Describe the operations supported by the I2C bus. This structure 
/// is used in the MCU layer to implement the real functions for I2C buses, 
/// the application layer user should not touch this structure. 
typedef struct PonyI2cBusOps {
  /// A function pointer pointing to a function used to open an I2C bus.
  ReturnCode (*open)(pony_i2c_bus_t *bus);
  /// A function pointer pointing to a function used to close an I2C bus.
  ReturnCode (*close)(pony_i2c_bus_t *bus);
  /// A function pointer pointing to a function used for data transfer.
  uint32_t (*master_xfer)(pony_i2c_bus_t *bus, pony_i2c_msg_t msgs[], uint32_t num, void *param);
  uint32_t (*slave_xfer)(pony_i2c_bus_t *bus, pony_i2c_msg_t msgs[], uint32_t num, void *param);
  /// A function pointer pointing to a function used for IO function settings.
  ReturnCode (*ioctl)(pony_i2c_bus_t *bus, uint32_t cmd, void *arg);
} pony_i2c_bus_ops_t;

/// @ingroup bsp_i2c
/// @brief A structure used to describe the I2C bus.
 struct PonyI2cBus {
  /// Number of I2C bus.
  uint16_t number;
  /// Flag indicating whether the bus is turned on.
  uint16_t openflag;
  /// Operations supported by I2C bus.
  const pony_i2c_bus_ops_t *ops;
  void *param;
};

/// @ingroup bsp_i2c
/// @brief Registering I2C bus devices.
/// @param bus [const p_pony_i2c_bus_t] I2C bus device structure.
/// @return return ERROR_OK if registration is successful, return ERROR_INVALID_PARAM if bus is NULL,
/// return ERROR_OUT_OF_RANGE if the number of bus is greater than MAX_ I2C_ NUMBER, 
/// return ERROR_IN_USE if the bus has already been registered.
extern ReturnCode RegisterI2cBus(const p_pony_i2c_bus_t bus);
/// @ingroup bsp_i2c
/// @brief Open an I2C bus.
/// @param number [uint16_t] The number of the I2C bus to be opened.
/// @return return ERROR_OK if successfully opened, return ERROR_NOT_EXIST if bus is NULL,
/// return ERROR_OUT_OF_RANGE if the number of bus is greater than MAX_ I2C_ NUMBER.
extern ReturnCode OpenI2cBus(uint16_t number);
/// @ingroup bsp_i2c
/// @brief Close an I2C bus.
/// @param number [uint16_t] The number of the I2C bus to be closed.
/// @return return ERROR_OK if successfully closed, return ERROR_NOT_EXIST if bus is NULL,
/// return ERROR_OUT_OF_RANGE if the number of bus is greater than MAX_ I2C_ NUMBER.
extern ReturnCode CloseI2cBus(uint16_t number);
/// @ingroup bsp_i2c
/// @brief Used for transmitting data.
/// @param number [uint16_t] The number of the desired bus to use.
/// @param msgs [pony_i2c_msg_t] I2C message array.
/// @param num [uint32_t] The number of messages in the I2C message array.
/// @return return the number of successfully transmitted 
/// messages if the transmission is successful, return 0 if failed.
extern uint32_t I2cMasterTransfer(uint16_t number, pony_i2c_msg_t msgs[], uint32_t num);
/// @ingroup bsp_i2c
/// @brief Settings for IO function.
/// @param number [uint16_t] The number of the bus you want to set.
/// @param cmd [uint32_t] IO control function code. The currently supported CMDs 
/// include kI2cSetHoldSdaNs, which represent holding SDA for several nanoseconds.
/// @param arg [void*] Pointing to an integer representing the time of holding SDA.
/// @return return ERROR_OK if successful, return ERROR_INSURFFICIENT if bus is NULL,
/// return ERROR_OUT_OF_RANGE if the number of bus is greater than MAX_ I2C_ NUMBER.
extern ReturnCode IoctlI2c(uint16_t number, uint32_t cmd, void* arg);

#endif  // PLATFORM_DEVICE_BSP_BSP_I2C_H_
