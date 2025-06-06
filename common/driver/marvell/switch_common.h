// Copyright @2021 Pony AI Inc. All rights reserved.

/// @defgroup switch_driver switch driver

/// @defgroup switch_common_driver marvell switch common driver
/// @ingroup switch_driver
/// This is marvell switch common driver.

/// @file
/// @ingroup switch_common_driver
/// @brief the header file for marvell switch common driver

#ifndef COMMON_DRIVER_MARVELL_SWITCH_COMMON_H_
#define COMMON_DRIVER_MARVELL_SWITCH_COMMON_H_

#include <stdbool.h>
#include <stdint.h>

#include "common/driver/marvell/switch_def.h"
#include "common/mcu/utils/status.h"

/// @ingroup switch_common_driver
/// @brief The structure of a Marvell switch device
typedef struct MarvellSwitch {
  /// The SMI address of the switch
  uint8_t address;
  /// The device number of the switch
  uint8_t dev_num;
  /// The name of the switch
  const char* name;
  /// The pointer to the SMI read function
  ReturnCode (*smi_read)(uint8_t slave_addr, uint8_t reg_addr, uint16_t* value, void* user_data);
  /// The pointer to the SMI write function
  ReturnCode (*smi_write)(uint8_t slave_addr, uint8_t reg_addr, uint16_t value, void* user_data);
  // Please follow 88q6113's Reset Timing to implement this function:
  //    As Marvell FAE recommend: Pull-down reset pin at least 50ms, and then pull up and wait more
  //                              than 50ms.
  /// The pointer to the hard reset function
  ReturnCode (*hard_reset)(void* user_data);
  /// The pointer to the user data
  void* user_data;
} MarvellSwitch;

// This function indirectly set the port mode through SMI for port 9 and port 10.
/// @ingroup switch_common_driver
/// @brief Configure the port mode of the Marvell switch device through SMI for port 9 and port 10.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_number [uint8_t] The port number to configure (9 or 10)
/// @param mode [SwitchPortMode] The port mode to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode ConfigSwitchPortMode(MarvellSwitch* dev, uint8_t port_number, SwitchPortMode mode);

/// @ingroup switch_common_driver
/// @brief Set the C mode of the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param mode [SwitchCMode] The C mode to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortCMode(MarvellSwitch* switch_dev, uint8_t port_num, SwitchCMode mode);

/// @ingroup switch_common_driver
/// @brief Add a VLAN entry to the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param vlan_id [uint16_t] The VLAN ID to add (1-4094)
/// @param nodes [SwitchPortVlanNode*] The pointer to the array of VLAN nodes
/// @param nodes_num [uint16_t] The number of VLAN nodes in the array
/// @param vlan_prio [SwitchVlanPri] The VLAN priority to set (0-7)
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SwitchAddVlanEntry(MarvellSwitch* switch_dev,
                              uint16_t vlan_id,
                              SwitchPortVlanNode* nodes,
                              uint16_t nodes_num,
                              SwitchVlanPri vlan_prio);

/// @ingroup switch_common_driver
/// @brief Print the RMU port mode of the Marvell switch device.
/// @param mode [uint16_t] The RMU port mode to print
/// @return void
void PrintSwitchRmuPortMode(uint16_t mode);

/// @ingroup switch_common_driver
/// @brief Soft reset the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to reset (0-10)
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SoftResetSwitchPort(MarvellSwitch* dev, uint8_t port_num);

/// @ingroup switch_common_driver
/// @brief Enable or disable the PHY RGMII RX timing of the specified port of the Marvell switch
/// device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param enable [bool] Whether to enable or disable the PHY RGMII RX timing
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode EnableSwitchPhyRgmiiRxTiming(MarvellSwitch* switch_dev, uint8_t port_num, bool enable);

/// @ingroup switch_common_driver
/// @brief Enable or disable the PHY RGMII TX timing of the specified port of the Marvell switch
/// device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param enable [bool] Whether to enable or disable the PHY RGMII TX timing
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode EnableSwitchPhyRgmiiTxTiming(MarvellSwitch* switch_dev, uint8_t port_num, bool enable);

/// @ingroup switch_common_driver
/// @brief Set a register field of the Marvell switch device using SMI.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param reg_addr [uint8_t] The register address to set
/// @param field_offset [uint8_t] The field offset in the register
/// @param field_len [uint8_t] The field length in bits
/// @param data [uint16_t] The data to set in the field
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchRegField(MarvellSwitch* switch_dev,
                             uint8_t port_num,
                             uint8_t reg_addr,
                             uint8_t field_offset,
                             uint8_t field_len,
                             uint16_t data);

