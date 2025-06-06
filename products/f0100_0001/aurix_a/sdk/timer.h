// Copyright @2024 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_AURIX_A_SDK_TIMER_H_
#define PRODUCTS_F0100_0001_AURIX_A_SDK_TIMER_H_

enum PonyTimerID {
    kTimer0,
    kTimer1,
    kTimer2,
    kTimer3,
    kTimer4,
    kTimer012 = 7,
    kTimer34 = 8,
};

typedef enum PonyTimer012Period {
    kTimer012Period40Ns = 40,
    kTimer012Period80Ns = 80,
    kTimer012Period160Ns = 160,
    kTimer012Period320Ns = 320,
} PonyTimer012Period;

typedef enum PonyTimer34Period {
    kTimer34Period20Ns = 20,
    kTimer34Period40Ns = 40,
    kTimer34Period80Ns = 80,
    kTimer34Period160Ns = 160,
} PonyTimer34Period;

typedef enum PonyTimerPrescaler {
    kTimerPrescaler1 = 1,
    kTimerPrescaler2 = 2,
    kTimerPrescaler4 = 4,
    kTimerPrescaler8 = 8,
    kTimerPrescaler16 = 16,
    kTimerPrescaler32 = 32,
    kTimerPrescaler64 = 64,
    kTimerPrescaler128 = 128,
} PonyTimerPrescaler;

extern ReturnCode InitTimer(void);

#endif
