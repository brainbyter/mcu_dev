// Copyright @2022 Pony AI Inc. All rights reserved.

#include "products/f0100_0001/aurix_a/sdk/orin_spi.h"

#include <stdint.h>
#include <string.h>

#include "common/mcu/utils/debug.h"
#include "platform/device/bsp/bsp_spi.h"

#define TEST_ORIN_SPI_LEN 4
void TestOrinASpiSlave(void) {
  uint8_t out_buf[TEST_ORIN_SPI_LEN] = {0x11, 0x22, 0x33, 0x44};
  Printf("Send to orin A SPI:");
  for (int i = 0; i < TEST_ORIN_SPI_LEN; i++) {
    Printf(" 0x%x", out_buf[i]);
  }
  Printf(".\r\n");
  uint8_t in_buf[TEST_ORIN_SPI_LEN] = {0};
  if (TEST_ORIN_SPI_LEN == SpiMasterTransfer(0, 1, out_buf, in_buf, TEST_ORIN_SPI_LEN)) {
    Printf("Read from orin A SPI:");
    for (int i = 0; i < TEST_ORIN_SPI_LEN; i++) {
      Printf(" 0x%x", in_buf[i]);
    }
    Printf(".\r\n");
  }
}

void TestOrinBSpiSlave(void) {
  uint8_t out_buf[TEST_ORIN_SPI_LEN] = {0x11, 0x22, 0x33, 0x44};
  Printf("Send to orin B SPI:");
  for (int i = 0; i < TEST_ORIN_SPI_LEN; i++) {
    Printf(" 0x%x", out_buf[i]);
  }
  Printf(".\r\n");
  uint8_t in_buf[TEST_ORIN_SPI_LEN] = {0};
  if (TEST_ORIN_SPI_LEN == SpiMasterTransfer(0, 0, out_buf, in_buf, TEST_ORIN_SPI_LEN)) {
    Printf("Read from orin B SPI:");
    for (int i = 0; i < TEST_ORIN_SPI_LEN; i++) {
      Printf(" 0x%x", in_buf[i]);
    }
    Printf(".\r\n");
  }
}
