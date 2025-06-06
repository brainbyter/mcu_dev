// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_NUT_AURIX_F0100_03_0001_AURIX_BSP_H_
#define PRODUCTS_F0100_0001_NUT_AURIX_F0100_03_0001_AURIX_BSP_H_

// ============== UART ==============

#define DEBUG_CONSOLE_NUMBER 0

#define MAX_UART_NUMBER 1
// ============== UART0 ==============
#define SUPPORT_UART0
#define UART0_RX_PIN &IfxAsclin0_RXA_P14_1_IN
#define UART0_TX_PIN &IfxAsclin0_TX_P14_0_OUT
#define UART0_BAUDRATE 115200
#define UART0_RX_BUF_SIZE 256
#define UART0_TX_BUF_SIZE 256
#define UART0_ISR_RX_PRIORITY 4
#define UART0_ISR_TX_PRIORITY 8
#define UART0_ISR_ERR_PRIORITY 12
#define UART0_SERVICE_CPU_ID 0

#ifndef AB_LOADER_FIRMWARE_LOADER

// ============== I2C ==============
#define MAX_I2C_NUMBER 4

// =============== I2C0 ===============
#define SUPPORT_I2C0
#define I2C0_SCL_PIN &IfxI2c0_SCL_P13_1_INOUT
#define I2C0_SDA_PIN &IfxI2c0_SDA_P13_2_INOUT
#define I2C0_BAUDRATE 400000
#define I2C0_PAD_DRIVER_MODE IfxPort_PadDriver_ttlSpeed1

// =============== I2C1 ===============
#define SUPPORT_I2C1
#define I2C1_SCL_PIN &IfxI2c1_SCL_P11_14_INOUT
#define I2C1_SDA_PIN &IfxI2c1_SDA_P11_13_INOUT
#define I2C1_BAUDRATE 400000
#define I2C1_PAD_DRIVER_MODE IfxPort_PadDriver_ttlSpeed1

#endif  // AB_LOADER_FIRMWARE_LOADER

// |-----|--------|--------|--------|--------------|-------------|
// | SPI |  MISO  |  MOSI  |  SCLK  |     CS       |   Product   |
// |-----|--------|--------|--------|--------------|-------------|
// |SPI0 | P20.12 | P20.14 | P20.11 | P20.08(CS00) | OrinBSocSpi2|
// |     |        |        |        | P20.13(CS02) | OrinASocSpi2|
// |-----|--------|--------|--------|--------------|-------------|
// |SPI1 | P10.01 | P10.03 | P10.02 | P10.00(CS10) | AURIX B     |
// |-----|--------|--------|--------|--------------|-------------|
// |SPI2 | P15.04 | P15.05 | P15.03 | P15.02(CS02) | TLF35584    |
// |                                | P20.03(CS09) | TJA1145     |
// |-----|--------|--------|--------|--------------|-------------|
// |SPI3 | P01.05 | P01.06 | P01.07 | P01.03(CS09) | E52142A52C  |
// |                                | P01.04(CS10) | IS25LP032D  |
// |-----|--------|--------|--------|--------------|-------------|
// |SPI4 | P22.01 | P22.00 | P22.03 | P33.09(CS01) | OrinBFsiSpi7|
// |                                | P22.02(CS03) | OrinAFsiSpi7|
// |-----|--------|--------|--------|--------------|-------------|
// |SPI5 | P14.05 | P14.06 | P14.10 | P15.06(CS03) | E52142A52C  |
// |-----|--------|--------|--------|--------------|-------------|

// ============== SPI ==============
#define MAX_SPI_NUMBER 6
#define MAX_SPI_CHIPSELECT_NUM 4

#ifndef AB_LOADER_FIRMWARE_LOADER
// =============== SPI0 ===============
#define SUPPORT_SPI0
#define SPI0_RX_INT_PRIO 50
#define SPI0_TX_INT_PRIO 30
#define SPI0_ERR_INT_PRIO 20
#define SPI0_PROVIDER IfxSrc_Tos_cpu0
#define SPI0_SCLK_PIN &IfxQspi0_SCLK_P20_11_OUT
#define SPI0_MOSI_PIN &IfxQspi0_MTSR_P20_14_OUT
#define SPI0_MISO_PIN &IfxQspi0_MRSTA_P20_12_IN
#define SPI0_PIN_DRIVER IfxPort_PadDriver_cmosAutomotiveSpeed3

