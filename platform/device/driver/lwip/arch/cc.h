// Copyright @2020 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_LWIP_ARCH_CC_H_
#define PLATFORM_DEVICE_DRIVER_LWIP_ARCH_CC_H_

#include <stdint.h>
#include <stdio.h>

#include "platform/product/common/pony_driver.h"
#include "platform/system/debug.h"

#ifndef BYTE_ORDER
#define BYTE_ORDER LITTLE_ENDIAN
#endif

#ifndef __TASKING__  // TASKING already defined these somewhere.
// types used in lwIP
typedef uint8_t u8_t;
typedef int8_t s8_t;
typedef uint16_t u16_t;
typedef int16_t s16_t;
typedef uint32_t u32_t;
typedef int32_t s32_t;
typedef uintptr_t mem_ptr_t;
#endif  // __TASKING__

// the interrupt state flags
// http://savannah.nongnu.org/bugs/?25608
typedef long sys_prot_t;

// formatters for lwIP printf
#define U16_F "hu"
#define S16_F "hd"
#define X16_F "hx"
#define U32_F "u"
#define S32_F "d"
#define X32_F "x"

// pack related
#if defined(__GNUC__)
#define PACK_STRUCT_BEGIN
#define PACK_STRUCT_STRUCT __attribute__((packed))
#define PACK_STRUCT_END
#define PACK_STRUCT_FIELD(x) x
#elif defined(__TASKING__)
#define PACK_STRUCT_BEGIN
#define PACK_STRUCT_STRUCT __packed__
#define PACK_STRUCT_END
#define PACK_STRUCT_FIELD(x) x
#else
#error "This compiler is not supported."
#endif

// Port has no mutexes and binary semaphores should be used instead
#define LWIP_COMPAT_MUTEX 1
// Let lwIP provide ERRNO values and the 'errno' variable
#define LWIP_PROVIDE_ERRNO

// Debug related
#ifdef LWIP_DEBUG
#define LWIP_PLATFORM_DIAG(x) \
  { PrintfPony x; }
#define LWIP_PLATFORM_ASSERT(x)                          \
  {                                                      \
    PONY_LOG(DEBUG_ERR, "Assertion %s failed", x);       \
    PONY_ASSERT(false);                                  \
  }
#else
#define LWIP_PLATFORM_DIAG(x) \
  { ; }
#define LWIP_PLATFORM_ASSERT(x) \
  {                             \
    while (1)                   \
      ;                         \
  }
#endif

#endif  // PLATFORM_DEVICE_DRIVER_LWIP_ARCH_CC_H_
