/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "MCMCAN.h"

volatile uint32 g_count_can_adas = 0;
volatile uint32 g_count_can_test_adas = 0;

volatile uint32 g_count_can_adas_maxdeep = 0;
volatile uint32 g_count_can_test_adas_maxdeep = 0;

uint32 g_await_count_can_adas_maxdeep = 0;
uint32 g_await_count_can_test_adas_maxdeep = 0;

volatile can_msg_t rxDataAdasBuffer[ADAS_BUFF_MAX_ITEMS];
volatile can_msg_t rxDataTestAdasBuffer[DEBUG_BUFF_MAX_ITEMS];


