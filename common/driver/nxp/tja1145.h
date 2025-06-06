// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef COMMON_DRIVER_NXP_TJA1145_H_
#define COMMON_DRIVER_NXP_TJA1145_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

#include "common/driver/nxp/tja1145_def.h"
#include "common/driver/nxp/tja1145_regdefs.h"

typedef struct Tja1145SpiFrameCmdBits {
  uint8_t cmd: 1;
  uint8_t address: 7;
} Tja1145SpiFrameCmdBits;

typedef struct Tja1145Settings {
  Tja1145SettingList setting;
  Tja1145Regs reg_addr;
  uint8_t reg_msb;
  uint8_t reg_lsb;
} Tja1145Settings;

typedef struct Tja1145 {
  void* spi_bus;  // parameter used for spi_master_transfer
  void* spi_slave;  // parameter used for spi_master_transfer
  uint32_t (*spi_master_transfer)(void *spi_bus, void* spi_slave, const uint8_t *out_buf,
                                  uint8_t *in_buf, uint32_t size);
  void (*delay_in_us)(uint32_t interval);
} Tja1145;

void Tja1145DumpRegisters(Tja1145* tja1145);
ReturnCode Tja1145ReadOneReg(Tja1145* tja1145, uint8_t reg_addr, uint16_t* value);
ReturnCode Tja1145WriteOneReg(Tja1145* tja1145, uint8_t reg_addr, uint8_t reg_val);
ReturnCode Tja1145Init(Tja1145* tja1145);
ReturnCode Tja1145RegConfig(Tja1145* tja1145, Tja1145SettingList setting, uint8_t val);
ReturnCode Tja1145GetStatus(Tja1145* tja1145, Tja1145SettingList setting, uint8_t* val);
ReturnCode Tja1145SetToNormalMode(Tja1145* tja1145);
ReturnCode Tja1145SetToStandbyMode(Tja1145* tja1145);
ReturnCode Tja1145SetToSleepMode(Tja1145* tja1145);
ReturnCode Tja1145EnableSelectiveWake(Tja1145* tja1145, uint32_t id, const uint8_t* data);
ReturnCode Tja1145SleepWakeErrorConfig(Tja1145* tja1145, bool disable);
void Tja1145Dump(Tja1145* tja1145);

#endif  // COMMON_DRIVER_NXP_TJA1145_H_
