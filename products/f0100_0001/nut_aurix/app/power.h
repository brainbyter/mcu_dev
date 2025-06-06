// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_NUT_AURIX_APP_POWER_H_
#define PRODUCTS_F0100_0001_NUT_AURIX_APP_POWER_H_

#include "common/mcu/utils/status.h"

typedef enum
{
	pwr_idle_state,
	pwr_reset_state,
	pwr_turnon_state,
	pwr_turnoff_state
} pwr_state_t;

typedef struct
{
	pwr_state_t pwr_state;
	unsigned int currTick;
} pwr_awu_mode_t;

extern pwr_awu_mode_t pwr_awu_mode;

typedef enum PowerControlStage {
  kPowerControlInit,
  kPowerControlStep1,
  kPowerControlStep2,
  kPowerControlStep3,
  kPowerControlStep4,
  kPowerControlStep5,
  kPowerControlStep6,
  kPowerDownControlStep1,
  kPowerDownControlStep2,
  kPowerDownControlStep3,
  kPowerDownControlStep4,
  kPowerDownControlSleepStep5,
  kPowerDownControlStandbyStep5,
} PowerControlStage;

ReturnCode SetPowerControlStage(PowerControlStage target_stage);
void PowerOnSystem(void);
ReturnCode PowerdownSystem(PowerControlStage stage);
void CheckAllPgChannel(void);
ReturnCode SetPowerSystemSleep(void);
ReturnCode SetPowerSystemStandby(void);
ReturnCode ForceOrinAInRecovery(bool en);
ReturnCode PowerOnOrinA(void);
ReturnCode PowerOffOrinA(void);
ReturnCode ResetOrinA(void);
ReturnCode SetTja1145Sleep(void);

ReturnCode SetOrinABootChainToSlotA(void);
ReturnCode SetOrinABootChainToSlotB(void);

#ifdef BOOTCHAIN_SDK_DISABLE
// bootchain = 0 : set orin into slotA
// bootchain = 1 : set orin into slotB
ReturnCode SetOrinBootChain(uint8_t bootchain);
#endif // BOOTCHAIN_SDK_DISABLE

ReturnCode InitVoltageCurrentSensors(void);
void PrintVoltageChannels(void);
void PrintMax20087RegValue(void);
#ifndef  ELMOS_SDK_DISABLE
ReturnCode VerifyAllSensorsAssignAddress(void);
#endif

#endif  // PRODUCTS_F0100_0001_NUT_AURIX_APP_POWER_H_
