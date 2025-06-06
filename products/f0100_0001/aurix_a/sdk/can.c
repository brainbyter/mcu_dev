// Copyright @2022 Pony AI Inc. All rights reserved.

#include "products/f0100_0001/aurix_a/sdk/can.h"

#include "common/mcu/system/init.h"
#include "common/mcu/utils/debug.h"
#include "platform/device/bsp/bsp_can.h"
#include "platform/device/bsp/bsp_delay.h"
#include "platform/device/driver/lwip/netif/ethernetif.h"
#include "platform/device/driver/nxp/tja1145/tja1145.h"
#include "platform/product/common/pony_driver.h"

#define MIN_CAN_INDEX 0
#define MAX_CAN_INDEX 7

#define CAN_FRAME_BITS 110

enum CanMsgId {
  kPonyProtocolRxID = 0x760,
  kPonyProtocolTxID = 0x768,
  kTcan1145SelectiveWakeCanId = 0x111,
};

#define PONY_CAN_RX_BUF_SIZE 1024
#define PONY_CAN_TX_BUF_SIZE 8

#define PONY_CAN_RX_BUF_SIZE 1024
#define PONY_CAN_TX_BUF_SIZE 8

#if defined(SUPPORT_FOR_F0100_04_0000)
static can_filter_item g_filter_items[] = {
    CAN_FILTER_STD_PASSTHROUGH,
};
#else
static can_filter_item g_filter_items[] = {
    CAN_FILTER_STD_INIT(kPonyProtocolRxID),
    CAN_FILTER_STD_INIT(0x100),
    CAN_FILTER_STD_INIT(0x123),
    CAN_FILTER_STD_INIT(0x200),
    CAN_FILTER_STD_INIT(0x777),
};
#endif  // SUPPORT_FOR_F0100_04_0000

static can_filter_config_t g_filter_config = {ARRAY_SIZE(g_filter_items), 1, g_filter_items};

static const uint16_t g_can_num[] = {kCan1, kCan2, kCan3, kCan4, kCan5, kCan6, kCan7, kCan8};
const uint32_t kTestCanMsgCount = 100;
const uint32_t kTestStressCanMsgCount = 256;
uint8_t kTestData[] = {
  0x01,
  0x02,
  0x03,
  0x04,
  0x05,
  0x06,
  0x07,
  0x08,
};

uint8_t kCanFdTestData[] = {
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,
  0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20,
  0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30,
  0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40,
};

static const uint16_t kTja1145SelectiveWakeCanID = 0x123;

static const uint8_t kTja1145SelectiveWakeCanData[] = {
  0x01,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x01,
};

static Tja1145Device g_tja1145s = {
  .config.bus_num = 2,
  .config.slave_num = 1,
  .dev = {0},
};

#if defined(SUPPORT_FOR_F0100_02_0000) || defined(SUPPORT_FOR_F0100)
#define PONY_CAN_RX_BUF_SIZE 1024
#define PONY_CAN_TX_BUF_SIZE 8

static uint8_t g_pony_can_rxbuf[PONY_CAN_RX_BUF_SIZE] = {0};
static uint8_t g_pony_can_txbuf[PONY_CAN_TX_BUF_SIZE] = {0};

static pony_virtual_can_uart_t g_pony_can = {
    .number = 0,
    .can_number = kCan3,
    .rx_can_id = kPonyProtocolRxID,
    .tx_can_id = kPonyProtocolTxID,
    .ide = kCanIdStd,
    .fdf = kCanFdTypeClassic,
    .rxbuf = g_pony_can_rxbuf,
    .rxbufsize = PONY_CAN_RX_BUF_SIZE,
    .txbuf = g_pony_can_txbuf,
    .txbufsize = PONY_CAN_TX_BUF_SIZE,
};
#endif  // SUPPORT_FOR_F0100_02_0000

static void SetTja1145BasicSetting(void) {
  uint8_t val_reg = 0;
  uint8_t val = 0;
  Tja1145GetStatus(&g_tja1145s.dev, kTja1145SettingGlobalEvent, &val_reg);
  if (val_reg) {
    PONY_LOG(DEBUG_INFO, "Tja1145 global event val is 0x%x.", val_reg);
    Tja1145GetStatus(&g_tja1145s.dev, kTja1145SettingPo, &val);
    if (val) {
      Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingPo, TJA1145_PO_CLEAR);
    }
    Tja1145GetStatus(&g_tja1145s.dev, kTja1145SettingCw, &val);
    if (val) {
      Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingCw, TJA1145_CW_CLEAR);
    }
  }
  Tja1145GetStatus(&g_tja1145s.dev, kTja1145SettingGlobalEvent, &val_reg);
  PONY_LOG(DEBUG_INFO, "Tja1145 global event val modify to 0x%x.", val_reg);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingCfdc, TJA1145_ENABLE_FD_TOLERANCE);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingCdr, TJA1145_DATA_RATE_500K);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingIde, TJA1145_FRAME_STANDARD);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingDlc, TJA1145_DLC_8);
}

