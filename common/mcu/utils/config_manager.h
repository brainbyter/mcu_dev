// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef COMMON_MCU_UTILS_CONFIG_MANAGER_H_
#define COMMON_MCU_UTILS_CONFIG_MANAGER_H_

#include <stdbool.h>
#include <stdint.h>

#include "common/mcu/utils/status.h"

#ifndef MAX_CONFIG_DATA_SIZE
#define MAX_CONFIG_DATA_SIZE 128
#endif

#define MAX_CONFIG_SPACE_MANAGER_NUM 4

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ConfigItem {
  const char* name;
  uint16_t id;
  uint16_t offset;
  uint16_t length;
  void* value;
} ConfigItem;

typedef struct ConfigSpaceManager {
  uint8_t index;
  uint16_t config_tag;
  uint8_t* storage_space;
  uint32_t storage_space_length;
  uint16_t item_count;
  ConfigItem* item_list;
  ReturnCode (*write_config_space)(const uint8_t* data, int len);
  ReturnCode (*read_config_space)(uint8_t* data, int len);
} ConfigSpaceManager;

void PrintConfigManagerItem(ConfigSpaceManager* manager);
// Config manager can only add new item, can not delete item by default if use this API.
ReturnCode ConfigManagerInitNewAddedItems(ConfigSpaceManager* manager);
// This initial will only return error code if fix_item_num_mismatch is false when there is an item
// num mismatch find. Otherwise this initial will save the new added item with default value.
ReturnCode ConfigManagerInit(ConfigSpaceManager* manager, bool fix_item_num_mismatch);
ReturnCode SaveConfig(ConfigSpaceManager* manager);

ReturnCode GetConfigManagerStoredItemLength(ConfigSpaceManager* manager, uint16_t* item_num);
ReturnCode SetConfigManagerStoredItemNum(ConfigSpaceManager* manager);

ReturnCode GetValueWithItem(ConfigSpaceManager* manager, const ConfigItem* item,
                            void* value, int value_length);
ReturnCode SetValueWithItem(ConfigSpaceManager* manager, const ConfigItem* item,
                            const void* value, int value_length);

ReturnCode GetValueWithID(ConfigSpaceManager* manager, const uint16_t id,
                          void* value, int value_length);
ReturnCode SetValueWithID(ConfigSpaceManager* manager, const uint16_t id,
                          const void* value, int value_length);

const ConfigItem* SearchItemWithID(ConfigSpaceManager* manager, const uint16_t id);

ConfigSpaceManager* GetConfigManagerWithId(uint16_t id);
ReturnCode SetConfigManagerItemBaseOnId(uint8_t config_index, uint16_t item_index,
                                        const uint8_t* data, uint16_t data_len);
ReturnCode GetConfigManagerItemBaseOnId(uint8_t config_index, uint16_t item_index, uint8_t* buffer,
                                        uint16_t buffer_max_len, uint16_t* item_len);
#ifdef __cplusplus
}
#endif

#endif  // COMMON_MCU_UTILS_CONFIG_MANAGER_H_
