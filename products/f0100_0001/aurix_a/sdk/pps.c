// Copyright @2023 Pony AI Inc. All rights reserved.

#include "products/f0100_0001/aurix_a/sdk/pps.h"

#include <stdint.h>

#include "common/mcu/system/init.h"
#include "common/mcu/utils/debug.h"
#include "platform/device/bsp/bsp_gpio.h"
#include "platform/product/common/pony_driver.h"

static uint32_t g_pps_input_test_count = 0;

static void PpsHandler(void* args) {
  g_pps_input_test_count++;
}

static void InitPpsPin(void) {
  PONY_ASSERT(SetGpioMode(AURIXA_PPS_INPUT, PIN_MODE_INPUT_PULLDOWN) == ERROR_OK);
  PONY_ASSERT(AttachGpioIrq(AURIXA_PPS_INPUT, PIN_IRQ_MODE_RISING, PpsHandler, NULL) == ERROR_OK);
  PONY_ASSERT(EnableGpioIrq(AURIXA_PPS_INPUT, PIN_IRQ_ENABLE) == ERROR_OK);
  Printf("PPS initial value is %d.\r\n", ReadGpio(AURIXA_PPS_INPUT));
}

void PrintTestPpsCounter(void) {
  Printf("PPS now count is %d.\r\n", g_pps_input_test_count);
}

addAppStep4(InitPpsPin);
