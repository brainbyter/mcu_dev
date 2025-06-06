// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_TC39B_PONY_TC39B_GPIO_H_
#define PLATFORM_TC39B_PONY_TC39B_GPIO_H_

#include <stdint.h>

#include "Infra/Sfr/TC39B/_Reg/IfxPort_regdef.h"

// For TC39B, The Pins range from P00_00 to P42_XX, so we define the gpio as a Paa_bb.
// The aa is the module number, and the bb is pin index. Then we use the pin as:
//     int16_t pin_num = aa * 100 + bb = aabb

uint8_t GetTc39bPinIndex(int16_t pin_num);
Ifx_P* GetTc39bPinModulePtr(int16_t pin_num);

#endif  // PLATFORM_TC39B_PONY_TC39B_GPIO_H_
