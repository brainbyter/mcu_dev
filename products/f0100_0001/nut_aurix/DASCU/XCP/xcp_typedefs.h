#ifndef XCP_TYPEDEFS_H_
#define XCP_TYPEDEFS_H_

#include <stdint.h>
#include "xcp_protocol.h"
#include "xcp.h"

typedef struct
{
  daq_properties_t daq_info;
  uint16_t MAX_DAQ;
  uint16_t MAX_EVENT_CHANNEL;
  uint8_t  MIN_DAQ;
  daq_key_byte_t DAQ_KEY_BYTE;
  uint8_t GRANULARITY_ODT_ENTRY_SIZE_DAQ;
  uint8_t MAX_ODT_ENTRY_SIZE_DAQ;
  uint8_t GRANULARITY_ODT_ENTRY_SIZE_STIM;
  uint8_t MAX_ODT_ENTRY_SIZE_STIM;
  timestamp_mode_t timestamp;
  uint16_t timestamp_ticks;
} DAQsettings_t;


typedef struct
{
  uint16_t protocol_version;
  uint8_t MAX_CTO;
  uint16_t MAX_DTO;
  ressource_t ressource;
  comm_mode_basic_t comm_mode_base;
  comm_mode_opt_t comm_mode_opt;
  uint8_t MAX_BS;
  uint8_t MIN_ST;
  uint8_t XCP_Driver_version;
  uint8_t queue_size;
  DAQsettings_t daq_settings;
} XCP_Settings_t;


typedef struct
{
    daq_ev_properties_t event_prop;
    uint8_t max_daq_list;
    uint16_t time_cycle;
    uint8_t priority;
    char name[7];
    uint32_t last_signal_time;
    uint8_t signaled;
} EventChannel_t;

#pragma align 1

typedef struct __packed__
{
    uint8_t bit_offset;
    uint8_t size;
    uint32_t address;
} ODTentry_t;

typedef struct __packed__
{
    ODTentry_t odt_entry[XCP_MAX_ODT_ENTRY];
    uint8_t odt_entries_count;
    uint8_t size;
} ODT_t;

typedef struct __packed__
{
    ODT_t odt[XCP_MAX_ODT];
    uint8_t direction;
    uint8_t started;
    uint8_t selected;
    uint8_t timestamp_enabled;
    uint8_t prescaler;
    uint8_t daq_id;
    uint8_t event_channel_number;
    uint8_t odt_count;
    uint8_t signaled;
} DAQlist_t;

#pragma align restore


#endif /* USRC_XCP_XCP_TYPEDEFS_H_ */
