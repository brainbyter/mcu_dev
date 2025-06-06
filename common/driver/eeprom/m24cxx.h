// Copyright @2021 Pony AI Inc. All rights reserved.

#ifndef COMMON_DRIVER_EEPROM_M24CXX_H_
#define COMMON_DRIVER_EEPROM_M24CXX_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

typedef enum M24cxxType {
  kM24Invalid = 0,
  kM24c01,
  kM24c02,
  kM24c04,
  kM24c08,
  kM24c16,
  kM24c32,
  kM24c64,
} M24cxxType;

typedef struct M24cxx {
  M24cxxType type;
  uint8_t address;
  uint8_t page_size;
  uint16_t max_size;
  ReturnCode (*write_enable)(bool en, void* param);
  ReturnCode (*i2c_write_register)(uint8_t slave_addr, uint16_t reg_addr, uint8_t reg_addr_size,
                                   uint8_t* data, uint32_t data_length, void* param);
  ReturnCode (*i2c_read_register)(uint8_t slave_addr, uint16_t reg_addr, uint8_t reg_addr_size,
                                  uint8_t* data, uint32_t data_length, void* param);
  void (*delay_us)(uint32_t us);
  void (*delay_ms)(uint32_t ms);
  // This param is used in write_enable, i2c_write_register and i2c_read_register. It can be NULL.
  void* param;
} M24cxx;

ReturnCode M24cxxWriteEnable(M24cxx* m24cxx);
ReturnCode M24cxxWriteDisable(M24cxx* m24cxx);
ReturnCode M24cxxInit(M24cxx* m24cxx);
// IMPORTANT NOTE: For m24cxx, write cycle should be more than 5ms.
ReturnCode M24cxxWriteByte(M24cxx* m24cxx, uint16_t write_addr, uint8_t data);
ReturnCode M24cxxWriteBytes(M24cxx* m24cxx, uint16_t write_addr, uint8_t* data, uint16_t data_len);
// The Page Write mode allows up to 16 byte to be written in a single Write cycle, provided that
// they are all located in the same page in the memory: that is, the most significant memory
// address bits, A8/A4, are the same.
ReturnCode M24cxxWritePage(M24cxx* m24cxx, uint16_t write_addr, uint8_t* data, uint16_t data_len);
// Assume size of data is not less than read_len.
ReturnCode M24cxxReadBytes(M24cxx* m24cxx, uint16_t read_addr, uint8_t* data, uint16_t read_len);
uint16_t GetM24cxxMaxSize(M24cxx* m24cxx);

#endif  // COMMON_DRIVER_EEPROM_M24CXX_H_
