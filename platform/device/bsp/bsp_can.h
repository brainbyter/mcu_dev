// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef BSP_BSP_CAN_H_
#define BSP_BSP_CAN_H_

#include <Platform_Types.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "common/mcu/utils/status.h"
#include "platform/component/list.h"
#include "platform/component/ringbuffer.h"
#include "platform/product/common/pony_bsp.h"

#define CAN_SUPPORT_CANFD
typedef struct CanFiltrItem {
  uint32_t id : 29;  // id for this filter
  uint32_t ide : 1;  // extended frame flag
  uint32_t fdf : 1;  // can_fd frame flag
  uint32_t rtr : 1;  // remote frame flag
  uint32_t mask;     // mask for this filter item
} can_filter_item;

enum CanFilterTableActiveStatus {
  kCanFilterTableDeActivate = 0,
  kCanFilterTableActivate = 1,
};

typedef struct CanFilterConfig {
  uint16_t count;   // number of items
  uint16_t active;  // this config table is active(value is 1)
  can_filter_item* items;
} can_filter_config_t;

#define CAN_FILTER_ITEM_INIT(id, ide, fdf, rtr, mask) \
  { (id), (ide), (fdf), (rtr), (mask), }

#define CAN_FILTER_STD_INIT(id) \
  CAN_FILTER_ITEM_INIT(id, kCanIdStd, kCanFdTypeClassic, kCanRtrData, 0xFFFFFFFF)
#define CAN_FILTER_STD_FD_INIT(id) \
  CAN_FILTER_ITEM_INIT(id, kCanIdStd, kCanFdTypeCanFd, kCanRtrData, 0xFFFFFFFF)
#define CAN_FILTER_EXT_INIT(id) \
  CAN_FILTER_ITEM_INIT(id, kCanIdExt, kCanFdTypeClassic, kCanRtrData, 0xFFFFFFFF)
#define CAN_FILTER_STD_PASSTHROUGH \
  CAN_FILTER_ITEM_INIT(0, kCanIdStd, kCanFdTypeClassic, kCanRtrData, 0x0)
#define CAN_FILTER_EXT_PASSTHROUGH \
  CAN_FILTER_ITEM_INIT(0, kCanIdExt, kCanFdTypeClassic, kCanRtrData, 0x0)

#define CAN_FILTER_ID_MASK_OFFSET 3
#define CAN_FILTER_IDE_MASK_OFFSET 2
#define CAN_FILTER_FDF_MASK_OFFSET 1
#define CAN_FILTER_RTR_MASK_OFFSET 0

// Classic CAN and CANFD have different max data length
// if CANFD is supported, all can_msg_t is expanded to hold CANFD messages
#define CAN_MAX_DLEN 8
#define CANFD_MAX_DLEN 64

#ifdef CAN_SUPPORT_CANFD
#define CAN_MSG_DLEN CANFD_MAX_DLEN
#else
#define CAN_MSG_DLEN CAN_MAX_DLEN
#endif  // CAN_SUPPORT_CANFD

#pragma align 1
typedef struct CanMsg {
  uint32_t id : 29;  // id for msg
  uint32_t ide : 1;  // extended frame flag
  uint32_t fdf : 1;  // can fd flag
  uint32_t rtr : 1;  // remote frame flag
  uint8_t data[CANFD_MAX_DLEN];
  uint8_t len;  // data length
#ifdef CAN_SUPPORT_TIMESTAMP
  // Timestamp field of the CAN message.
  // NOTE:
  // The timestamp formats and ratios are platform-specific.
  // - SAMV71: timestamp_tc is used, the tick and counter are the values from TC0 Channel 0.
  union {
    uint64_t timestamp_us;
    struct {
      uint32_t tick_value;
      uint32_t counter_value;
    } timestamp_tc;
  };
#endif
  boolean msgNonReadedFromFifo;	// flag read or wait (0 = readed, 1 = nonReaded)
} can_msg_t;
#pragma align restore

typedef enum CanState {
  kCanStateOn,
  kCanStateOFF,
  kCanStateInvalid,
} can_state_t;

typedef enum CanFdType {
  kCanFdTypeClassic = 0,
  kCanFdTypeCanFd = 1,
} can_fd_type_t;

typedef enum CanIdType {
  kCanIdStd = 0,
  kCanIdExt = 1,
} can_id_type_t;

typedef enum CanRtrType {
  kCanRtrData = 0,
  kCanRtrRemote = 1,
} can_rtr_type_t;

typedef enum CanBaudrate {
  kCANBaudrate125K = 125000,
  kCANBaudrate250K = 250000,
  kCANBaudrate500K = 500000,  // most common in automotive
  kCANBaudrate1M = 1000000,
  kCANBaudrate2M = 2000000,
  kCANBaudrate4M = 4000000,
  kCANBaudrate5M = 5000000,
  kCANBaudrate8M = 8000000,
  kCANBaudrate10M = 10000000,
} can_baudrate_t;

typedef enum CanIoctlCmd {
  kCanIoctlCmdSetFilter,
  kCanIoctlCmdSetBaudrate,
  kCanIoctlCmdEnableLoopback,
  // This callback is called when data is received.
  // The callback is called in interrupt context.
  kCanIoctlCmdSetDataReadyCallback,
  // Query the hardware TX FIFO/Queue free level.
  kCanIoctlCmdGetTxFreeLevel,
  kCanIoctlCmdSetBusoffHandler,
  // Recover from bus off state
  kCanIoctlCmdRecoverBusOff,
  kCanIoctlCmdGetTxBufferFull,
  kCanIoctlCmdInvalid,
} can_ioctl_cmd_t;

