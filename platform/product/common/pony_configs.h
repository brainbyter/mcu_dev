// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef COMMON_PONY_CONFIGS_H_
#define COMMON_PONY_CONFIGS_H_

#define _INCLUDE_CONFIGS(x) #x
#define INCLUDE_CONFIGS(x) _INCLUDE_CONFIGS(x)

#ifdef PONY_CONFIGS
#include INCLUDE_CONFIGS(PONY_CONFIGS)
#endif

#endif  // COMMON_PONY_CONFIGS_H_
