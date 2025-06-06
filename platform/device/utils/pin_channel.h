// Copyright @2021 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_UTILS_PIN_CHANNEL_
#define PLATFORM_DEVICE_UTILS_PIN_CHANNEL_

#include <stdint.h>

#include "common/mcu/utils/status.h"
#include "platform/device/driver/ti/tca9539_q1.h"

#define MAX_DEVICE_NAME_LEN 32

typedef enum PowerControlPinType {
  kPinTypeGpio = 0,
  kPinTypeTca9539 = 1,
} PowerControlPinType;

typedef struct PinChannel {
  int index;
  PowerControlPinType pin_type;
  union {
    // if pin_type == kPinTypeGpio
    struct {
      int16_t pin_num;
    } gpio;
    // if pin_type == kPowerGoodPinTypeTca9539
    struct {
      tca9539_t* dev;
      tca9539_q1_port_t port;
      uint8_t channel;
    } tca9539;
  };
  char name[MAX_DEVICE_NAME_LEN];
  uint8_t enable;
  uint8_t disable;
} PinChannel;

#define PIN_TCA9539(pin_index, tca9539_dev, dev_port, dev_channel, pin_name, enable_value)  \
  {                                                                                         \
    .index = pin_index,                                                                     \
    .pin_type = kPinTypeTca9539,                                                            \
    .tca9539.dev = tca9539_dev,                                                             \
    .tca9539.port = dev_port,                                                               \
    .tca9539.channel = dev_channel,                                                         \
    .name = pin_name,                                                                       \
    .enable = enable_value,                                                                 \
    .disable = !(enable_value)                                                              \
  }

#define PIN_GPIO(pin_index, gpio_pin_num, pin_name, enable_value)   \
  {                                                                 \
    .index = pin_index,                                             \
    .pin_type = kPinTypeGpio,                                       \
    .gpio.pin_num = gpio_pin_num,                                   \
    .name = pin_name,                                               \
    .enable = enable_value,                                         \
    .disable = !(enable_value)                                      \
  }

ReturnCode EnablePinChannel(PinChannel* channel);
ReturnCode DisablePinChannel(PinChannel* channel);
ReturnCode ReadPinValue(PinChannel* channel, uint8_t* level);
ReturnCode ReadInputPinValue(PinChannel* channel, uint8_t* level);

#endif  // PLATFORM_DEVICE_UTILS_PIN_CHANNEL_
