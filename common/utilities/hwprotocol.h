// Copyright @2019 Pony AI Inc. All rights reserved.

/// @defgroup protocol protocol

/// @defgroup hwprotocol hwprotocol
/// @ingroup protocol
/// This is the implementation of hwprotocol. Hwprotocol is a Pony.AI designed protocol to
/// communicate between devices.

/// @file
/// @ingroup hwprotocol
/// @brief The header file for hwprotocol.

#ifndef COMMON_UTILITIES_HWPROTOCOL_H_
#define COMMON_UTILITIES_HWPROTOCOL_H_

#include <stdbool.h>

#include "common/mcu/utils/status.h"
#include "platform/protocol/hwprotocol_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @ingroup hwprotocol
/// @brief The max length of payload.
#define PROTOCOL_MAX_LEN 512
/// @ingroup hwprotocol
/// @brief The extra length of hwprotocol, including hwprotocol header and crc.
#define PROTOCOL_EXTRA_LEN 17
/// @ingroup hwprotocol
/// @brief The max length of a hwprotocol packet.
#define PROTOCOL_MAX_PACKET_LEN (PROTOCOL_MAX_LEN + PROTOCOL_EXTRA_LEN)
/// @ingroup hwprotocol
/// @brief The suggestion max buffer size for protocol.
#define PROTOCOL_MAX_BUFFER_LEN 1024

/// @ingroup hwprotocol
/// @brief The hwprotocol packet struct.
typedef struct ProtocolPacket {
  /// The hwprotocol cmd's sender device ID.
  uint16_t sender;
  /// The hwprotocol cmd's receiver device ID.
  uint16_t receiver;
  /// The sequence of the cmd.
  uint16_t sequence;
  /// The command ID of the cmd. In Pony, it's combinded by a cmd set(uint8_t) and cmd id(uint8_t).
  uint16_t command;
  /// The type of the cmd, including post, requeset, response.
  uint8_t type;
  /// The length of the data.
  uint16_t data_length;
  /// The payload of the cmd.
  uint8_t* data;
} protocol_packet_t;

/// @ingroup hwprotocol
/// @brief The hwprotocol cmd handlers's defined node. The HandleCmd will handle the cmd by
/// calling the handlers.
typedef struct ProtocolCmdNode {
  /// The command ID of this node.
  uint16_t cmd;
  /// The security level of this node.
  uint8_t security_level;
  /// If the cmd's type is post cmd, then will call this handler.
  ReturnCode (*PostHandler)(const protocol_packet_t* temp_packet);
  /// If the cmd's type is requeset cmd, then will call this handler.
  ReturnCode (*ReqHandler)(const protocol_packet_t* temp_packet);
  /// If the cmd's type is response cmd, then will call this handler.
  ReturnCode (*ResponseHandler)(const protocol_packet_t* temp_packet);
  struct ProtocolCmdNode* next;
} protocol_cmd_node_t;

/// @ingroup hwprotocol
/// @brief The hwprotocol cmd type.
enum PacketType {
  /// Post type means the cmd does not need to response.
  kTypePost = 0x00,
  /// Request type means the sender will wait the response.
  kTypeRequest = 0x01,
  /// Response will always response to a request cmd.
  kTypeResponse = 0x02,
  /// Invalid type.
  kTypeInvalid,
};

/// @ingroup hwprotocol
/// @brief The pony used command structure, a uint16_t command is a combined of a command set and
/// command id.
#define PONY_CMD(cmd_set, cmd_id) (uint16_t)((uint16_t)cmd_set << 8 | cmd_id)

/// @ingroup hwprotocol
/// @brief The handler function defined for UnpackPacketNoCopy to unpack a cmd without copying the
/// payload
typedef ReturnCode (*packet_handler_callback_t)(protocol_packet_t* packet, void* user_data);

/// @ingroup hwprotocol
/// @brief Initialize hwprotocol stack. Only after the initialization, the user can use other
/// hwprotocol APIs.
/// @param device_id [uint16_t] The device ID of this hwprotocol node.
/// @param device_cmd_table [protocol_cmd_node_t*] The cmd table added by user, the HandleCmd will
/// handle the cmd by calling it's callback. Please make sure device_cmd_table is a static table.
/// this initial function will use AppendCmdTable to add the cmd table the hwprotocol node.
/// @param table_size [uint16_t] the size of the device cmd table.
/// @return ERROR_OK if successfully.
extern ReturnCode InitLocalProtocol(uint16_t device_id,
                                    protocol_cmd_node_t* device_cmd_table,
                                    uint16_t table_size);
