// Copyright @2020 Pony AI Inc. All rights reserved.

#ifndef COMMON_MCU_UTILS_DEBUG_H_
#define COMMON_MCU_UTILS_DEBUG_H_

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "common/mcu/utils/status.h"

#ifdef __cplusplus
extern "C" {
#endif

// Macros in this header are listed as below.
// These can be defined either in bazelrc or configs.
//
// USE_STDIO_PRINTF
// Define this macro to use the stdio printf implementation.
// If not defined, the "Printf" defined in this library will be used as printf.
//
// USE_COLOR_LOGGING
// Define this macro to make the logging colorful.
// If you are used to the cutecom, then it might not be a good idea to turn color logging on.
// Recommended serial client: putty, screen, and minicom (with -c on).
//
// DEBUG_LEVEL
// The verbose level of PONY_LOG. Default to DEBUG_DEBUG.

// Note: Users needs to implement their own functions to override the default ones for:
// int32_t DebugGetTimestampInternal(void);
// if they want the logging utilities to print out things.

#ifdef __TASKING__
// 537: unused variable.
#define TASKING_DISABLE_WARNING_W537 _Pragma("warning 537")
// 557: possible infinite loop warning.
#define TASKING_DISABLE_WARNING_W557 _Pragma("warning 557")
// Back to default, all warning are shown
#define TASKING_WARNING_DEFAULT _Pragma("warning default")

// manually add them for temporaray solution
// Those MACROS from `ctc/include.cxx/errno.h`
#ifndef ECANCELED
#define ECANCELED 9927
#endif

#ifndef ENOTSUP
#define ENOTSUP 9926
#endif

#ifndef EOWNERDEAD
#define EOWNERDEAD 9931
#endif

#ifndef ENOTRECOVERABLE
#define ENOTRECOVERABLE 9934
#endif

#else
#define TASKING_DISABLE_WARNING_W537
#define TASKING_DISABLE_WARNING_W557
#define TASKING_WARNING_DEFAULT
#endif

#ifdef USE_STDIO_PRINTF
#define Printf printf
#else
#ifdef CHECK_PONY_LOG_FORMAT
extern int Printf(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
#else
extern int Printf(const char* fmt, ...);
#endif  // CHECK_PONY_LOG_FORMAT
#define printf Printf
#endif

#define CRLF            "\n\r"

// This will cut only the file name of the source file, abandon its path.
// This calculation would happen at compile time.
// e.g.
// If the __FILE__ "./a/b/c/d/e/f/g.c" generates a string with a addr,
// the __FILENAME__ will be the addr + 14, i.e., "g.c"
#ifdef __TASKING__
#define __FILENAME__ \
  (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#else
#define __FILENAME__ \
  (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_DEBUG
#endif  // DEBUG_LEVEL

// clang-format off
#define DEBUG_DISABLE  0
#define DEBUG_FATAL    1
#define DEBUG_ALARM    2
#define DEBUG_ERR      3
#define DEBUG_WARNING  4
#define DEBUG_INFO     5
#define DEBUG_DEBUG    6

TASKING_DISABLE_WARNING_W537 static const char* const kDebugLevelStr[] = {
    "U",  // Placeholder for "DEBUG_DISABLE", won't be used actually.
    "F",  // FATAL
    "A",  // ALARM
    "E",  // ERROR
    "W",  // WARNING
    "I",  // INFO
    "D",  // DEBUG
};

#ifdef USE_COLOR_LOGGING
// ascii color codes
#define COLOR_EMPTY     ""
#define COLOR_RED       "\033[1;31m"
#define COLOR_GREEN     "\033[1;32m"
#define COLOR_YELLOW    "\033[1;33m"
#define COLOR_PURPLE    "\033[1;35m"
#define COLOR_CYAN      "\033[1;36m"
#define COLOR_RESET     "\033[0m"
#define COLOR_RED_HL    "\033[41m"

TASKING_DISABLE_WARNING_W537 static const char* const kDebugLevelColor[] = {
  COLOR_RESET,   // RESET
  COLOR_RED_HL,  // FATAL
  COLOR_PURPLE,  // ALARM
  COLOR_RED,     // ERROR
  COLOR_YELLOW,  // WARNING
  COLOR_GREEN,   // INFO
  COLOR_RESET,   // DEBUG
};

#define COLOR_FMT "%s"
#define COLOR_ARG(level) kDebugLevelColor[level],
#define COLOR_RST COLOR_RESET
#else
#define COLOR_FMT
#define COLOR_ARG(level)
#define COLOR_RST
#endif

TASKING_WARNING_DEFAULT
// clang-format on

typedef int32_t(*DebugWriteFuncPtr)(const uint8_t* buffer, uint32_t len);

// Note: User should define and register there owen debug write function in their product.
ReturnCode RegisterDebugWriteFunc(DebugWriteFuncPtr func);

#define PONY_LOG(level, fmt, args...)                       \
  do {                                                      \
    if (level <= DEBUG_LEVEL) {                             \
      Printf(COLOR_FMT "%s %ld %s:%d] " fmt COLOR_RST CRLF, \
             COLOR_ARG(level) kDebugLevelStr[level],        \
             DebugGetTimestampInternal(),                   \
             __FILENAME__,                                  \
             __LINE__,                                      \
             ##args);                                       \
    }                                                       \
  } while (0)

#define PONY_ASSERT(statement)                                         \
  if (!(statement)) {                                                  \
    TASKING_DISABLE_WARNING_W557 PONY_LOG(                             \
        DEBUG_FATAL,                                                   \
        "ASSERTION \"%s\" FAILED: FILE \"%s\", LINE %d, FUNCTION: %s", \
        #statement,                                                    \
        __FILE__,                                                      \
        __LINE__,                                                      \
        __FUNCTION__);                                                 \
    while (1)                                                          \
      ;                                                                \
    TASKING_WARNING_DEFAULT                                            \
  }

#ifdef USER_ASSERTION_DELAY_COUNT
#define ASSERTION_DELAY_COUNT USER_ASSERTION_DELAY_COUNT
#else
// The number 1e7 equals to ~3 seconds delay on a 300MHz processor
#define ASSERTION_DELAY_COUNT (1e7)
#endif

#define ASSERT(statement)                    \
  do {                                       \
    if (!(statement)) {                      \
      while (1) {                            \
        PONY_LOG(DEBUG_FATAL, "Asserted! "); \
        int delay = ASSERTION_DELAY_COUNT;   \
        while (delay--) {                    \
        }                                    \
      }                                      \
    }                                        \
  } while (0)

#define ASSERT_(statement, format, args...)                 \
  do {                                                      \
    if (!(statement)) {                                     \
      while (1) {                                           \
        PONY_LOG(DEBUG_FATAL, "Asserted! " format, ##args); \
        int delay = ASSERTION_DELAY_COUNT;                  \
        while (delay--) {                                   \
        }                                                   \
      }                                                     \
    }                                                       \
  } while (0)

// clang-format off
#ifndef CHECK
#define CHECK(statement, format, args...) \
  ASSERT_((statement), format, ##args)
#endif

#ifndef CHECK_OK
#define CHECK_OK(statement, format, args...) \
  ASSERT_(((ReturnCode)(statement) == ERROR_OK), format, ##args)
#endif

#undef DEBUG
#define DEBUG(format, args...)   PONY_LOG(DEBUG_DEBUG,   format, ##args)
#define INFO(format, args...)    PONY_LOG(DEBUG_INFO,    format, ##args);
#define INFO_HL(format, args...) PONY_LOG(DEBUG_ALARM,   format, ##args);
#define ERROR(format, args...)   PONY_LOG(DEBUG_ERR,     format, ##args);
#define WARNING(format, args...) PONY_LOG(DEBUG_WARNING, format, ##args);
#define FATAL(format, args...)   ASSERT_(0, format, ##args)
// clang-format on

#define LOG_TO_BUFFER(pbuf, space, format, ...)                 \
  do {                                                          \
    if ((space) < 0) {                                          \
      ERROR("Invalid space");                                   \
      break;                                                    \
    }                                                           \
    int ret = snprintf((pbuf), (space), format, ##__VA_ARGS__); \
    if (ret < 0) {                                              \
      ERROR("snprintf err:%d.", ret);                           \
      break;                                                    \
    }                                                           \
    (pbuf) += ret;                                              \
    (space) -= ret;                                             \
  } while (0)

#define RETURN_IF_ERROR(statement)                              \
  do {                                                          \
    ReturnCode _result = (statement);                           \
    if ((ReturnCode)_result != ERROR_OK) {                      \
      ERROR("CallTrace: %s returned %ld.", #statement, _result); \
      return _result;                                           \
    }                                                           \
  } while (0)

#define LOG_IF_ERROR(statement)                                     \
  do {                                                              \
    ReturnCode _result = (statement);                               \
    if ((ReturnCode)_result != ERROR_OK) {                          \
      ERROR("LOG_IF_ERROR: %s returned %ld.", #statement, _result); \
    }                                                               \
  } while (0)

#define RETURN_IF_NULL(val, ret)             \
  do {                                       \
    if (val == NULL) {                       \
      ERROR("CallTrace: %s is NULL.", #val); \
      return ret;                            \
    }                                        \
  } while (0);

#define RETURN_IF_OUT_OF_RANGE(val, max, ret)                                         \
  do {                                                                                \
    if (val >= max) {                                                                 \
      ERROR("CallTrace: %s (%d) is out of range, max %d.", #val, (int)val, (int)max); \
      return ret;                                                                     \
    }                                                                                 \
  } while (0);

#define RETURN_IF_ERROR_ERASE_EXCLUDE(statement)               \
  do {                                                         \
    ReturnCode _result = (statement);                          \
    if ((_result != ERROR_OK) && (_result != ERROR_ERASED)) {  \
      ERROR("%s returned %ld.", #statement, _result);          \
      return _result;                                          \
    }                                                          \
  } while (0)

// Note: Users needs to implement their own functions to override the default ones for:
// int32_t DebugGetTimestampInternal(void);
// if they want the logging utilities to print out things.

// The logging macros will call this function internally to get timestamp for logs.
// User should implement this function in the product code.
extern int32_t DebugGetTimestampInternal(void);

#ifdef __cplusplus
}
#endif

#endif  // COMMON_MCU_UTILS_DEBUG_H_
