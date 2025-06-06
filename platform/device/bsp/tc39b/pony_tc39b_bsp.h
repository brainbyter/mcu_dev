// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_TC39B_PONY_TC39B_BSP_H_
#define PLATFORM_TC39B_PONY_TC39B_BSP_H_

#include <stdbool.h>
#include <stdint.h>

typedef enum Tc3xxSwapAddrCfgType {
  kSwapAddrcfgReserved0 = 0,
  kSwapAddrcfgStandard = 1,
  kSwapAddrcfgAlternate = 2,
  kSwapAddrcfgReserved1 = 3,
} Tc3xxSwapAddrCfgType;

bool IsTc39bCpu0Ddis(void);
bool IsTc39bCpu1Ddis(void);
bool IsTc39bCpu2Ddis(void);
bool IsTc39bCpu3Ddis(void);
bool IsTc39bCpu4Ddis(void);
bool IsTc39bCpu5Ddis(void);

bool IsTc3xxSwapEn(void);
Tc3xxSwapAddrCfgType Tc3xxGetSwapAddrCfgType(void);
void PrintCpuInfo(void);

#endif  // PLATFORM_TC39B_PONY_TC39B_BSP_H_
