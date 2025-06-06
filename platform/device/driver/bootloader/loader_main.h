// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_BOOTLOADER_LOADER_MAIN_H_
#define PLATFORM_DEVICE_DRIVER_BOOTLOADER_LOADER_MAIN_H_

#include <stdint.h>

#include "common/utilities/hwprotocol.h"
#include "platform/device/driver/bootloader/fw_checker.h"
#include "platform/product/common/pony_system.h"

#ifndef USING_LOADER_V2

struct AppInfo {
  uint32_t version;
  uint32_t address;
  uint32_t length;
  uint8_t checksum[FW_CHECKSUM_LENGTH];
  uint32_t crc32;
};

#else

#define BURN_INFO_HEAD_VERSION_LEN 64
#define BURN_INFO_HEAD_GITHASH_LEN 48
typedef struct AppInfoHead {
  uint32_t magic;
  uint32_t start_address;
  uint8_t bank_num;
  uint8_t reserve[3];
  uint8_t version[BURN_INFO_HEAD_VERSION_LEN];
  uint8_t githash[BURN_INFO_HEAD_GITHASH_LEN];
} AppInfoHead;

typedef struct AppInfoBank {
  uint8_t index;
  uint8_t reserve[3];
  uint32_t length;
  uint32_t start_address;
  uint8_t checksum[FW_CHECKSUM_LENGTH];
} AppInfoBank;

typedef struct AppInfo {
  AppInfoHead head;
  AppInfoBank bank[APP_BANK_NUM];
  uint32_t crc;
} AppInfo;

#endif  // USING_LOADER_V2

typedef struct PonyLoaderOps {
  uint32_t app_info_address;
  void (*start_upgrade_handler)(void);
  void (*during_upgrade_handler)(void);
  void (*stop_upgrade_handler)(void);
  uint32_t app_start_address;
} pony_loader_ops_t, *p_pony_loader_ops_t;

typedef struct LoaderFlashMapping {
  uint32_t start_address;
  uint32_t end_address;
  uint32_t map_offset;
} LoaderFlashMapping;

extern ReturnCode HandleThePing(const protocol_packet_t* temp_packet);
extern ReturnCode ProcessUpdateMode(const protocol_packet_t* temp_packet);
extern ReturnCode ProcessRestart(const protocol_packet_t* temp_packet);
extern ReturnCode ProcessStartUpgrade(const protocol_packet_t* temp_packet);
extern ReturnCode ProcessFirmwareData(const protocol_packet_t* temp_packet);
extern ReturnCode ProcessFwTransEnd(const protocol_packet_t* temp_packet);
extern ReturnCode ProcessBootApp(const protocol_packet_t* temp_packet);
extern ReturnCode HandleStayInloaderCmd(const protocol_packet_t* temp_packet);
extern void TryStartApp(void);
extern void TryStartAppWithInfo(struct AppInfo* app_info);
extern ReturnCode InitBootloader(p_pony_loader_ops_t temp_ops);
extern bool IsLoaderMainBurning(void);
extern bool ShouldStayInLoader(void);
// NOTE: Please make sure the flash_mapping exists during the OTA, otherwise, there will be a
// disaster crash. So, better define the flash_mapping as a global variable rather than a table
// in the stack.
extern ReturnCode RegisterFlashMapping(LoaderFlashMapping* flash_mapping, uint32_t map_num);
extern ReturnCode CheckAppWithInfo(struct AppInfo* app_info);

#endif  // PLATFORM_DEVICE_DRIVER_BOOTLOADER_LOADER_MAIN_H_
