// Copyright @2021 Pony AI Inc. All rights reserved.

#ifndef COMMON_DRIVER_MARVELL_SWITCH_DEF_H_
#define COMMON_DRIVER_MARVELL_SWITCH_DEF_H_

#include <stdbool.h>
#include <stdint.h>

typedef enum SwitchPortSpeed {
  kSwitchSpeed10M,
  kSwitchSpeed100M,
  kSwitchSpeed200M,
  kSwitchSpeed1000M,
  kSwitchSpeed2Dot5G,
  kSwitchSpeed5G,
  kSwitchSpeed10G,
  kSwitchSpeedUnknown,
} SwitchPortSpeed;

typedef enum SwitchPortState {
  kSwitchPortDisable,
  kSwitchPortBlocking,
  kSwitchPortLearning,
  kSwitchPortForwarding,
  kSwitchPortUnknown,
} SwitchPortState;

typedef enum SwitchPortMode {
  kSwitchBase1000X = 0x0,
  kSwitchBase2500X = 0x1,
  kSwitchSgmiiPhy = 0x2,
  kSwitchSgmiiMac = 0x3,
  kSwitchBase5GR = 0x4,
  kSwitchBase10GR = 0x5,
  kSwitchUsxgmiiPhy = 0x6,
  kSwitchUsxgmiiMac = 0x7,
} SwitchPortMode;

typedef enum SwitchCMode {
  kSwitchCModeBase1000X = 0x9,
  kSwitchCModeSgmii = 0xa,
} SwitchCMode;

typedef enum SwitchVlanMemberTag {
  kSwitchMemberUnmodified = 0,
  kSwitchMemberUntagged = 1,
  kSwitchMemberTagged = 2,
  kSwitchNotMember,
} SwitchVlanMemberTag;

typedef enum SwitchPortEgressMode {
  kSwitchEgressUnmodified,
  kSwitchEgressUntagged,
  kSwitchEgressTagged,
} SwitchPortEgressMode;

typedef enum SwitchPortDuplexMode {
  kSwitchDuplexFull,
  kSwitchDuplexHalf,
  kSwitchDuplexAuto,
  kSwitchDuplexUnknown,
} SwitchPortDuplexMode;

typedef enum SwitchPort8021qMode {
  kSwitch8021qDisable,  // Use Port Based VLANs only.
  // Enable 802.1Q for this Ingress port. Do not discard Ingress Membership violations and use the
  // VLANTable bits if the frame's VID is not contained in the VTU.
  kSwitch8021qFallback,
  // Enable 802.1Q for this Ingress port. Do not discard Ingress Membership violations but discard
  // frames if its VID is not contained in the VTU.
  kSwitch8021qCheck,
   // Enable 802.1Q for this Ingress port. Discard Ingress Membership violations and discard frames
   // whose VID is not contained in the VTU
  kSwitch8021qSecure,
} SwitchPort8021qMode;

typedef enum SwitchPortSchedMode {
  kPortSchedWrrPri76543210 = 0x0,
  kPortSchedWrrPri6543210,
  kPortSchedWrrPri543210,
  kPortSchedWrrPri43210,
  kPortSchedWrrPri3210,
  kPortSchedWrrPri210,
  kPortSchedWrrPri10,
  kPortSchedStrictPriAll,
  kPortSchedUnknown,
} SwitchPortSchedMode;

typedef enum SwitchFlashMacAddrCmd {
  kFlushAll = 1,
  kFlushAllNonStatic = 2,
} SwitchFlashMacAddrCmd;

typedef enum SwitchPortMtuSize {
  kMtu1522 = 0,
  kMtu2048,
  kMtu10240,
} SwitchPortMtuSize;

typedef enum SwitchPortFcMode {
  kFcTxRxEnable = 0,
  kFcRxOnly,
  kFcTxOnly,
  kFcPfcEnable,
} SwitchPortFcMode;

typedef enum SwitchAtuViolationCause {
  kAgeOutVio = 0,
  kMemberVio,
  kMissVio,
  kFullVio,
} SwitchAtuViolationCause;

typedef enum SwitchPortVtuPrioOverride {
  kPrioOverrideNone = 0,
  kPrioOverrideFrame,
  kPrioOverrideQueue,
  kPrioOverrideFrameQueue,
} SwitchPortVtuPrioOverride;

typedef enum SwitchPortFrameMode {
  kPortFrameModeNormal = 0,
  kPortFrameModeDsa,
  kPortFrameModeProvider,
  kPortFrameModeEtherTypeDsa,
} SwitchPortFrameMode;

typedef struct SwitchPortVlanNode {
  uint8_t port_num;
  SwitchVlanMemberTag state;
} SwitchPortVlanNode;

typedef struct SwitchVlanPri {
  uint8_t use_q_pri;
  uint8_t q_pri;
  uint8_t use_f_pri;
  uint8_t f_pri;
} SwitchVlanPri;

typedef struct SwitchVlanTable {
  uint16_t vlan_id;
  uint16_t node_num;
  SwitchPortVlanNode* nodes;
  SwitchVlanPri v_pri;
} SwitchVlanTable;

typedef struct SwitchPortConfig {
  uint8_t port_num;
  uint8_t enable_default_vlan_id: 1;
  uint8_t allow_vlan_id_zero: 1;
  uint8_t reserved: 6;
  uint16_t default_vlan_id;
  SwitchPort8021qMode vlan_mode;
} __attribute__((packed)) SwitchPortConfig;

#endif  // COMMON_DRIVER_MARVELL_SWITCH_DEF_H_