// ============ SPI0 SLAVE0=============
#define SUPPORT_SPI0_SLAVE0
#define SPI0_SLAVE0_CS_PIN &IfxQspi0_SLSO0_P20_8_OUT  // To Orin B
#define SPI0_SLAVE0_DATA_WIDTH 8
#define SPI0_SLAVE0_BAUDRATE 5000000
#define SPI0_SLAVE0_DATA_MODE IfxQspi_SpiMaster_Mode_shortContinuous
#define SPI0_SLAVE0_DATA_HEADING SpiIf_DataHeading_msbFirst
#define SPI0_SLAVE0_TRAIL_DELAY SpiIf_SlsoTiming_0
#define SPI0_SLAVE0_CLOCK_PHASE SpiIf_ShiftClock_shiftTransmitDataOnLeadingEdge
#define SPI0_SLAVE0_CLOCK_POLARITY SpiIf_ClockPolarity_idleLow

// ============ SPI0 SLAVE1=============
#define SUPPORT_SPI0_SLAVE1
#define SPI0_SLAVE1_CS_PIN &IfxQspi0_SLSO2_P20_13_OUT  // To Orin A
#define SPI0_SLAVE1_DATA_WIDTH 8
#define SPI0_SLAVE1_BAUDRATE 5000000
#define SPI0_SLAVE1_DATA_MODE IfxQspi_SpiMaster_Mode_shortContinuous
#define SPI0_SLAVE1_DATA_HEADING SpiIf_DataHeading_msbFirst
#define SPI0_SLAVE1_TRAIL_DELAY SpiIf_SlsoTiming_0
#define SPI0_SLAVE1_CLOCK_PHASE SpiIf_ShiftClock_shiftTransmitDataOnLeadingEdge
#define SPI0_SLAVE1_CLOCK_POLARITY SpiIf_ClockPolarity_idleLow

// =============== SPI1 ===============
#define SUPPORT_SPI1
#define SPI1_RX_INT_PRIO 51
#define SPI1_TX_INT_PRIO 31
#define SPI1_ERR_INT_PRIO 21
#define SPI1_PROVIDER IfxSrc_Tos_cpu0
#define SPI1_SCLK_PIN &IfxQspi1_SCLK_P10_2_OUT
#define SPI1_MOSI_PIN &IfxQspi1_MTSR_P10_3_OUT
#define SPI1_MISO_PIN &IfxQspi1_MRSTA_P10_1_IN
#define SPI1_PIN_DRIVER IfxPort_PadDriver_cmosAutomotiveSpeed1

// ============ SPI1 SLAVE0=============
#define SUPPORT_SPI1_SLAVE0
#define SPI1_SLAVE0_CS_PIN &IfxQspi1_SLSO10_P10_0_OUT  // To Aurix B
#define SPI1_SLAVE0_DATA_WIDTH 8
#define SPI1_SLAVE0_BAUDRATE 5000000
#define SPI1_SLAVE0_DATA_MODE IfxQspi_SpiMaster_Mode_shortContinuous
#define SPI1_SLAVE0_DATA_HEADING SpiIf_DataHeading_msbFirst
#define SPI1_SLAVE0_TRAIL_DELAY SpiIf_SlsoTiming_0
#define SPI1_SLAVE0_CLOCK_PHASE SpiIf_ShiftClock_shiftTransmitDataOnLeadingEdge
#define SPI1_SLAVE0_CLOCK_POLARITY SpiIf_ClockPolarity_idleLow

#endif  // AB_LOADER_FIRMWARE_LOADER

// =============== SPI2 ===============
#define SUPPORT_SPI2
#define SPI2_RX_INT_PRIO 53
#define SPI2_TX_INT_PRIO 33
#define SPI2_ERR_INT_PRIO 23
#define SPI2_PROVIDER IfxSrc_Tos_cpu0
#define SPI2_SCLK_PIN &IfxQspi2_SCLK_P15_3_OUT
#define SPI2_MOSI_PIN &IfxQspi2_MTSR_P15_5_OUT
#define SPI2_MISO_PIN &IfxQspi2_MRSTA_P15_4_IN
#define SPI2_PIN_DRIVER IfxPort_PadDriver_cmosAutomotiveSpeed3

