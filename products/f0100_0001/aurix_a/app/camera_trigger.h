// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_CAMERA_TRIGGER_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_CAMERA_TRIGGER_H_

#include "common/mcu/utils/status.h"

void InitialCameraTrigger(void);

void CameraTriggerSquareWave(uint16_t channel, uint32_t freq, uint32_t time);
void GpioCameraTriggerSquareWave(uint32_t freq, uint8_t duty, uint32_t time);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_CAMERA_TRIGGER_H_
