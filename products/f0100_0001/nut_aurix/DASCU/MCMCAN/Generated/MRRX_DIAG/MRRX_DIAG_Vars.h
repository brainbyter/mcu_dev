#ifndef MRRX_DIAG_VARS_H
#define MRRX_DIAG_VARS_H

#include <Platform_Types.h>
#include <stdint.h>

extern uint8_t IGN_State_V;
extern uint8_t IGN_State;
extern uint8_t GEAR_STA_NOW_V;
extern uint8_t GEAR_STATE_NOW;
extern uint8_t VehSpeed_V;
extern float YawRate_IN;
extern uint32_t YawRate_IN_Raw;
extern uint8_t YawRate_IN_UseRaw;
extern uint8_t YawRat_V;
extern float VehSpeed_IN;
extern uint32_t VehSpeed_IN_Raw;
extern uint8_t VehSpeed_IN_UseRaw;
extern uint8_t Str_Angle_V;
extern float Str_Angle;
extern uint32_t Str_Angle_Raw;
extern uint8_t Str_Angle_UseRaw;
extern uint8_t RightTurnSWSts;
extern uint8_t LeftTurnSWSts;
extern uint8_t RRDoorSts;
extern uint8_t PassengerDoorSts;
extern uint8_t RLDoorSts;
extern uint8_t DriverDoorSts;
extern uint8_t LockSts;

#endif
