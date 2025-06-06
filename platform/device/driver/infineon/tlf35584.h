// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_INFINEON_TLF35584_H_
#define PLATFORM_DEVICE_DRIVER_INFINEON_TLF35584_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "common/mcu/utils/status.h"

typedef enum Tlf35584SpiCommandType {
  kSpiCommandRead = 0,
  kSpiCommandWrite = 1,
} Tlf35584SpiCommandType;

// Tlf35584 register address space
typedef enum Tlf35584RegAddr {
  kProtCfgRegAddr = 0x03,    // Protection register
  kSyspCfg0RegAddr = 0x04,   // Protected System configuration request 0
  kSyspCfg1RegAddr = 0x05,   // Protected System configuration request 1
  kWdCfg0RegAddr = 0x06,     // Protected Watchdog configuration request 0
  kRwWwdCfg1Addr = 0x0A,     // Protected Watchdog configuration request 1
  kRsyspCfg0RegAddr = 0x0B,  // System configuration 0 status
  kRsyspCfg1RegAddr = 0x0C,  // System configuration 1 status
  kWwdcfg0RegAddr = 0x10,    // Get the value of Window watchdog configuration 0 status
  kWwdcfg1RegAddr = 0x11,    // Get the value of Window watchdog configuration 1 status
  kRwdCfg0RegAddr = 0x0D,    // Watchdog configuration 0 status
  kDevctrlRegAddr = 0x15,    // Device control request
  kDevctrlnRegAddr = 0x16,   // Device control inverted request
  kWwdscmdRegAddr = 0x17,    // Window watchdog service command
  kSyssfRegAddr = 0x1D,      // System status flags
  kSpisfRegAddr = 0x1F,      // SPI status flags
  kMonsf0RegAddr = 0x20,     // Monitor status flags
  kMonsf1RegAddr = 0x21,     // Monitor status flags
  kMonsf2RegAddr = 0x22,     // Monitor status flags
  kOtfailRegAddr = 0x24,     // Over tempature failure status flags
  kOtwrnsfRegAddr = 0x25,    // Over tempature warning status flags
  kDevstatRegAddr = 0x27,    // Device status
} Tlf35584RegAddr;

// Protection key
typedef enum Tlf35584KeyType {
  kUnlockKey1 = 0xAB,
  kUnlockKey2 = 0xEF,
  kUnlockKey3 = 0x56,
  kUnlockKey4 = 0x12,
  kLockKey1 = 0xDF,
  kLockKey2 = 0x34,
  kLockKey3 = 0xBE,
  kLockKey4 = 0xCA,
} Tlf35584KeyType;

typedef enum Tlf35584BoolType {
  kDisabled = 0,
  kEnable = 1,
} Tlf35584BoolType;

// Device state
typedef enum Tlf35584StatusType {
  kDeviceStateNone = 0,      // NONE
  kDeviceStateInit = 1,      // INIT
  kDeviceStateNormal = 2,    // NORMAL
  kDeviceStateSleep = 3,     // SLEEP
  kDeviceStateStandby = 4,   // STANDBY
  kDeviceStateWake = 5,      // WAKE
  kDeviceStateReserved = 6,  // RESERVED
} Tlf35584StatusType;

// Protected System configuration request 0 bitfields
typedef struct Tlf35584SyspCfg0Bits {
  Tlf35584BoolType stbyen : 1;
  uint8_t nu : 7;
} Tlf35584SyspCfg0Bits;

// Protected System configuration request 1 bitfields
typedef struct Tlf35584SyspCfg1Bits {
  uint8_t errec : 2;
  Tlf35584BoolType errecn : 1;
  Tlf35584BoolType erren : 1;
  Tlf35584BoolType errslpen : 1;
  uint8_t ss2del : 2;
} Tlf35584SyspCfg1Bits;

// Protected Watchdog configuration request 0 bitfields
typedef struct Tlf35584WdCfg0Bits {
  Tlf35584BoolType wdcyc : 1;
  Tlf35584BoolType wwdtsel : 1;
  Tlf35584BoolType fwden : 1;
  Tlf35584BoolType wwden : 1;
  uint8_t wwdethr : 4;
} Tlf35584WdCfg0Bits;

// Device control request bitfields
typedef struct Tlf35584DevctrlBits {
  Tlf35584StatusType statereq : 3;  // Request for device state transition
  Tlf35584BoolType vrefen : 1;      // Request voltage reference QVR enable
  uint8_t reserved : 1;
  Tlf35584BoolType comen : 1;
  Tlf35584BoolType trk1en : 1;
  Tlf35584BoolType trk2en : 1;
} Tlf35584DevctrlBits;

