// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef COMMON_DRIVER_MICRO_CHIP_PAC1954_REGDEFS_H_
#define COMMON_DRIVER_MICRO_CHIP_PAC1954_REGDEFS_H_

// ALERT
#define CH1OC (0x1 << 23)
#define CH2OC (0x1 << 22)
#define CH3OC (0x1 << 21)
#define CH4OC (0x1 << 20)
#define CH1UC (0x1 << 19)
#define CH2UC (0x1 << 18)
#define CH3UC (0x1 << 17)
#define CH4UC (0x1 << 16)
#define CH1OV (0x1 << 15)
#define CH2OV (0x1 << 14)
#define CH3OV (0x1 << 13)
#define CH4OV (0x1 << 12)
#define CH1UV (0x1 << 11)
#define CH2UV (0x1 << 10)
#define CH3UV (0x1 << 9)
#define CH4UV (0x1 << 8)
#define CH1OP (0x1 << 7)
#define CH2OP (0x1 << 6)
#define CH3OP (0x1 << 5)
#define CH4OP (0x1 << 4)
#define ACC_OVF (0x1 << 3)
#define ACC_COUNT (0x1 << 2)
#define ALERT_CC (0x1 << 1)  // only used in reg kPac1954AlertEnable
#define ALERT_CHANNEL_NUM 23

// kPac1954SettingSampleMode
#define SPS_1024_ADAPTIVE_ACCUMULATION (0x0)
#define SPS_256_ADAPTIVE_ACCUMULATION (0x1)
#define SPS_64_ADAPTIVE_ACCUMULATION (0x2)
#define SPS_8_ADAPTIVE_ACCUMULATION (0x3)
#define SPS_1024 (0x4)
#define SPS_256 (0x5)
#define SPS_64 (0x6)
#define SPS_8 (0x7)
#define SINGLE_SHOT (0x8)
#define SINGLE_SHOT_8X (0x9)
#define FAST_MODE (0xa)
#define BURST_MODE (0xb)
#define SLEEP (0xf)
// kPac1954SettingGpioAlert2, kPac1954SettingGpioAlert1
#define FUNC_ALERT (0x0)
#define FUNC_GPIO_DIGITAL_INPUT (0x1)
#define FUNC_GPIO_DIGITAL_OUTPUT (0x2)
#define FUNC_SLOW_PIN (0x3)
// kPac1954SettingChannelNOFF
#define CHANNEL_OFF_1 (0x8)
#define CHANNEL_OFF_2 (0x4)
#define CHANNEL_OFF_3 (0x2)
#define CHANNEL_OFF_4 (0x1)
#define CHANNEL_OFF_12 (0xc)
#define CHANNEL_OFF_13 (0xa)
#define CHANNEL_OFF_14 (0x9)
#define CHANNEL_OFF_23 (0x6)
#define CHANNEL_OFF_24 (0x5)
#define CHANNEL_OFF_34 (0x3)
#define CHANNEL_OFF_123 (0xe)
#define CHANNEL_OFF_124 (0xd)
#define CHANNEL_OFF_134 (0xb)
#define CHANNEL_OFF_234 (0x7)
#define CHANNEL_OFF_1234 (0xf)
// kPac1954SettingGpioData2, kPac1954SettingGpioData1
#define GPIO_DATA_SET_L (0x0)
#define GPIO_DATA_SET_H (0x1)
// kPac1954SettingPor, kPac1954StatusPor
#define NO_POR (0x0)
#define AN_POR (0x1)
// kPac1954SettingTimeout
#define SMBUS_TIMEOUT_OFF (0x0)
#define SMBUS_TIMEOUT_ON (0x1)
// kPac1954SettingByteCount
#define BLOCK_READ_WITH_NO_BYTE_COUNT (0x0)
#define BLOCK_READ_WITH_BYTE_COUNT (0x1)
// kPac1954SettingNoSkip
#define ADDR_INC_SKIP_INACTIVE (0x0)
#define ADDR_INC_NO_SKIP_INACTIVE (0x1)
// kPac1954SettingI2cHighSpeed
#define I2C_3_4MHZ_OFF (0x0)
#define I2C_3_4MHZ_ON (0x1)
// kPac1954SettingCfgVs1~4
#define FSR_UNIPOLAR_0_100MVP (0x0)
#define FSR_BIPOLAR_100MVN_100MVP (0x1)
#define FSR_BIPOLAR_50MVN_50MVP (0x2)
// kPac1954SettingCfgVb1~4
#define FSR_UNIPOLAR_0_32VP (0x0)
#define FSR_BIPOLAR_32VN_32VP (0x1)
#define FSR_BIPOLAR_16VN_16VP (0x2)
// kPac1954SettingRRise, kPac1954SettingRVRise
// kPac1954SettingRFall, kPac1954SettingRVFall
#define SLOW_REFRESH_DIS (0x0)
#define SLOW_REFRESH_EN (0x1)
// kPac1954SettingAccConfig1~4
#define ACCUMULATE_VPOWER (0x0)
#define ACCUMULATE_VSENSE (0x1)
#define ACCUMULATE_VBUS (0x2)
// kPac1954SettingNsamplesXXchX
#define NSAMPLES_COUNT_1 (0x0)
#define NSAMPLES_COUNT_4 (0x1)
#define NSAMPLES_COUNT_8 (0x2)
#define NSAMPLES_COUNT_16 (0x3)

// kPac1954StatusAnyAlert
#define NO_ALERT (0x0)
#define AN_ALERT (0x1)
// kPac1954StatusSlow
#define SLOW_STATUS_LOW (0x0)
#define SLOW_STATUS_HIGH (0x1)
// kPac1954StatusSlowLH
#define SLOW_STATUS_L2H_NO (0x0)
#define SLOW_STATUS_L2H_YES (0x1)
// kPac1954StatusSlowHL
#define SLOW_STATUS_H2L_NO (0x0)
#define SLOW_STATUS_H2L_YES (0x1)

#endif  // COMMON_DRIVER_MICRO_CHIP_PAC1954_REGDEFS_H_
