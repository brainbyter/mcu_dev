// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_BSP_BSP_DELAY_H_
#define PLATFORM_DEVICE_BSP_BSP_DELAY_H_

#include <stdio.h>

#include "common/mcu/utils/status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct PonyDelayOps {
  void (*delay_s) (uint32_t s);
  void (*delay_ms) (uint32_t ms);
  void (*delay_us) (uint32_t us);
} pony_delay_ops_t;

extern ReturnCode DelayS(uint32_t s);
extern ReturnCode DelayMs(uint32_t ms);
extern ReturnCode DelayUs(uint32_t us);
extern void RegisterDelayOps(pony_delay_ops_t* ops);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // PLATFORM_DEVICE_BSP_BSP_DELAY_H_
