// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef COMMON_DRIVER_RTC_PCA2131_H_
#define COMMON_DRIVER_RTC_PCA2131_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

#define BIT(nr) (1 << (nr))

#define bcdtobin(x) (((x)&0x0F) + ((x) >> 4) * 10)
#define bintobcd(x) ((((x) / 10) << 4) + (x) % 10)

// Control register 1
#define PCA2131_REG_CTRL1 0x00
#define PCA2131_BIT_CTRL1_HOUR_MODE BIT(2)
#define PCA2131_BIT_CTRL1_POR_OVRD BIT(3)
#define PCA2131_BIT_CTRL1_TSF1 BIT(4)
#define PCA2131_BIT_CTRL1_STOP BIT(5)
#define PCA2131_BIT_CTRL1_TEST BIT(7)
#define PCA2131_STOP_CLOCK 0x20
#define PCA2121_START_CLOCK 0xDF
// Control register 2
#define PCA2131_REG_CTRL2 0x01
#define PCA2131_BIT_CTRL2_AIE BIT(1)
#define PCA2131_BIT_CTRL2_AF BIT(4)
#define PCA2131_BIT_CTRL2_WDTF BIT(6)
// Control register 3
#define PCA2131_REG_CTRL3 0x02
#define PCA2131_BIT_CTRL3_BLIE BIT(0)
#define PCA2131_BIT_CTRL3_BIE BIT(1)
#define PCA2131_BIT_CTRL3_BLF BIT(2)
#define PCA2131_BIT_CTRL3_BF BIT(3)
#define PCA2131_BIT_CTRL3_BTSE BIT(4)
#define PCA2131_PWRMNG_OFFSET 5
#define PCA2131_REG_CTRL3_PWRMNG_BITS_MASK 0xE0
// Software Reset
#define PCA2131_REG_SR_RESET 0x05
#define PCA2131_BIT_SR BIT(3)
#define PCA2131_BIT_CPR BIT(7)
#define PCA2131_CPR_SET 0x80
// Time and date registers
#define PCA2121_CONCTROL_LEN 1
#define PCA2131_TIME_LEN 8
#define PCA2131_RETRIEVE_OFFSET 6
#define PCA2131_REG_100TH_SC 0x06
#define PCA2131_REG_SC 0x07
#define PCA2131_BIT_SC_OSF BIT(7)
#define PCA2131_REG_MN 0x08
#define PCA2131_REG_HR 0x09
#define PCA2131_REG_DM 0x0A
#define PCA2131_REG_DW 0x0B
#define PCA2131_REG_MO 0x0C
#define PCA2131_REG_YR 0x0D
// Alarm registers
#define PCA2131_REG_ALARM_SC 0x0E
#define PCA2131_REG_ALARM_MN 0x0F
#define PCA2131_REG_ALARM_HR 0x10
#define PCA2131_REG_ALARM_DM 0x11
#define PCA2131_REG_ALARM_DW 0x12
#define PCA2131_BIT_ALARM_AE BIT(7)
// CLKOUT control register
#define PCA2131_REG_CLKOUT 0x13
#define PCA2131_BIT_CLKOUT_OTPR BIT(5)
#define PCA2131_BIT_CLKOUT_COF_BITS_MASK 0x7
// Watchdog registers
#define PCA2131_REG_WD_CTL 0x10
#define PCA2131_BIT_WD_CTL_TF0 BIT(0)
#define PCA2131_BIT_WD_CTL_TF1 BIT(1)
#define PCA2131_BIT_WD_CTL_CD0 BIT(6)
#define PCA2131_BIT_WD_CTL_CD1 BIT(7)
#define PCA2131_REG_WD_VAL 0x11
// Tamper timestamp registers
#define PCA2131_REG_TS_CTRL 0x12
#define PCA2131_BIT_TS_CTRL_TSOFF BIT(6)
#define PCA2131_BIT_TS_CTRL_TSM BIT(7)
#define PCA2131_REG_TS_SC 0x13
#define PCA2131_REG_TS_MN 0x14
#define PCA2131_REG_TS_HR 0x15
#define PCA2131_REG_TS_DM 0x16
#define PCA2131_REG_TS_MO 0x17
#define PCA2131_REG_TS_YR 0x18

// Aging offset register
#define PCA2131_REG_AGING_OFFSET 0x30

#define PCA2131_INT_A_MASK1_REG 0x31
#define PCA2131_INT_B_MASK1_REG 0x33

