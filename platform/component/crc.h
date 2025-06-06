// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef COMPONENT_CRC_H_
#define COMPONENT_CRC_H_

#include <stdint.h>


#define CRC_TABLE_SIZE 256

struct CrcContext {
  int crc_type;
  uint32_t polynomial;
  void* crc_table;
};

enum CrcType {
  kCrcType8,
  kCrcTypeReflect8,
  kCrcType16,
  kCrcTypeReflect16,
  kCrcType32,
  kCrcTypeReflect32
};

int InitCrc(const struct CrcContext* context);
uint32_t CalcCrc(const struct CrcContext* context, const void* data, int len, uint32_t crc);

#endif  // COMPONENT_CRC_H_