static void SetTja1145SelectiveWake(void) {
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingPndm, TJA1145_PARTIAL_DLC_DATA_EVALUATED);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingstandardIdentifier10to6,
                   kTja1145SelectiveWakeCanID >> 6 & 0x1f);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingstandardIdentifier5to0,
                   kTja1145SelectiveWakeCanID & 0x3f);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingstandardMask10to6, 0x0);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingstandardMask5to0, 0x0);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingDataMask0, kTja1145SelectiveWakeCanData[0]);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingDataMask1, kTja1145SelectiveWakeCanData[1]);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingDataMask2, kTja1145SelectiveWakeCanData[2]);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingDataMask3, kTja1145SelectiveWakeCanData[3]);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingDataMask4, kTja1145SelectiveWakeCanData[4]);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingDataMask5, kTja1145SelectiveWakeCanData[5]);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingDataMask6, kTja1145SelectiveWakeCanData[6]);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingDataMask7, kTja1145SelectiveWakeCanData[7]);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingPncOk, TJA1145_CONFIGURE_PARTIAL_NETWORK_SUCCESS);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingCwe, TJA1145_CAN_WAKEUP_ENABLE);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingPncOk, TJA1145_CONFIGURE_PARTIAL_NETWORK_SUCCESS);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingCpnc, TJA1145_ENABLE_SELECTIVE_WAKE_UP);
  Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingPncOk, TJA1145_CONFIGURE_PARTIAL_NETWORK_SUCCESS);
}

static void InitTja1145(void) {
  ReturnCode ret = Tja1145InitWithConfiguration(&g_tja1145s);
  if (ret != ERROR_OK) {
    PONY_LOG(DEBUG_ERR, "Failed to init tja1145, result=%d.", ret);
  }
  SetTja1145BasicSetting();
  SetTja1145SelectiveWake();
}

void OpenCanDevices(const uint16_t* can_array, int size) {
  for (int i = 0; i < size; i++) {
    PONY_ASSERT(CanOpen(can_array[i]) == ERROR_OK);
    CanIoctl(can_array[i], kCanIoctlCmdSetFilter, &g_filter_config);
  }
}

void InitCanDevices(void) {
  InitTja1145();
  OpenCanDevices(g_can_num, ARRAY_SIZE(g_can_num));
#if defined(SUPPORT_FOR_F0100_02_0000) || defined(SUPPORT_FOR_F0100)
  PONY_LOG(DEBUG_INFO, "Add virtual CAN.");
  PONY_ASSERT(RegisterVirtualCanUart(&g_pony_can) == ERROR_OK);
#endif
  PONY_LOG(DEBUG_INFO, "Can init done.");
}

static int GetDelayTimeWithPercentageLoad(float load, int8_t can_fd_select) {
  if (load < 0 || load > 1) {
    return -1;
  }
  // The unit of return value is Us
  int16_t bits = can_fd_select? 121 : 110;
  return (int)((1 / (kCANBaudrate500K * load / bits)) * 1000 * 1000);
}

ReturnCode TestCanStressSend(int8_t send_can, int8_t can_fd_select, float load) {
  can_msg_t temp_msg = {
    .ide = kCanIdStd,
    .id = 0x123,
    .rtr = kCanRtrData,
    .fdf = can_fd_select? kCanFdTypeCanFd : kCanFdTypeClassic,
    .len = can_fd_select? 64 : 8,
  };
  if (temp_msg.fdf == kCanFdTypeCanFd) {
    memcpy(temp_msg.data, kCanFdTestData, sizeof(kCanFdTestData));
    PONY_LOG(DEBUG_ERR, "Start CANFD TEST.");
  } else {
    memcpy(temp_msg.data, kTestData, sizeof(kTestData));
    PONY_LOG(DEBUG_ERR, "Start CAN TEST.");
  }
  int delay_time = GetDelayTimeWithPercentageLoad(load, can_fd_select);
  if (delay_time == -1) {
    PONY_LOG(DEBUG_ERR, "load value out of range.");
    return ERROR_GENERAL;
  }
  int i = 0;
  for (i = 0; i < kTestStressCanMsgCount; i++) {
    int count = CanMsgSend(g_can_num[send_can], &temp_msg, 1);
    if (count != 1) {
      PONY_LOG(DEBUG_ERR, "can%d send failed, %d frame has been send", send_can, i);
      break;
    }
    DelayUs(delay_time);
  }
  if (i == kTestStressCanMsgCount) {
    PONY_LOG(DEBUG_INFO, "can%d send successfully", send_can);
  }
  return ERROR_OK;
}

