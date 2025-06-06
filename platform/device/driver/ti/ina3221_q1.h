// Copyright @2019-2020 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_TI_INA3221_Q1_H_
#define PLATFORM_DEVICE_DRIVER_TI_INA3221_Q1_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

// INA3221 is a triple-channel current and voltage monitor with programmable overcurrent alerts.

#ifdef __cplusplus
extern "C" {
#endif

#define INA3221_CHANNEL_NUM 3
#define INA3221_ALERT_TYPE_NUM 2

typedef struct Ina3221 {
  uint8_t i2c_bus;
  uint8_t i2c_slave_addr;
  uint16_t config_value;
  uint16_t shunt_res_values_mohm[INA3221_CHANNEL_NUM];
} ina3221_t;

typedef enum Ina3221Channel {
  kIna3221Channel1 = 0,
  kIna3221Channel2,
  kIna3221Channel3,
} ina3221_channel_t;

enum Ina3221ConfigValue {
  // all channels enable, no averaging,
  // bus voltage conversion time 1.1ms
  // shunt voltage conversion time 1.1ms
  // shunt and bus continuous
  kIna3221ConfigDefault = 0x7127,
};

typedef enum Ina3221AlertType {
  kIna3221CriticalAlert = 0,
  kIna3221WarningAlert,
} ina3221_alert_t;

extern ReturnCode Ina3221Q1Init(const ina3221_t* ina3221);
extern ReturnCode Ina3221Q1ReadManufactureId(const ina3221_t* ina3221, uint16_t* id_value);
extern ReturnCode Ina3221Q1WriteConfiguration(const ina3221_t* ina3221);
extern ReturnCode Ina3221Q1ReadBusVoltage(const ina3221_t* ina3221,
                                          ina3221_channel_t channel,
                                          float* result_v);
extern ReturnCode Ina3221Q1ReadShuntCurrent(const ina3221_t* ina3221,
                                            ina3221_channel_t channel,
                                            float* result_a);
extern ReturnCode Ina3221Q1SetChannelAlertLimit(const ina3221_t* ina3221,
                                                ina3221_channel_t channel,
                                                ina3221_alert_t alert_type,
                                                float value);
#ifdef __cplusplus
}
#endif

#endif  // PLATFORM_DEVICE_DRIVER_TI_INA3221_Q1_H_
