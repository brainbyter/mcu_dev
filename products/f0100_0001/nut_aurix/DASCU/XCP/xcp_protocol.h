#ifndef XCP_PROTOCOL_H_
#define XCP_PROTOCOL_H_

//#include <stdint.h>
#include "xcp_protocol_typedefs.h"

#define LITTLE_ENDIAN_XCP

#pragma align 1

#ifdef LITTLE_ENDIAN_XCP
typedef struct __packed__
{
  uint8_t CAL_PAG:1;
  uint8_t reserve0:1;
  uint8_t DAQ:1;
  uint8_t STIM:1;
  uint8_t PGM:1;
  uint8_t reserve1:3;
}ressource_bitmap_t;
#else
typedef struct __packed__
{
    uint8_t reserve1:3;
    uint8_t PGM:1;
    uint8_t STIM:1;
    uint8_t DAQ:1;
    uint8_t reserve0:1;
    uint8_t CAL_PAG:1;
}ressource_bitmap_t;
#endif




typedef union
{
  ressource_bitmap_t BM;
  uint8_t V;
}ressource_t;




#ifdef LITTLE_ENDIAN_XCP
typedef struct __packed__
{
  byte_order_t byte_order:1;
  address_granularity_t granularity:2;
  uint8_t reserve:3;
  uint8_t slave_block_mode:1;
  uint8_t optional:1;
}comm_mode_basic_bitmap_t;
#else
typedef struct __packed__
{
    uint8_t optional:1;
    uint8_t slave_block_mode:1;
    uint8_t reserve:3;
    address_granularity_t granularity:2;
    byte_order_t byte_order:1;
}comm_mode_basic_bitmap_t;
#endif




typedef union
{
  comm_mode_basic_bitmap_t BM;
  uint8_t V;
}comm_mode_basic_t;




#ifdef LITTLE_ENDIAN_XCP
typedef struct __packed__
{
  uint8_t MASTER_BLOCK_MODE:1;
  uint8_t INTERLEAVED_MODE:1;
  uint8_t reserve:6;
}comm_mode_opt_bitmap_t;
#else
typedef struct __packed__
{
    uint8_t reserve:6;
    uint8_t INTERLEAVED_MODE:1;
    uint8_t MASTER_BLOCK_MODE:1;
}comm_mode_opt_bitmap_t;
#endif




typedef union
{
  comm_mode_opt_bitmap_t BM;
  uint8_t V;
}comm_mode_opt_t;




#ifdef LITTLE_ENDIAN_XCP
typedef struct __packed__
{
  uint8_t STORE_CAL_REQ:1;
  uint8_t reserve0:1;
  uint8_t STORE_DAQ_REQ:1;
  uint8_t CLEAR_DAQ_REQ:1;
  uint8_t reserve1:2;
  uint8_t DAQ_RUNNING:1;
  uint8_t RESUME:1;
} session_status_bitmap_t;
#else
typedef struct __packed__
{
    uint8_t RESUME:1;
    uint8_t DAQ_RUNNING:1;
    uint8_t reserve1:2;
    uint8_t CLEAR_DAQ_REQ:1;
    uint8_t STORE_DAQ_REQ:1;
    uint8_t reserve0:1;
    uint8_t STORE_CAL_REQ:1;
} session_status_bitmap_t;
#endif




typedef union
{
  session_status_bitmap_t BM;
  uint8_t V;
} session_status_t;




#ifdef LITTLE_ENDIAN_XCP
typedef struct __packed__
{
  uint8_t CAL_PAG:1;
  uint8_t reserve0:1;
  uint8_t DAQ:1;
  uint8_t STIM:1;
  uint8_t PGM:1;
  uint8_t reserve1:1;
  uint8_t reserve2:1;
  uint8_t reserve3:1;
}protection_status_bitmap_t;
#else
typedef struct __packed__
{
    uint8_t reserve3:1;
    uint8_t reserve2:1;
    uint8_t reserve1:1;
    uint8_t PGM:1;
    uint8_t STIM:1;
    uint8_t DAQ:1;
    uint8_t reserve0:1;
    uint8_t CAL_PAG:1;
}protection_status_bitmap_t;
#endif



typedef union
{
  protection_status_bitmap_t BM;
  uint8_t V;
}protection_status_t;




#ifdef LITTLE_ENDIAN_XCP
typedef struct __packed__
{
  uint8_t DAQ_CONFIG_TYPE:1;
  uint8_t PRESCALER_SUPPORTED:1;
  uint8_t RESUME_SUPPORTED:1;
  uint8_t BIT_STIM_SUPPORTED:1;
  uint8_t TIMESTAMP_SUPPORTED:1;
  uint8_t PID_OFF_SUPPORTED:1;
  overload_t OVERLOAD:2;
} daq_properties_bitmap_t;
#else
typedef struct __packed__
{
    overload_t OVERLOAD:2;
    uint8_t PID_OFF_SUPPORTED:1;
    uint8_t TIMESTAMP_SUPPORTED:1;
    uint8_t BIT_STIM_SUPPORTED:1;
    uint8_t RESUME_SUPPORTED:1;
    uint8_t PRESCALER_SUPPORTED:1;
    uint8_t DAQ_CONFIG_TYPE:1;
} daq_properties_bitmap_t;
#endif



typedef union
{
  daq_properties_bitmap_t BM;
  uint8_t V;
} daq_properties_t;



