/*
 * CAN_Private.h
 *
 *  Created on: 28 ���. 2020 �.
 *      Author: ivan.gerasimov
 */

#ifndef _CAN_PRIVATE_H_
#define _CAN_PRIVATE_H_

#include "DASCU/MCMCAN/MCMCAN.h"
#include <Generated/CAN.h>
#include <CAN_Typedefs.h>
#include <CAN_Extern.h>
#include <ADASCANFD_Vars.h>
#include <ADASCANFD_Handlers.h>
#include <ADASCANFD_MessageObjects.h>
#include <CAN_Defaults.h>
#include <CAN_Handlers.h>
#include <CAN_CheckSums.h>
#include <Framemonitor.h>
#include <FD_Vars.h>
#include <FD_MessageObjects.h>
#include <FD_Handlers.h>
#include <FD_MessageObjects.h>
#include <MRRX_DIAG_Handlers.h>
#include <MRRX_DIAG_MessageObjects.h>
#include <MRRX_DIAG_IDs.h>
#include <MRRX_DATA_Handlers.h>
#include <MRRX_DATA_MessageObjects.h>
#include <MRRX_DATA_IDs.h>
#include <HAVAL_Handlers.h>
#include <HAVAL_MessageObjects.h>
#include <HAVAL_IDs.h>
#include <XCPCAN_Handlers.h>
#include <XCPCAN_MessageObjects.h>
#include <XCPCAN_IDs.h>
#include <Adas.h>
#include <DiagVars.h>
#include <CAN_Mapping.h>

#include <CAN_PostSettings.h>
//#include <DiagMrr_typedefs.h>

#include "IfxCan_Can.h"
#include "bsp_can.h"
#include "f0100_03_0001_aurix_driver.h"

#include <UDP_Extern.h>
#include <UdpMessageObjects.h>
#include <sw_version.h>

#define M_PI 3.1415926535897932384626433832

extern CANNetwork_t CAN_Networks[];
extern const uint8 CAN_MAX_NETWORKS;
extern CanMessageObject_t* lastMessageObject;
extern CanMessageObject_t* lastMessageObjectAurus;
extern CanMessageObject_t* lastMessageObjectHaval;
extern CanMessageObject_t* lastMessageObjectMrrxData;
extern CanMessageObject_t* lastMessageObjectMrrxDiag;
extern CanMessageObject_t* lastMessageObjectDebug;
extern CanMessageObject_t* lastMessageObjectXcp;

extern can_filter_item g_adas_filter_for_reset_items[2];
extern can_filter_config_t g_adas_filter_for_reset_config;

extern can_filter_item g_adas_filter_items[ADAS_MAX_RX_FILTER];
extern can_filter_config_t g_adas_filter_config;

extern can_filter_item g_test_adas_filter_items[DEBUG_ADAS_MAX_RX_FILTER];
extern can_filter_config_t g_test_adas_filter_config;

extern can_filter_item g_mrrx_diag_items[MRRX_DIAG_MAX_RX_FILTER];
extern can_filter_config_t g_mrrx_diag_filter_config;

extern can_filter_item g_mrrx_data_items[MRRX_DATA_MAX_RX_FILTER];
extern can_filter_config_t g_mrrx_data_filter_config;

extern can_filter_item g_haval_items[HAVAL_MAX_RX_FILTER];
extern can_filter_config_t g_haval_filter_config;

extern can_filter_item g_xcp_items[XCP_MAX_RX_FILTER];
extern can_filter_config_t g_xcp_filter_config;

void SetCANTXEn(CANNetworkID_t node, boolean enable);
void SetCANRXEn(CANNetworkID_t node, boolean enable);
void CAN_NetworkManagement();
void CAN_InitMessageObject(CanMessageObject_t *messageObj);
extern void CAN_InitMessageObjects();

boolean IsUDSMessageObject(CanMessageObject_t* messageObject);

void CAN_ReceiveSdkFrameAdas(CanMessageObject_t* messageObj);
#ifdef HW_DEBUG
void CAN_ReceiveSdkFrameTestAdas(CanMessageObject_t* messageObj);
#endif
void CAN_TransmitFrame(CanMessageObject_t* messageObj, uint8* data);
extern int DEBUG_CAN(uint16 can_device, can_msg_t *can_msg);

extern void CAN_InitRxDascuIdItems();

#ifdef SW_AURUS
extern void CAN_InitRxAdasFilters();
#endif
#ifdef SW_HAVAL
extern void CAN_InitRxHavalFilters();
#endif
extern void CAN_InitRxMrrxDataFilters();
extern void CAN_InitRxMrrxDiagFilters();
#ifdef HW_DEBUG
extern void CAN_InitRxTestAdasFilters();
#ifdef SW_AURUS
extern void CAN_InitRxXcpFilters();
#endif
#endif


#endif
