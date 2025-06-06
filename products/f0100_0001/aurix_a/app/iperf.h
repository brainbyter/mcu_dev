// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_IPERF_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_IPERF_H_

#include "common/mcu/utils/status.h"

ReturnCode InitIperfTcpServer(void);
ReturnCode StartIperfTcpServer(void);
ReturnCode StopIperfTcpServer(void);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_IPERF_H_
