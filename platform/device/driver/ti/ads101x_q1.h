// Copyright @2019-2020 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_TI_ADS101X_Q1_H_
#define PLATFORM_DEVICE_DRIVER_TI_ADS101X_Q1_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ADS1015_SET_INPUT(val, input) (((val) & ~(0x7 << 12)) | ((input) << 12))
#define ADS1015_SET_GAIN(val, gain) (((val) & ~(0x07 << 9)) | ((gain) << 9))

#define ADS1015_STATUS_FILED(val) (((val) & (1 << 15)) >> 15)
#define ADS1015_STATUS_FREE 1
#define ADS1015_STATUS_BUSY 0
#define ADS1015_OS_MASK 0x8000UL

#define ADS1015_DR_FIELD(val) (((val) & (0x7 << 5)) >> 5)

#define POWER_ALERT_PIN PIO_PA3_IDX

#define ADS1015_REG_SIZE 2
#define ADS1015_POINTER_SIZE 1

#define ADS1015_POLL_RETRY_CNT 100

#define ADS1015_ADC_RAW_MAX 0xFFFUL  // 12-bit resolution
#define ASS1015_ADC_NEGATIVE_MASK 0x800UL

#define ADS1015_ADC_RAW_READING(val) ((val) >> 4)

#define ADS1015_RATIO_6_144V 333.3f
#define ADS1015_RATIO_4_096V 500.0f
#define ADS1015_RATIO_2_048V 1000.0f
#define ADS1015_RATIO_1_024V 2000.0f
#define ADS1015_RATIO_0_512V 4000.0f
#define ADS1015_RATIO_0_256V 8000.0f

#define ADS1015_CONFIG_GAIN_MASK 0x1C00UL
#define ADS1015_CONFIG_GAIN_SHFT 9

#define ADS1015_DEFAULT_CONFIG 0x8583UL

// Only avaiable for ads1015.
// ads1013 has a fixed 2.048V.
typedef enum ads1015_q1_config_reg_gain {
  k6_144V = 0,  // 6.144V, 1LSB = 3mv
  k4_096V,  // 4.096V, 1LSB = 2mv
  k2_048V,  // 2.048V, 1LSB = 1mV (default)
  k1_024V,  // 1.024V, 1LSB = 0.5mV
  k0_512V,  // 0.512V, 1LSB = 0.25mV
  k0_256V,  // 0.256V, 1LSB = 0.125mV
} ads1015_q1_config_reg_gain_t;

typedef enum ads1015_q1_config_reg_input {
  kAin0AndAin1,
  kAin0AndAin3,
  kAin1AndAin3,
  kAin2AndAin3,
  kAin0AndGnd,
  kAin1AndGnd,
  kAin2AndGnd,
  kAin3AndGnd,
} ads1015_q1_config_reg_input_t;

typedef struct ads1015 {
  uint16_t i2c_bus;
  uint8_t i2c_slave_addr;
} ads1015_t;

typedef enum ads1015_q1_reg_addr {
  kConversionReg = 0,
  kConfigReg = 1,
  kLoThreshReg = 2,
  kHiThreshReg = 3,
} ads1015_q1_reg_addr_t;

ReturnCode Ads1015Q1Init(ads1015_t* ads1015);
ReturnCode Ads1015Q1WriteReg(ads1015_t* ads1015,
                             ads1015_q1_reg_addr_t reg_addr,
                             uint16_t value);
ReturnCode Ads1015Q1ReadReg(ads1015_t* ads1015,
                            ads1015_q1_reg_addr_t reg_addr,
                            uint16_t* buffer);

ReturnCode Ads1015Q1SelectConfigReg(ads1015_t* ads1015);
ReturnCode Ads1015Q1SelectConvReg(ads1015_t* ads1015);
ReturnCode Ads1015Q1SelectLoThrReg(ads1015_t* ads1015);
ReturnCode Ads1015Q1SelectHiThrReg(ads1015_t* ads1015);
ReturnCode Ads1015Q1WaitTillFree(ads1015_t* ads1015, uint32_t delay_us);
ReturnCode Ads1015Q1ReadSelectedReg(ads1015_t* ads1015, uint16_t* buffer);
uint32_t Ads1015Q1GetDataRate(uint8_t index);
float Ads1015Q1GetRatio(uint8_t gain);
float Ads1015Q1RawToRealValue(float internal_ratio, uint32_t raw);

#ifdef __cplusplus
}
#endif

#endif  // PLATFORM_DEVICE_DRIVER_TI_ADS101X_Q1_H_
