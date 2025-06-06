/*
 * File: zero_crossing_types.h
 *
 * Code generated for Simulink model 'VLCforADAS_UMP'.
 *
 * Model version                  : 1.850
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Mon Apr  1 17:55:13 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->TMS570 Cortex-R4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef ZERO_CROSSING_TYPES_H
#define ZERO_CROSSING_TYPES_H
#include "rtwtypes.h"

/* Trigger directions: falling, either, and rising */
typedef enum {
  FALLING_ZERO_CROSSING = -1,
  ANY_ZERO_CROSSING = 0,
  RISING_ZERO_CROSSING = 1
} ZCDirection;

/* Previous state of a trigger signal */
typedef uint8_T ZCSigState;

/* Initial value of a trigger zero crossing signal */
#define UNINITIALIZED_ZCSIG            0x03U
#define NEG_ZCSIG                      0x02U
#define POS_ZCSIG                      0x01U
#define ZERO_ZCSIG                     0x00U

/* Current state of a trigger signal */
typedef enum {
  FALLING_ZCEVENT = -1,
  NO_ZCEVENT = 0,
  RISING_ZCEVENT = 1
} ZCEventType;

#endif                                 /* ZERO_CROSSING_TYPES_H */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
