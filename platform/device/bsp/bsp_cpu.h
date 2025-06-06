// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_BSP_BSP_CPU_H_
#define PLATFORM_DEVICE_BSP_BSP_CPU_H_

#include <stdio.h>

#include "common/mcu/utils/status.h"

typedef enum CpuResetType {
  kResetTypeGeneral = 0,
  kResetTypePin = 1,     // Reset from reset pin, warm reset.
  kResetTypeSw = 2,      // Software reset
  kResetTypeIwdg = 3,    // Independent Watchdog reset
  kResetTypeWwdg = 4,    // Window Watchdog reset
  kResetTypeLpwr = 5,    // Low Power reset
  kResetTypeBackup = 6,  // Backup reset
  kResetTypeDebug = 7,   // Debug reset by debugger
  kResetTypeInvalid,
} CpuResetType;

typedef struct CpuBspStruct {
  uint8_t number;
  uint32_t (*getCpuClkFreqCore)(void);
  uint32_t (*getCpuSystemTick)(void);
  uint32_t (*getCpuSystemTickOverNs)(uint32_t now_systick);
  uint64_t (*getCpuSystemUpTimeNs)(void);
  CpuResetType (*getCpuResetType)(void);
  void (*reboot)(void);
  void (*tickOverFlowHandler)(uint32_t tick_h, void* param);
  void* param;
} cpu_bsp_t, *p_cpu_bsp_t;

extern uint32_t GetCpuClkFreq(uint32_t number);
extern uint32_t GetSystemTick(uint32_t number);
extern uint32_t GetSystemTickOverNs(uint32_t number, uint32_t now_systick);
extern uint64_t GetSystemUpTimeNs(uint32_t number);
extern ReturnCode RebootCpu(uint32_t number);
extern CpuResetType GetCpuResetType(uint32_t number);

// Please define ENABLE_TICK_OVERFLOW_HOOK if you want to enable the hooked function.
extern ReturnCode SetCpuTickOverFlowHandler(uint32_t number,
                                            void (tickOverFlowHandler)(uint32_t tick_h, void* param));

// RegisterCpu() should be only called by BSP layer
// KEEP IN MIND, it only registers the pointer to the cpu_bsp_t rather than the content within it,
// so do not pass a pointer to a local variable.
extern ReturnCode RegisterCpu(p_cpu_bsp_t cpuX);

#endif  // PLATFORM_DEVICE_BSP_BSP_CPU_H_
