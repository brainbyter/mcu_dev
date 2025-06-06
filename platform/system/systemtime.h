// Copyright @2019-2022 Pony AI Inc. All rights reserved.

#ifndef SYSTEM_SYSTEMTIME_H_
#define SYSTEM_SYSTEMTIME_H_

#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include "common/mcu/utils/status.h"

#define TIME_STRUCT_TM_YEAR_BASE 1900

#define MILLISEC_PER_SEC (1000)
#define MICROSEC_PER_SEC (1000000)
#define NANOSEC_PER_SEC (1000000000)

time_t GetSystemTimeInSeconds(void);
int64_t GetSystemTimeInMilliseconds(void);
int64_t GetSystemTimeInMicroSeconds(void);
int64_t SystemClock(void);
void SetSystemClock(int64_t target_tick);
void InitSystemTime(void);
ReturnCode GetSystemTime(uint32_t* sec, uint32_t* us);
ReturnCode SetSystemTime(uint32_t utc_sec, uint32_t utc_us);

uint64_t ConvertToNanoSec(uint32_t seconds, uint32_t nanoseconds);

#endif  //  SYSTEM_SYSTEMTIME_H_