ReturnCode ClearCanBuffer(int8_t can_index) {
  can_msg_t message = {0};
  uint32_t max_clear_num = 256;
  while (CanMsgRecv(g_can_num[can_index], &message, 1) && max_clear_num--) {}
  if (max_clear_num != 0) {
    PONY_LOG(DEBUG_INFO, "Cleared %d frames of can message", 256 - max_clear_num);
    return ERROR_OK;
  }
  PONY_LOG(DEBUG_INFO, "Cleared 256 frames of can message, "
                "Please perform the operation again to avoid omissions");
  return ERROR_GENERAL;
}

ReturnCode TestCanStressRecv(int8_t recv_can, int8_t can_fd_select, float load) {
  uint32_t kTestStressCanMsgTimeOut = 300000;
  int count = 0;
  uint16_t rev_count = 0;
  can_msg_t message = {0};
  uint16_t test_failed = 0;
  int delay_time = GetDelayTimeWithPercentageLoad(load, can_fd_select);
  if (delay_time == -1) {
    PONY_LOG(DEBUG_ERR, "load value out of range.");
    return ERROR_GENERAL;
  }
  while (kTestStressCanMsgTimeOut) {
    count = CanMsgRecv(g_can_num[recv_can], &message, 1);
    if (count != 1) {
      kTestStressCanMsgTimeOut--;
      DelayUs(delay_time / 10);
      if (kTestStressCanMsgTimeOut % 10) {
        LwipTask();
      }
      continue;
    }
    if (message.id != 0x123) {
      test_failed++;
      continue;
    }
    uint8_t* kTestDataBuf;
    if (message.fdf == kCanFdTypeCanFd) {
      kTestDataBuf = &kCanFdTestData[0];
    } else {
      kTestDataBuf = &kTestData[0];
    }
    if (memcmp(message.data, kTestDataBuf, message.len)) {
      test_failed++;
      continue;
    }
    rev_count++;
    if (rev_count == kTestStressCanMsgCount) {
      break;
    }
    kTestStressCanMsgTimeOut = 300000;
  }
  if (rev_count == kTestStressCanMsgCount) {
    PONY_LOG(DEBUG_ERR, "can%d rev successfully", recv_can);
  } else {
    PONY_LOG(DEBUG_ERR, "can%d rev failed, rev frame count %d, failed count %d", recv_can, rev_count,
                 test_failed);
  }
  return ERROR_OK;
}

void TestCanSend(int8_t send_can, int8_t can_fd_select) {
  can_msg_t temp_msg = {
    .ide = kCanIdStd,
    .id = 0x123,
    .rtr = kCanRtrData,
    .fdf = can_fd_select? kCanFdTypeCanFd : kCanFdTypeClassic,
    .len = can_fd_select? 64 : 8,
  };
  if (temp_msg.fdf == kCanFdTypeCanFd) {
    memcpy(temp_msg.data, kCanFdTestData, sizeof(kCanFdTestData));
    PONY_LOG(DEBUG_ERR, "Start CANFD TEST.");
  } else {
    memcpy(temp_msg.data, kTestData, sizeof(kTestData));
    PONY_LOG(DEBUG_ERR, "Start CAN TEST.");
  }

  int count = CanMsgSend(g_can_num[send_can], &temp_msg, 1);
  if (count != 1) {
    PONY_LOG(DEBUG_ERR, "Failed to send, can id: %d count: %d.", send_can, count);
  }
  PONY_LOG(DEBUG_ERR, "send succes, can id: %d count: %d.", send_can, count);
}