// ============ SPI2 SLAVE0=============
#define SUPPORT_SPI2_SLAVE0
#define SPI2_SLAVE0_CS_PIN &IfxQspi2_SLSO0_P15_2_OUT  // To TLF35584
#define SPI2_SLAVE0_DATA_WIDTH 8
#define SPI2_SLAVE0_BAUDRATE 5000000
#define SPI2_SLAVE0_DATA_MODE IfxQspi_SpiMaster_Mode_shortContinuous
#define SPI2_SLAVE0_DATA_HEADING SpiIf_DataHeading_msbFirst
#define SPI2_SLAVE0_TRAIL_DELAY SpiIf_SlsoTiming_2
#define SPI2_SLAVE0_CLOCK_PHASE SpiIf_ShiftClock_shiftTransmitDataOnTrailingEdge
#define SPI2_SLAVE0_CLOCK_POLARITY SpiIf_ClockPolarity_idleLow

#ifndef AB_LOADER_FIRMWARE_LOADER

// ============ SPI2 SLAVE1=============
#define SUPPORT_SPI2_SLAVE1
#define SPI2_SLAVE1_CS_PIN &IfxQspi2_SLSO9_P20_3_OUT  // To TJA1145
#define SPI2_SLAVE1_DATA_WIDTH 8
#define SPI2_SLAVE1_BAUDRATE 500000
#define SPI2_SLAVE1_DATA_MODE IfxQspi_SpiMaster_Mode_shortContinuous
#define SPI2_SLAVE1_DATA_HEADING SpiIf_DataHeading_msbFirst
#define SPI2_SLAVE1_TRAIL_DELAY SpiIf_SlsoTiming_0
#define SPI2_SLAVE1_CLOCK_PHASE SpiIf_ShiftClock_shiftTransmitDataOnLeadingEdge
#define SPI2_SLAVE1_CLOCK_POLARITY SpiIf_ClockPolarity_idleLow

// =============== SPI3 ===============
#define SUPPORT_SPI3
#define SPI3_RX_INT_PRIO 52
#define SPI3_TX_INT_PRIO 32
#define SPI3_ERR_INT_PRIO 22
#define SPI3_PROVIDER IfxSrc_Tos_cpu0
#define SPI3_SCLK_PIN &IfxQspi3_SCLK_P01_7_OUT
#define SPI3_MOSI_PIN &IfxQspi3_MTSR_P01_6_OUT
#define SPI3_MISO_PIN &IfxQspi3_MRSTC_P01_5_IN
#define SPI3_PIN_DRIVER IfxPort_PadDriver_cmosAutomotiveSpeed1

// ============ SPI3 SLAVE0=============
#define SUPPORT_SPI3_SLAVE0
#define SPI3_SLAVE0_CS_PIN &IfxQspi3_SLSO9_P01_3_OUT  // To USS
#define SPI3_SLAVE0_DATA_WIDTH 16
#define SPI3_SLAVE0_BAUDRATE 500000
#define SPI3_SLAVE0_DATA_MODE IfxQspi_SpiMaster_Mode_shortContinuous
#define SPI3_SLAVE0_DATA_HEADING SpiIf_DataHeading_msbFirst
#define SPI3_SLAVE0_TRAIL_DELAY SpiIf_SlsoTiming_0
#define SPI3_SLAVE0_LEAD_DELAY SpiIf_SlsoTiming_1
#define SPI3_SLAVE0_CLOCK_PHASE SpiIf_ShiftClock_shiftTransmitDataOnLeadingEdge
#define SPI3_SLAVE0_CLOCK_POLARITY SpiIf_ClockPolarity_idleLow

// ============ SPI3 SLAVE1 =============
#define SUPPORT_SPI3_SLAVE1
#define SPI3_SLAVE1_CS_PIN &IfxQspi3_SLSO10_P01_4_OUT  // To IS25LP032D
#define SPI3_SLAVE1_DATA_WIDTH 8
#define SPI3_SLAVE1_BAUDRATE 1000000
#define SPI3_SLAVE1_DATA_MODE IfxQspi_SpiMaster_Mode_shortContinuous
#define SPI3_SLAVE1_DATA_HEADING SpiIf_DataHeading_msbFirst
#define SPI3_SLAVE1_TRAIL_DELAY SpiIf_SlsoTiming_0
#define SPI3_SLAVE1_LEAD_DELAY SpiIf_SlsoTiming_2
#define SPI3_SLAVE1_CLOCK_PHASE SpiIf_ShiftClock_shiftTransmitDataOnTrailingEdge
#define SPI3_SLAVE1_CLOCK_POLARITY SpiIf_ClockPolarity_idleLow

