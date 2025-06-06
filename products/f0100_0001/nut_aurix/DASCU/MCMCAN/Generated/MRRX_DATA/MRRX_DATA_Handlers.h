#ifndef MRRX_DATA_HANDLERS_H
#define MRRX_DATA_HANDLERS_H
/*File generated by NAMI Standart Code generator 1.0.2
 from file RR1CANFD_2024_06_13 (!).dbc
 13.06.2024 16:19:31*/
#include <stdint.h>

extern void Obj_0_Status_RL_Handler(uint8_t *data, uint8_t dlc);
extern void RightRadarSynMessage_Handler(uint8_t *data, uint8_t dlc);
extern void LeftRadarSynMessage_Handler(uint8_t *data, uint8_t dlc);
extern void VehInfo_Left_Radar_Handler(uint8_t *data, uint8_t dlc);
extern void VehInfo_Right_Radar_Handler(uint8_t *data, uint8_t dlc);
extern void Monitor_Time_L_1_Handler(uint8_t *data, uint8_t dlc);
extern void Monitor_Time_R_1_Handler(uint8_t *data, uint8_t dlc);
extern void Monitor_Time_L_2_Handler(uint8_t *data, uint8_t dlc);
extern void Monitor_Time_R_2_Handler(uint8_t *data, uint8_t dlc);
extern void Obj_End_Msg_RR_Handler(uint8_t *data, uint8_t dlc);
extern void Obj_End_Msg_RL_Handler(uint8_t *data, uint8_t dlc);
extern void Obj_Quality_Info_RR_Handler(uint8_t *data, uint8_t dlc);
extern void Obj_General_Info_RR_Handler(uint8_t *data, uint8_t dlc);
extern void Obj_Extended_Info_RR_Handler(uint8_t *data, uint8_t dlc);
extern void Obj_Collision_Info_RR_Handler(uint8_t *data, uint8_t dlc);
extern void Obj_0_Status_RR_Handler(uint8_t *data, uint8_t dlc);
extern void Obj_Collision_Info_RL_Handler(uint8_t *data, uint8_t dlc);
extern void Obj_Extended_Info_RL_Handler(uint8_t *data, uint8_t dlc);
extern void Obj_Quality_Info_RL_Handler(uint8_t *data, uint8_t dlc);
extern void Radar_Rear_ADAS_Handler(uint8_t *data, uint8_t dlc);
extern void Obj_General_Info_RL_Handler(uint8_t *data, uint8_t dlc);
#endif
