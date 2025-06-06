// Copyright @2021 Pony AI Inc. All rights reserved.

/// @defgroup phy_driver phy driver

/// @defgroup phy88q2112_common_driver phy88q2112 common driver
/// @ingroup phy_driver
/// This is the abstract layer of phy88q2112 device interface and common driver.

/// @file
/// @ingroup phy88q2112_common_driver
/// @brief the header file for phy88q2112 common driver

#ifndef COMMON_DRIVER_PHY_PHY_88Q2112_H_
#define COMMON_DRIVER_PHY_PHY_88Q2112_H_

#include <stdbool.h>
#include <stdint.h>

#include "common/driver/phy/phy_def.h"
#include "common/mcu/utils/status.h"

/// @ingroup phy88q2112_common_driver
/// @brief The unified phy88q2112 device struct for phy88q2112 device. the basic phy88q2112
/// driver should implement these parameters
typedef struct Phy88q2112 {
  /// The phy device name
  const char* name;
  /// The phy device speed
  uint32_t speed;
  /// The phy device address
  uint8_t address;
  /// The phy device use Clause 45
  bool is_c45;
  /// The phy device role
  PhyDeviceRole device_role;
  // Operate reset pin to reset phy88q2112, follow datasheet, pull-down this pin at least 10ms and
  // then pull-up this pin wait least 50ms.
  /// @brief Hard reset the device.
  /// @param param [void*]
  /// @return void
  void (*hard_reset)(void* param);
  /// @brief Read data from device.
  /// @param slave_addr [uint8_t] smi slave address
  /// @param reg_addr [uint8_t] device register address
  /// @param value [uint16_t*] the read out value
  /// @param param [void*] The parameter for the smi read function
  /// @return ReturnCode: if succeed, return ERROR_OK.
  ReturnCode (*smi_read)(uint8_t slave_addr, uint8_t reg_addr, uint16_t* value, void* param);
  /// @brief Write data to device.
  /// @param slave_addr [uint8_t] smi slave address
  /// @param reg_addr [uint8_t] device register address
  /// @param value [uint16_t] the value to write
  /// @param param [void*] The parameter for the smi write function
  /// @return ReturnCode: if succeed, return ERROR_OK.
  ReturnCode (*smi_write)(uint8_t slave_addr, uint8_t reg_addr, uint16_t value, void* param);
  /// @brief Read data from device using Clause 45.
  /// @param slave_addr [uint8_t] smi slave address
  /// @param dev_addr [uint8_t] device address in Clause 45 mode
  /// @param reg_addr [uint16_t] device register address in Clause 45 mode
  /// @param value [uint16_t*] the read out value
  /// @param param [void*] The parameter for the smi read c45 function
  /// @return ReturnCode: if succeed, return ERROR_OK.
  ReturnCode (*smi_read_c45)(uint8_t slave_addr, uint8_t dev_addr, uint16_t reg_addr,
                             uint16_t* value, void* param);
   /// @brief Write data to device using Clause 45.
   /// @param slave_addr [uint8_t] smi slave address
   /// @param dev_addr [uint8_t] device address in Clause 45 mode
   /// @param reg_addr [uint16_t] device register address in Clause 45 mode
   /// @param value [uint16_t] the value to write
   /// @param param [void*] The parameter for the smi write c45 function
   /// @return ReturnCode: if succeed, return ERROR_OK.
  ReturnCode (*smi_write_c45)(uint8_t slave_addr, uint8_t dev_addr, uint16_t reg_addr,
                              uint16_t value, void* param);
  /// @brief Delay in millisecond.
  /// @param ms [uint32_t] millisecond
  /// @return void
  void (*delay_ms)(uint32_t ms);
  /// The parameter for the Phy88q2112 device
  void* param;
} Phy88q2112;

