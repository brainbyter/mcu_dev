// Copyright @2020 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_BSP_MAC_H_
#define PLATFORM_DEVICE_BSP_MAC_H_

#include <stdbool.h>
#include <stdint.h>

#include "common/mcu/utils/status.h"

typedef enum EthIoctlCmd {
  kEthIoctlCmdSetMac,
  // Query whether WriteV/ReadV is supported by the driver.
  // Useful to determine whether to use the Scatter-Gather IO interfaces.
  kEthIoctlCmdQueryWriteVSupport,
  kEthIoctlCmdQueryReadVSupport,
  kEthIoctlCmdOpenPps,  // Open PPS with PonyMacPpsConfig
  kEthIoctlCmdTriggerSinglePps,  // Trigger one single PPS with PonyMacPpsTargetConfig
} EthIoctlCmd;

typedef enum PonyMacPpsMode {
  kPonyMacPpsModeSingle = 0,
  kPonyMacPpsModePulseTrain = 1,
  kPonyMacPpsModeSingleOnlyPps = 2,
  kPonyMacPpsModeTrainOnlyPps = 3,
  kPonyMacPpsModeSingleOnlyInterrupt = 4,
  kPonyMacPpsModeTrainOnlyInterrupt = 5,
} PonyMacPpsMode;

typedef enum PonyMacPpsFreq {
  kPonyMacPpsFreq1Hz = 1,
  kPonyMacPpsFreq2Hz = 2,
  kPonyMacPpsFreq4Hz = 4,
  kPonyMacPpsFreq8Hz = 8,
  kPonyMacPpsFreq16Hz = 16,
} PonyMacPpsFreq;

typedef struct PonyMacPpsTargetConfig {
  uint32_t seconds;
  uint32_t nanoseconds;
} PonyMacPpsTargetConfig;

// Scatterred IO vector buffer structure.
typedef struct IoVector {
  void* iov_base;  // Pointer to data.
  int iov_len;     // Length of data.
} IoVector;

typedef struct PonyMacDevice {
  int dev_num;
  bool is_opened;
  ReturnCode (*open)(struct PonyMacDevice* dev);
  ReturnCode (*close)(struct PonyMacDevice* dev);
  // The read and write interfaces must perform blocking IOs.
  int32_t (*write)(struct PonyMacDevice* dev, const uint8_t* buffer, uint32_t size);
  int32_t (*read)(struct PonyMacDevice* dev, uint8_t* buffer, uint32_t max_size);
  int32_t (*write_vec)(struct PonyMacDevice* dev, const IoVector* iov, int iovcnt);
  int32_t (*read_vec)(struct PonyMacDevice* dev, const IoVector* iov, int iovcnt);
  ReturnCode (*ioctl)(struct PonyMacDevice* dev, EthIoctlCmd cmd, void* arg);
} PonyMacDevice;

typedef struct PonyMacPpsConfig {
  PonyMacPpsMode mode;
  PonyMacPpsFreq freq;
  uint32_t interval;
  uint32_t width;
  void (*pps_handler)(uint32_t sec_timestamp, uint32_t nanosec_timestamp, void* arg);
  PonyMacPpsTargetConfig target_timestamp;
  void* arg;
} PonyMacPpsConfig;

// Public user API
ReturnCode MacOpen(int dev_num);
ReturnCode MacClose(int dev_num);
int32_t MacWrite(int dev_num, const uint8_t* buffer, uint32_t size);
int32_t MacRead(int dev_num, uint8_t* buffer, uint32_t max_size);
ReturnCode MacIoctl(int dev_num, EthIoctlCmd cmd, void* arg);

// Scatter-Gather Read and Writer interfaces.
// The MacReadV and MacWriteV read or write data into multiple buffers.
int32_t MacReadV(int dev_num, const struct IoVector* iov, int iovcnt);
int32_t MacWriteV(int dev_num, const struct IoVector* iov, int iovcnt);

// Copy from IoVector to data buffer.
// Return error if the IoVector contains data longer than the output buffer.
int32_t IoVectorCopyToBuffer(const struct IoVector* iov, int iovcnt, void* data, int max_len);

// Internal BSP API
ReturnCode RegisterMacDevice(struct PonyMacDevice* dev);

#endif  // PLATFORM_DEVICE_BSP_MAC_H_
