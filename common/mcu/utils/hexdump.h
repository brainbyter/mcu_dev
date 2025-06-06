// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef COMMON_MCU_UTILS_HEXDUMP_H_
#define COMMON_MCU_UTILS_HEXDUMP_H_

#include "common/mcu/utils/debug.h"
#include "common/mcu/utils/status.h"

#ifdef __cplusplus
extern "C" {
#endif

// The HexDump utility dumps a block of memory in a format similar to the linux "xxd".
// There will be 16 bytes dumped per line. The unprintable chars are replaced by ".".
// Example:
// Code:
// ```
// const char* pangram = "The quick brown fox jumps over the lazy dog\1\2\3\4\5";
// PONY_LOG_HEXDUMP(DEBUG_INFO, pangram, strlen(pangram));
// ```
// output (console):
// ```
// I 2001 xxxxxx.c:123] HexDump of "pangram" (0x4149dc):
// 00000000: 5468 6520 7175 6963 6b20 6272 6f77 6e20  The quick brown
// 00000010: 666f 7820 6a75 6d70 7320 6f76 6572 2074  fox jumps over t
// 00000020: 6865 206c 617a 7920 646f 6701 0203 0405  he lazy dog.....
// ```

// Hex-dump a block of memory and print the results by print_line function.
ReturnCode HexDumpImpl(const void* memory,
                       int length,
                       void (*print_line)(const char* line, void* print_line_param),
                       void* print_line_param);

static inline void PonyLogPrintLine(const char* line, void* param) {
  int level = *((int*)param);
  if (level <= DEBUG_LEVEL) {
    Printf(COLOR_FMT "%s" COLOR_RST CRLF, COLOR_ARG(level) line);
  }
}

// A convenient macro to dump a block of memory to the debug console.
#define PONY_LOG_HEXDUMP(level, memory, length)                             \
  do {                                                                      \
    if (level <= DEBUG_LEVEL) {                                             \
      PONY_LOG(level, "HexDump of \"%s\" (0x%lx):", #memory, (long)memory); \
      int param = level;                                                    \
      HexDumpImpl(memory, length, PonyLogPrintLine, &param);                \
    }                                                                       \
  } while (0)

#ifdef __cplusplus
}
#endif

#endif  // COMMON_MCU_UTILS_HEXDUMP_H_
