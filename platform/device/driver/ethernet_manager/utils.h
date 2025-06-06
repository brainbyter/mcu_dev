// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_UTILS_H_
#define PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_UTILS_H_

#include "pb_encode.h"
#include "pb_decode.h"

#include "common/mcu/utils/status.h"

// Provide buffer information to avoid out-of-bounds operation when DecodeStr.
typedef struct EthBufferInfo {
  void* buffer_ptr;
  int buffer_len;
} EthBufferInfo;

// Encode API
bool EncodeEthStr(pb_ostream_t* stream, const pb_field_t* field, void* const* arg);

// Decode API
bool DecodeEthStr(pb_istream_t* stream, const pb_field_t* field, void** arg);

// Convert string to mac、ip、gateway、netmask
ReturnCode StringSplit(char* buffer, uint8_t* value, const int value_len, const char* separator);
// Convert mac、ip、gateway、netmask to string
ReturnCode StringSplice(char* buffer, const int buf_len, const uint8_t* value, const int value_len,
                        const char* separator);

#endif  // PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_UTILS_H_