/// @ingroup hwprotocol
/// @brief Add cmds' handler list to the hwprotocol handler list.
/// @param device_cmd_table [protocol_cmd_node_t*] The cmd table added by user, the HandleCmd will
/// handle the cmd by calling it's callback. Please make sure device_cmd_table is a static table.
/// this initial function will use AppendCmdTable to add the cmd table the hwprotocol node.
/// @param table_size [uint16_t] the size of the device cmd table.
/// @return ERROR_OK if successfully.
extern ReturnCode AppendCmdTable(protocol_cmd_node_t* device_cmd_table, uint16_t table_size);
/// @ingroup hwprotocol
/// @brief Check if the buffer starts with a whole hwprotocol packet. Should always check a buffer
/// before unpack a packet. It's ready to unpack a serialized hwprotocol packet only the result is
/// ERROR_OK. You can drop one byte in buffer "data" if the return code is ERROR_CHECKSUM or
/// ERROR_PROTOCOL, it means the data is not start with a hwprotocol packet. If the result is
/// ERROR_INSURFFICIENT means it's not ready to unpack the buffer, should wait for more data.
/// @param data [uint8_t*] The data to check.
/// @param data_length [uint16_t] the data length.
/// @return ERROR_OK if it is started with a hwprotocol cmd.
extern ReturnCode CheckPacket(const uint8_t* data, uint16_t data_length);
/// @ingroup hwprotocol
/// @brief Unpack(deserialize) the hwprotocol cmd from the buffer. Will copy the payload to the user
/// defined buffer. Please make sure CheckPacket the datain before UnpackPacket.
/// @param datain [uint8_t*] The data to unpack.
/// @param packet_get [protocol_packet_t*] the unpacked data will be stored in this pointer.
/// @return ERROR_OK if it is unpacked successfully.
extern ReturnCode UnpackPacket(const uint8_t* datain, protocol_packet_t* packet_get);
/// @ingroup hwprotocol
/// @brief Unpack(deserialize) the hwprotocol cmd from the buffer. Will not copy the payload during
/// the unpack. The user should use a callback to handle the cmd during the unpack.
/// @param datain [uint8_t*] The data to unpack.
/// @param packet_handler [packet_handler_callback_t] the callback after the unpack.
/// @param user_data [void*] The data used for the callback.
/// @return ERROR_OK if it is unpacked successfully.
extern ReturnCode UnpackPacketNoCopy(uint8_t* datain,
                                     packet_handler_callback_t packet_handler,
                                     void* user_data);
/// @ingroup hwprotocol
/// @brief Handle a hwprotocol cmd, will call the handler added by AppendCmdTable if the cmd is
/// for the local hwprotocol node.
/// @param temp_packet [protocol_packet_t*] the cmd to handle.
/// @return ERROR_OK if it is unpacked successfully.
extern ReturnCode HandleCmd(protocol_packet_t* temp_packet);
/// @ingroup hwprotocol
/// @brief Serialize a hwprotocol cmd.
/// @param send_packet [protocol_packet_t*] The cmd to serialize.
/// @param data_out [uint8_t*] The buffer to fill the serialized data.
/// @param max_data_len [uint16_t] The buffer's length.
/// @return The packet length to be packed.
extern uint32_t PackPacket(const protocol_packet_t* send_packet,
                           uint8_t* data_out,
                           uint16_t max_data_len);
/// @ingroup hwprotocol
/// @brief Get local hwprotocol node's device ID.
/// @return The device id of the local hwprotocol node.
extern uint16_t GetDeviceId(void);

/// @ingroup hwprotocol
/// @brief Get local device security level.
/// @return The device security level of the local device.
extern uint8_t GetDeviceSecurityLevel(void);

/// @ingroup hwprotocol
/// @brief Set local device security level.
/// @param level [uint8_t] The value of security level.
/// @return void.
extern void SetDeviceSecurityLevel(uint8_t level);

/// @ingroup hwprotocol
/// @brief Print Hwprotocol Hash Table.
/// @return void.
extern void PrintProtocolHashTable(void);

#ifdef __cplusplus
}  // extern "C"
#endif
#endif  //  COMMON_UTILITIES_HWPROTOCOL_H_
