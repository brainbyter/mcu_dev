#include "xcp.h"
#include "xcp_protocol.h"
#include "xcp_node.h"
#include "xcp_typedefs.h"
#include <CAN_Extern.h>
#include <bsp_can.h>


#include "../MCMCAN/Generated/XCPCAN/XCPCAN_Handlers.h"

static void XCP_Connect();
static void XCP_Disconnect();
static void XCP_SendCommModeInfo();
static void XCP_SendStatus();
static void XCP_SendDAQprocessorInfo();
static void XCP_SendDAQresolutionInfo();
static void XCP_SendDAQeventInfo();
static void XCP_Upload();
static void XCP_SendDAQclock();
static void XCP_ShortUpload();
static void XCP_SetMTA();
static void XCP_Download();
static void XCP_FreeDAQ();
static void XCP_AllocDAQ();
static void XCP_AllocODT();
static void XCP_AllocODTentry();
static void XCP_SetDAQptr();
static void XCP_WriteDAQ();
static void XCP_SetDAQlistMode();
static void XCP_StartStopDAQlist();
static void XCP_StartStopSynch();
static void XCP_Synch();
void SetErrorResponse(uint8_t code);

DAQlist_t DAQlist[XCP_MAX_DAQ];

EventChannel_t EventChannel[XCP_MAX_EVENT_CHANNEL] =
{
  {.name = "10 ms",  .time_cycle = 10,   .priority = 2},
  {.name = "100 ms", .time_cycle = 100,  .priority = 1},
  {.name = "1 s",    .time_cycle = 1000, .priority = 0}
};

uint8_t XCP_Connected = FALSE;
static uint8_t* XCP_Request;
static uint8_t XCP_Response[8] = {0};
static uint8_t XCP_ResponseDLC = 0;
static uint32_t XCP_MTAmemoryPointer;
static uint32_t XCP_UploadMemoryLength = 0;
static uint32_t XCP_DownloadMemoryLength = 0;
static boolean XCP_DAQallocated = FALSE;
static boolean XCP_ODTallocated = FALSE;
static boolean XCP_ODTentryAllocated = FALSE;
uint8_t XCP_DAQcount = 0;

static struct
{
    uint8_t daq_list_number;
    uint8_t odt_number;
    uint8_t odt_entry_number;
} XCP_CurrentDAQptr = {0xFF, 0xFF, 0xFF};


void XCP_Init()
{
    for(int i = 0; i < XCP_MAX_EVENT_CHANNEL; i++)
    {
        EventChannel[i].event_prop = DAQ_STIM;
        EventChannel[i].max_daq_list = XCP_MAX_DAQ;
    }

    for(int i = 0; i < XCP_MAX_DAQ; i++)
    {
        DAQlist[i].daq_id = i;
        XCP_DAQreset(&DAQlist[i]);
    }
}


