/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.1 */

#ifndef PB_PLATFORM_ETHERNET_PHY_GENERAL_PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_PROTO_PHY_GENERAL_CFG_PB_H_INCLUDED
#define PB_PLATFORM_ETHERNET_PHY_GENERAL_PLATFORM_DEVICE_DRIVER_ETHERNET_MANAGER_PROTO_PHY_GENERAL_CFG_PB_H_INCLUDED
#include <pb.h>
#include "platform/device/driver/ethernet_manager/proto/common.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _platform_ethernet_phy_general_EthPhyRoleType {
    platform_ethernet_phy_general_EthPhyRoleType_ETH_PHY_ROLE_UNKNOWN = 0,
    platform_ethernet_phy_general_EthPhyRoleType_ETH_PHY_ROLE_SLAVE = 1,
    platform_ethernet_phy_general_EthPhyRoleType_ETH_PHY_ROLE_MASTER = 2
} platform_ethernet_phy_general_EthPhyRoleType;

/* Struct definitions */
typedef struct _platform_ethernet_phy_general_EthPhyGeneral {
    bool has_speed;
    platform_ethernet_common_EthSpeedType speed;
    bool has_role;
    platform_ethernet_phy_general_EthPhyRoleType role;
} platform_ethernet_phy_general_EthPhyGeneral;


/* Helper constants for enums */
#define _platform_ethernet_phy_general_EthPhyRoleType_MIN platform_ethernet_phy_general_EthPhyRoleType_ETH_PHY_ROLE_UNKNOWN
#define _platform_ethernet_phy_general_EthPhyRoleType_MAX platform_ethernet_phy_general_EthPhyRoleType_ETH_PHY_ROLE_MASTER
#define _platform_ethernet_phy_general_EthPhyRoleType_ARRAYSIZE ((platform_ethernet_phy_general_EthPhyRoleType)(platform_ethernet_phy_general_EthPhyRoleType_ETH_PHY_ROLE_MASTER+1))


/* Initializer values for message structs */
#define platform_ethernet_phy_general_EthPhyGeneral_init_default {false, _platform_ethernet_common_EthSpeedType_MIN, false, _platform_ethernet_phy_general_EthPhyRoleType_MIN}
#define platform_ethernet_phy_general_EthPhyGeneral_init_zero {false, _platform_ethernet_common_EthSpeedType_MIN, false, _platform_ethernet_phy_general_EthPhyRoleType_MIN}

/* Field tags (for use in manual encoding/decoding) */
#define platform_ethernet_phy_general_EthPhyGeneral_speed_tag 1
#define platform_ethernet_phy_general_EthPhyGeneral_role_tag 2

/* Struct field encoding specification for nanopb */
#define platform_ethernet_phy_general_EthPhyGeneral_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UENUM,    speed,             1) \
X(a, STATIC,   OPTIONAL, UENUM,    role,              2)
#define platform_ethernet_phy_general_EthPhyGeneral_CALLBACK NULL
#define platform_ethernet_phy_general_EthPhyGeneral_DEFAULT NULL

extern const pb_msgdesc_t platform_ethernet_phy_general_EthPhyGeneral_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define platform_ethernet_phy_general_EthPhyGeneral_fields &platform_ethernet_phy_general_EthPhyGeneral_msg

/* Maximum encoded size of messages (where known) */
#define platform_ethernet_phy_general_EthPhyGeneral_size 4

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
