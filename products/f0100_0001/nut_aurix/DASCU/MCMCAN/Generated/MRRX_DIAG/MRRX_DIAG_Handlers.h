#ifndef MRRX_DIAG_HANDLERS_H
#define MRRX_DIAG_HANDLERS_H

#include <stdint.h>

/* DATA VEH INFO HANDLERS */
void DAS_VehInfo1_Handler(uint8_t *data, uint8_t dlc);
void DAS_VehInfo2_Handler(uint8_t *data, uint8_t dlc);
void DAS_VehInfo3_Handler(uint8_t *data, uint8_t dlc);

/* DIAG HANDLERS */
void DAS_SwitchCalibWave_Handler(uint8_t *data, uint8_t dlc);
void UDS_CALIB_RL_REQ_Handler(uint8_t *data, uint8_t dlc);
void UDS_CALIB_RL_RESP_Handler(uint8_t *data, uint8_t dlc);
void UDS_CALIB_RR_REQ_Handler(uint8_t *data, uint8_t dlc);
void UDS_CALIB_RR_RESP_Handler(uint8_t *data, uint8_t dlc);

#endif
