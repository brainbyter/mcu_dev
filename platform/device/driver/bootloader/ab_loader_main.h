// Copyright @2020 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_BOOTLOADER_AB_LOADER_MAIN_H_
#define PLATFORM_DEVICE_DRIVER_BOOTLOADER_AB_LOADER_MAIN_H_

#include "common/mcu/utils/status.h"

#include "platform/device/driver/bootloader/boot_control_ab.h"
#include "platform/device/driver/bootloader/loader_main.h"

// Initialize the A/B loader.
// Note:
// In the application, the user should define the APP_START_ADDRESS and APP_INFO_ADDRESS correctly.
// i.e. for loaders, the APP_START_ADDRESS and APP_INFO_ADDRESS should point to Slot A.
//      for Slot A, the *_ADDRESS should point to Slot B.
//      for Slot B, the *_ADDRESS should point to Slot A.
ReturnCode ABLoaderInit(const pony_loader_ops_t* loader_ops, Slot current_slot_type);

// Try start one of the application (decided internally) in loader.
// Won't start any if none of the slots is bootable.
ReturnCode ABLoaderTryStartApp(void);

// Mark the current Slot as boot successful.
// User should call this somewhere in the application. This function can be called repeatly.
// There will be no Flash write operation if the slot is already marked successful.
ReturnCode ABLoaderMarkBootSuccessful(void);

#endif  // PLATFORM_DEVICE_DRIVER_BOOTLOADER_AB_LOADER_MAIN_H_
