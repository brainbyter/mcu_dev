// Copyright @2020 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_BOOTLOADER_BOOT_CONTROL_AB_H_
#define PLATFORM_DEVICE_DRIVER_BOOTLOADER_BOOT_CONTROL_AB_H_

#include "platform/device/driver/bootloader/boot_control_interface.h"

typedef enum ActiveAppStatus {
  kActiveAppNotBootable,
  kActiveAppWaitMark,
  kActiveAppMarked,
  kActiveAppWaitMarkFailed,
  kActiveAppInvalid,
} ActiveAppStatus;

// Get the BootControlAB singleton instance.
BootControlInterface* GetBootControlAB(void);

// Try to start the Application.
ReturnCode TryStartAppAB(void);

void SetCurrentSlotType(Slot slot);
ReturnCode GetStoredActiveBootSlotType(Slot* slot);

typedef ReturnCode(*ABLoaderSetActiveSlotExtFunc)(Slot target_slot);
// Define a set active slot type function to add some user defined function after set active slot.
ReturnCode ABLoaderRegisterSetActiveSlotTypeFunc(ABLoaderSetActiveSlotExtFunc func);

// Check if current slot type diff the active slot stored in active info, if so, set the active slot
// type to current slot type.
ReturnCode SyncActiveSlotBasedActiveSlot(void);

// NOTE: TryStartAppAB actually includes these functions. So should either use TryStartAppAB or
// these functions below. Please don't mix them together.
// Find the active app the loader can use to boot. With full check for the active slot.
Slot TryFindActiveAppToBoot(void);
// Get the status of the current active app.
ActiveAppStatus GetActiveAppStatus(void);
// After the check, now can boot the app directly.
ReturnCode TryBootApp(Slot slot);
// Use this API to rollback the app.
ReturnCode RollbackPreviousApp(Slot current_slot, Slot* rollbacked_slot);

// Get current slot type's previous slot type.
Slot GetPreviousSlotType(Slot current_slot);

// Set the active slot type to target slot type.
ReturnCode SetActiveBootSlotType(Slot target_slot);

#endif  // PLATFORM_DEVICE_DRIVER_BOOTLOADER_BOOT_CONTROL_AB_H_
