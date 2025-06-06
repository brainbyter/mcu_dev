// Copyright @2022 Pony AI Inc. All rights reserved.

/// @defgroup driver driver

/// @defgroup driver_bootchain bootchain
/// @ingroup driver
/// This is the implementation of bootchain driver. For bootchain, each device's slot firmware
/// information is stored in slot info, device's bootchain information is stored in active ino.

/// @file
/// @ingroup driver_bootchain
/// @brief The header file for bootchain driver.

#ifndef COMMON_DRIVER_BOOTCHAIN_H_
#define COMMON_DRIVER_BOOTCHAIN_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @ingroup driver_bootchain
/// @brief The bootchain slot type.
typedef uint32_t BootChainSlot;
/// @ingroup driver_bootchain
/// @brief The invalid bootchain slot type stored in bootchain module.
#define kInvalidBootChainSlot 0xFFFFFFFF

/// @ingroup driver_bootchain
/// @brief The flag value means the bootchain data is set as valid.
extern const uint8_t kBootChainFlagSet;
/// @ingroup driver_bootchain
/// @brief The flag value means the bootchain data is set as invalid.
extern const uint8_t kBootChainFlagClear;

/// @ingroup driver_bootchain
/// @brief The structure is defined for slot info. This structure is always stored in flash、eeprom
/// or other permanent storage. The user should provide APIs to read\write this structure in
/// BootChainSlotInfo.
typedef struct BootChainSlotInfoRaw {
  /// The update time for this firmware stored in the device's target slot.
  int64_t update_time;
  /// The update counter for the device's target slot.
  uint32_t update_counter;
  /// This means that the slot firmware is bootable. This flag is always set if the device's target
  /// slot firmware is updated successfully.
  uint8_t bootable;
  /// The flag points out that if the slot firmware has booted successfully. This means the device's
  /// target slot firmware has got a handshake with bootchain module.
  uint8_t boot_successful;
  /// The CRC for this structure.
  uint16_t crc;
} __attribute__((packed)) BootChainSlotInfoRaw;

// The user should define BOOTCHAIN_DEVICE_NUMBER before using this module. Menas the device
// number managed by bootchain module.
#ifndef BOOTCHAIN_DEVICE_NUMBER
#error "Please define BOOTCHAIN_DEVICE_NUMBER!"
#endif  // BOOTCHAIN_DEVICE_NUMBER

/// @ingroup driver_bootchain
/// @brief The structure is defined for active info. This structure is always stored in flash、
/// eeprom or other permanent storage. The user should provide APIs to read\write this
/// structure in BootChainActiveInfo.
typedef struct BootChainActiveInfoRaw {
  /// The slot type stored used to control the devices' slot type.  The user should define BOOTCHAIN_DEVICE_NUMBER
  /// before using this module.
  BootChainSlot slot_type[BOOTCHAIN_DEVICE_NUMBER];
  /// The update counter for this active info.
  uint32_t update_counter;
  /// The update time for this active info.
  int64_t update_time;
  /// The status for this active info. These values are defined in BootChainUpdateStatus.
  uint8_t update_status;
  /// The retry times left can try to boot with this active info.
  uint8_t boot_retry;
  /// The CRC for this structure.
  uint16_t crc;
} __attribute__((packed)) BootChainActiveInfoRaw;

/// @ingroup driver_bootchain
/// @brief The update status's value for the update_status in BootChainActiveInfoRaw.
enum BootChainUpdateStatus {
  /// The boot chain info is invalid.
  kBootChainInvalid = 0,
  /// The boot chain info is verified. For example, the active info's slot types are all boot
  /// successfully.
  kBootChainVerified = 1,
  /// The boot chain info is during updating.
  kBootChainUpdating = 2,
  /// The boot chain info is waiting verify.
  kBootChainWaitVerify = 3,
};

/// @ingroup driver_bootchain
/// @brief The slot types in this module are supported now.
enum BootChainSlotType {
  kBootChainSlotA = 0,
  kBootChainSlotB = 1,
  kBootChainSlotC = 2,
};

/// @ingroup driver_bootchain
/// @brief The bootchain slot info's full definition.
typedef struct BootChainSlotInfo {
  /// The API to read raw slot info data for the bootchain module.
  ReturnCode (*read_slot_info)(BootChainSlotInfoRaw* raw);
  /// The API to write the raw slot info data back for the bootchain module.
  ReturnCode (*write_slot_info)(BootChainSlotInfoRaw* raw);
  /// The callback for this slot info. For Orin, it's bootcfg pin's operation.
  ReturnCode (*bootchain_handler)(void);
  /// The raw data for this slot info, user doesn't need to care the value, it's managed by
  /// bootchain module.
  BootChainSlotInfoRaw info;
  /// If current slot info is valid, user doesn't need to care the value, it's managed by bootchain
  /// module.
  bool valid;
} BootChainSlotInfo;

