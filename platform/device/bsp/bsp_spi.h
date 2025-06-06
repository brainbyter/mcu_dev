// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_BSP_SPI_H_
#define PLATFORM_DEVICE_BSP_SPI_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "common/mcu/utils/status.h"

enum SpiMasterIoctlCmd {
  // Enable/disable loopback mode.
  kSpiIoctlEnableLoopback,
  kSpiIoctlDisableLoopback,
  // Enable/disable fixed slave mode for SAMV71 device.
  kSpiIoctlEnableFixedSlave,
  kSpiIoctlDisableFixedSlave,
};

typedef enum PonySpiInterruptType {
  kPonySpiInterruptRxDataRegFull,
  kPonySpiInterruptTxDataRegEmpty,
  kPonySpiInterruptOverRun,
  kPonySpiInterruptUnderRun,
  kPonySpiInterruptNssRising,
} PonySpiInterruptType;

typedef void (*PonySpiSlaveCallback)(uint16_t bus_num, PonySpiInterruptType type, void* user_data);

struct PonySpiSlaveDevice;
typedef struct PonySpiMasterBus {
  uint16_t bus_num;
  uint16_t num_chip_select;
  uint32_t (*master_transfer)(const struct PonySpiMasterBus* bus,
                              const struct PonySpiSlaveDevice* slave,
                              const uint8_t* out_buf,
                              uint8_t* in_buf,
                              uint32_t size);
  ReturnCode (*ioctl)(const struct PonySpiMasterBus* bus,
                      const struct PonySpiSlaveDevice* slave,
                      int cmd,
                      void* arg);
} PonySpiMasterBus;

typedef struct PonySpiSlaveBus {
  uint16_t bus_num;
  uint32_t (*slave_transfer)(const struct PonySpiSlaveBus* bus,
                             const uint8_t* out_buf,
                             uint8_t* in_buf,
                             uint32_t size);
} PonySpiSlaveBus;

typedef struct PonySpiSlaveDevice {
  uint16_t bus_num;
  uint16_t slave_num;
} PonySpiSlaveDevice;

// BSP Internel APIs
extern ReturnCode RegisterSpiMasterBus(const PonySpiMasterBus* bus);
extern ReturnCode RegisterSpiSlaveDevice(const PonySpiSlaveDevice* slave);
extern ReturnCode RegisterSpiSlaveBus(const PonySpiSlaveBus* bus);
extern ReturnCode SpiSlaveBusIsr(const uint16_t bus_num, PonySpiInterruptType type);

// Public user APIs
// In SPI master mode, MCU initiate a transfer by calling this function.
// Since SPI is full-duplex, MCU will also receive data to in_buf when sending data from out_buf
extern uint32_t SpiMasterTransfer(
    uint16_t bus_num, uint8_t slave_num, const uint8_t* out_buf, uint8_t* in_buf, uint32_t size);

// Control the the SPI bus, it manipulates the underlying device parameters of an SPI bus.
extern ReturnCode SpiMasterIoctl(uint16_t bus_num, uint8_t slave_num, int cmd, void* arg);

// In SPI slave mode, MCU will call the registered callbacks on interrupt of any possible
// PonySpiInterruptType.
// The callback will let the user know the type of the interrupt by it's parameters.
// The "user_data" will also be passed to the callback function
extern ReturnCode SpiSlaveRegisterCallback(uint16_t bus_num,
                                              PonySpiSlaveCallback callback,
                                              void* user_data);
// Call the SpiSlaveTransfer when the SPI master is transfering data.
// Usually this function can be called from callback function with size == 1 when there are new data
// ready
extern uint32_t SpiSlaveTransfer(uint16_t bus_num,
                                 const uint8_t* out_buf,
                                 uint8_t* in_buf,
                                 uint32_t size);

#endif  // PLATFORM_DEVICE_BSP_SPI_H_
