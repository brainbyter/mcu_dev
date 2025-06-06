#include "xcp.h"
#include "xcp_typedefs.h"
#include "xcp_node.h"
#include <CAN_Extern.h>

extern DAQlist_t DAQlist[XCP_MAX_DAQ];
extern EventChannel_t EventChannel[XCP_MAX_EVENT_CHANNEL];
extern uint8_t XCP_DAQcount;


void XCP_DAQreset(DAQlist_t* daqList)
{
    daqList->odt_count = 0;
    daqList->started = 0;
    daqList->selected = 0;
    for(int i = 0; i < XCP_MAX_ODT; i++)
    {
        daqList->odt[i].odt_entries_count = 0;
        daqList->odt[i].size = 0;
    }
}


void XCP_UpdateEvents()
{
    uint32_t time = SystemTime;
    uint8_t event_signaled[XCP_MAX_EVENT_CHANNEL];

    for(int i = 0; i < XCP_MAX_EVENT_CHANNEL; i++)
    {
        event_signaled[i] = (time - EventChannel[i].last_signal_time) >= EventChannel[i].time_cycle;
        if(event_signaled[i])
        {
            EventChannel[i].last_signal_time = time;
        }
    }

    for(int i = 0; i < XCP_DAQcount; i++)
    {
        if((DAQlist[i].started) && event_signaled[DAQlist[i].event_channel_number])
        {
            XCP_ProcessDAQlist(i);
        }
    }
}


void XCP_ProcessDAQlist(uint8_t CurrentDAQlist)
{
    DAQlist_t* daqList = &DAQlist[CurrentDAQlist];

    for(uint8_t CurrentODT = 0; CurrentODT < daqList->odt_count; CurrentODT++)
    {
        ODT_t* odt = &(daqList->odt[CurrentODT]);
        uint8_t CANdata[8];
        uint8_t CANdataCounter = 2;

        CANdata[0] = CurrentODT;
        CANdata[1] = CurrentDAQlist;
        if((daqList->timestamp_enabled) && (CurrentODT == 0))
        {
        	*((uint32_t*)(CANdata + 2)) = SystemTime;
            CANdataCounter += 4;
        }

        for(int i = 0; i < odt->odt_entries_count; i++)
        {
            ODTentry_t* odtEntry = &(odt->odt_entry[i]);
            uint8_t* data_to_write = (uint8_t*)(odtEntry->address);

            for(int j = 0; j < odtEntry->size; j++)
            {
                CANdata[CANdataCounter] = data_to_write[j];
                CANdataCounter++;
            }
        }

        XCP_Send(CANdata, CANdataCounter);
    }
}
