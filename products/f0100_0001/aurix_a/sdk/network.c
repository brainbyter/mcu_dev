// Copyright @2022 Pony AI Inc. All rights reserved.

#include "products/f0100_0001/aurix_a/sdk/network.h"

#include "common/mcu/system/init.h"
#include "common/mcu/utils/debug.h"
#include "common/mcu/utils/status.h"
#include "common/utilities/hwprotocol.h"
#include "platform/device/bsp/bsp_i2c.h"
#include "platform/device/driver/lwip/lwip_utils/tcp_server.h"
#include "platform/device/driver/lwip/netif/ethernetif.h"
#include "platform/product/common/pony_system.h"
#include "products/f0100_0001/aurix_a/app/config.h"
#include "products/f0100_0001/aurix_a/app/ethernet.h"
#include "products/f0100_0001/aurix_a/app/ethernet_manager.h"

#define TCP_UPDATE_SERVER_DEV_RX_BUF_LEN 2048
#define TCP_UPDATE_SERVER_DEV_TX_BUF_LEN 2048
#define TCP_UPDATE_SERVER_DEV_PORT 32888
#define TCP_UPDATE_SERVER_DEV_ID 0

static uint8_t g_tcp_update_server_rx_buffer[TCP_UPDATE_SERVER_DEV_RX_BUF_LEN] = {0};
static uint8_t g_tcp_update_server_tx_buffer[TCP_UPDATE_SERVER_DEV_TX_BUF_LEN] = {0};

#define TCP_CLI_SERVER_DEV_RX_BUF_LEN 256
#define TCP_CLI_SERVER_DEV_TX_BUF_LEN 512
#define TCP_CLI_SERVER_DEV_PORT 32889
#define TCP_CLI_SERVER_DEV_ID 1

static uint8_t g_tcp_cli_server_rx_buffer[TCP_CLI_SERVER_DEV_RX_BUF_LEN] = {0};
static uint8_t g_tcp_cli_server_tx_buffer[TCP_CLI_SERVER_DEV_TX_BUF_LEN] = {0};

ReturnCode InitNetwork(void) {
  RETURN_IF_ERROR(InitEthernetManager());
  InitSwitchsAndPhys();
  return InitNetworkProtocolStack();
}

ReturnCode InitNetworkProtocolStack(void) {
  uint8_t mac_address[6] = {ETHERNET_CONF_ETHADDR0,
                            ETHERNET_CONF_ETHADDR1,
                            ETHERNET_CONF_ETHADDR2,
                            ETHERNET_CONF_ETHADDR3,
                            ETHERNET_CONF_ETHADDR4,
                            ETHERNET_CONF_ETHADDR5};
  uint8_t config_ip[4] = {
      ETHERNET_CONF_IPADDR0, ETHERNET_CONF_IPADDR1, ETHERNET_CONF_IPADDR2, ETHERNET_CONF_IPADDR3};
  uint8_t config_gateway[4] = {ETHERNET_CONF_GATEWAY_ADDR0,
                               ETHERNET_CONF_GATEWAY_ADDR1,
                               ETHERNET_CONF_GATEWAY_ADDR2,
                               ETHERNET_CONF_GATEWAY_ADDR3};
  uint8_t config_mask[4] = {ETHERNET_CONF_NET_MASK0,
                            ETHERNET_CONF_NET_MASK1,
                            ETHERNET_CONF_NET_MASK2,
                            ETHERNET_CONF_NET_MASK3};
  ReturnCode result = ERROR_OK, ret = ERROR_OK;
  ret = GetConfigValue(1, kItemIp, &config_ip, sizeof(config_ip));
  if (ret != ERROR_OK) {
    result = ret;
  }
  ret = GetConfigValue(1, kItemGateway, &config_gateway, sizeof(config_gateway));
  if (ret != ERROR_OK) {
    result = ret;
  }
  ret = GetConfigValue(1, kItemNetworkMask, &config_mask, sizeof(config_mask));
  if (ret != ERROR_OK) {
    result = ret;
  }
  if (result == ERROR_OK) {
    PONY_ASSERT(SetEthernetifIpGatewayNetworkMask(config_ip, config_gateway, config_mask) ==
                ERROR_OK);
  } else {
    PONY_LOG(
        DEBUG_ERR, "Failed to read network configurations from config manager. result=%d.", result);
  }
  ret = GetConfigValue(0, kItemEepromMac, &mac_address, sizeof(mac_address));
  if (ret == ERROR_OK) {
    LOG_IF_ERROR(SetEthernetifMac(mac_address));
  }
  if (LwipInitEthernetIf() != ERROR_OK) {
    PONY_LOG(DEBUG_ERR, "Failed to init lwIP.");
    return ERROR_IO_ERROR;
  }
  LwipSetLinkUpEthernetIf();

  ip_addr_t ip, mask, gateway;
  LwipGetLocalIpConfig(&ip, &mask, &gateway);
  char ip_str[16] = {0};
  char mask_str[16] = {0};
  char gateway_str[16] = {0};
  ip4addr_ntoa_r(&ip, ip_str, sizeof(ip_str));
  ip4addr_ntoa_r(&mask, mask_str, sizeof(mask_str));
  ip4addr_ntoa_r(&gateway, gateway_str, sizeof(gateway_str));

  PONY_LOG(DEBUG_INFO, "IP: %s, Mask: %s, Gateway: %s.", ip_str, mask_str, gateway_str);

  // This server is initialized as a router interface.
  if (InitLwipTcpServer(TCP_UPDATE_SERVER_DEV_ID,
                        TCP_UPDATE_SERVER_DEV_PORT,
                        g_tcp_update_server_rx_buffer,
                        TCP_UPDATE_SERVER_DEV_RX_BUF_LEN,
                        g_tcp_update_server_tx_buffer,
                        TCP_UPDATE_SERVER_DEV_TX_BUF_LEN) != ERROR_OK) {
    PONY_LOG(DEBUG_ERR, "Failed to init lwIP TCP server at port %d.", TCP_UPDATE_SERVER_DEV_PORT);
    return ERROR_IO_ERROR;
  }

  if (InitLwipTcpServer(TCP_CLI_SERVER_DEV_ID,
                        TCP_CLI_SERVER_DEV_PORT,
                        g_tcp_cli_server_rx_buffer,
                        TCP_CLI_SERVER_DEV_RX_BUF_LEN,
                        g_tcp_cli_server_tx_buffer,
                        TCP_CLI_SERVER_DEV_TX_BUF_LEN) != ERROR_OK) {
    PONY_LOG(DEBUG_ERR, "Failed to init lwIP TCP server at port %d.", TCP_CLI_SERVER_DEV_PORT);
    return ERROR_IO_ERROR;
  }
  LwipTcpServerStart(TCP_CLI_SERVER_DEV_ID);

  return ERROR_OK;
}