// =============== SPI4 ===============
#define SUPPORT_SPI4
#define SUPPORT_SPI4_DMA
#define SPI4_DMA_RX_INT_PRIO 48
#define SPI4_DMA_TX_INT_PRIO 28
#define SPI4_DMA_RX_CHANNEL_ID IfxDma_ChannelId_48
#define SPI4_DMA_TX_CHANNEL_ID IfxDma_ChannelId_28
#define SPI4_ERR_INT_PRIO 22
#define SPI4_PROVIDER IfxSrc_Tos_cpu0
#define SPI4_SCLK_PIN &IfxQspi4_SCLK_P22_3_OUT
#define SPI4_MOSI_PIN &IfxQspi4_MTSR_P22_0_OUT
#define SPI4_MISO_PIN &IfxQspi4_MRSTB_P22_1_IN
#define SPI4_PIN_DRIVER IfxPort_PadDriver_cmosAutomotiveSpeed3

// ============ SPI4 SLAVE0=============
#define SUPPORT_SPI4_SLAVE0
#define SPI4_SLAVE0_CS_PIN &IfxQspi4_SLSO1_P33_9_OUT  // To Orin B
#define SPI4_SLAVE0_DATA_WIDTH 32
#define SPI4_SLAVE0_BAUDRATE 5000000
#define SPI4_SLAVE0_DATA_MODE IfxQspi_SpiMaster_Mode_longContinuous
#define SPI4_SLAVE0_DATA_HEADING SpiIf_DataHeading_lsbFirst
#define SPI4_SLAVE0_TRAIL_DELAY SpiIf_SlsoTiming_0
#define SPI4_SLAVE0_CLOCK_PHASE SpiIf_ShiftClock_shiftTransmitDataOnLeadingEdge
#define SPI4_SLAVE0_CLOCK_POLARITY SpiIf_ClockPolarity_idleLow

// ============ SPI4 SLAVE1=============
#define SUPPORT_SPI4_SLAVE1
#define SPI4_SLAVE1_CS_PIN &IfxQspi4_SLSO3_P22_2_OUT  // To Orin A
#define SPI4_SLAVE1_DATA_WIDTH 32
#define SPI4_SLAVE1_BAUDRATE 5000000
#define SPI4_SLAVE1_DATA_MODE IfxQspi_SpiMaster_Mode_longContinuous
#define SPI4_SLAVE1_DATA_HEADING SpiIf_DataHeading_lsbFirst
#define SPI4_SLAVE1_TRAIL_DELAY SpiIf_SlsoTiming_0
#define SPI4_SLAVE1_CLOCK_PHASE SpiIf_ShiftClock_shiftTransmitDataOnLeadingEdge
#define SPI4_SLAVE1_CLOCK_POLARITY SpiIf_ClockPolarity_idleLow

// =============== SPI5 ===============
#define SUPPORT_SPI5
#define SPI5_RX_INT_PRIO 49
#define SPI5_TX_INT_PRIO 29
#define SPI5_ERR_INT_PRIO 19
#define SPI5_PROVIDER IfxSrc_Tos_cpu0
#define SPI5_SCLK_PIN &IfxQspi5_SCLK_P14_10_OUT
#define SPI5_MOSI_PIN &IfxQspi5_MTSR_P14_6_OUT
#define SPI5_MISO_PIN &IfxQspi5_MRSTB_P14_5_IN
#define SPI5_PIN_DRIVER IfxPort_PadDriver_cmosAutomotiveSpeed3

