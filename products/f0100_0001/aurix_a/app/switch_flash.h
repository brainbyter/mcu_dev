// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_ROSE_AURIX_A_APP_SWITCH_FLASH_H_
#define PRODUCTS_ROSE_AURIX_A_APP_SWITCH_FLASH_H_

#include "common/mcu/utils/status.h"

void SwitchFlashInit(void);
void SwitchEraseFlash(void);
ReturnCode EnalbeFlashQspiMode(void);
ReturnCode DisalbeFlashQspiMode(void);
ReturnCode GetSwitchFlashStatus(uint8_t* status);

#endif  // PRODUCTS_ROSE_AURIX_A_APP_SWITCH_FLASH_H_
