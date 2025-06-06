#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum
{
	T15_idle,
	T15_on,
	T15_off
} car_state_t;

extern car_state_t T15_state;
extern unsigned char fui_data_write_en;

extern void Watch_T15_state();

extern void ReadMemFiuStates();
extern void WriteMemFiuStates();