void XCP_ProcessMessage(uint8_t *data, uint8_t dlc)
{
    XCP_Request = (uint8_t*)data;
    uint8_t PID = XCP_Request[0];
    XCP_ResponseDLC = 0;

    if(XCP_Connected)
    {
        switch(PID)
        {
        case CONNECT:                       XCP_Connect(); break;
        case DISCONNECT:                    XCP_Disconnect(); break;
        case GET_COMM_MODE_INFO:            XCP_SendCommModeInfo(); break;
        case GET_STATUS:                    XCP_SendStatus(); break;
        case GET_DAQ_PROCESSOR_INFO:        XCP_SendDAQprocessorInfo(); break;
        case GET_DAQ_RESOLUTION_INFO:       XCP_SendDAQresolutionInfo(); break;
        case GET_DAQ_EVENT_INFO:            XCP_SendDAQeventInfo(); break;
        case UPLOAD:                        XCP_Upload(); break;
        case GET_DAQ_CLOCK:                 XCP_SendDAQclock(); break;
        case SHORT_UPLOAD:                  XCP_ShortUpload(); break;
        case SET_MTA:                       XCP_SetMTA(); break;
        case DOWNLOAD_NEXT:
        case DOWNLOAD:                      XCP_Download(); break;
        case FREE_DAQ:                      XCP_FreeDAQ(); break;
        case ALLOC_DAQ:                     XCP_AllocDAQ(); break;
        case ALLOC_ODT:                     XCP_AllocODT(); break;
        case ALLOC_ODT_ENTRY:               XCP_AllocODTentry(); break;
        case SET_DAQ_PTR:                   XCP_SetDAQptr(); break;
        case WRITE_DAQ:                     XCP_WriteDAQ(); break;
        case SET_DAQ_LIST_MODE:             XCP_SetDAQlistMode(); break;
        case START_STOP_DAQ_LIST:           XCP_StartStopDAQlist(); break;
        case START_STOP_SYNCH:              XCP_StartStopSynch(); break;
        case SYNCH:                         XCP_Synch(); break;
        default:                            SetErrorResponse(ERR_CMD_UNKNOWN); break;
        }
    }
    else if(PID == CONNECT)
    {
        XCP_Connect();
    }

    if(XCP_ResponseDLC != 0)
    {
        XCP_Send(XCP_Response, XCP_ResponseDLC);
    }
}


void SetErrorResponse(uint8_t code)
{
    XCP_Response[0] = ERR;
    XCP_Response[1] = code;
    XCP_ResponseDLC = 2;
}


void XCP_Connect()
{
    XCPconnectResponse_t* response = (XCPconnectResponse_t*)XCP_Response;
    response->response = POSITIVE_RESPONSE;
    ressource_t ressource;
    comm_mode_basic_t comm_mode_basic;

    ressource.BM.CAL_PAG = 0;
    ressource.BM.DAQ = 1;
    ressource.BM.PGM = 0;
    ressource.BM.STIM = 0;
    ressource.BM.reserve0 = 0;
    ressource.BM.reserve1 = 0;
    comm_mode_basic.BM.byte_order = BYTE_ORDER_MSB_LAST;
    comm_mode_basic.BM.granularity = ADDRESS_GRANULARITY_BYTE;
    comm_mode_basic.BM.optional = 1;
    comm_mode_basic.BM.slave_block_mode = 1;
    comm_mode_basic.BM.reserve = 0;
    response->max_cto = 8;
    response->max_dto = 8;
    response->protocol_version = 1;
    response->transport_version = 1;

    response->ressource = ressource.V;
    response->comm_mode_basic = comm_mode_basic.V;

    XCP_Connected = TRUE;
    XCP_ResponseDLC = sizeof(*response);
}


void XCP_Disconnect()
{
    XCP_Connected = FALSE;
    XCP_Response[0] = POSITIVE_RESPONSE;
    XCP_ResponseDLC = 1;
}


void XCP_SendCommModeInfo()
{
    XCPcommModeInfoResponse_t* response = (XCPcommModeInfoResponse_t*)XCP_Response;
    response->response = POSITIVE_RESPONSE;
    XCP_ResponseDLC = sizeof(*response);
    comm_mode_opt_t comm_mode_opt;

    comm_mode_opt.BM.INTERLEAVED_MODE = 0;
    comm_mode_opt.BM.MASTER_BLOCK_MODE = 1;
    response->max_bs = XCP_MAX_BS;
    response->min_st = 20; // * 100 us
    response->queue_size = 0;
    response->xcp_driver_version = 25;

    response->comm_mode_opt = comm_mode_opt.V;
}