typedef struct Tlf35584WwdscmdBits {
  uint8_t trig : 1;         // Window watchdog SPI trigger command
  uint8_t reserved : 6;     // unused bits
  uint8_t trig_status : 1;  // Last SPI trigger received
} Tlf35584WwdscmdBits;

typedef struct Tlf35584WwdCfg1Bits {
  uint8_t ow : 5;  // Request window watchdog open window time
  uint8_t nu : 3;
} Tlf35584WwdCfg1Bits;

typedef struct Tlf35584SyssfBits {
  Tlf35584BoolType cfge : 1;     // Protected configuration double bit error flag
  Tlf35584BoolType wwde : 1;     // Window watchdog error interrupt flag
  Tlf35584BoolType fwde : 1;     // Functional watchdog error interrupt flag
  Tlf35584BoolType errmiss : 1;  // MCU error miss status flag
  Tlf35584BoolType rfail : 1;    // Transition to low power failed flag
  Tlf35584BoolType no_op : 1;    // State transition request failure flag
  uint8_t reserved : 2;          // unused bits
} Tlf35584SyssfBits;

typedef struct Tlf35584SpisfBits {
  Tlf35584BoolType pare : 1;   // SPI frame parity error flag
  Tlf35584BoolType lene : 1;   // SPI frame length invalid flag
  Tlf35584BoolType addre : 1;  // SPI address invalid flag
  Tlf35584BoolType dure : 1;   // SPI frame duration error flag
  Tlf35584BoolType lock : 1;   // LOCK or UNLOCK procedure error flag
  uint8_t reserved : 3;        // unused bits
} Tlf35584SpisfBits;

typedef struct Tlf35584DevstatBits {
  Tlf35584StatusType state : 3;  // Device status
  Tlf35584BoolType vrefen : 1;
  Tlf35584BoolType stbyen : 1;
  Tlf35584BoolType comen : 1;
  Tlf35584BoolType trk1en : 1;
  Tlf35584BoolType trk2en : 1;
} Tlf35584DevstatBits;

typedef struct Tlf35584SpiFrameTypeBits {
  uint32_t parity : 1;       // Parity is automatically generated by the HW if 'ParityCheck = True'
  uint32_t data : 8;         // Data part of the SPI frame structure
  Tlf35584RegAddr addr : 6;  // Address part of the SPI frame structure
  Tlf35584SpiCommandType cmd : 1;  // Command part of the SPI frame structure
} Tlf35584SpiFrameTypeBits;

// Protection register bitfields
typedef struct Tlf35584ProtCfgBits {
  Tlf35584KeyType key : 8;
} Tlf35584ProtCfgBits;

// Protection register
typedef union Tlf35584ProtCfg {
  uint8_t u;                     // Unsigned access
  int8_t i;                      // Signed access
  Tlf35584ProtCfgBits reg_bits;  // Bitfield access
} Tlf35584ProtCfg;

// Protected System configuration request 0
typedef union Tlf35584SyspCfg0 {
  uint8_t u;
  int8_t i;
  Tlf35584SyspCfg0Bits reg_bits;
} Tlf35584SyspCfg0;

// Protected System configuration request 1
typedef union Tlf35584SyspCfg1 {
  uint8_t u;
  int8_t i;
  Tlf35584SyspCfg1Bits reg_bits;
} Tlf35584SyspCfg1;

// Protected Watchdog configuration request 0
typedef union Tlf35584WdCfg0 {
  uint8_t u;
  int8_t i;
  Tlf35584WdCfg0Bits reg_bits;
} Tlf35584WdCfg0;

typedef union Tlf35584WwdCfg1 {
  uint8_t u;
  int8_t i;
  Tlf35584WwdCfg1Bits reg_bits;
} Tlf35584WwdCfg1;

// Device control request
typedef union Tlf35584Devctrl {
  uint8_t u;
  int8_t i;
  Tlf35584DevctrlBits reg_bits;
} Tlf35584Devctrl;

typedef union Tlf35584Wwdscmd {
  uint8_t u;
  int8_t i;
  Tlf35584WwdscmdBits reg_bits;
} Tlf35584Wwdscmd;

// System status flags
typedef union Tlf35584Syssf {
  uint8_t u;
  int8_t i;
  Tlf35584SyssfBits reg_bits;
} Tlf35584Syssf;

// SPI status flags
typedef union Tlf35584Spisf {
  uint8_t u;
  int8_t i;
  Tlf35584SpisfBits reg_bits;
} Tlf35584Spisf;