// ============ SPI5 SLAVE0=============
#define SUPPORT_SPI5_SLAVE0
#define SPI5_SLAVE0_CS_PIN &IfxQspi5_SLSO3_P15_6_OUT  // To USS
#define SPI5_SLAVE0_DATA_WIDTH 16
#define SPI5_SLAVE0_BAUDRATE 500000
#define SPI5_SLAVE0_DATA_MODE IfxQspi_SpiMaster_Mode_shortContinuous
#define SPI5_SLAVE0_DATA_HEADING SpiIf_DataHeading_msbFirst
#define SPI5_SLAVE0_TRAIL_DELAY SpiIf_SlsoTiming_0
#define SPI5_SLAVE0_LEAD_DELAY SpiIf_SlsoTiming_1
#define SPI5_SLAVE0_CLOCK_PHASE SpiIf_ShiftClock_shiftTransmitDataOnLeadingEdge
#define SPI5_SLAVE0_CLOCK_POLARITY SpiIf_ClockPolarity_idleLow

#endif  // AB_LOADER_FIRMWARE_LOADER

// ============== CAN ==============
#define MAX_CAN_NUMBER 12
#define SUPPORT_VIRTUAL_CAN_UART
#define CAN_SUPPORT_CANFD

// ============== CAN0 ==============
#define SUPPORT_CAN0  // CAN3 for F0100_0001 Aurix A, TJA1042
#define CAN0_SERVICE_CPU_ID 0
#define CAN0_RX_MSG_BUF_SIZE 255
#define CAN0_BAUDRATE kCANBaudrate500K
#define CAN0_CANFD_BADURATE kCANBaudrate2M
#define CAN0_ENABLE_CANFD 1
#define CAN0_CANFD_BRS 0
#define CAN0_RX_PIN &IfxCan_RXD00G_P34_2_IN
#define CAN0_TX_PIN &IfxCan_TXD00_P34_1_OUT
#define CAN0_STANDBY_PIN 206
#define CAN0_STANDBY_ACTIVE_LOW 1
#define CAN0_TX_IRQ_PRIORITY 68
#define CAN0_RX_IRQ_PRIORITY 60

#ifndef AB_LOADER_FIRMWARE_LOADER
// ============== CAN2 ==============
#define SUPPORT_CAN2  // CAN4 for F0100_0001 Aurix A, TJA1042
#define CAN2_SERVICE_CPU_ID 0
#define CAN2_RX_MSG_BUF_SIZE 255
#define CAN2_BAUDRATE kCANBaudrate500K
#define CAN2_CANFD_BADURATE kCANBaudrate2M
#define CAN2_ENABLE_CANFD 1
#define CAN2_CANFD_BRS 0
#define CAN2_RX_PIN &IfxCan_RXD02B_P02_3_IN
#define CAN2_TX_PIN &IfxCan_TXD02_P02_2_OUT
#define CAN2_STANDBY_PIN 207
#define CAN2_STANDBY_ACTIVE_LOW 1
#define CAN2_TX_IRQ_PRIORITY 69
#define CAN2_RX_IRQ_PRIORITY 61

// ============== CAN3 ==============
#define SUPPORT_CAN3  // CAN2 for F0100_0001 Aurix A, TJA1042
#define CAN3_SERVICE_CPU_ID 0
#define CAN3_RX_MSG_BUF_SIZE 255
#define CAN3_BAUDRATE kCANBaudrate500K
#define CAN3_CANFD_BADURATE kCANBaudrate2M
#define CAN3_ENABLE_CANFD 1
#define CAN3_CANFD_BRS 0
#define CAN3_RX_PIN &IfxCan_RXD03A_P00_3_IN
#define CAN3_TX_PIN &IfxCan_TXD03_P00_2_OUT
#define CAN3_STANDBY_PIN 5
#define CAN3_STANDBY_ACTIVE_LOW 1
#define CAN3_TX_IRQ_PRIORITY 70
#define CAN3_RX_IRQ_PRIORITY 62

// ============== CAN4 ==============
#define SUPPORT_CAN4  // CAN1 for F0100_0001 Aurix A, TJA1145
#define CAN4_SERVICE_CPU_ID 0
#define CAN4_RX_MSG_BUF_SIZE 255
#define CAN4_BAUDRATE kCANBaudrate500K
#define CAN4_CANFD_BADURATE kCANBaudrate2M
#define CAN4_ENABLE_CANFD 1
#define CAN4_CANFD_BRS 0
#define CAN4_RX_PIN &IfxCan_RXD10A_P00_1_IN
#define CAN4_TX_PIN &IfxCan_TXD10_P00_0_OUT
#define CAN4_TX_IRQ_PRIORITY 71
#define CAN4_RX_IRQ_PRIORITY 63