void XCP_SendStatus()
{
    XCPstatusResponse_t* response = (XCPstatusResponse_t*)XCP_Response;
    response->response = POSITIVE_RESPONSE;
    XCP_ResponseDLC = sizeof(*response);
    session_status_t session_status;
    protection_status_t protection_status;

    boolean daq_running = FALSE;
    for(int i = 0; i < XCP_DAQcount; i++)
    {
        daq_running |= DAQlist[i].started;
    }

    session_status.BM.CLEAR_DAQ_REQ = 0;
    session_status.BM.DAQ_RUNNING = daq_running;
    session_status.BM.RESUME = 0;
    session_status.BM.STORE_CAL_REQ = 0;
    session_status.BM.STORE_DAQ_REQ = 0;
    protection_status.BM.CAL_PAG = 0;
    protection_status.BM.DAQ = 0;
    protection_status.BM.PGM = 0;
    protection_status.BM.STIM = 0;
    response->session_config_id = 0;

    response->session_status = session_status.V;
    response->protection_status = protection_status.V;
}


void XCP_SendDAQprocessorInfo()
{
    XCPdaqProcessorInfo_t* response = (XCPdaqProcessorInfo_t*)XCP_Response;
    response->response = POSITIVE_RESPONSE;
    XCP_ResponseDLC = sizeof(*response);
    daq_properties_t daq_properties;
    daq_key_byte_t daq_key_byte;

    daq_properties.BM.BIT_STIM_SUPPORTED = 0;
    daq_properties.BM.DAQ_CONFIG_TYPE = DAQ_DYNAMIC;
    daq_properties.BM.OVERLOAD = OVERLOAD_NONE;
    daq_properties.BM.PID_OFF_SUPPORTED = 0;
    daq_properties.BM.PRESCALER_SUPPORTED = 1;
    daq_properties.BM.RESUME_SUPPORTED = 0;
    daq_properties.BM.TIMESTAMP_SUPPORTED = 1;
    response->max_daq = XCP_DAQcount;
    response->max_event_channel = XCP_MAX_EVENT_CHANNEL;
    response->min_daq = 0;
    daq_key_byte.BM.addr_extension = ADDR_EXTENSION_SAME_WITHIN_ONE_DAQ;
    daq_key_byte.BM.identification_field_type = RELODT_ABSDAQ_BYTE;
    daq_key_byte.BM.optimization = OM_DEFAULT;

    response->daq_key_byte = daq_key_byte.V;
    response->daq_properties = daq_properties.V;
}


void XCP_SendDAQresolutionInfo()
{
    XCPdaqResolutionInfo_t* response = (XCPdaqResolutionInfo_t*)XCP_Response;
    response->response = POSITIVE_RESPONSE;
    XCP_ResponseDLC = sizeof(*response);
    timestamp_mode_t timestamp_mode;

    response->granularity_odt_entry_size_daq = 1;
    response->max_odt_entry_size_daq = XCP_MAX_ODT_ENTRY_SIZE;
    response->granularity_odt_entry_size_stim = 1;
    response->max_odt_entry_size_stim = XCP_MAX_ODT_ENTRY_SIZE;
    timestamp_mode.BM.is_fixed = 0;
    timestamp_mode.BM.size = 4;
    timestamp_mode.BM.unit = DAQ_TIMESTAMP_UNIT_1MS;
    response->timestamp_ticks = 1;

    response->timestamp_mode = timestamp_mode.V;
}


void XCP_SendDAQeventInfo()
{
    XCPdaqEventInfoReq_t* request = (XCPdaqEventInfoReq_t*)XCP_Request;
    XCPdaqEventInfo_t* response = (XCPdaqEventInfo_t*)XCP_Response;
    //XCP_ResponseDLC = sizeof(*response);
    XCP_ResponseDLC = 7;

    if(request->channel_number > XCP_MAX_EVENT_CHANNEL) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else
    {
        EventChannel_t* eventChannel = &EventChannel[request->channel_number];

        response->response = POSITIVE_RESPONSE;
        response->daq_event_properties = eventChannel->event_prop;
        response->max_daq_list = eventChannel->max_daq_list;
        response->name_length = sizeof(eventChannel->name);
        response->time_cycle = (eventChannel->time_cycle <= 255) ? eventChannel->time_cycle : (eventChannel->time_cycle / 10);
        response->time_unit = (eventChannel->time_cycle <= 255) ? DAQ_TIMESTAMP_UNIT_1MS : DAQ_TIMESTAMP_UNIT_10MS;
        response->priority = eventChannel->priority;

        XCP_MTAmemoryPointer = (uint32_t)&eventChannel->name;
    }
}


