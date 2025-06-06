// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_TI_TMP102_H_
#define PLATFORM_DEVICE_DRIVER_TI_TMP102_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// I2C bus might be shared by multiple users, it is user's responsibility to
// avoid race condition.

// Per datasheet, it takes 26ms to get the first available reading after power
// on Caller should take care of this delay!
#define TMP102_Q1_FIRST_RESULT_DELAY_MS 26

#define TMP102_REG_SIZE 2

typedef struct tmp102 {
  uint8_t i2c_bus;
  uint8_t i2c_slave_addr;
  uint8_t config_reg;
} tmp102_t;

enum Tmp102ConfigValue {
  kTmp102Config = 0x60,  // Continuous conversion, comparator mode, 12-bit resolution
};

// bytes[0] is MSB byte, bytes[1] is LSB byte
extern int WriteTmp102Configuration(const tmp102_t* tmp102);
extern int ReadTmp102Temperature(const tmp102_t* tmp102, float* result);
extern int WriteTmp102LowLimit(const tmp102_t* tmp102, uint8_t byte_1, uint8_t byte_2);
extern int WriteTmp102HighLimit(const tmp102_t* tmp102, uint8_t byte_1, uint8_t byte_2);

extern float ConvertTmp102RawToCelsius(uint8_t byte_1, uint8_t byte_2);

#ifdef __cplusplus
}
#endif

#endif  // PLATFORM_DEVICE_DRIVER_TI_TMP102_H_
