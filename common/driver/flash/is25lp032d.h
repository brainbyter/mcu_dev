// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef COMMON_DRIVER_FLASH_IS25LP032D_H_
#define COMMON_DRIVER_FLASH_IS25LP032D_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

// Status regisger offset
#define IS25LP032D_STATUS_REG_WIP_OFFSET 0
#define IS25LP032D_STATUS_REG_WEL_OFFSET 1
#define IS25LP032D_STATUS_REG_QE_OFFSET  6

typedef enum Is25lp032dPageSize {
  kIs25lp032dPageSize256B = 0x100,
} Is25lp032dPageSize;

typedef enum Is25lp032dSectorSize {
  kIs25lp032dSectorSize4Kb = 0x00001000,
} Is25lp032dSectorSize;

typedef enum Is25lp032dMaxSize {
  kIs25lp032dMaxSize4Mb = 0x00400000,
} Is25lp032dMaxSize;

typedef struct Is25lp032dDevice {
  int (*transfer)(const uint8_t* out_buf, uint8_t* in_buf, uint32_t size);
  void (*delay_ms)(uint32_t ms);
} Is25lp032dDevice;

ReturnCode Is25lp032dReadSfdp(Is25lp032dDevice* device, uint8_t address, uint8_t* data);
ReturnCode Is25lp032dReadStatus(Is25lp032dDevice* device, uint8_t* data);
ReturnCode Is25lp032dWriteStatus(Is25lp032dDevice* device, uint8_t data);
// data len no limit, provided that data len plus read addr is less than max addr(max size).
ReturnCode Is25lp032dReadBytes(Is25lp032dDevice* device,
                               uint32_t read_addr,
                               uint8_t* data,
                               uint32_t data_len);
ReturnCode Is25lp032dWriteEnable(Is25lp032dDevice* device);
// data len no limit, provided that data len plus write addr is less than max addr(max size).
ReturnCode Is25lp032dWriteBytes(Is25lp032dDevice* device,
                                uint32_t write_addr,
                                uint8_t* data,
                                uint32_t data_len);
// Erase size is 4 KB.
// This API erases the sector that starts with the address.
ReturnCode Is25lp032dSectorErase(Is25lp032dDevice* device, uint32_t addr);
ReturnCode Is25lp032dEnterQpi(Is25lp032dDevice* device);

#endif  // COMMON_DRIVER_FLASH_IS25LP032D_H_
