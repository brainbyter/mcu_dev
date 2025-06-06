// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_APP_ORIN_FSI_WRAPPER_H_
#define PRODUCTS_F0100_0001_AURIX_A_APP_ORIN_FSI_WRAPPER_H_

typedef uint16_t SystemFailureId;
typedef uint8_t MaturationState;
typedef uint8_t FailureAttribute;
typedef uint16_t NvSehSeed;

typedef struct ErrorReportFrame {
  uint32_t error_code;
  uint32_t error_attribute;
  uint32_t timestamp;
  uint16_t reporter_id;
} ErrorReportFrame;

typedef struct NvSehCriticalFailure {
  ErrorReportFrame error_report_frame;
  SystemFailureId system_failure_id;
  MaturationState maturation_state;
} NvSehCriticalFailure;

typedef struct NvSehSmcuPeriodicStatus{
  SystemFailureId system_failure_id;
  MaturationState maturation_state;
  FailureAttribute failure_attribute;
} NvSehSmcuPeriodicStatus;

typedef struct NvSehSmcuPeriodicReport {
  NvSehSmcuPeriodicStatus failures[10];
  NvSehSeed key_of_seed;
} NvSehSmcuPeriodicReport;

#endif // PRODUCTS_F0100_0001_AURIX_A_APP_ORIN_FSI_WRAPPER_H_
