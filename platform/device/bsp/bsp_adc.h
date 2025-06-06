// Copyright @2019-2020 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_BSP_BSP_ADC_H_
#define PLATFORM_DEVICE_BSP_BSP_ADC_H_

#include <stdbool.h>
#include <stdio.h>

#include "common/mcu/utils/status.h"

typedef struct PonyAdcConfiguration {
  ReturnCode (*enabledAdc)(uint32_t adcnum, uint32_t channel, bool enabled);
  uint32_t (*getAdcValue)(uint32_t adcnum, uint32_t channel);
} pony_adc_configuration_t;

// We can add some constant or configurable calibration data interfaces in the future.
extern ReturnCode EnableAdc(uint32_t adcnum, uint32_t channel);
extern ReturnCode DisableAdc(uint32_t adcnum, uint32_t channel);
extern uint32_t ReadAdc(uint32_t adcnum, uint32_t channel);
extern void RegisterAdc(pony_adc_configuration_t* tempOps);

#endif  // PLATFORM_DEVICE_BSP_BSP_ADC_H_