/// @ingroup driver_bootchain
/// @brief The bootchain active info's full definition.
typedef struct BootChainActiveInfo {
  /// The API to read raw active info data for the bootchain module.
  ReturnCode (*read_active_info)(BootChainActiveInfoRaw* raw);
  /// The API to write the raw active info data back for the bootchain module.
  ReturnCode (*write_active_info)(BootChainActiveInfoRaw* raw);
  /// The raw data for this active info, user doesn't need to care the value, it's managed by
  /// bootchain module
  BootChainActiveInfoRaw info;
  /// If current active info is valid, user doesn't need to care the value, it's managed by
  /// bootchain module.
  bool valid;
} BootChainActiveInfo;

/// @ingroup driver_bootchain
/// @brief Map defined to show the relation between bootchain device's slot type and it's
/// BootChainSlotInfo.
typedef struct BootChainDeviceToSlotMapNode {
  /// The device index, always starts from 0. The devices' number is BOOTCHAIN_DEVICE_NUMBER.
  uint32_t device_index;
  /// The slot type for the device.
  BootChainSlot slot_type;
  /// The BootChainSlotInfo for this slot type.
  BootChainSlotInfo* slot_info;
} BootChainDeviceToSlotMapNode;

/// @ingroup driver_bootchain
/// @brief Map defined to show the relation between bootchain device index and hwprotocol device
/// id.
typedef struct BootChainDeviceIdToDeviceIndexMapNode {
  /// The hwprotocol device id for this device.
  uint16_t device_id;
  /// The device index, always starts from 0. The devices' number is BOOTCHAIN_DEVICE_NUMBER.
  uint32_t storage_device_index;
} BootChainDeviceIdToDeviceIndexMapNode;

/// @ingroup driver_bootchain
/// @brief Print all the active infos.
void DumpAllActiveInfo(void);
/// @ingroup driver_bootchain
/// @brief Print all the slot infos.
void DumpAllSlotInfo(void);

/// @ingroup driver_bootchain
/// @brief Check if the current boot chain active is waiting verify(kBootChainWaitVerify).
/// @return True if it is, otherwise false.
bool IsCurrentBootChainWaitVerify(void);
/// @ingroup driver_bootchain
/// @brief Check if the current boot chain active is verified(kBootChainVerified).
/// @return True if it is, otherwise false.
bool IsCurrentBootChainVerified(void);
/// @ingroup driver_bootchain
/// @brief Set a device's slot info in next active info bootable. This API is used after the
/// update of a device. To set the new firmware bootable.
/// This API reponses to cmd (kSetBootChain, kBootChainSetActiveSlot).
/// @param device_index [uint32_t] The device index defined in bootchain module.
/// @param slot_type [BootChainSlot] The slot type for the device to fresh.
/// @param timestamp [int64_t] The timestamp to set it as bootable.
/// @return ERROR_OK if it is set successfully.
ReturnCode SetNextBootChainActiveInfoSlotTypeBootable(uint32_t device_index,
                                                      BootChainSlot slot_type,
                                                      int64_t timestamp);
/// @ingroup driver_bootchain
/// @brief Set the next active info wait verify. This API is used after all the devices are updated.
/// This API reponses to cmd (kSetBootChain, kBootChainUpdateDone).
/// @param timestamp [int64_t] The timestamp that the updating is done.
/// @return ERROR_OK if it is set successfully.
ReturnCode SetNextBootChainActiveInfoWaitVerify(int64_t timestamp);
/// @ingroup driver_bootchain
/// @brief Clear the next bootchain active info means clear the flag and set the status to updating.
///  This API is called at the beggining of a new update. This API reponses to the first cmd
/// (kSetBootChain, kBootChainStartUpdate).
/// @return ERROR_OK if it is set successfully.
ReturnCode ClearNextBootChainActiveInfo(void);
/// @ingroup driver_bootchain
/// @brief Set the next bootchain active info's slot info not bootable.
///  This API is called at the beggining of a new update. This API reponses to cmd
/// (kSetBootChain, kBootChainStartUpdate).
/// @param device_index [uint32_t] The device index defined in bootchain module.
/// @param slot_type [BootChainSlot] The slot type for the device to fresh.
/// @return ERROR_OK if it is unset successfully.
ReturnCode UnsetNextBootChainActiveInfoSlotBootable(uint32_t device_index,
                                                    BootChainSlot slot_type);
