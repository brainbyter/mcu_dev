/*
 * CAN_CheckSums.h
 *
 *  Created on: 02 ���. 2020 �.
 *      Author: ivan.gerasimov
 */

#ifndef _CAN_CHECKSUMS_H_
#define _CAN_CHECKSUMS_H_

#include "Platform_Types.h"


uint8 CAN_CalculateXOR4(uint8* buffer_pu8, uint8 dlc_u8, uint8 bitpos_u8);
uint8 CAN_CalculateXOR8(uint8* buffer_pu8, uint8 dlc_u8, uint8 bitpos_u8);
uint8 CAN_CalculateCRC8(uint8* buffer_pu8, uint8 dlc, uint8 bitpos);



#endif /* _CAN_CHECKSUMS_H_ */