typedef enum Pca2131PwrMngMode {
  // battery switch-over function is enabled in standard mode
  // battery low detection function is enabled
  kPca2131SoEnStdLdEn = 0x0,
  // battery switch-over function is enabled in standard mode
  // battery low detection function is disabled
  kPca2131SoEnStdLdDis1 = 0x1,
  kPca2131SoEnStdLdDis2 = 0x2,
  // battery switch-over function is enabled in direct mode
  // battery low detection function is enabled
  kPca2131SoEnDirectLdEn = 0x3,
  // battery switch-over function is enabled in direct mode
  // battery low detection function is disabled
  kPca2131SoEnDirectLdDis1 = 0x4,
  kPca2131SoEnDirectLdDis2 = 0x5,
  // battery switch-over function is disabled, only one power supply (VDD)
  // battery low detection function is disabled
  kPca2131SoDisLdDis1 = 0x6,
  kPca2131SoDisLdDis2 = 0x7,
} Pca2131PwrMngMode;

typedef enum Pca2131ClkoutFreq {
  kPca2131ClkoutFreq32768 = 0x0,  // Hz
  kPca2131ClkoutFreq16384 = 0x1,  // Hz
  kPca2131ClkoutFreq8192 = 0x2,  // Hz
  kPca2131ClkoutFreq4096 = 0x3,  // Hz
  kPca2131ClkoutFreq2048 = 0x4,  // Hz
  kPca2131ClkoutFreq1024 = 0x5,  // Hz
  kPca2131ClkoutFreq1 = 0x6,  // Hz
  kPca2131ClkoutFreqHighZ = 0x7,  // Hz
} Pca2131ClkoutFreq;

typedef enum Pca2131AgingOffset {
  kPca2131AgingOffsetPpm16 = 0,      // +16ppm
  kPca2131AgingOffsetPpm14 = 1,      // +14ppm
  kPca2131AgingOffsetPpm12 = 2,      // +12ppm
  kPca2131AgingOffsetPpm10 = 3,      // +10ppm
  kPca2131AgingOffsetPpm8 = 4,       // +8ppm
  kPca2131AgingOffsetPpm6 = 5,       // +6ppm
  kPca2131AgingOffsetPpm4 = 6,       // +4ppm
  kPca2131AgingOffsetPpm2 = 7,       // +2ppm
  kPca2131AgingOffsetPpm0 = 8,       // +0ppm
  kPca2131AgingOffsetPpmNeg2 = 9,    // -2ppm
  kPca2131AgingOffsetPpmNeg4 = 10,   // -4ppm
  kPca2131AgingOffsetPpmNeg6 = 11,   // -6ppm
  kPca2131AgingOffsetPpmNeg8 = 12,   // -8ppm
  kPca2131AgingOffsetPpmNeg10 = 13,  // -10ppm
  kPca2131AgingOffsetPpmNeg12 = 14,  // -12ppm
  kPca2131AgingOffsetPpmNeg14 = 15,  // -14ppm
} Pca2131AgingOffset;

typedef struct Pca2131 {
  void* i2c_bus;
  uint8_t i2c_slave_addr;
  int (*i2c_write_register)(void* i2c_bus,
                            uint8_t slave_addr,
                            uint32_t reg_addr,
                            uint8_t reg_addr_size,
                            const uint8_t data[],
                            uint16_t data_length);
  int (*i2c_read_register)(void* i2c_bus,
                           uint8_t slave_addr,
                           uint32_t reg_addr,
                           uint8_t reg_addr_size,
                           uint8_t data[],
                           uint16_t data_length);
  void (*delay_us)(uint32_t us);
} Pca2131;

typedef struct RtcTime {
  int tm_100th_sec;
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
} RtcTime;

ReturnCode Pca2131RtcReadTime(struct Pca2131* dev, struct RtcTime* tm);
// The tm_yday and tm_isdst is not needed, if you just want to set simple time.
ReturnCode Pca2131RtcSetTime(struct Pca2131* dev, struct RtcTime* tm);
ReturnCode Pca2131RtcReadReg(Pca2131* dev, uint8_t reg_addr, uint8_t* reg_value);
ReturnCode Pca2131RtcWriteReg(Pca2131* dev, uint8_t reg_addr, uint8_t reg_value);
ReturnCode SetPca2131PwrMng(Pca2131* dev, Pca2131PwrMngMode mode);
ReturnCode ClearPca2131Btse(Pca2131* dev);
ReturnCode EnablePca2131TestMode(Pca2131* dev, bool enable);
ReturnCode InitPca2131Rtc(Pca2131* dev);
ReturnCode SoftResetPca2131(Pca2131* dev);
ReturnCode SetPca2131AgingOffset(Pca2131* dev, Pca2131AgingOffset offset);
ReturnCode EnablePca2131BatteryLowInterrupt(Pca2131* dev, bool enable);

#endif  // COMMON_DRIVER_RTC_PCA2131_H_
