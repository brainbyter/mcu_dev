// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_TLF35584_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_TLF35584_H_

#include "common/mcu/utils/status.h"
#include "platform/device/driver/infineon/tlf35584.h"

ReturnCode SetTlf35584Mode(Tlf35584StatusType mode);
void PrintTlf35584CurrentInfo(void);
ReturnCode DisableTlf35584StandbyQst(void);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_TLF35584_H_
