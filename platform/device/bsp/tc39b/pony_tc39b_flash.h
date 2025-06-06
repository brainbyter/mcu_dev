// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_TC39B_PONY_TC39B_FLASH_H_
#define PLATFORM_TC39B_PONY_TC39B_FLASH_H_

// IMPORTANT NOTE: Now this flash driver should use from the start address of one section.
// For DFlash, it's 0x1000; for PFlash it's 0x4000. We should erase before write, and can only
// write a bit once after one erasing operation.

#endif  // PLATFORM_TC39B_PONY_TC39B_FLASH_H_