void XCP_Upload()
{
    XCP_UploadMemoryLength = XCP_Request[1];

    while(XCP_UploadMemoryLength != 0)
    {
        XCP_Response[0] = POSITIVE_RESPONSE;

        uint8_t counter;
        for(counter = 1; counter < 8; counter++)
        {
            XCP_Response[counter] = *((uint8_t*)XCP_MTAmemoryPointer);
            XCP_MTAmemoryPointer++;
            XCP_UploadMemoryLength--;
            if(XCP_UploadMemoryLength == 0)
            {
                counter++;
                break;
            }
        }
        XCP_Send(XCP_Response, counter);
    }
    XCP_ResponseDLC = 0;
}


void XCP_SendDAQclock()
{
    XCPdaqClock_t* response = (XCPdaqClock_t*)XCP_Response;
    response->response = POSITIVE_RESPONSE;
    XCP_ResponseDLC = sizeof(*response);

    ///    response->receive_timestamp = xTaskGetTickCount();
    response->receive_timestamp = SystemTime;
}

/*
void XCP_ShortUpload()
{
    XCPshortUploadReq_t* request = (XCPshortUploadReq_t*)XCP_Request;
    XCP_Response[0] = POSITIVE_RESPONSE;
    XCP_ResponseDLC = request->number_elements + 1;
    if(request->number_elements > 8-1) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else
    {
        uint8_t* data = (uint8_t*)request->address;

        for(int i = 0; i < request->number_elements; i++)
        {
            XCP_Response[i + 1] = data[i];
        }
    }
}
*/


void XCP_ShortUpload()
{
    XCPshortUploadReq_t* request = (XCPshortUploadReq_t*)XCP_Request;
    XCP_Response[0] = POSITIVE_RESPONSE;
    XCP_ResponseDLC = request->number_elements + 1;
    if(request->number_elements > 8-1) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else
    {
        for(int i = 0; i < request->number_elements; i++)
        {
        	XCP_Response[i + 1] = ADDRESS_IN_RANGE(request->address) ? (*((uint8*)request->address)) : 0xFF;
        	request->address++;
        }
    }
}


void XCP_SetMTA()
{
    XCPsetMTAreq_t* request = (XCPsetMTAreq_t*)XCP_Request;
    XCP_ResponseDLC = 1;
    XCP_Response[0] = POSITIVE_RESPONSE;

    XCP_MTAmemoryPointer = request->address;
}

/*
void XCP_Download()
{
	boolean error = FALSE;
    uint8_t number_of_elements = XCP_Request[1];

    if(XCP_Request[0] == DOWNLOAD)
    {
        XCP_DownloadMemoryLength = number_of_elements;
    }
    else
    {
        error |= (number_of_elements > XCP_DownloadMemoryLength);
        error |= ((XCP_DownloadMemoryLength >= 6) && (number_of_elements < XCP_DownloadMemoryLength));
    }

    if(!error)
    {
        uint8_t counter;
        for(counter = 2; counter < 8; counter++)
        {
            *((uint8_t*)XCP_MTAmemoryPointer) = XCP_Request[counter];
            XCP_MTAmemoryPointer++;
            XCP_DownloadMemoryLength--;
            if(XCP_DownloadMemoryLength == 0)
            {
                XCP_Response[0] = POSITIVE_RESPONSE;
                XCP_ResponseDLC = 1;
                break;
            }
        }
    }
    else
    {
        SetErrorResponse(ERR_SEQUENCE);
    }
}
*/

