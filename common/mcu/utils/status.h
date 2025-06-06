// Copyright @2020 Pony AI Inc. All rights reserved.

#ifndef COMMON_MCU_UTILS_STATUS_H_
#define COMMON_MCU_UTILS_STATUS_H_

#include <stdint.h>
#include <stdbool.h>

typedef int32_t ReturnCode;

#define ERROR_OK                        (0)
#define ERROR_GENERAL                   (-1)
#define ERROR_UNKNOWN                   (-2)
#define ERROR_OUT_OF_RANGE              (-3)
#define ERROR_IN_USE                    (-4)
#define ERROR_INVALID                   (-5)
#define ERROR_INVALID_PARAM             (-6)
#define ERROR_INVALID_HANDLER           (-7)
#define ERROR_CREATE_ERROR              (-8)
#define ERROR_BUSY                      (-9)
#define ERROR_IO_ERROR                  (-10)
#define ERROR_INSURFFICIENT             (-11)
#define ERROR_PROTOCOL                  (-12)
#define ERROR_NOT_EXIST                 (-13)
#define ERROR_CHECKSUM                  (-14)
#define ERROR_TIMEOUT                   (-15)
#define ERROR_VERSION_MISMATCH          (-16)
#define ERROR_SEQUENCE                  (-17)
#define ERROR_ERASED                    (-18)
#define ERROR_ALIGNMENT                 (-19)
#define ERROR_SIZE                      (-20)
#define ERROR_SECURE                    (-21)
#define ERROR_LOCKED                    (-22)

#if defined (__TASKING__)
#define MUST_USE_RESULT
#else
#define MUST_USE_RESULT __attribute__((warn_unused_result))
#endif  // __TASKING__

#ifdef __cplusplus
namespace mcu {

enum class Status : ReturnCode {
  kOk      = ERROR_OK,
  kError   = ERROR_GENERAL,
  kBusy    = ERROR_BUSY,
  kTimeout = ERROR_TIMEOUT,
  kInval   = ERROR_INVALID,
  kUnknown = ERROR_UNKNOWN,
  kInvalidHandler = ERROR_INVALID_HANDLER,
};

}  // namespace mcu
#endif

#endif  // COMMON_MCU_UTILS_STATUS_H_
