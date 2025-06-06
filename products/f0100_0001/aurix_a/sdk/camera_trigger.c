// Copyright @2023 Pony AI Inc. All rights reserved.

#include "products/f0100_0001/aurix_a/sdk/camera_trigger.h"

#include "common/mcu/system/init.h"
#include "common/mcu/utils/debug.h"
#include "platform/device/bsp/bsp_delay.h"
#include "platform/device/bsp/bsp_gpio.h"
#include "platform/device/driver/ti/tca9539_q1.h"
#include "platform/device/utils/pin_channel.h"
#include "platform/product/common/pony_driver.h"
#include "products/f0100_0001/aurix_a/app/gpio.h"

static Tca9539Device g_camera_io[] = {
#ifdef SUPPORT_FOR_F0100_03_0000
  TCA9539_DEVICE("PCA9535_trigger MCU", 1, 0x27, -1, -1, 0xffff, 0x0000),
#else
  TCA9539_DEVICE("PCA9535_trigger", 1, 0x12, -1, -1, 0x0000, 0x0000),
#endif
};

// Set the IO expander chip pin to input mode to
// avoid affecting the normal operation of the camera
void InitialCameraTrigger(void) {
  for (int i = 0; i < ARRAY_SIZE(g_camera_io); i++) {
    if (Tca9539Q1Init(&g_camera_io[i].dev) != ERROR_OK) {
      PONY_LOG(DEBUG_ERR,
               "Failed to init PCA9535: %s, bus %d, address 0x%x.",
               g_camera_io[i].name,
               g_camera_io[i].dev.i2c_bus,
               g_camera_io[i].dev.i2c_slave_addr);
    } else {
      PONY_ASSERT(Tca9539Q1SetIoMode(&g_camera_io[i].dev, g_camera_io[i].io_bitmap,
                                     g_camera_io[i].io_polarity_bitmap) == ERROR_OK);
    }
  }
}

static const uint32_t kUsPerSecond = 1e6;

void CameraTriggerSquareWave(uint16_t channel, uint32_t freq, uint32_t time) {
  // Set the IO expander chip pin to output mode
  if (Tca9539Q1SetIoMode(&g_camera_io[0].dev, ~g_camera_io[0].io_bitmap,
                         g_camera_io[0].io_polarity_bitmap) != ERROR_OK) {
    PONY_LOG(DEBUG_ERR, "Failed to set IO expander as output mode.\r\n");
  }
  uint8_t port0_channel = channel & 0xFF;
  uint8_t port1_channel = (channel >> 8) & 0xFF;

  if (freq == 0) {
    PONY_LOG(DEBUG_ERR, "Invaild frequence parameter %d.\r\n", freq);
    return;
  }
  uint32_t pwm_period_us = kUsPerSecond / freq;
  uint32_t pwm_duty_us = pwm_period_us / 10;

  Printf("Output channel: port0 %x port1 %x\r\n", port0_channel, port1_channel);
  Printf("Output %d seconds square wave: freq %dHz duty 10%%\r\n", time, freq);
  for (int i = 0; i < time * freq; i++) {
    if (Tca9539Q1SetAllOutputLevel(&g_camera_io[0].dev, kTcaPort0, port0_channel) != ERROR_OK ||
        Tca9539Q1SetAllOutputLevel(&g_camera_io[0].dev, kTcaPort1, port1_channel) != ERROR_OK) {
        PONY_LOG(DEBUG_ERR, "Failed to set high level in %dth pwm.\r\n", i);
        break;
    }
    DelayUs(pwm_duty_us);
    if (Tca9539Q1SetAllOutputLevel(&g_camera_io[0].dev, kTcaPort0, 0) != ERROR_OK ||
        Tca9539Q1SetAllOutputLevel(&g_camera_io[0].dev, kTcaPort1, 0) != ERROR_OK) {
        PONY_LOG(DEBUG_ERR, "Failed to set low level in %dth pwm.\r\n", i);
        break;
    }
    DelayUs(pwm_period_us - pwm_duty_us);
  }
  // Set the IO expander chip pin to input mode
  if (Tca9539Q1SetIoMode(&g_camera_io[0].dev, g_camera_io[0].io_bitmap,
                         g_camera_io[0].io_polarity_bitmap) != ERROR_OK) {
    PONY_LOG(DEBUG_ERR, "Failed to set IO expander as input mode.\r\n");
    return;
  }
  Printf("Successfully output square wave pin\r\n");
}

void GpioCameraTriggerSquareWave(uint32_t freq, uint8_t duty, uint32_t time) {
  Printf("Enable all gpio camera trigger %dHZ duty %d%% square wave for %d seconds.\r\n", 
         freq, duty, time);
  SetGpioMode(GMSL_TRIGGER1, PIN_MODE_OUTPUT);
  SetGpioMode(GMSL_TRIGGER2, PIN_MODE_OUTPUT);
  SetGpioMode(GMSL_TRIGGER3, PIN_MODE_OUTPUT);
  SetGpioMode(GMSL_TRIGGER4, PIN_MODE_OUTPUT);
  if (freq == 0 || duty == 0) {
    return;
  }
  uint32_t pwm_period_us = kUsPerSecond / freq;
  uint32_t pwm_duty_us = pwm_period_us * ((float)duty / 100);
  for (int i = 0; i <= time * freq; ++i) {
    WriteGpio(GMSL_TRIGGER1, PIN_LOW);
    WriteGpio(GMSL_TRIGGER2, PIN_LOW);
    WriteGpio(GMSL_TRIGGER3, PIN_LOW);
    WriteGpio(GMSL_TRIGGER4, PIN_LOW);
    DelayUs(pwm_duty_us);
    WriteGpio(GMSL_TRIGGER1, PIN_HIGH);
    WriteGpio(GMSL_TRIGGER2, PIN_HIGH);
    WriteGpio(GMSL_TRIGGER3, PIN_HIGH);
    WriteGpio(GMSL_TRIGGER4, PIN_HIGH);
    DelayUs(pwm_period_us - pwm_duty_us);
  }
  Printf("Successfully output square wave pin\r\n");
}
