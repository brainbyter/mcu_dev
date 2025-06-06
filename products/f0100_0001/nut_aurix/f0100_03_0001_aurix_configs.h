// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_03_0001_AURIX_CONFIGS_H_
#define PRODUCTS_F0100_03_0001_AURIX_CONFIGS_H_

#define PONY_DRIVER_PATH "products/f0100_0001/nut_aurix/f0100_03_0001_aurix_driver.h"
#ifdef F0100_03_0001_SDK_CONFIG
#define PONY_BSP_PATH "products/f0100_0001/nut_aurix/f0100_03_0001_aurix_sdk_bsp.h"
#define PONY_SYSTEM_PATH "products/f0100_0001/nut_aurix/f0100_03_0001_aurix_sdk_system.h"
#define PONY_COMM_PATH "products/f0100_0001/nut_aurix/f0100_03_0001_aurix_sdk_comm.h"
#else
#define PONY_BSP_PATH "products/f0100_0001/nut_aurix/f0100_03_0001_aurix_bsp.h"
#define PONY_SYSTEM_PATH "products/f0100_0001/nut_aurix/f0100_03_0001_aurix_system.h"
#define PONY_COMM_PATH "products/f0100_0001/nut_aurix/f0100_03_0001_aurix_comm.h"
#endif

#endif  // PRODUCTS_F0100_03_0001_AURIX_CONFIGS_H_