#ifdef LITTLE_ENDIAN_XCP
typedef struct __packed__
{
	optimisation_type_t optimization:4;
	address_extension_type_t addr_extension:2;
	identification_field_type_t identification_field_type:2;
} daq_key_byte_bitmap_t;
#else
typedef struct __packed__
{
    identification_field_type_t identification_field_type:2;
    address_extension_type_t addr_extension:2;
    optimisation_type_t optimization:4;
} daq_key_byte_bitmap_t;
#endif




typedef union
{
  daq_key_byte_bitmap_t BM;
  uint8_t V;
} daq_key_byte_t;




#ifdef LITTLE_ENDIAN_XCP
typedef struct __packed__
{
  uint8_t size:3;
  uint8_t is_fixed:1;
  uint8_t unit:4;
}timestamp_mode_bitmap_t;
#else
typedef struct __packed__
{
    uint8_t unit:4;
    uint8_t is_fixed:1;
    uint8_t size:3;
}timestamp_mode_bitmap_t;
#endif




typedef union
{
  timestamp_mode_bitmap_t BM;
  uint8_t V;
} timestamp_mode_t;



#ifdef LITTLE_ENDIAN_XCP
typedef struct __packed__
{
    uint8_t : 1;
    uint8_t direction: 1;
    uint8_t : 2;
    uint8_t timestamp: 1;
    uint8_t pid_off: 1;
    uint8_t : 2;
} daq_list_mode_bitmap_t;
#else
typedef struct __packed__
{
    uint8_t : 2;
    uint8_t pid_off: 1;
    uint8_t timestamp: 1;
    uint8_t : 2;
    uint8_t direction: 1;
    uint8_t : 1;
} daq_list_mode_bitmap_t;
#endif




typedef union
{
	daq_list_mode_bitmap_t BM;
	uint8_t V;
} daq_list_mode_t;




typedef struct __packed__
{
    uint8_t response;
    uint8_t ressource;
    uint8_t comm_mode_basic;
    uint8_t max_cto;
    uint16_t max_dto;
    uint8_t protocol_version;
    uint8_t transport_version;
} XCPconnectResponse_t;



typedef struct __packed__
{
    uint8_t response;
    uint8_t res1;
    uint8_t comm_mode_opt;
    uint8_t res2;
    uint8_t max_bs;
    uint8_t min_st;
    uint8_t queue_size;
    uint8_t xcp_driver_version;
} XCPcommModeInfoResponse_t;



typedef struct __packed__
{
    uint8_t response;
    uint8_t session_status;
    uint8_t protection_status;
    uint8_t res1;
    uint16_t session_config_id;
} XCPstatusResponse_t;



typedef struct __packed__
{
    uint8_t response;
    uint8_t daq_properties;
    uint16_t max_daq;
    uint16_t max_event_channel;
    uint8_t min_daq;
    uint8_t daq_key_byte;
} XCPdaqProcessorInfo_t;



typedef struct __packed__
{
    uint8_t response;
    uint8_t granularity_odt_entry_size_daq;
    uint8_t max_odt_entry_size_daq;
    uint8_t granularity_odt_entry_size_stim;
    uint8_t max_odt_entry_size_stim;
    uint8_t timestamp_mode;
    uint16_t timestamp_ticks;
} XCPdaqResolutionInfo_t;



typedef struct __packed__
{
    uint8_t response;
    uint8_t daq_event_properties;
    uint8_t max_daq_list;
    uint8_t name_length;
    uint8_t time_cycle;
    uint8_t time_unit;
    uint8_t priority;
} XCPdaqEventInfo_t;



typedef struct __packed__
{
    uint8_t response;
    uint8_t res[3];
    uint32_t receive_timestamp;
} XCPdaqClock_t;



typedef struct __packed__
{
    uint8_t command;
    uint8_t res;
    uint16_t channel_number;
} XCPdaqEventInfoReq_t;



typedef struct __packed__
{
    uint8_t command;
    uint8_t number_elements;
    uint8_t res;
    uint8_t address_extension;
    uint32_t address;
} XCPshortUploadReq_t;



typedef struct __packed__
{
    uint8_t command;
    uint8_t res[2];
    uint8_t address_extension;
    uint32_t address;
} XCPsetMTAreq_t;



typedef struct __packed__
{
    uint8_t command;
    uint8_t res;
    uint16_t daq_count;
} XCPallocDAQreq_t;



typedef struct __packed__
{
    uint8_t command;
    uint8_t res;
    uint16_t daq_list_number;
    uint8_t odt_count;
} XCPallocODTreq_t;



typedef struct __packed__
{
    uint8_t command;
    uint8_t res;
    uint16_t daq_list_number;
    uint8_t odt_number;
    uint8_t odt_entries_count;
} XCPallocODTentryReq_t;



typedef struct __packed__
{
    uint8_t command;
    uint8_t res;
    uint16_t daq_list_number;
    uint8_t odt_number;
    uint8_t odt_entry_number;
} XCPsetDAQptrReq_t;



typedef struct __packed__
{
    uint8_t command;
    uint8_t bit_offset;
    uint8_t size;
    uint8_t address_extension;
    uint32_t address;
} XCPwriteDAQreq_t;



typedef struct __packed__
{
    uint8_t command;
    daq_list_mode_t mode;
    uint16_t daq_list_number;
    uint16_t event_channel_number;
    uint8_t transmission_rate_prescaler;
    uint8_t priority;
} XCPsetDAQlistModeReq_t;



typedef struct __packed__
{
    uint8_t command;
    uint8_t mode;
    uint16_t daq_list_number;
} XCPstartStopDAQlistReq_t;

#pragma align restore



#endif /* USRC_XCP_XCP_PROTOCOL_H_ */