typedef struct CanDataReadyCallback {
  void (*callback)(void*);
  void* param;
} can_data_ready_callback_t;

typedef struct CanBusoffCallback {
  void (*callback)(void*);
  void* param;
} can_busoff_callback_t;

typedef enum CanIdeMsgLength {
  kCanStdMsgLength = 8,
  kCanExtMsgLength = 64,
} can_ide_msg_length_t;

typedef struct CanMsgNode {
  list_node_t list;
  can_msg_t data;
} can_msg_node_t;

typedef struct CanRxFifo {
  can_msg_node_t* buffer;
  uint16_t buffer_size;
  uint16_t free_numbers;
  list_node_t free_list;
  list_node_t use_list;
} can_rx_fifo_t;

typedef struct CanBaudrateConfig {
  uint8_t can_fd;
  // Base on kCANBaudrate125K.
  uint8_t std_baudrate_factor;
  uint8_t fd_baudrate_factor;
} __attribute__((packed)) CanBaudrateConfig;

typedef enum CanErrorType {
  kCanErrorTypeBusOff = 0,
  kCanErrorTypePassive,
  kCanErrorTypeCrcError,
  kCanErrorTypeBitError,
  kCanErrorTypeAckError,
  kCanErrorTypeFormatError,
  kCanErrorTypeStuffError,
  kCanErrorTypeCount,
} CanErrorType;
// error_code in CanStatus is uint32_t and uses the error type as bit offset.
_Static_assert(kCanErrorTypeCount < 32, "CanErrorType can't excceed 32.");

typedef struct CanStatus {
  uint32_t recv_change;       // if this can is receiving some packages
  uint32_t recv_pkg;          // can receive package's count
  uint32_t drop_recv_pkg;     // the dropped receive pacakge's count, perhaps the buffer is full
  uint32_t send_change;       // if the can is sending some packages
  uint32_t send_pkg;          // can send package's count
  uint32_t drop_send_pkg;     // the dropped send pacakge's count, perhaps the can is in error status
  uint32_t error_code;        // bitwise OR of (1UL << CanErrorType).
  uint32_t tx_error_counter;  // transmit error counter, value between 0 and 255
  uint32_t rx_error_counter;  // receive error counter, value between 0 and 127
} can_status_t;

typedef struct PonyCanDevice {
  uint16_t open_flag;                 // 1 for open, 0 for closed
  uint16_t number;                    // number for this can, [0 ~ MAX_CAN_NUMBER-1],
  can_baudrate_t baud_rate;           // bandrate for this can
  can_rx_fifo_t can_rx;               // buffer for receive package
  can_status_t status;                // state the status of the send and receive packages
  can_filter_config_t filter_config;  // filter for this can
  ReturnCode (*open)(struct PonyCanDevice* can);
  ReturnCode (*close)(struct PonyCanDevice* can);
  ReturnCode (*ioctl)(struct PonyCanDevice* can, can_ioctl_cmd_t cmd, void* arg);
  ReturnCode (*sendmsg)(struct PonyCanDevice* can, can_msg_t* message);
  ReturnCode (*recvmsg)(struct PonyCanDevice* can, can_msg_t* rx_message);
  ReturnCode (*get_error_code)(struct PonyCanDevice* can, can_status_t* status);
  void* param;
  can_data_ready_callback_t data_ready_callback;
  can_busoff_callback_t busoff_callback;
} pony_can_t;

#ifdef SUPPORT_VIRTUAL_CAN_UART
typedef struct PonyVirtualCanUart {
  uint8_t number;      // number for this can, [0 ~ MAX_CAN_NUMBER-1],
  uint8_t can_number;  // can device number
  uint8_t ide;         // extended frame flag
  uint8_t fdf;         // can fd flag
  uint32_t rx_can_id;  // can id use as rx
  uint32_t tx_can_id;  // can id use as tx
  uint8_t* rxbuf;
  uint32_t rxbufsize;
  uint8_t* txbuf;
  uint32_t txbufsize;
  struct RingBuffer rxbuffer;
  struct RingBuffer txbuffer;
} pony_virtual_can_uart_t;

ReturnCode RegisterVirtualCanUart(pony_virtual_can_uart_t* virtual_can_uart);
ReturnCode UnregisterVirtualCanUart(uint8_t virtual_can_uart_num);
uint32_t ReadVirtualCanUart(uint8_t virtual_can_uart_num, uint8_t* buff, uint32_t max_buff_size);
uint32_t WriteVirtualCanUart(uint8_t virtual_can_uart_num, const uint8_t* buff, uint32_t buff_size);
#endif

ReturnCode CanOpen(uint16_t can_id);
ReturnCode CanClose(uint16_t can_id);
uint32_t CanMsgRecv(uint16_t can_id, can_msg_t* msg, uint32_t msg_buf_count);
uint32_t CanMsgSend(uint16_t can_id, can_msg_t* msg, uint32_t msg_count);
ReturnCode CanIoctl(uint16_t can_id, can_ioctl_cmd_t cmd, void* arg);
ReturnCode CanGetStatus(uint16_t can_id, can_status_t* status);
const char* ErrorTypeToString(CanErrorType error_type);

ReturnCode RegisterCan(pony_can_t* can);
ReturnCode HwCanRxIsr(pony_can_t* can);

#endif  // BSP_BSP_UART_H_