/// @ingroup switch_common_driver
/// @brief Get a register field of the Marvell switch device using SMI.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to get (0-10)
/// @param reg_addr [uint8_t] The register address to get
/// @param field_offset [uint8_t] The field offset in the register
/// @param field_len [uint8_t] The field length in bits
/// @param data [uint16_t*] The pointer to store the data in the field
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchRegField(MarvellSwitch* switch_dev,
                             uint8_t port_num,
                             uint8_t reg_addr,
                             uint8_t field_offset,
                             uint8_t field_len,
                             uint16_t* data);

/// @ingroup switch_common_driver
/// @brief Set a PHY register of the Marvell switch device using SMI clause 45.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param phy_addr [uint8_t] The PHY address to set (0-31)
/// @param dev_addr [uint8_t] The device address to set (0-31)
/// @param reg_addr [uint16_t] The register address to set (0-65535)
/// @param data [uint16_t] The data to set in the register
/// @param is_ext [bool] Whether the register is extended or not
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchSmiClause45PhyReg(MarvellSwitch* dev,
                                      uint8_t phy_addr,
                                      uint8_t dev_addr,
                                      uint16_t reg_addr,
                                      uint16_t data,
                                      bool is_ext);

/// @ingroup switch_common_driver
/// @brief Get a PHY register of the Marvell switch device using SMI clause 45.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param phy_addr [uint8_t] The PHY address to get (0-31)
/// @param dev_addr [uint8_t] The device address to get (0-31)
/// @param reg_addr [uint16_t] The register address to get (0-65535)
/// @param data [uint16_t*] The pointer to store the data in the register
/// @param is_ext [bool] Whether the register is extended or not
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchSmiClause45PhyReg(MarvellSwitch* dev,
                                      uint8_t phy_addr,
                                      uint8_t dev_addr,
                                      uint16_t reg_addr,
                                      uint16_t* data,
                                      bool is_ext);

/// @ingroup switch_common_driver
/// @brief Get the PHY detect status of the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to get (0-10)
/// @param status [bool*] The pointer to store the PHY detect status
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchPhyDetect(MarvellSwitch* switch_dev, uint8_t port_num, bool* status);

/// @ingroup switch_common_driver
/// @brief Set the PHY detect status of the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param status [bool] The PHY detect status to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPhyDetect(MarvellSwitch* switch_dev, uint8_t port_num, bool status);

/// @ingroup switch_common_driver
/// @brief Get the port link status of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint32_t] The port number to get (0-10)
/// @param state [bool*] The pointer to store the port link status
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchPortLinkStatus(MarvellSwitch* dev, uint32_t port_num, bool* state);

/// @ingroup switch_common_driver
/// @brief Set the port state of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_number [uint8_t] The port number to set (0-10)
/// @param state [SwitchPortState] The port state to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortState(MarvellSwitch* dev, uint8_t port_number, SwitchPortState state);

/// @ingroup switch_common_driver
/// @brief Get the port state of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_number [uint8_t] The port number to get (0-10)
/// @param state [SwitchPortState*] The pointer to store the port state
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchPortState(MarvellSwitch* dev, uint8_t port_number, SwitchPortState* state);

/// @ingroup switch_common_driver
/// @brief Delete all VLAN entries of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode DeleteSwitchAllVlans(MarvellSwitch* switch_dev);

/// @ingroup switch_common_driver
/// @brief Get the port speed of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint32_t] The port number to get (0-10)
/// @param speed [SwitchPortSpeed*] The pointer to store the port speed
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchPortSpeed(MarvellSwitch* dev, uint32_t port_num, SwitchPortSpeed* speed);

/// @ingroup switch_common_driver
/// @brief Set the port speed of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint32_t] The port number to set (0-10)
/// @param speed [SwitchPortSpeed] The port speed to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortSpeed(MarvellSwitch* dev, uint32_t port_num, SwitchPortSpeed speed);

/// @ingroup switch_common_driver
/// @brief Get the port duplex mode of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to get (0-10)
/// @param get_mode [SwitchPortDuplexMode*] The pointer to store the port duplex mode
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchPortDuplexMode(MarvellSwitch* switch_dev,
                                   uint8_t port_num,
                                   SwitchPortDuplexMode* get_mode);