// ============== CAN5 ==============
#define SUPPORT_CAN5  // CAN5 for F0100_0001 Aurix A, TJA1042
#define CAN5_SERVICE_CPU_ID 0
#define CAN5_RX_MSG_BUF_SIZE 255
#define CAN5_BAUDRATE kCANBaudrate500K
#define CAN5_CANFD_BADURATE kCANBaudrate2M
#define CAN5_ENABLE_CANFD 1
#define CAN5_CANFD_BRS 0
#define CAN5_RX_PIN &IfxCan_RXD11A_P02_4_IN
#define CAN5_TX_PIN &IfxCan_TXD11_P02_5_OUT
#define CAN5_STANDBY_PIN 1004  // 1004
#define CAN5_STANDBY_ACTIVE_LOW 1
#define CAN5_TX_IRQ_PRIORITY 72
#define CAN5_RX_IRQ_PRIORITY 64

// ============== CAN9 ==============
#define SUPPORT_CAN9  // CAN6 for F0100_0001 Aurix A, TJA1042
#define CAN9_SERVICE_CPU_ID 0
#define CAN9_RX_MSG_BUF_SIZE 255
#define CAN9_BAUDRATE kCANBaudrate500K
#define CAN9_CANFD_BADURATE kCANBaudrate2M
#define CAN9_ENABLE_CANFD 1
#define CAN9_CANFD_BRS 0
#define CAN9_RX_PIN &IfxCan_RXD21F_P22_7_IN
#define CAN9_TX_PIN &IfxCan_TXD21_P22_6_OUT
#define CAN9_TX_IRQ_PRIORITY 73
#define CAN9_RX_IRQ_PRIORITY 65

// ============== CAN10 ==============
#define SUPPORT_CAN10  // CAN7 for F0100_0001 Aurix A, TJA1042
#define CAN10_SERVICE_CPU_ID 0
#define CAN10_RX_MSG_BUF_SIZE 255
#define CAN10_BAUDRATE kCANBaudrate500K
#define CAN10_CANFD_BADURATE kCANBaudrate2M
#define CAN10_ENABLE_CANFD 1
#define CAN10_CANFD_BRS 0
#define CAN10_RX_PIN &IfxCan_RXD22E_P22_9_IN
#define CAN10_TX_PIN &IfxCan_TXD22_P22_8_OUT
#define CAN10_TX_IRQ_PRIORITY 74
#define CAN10_RX_IRQ_PRIORITY 66

// ============== CAN11 ==============
#define SUPPORT_CAN11  // CAN8 for F0100_0001 Aurix A, TJA1042
#define CAN11_SERVICE_CPU_ID 0
#define CAN11_RX_MSG_BUF_SIZE 255
#define CAN11_BAUDRATE kCANBaudrate500K
#define CAN11_CANFD_BADURATE kCANBaudrate2M
#define CAN11_ENABLE_CANFD 1
#define CAN11_CANFD_BRS 0
#define CAN11_RX_PIN &IfxCan_RXD23E_P22_11_IN
#define CAN11_TX_PIN &IfxCan_TXD23_P22_10_OUT
#define CAN11_TX_IRQ_PRIORITY 75
#define CAN11_RX_IRQ_PRIORITY 67

// ============== GETH0 ==============
#define SUPPORT_GETH0
#define GETH0_SERVICE_CPU_ID 0
#define GETH0_RX_IRQ_PRIORITY 90
#define GETH0_TX_IRQ_PRIORITY 91
#define GETH0_PHY_MODE IfxGeth_PhyInterfaceMode_rgmii
#define GETH0_MAC_SPEED IfxGeth_LineSpeed_1000Mbps
#define GETH0_RGMII_MAC_TX_DELAY 0
#define GETH0_RGMII_MAC_RX_DELAY 0

