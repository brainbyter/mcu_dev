// Copyright @2021 Pony AI Inc. All rights reserved.

#ifndef COMMON_DRIVER_PHY_PHY_88Q2112_REGDEFS_H_
#define COMMON_DRIVER_PHY_PHY_88Q2112_REGDEFS_H_

// Phy88Q2112 register macro defines
// More detail information, please refer datasheet
// https://drive.google.com/file/d/1hw3rVP7g8B7E6xhmja4hVVQoH5gBiOn4/view?usp=sharing
#define PHY_88Q2112_MODEL_NUMBER (0x18)

// A2: can connect to any 1000 BASE-T1 compliant device
// A2: can be configured in lagacy/compatibility mode to connect to A0/A1/Z1
// A1: can be configured in lagacy/compatibility mode to connect to A0/Z1
#define PHY_88Q2112_MODEL_TYPE_A0 (0x01)
#define PHY_88Q2112_MODEL_TYPE_A1 (0x02)
#define PHY_88Q2112_MODEL_TYPE_A2 (0x03)
#define PHY_88Q2112_MODEL_TYPE_Z1 (0x00)

#define PHY_88Q2112_AN_DISABLE (0x0000)
#define PHY_88Q2112_AN_RESET (0x8000)
#define PHY_88Q2112_AN_ENABLE (0x1000)
#define PHY_88Q2112_AN_RESTART (0x0200)

// Device 0
#define MMD_CTRL_ADDR (0x0000)
#define MMD_CTRL_NOINCR (0x4000)
#define MMD_CTRL_INCR_RDWT (0x8000)
#define MMD_CTRL_INCR_ON_WT (0xc0000)

#define PHY_REG_XMDIO_MMD_CTRL (13)       // MMD Access Control Register
#define PHY_REG_XMDIO_MMD_ADDR_DATA (14)  // MMD Access Data Register

// Device 1
#define PHY_DEVICE_1 (1)
#define PHY_IDENTIFIER_REG_1 (0x0003)
#define PHY_IDENTIFIER_REG_2 (0x0004)
#define PHY_PMA_PMD_CONTROL_REG (0x0834)
#define PHY_BASE_T1_CONTROL_REG (0x0900)
#define PHY_1000_BASE_T1_TEST_MODE_CONTROL_REG (0x0904)

#define PHY88Q2112_1000_BASE_T1_TEST_MODE_OFFSET 13

// Device 3
#define PHY_DEVICE_3 (3)
#define PHY_PCS_CONTROL_REGISTER (0x0000)
#define PHY_PCS_IDENTIFIER_REG_1 (0x0002)
#define PHY_PCS_IDENTIFIER_REG_2 (0x0003)
#define PHY_PCS_STATUS_REG (0x0901)
#define PHY_100BASET1_STATUS_REG1 (0X8108)
#define PHY_100BASET1_STATUS_REG2 (0X8109)
#define PHY_LINK_DROP_COUNTER_REG (0x8120)
#define PHY_COUNTER_CONTROL_REG (0X8200)
#define PHY_BAD_LINK_COUNTER_REG (0x8221)
#define PHY_BAD_SSD_COUNTER_REG (0x8222)
#define PHY_BAD_ESD_COUNTER_REG (0x8223)
#define PHY_RX_ERROR_COUNTER_REG (0x8224)
#define PHY_RECEIVER_STATUS_REG (0x8230)
#define PHY_SQI_REG (0xFC4C)
// The SQI register information comes from the supplier
#define PHY_100M_SQI_16LEVEL (0x8230)
#define PHY_1000M_SQI_16LEVEL (0xFC88)
#define PHY_PACKET_CHECKER_CONTROL_REG (0xFD07)
#define PHY_PACKET_CHECKER_COUNT_REG (0xFD08)

#define PHY_PACKET_CHECKER_COUNT_START 0
#define PHY_PACKET_CHECKER_COUNT_ENABLE 2
#define PHY_PACKET_CHECKER_COUNT_RESET 3

// Device 4
#define PHY_DEVICE_4 (4)
#define PHY_SGMII_SPECIFIC_CONTROL_REG (0x801A)

// Device 7
#define PHY_DEVICE_7 (7)
#define PHY_AUTO_NEGOTIATION_REG (0x0200)
#define PHY_COM_PORT_CONTROL_REG (0x8001)

// Device 31
#define PHY_DEVICE_31 (31)

// For PHY_REG_MAC_CONTROL_2
#define RGMII_RXC_DELAY_EN_OFFSET 14
#define RGMII_TXC_DELAY_EN_OFFSET 15

#endif  // COMMON_DRIVER_PHY_PHY_88Q2112_REGDEFS_H_