/// @ingroup switch_common_driver
/// @brief Set the port duplex mode of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to get (0-10)
/// @param set_mode [SwitchPortDuplexMode] The port duplex mode to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortDuplexMode(MarvellSwitch* switch_dev,
                                   uint8_t port_num,
                                   SwitchPortDuplexMode set_mode);

/// @ingroup switch_common_driver
/// @brief Get a PHY register of the Marvell switch device using SMI extension.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param dev_addr [uint8_t] The device address to get
/// @param reg_addr [uint8_t] The register address to get
/// @param data [uint16_t*] The pointer to store the data in the register
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchSmiExtPhyReg(MarvellSwitch* switch_dev,
                                 uint8_t dev_addr,
                                 uint8_t reg_addr,
                                 uint16_t* data);

/// @ingroup switch_common_driver
/// @brief Set a PHY register of the Marvell switch device using SMI extension.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param dev_addr [uint8_t] The device address to set
/// @param reg_addr [uint8_t] The register address to set
/// @param data [uint16_t] The data to set in the register
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchSmiExtPhyReg(MarvellSwitch* switch_dev,
                                 uint8_t dev_addr,
                                 uint8_t reg_addr,
                                 uint16_t data);

/// @ingroup switch_common_driver
/// @brief Add a VLAN entry to the Marvell switch device with UMSD (User Mode Switch Driver).
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param vlan_id [uint16_t] The VLAN ID to add (1-4094)
/// @param nodes [SwitchPortVlanNode*] The pointer to the array of VLAN nodes
/// @param nodes_num [uint16_t] The number of VLAN nodes in the array
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SwitchCommonAddVlanEntryWithUmsd(MarvellSwitch* switch_dev,
                                            uint16_t vlan_id,
                                            SwitchPortVlanNode* nodes,
                                            uint16_t nodes_num);

/// @ingroup switch_common_driver
/// @brief Set the 802.1Q mode of the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param mode [SwitchPort8021qMode] The 802.1Q mode to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPort8021qMode(MarvellSwitch* switch_dev,
                                  uint8_t port_num,
                                  SwitchPort8021qMode mode);

/// @ingroup switch_common_driver
/// @brief Set the egress mode of the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param mode [SwitchPortEgressMode] The egress mode to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortEgressMode(MarvellSwitch* switch_dev,
                                   uint8_t port_num,
                                   SwitchPortEgressMode mode);

/// @ingroup switch_common_driver
/// @brief Set the default VLAN ID of the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param vlan_id [uint16_t] The default VLAN ID to set (1-4094)
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortDefaultVlanId(MarvellSwitch* switch_dev,
                                      uint8_t port_num,
                                      uint16_t vlan_id);

/// @ingroup switch_common_driver
/// @brief Set the VTU priority override of the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param override [SwitchPortVtuPrioOverride] The VTU priority override to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortVTUPrioOverride(MarvellSwitch* switch_dev,
                                        uint8_t port_num,
                                        SwitchPortVtuPrioOverride override);

/// @ingroup switch_common_driver
/// @brief Set the default priority of the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param vlan_prio [SwitchVlanPri] The default priority to set (0-7)
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortDefaultPri(MarvellSwitch* switch_dev,
                                   uint8_t port_num,
                                   SwitchVlanPri vlan_prio);

/// @ingroup switch_common_driver
/// @brief Set the force default VLAN ID of the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param en [bool] Whether to enable or disable the force default VLAN ID
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortForceDefaultVlanId(MarvellSwitch* switch_dev, uint8_t port_num, bool en);

/// @ingroup switch_common_driver
/// @brief Set the allow VID zero set of the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param en [bool] Whether to enable or disable the allow VID zero set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortAllowVidZeroSet(MarvellSwitch* switch_dev, uint8_t port_num, bool en);

/// @ingroup switch_common_driver
/// @brief Set the queue control port schedule of the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param mode [SwitchPortSchedMode] The queue control port schedule mode to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchQueueControlPortSchedule(MarvellSwitch* switch_dev,
                                             uint8_t port_num,
                                             SwitchPortSchedMode mode);

/// @ingroup switch_common_driver
/// @brief Get the queue control port schedule mode of the specified port of the Marvell switch
/// device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to get (0-10)
/// @param mode [SwitchPortSchedMode*] The pointer to store the queue control port schedule mode
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchQueueControlPortSchedule(MarvellSwitch* switch_dev,
                                             uint8_t port_num,
                                             SwitchPortSchedMode* mode);

