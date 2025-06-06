#include "bsp_can.h"

extern can_data_ready_callback_t data_ready_callback_can_adas;
extern can_data_ready_callback_t data_ready_callback_haval;
extern can_data_ready_callback_t data_ready_callback_xcp_rx;

extern can_data_ready_callback_t data_ready_callback_can_test_adas;
extern can_data_ready_callback_t data_ready_callback_mrrx_diag;
extern can_data_ready_callback_t data_ready_callback_mrrx_data;

extern void canRxInterruptCanAdas(void);
extern void canRxInterruptCanHaval(void);
extern void canRxInterruptXcpCan(void);

extern void canRxInterruptCanTestAdas(void);
extern void canRxInterruptCanMrrxDiag(void);
extern void canRxInterruptCanMrrxData(void);


