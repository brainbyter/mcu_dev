// Copyright @2024 Pony AI Inc. All rights reserved.

#include "common/mcu/system/init.h"
#include "common/mcu/utils/debug.h"
#include "common/mcu/utils/status.h"
#include "platform/device/bsp/bsp_can.h"
#include "platform/device/driver/lwip/lwip_utils/udp_server.h"
#include "platform/device/driver/lwip/netif/ethernetif.h"
#include "platform/product/common/pony_driver.h"
#include "products/f0100_0001/aurix_a/app/config.h"
#include "products/f0100_0001/aurix_a/sdk/can.h"
#include "products/f0100_0001/aurix_a/sdk/can_bridge_demo.h"

#define UDP_CAN_BRIDGE_DEV_ID 0

#define UDP_CAN_BRIDGE_MCUA_DEV_PORT 8000
#define UDP_CAN_BRIDGE_REMOTE_DEV_PORT 8001

#define UDP_CAN_BRIDGE_RX_BUFFER_SIZE 1024

static ip_addr_t g_udp_remote_ip = {0};

static uint8_t g_udp_dev0_rx_buffer[UDP_CAN_BRIDGE_RX_BUFFER_SIZE] = {0};

static ReturnCode LwipGetGroupIpConfig(ip_addr_t* ip) {
  if (ip == NULL) {
    return ERROR_INVALID_PARAM;
  }
  uint8_t remote_ip[4] = {0};
  ReturnCode ret = GetConfigValue(1, kItemRemoteIp, &remote_ip, sizeof(remote_ip));
  if (ret != ERROR_OK) {
    PONY_LOG(DEBUG_ERR, "Failed to read remote ip.");
    return ret;
  }
  IP4_ADDR(ip, remote_ip[0], remote_ip[1], remote_ip[2], remote_ip[3]);
  return ERROR_OK;
}

static void CanBridegUdpTxTask(void) {
  can_msg_t message = {0};
  if (CanMsgRecv(kCan1, &message, 1)) {
    int32_t res = LwipUdpServerWrite(UDP_CAN_BRIDGE_DEV_ID, message.data, message.len);
    if(res != message.len) {
      PONY_LOG(DEBUG_ERR, "send CAN message to remote failed!");
    }
  }
}

static void CanBridegUdpRxTask(void) {
  int32_t recv_count = 
    LwipUdpServerRead(UDP_CAN_BRIDGE_DEV_ID, 
                      g_udp_dev0_rx_buffer,
                      UDP_CAN_BRIDGE_RX_BUFFER_SIZE);
  if(recv_count > 0) {
    can_msg_t message = { 
      .ide = kCanIdStd,
      .id = 0x123,
      .rtr = kCanRtrData,
      .fdf = kCanFdTypeClassic,
      .len = 8,
    };
    memcpy(message.data, g_udp_dev0_rx_buffer, message.len);
    PONY_LOG(DEBUG_INFO, "recive UDP message from remote and send to kCAN1.");
    int count = CanMsgSend(kCan1, &message, 1);
    if (count != 1) {
      PONY_LOG(DEBUG_ERR, "send CAN message to kCAN1 failed!");
    } 
  }
}

ReturnCode InitCanBridgeDemo(void) {
  PONY_ASSERT(CanOpen(kCan1) == ERROR_OK);
  ReturnCode ret = InitLwipUdpServer(UDP_CAN_BRIDGE_DEV_ID,
                                     UDP_CAN_BRIDGE_MCUA_DEV_PORT,
                                     g_udp_dev0_rx_buffer,
                                     UDP_CAN_BRIDGE_RX_BUFFER_SIZE);
  if (ret != ERROR_OK) {
    PONY_LOG(DEBUG_ERR, "Failed to init lwip udp server.");
    return ret;
  }
  ret = LwipUdpServerStart(UDP_CAN_BRIDGE_DEV_ID);
  if (ret != ERROR_OK) {
    PONY_LOG(DEBUG_ERR, "Failed to start lwip udp server.");
    return ret;
  }
  ret = LwipGetGroupIpConfig(&g_udp_remote_ip);
  if (ret != ERROR_OK) {
    PONY_LOG(DEBUG_ERR, "Failed to get udp remote ip.");
    return ret;
  }
  ret = LwipUdpServerConfigDst(UDP_CAN_BRIDGE_DEV_ID,
                               &g_udp_remote_ip, 
                               UDP_CAN_BRIDGE_REMOTE_DEV_PORT);
  if (ret != ERROR_OK) {
    PONY_LOG(DEBUG_ERR, "Failed to config udp destination.");
    return ret;
  }
  char ip_str[16] = {0};
  ip4addr_ntoa_r(&g_udp_remote_ip, ip_str, sizeof(ip_str));
  PONY_LOG(DEBUG_INFO, "Remote IP: %s.", ip_str);
  return ERROR_OK;
}

void CanTransferTask(void) {
  CanBridegUdpTxTask();
  CanBridegUdpRxTask();
}