void XCP_Download()
{
	boolean error = FALSE;
    uint8_t number_of_elements = XCP_Request[1];

    if(XCP_Request[0] == DOWNLOAD)
    {
        XCP_DownloadMemoryLength = number_of_elements;
    }
    else
    {
        error |= (number_of_elements > XCP_DownloadMemoryLength);
        error |= ((XCP_DownloadMemoryLength >= 6) && (number_of_elements < XCP_DownloadMemoryLength));
    }

    if(!error)
    {
        uint8_t counter;
        for(counter = 2; counter < 8; counter++)
        {
        	if(ADDRESS_IN_RANGE(XCP_MTAmemoryPointer))
        	{
				*((uint8_t*)XCP_MTAmemoryPointer) = XCP_Request[counter];
        	}
            XCP_MTAmemoryPointer++;
            XCP_DownloadMemoryLength--;
            if(XCP_DownloadMemoryLength == 0)
            {
                XCP_Response[0] = POSITIVE_RESPONSE;
                XCP_ResponseDLC = 1;
                break;
            }
        }
    }
    else
    {
        SetErrorResponse(ERR_SEQUENCE);
    }
}

void XCP_FreeDAQ()
{
    XCP_Response[0] = POSITIVE_RESPONSE;
    XCP_ResponseDLC = 1;

    for(int i = 0; i < XCP_MAX_DAQ; i++)
    {
        XCP_DAQreset(&DAQlist[i]);
    }

    XCP_DAQallocated = FALSE;
    XCP_ODTallocated = FALSE;
    XCP_ODTentryAllocated = FALSE;
    XCP_DAQcount = 0;
    XCP_CurrentDAQptr.daq_list_number = 0xFF;
    XCP_CurrentDAQptr.odt_entry_number = 0xFF;
    XCP_CurrentDAQptr.odt_number = 0xFF;
}


void XCP_AllocDAQ()
{
    XCPallocDAQreq_t* request = (XCPallocDAQreq_t*)XCP_Request;
    XCP_Response[0] = POSITIVE_RESPONSE;
    XCP_ResponseDLC = 1;

    if(XCP_ODTallocated || XCP_ODTentryAllocated) { SetErrorResponse(ERR_SEQUENCE); }
    else if((XCP_DAQcount + request->daq_count) > XCP_MAX_DAQ) { SetErrorResponse(ERR_MEMORY_OVERFLOW); }
    else
    {
        XCP_DAQcount += request->daq_count;
        XCP_DAQallocated = TRUE;
    }
}


void XCP_AllocODT()
{
    XCPallocODTreq_t* request = (XCPallocODTreq_t*)XCP_Request;
    XCP_Response[0] = POSITIVE_RESPONSE;
    XCP_ResponseDLC = 1;

    if((!XCP_DAQallocated) || XCP_ODTentryAllocated) { SetErrorResponse(ERR_SEQUENCE); }
    else if(request->daq_list_number >= XCP_DAQcount) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else if((DAQlist[request->daq_list_number].odt_count + request->odt_count) > XCP_MAX_ODT) { SetErrorResponse(ERR_MEMORY_OVERFLOW); }
    else
    {
        DAQlist[request->daq_list_number].odt_count += request->odt_count;
        XCP_ODTallocated = TRUE;
    }
}


void XCP_AllocODTentry()
{
    XCPallocODTentryReq_t* request = (XCPallocODTentryReq_t*)XCP_Request;
    XCP_Response[0] = POSITIVE_RESPONSE;
    XCP_ResponseDLC = 1;

    if((!XCP_DAQallocated) || (!XCP_ODTallocated)) { SetErrorResponse(ERR_SEQUENCE); }
    else if(request->daq_list_number >= XCP_DAQcount) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else if(request->odt_number >= DAQlist[request->daq_list_number].odt_count) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else if((request->odt_entries_count + DAQlist[request->daq_list_number].odt[request->odt_number].odt_entries_count) > XCP_MAX_ODT_ENTRY) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else
    {
        DAQlist[request->daq_list_number].odt[request->odt_number].odt_entries_count += request->odt_entries_count;
        XCP_ODTentryAllocated = TRUE;
    }
}


