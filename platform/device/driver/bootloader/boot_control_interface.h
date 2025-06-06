// Copyright @2020 Pony AI Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// This file is modified from Android Open Source Project. [Apache License V2.0]
// HAL boot_control_module:
// https://android.googlesource.com/platform/hardware/libhardware/+/master/include/hardware/boot_control.h
// update_engine BootControlInterface:
// https://android.googlesource.com/platform/system/update_engine/+/refs/heads/master/common/boot_control_interface.h

#ifndef PLATFORM_DEVICE_DRIVER_BOOTLOADER_BOOT_CONTROL_INTERFACE_H_
#define PLATFORM_DEVICE_DRIVER_BOOTLOADER_BOOT_CONTROL_INTERFACE_H_

#include <limits.h>
#include <stdbool.h>

#include "common/mcu/utils/status.h"

typedef uint32_t Slot;
#define kInvalidSlot 0xFFFFFFFF
#define kSlotLoader kInvalidSlot
#define kSlotA 0
#define kSlotB 1

typedef struct BootControlInterface {
  // (*Init)() perform any initialization tasks needed.
  // This is called only once.
  ReturnCode (*Init)(struct BootControlInterface* interface);

  // (*GetNumberSlots)() returns the number of available slots.
  // For instance, a system with a single set of partitions would return
  // 1, a system with A/B would return 2, A/B/C -> 3...
  uint32_t (*GetNumSlots)(struct BootControlInterface* interface);

  // (*GetCurrentSlot)() returns the value letting the system know
  // whether the current slot is A or B. The meaning of A and B is
  // left up to the implementer. It is assumed that if the current slot
  // is A, then the block devices underlying B can be accessed directly
  // without any risk of corruption.
  // Slots start at 0 and finish at getNumberSlots() - 1.
  // Return kInvalidSlot when error.
  Slot (*GetCurrentSlot)(struct BootControlInterface* interface);

  // (*IsSlotBootable)() returns if the slot passed in parameter is
  // bootable. Note that slots can be made unbootable by both the
  // bootloader and by the OS using MarkSlotUnbootable.
  // Returns true if the slot is bootable, false if it's not.
  bool (*IsSlotBootable)(struct BootControlInterface* interface, Slot slot);

  // (*MarkSlotUnbootable)() marks the slot passed in parameter as
  // an unbootable. This can be used while updating the contents of the slot's
  // partitions, so that the system will not attempt to boot a known bad set up.
  ReturnCode (*MarkSlotUnbootable)(struct BootControlInterface* interface, Slot slot);

  // (*SetActiveBootSlot)() marks the slot passed in parameter as
  // the active boot slot (see GetCurrentSlot for an explanation
  // of the "slot" parameter). This overrides any previous call to
  // SetActiveBootSlot.
  ReturnCode (*SetActiveBootSlot)(struct BootControlInterface* interface, Slot slot);

  // (*MarkBootSuccessful)() marks the current slot
  // as having booted successfully.
  ReturnCode (*MarkBootSuccessful)(struct BootControlInterface* interface);

  // (*IsSlotMarkedSuccessful)() returns if the slot passed in parameter has
  // been marked as successful using markBootSuccessful.
  // Returns true if the slot has been marked as successful, false if it's not the case.
  bool (*IsSlotMarkedSuccessful)(struct BootControlInterface* interface, Slot slot);
} BootControlInterface;

static inline const char* SlotName(Slot slot) {
  switch (slot) {
    case kInvalidSlot:
      return "INVALID";
    case 0:
      return "A";
    case 1:
      return "B";
    default:
      return "TOO_BIG";
  }
}

#endif  // PLATFORM_DEVICE_DRIVER_BOOTLOADER_BOOT_CONTROL_INTERFACE_H_
