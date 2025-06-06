// Copyright @2020 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_LWIP_ARCH_LWIPOPTS_H_
#define PLATFORM_DEVICE_DRIVER_LWIP_ARCH_LWIPOPTS_H_

// Please define options for lwIP in xxx_driver.h
// Check all the options from src/include/lwip/opt.h in lwIP
#include "platform/product/common/pony_driver.h"

#ifdef LWIPOPTS_USE_NO_SYS_DEFAULT

#include "platform/device/driver/lwip/arch/lwipopts_no_sys_default.h"

#endif

#endif  // PLATFORM_DEVICE_DRIVER_LWIP_ARCH_LWIPOPTS_H_
