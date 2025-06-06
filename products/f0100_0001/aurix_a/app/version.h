// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_VERSION_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_VERSION_H_

typedef enum ProductHwVersion {
  kHwVersionInvalid = 0,
  kHwVersionB100 = 1,
  kHwVersionB200R = 2,
  kHwVersionB200Mt = 3,
  kHwVersionB200Nut = 4,
} ProductHwVersion;

void PrintVersion(void);
ProductHwVersion GetHwVersion(void);

#endif  // PRODUCTS_F0100_0001_AURIX_A_APP_VERSION_H_
