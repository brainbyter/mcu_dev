// Copyright @2024 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_SDK_CAN_BRIDGE_DEMO_H_
#define PRODUCTS_F0100_0001_AURIX_A_SDK_CAN_BRIDGE_DEMO_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

ReturnCode InitCanBridgeDemo(void);
void CanTransferTask(void);

#endif  // PRODUCTS_F0100_0001_AURIX_A_SDK_CAN_BRIDGE_DEMO_H_
