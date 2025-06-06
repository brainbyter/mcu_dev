// Copyright @2020 Pony AI Inc. All rights reserved.

/// @defgroup bsp_interface bsp interface

/// @defgroup bsp_timer bsp timer
/// @ingroup bsp_interface
/// This is the abstract layer of timer.

#ifndef PLATFORM_DEVICE_BSP_TIMER_H_
#define PLATFORM_DEVICE_BSP_TIMER_H_

#include <stdbool.h>
#include <stdio.h>

#include "common/mcu/utils/status.h"

typedef struct PonyTimerConfiguration {
  ReturnCode (*set_timer_period)(uint8_t id, uint32_t period_ns);
  ReturnCode (*set_interrupt_priority)(uint8_t id, uint8_t priority);
  ReturnCode (*enable_timer)(uint8_t id, bool enable);
  ReturnCode (*request_timer_timeout_function)(uint8_t id,
                                               void (*timeout_handler)(void* info),
                                               void* param);
  ReturnCode (*config_timer_tick)(uint8_t id, uint32_t clk_freq, uint32_t counter_size);
  ReturnCode (*reset_timer_tick)(uint8_t id);
  ReturnCode (*start_timer_tick)(uint8_t id);
  ReturnCode (*get_timer_tick)(uint8_t id, uint32_t* tick_value, uint32_t* counter_value);
} PonyTimerConfiguration;

extern ReturnCode SetTimerPeriod(uint8_t id, uint32_t period_ns);
extern ReturnCode SetTimerInterruptPriority(uint8_t id, uint8_t priority);
extern ReturnCode EnableTimer(uint8_t id);
extern ReturnCode DisableTimer(uint8_t id);
extern ReturnCode RequestTimerTimeoutFunction(uint8_t id,
                                              void (*timeout_handler)(void* info),
                                              void* param);

extern ReturnCode ConfigTimerTick(uint8_t id, uint32_t clk_freq, uint32_t counter_size);
extern ReturnCode ResetTimerTick(uint8_t id);
extern ReturnCode StartTimerTick(uint8_t id);
extern ReturnCode GetTimerTick(uint8_t id, uint32_t* tick_value, uint32_t* counter_value);

extern ReturnCode RegisterTimerOps(PonyTimerConfiguration* timer_ops);

#endif // PLATFORM_DEVICE_BSP_TIMER_H_