/// @ingroup switch_common_driver
/// @brief Set the port learn enable of the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param enable [bool] Whether to enable or disable the port learn
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortLearnEnable(MarvellSwitch* switch_dev, uint8_t port_num, bool enable);

/// @ingroup switch_common_driver
/// @brief Get the port learn enable of the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to get (0-10)
/// @param enable [bool*] The pointer to store the port learn enable status
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchPortLearnEnable(MarvellSwitch* switch_dev, uint8_t port_num, bool* enable);

/// @ingroup switch_common_driver
/// @brief Set the discard error FCS message of the specified port of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchDiscardErrorFCSMsg(MarvellSwitch* switch_dev, uint8_t port_num);

/// @ingroup switch_common_driver
/// @brief Flush all MAC address entries of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param cmd [SwitchFlashMacAddrCmd] The flush command to execute
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode FlushSwitchAllMacAddress(MarvellSwitch* switch_dev, SwitchFlashMacAddrCmd cmd);

/// @ingroup switch_common_driver
/// @brief Set the port MTU size of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param size [SwitchPortMtuSize] The port MTU size to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortMtu(MarvellSwitch* switch_dev, uint8_t port_num, SwitchPortMtuSize size);

/// @ingroup switch_common_driver
/// @brief Get the port MTU size of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to get (0-10)
/// @param size [SwitchPortMtuSize*] The pointer to store the port MTU size
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchPortMtu(MarvellSwitch* switch_dev, uint8_t port_num, SwitchPortMtuSize* size);

/// @ingroup switch_common_driver
/// @brief Set the port interrupt on age out of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param enable [bool] Whether to enable or disable the port interrupt on age out
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortIntOnAgeOut(MarvellSwitch* switch_dev, uint8_t port_num, bool enable);

/// @ingroup switch_common_driver
/// @brief Get the port interrupt enable on age out of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to get (0-10)
/// @param enable [bool*] The pointer to store the port interrupt on age out enable status
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchPortIntOnAgeOut(MarvellSwitch* switch_dev, uint8_t port_num, bool* enable);
// Sets the timeout period in milliseconds for aging out dynamically learned
// forwarding information. The standard recommends 300 sec.
// Set timeout to '0' means will never age out.

/// @ingroup switch_common_driver
/// @brief Set the aging timeout of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param milliseconds [uint32_t] The timeout period in milliseconds for aging out dynamically
/// learned forwarding information. The standard recommends 300 sec. Set timeout to '0' means will
/// never age out.
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchAgingTimeout(MarvellSwitch* dev, uint32_t milliseconds);

/// @ingroup switch_common_driver
/// @brief Get the aging timeout of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param timeout [uint32_t*] The pointer to store the timeout period in milliseconds for aging out
/// dynamically learned forwarding information. The standard recommends 300 sec. Set timeout to '0'
/// means will never age out.
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchAgingTimeout(MarvellSwitch* switch_dev, uint32_t* timeout);

/// @ingroup switch_common_driver
/// @brief Set the port flow control enable of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param enable [bool] Whether to enable or disable the port flow control
/// @param mode [SwitchPortFcMode] The port flow control mode to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortFlowControlEnable(MarvellSwitch* switch_dev,
                                          uint8_t port_num,
                                          bool enable,
                                          SwitchPortFcMode mode);

/// @ingroup switch_common_driver
/// @brief Get the port flow control enable of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to get (0-10)
/// @param enable [bool*] The pointer to store the port flow control enable status
/// @param mode [SwitchPortFcMode*] The pointer to store the port flow control mode
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchPortFlowControlEnable(MarvellSwitch* switch_dev,
                                          uint8_t port_num,
                                          bool* enable,
                                          SwitchPortFcMode* mode);
// fid: ATU MAC Address Database Number
// ATU MAC Address Database number. If multiple address
// databases are not being used, fid should be zero.
// If multiple address databases are being used, this value
// should be set to the desired address database number.
/// @ingroup switch_common_driver
/// @brief Add a static MAC entry to the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to add (0-10)
/// @param mac_address [uint8_t*] The pointer to the MAC address to add
/// @param is_trunk [bool] Whether the port is a trunk port or not
/// @param fid [uint16_t] The ATU MAC Address Database number
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode AddSwitchStaticMacEntry(
    MarvellSwitch* switch_dev, uint8_t port_num, uint8_t* mac_address, bool is_trunk, uint16_t fid);