/// @ingroup driver_bootchain
/// @brief Set the current bootchain active info's slot info verified. This API is called when the
/// bootchain module gets a handshake from the device. This API reponses to cmd
/// (kSetBootChain, kBootChainHandshake).
/// @param device_index [uint32_t] The device index defined in bootchain module.
/// @return ERROR_OK if it is set successfully.
ReturnCode SetBootChainCurrentActiveInfoVerified(uint32_t device_index);
/// @ingroup driver_bootchain
/// @brief Get the device's slot type stored in current bootchain active info.
/// This API reponses to cmd (kSetBootChain, kBootChainGetDeviceSlotType).
/// @param device_index [uint32_t] The device index defined in bootchain module.
/// @return BootChainSlot is the device slot type.
BootChainSlot GetCurrentActiveInfoSlotType(uint32_t device_index);
/// @ingroup driver_bootchain
/// @brief Get the bootchain device index based on hwprotocol device id.
/// @param device_id [uint16_t] The hwprotocol device id.
/// @param device_index [uint32_t*] The device index defined in bootchain module.
/// @return ERROR_OK if it is get successfully.
ReturnCode GetBootChainDeviceIndexByDeviceId(uint16_t device_id, uint32_t* device_index);

/// @ingroup driver_bootchain
/// @brief Register the hwprotocol device ID and bootchain device index map for this module.
/// Without this map, the bootchain module doesn't know how to figure out the device based on
/// hwprotocol cmd.
/// @param map [BootChainDeviceIdToDeviceIndexMapNode*] The hwprotocol device ID to bootchain device
/// index map.
/// @param node_num [uint32_t] The map's number.
/// @return ERROR_OK if it is registered successfully.
ReturnCode BootChainRegisterIndexMap(BootChainDeviceIdToDeviceIndexMapNode* map, uint32_t node_num);
/// @ingroup driver_bootchain
/// @brief Initial and start a bootchain. The bootchain will try to find and fresh the bootchain
/// data and call the bootchain's callback for all the device slots.
/// @param active_info [BootChainActiveInfo*] These active infos definitions.
/// @param active_info_num [uint32_t] The number of active infos.
/// @param slot_info [BootChainSlotInfo*] These slot infos definitions.
/// @param slot_info_num [uint32_t] The number of slot infos.
/// @param map_node [BootChainDeviceToSlotMapNode*] The map to define the slot info to device.
/// @param map_node_num [uint32_t] The map's number.
/// @param default_slots [BootChainSlot*] The default slot info list used for the bootchain module.
/// @param device_num [uint32_t] The device number for this bootchain module.
/// @param retry_boot [uint8_t] The boot retry times for this bootchain module.
/// @return ERROR_OK if it is started successfully.
ReturnCode BootChainStart(BootChainActiveInfo* active_info,
                          uint32_t active_info_num,
                          BootChainSlotInfo* slot_info,
                          uint32_t slot_info_num,
                          BootChainDeviceToSlotMapNode* map_node,
                          uint32_t map_node_num,
                          BootChainSlot* default_slots,
                          uint32_t device_num,
                          uint8_t retry_boot);
/// @ingroup driver_bootchain
/// @brief Get all the active info data (format is BootChainActiveInfoRaw).
/// @param buffer [uint8_t*] The buffer to store the result.
/// @param max_size [uint32_t] The max size of the buffer.
/// @return is data's length.
uint16_t GetAllActiveInfo(uint8_t* buffer, uint32_t max_size);
/// @ingroup driver_bootchain
/// @brief Get the current active info data (format is BootChainActiveInfoRaw).
/// @param buffer [uint8_t*] The buffer to store the result.
/// @param max_size [uint32_t] The max size of the buffer.
/// @return is data's length.
uint16_t GetCurrentActiveInfo(uint8_t* buffer, uint32_t max_size);
/// @ingroup driver_bootchain
/// @brief Get all the slot info data (format is BootChainSlotInfoRaw).
/// @param buffer [uint8_t*] The buffer to store the result.
/// @param max_size [uint32_t] The max size of the buffer.
/// @return is data's length.
uint16_t GetAllSlotInfo(uint8_t* buffer, uint32_t max_size);
/// @ingroup driver_bootchain
/// @brief Calculate the CRC16 for some data.
/// @param buffer [uint8_t*] The data to Calculate the result.
/// @param max_size [uint32_t] The size of the data.
/// @return is CRC16 for the data.
uint16_t CalBootChainCrc(uint8_t* buffer, uint32_t buffer_len);
/// @ingroup driver_bootchain
/// @brief Set current active info's device to a target slot type.
/// @param device_index [uint32_t] The device index defined in bootchain module.
/// @param slot_type [BootChainSlot] The new slot type for the device to use.
/// @return ERROR_OK if it is set successfully.
ReturnCode SetCurrentActiveInfoSlotType(uint32_t device_index, BootChainSlot slot_type);
#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // COMMON_DRIVER_BOOTCHAIN_H_