void XCP_SetDAQptr()
{
    XCPsetDAQptrReq_t* request = (XCPsetDAQptrReq_t*)XCP_Request;
    XCP_Response[0] = POSITIVE_RESPONSE;
    XCP_ResponseDLC = 1;

    if(request->daq_list_number >= XCP_DAQcount) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else if(request->odt_number >= DAQlist[request->daq_list_number].odt_count) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else if(request->odt_entry_number >= DAQlist[request->daq_list_number].odt[request->odt_number].odt_entries_count) { SetErrorResponse(ERR_OUT_OF_RANGE); }

    if(XCP_Response[0] == POSITIVE_RESPONSE)
    {
        XCP_CurrentDAQptr.daq_list_number = request->daq_list_number;
        XCP_CurrentDAQptr.odt_number = request->odt_number;
        XCP_CurrentDAQptr.odt_entry_number = request->odt_entry_number;
    }
    else
    {
        XCP_CurrentDAQptr.daq_list_number = 0xFF;
        XCP_CurrentDAQptr.odt_number = 0xFF;
        XCP_CurrentDAQptr.odt_entry_number = 0xFF;
    }
}

/*
void XCP_WriteDAQ()
{
    XCPwriteDAQreq_t* request = (XCPwriteDAQreq_t*)XCP_Request;
    XCP_Response[0] = POSITIVE_RESPONSE;
    XCP_ResponseDLC = 1;

    if(XCP_CurrentDAQptr.daq_list_number >= XCP_DAQcount) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else if(XCP_CurrentDAQptr.odt_number >= DAQlist[XCP_CurrentDAQptr.daq_list_number].odt_count) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else if(XCP_CurrentDAQptr.odt_entry_number >= DAQlist[XCP_CurrentDAQptr.daq_list_number].odt[XCP_CurrentDAQptr.odt_number].odt_entries_count) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else if(DAQlist[XCP_CurrentDAQptr.daq_list_number].odt[XCP_CurrentDAQptr.odt_number].size + request->size > XCP_MAX_ODT_ENTRY_SIZE) { SetErrorResponse(ERR_OUT_OF_RANGE); }

    ODTentry_t* odtEntry = &(DAQlist[XCP_CurrentDAQptr.daq_list_number].odt[XCP_CurrentDAQptr.odt_number].odt_entry[XCP_CurrentDAQptr.odt_entry_number]);

    odtEntry->address = request->address;
    odtEntry->size = request->size;
    DAQlist[XCP_CurrentDAQptr.daq_list_number].odt[XCP_CurrentDAQptr.odt_number].size += request->size;
    XCP_CurrentDAQptr.odt_entry_number++;
}
*/
void XCP_WriteDAQ()
{
    XCPwriteDAQreq_t* request = (XCPwriteDAQreq_t*)XCP_Request;
    XCP_Response[0] = POSITIVE_RESPONSE;
    XCP_ResponseDLC = 1;

    if (XCP_CurrentDAQptr.daq_list_number >= XCP_DAQcount)
    {
    	SetErrorResponse(ERR_OUT_OF_RANGE);
    }
    else if (XCP_CurrentDAQptr.odt_number >= DAQlist[XCP_CurrentDAQptr.daq_list_number].odt_count)
    {
    	SetErrorResponse(ERR_OUT_OF_RANGE);
    }
    else if (XCP_CurrentDAQptr.odt_entry_number >= DAQlist[XCP_CurrentDAQptr.daq_list_number].odt[XCP_CurrentDAQptr.odt_number].odt_entries_count)
    {
    	SetErrorResponse(ERR_OUT_OF_RANGE);
    }
    else if (DAQlist[XCP_CurrentDAQptr.daq_list_number].odt[XCP_CurrentDAQptr.odt_number].size + request->size > XCP_MAX_ODT_ENTRY_SIZE)
    {
    	SetErrorResponse(ERR_OUT_OF_RANGE);
    }
    else if (ADDRESS_AND_SIZE_IN_RANGE(request->address, request->size) == FALSE)
    {
    	SetErrorResponse(ERR_OUT_OF_RANGE);
    }

    ODTentry_t* odtEntry = &(DAQlist[XCP_CurrentDAQptr.daq_list_number].odt[XCP_CurrentDAQptr.odt_number].odt_entry[XCP_CurrentDAQptr.odt_entry_number]);

    odtEntry->address = request->address;
    odtEntry->size = request->size;
    DAQlist[XCP_CurrentDAQptr.daq_list_number].odt[XCP_CurrentDAQptr.odt_number].size += request->size;
    XCP_CurrentDAQptr.odt_entry_number++;
}