/// @ingroup switch_common_driver
/// @brief Delete a MAC entry from the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param mac_address [uint8_t*] The pointer to the MAC address to delete
/// @param fid [uint16_t] The ATU MAC Address Database number
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode DeleteSwitchMacEntry(MarvellSwitch* switch_dev, uint8_t* mac_address, uint16_t fid);

/// @ingroup switch_common_driver
/// @brief Get the latest violation MAC entry from the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t*] The pointer to store the port number of the violation entry (0-10)
/// @param fid [uint16_t*] The pointer to store the ATU MAC Address Database number of the violation
/// entry
/// @param mac_address [uint8_t*] The pointer to store the MAC address of the violation entry
/// @param cause [SwitchAtuViolationCause*] The pointer to store the cause of the violation entry
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchViolationMacEntry(MarvellSwitch* switch_dev,
                                      uint8_t* port_num,
                                      uint16_t* fid,
                                      uint8_t* mac_address,
                                      SwitchAtuViolationCause* cause);

/// @ingroup switch_common_driver
/// @brief Get the total number of MAC entries in the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param is_non_static [bool] Whether to count only non-static entries or all entries
/// @param count [uint32_t*] The pointer to store the total number of MAC entries
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchAllMacEntryCount(MarvellSwitch* switch_dev,
                                     bool is_non_static,
                                     uint32_t* count);

/// @ingroup switch_common_driver
/// @brief Set the system ingress monitor destination port of the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set as the system ingress monitor destination
/// (0-10)
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchSysIngressMonitorDest(MarvellSwitch* switch_dev, uint8_t port_num);

/// @ingroup switch_common_driver
/// @brief Get the system ingress monitor destination port of the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t*] The pointer to store the port number of the system ingress monitor
/// destination (0-10)
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchSysIngressMonitorDest(MarvellSwitch* switch_dev, uint8_t* port_num);

/// @ingroup switch_common_driver
/// @brief Set the system egress monitor destination port of the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set as the system egress monitor destination (0-10)
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchSysEgressMonitorDest(MarvellSwitch* switch_dev, uint8_t port_num);

/// @ingroup switch_common_driver
/// @brief Get the system egress monitor destination port of the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t*] The pointer to store the port number of the system egress monitor
/// destination (0-10)
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchSysEgressMonitorDest(MarvellSwitch* switch_dev, uint8_t* port_num);

/// @ingroup switch_common_driver
/// @brief Set the port egress monitor source enable status of the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param enable [bool] Whether to enable or disable the port egress monitor source
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortEgressMonitorSourceEnable(MarvellSwitch* switch_dev,
                                                  uint8_t port_num,
                                                  bool enable);

/// @ingroup switch_common_driver
/// @brief Set the port ingress monitor source enable status of the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param enable [bool] Whether to enable or disable the port ingress monitor source
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortIngressMonitorSourceEnable(MarvellSwitch* switch_dev,
                                                   uint8_t port_num,
                                                   bool enable);

/// @ingroup switch_common_driver
/// @brief Get the port egress monitor source enable status of the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to get (0-10)
/// @param enable [bool*] The pointer to store the port egress monitor source enable status
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchPortEgressMonitorSourceEnable(MarvellSwitch* switch_dev,
                                                  uint8_t port_num,
                                                  bool* enable);

/// @ingroup switch_common_driver
/// @brief Get the port ingress monitor source enable status of the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to get (0-10)
/// @param enable [bool*] The pointer to store the port ingress monitor source enable status
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchPortIngressMonitorSourceEnable(MarvellSwitch* switch_dev,
                                                   uint8_t port_num,
                                                   bool* enable);

/// @ingroup switch_common_driver
/// @brief Print a MAC entry from the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param fid [uint32_t] The ATU MAC Address Database number of the MAC entry to print
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode PrintSwitchMacEntry(MarvellSwitch* switch_dev, uint32_t fid);

// Pcp map to both Fpri and Qpri
/// @ingroup switch_common_driver
/// @brief Set the QoS PCP to FPRI and QPRI mapping of the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param qpri_list [uint8_t[8]] The array of QPRI values maped for each PCP value (0-7)
/// @param fpri_list [uint8_t[8]] The array of FPRI values maped for each PCP value (0-7)
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchQosPcpToFpriQpriMap(MarvellSwitch* switch_dev,
                                        uint8_t port_num,
                                        uint8_t qpri_list[8],
                                        uint8_t fpri_list[8]);