// clang-format off
#define GETH0_RGMII_TXCLK_PIN    &IfxGeth_TXCLK_P11_4_OUT
#define GETH0_RGMII_TXD0_PIN     &IfxGeth_TXD0_P11_3_OUT
#define GETH0_RGMII_TXD1_PIN     &IfxGeth_TXD1_P11_2_OUT
#define GETH0_RGMII_TXD2_PIN     &IfxGeth_TXD2_P11_1_OUT
#define GETH0_RGMII_TXD3_PIN     &IfxGeth_TXD3_P11_0_OUT
#define GETH0_RGMII_TXCTL_PIN    &IfxGeth_TXCTL_P11_6_OUT
#define GETH0_RGMII_RXCLK_PIN    &IfxGeth_RXCLKA_P11_12_IN
#define GETH0_RGMII_RXD0_PIN     &IfxGeth_RXD0A_P11_10_IN
#define GETH0_RGMII_RXD1_PIN     &IfxGeth_RXD1A_P11_9_IN
#define GETH0_RGMII_RXD2_PIN     &IfxGeth_RXD2A_P11_8_IN
#define GETH0_RGMII_RXD3_PIN     &IfxGeth_RXD3A_P11_7_IN
#define GETH0_RGMII_RXCTL_PIN    &IfxGeth_RXCTLA_P11_11_IN
#define GETH0_RGMII_MDC_PIN      &IfxGeth_MDC_P12_0_OUT
#define GETH0_RGMII_MDIO_PIN     &IfxGeth_MDIO_P12_1_INOUT
#define GETH0_RGMII_GREFCLK_PIN  &IfxGeth_GREFCLK_P11_5_IN
// clang-format on

#define SUPPORT_MDIO0
#define MDIO0_PIN_MDC &IfxGeth_MDC_P12_0_OUT
#define MDIO0_PIN_MDIO &IfxGeth_MDIO_P12_1_INOUT

// #define SUPPORT_ERU0
// define ISR_SCUERU_INT0_PRIORITY 80
//
// #define SUPPORT_ERU1
// #define ISR_SCUERU_INT1_PRIORITY 81
//
// #define SUPPORT_ERU2
// #define ISR_SCUERU_INT2_PRIORITY 82
//
// #define SUPPORT_ERU3
// #define ISR_SCUERU_INT3_PRIORITY 83
//
// #define SUPPORT_ERU4
// #define ISR_SCUERU_INT4_PRIORITY 84
//
// #define SUPPORT_ERU5
// #define ISR_SCUERU_INT5_PRIORITY 85

#define SUPPORT_ERU7
#define ISR_SCUERU_INT7_PRIORITY 87

#define SUPPORT_HSSL0
#define SUPPORT_HSSL0_MASTER

// PWM
#define SUPPORT_TOM_PWM0
#define PWM0_CLK_FREQ 1000000
#define PWM0_PERIOD 33333333

#define SUPPORT_TOM_PWM0_CH8
#define PWM0_CH8_PIN &IfxGtm_TOM0_8_TOUT8_P02_8_OUT

// TIMER
#define SUPPORT_TIMER0
#define TIME0_PRIORITY 76
#define TIME0_MODE        IfxGpt12_Mode_timer
#define TIME0_DIRECTION   IfxGpt12_TimerDirection_up
#define TIME0_RELOAD_MODE IfxGpt12_ReloadInputMode_counterDisabled 

// #define SUPPORT_TIMER1
// #define TIME1_PRIORITY 77
// #define TIME1_MODE        IfxGpt12_Mode_timer
// #define TIME1_DIRECTION   IfxGpt12_TimerDirection_up

// #define SUPPORT_TIMER2
// #define TIME2_PRIORITY 78
// #define TIME2_MODE        IfxGpt12_Mode_timer
// #define TIME2_DIRECTION   IfxGpt12_TimerDirection_up
// #define TIME2_RELOAD_MODE IfxGpt12_ReloadInputMode_counterDisabled 

// #define SUPPORT_TIMER3
// #define TIME3_PRIORITY 79
// #define TIME3_MODE        IfxGpt12_Mode_timer
// #define TIME3_DIRECTION   IfxGpt12_TimerDirection_up

// #define SUPPORT_TIMER4
// #define TIME4_PRIORITY 80
// #define TIME4_MODE        IfxGpt12_Mode_timer
// #define TIME4_DIRECTION   IfxGpt12_TimerDirection_up

#endif  // AB_LOADER_FIRMWARE_LOADER

#define MAX_IRQ_NUMBERS 255

#endif  // PRODUCTS_F0100_0001_NUT_AURIX_F0100_03_0001_AURIX_BSP_H_