/* Device status */
typedef union Tlf35584Devstat {
  uint8_t u;
  int8_t i;
  Tlf35584DevstatBits reg_bits;
} Tlf35584Devstat;

typedef union Tlf35584SpiFrameType {
  uint16_t u;
  int16_t i;
  Tlf35584SpiFrameTypeBits reg_bits;
} Tlf35584SpiFrameType;

// Window watchdog trigger selection type
typedef enum Tlf35584WwdtselType {
  kTlf35584WwdtselTypePin = 0,  // External WDI input used as a WWD trigger
  kTlf35584WwdtselTypeSpi = 1,  // WWD is triggered by SPI write to WWDSCMD register
} Tlf35584WwdtselType;

// Tlf35584 register structure
typedef struct {
  Tlf35584ProtCfg protcfg;     // 0x03, Protection register
  Tlf35584SyspCfg0 syspcfg0;   // 0x04, Protected System configuration request 0
  Tlf35584SyspCfg1 syspcfg1;   // 0x05, Protected System configuration request 1
  Tlf35584WdCfg0 wdcfg0;       // 0x06, Protected Watchdog configuration request 0
  Tlf35584WwdCfg1 wwdcfg1;     // 0x0A Protected Window watchdog configuration request 1
  Tlf35584SyspCfg0 rsyspcfg0;  // 0x0B, System configuration 0 status
  Tlf35584SyspCfg1 rsyspcfg1;  // 0x0C, System configuration 1 status
  Tlf35584WdCfg0 rwdcfg0;      // 0x0D, Watchdog configuration 0 status
  Tlf35584Devctrl devctrl;     // 0x15, Device control request
  Tlf35584Devctrl devctrln;    // 0x16, Device control inverted request
  Tlf35584Wwdscmd wwdscmd;     // 0x17, Window watchdog service command
  Tlf35584Syssf syssf;         // 0x1D, System status flags
  Tlf35584Spisf spisf;         // 0x1F, SPI status flags
  Tlf35584Devstat devstat;     // 0x27, Device status
  uint16_t spi_bus;            // Parameter used for spi_master_transfer
  uint8_t spi_slave;           // Parameter used for spi_master_transfer
  bool en_wwdt;                // enable window watchdog
  uint8_t wwdt_ow;             // window watchdog open window time
  Tlf35584WwdtselType wwdt_sel_type;  // used to select window watchdog trigger selection type
} Tlf35584;

ReturnCode Tlf35584Init(Tlf35584* tlfDevice);
ReturnCode Tlf35584EnableVoltageSupplyRails(Tlf35584* tlf_device);

uint8_t Tlf35584GetSpiStatusFlags(Tlf35584* tlfDevice);
uint8_t Tlf35584GetSystemStatusFlags(Tlf35584* tlfDevice);
ReturnCode Tlf35584ClearSpiStatusFlags(Tlf35584* tlfDevice);
ReturnCode Tlf35584ClearSystemStatusFlags(Tlf35584* tlfDevice);
ReturnCode Tlf35584ServiceWindowWatchdog(Tlf35584* tlf_device);

uint8_t Tlf35584GetConfig0Reg(Tlf35584* tlf_device);
uint8_t Tlf35584GetWwdcfg0Reg(Tlf35584* tlf_device);
uint8_t Tlf35584GetWwdcfg1Reg(Tlf35584* tlf_device);
uint8_t Tlf35584GetMonsf0Reg(Tlf35584* tlf_device);
uint8_t Tlf35584GetMonsf1Reg(Tlf35584* tlf_device);
uint8_t Tlf35584GetMonsf2Reg(Tlf35584* tlf_device);
uint8_t Tlf35584OtwfailReg(Tlf35584* tlf_device);
uint8_t Tlf35584OtwrnsfReg(Tlf35584* tlf_device);
ReturnCode Tlf35584WindowWatchdogTriggerSelect(Tlf35584* tlf_device, Tlf35584WwdtselType selection);

ReturnCode Tlf35584DisableWindowWatchdog(Tlf35584* tlf_device);
ReturnCode Tlf35584EnableErrPinMonitor(Tlf35584* tlf_device);

Tlf35584StatusType Tlf35584GetCurrentState(Tlf35584* tlfDevice);
void Tlf35584SetStateTransition(Tlf35584* tlfDevice, Tlf35584StatusType requestedStateTransition);

uint16_t Tlf35584ReadRegister(Tlf35584* tlfDevice, Tlf35584RegAddr reg);

ReturnCode Tlf35584StandbyQstDisable(Tlf35584* tlf_device);

#endif  // PLATFORM_DEVICE_DRIVER_INFINEON_TLF35584_H_