void TestCanRecv(int8_t recv_can) {
  can_msg_t message = {0};
  int count = CanMsgRecv(g_can_num[recv_can], &message, 1);
  if (count != 1) {
    PONY_LOG(DEBUG_ERR, "Failed to recv, can id: %d.", recv_can);
  }

  if (message.fdf) {
    PONY_LOG(DEBUG_ERR, "Rev CAN FD frame");
  } else {
    PONY_LOG(DEBUG_ERR, "Rev CAN frame");
  }
  PONY_LOG(DEBUG_ERR, "CAN ID: 0x%x", message.id);
  PONY_LOG(DEBUG_ERR, "CAN_MSG_DLEN: %d", message.len);
  PONY_LOG(DEBUG_ERR, "Recv Data: ");
  for (int i = 0; i < message.len; ++i) {
    PONY_LOG(DEBUG_ERR, "0x%x", message.data[i]);
  }
  Printf(".\r\n");
}

static ReturnCode StressCanCheck(int16_t send_can, int16_t recv_can,
                                 int8_t can_fd_select, float load) {
  can_msg_t temp_msg = {
    .ide = kCanIdStd,
    .id = 0x123,
    .rtr = kCanRtrData,
    .fdf = can_fd_select ? kCanFdTypeCanFd : kCanFdTypeClassic,
    .len = can_fd_select ? 64 : 8,
  };

  if (temp_msg.fdf == kCanFdTypeCanFd) {
    memcpy(temp_msg.data, kCanFdTestData, sizeof(kCanFdTestData));
    PONY_LOG(DEBUG_ERR, "Start CANFD TEST.");
  } else {
    memcpy(temp_msg.data, kTestData, sizeof(kTestData));
    PONY_LOG(DEBUG_ERR, "Start CAN TEST.");
  }

  uint8_t* kTestDataBuf = NULL;
  if (can_fd_select) {
    kTestDataBuf = &kCanFdTestData[0];
  } else {
    kTestDataBuf = &kTestData[0];
  }

  for (int j = 0; j < kTestStressCanMsgCount; j++) {
    int count = CanMsgSend(send_can, &temp_msg, 1);
    if (count != 1) {
      return ERROR_GENERAL;
    }
    int delay_time = GetDelayTimeWithPercentageLoad(load, can_fd_select);
    if (delay_time == -1) {
      PONY_LOG(DEBUG_ERR, "load value out of range.");
      return ERROR_OUT_OF_RANGE;
    }
    DelayUs(delay_time);
    can_msg_t message = {0};
    count = CanMsgRecv(recv_can, &message, 1);
    if (count != 1 || message.id != 0x123 || \
        memcmp(message.data, kTestDataBuf, sizeof(kTestDataBuf))) {
      return ERROR_GENERAL;
    }
  }
  return ERROR_OK;
}

void TestStressCan(int8_t send_can, int8_t recv_can, int8_t can_fd_select, float load) {
  if (send_can >= MIN_CAN_INDEX && send_can <= MAX_CAN_INDEX &&
      recv_can >= MIN_CAN_INDEX && recv_can <= MAX_CAN_INDEX && send_can != recv_can) {
    if (StressCanCheck(g_can_num[send_can], g_can_num[recv_can],
                       can_fd_select, load) != ERROR_OK) {
      PONY_LOG(DEBUG_ERR, "can%d send to can%d failed.", send_can, recv_can);
      return;
    }
    Printf("can%d send to can%d successfully.\r\n", send_can, recv_can);
    return;
  }
  PONY_LOG(DEBUG_ERR, "send_can:%d, recv_can:%d, invalid parameter.", send_can, recv_can);
}

ReturnCode SetTja1145SleepMode(void) {
  uint8_t val_reg = 0;
  uint8_t val = 0;
  Tja1145GetStatus(&g_tja1145s.dev, kTja1145SettingGlobalEvent, &val_reg);
  PONY_LOG(DEBUG_INFO, "Tja1145 global event val when set to sleep is 0x%x.", val_reg);
  if (val_reg) {
    Tja1145GetStatus(&g_tja1145s.dev, kTja1145SettingPo, &val);
    if (val) {
      Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingPo, TJA1145_PO_CLEAR);
    }
    Tja1145GetStatus(&g_tja1145s.dev, kTja1145SettingCw, &val);
    if (val) {
      Tja1145RegConfig(&g_tja1145s.dev, kTja1145SettingCw, TJA1145_CW_CLEAR);
    }
  }
  Tja1145GetStatus(&g_tja1145s.dev, kTja1145SettingGlobalEvent, &val_reg);
  PONY_LOG(DEBUG_INFO, "Tja1145 global event val modify to 0x%x.", val_reg);
  return Tja1145SetToSleepMode(&g_tja1145s.dev);
}

addAppStep3(InitCanDevices);