/// @ingroup phy88q2112_common_driver
/// @brief Initialize the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112Init(Phy88q2112* dev);
/// @ingroup phy88q2112_common_driver
/// @brief Set the device role of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param role [PhyDeviceRole] The device role to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112SetDeviceRole(Phy88q2112* dev, PhyDeviceRole role);
/// @ingroup phy88q2112_common_driver
/// @brief Get the device role of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param role [PhyDeviceRole*] The pointer to store the device role
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112GetDeviceRole(Phy88q2112* dev, PhyDeviceRole* role);
/// @ingroup phy88q2112_common_driver
/// @brief Get the speed of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param speed [PhySpeed*] The pointer to store the speed
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112GetSpeed(Phy88q2112* dev, PhySpeed* speed);
/// @ingroup phy88q2112_common_driver
/// @brief Get the PCS speed of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param speed [PhySpeed*] The pointer to store the PCS speed
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112GetPcsSpeed(Phy88q2112* dev, PhySpeed* speed);
/// @ingroup phy88q2112_common_driver
/// @brief Set the PMA speed of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param speed [PhySpeed] The PMA speed to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112SetPmaSpeed(Phy88q2112* dev, PhySpeed speed);
/// @ingroup phy88q2112_common_driver
/// @brief Get the link status of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param link_status [PhyLinkStatus*] The pointer to store the link status
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112GetLinkStatus(Phy88q2112* dev, PhyLinkStatus* link_status);
/// @ingroup phy88q2112_common_driver
/// @brief Set the 1000Base-T1 test mode of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param test_mode [PhyTestMode] The test mode to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112Set1000BaseT1TestMode(Phy88q2112* dev, PhyTestMode test_mode);
/// @ingroup phy88q2112_common_driver
/// @brief Get the 1000Base-T1 test mode of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param test_mode [PhyTestMode*] The pointer to store the test mode
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112Get1000BaseT1TestMode(Phy88q2112* dev, PhyTestMode* test_mode);
/// @ingroup phy88q2112_common_driver
/// @brief Set the SGMII output amplitude of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param value [uint16_t] The value to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112SetSgmiiOutputAmplitude(Phy88q2112* dev, uint16_t value);
/// @ingroup phy88q2112_common_driver
/// @brief Get the SGMII output amplitude of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param value [uint16_t*] The pointer to store the value
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112GetSgmiiOutputAmplitude(Phy88q2112* dev, uint16_t* value);
/// @ingroup phy88q2112_common_driver
/// @brief Set the counter control of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param bad_link [bool] Whether to enable bad link counter
/// @param rx_error [bool] Whether to enable rx error counter
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112SetCounterControl(Phy88q2112* dev, bool bad_link, bool rx_error);
/// @ingroup phy88q2112_common_driver
/// @brief Get the bad link counter of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param value [uint16_t*] The pointer to store the bad link counter value
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112GetBadLinkCounter(Phy88q2112* dev, uint16_t* value);
/// @ingroup phy88q2112_common_driver
/// @brief Get the bad SSD counter of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param value [uint16_t*] The pointer to store the bad SSD counter value
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112GetBadSsdCounter(Phy88q2112* dev, uint16_t* value);
/// @ingroup phy88q2112_common_driver
/// @brief Get the bad ESD counter of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param value [uint16_t*] The pointer to store the bad ESD counter value
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112GetBadEsdCounter(Phy88q2112* dev, uint16_t* value);
/// @ingroup phy88q2112_common_driver
/// @brief Get the RX error counter of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param value [uint16_t*] The pointer to store the RX error counter value
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112GetRxErrorCounter(Phy88q2112* dev, uint16_t* value);
/// @ingroup phy88q2112_common_driver
/// @brief Get the link drop counter of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param value [uint16_t*] The pointer to store the link drop counter value
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112GetLinkDropCounter(Phy88q2112* dev, uint16_t* value);
/// @ingroup phy88q2112_common_driver
/// @brief Enable or disable the packet counter of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param enable [bool] Whether to enable or disable the packet counter
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112EnablePacketCounter(Phy88q2112* dev, bool enable);
/// @ingroup phy88q2112_common_driver
/// @brief Start or stop the packet counter of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param start [bool] Whether to start or stop the packet counter
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112StartPacketCounter(Phy88q2112* dev, bool start);
/// @ingroup phy88q2112_common_driver
/// @brief Get the packet counter of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param crc_error [uint16_t*] The pointer to store the CRC error counter value
/// @param packet_counter [uint16_t*] The pointer to store the packet counter value
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112GetPacketCounter(Phy88q2112* dev, uint16_t* crc_error, uint16_t* packet_counter);
/// @ingroup phy88q2112_common_driver
/// @brief Reset the packet counter of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88q2112ResetPacketCounter(Phy88q2112* dev);
/// @ingroup phy88q2112_common_driver
/// @brief Read data from the phy88q2112 device using the specified device address and register address.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param dev_addr [uint8_t] The device address to read from
/// @param reg_addr [uint16_t] The register address to read from
/// @param value [uint16_t*] The pointer to store the read out value
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112Read(Phy88q2112* dev, uint8_t dev_addr, uint16_t reg_addr, uint16_t* value);
/// @ingroup phy88q2112_common_driver
/// @brief Write data to the phy88q2112 device using the specified device address and register address.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param dev_addr [uint8_t] The device address to write to
/// @param reg_addr [uint16_t] The register address to write to
/// @param value [uint16_t] The value to write
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112Write(Phy88q2112* dev, uint8_t dev_addr, uint16_t reg_addr, uint16_t value);
/// @ingroup phy88q2112_common_driver
/// @brief Get the SQI level of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param level [uint16_t*] The pointer to store the SQI level value
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88q2112GetSqiLevel(Phy88q2112* dev, uint16_t* level);
/// @ingroup phy88q2112_common_driver
/// @brief Get the SQI measurement of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @param value [uint16_t*] The pointer to store the SQI measurement value
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88q2112GetSqiMeasurement(Phy88q2112* dev, uint16_t* value);
/// @ingroup phy88q2112_common_driver
/// @brief Initialize for 1000 BASE-T1 for SingleSendS.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88q2112InitGeSingleSendS(Phy88q2112* dev);
/// @ingroup phy88q2112_common_driver
/// @brief // Initialize for 100 BASE-T1.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88q2112InitFe(Phy88q2112* dev);
/// @ingroup phy88q2112_common_driver
/// @brief Print the VCT value of the phy88q2112 device.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @return void
void Phy88Q2112PrintVctValue(Phy88q2112* dev);

/// @ingroup phy88q2112_common_driver
/// @brief Initialize the phy88q2112 device without hard reset.
/// @param dev [Phy88q2112*] The pointer to the phy88q2112 device struct
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode Phy88Q2112InitWithoutReset(Phy88q2112* dev);

#endif  // COMMON_DRIVER_PHY_PHY_88Q2112_H_
