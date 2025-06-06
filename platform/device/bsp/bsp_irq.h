// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef BSP_BSP_IRQ_H_
#define BSP_BSP_IRQ_H_

#include <stdio.h>

#include "common/mcu/utils/status.h"

typedef struct IrqOps {
  long (*disable_irq)(void);
  void (*enable_irq)(long level);
  bool (*is_irq_mode)(void);
  bool (*is_irq_masked)(void);
} irq_ops_t;

long DisableIrq(void);
void EnableIrq(long level);
bool IsIrqMode(void);
bool IsIrqMasked(void);

ReturnCode RequestIrq(const uint32_t irq_number, void (*irqhandler)(void *info), void *param);
ReturnCode DoIrq(const uint32_t irq_number);
ReturnCode RegisterIrq(irq_ops_t *ops);

#endif  // BSP_BSP_IRQ_H_
