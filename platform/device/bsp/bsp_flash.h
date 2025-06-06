// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef BSP_BSP_FLASH_H_
#define BSP_BSP_FLASH_H_

#include <stdio.h>

#include "common/mcu/utils/status.h"

typedef struct PonyFlashConfiguration {
  ReturnCode (*erase)(uint32_t start_address, uint32_t data_len_erase);
  ReturnCode (*write)(uint32_t start_address, const uint8_t* data, uint32_t data_len_write);
  ReturnCode (*read)(uint32_t start_address, uint8_t* buffer, uint32_t data_len_read);
} pony_flash_configuration_t, *p_pony_flash_configuration_t;

extern ReturnCode EraseFlash(uint32_t start_address, uint32_t data_len_erase);
extern ReturnCode WriteFlash(uint32_t start_address, const uint8_t* data, uint32_t data_len_write);
extern ReturnCode ReadFlash(uint32_t start_address, uint8_t* buffer, uint32_t data_len_read);
extern ReturnCode RegisterFlash(p_pony_flash_configuration_t temp_ops);

#endif  // BSP_BSP_FLASH_H_
