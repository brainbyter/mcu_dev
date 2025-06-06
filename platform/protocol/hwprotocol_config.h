// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_PROTOCOL_HWPROTOCOL_CONFIG_H_
#define PLATFORM_PROTOCOL_HWPROTOCOL_CONFIG_H_

#define _INCLUDE_HWCONFIG(x) #x
#define INCLUDE_HWCONFIG(x) _INCLUDE_HWCONFIG(x)

#ifdef HWPROTOOCL_CONFIG
#include INCLUDE_HWCONFIG(HWPROTOOCL_CONFIG)
#else
#include "platform/protocol/hwprotocol_def.h"
#endif

#endif  // PLATFORM_PROTOCOL_HWPROTOCOL_CONFIG_H_
