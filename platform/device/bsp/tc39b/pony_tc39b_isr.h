// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_TC39B_PONY_TC39B_ISR_H_
#define PLATFORM_TC39B_PONY_TC39B_ISR_H_

#include "iLLD/TC39B/Tricore/_Impl/IfxSrc_cfg.h"

#include "common/mcu/utils/debug.h"

#define TC39B_CPU_COUNT 6

ReturnCode Tc39bMapCpuIdToServiceProvider(int cpu_id, IfxSrc_Tos* service_provider);

#endif  // PLATFORM_TC39B_PONY_TC39B_ISR_H_
