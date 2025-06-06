// Copyright @2021 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_UTILS_POWER_CHANNEL_H_
#define PLATFORM_DEVICE_UTILS_POWER_CHANNEL_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"
#include "platform/device/driver/ti/ads101x_q1.h"
#include "platform/device/driver/ti/ina226.h"
#include "platform/device/driver/ti/ina3221_q1.h"
#include "platform/device/driver/micro_chip/pac1954.h"
#include "platform/device/driver/maxim/max20087.h"

typedef enum VoltageIcType {
  kVoltageIcTypeAds1015 = 0,
  kVoltageIcTypeIna3221 = 1,
  kVoltageIcTypeIna226  = 2,
  kVoltageIcTypePac1954 = 3,
  kVoltageIcTypeMax20087 = 4,
} VoltageIcType;

typedef struct VoltageChannel {
  VoltageIcType ic_type;
  union {
    // if ic_type == kVoltageIcTypeAds1015
    struct {
      ads1015_t* dev;
      ads1015_q1_config_reg_input_t channel_cfg;
    } ads1015;
    // if ic_type == kVoltageIcTypeIna3221
    struct {
      ina3221_t* dev;
      ina3221_channel_t channel;
    } ina3221;
    // if ic_type == kVoltageIcTypeIna226
    struct {
      ina226_t* dev;
    } ina226;
    struct {
      Pac1954* dev;
      Pac1954ChNum channel;
    } Pac1954Chip;
    struct {
      Max20087* dev;
      Max20087ChNum channel;
    } Max20087Chip;
  };
  float expected_v;  // The voltage that this channel expected.
  float reading_v;  // The real voltage that this channel reading from the sensor.
  float alert_limit_v;  // The overvoltage threshold.
  float alert_limit_uv;  // The undervoltage threshold.
  const char* name;
} VoltageChannel;

typedef enum CurrentIcType {
  kCurrentIcTypeIna3221 = 0,
  kCurrentIcTypeIna226 = 1,
  kCurrentIcTypePac1954 = 2,
} CurrentIcType;

typedef struct CurrentChannel {
  CurrentIcType ic_type;
  union {
    // if ic_type = kCurrentIcTypeIna3221
    struct {
      ina3221_t* dev;
      ina3221_channel_t channel;
    } ina3221;
    struct {
      ina226_t* dev;
    } ina226;
    struct {
      Pac1954* dev;
      Pac1954ChNum channel;
    } Pac1954Chip;
  };
  float expected_a;  // The current that this channel expected.
  float reading_a;  // The real current that this channel reading from the sensor.
  float alert_limit_oc;  // The overcurrent threshold.
  float alert_limit_uc;  // The undercurrent threshold.
  const char* name;
} CurrentChannel;

typedef enum PowerIcType {
  kPowerIcTypePac1954 = 2,
} PowerIcType;

typedef struct PowerChannel {
  PowerIcType ic_type;
  union {
    struct {
      Pac1954* dev;
      Pac1954ChNum channel;
    } Pac1954Chip;
  };
  float expected_a;  // The current that this channel expected.
  float reading_a;  // The real current that this channel reading from the sensor.
  float alert_limit_op;  // The overpower threshold.
  const char* name;
} PowerChannel;

#define VOLTAGE_ADS1015(ads1015_dev, ads1015_ch_cfg, ch_expected_v, ch_reading_v, ch_name) \
{                                                                                          \
  .ic_type = kVoltageIcTypeAds1015,                                                        \
  .ads1015.dev = ads1015_dev,                                                              \
  .ads1015.channel_cfg = ads1015_ch_cfg,                                                   \
  .expected_v = ch_expected_v,                                                             \
  .reading_v = ch_reading_v,                                                               \
  .name = ch_name,                                                                         \
}

#define VOLTAGE_INA3221(ina3221_dev, ina3221_channel, ch_expected_v, \
                        ch_reading_v, ch_alert_limit_v, ch_name)     \
{                                                                    \
  .ic_type = kVoltageIcTypeIna3221,                                  \
  .ina3221.dev = ina3221_dev,                                        \
  .ina3221.channel = ina3221_channel,                                \
  .expected_v = ch_expected_v,                                       \
  .reading_v = ch_reading_v,                                         \
  .alert_limit_v = ch_alert_limit_v,                                 \
  .name = ch_name,                                                   \
}

