// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_GPIO_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_GPIO_H_

#include "common/mcu/utils/status.h"

void GpioHigh(int16_t pin);
void GpioLow(int16_t pin);
void GpioReset(int16_t pin);
void GpioSquareWave(int16_t pin);
void GpioSquareWaveFreqDutyTime(int16_t pin, uint32_t freq, uint8_t duty, uint32_t time);
void GpioRead(int16_t pin);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_GPIO_H_
