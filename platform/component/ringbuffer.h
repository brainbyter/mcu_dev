// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef COMPONENT_RINGBUFFER_H_
#define COMPONENT_RINGBUFFER_H_

#include <stdint.h>

#include "common/mcu/utils/status.h"

struct RingBuffer {
  uint8_t* buf;
  uint32_t size;
  uint32_t mask;
  uint32_t read_index;
  uint32_t write_index;
};

extern uint8_t* GetRingBufferWriteAddr(struct RingBuffer* ring_buffer);
extern uint8_t* GetRingBufferReadAddr(struct RingBuffer* ring_buffer);
extern int GetRingBufferMaxWrite(struct RingBuffer* ring_buffer);
extern int GetRingBufferMaxRead(struct RingBuffer* ring_buffer);
extern int GetRingBufferMaxSpace(struct RingBuffer* ring_buffer);
extern int GetRingBufferMaxData(struct RingBuffer* ring_buffer);
extern void ClearRingBufferData(struct RingBuffer* ring_buffer);

// The buffer's size must be 2^n
extern ReturnCode InitRingBuffer(struct RingBuffer* ring_buffer, uint8_t* buf, uint32_t size);
extern int WriteRingBufferData(struct RingBuffer* ring_buffer,
                               const uint8_t* data,
                               uint32_t length);
extern int ReadRingBufferData(struct RingBuffer* ring_buffer, uint8_t* data, uint32_t length);

#endif  // COMPONENT_RINGBUFFER_H_
