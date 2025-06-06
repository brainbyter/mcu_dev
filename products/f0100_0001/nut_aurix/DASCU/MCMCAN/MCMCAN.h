#ifndef MCMCAN_H_
#define MCMCAN_H_

#include <stdio.h>
#include <string.h>
#include "bsp_can.h"

#define ADAS_BUFF_MAX_ITEMS 64U
#define DEBUG_BUFF_MAX_ITEMS 64U

#define ADAS_MAX_RX_FILTER 90U
#define HAVAL_MAX_RX_FILTER 16U
#define DEBUG_ADAS_MAX_RX_FILTER 40U
#define MRRX_DATA_MAX_RX_FILTER 25U
#define MRRX_DIAG_MAX_RX_FILTER 10U
#define XCP_MAX_RX_FILTER 5U

extern volatile uint32 g_count_can_adas;
extern volatile uint32 g_count_can_test_adas;

extern volatile uint32 g_count_can_adas_maxdeep;
extern volatile uint32 g_count_can_test_adas_maxdeep;

extern uint32 g_await_count_can_adas_maxdeep;
extern uint32 g_await_count_can_test_adas_maxdeep;


extern volatile can_msg_t rxDataAdasBuffer[ADAS_BUFF_MAX_ITEMS];
extern volatile can_msg_t rxDataTestAdasBuffer[DEBUG_BUFF_MAX_ITEMS];

#endif
