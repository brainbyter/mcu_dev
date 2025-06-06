// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_PROTOCOL_SDK_HWPROTOCOL_DEF_H_
#define PLATFORM_PROTOCOL_SDK_HWPROTOCOL_DEF_H_

enum DeviceId {
  kIdReserved = 0x0000,
  kIdOnboard = 0x0001,
  kIdUpdater = 0x0002,
  kIdAdcMcu = 0x0c00,
  kIdAdcOrinUpdater = 0x0c01,
  kIdAdcMcu2 = 0x0c0b,
  kIdAdcOrinASoc = 0x0c0c,
  kIdInvalid,
};

enum CommandSet {
  kSetGeneral = 0x00,
  kSetTimeSync = 0x0a,
  kSetAdcMcu = 0x0b,
  kSetStorageFlash = 0x11,
  kSetEthernet = 0xFB,
  kSetBootChain = 0x0FC,
  kSetPullStorageLog = 0xFE,
  kSetInvalid,
};

enum GeneralCommand {
  kGeneralPing = 0x00,
  kGeneralVersion = 0x01,
  kGeneralRestart = 0x02,
  kGeneralUpdateMode = 0x03,
  kGeneralStartUpdate = 0x04,
  kGeneralTransport = 0x05,
  kGeneralTransportComplete = 0x06,
  kGeneralStartApp = 0x07,
  kGeneralFirmwareRead = 0x08,
  kGeneralFirmwareData = 0x09,
  kGeneralFirmwareReadend = 0x0A,
  kGeneralLockBootloader = 0x0B,
  kGeneralFpgaFlag = 0x0C,
  kGeneralSyncIpcTime = 0x0D,
  kGeneralSelectAppVersion = 0x0E,
  kGeneralGetSlotType = 0x0F,
  kGeneralPowerOff = 0x10,
  kGeneralPoffNoticeSubscribe = 0x11,
  kGeneralRebootSamba = 0x12,
  kGeneralOpenDebugUart = 0x13,
  kGeneralSetConfig = 0x15,
  kGeneralGetConfig = 0x16,
  kGeneralSaveConfig = 0x17,
  kGeneralPowerOn = 0x18,
  kGeneralStayInLoader = 0x19,
  kGeneralSendThermal = 0x1d,
  kGeneralWriteSerialNumber = 0x20,
  kGeneralReadSerialNumber = 0x21,
  kGeneralCheckRsaMd5Sign = 0x22,
  kGeneralSetActiveSlot = 0x23,
  kGeneralGetHwType = 0x40,
  kGeneralGetFwType = 0x41,
  kGeneralLoaderVersion = 0x42,
  kGeneralAsciiCommand = 0xF0,
  kGeneralClosePush = 0xF1,
  kGeneralDebugFlag = 0xF2,
  kGeneralDebugData = 0xF3,
  kGeneralPtpStatus = 0xF4,
  kGeneralNetworkPortStatus = 0xF5,
  kGeneralCanPortStatus = 0xF6,
  kGeneralInvalid,
};

enum AdcMcuCommand {
  kAdcMcuPowerPeriodicUpdate = 0x00,
  kAdcOrinPowerOff = 0x01,
  kAdcAllPowerOff = 0x02,
  kAdcSetStandby = 0x03,
  kAdcOrinPowerOn = 0x04,
  kAdcInvalid,
};

enum ProtocolErrorCode {
  kProtocolSuccess = 0x0000,
  kProtocolDiscontinuousErr = 0x0001,
  kProtocolMd5Err = 0x0002,
  kProtocolOversize = 0x0003,
  kProtocolUnkownErr = 0x0004,
  kProtocolInvalidSize = 0x0005,
  kProtocolFlashFailed = 0x0006,
  kProtocolInvalidAppAddr = 0x0007,
  kProtocolUnAuth = 0x0008,
  kProtocolSwErr = 0x1000,
  kProtocolHwErr = 0x2000,
};

enum StorageLogCommand {
  kPullStorageLogRecordCount = 0x00,
  kPullStorageLogStart = 0x1,
  kPullStorageLogTransferring = 0x2,
  kPullStorageLogReturnCode = 0x3,
  kPullStorageLogTransferDone = 0x4,
};

enum StorageFlashCommand {
  kStorageFlashReserved = 0x00,
  kStorageFlashUpdateMode = 0x01,
  kStorageFlashStartUpdate = 0x02,
  kStorageFlashTransport = 0x03,
  kStorageFlashTransportComplete = 0x04,
  kStorageFlashEnable = 0x05,
  kStorageFlashDisable = 0x06,
  kStorageFlashGetStatus = 0x07,
  kStorageFlashGetVersion = 0x08,
  kStorageFlashSelectId = 0x09,
  kStorageFlashReadMode = 0x0a,
  kStorageFlashReading = 0x0b,
  kStorageFlashReadComplete = 0x0c,
};

enum TimeSyncCommand {
  kCmdTimeSyncSetLocalTime = 0x00,
  kCmdTimeSyncSaveRtc = 0x01,
  kCmdTimeSyncReadLocalTime = 0x02,
};

enum BootChainCommand {
  kBootChainStartUpdate = 0x00,  // data is device_id(uint16_t) + slot_type(uint32_t)
  // data is device_id(uint16_t) + slot_type(uint32_t) + timestamp(int64_t)
  kBootChainSetActiveSlot = 0x01,
  kBootChainUpdateDone = 0x02,  // data is timestamp(int64_t)
  kBootChainHandshake = 0x03,  // data is device_id (uint16_t)
  kBootChainGetAllActiveInfo = 0x04,  // data is NULL
  kBootChainGetActiveInfo = 0x05,  // data is NULL
  kBootChainGetAllSlotInfo = 0x06,  // data is NULL
  kBootChainGetDeviceSlotType = 0x07,  // data is device_id (uint16_t)
};

enum EthernetCommand {
  kEthernetPhySqiLevel = 0x00,
  kEthernetGetConfig = 0x01,
  kEthernetSetConfig = 0x02,
  kEthernetSaveConfig = 0x03,
  kEthernetReloadConfig = 0x04,
};

#endif  // PLATFORM_PROTOCOL_SDK_HWPROTOCOL_DEF_H_
