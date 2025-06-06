// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_BOOTLOADER_FW_CHECK_H_
#define PLATFORM_DEVICE_DRIVER_BOOTLOADER_FW_CHECK_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

#define FW_CHECKSUM_LENGTH 16

// The read length used in FwCheckerChecksumFromAddress to read fw from MCU flash.
#ifndef FW_CHECKSUM_READ_LENGTH
#define FW_CHECKSUM_READ_LENGTH 256
#endif  // FW_CHECKSUM_READ_LENGTH

typedef enum FwCheckStage {
  kFwCheckStageIdle = 0,
  kFwCheckStageUpdating = 1,
} FwCheckStage;

// The user can define and register these APIs. Then the loader_main will call these APIs during
// application checks before jumping from loader to app and firmware check during OTA.
typedef struct FwChecker {
  // These init\update\finalize are called during the OTA as the hash or other algorithms may need
  // these steps to calculate the finalize result.
  ReturnCode (*init)(void* param);  // The start update cmd will init this check algorithm.
  // The transfer cmd will update the new firmware data to calculate the result.
  ReturnCode (*update)(const uint8_t* data, uint32_t data_len, void* param);
  // The transfer complete cmd will finalize the result.
  ReturnCode (*finalize)(uint8_t* result, uint32_t result_len, void* param);
  // calculate_from_address is called before the loader's jump to the application to check the
  // firmware's integrity. This API should include the algorithms' init\update\finalize
  // to act as an independent function.
  ReturnCode (*calculate_from_address)(
      uint8_t* result, uint32_t result_len, uint32_t start_address, uint32_t data_len, void* param);
  void* param;
} FwChecker;

ReturnCode RegisterFwChecker(FwChecker* checker);

ReturnCode FwCheckerInit(void);
ReturnCode FwCheckerUpdate(const uint8_t* data, uint32_t data_len);
ReturnCode FwCheckerFinalize(uint8_t* result, uint32_t result_len);

ReturnCode FwCheckerChecksumFromAddress(const uint8_t* target_result,
                                        uint32_t result_len,
                                        uint32_t start_address,
                                        uint32_t data_len);

#endif  // PLATFORM_DEVICE_DRIVER_BOOTLOADER_FW_CHECK_H_
