// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_SDK_NETWORK_H_
#define PRODUCTS_F0100_0001_AURIX_A_SDK_NETWORK_H_

#include "common/mcu/utils/status.h"

// When not using state machine to manage the network, this API can be used to initialize network,
// include switch and phys.
ReturnCode InitNetwork(void);
ReturnCode InitNetworkProtocolStack(void);

#endif  // PRODUCTS_F0100_0001_AURIX_A_SDK_NETWORK_H_
