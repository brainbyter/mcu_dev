// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_SDK_CAN_H_
#define PRODUCTS_F0100_0001_AURIX_A_SDK_CAN_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"
#include "platform/device/driver/nxp/tja1145/tja1145.h"

void InitCanDevices(void);
ReturnCode ClearCanBuffer(int8_t can_index);
ReturnCode TestCanStressSend(int8_t send_can, int8_t can_fd_select, float load);
ReturnCode TestCanStressRecv(int8_t recv_can, int8_t can_fd_select, float load);
void TestStressCan(int8_t send_can, int8_t recv_can, int8_t can_fd_select, float load);
void TestCanSend(int8_t send_can, int8_t can_fd_select);
void TestCanRecv(int8_t recv_can);
ReturnCode SetTja1145SleepMode(void);
void OpenCanDevices(const uint16_t* can_array, int size);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_CAN_H_
