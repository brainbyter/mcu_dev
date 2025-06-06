// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_LED_H_
#define PLATFORM_DEVICE_DRIVER_LED_H_

#include "common/mcu/utils/status.h"
#include "platform/product/common/pony_driver.h"

typedef enum PonyLedStatus {
  kLedIdle = 0,
  kLedGreenBright,
  kLedGreenTwinkling1s,
  kLedGreenTwinkling100ms,
} pony_led_status_t;

extern ReturnCode AddLed2System(int16_t lednum, int16_t pinnum);
extern ReturnCode SetLedStatus(int16_t lednum, pony_led_status_t ledstatus);
extern ReturnCode GetLedStatus(int16_t lednum, pony_led_status_t *ledstatus);
extern void LightLedsByStatus(void);
extern void ToggleLed(int16_t lednum);

#endif  // PLATFORM_DEVICE_DRIVER_LED_H_
