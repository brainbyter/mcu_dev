// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef COMMON_MCU_SYSTEM_INIT_H_
#define COMMON_MCU_SYSTEM_INIT_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PONY_SECTION(x)               __attribute__((section(x)))

#if defined (__TASKING__)
  // We use __attribute__((protect)) to exclude a variable/function from the duplicate/unreferenced
  // section removal optimization in the linker. When we use this attribute, the compiler will
  // add the "protect" section attribute to the symbol's section.
  #define PONY_USED                     __attribute__((used, protect))
  // In the tasking C modules where the variable is declared extern a near access is made which
  // requires that the variable is placed within the first 16 kB. We can use __far to avoit the
  // linker error.
  #define PONY_EXTERN                   __far extern
#else
  #define PONY_USED                     __attribute__((used))
  #define PONY_EXTERN                   extern
#endif

typedef struct InitialStruct {
  const char* name;
  void (*initfunction)(void);
} initial_struct_t, *p_initial_struct_t;

#define MEMBASE(name) ((unsigned long)&__start_##name)
#define MEMLIMIT(name) ((unsigned long)&__stop_##name)
#define MEMSIZE(name) ((long)((&__start_##name) - (&__stop_##name)))

#define DECLARE_TYPE_MEM(type, value) \
  PONY_EXTERN type __start_##value;        \
  PONY_EXTERN type __stop_##value

#define INIT_EXPORT(fn, section)                                                              \
    const static char __pony_##fn##_name[] = #fn;                                             \
    PONY_USED const initial_struct_t __pony_init_desc_##fn PONY_SECTION(".initial" section) = \
        { __pony_##fn##_name, fn};

// The hard steps are for some initial functions for the MCU.
// The bsp steps are for bsp driver’s initial.
// The pre steps are for some initial before the app, just like the initial for the rtos.
// The app steps are for the app’s initial.
#define addHardStep1(func)  INIT_EXPORT(func, "_1")
#define addHardStep2(func)  INIT_EXPORT(func, "_2")
#define addHardStep3(func)  INIT_EXPORT(func, "_3")
#define addHardStep4(func)  INIT_EXPORT(func, "_4")
#define addBspStep1(func)   INIT_EXPORT(func, "_5")
#define addBspStep2(func)   INIT_EXPORT(func, "_6")
#define addBspStep3(func)   INIT_EXPORT(func, "_7")
#define addBspStep4(func)   INIT_EXPORT(func, "_8")
#define addPreStep1(func)   INIT_EXPORT(func, "_9")
#define addPreStep2(func)   INIT_EXPORT(func, "_10")
#define addPreStep3(func)   INIT_EXPORT(func, "_11")
#define addPreStep4(func)   INIT_EXPORT(func, "_12")
#define addAppStep1(func)   INIT_EXPORT(func, "_13")
#define addAppStep2(func)   INIT_EXPORT(func, "_14")
#define addAppStep3(func)   INIT_EXPORT(func, "_15")
#define addAppStep4(func)   INIT_EXPORT(func, "_16")

#define IS_INDEXABLE(arg) (sizeof(arg[0]))
#define IS_ARRAY(arg) (IS_INDEXABLE(arg) && (((void*)&arg) == ((void*)arg)))
#define ARRAY_SIZE(arr) (IS_ARRAY(arr) ? (sizeof(arr) / sizeof(arr[0])) : 0)

#if defined (__TASKING__)
// Please make sure the a/b's type is uint32_t.
#define time_after(a, b) \
  ((int32_t)((b) - (a)) < 0)

// Please make sure the a/b's type is uint16_t.
#define uint16_smaller_than(a, b) \
  ((int16_t)((a) - (b)) < 0)

// Please make sure the a/b's type is uint16_t.
#define uint16_bigger_than(a, b) \
  ((int16_t)((b) - (a)) < 0)

#else

#define typecheck(type, x)         \
  ({                               \
    type __dummy;                  \
    typeof(x) __dummy2;            \
    (void)(&__dummy == &__dummy2); \
    1;                             \
  })

#define time_after(a, b) \
  (typecheck(uint32_t, a) && typecheck(uint32_t, b) && ((int32_t)((b) - (a)) < 0))

#define uint16_smaller_than(a, b) \
  (typecheck(uint16_t, a) && typecheck(uint16_t, b) && ((int16_t)((a) - (b)) < 0))

#define uint16_bigger_than(a, b) \
  (typecheck(uint16_t, a) && typecheck(uint16_t, b) && ((int16_t)((b) - (a)) < 0))

#endif

#define container_of(ptr, type, member) \
  ((type*)((char*)(ptr) - (unsigned long)(&((type*)0)->member)))

#define Invert32Bit(x)        ((uint32_t)((x) ^ ((uint32_t)0xFFFFFFFF)))

void InitialSetup(void);

#ifdef __cplusplus
}
#endif

#endif  // COMMON_MCU_SYSTEM_INIT_H_
