// Copyright @2023 Pony AI Inc. All rights reserved.

/// @defgroup lwip_driver lwip driver

/// @defgroup lwip_iperf_driver lwip iperf driver
/// @ingroup lwip_driver
/// This is lwip iperf driver.

/// @file
/// @ingroup lwip_iperf_driver
/// @brief the header file for lwip iperf driver

#ifndef PLATFORM_DEVICE_LWIP_IPERF_H_
#define PLATFORM_DEVICE_LWIP_IPERF_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

/// @ingroup lwip_iperf_driver
/// @brief Init the lwip iperf tcp server.
/// @param id [uint8_t] The iperf id.
/// @param port [uint16_t] The iperf tcp server port.
/// @param enable_log [bool] if true, will log to uart.
/// @return ReturnCode: if succeed, return ERROR_OK; if fail, return the error code.
ReturnCode LwipIperfTcpServerInit(uint8_t id, uint16_t port, bool enable_log);

/// @ingroup lwip_iperf_driver
/// @brief Start the lwip iperf tcp server.
/// @param id [uint8_t] The iperf id.
/// @return ReturnCode: if succeed, return ERROR_OK; if fail, return the error code.
ReturnCode LwipIperfTcpServerStart(uint8_t id);

/// @ingroup lwip_iperf_driver
/// @brief Free the resources and stop the lwip iperf tcp server.
/// @param id [uint8_t] The iperf id.
/// @return ReturnCode: if succeed, return ERROR_OK; if fail, return the error code.
ReturnCode LwipIperfTcpServerStop(uint8_t id);

#endif  // PLATFORM_DEVICE_LWIP_IPERF_H_
