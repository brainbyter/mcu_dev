// Copyright @2021 Pony AI Inc. All rights reserved.

#ifndef COMMON_DRIVER_PHY_PHY_DEF_H_
#define COMMON_DRIVER_PHY_PHY_DEF_H_

typedef enum PhyLinkStatus {
  kPhyLinkDown = 0,
  kPhyLinkUp = 1,
  kPhyLinkUnknown = 0xff,
} PhyLinkStatus;

typedef enum PhyPolarity {
  kPhyPolarityNormal = 0,
  kPhyPolarityInvert = 1,
  kPhyPolarityUnknown = 0xff,
} PhyPolarity;

typedef enum PhySpeed {
  kPhySpeedUnknown = 0,
  kPhySpeed10M = 10,
  kPhySpeed100M = 100,
  kPhySpeed1000M = 1000,
  kPhySpeed2500M = 2500,
  kPhySpeed5G = 5000,
  kPhySpeed10G = 10000,
} PhySpeed;

typedef enum PhyDeviceRole {
  kPhyRoleSlave = 0,
  kPhyRoleMaster = 1,
  kPhyRoleUnknown = 0xff,
} PhyDeviceRole;

typedef struct PhySnr {
  int operation_margin;
  int minimum_margin;
} PhySnr;

#define PHY_SNR_BASE_DBM (21)

typedef enum PhyTestMode {
  kPhyTestModeNormal = 0x0,
  kPhyTestMode1 = 0x1,
  kPhyTestMode2 = 0x2,
  kPhyTestModeReserved = 0x3,
  kPhyTestMode4 = 0x4,
  kPhyTestMode5 = 0x5,
  kPhyTestMode6 = 0x6,
  kPhyTestMode7 = 0x7,
} PhyTestMode;

#endif  // COMMON_DRIVER_PHY_PHY_DEF_H_