void XCP_SetDAQlistMode()
{
    XCPsetDAQlistModeReq_t* request = (XCPsetDAQlistModeReq_t*)XCP_Request;
    XCP_Response[0] = POSITIVE_RESPONSE;
    XCP_ResponseDLC = 1;

    if(request->daq_list_number >= XCP_DAQcount) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else if(request->event_channel_number >= XCP_MAX_EVENT_CHANNEL) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    //else if(request->priority > 0) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else if(request->mode.BM.pid_off) { SetErrorResponse(ERR_CMD_SYNTAX); }
    else
    {
        DAQlist_t* daqList = &DAQlist[request->daq_list_number];
        daqList->direction = request->mode.BM.direction;
        daqList->event_channel_number = request->event_channel_number;
        daqList->prescaler = request->transmission_rate_prescaler;
        daqList->timestamp_enabled = request->mode.BM.timestamp;
    }
}


void XCP_StartStopDAQlist()
{
    XCPstartStopDAQlistReq_t* request = (XCPstartStopDAQlistReq_t*)XCP_Request;
    XCP_Response[0] = POSITIVE_RESPONSE;
    XCP_ResponseDLC = 2;

    if(request->daq_list_number >= XCP_DAQcount) { SetErrorResponse(ERR_OUT_OF_RANGE); }
    else
    {
        switch(request->mode)
        {
        case DAQ_START: DAQlist[request->daq_list_number].started = TRUE;  DAQlist[request->daq_list_number].selected = FALSE; break;
        case DAQ_STOP:  DAQlist[request->daq_list_number].started = FALSE; DAQlist[request->daq_list_number].selected = FALSE; break;
        case DAQ_SELECT: DAQlist[request->daq_list_number].selected = TRUE; break;
        default: SetErrorResponse(ERR_CMD_SYNTAX); break;
        }
        XCP_Response[1] = 0;
    }
}


void XCP_StartStopSynch()
{
    XCP_Response[0] = POSITIVE_RESPONSE;
    XCP_ResponseDLC = 1;

    switch(XCP_Request[1])
    {
    case SYNCH_STOP_ALL:        for(int i = 0; i < XCP_DAQcount; i++) { DAQlist[i].started = FALSE; } break;
    case SYNCH_START_SELECTED:  for(int i = 0; i < XCP_DAQcount; i++) { if(DAQlist[i].selected) { DAQlist[i].started = TRUE;  DAQlist[i].selected = FALSE; }} break;
    case SYNCH_STOP_SELECTED:   for(int i = 0; i < XCP_DAQcount; i++) { if(DAQlist[i].selected) { DAQlist[i].started = FALSE; DAQlist[i].selected = FALSE; }} break;
    default: SetErrorResponse(ERR_CMD_SYNTAX); break;
    }
}


void XCP_Synch()
{
    SetErrorResponse(ERR_CMD_SYNCH);
    XCP_ResponseDLC = 1;
}


void XCPProcess()
{
    if(XCP_Connected)
    {
        XCP_UpdateEvents();
    }
}