/// @ingroup switch_common_driver
/// @brief Set the QoS PCP to QPRI mapping of the Marvell switch device and disable FPRI mapping.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param qpri_list [uint8_t[8]] The array of QPRI values maped for each PCP value (0-7)
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchQosPcpToQpriMap(MarvellSwitch* switch_dev,
                                    uint8_t port_num,
                                    uint8_t qpri_list[8]);

/// @ingroup switch_common_driver
/// @brief Set the QoS PCP to FPRI mapping of the Marvell switch device and disable QPRI mapping.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param fpri_list [uint8_t[8]] The array of FPRI values maped for each PCP value (0-7)
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchQosPcpToFpriMap(MarvellSwitch* switch_dev,
                                    uint8_t port_num,
                                    uint8_t fpri_list[8]);

/// @ingroup switch_common_driver
/// @brief Set the port frame mode of the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to set (0-10)
/// @param frame_mode [SwitchPortFrameMode] The frame mode to set
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchPortFrameMode(MarvellSwitch* switch_dev,
                                  uint8_t port_num,
                                  SwitchPortFrameMode frame_mode);
// RMU Port 1  -> mode 0
// RMU Port 7  -> mode 1
// RMU Port 8  -> mode 2
// RMU Port 9  -> mode 3
// RMU disable -> mode 7

/// @ingroup switch_common_driver
/// @brief Get the RMU mode of the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param mode [uint16_t*] The pointer to store the RMU mode of the switch device
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode GetSwitchRmuMode(MarvellSwitch* switch_dev, uint16_t* mode);

/// @ingroup switch_common_driver
/// @brief Set the RMU mode of the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param mode [uint16_t] The RMU mode to set for the switch device
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode SetSwitchRmuMode(MarvellSwitch* switch_dev, uint16_t mode);

/// @ingroup switch_common_driver
/// @brief Reset the PTP timestamp of the Marvell switch device.
/// @param switch_dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to reset (0-10)
/// @param time_to_reset [uint8_t] The time to reset in seconds
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode ResetSwitchPtpTimestamp(MarvellSwitch* switch_dev,
                                   uint8_t port_num,
                                   uint8_t time_to_reset);

/// @ingroup switch_common_driver
/// @brief Get the port number of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @return uint32_t: The port number of the switch device
uint32_t GetSwitchPortNum(MarvellSwitch* dev);

/// @ingroup switch_common_driver
/// @brief Get the port counters of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param port_num [uint8_t] The port number to get (0-10)
/// @param in_good [uint64_t*] The pointer to store the number of good frames received on the port
/// @param in_bad [uint64_t*] The pointer to store the number of bad frames received on the port
/// @param out_good [uint64_t*] The pointer to store the number of good frames transmitted on the
/// port
/// @param out_bad [uint64_t*] The pointer to store the number of bad frames transmitted on the port
void GetSwitchPortCounters(MarvellSwitch* dev,
                           uint8_t port_num,
                           uint64_t* in_good,
                           uint64_t* in_bad,
                           uint64_t* out_good,
                           uint64_t* out_bad);

/// @ingroup switch_common_driver
/// @brief Print the common counters of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
void PrintCommonCounters(MarvellSwitch* dev);

/// @ingroup switch_common_driver
/// @brief Print the common status of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
void PrintCommonStatus(MarvellSwitch* dev);

/// @ingroup switch_common_driver
/// @brief Initialize the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode InitSwitch(MarvellSwitch* dev);

/// @ingroup switch_common_driver
/// @brief Initialize the Marvell switch device without hard reset.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode InitSwitchWithoutReset(MarvellSwitch* dev);

/// @ingroup switch_common_driver
/// @brief Deinitialize the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @return ReturnCode: if succeed, return ERROR_OK.
ReturnCode DeInitSwitch(MarvellSwitch* dev);

/// @ingroup switch_common_driver
/// @brief Set a Misc register of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param index [int] The index of the Misc register to set
/// @param value [int] The value to set for the Misc register
void SetSwitchMiscRegister(MarvellSwitch* dev, int index, int value);

/// @ingroup switch_common_driver
/// @brief Set a register of the Marvell switch device.
/// @param dev [MarvellSwitch*] The pointer to the Marvell switch device struct
/// @param address [uint8_t] The address of the register to set
/// @param value [uint16_t] The value to set for the register
void SetSwitchRegister(MarvellSwitch* dev, uint8_t address, uint16_t value);

#endif  // COMMON_DRIVER_MARVELL_SWITCH_COMMON_H_