#define VOLTAGE_INA226(ina226_dev, ch_expected_v, ch_reading_v, ch_name) \
{                                                                        \
  .ic_type = kVoltageIcTypeIna226,                                       \
  .ina226.dev = ina226_dev,                                              \
  .expected_v = ch_expected_v,                                           \
  .reading_v = ch_reading_v,                                             \
  .name = ch_name,                                                       \
}

#define VOLTAGE_PAC1954(pac1954_dev, pac1954_channel, ch_expected_v, \
                        ch_reading_v, ch_alert_limit_v,              \
                        ch_alert_limit_uv, ch_name)                  \
{                                                                    \
  .ic_type = kVoltageIcTypePac1954,                                  \
  .Pac1954Chip.dev = pac1954_dev,                                    \
  .Pac1954Chip.channel = pac1954_channel,                            \
  .expected_v = ch_expected_v,                                       \
  .reading_v = ch_reading_v,                                         \
  .alert_limit_v = ch_alert_limit_v,                                 \
  .alert_limit_uv = ch_alert_limit_uv,                               \
  .name = ch_name,                                                   \
}

#define VOLTAGE_MAX20087(max20087_dev, max20087_channel, ch_expected_v, ch_reading_v, ch_name) \
{                                                                                              \
  .ic_type = kVoltageIcTypeMax20087,                                                           \
  .Max20087Chip.dev = max20087_dev,                                                            \
  .Max20087Chip.channel = max20087_channel,                                                    \
  .expected_v = ch_expected_v,                                                                 \
  .reading_v = ch_reading_v,                                                                   \
  .name = ch_name,                                                                             \
}

#define CURRENT_INA3221(ina3221_dev, ina3221_channel, ch_expected_a, ch_reading_a, ch_name) \
{                                                                                           \
  .ic_type = kCurrentIcTypeIna3221,                                                         \
  .ina3221.dev = ina3221_dev,                                                               \
  .ina3221.channel = ina3221_channel,                                                       \
  .expected_a = ch_expected_a,                                                              \
  .reading_a = ch_reading_a,                                                                \
  .name = ch_name,                                                                          \
}

#define CURRENT_INA226(ina226_dev, ch_expected_a, ch_reading_a, ch_name) \
{                                                                        \
  .ic_type = kCurrentIcTypeIna226,                                       \
  .ina226.dev = ina226_dev,                                              \
  .expected_a = ch_expected_a,                                           \
  .reading_a = ch_reading_a,                                             \
  .name = ch_name,                                                       \
}

#define CURRENT_PAC1954(pac1954_dev, pac1954_channel, ch_expected_a, ch_reading_a,          \
                        ch_alert_limit_oc, ch_alert_limit_uc, ch_name)                      \
{                                                                                           \
  .ic_type = kCurrentIcTypePac1954,                                                         \
  .Pac1954Chip.dev = pac1954_dev,                                                           \
  .Pac1954Chip.channel = pac1954_channel,                                                   \
  .expected_a = ch_expected_a,                                                              \
  .reading_a = ch_reading_a,                                                                \
  .alert_limit_oc = ch_alert_limit_oc,                                                      \
  .alert_limit_uc = ch_alert_limit_uc,                                                      \
  .name = ch_name,                                                                          \
}

#define POWER_PAC1954(pac1954_dev, pac1954_channel, ch_expected_a,                          \
                      ch_reading_a, ch_alert_limit_op, ch_name)                             \
{                                                                                           \
  .ic_type = kPowerIcTypePac1954,                                                           \
  .Pac1954Chip.dev = pac1954_dev,                                                           \
  .Pac1954Chip.channel = pac1954_channel,                                                   \
  .expected_a = ch_expected_a,                                                              \
  .reading_a = ch_reading_a,                                                                \
  .alert_limit_op = ch_alert_limit_op,                                                      \
  .name = ch_name,                                                                          \
}

ReturnCode ReadChannelVoltage(VoltageChannel* channel);
ReturnCode ReadChannelCurrent(CurrentChannel* channel);
ReturnCode ReadChannelPower(PowerChannel* channel);

#endif  // PLATFORM_DEVICE_UTILS_POWER_CHANNEL_H_
