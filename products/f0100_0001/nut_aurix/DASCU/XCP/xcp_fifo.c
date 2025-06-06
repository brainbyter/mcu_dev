#include "xcp_node.h"
#include <bsp_can.h>

uint8_t FIFOinputNum = 0;
uint8_t FIFOoutputNum = 0;
boolean FIFOsending = FALSE;
uint8_t FIFOdata[XCP_FIFO_SIZE][9];
uint8_t fXcpTxIrqEn = 0;

void FIFOsetData(uint8_t* data, uint8_t dlc)
{
    for(int i = 0; i < dlc; i++)
    {
        FIFOdata[FIFOinputNum][i] = data[i];
    }
    FIFOdata[FIFOinputNum][8] = dlc;
    FIFOinputNum = (FIFOinputNum < (XCP_FIFO_SIZE - 1)) ? (FIFOinputNum + 1) : 0;
}


boolean FIFOgetData(uint8_t* data, uint8_t* dlc)
{
    boolean result = false;
    if(FIFOoutputNum != FIFOinputNum)
    {
        *dlc = FIFOdata[FIFOoutputNum][8];
        for(int i = 0; i < *dlc; i++)
        {
             data[i] = FIFOdata[FIFOoutputNum][i];
        }
        FIFOoutputNum = (FIFOoutputNum < (XCP_FIFO_SIZE - 1)) ? (FIFOoutputNum + 1) : 0;
        result = true;
    }
    return result;
}


void SendToFIFO(uint8_t* data, uint8_t size)
{
    if(!FIFOsending)
    {
    	if (Send(data, size))
    	{
    		fXcpTxIrqEn = 1;
//			TxInterrupt();
    	}

    	FIFOsending = TRUE;
    }
    else
    {
        FIFOsetData(data, size);

//      FIFOsending = FALSE;

        if(!FIFOsending)
        {
            FIFOsending = TRUE;
            uint8_t data[8];
            uint8_t size = 0;
            FIFOgetData(data, &size);
            if (Send(data, size))
            {
//				TxInterrupt();
            	fXcpTxIrqEn = 1;
            }
        }
    }
}


void TxInterrupt()
{
	uint8_t data[8];
    uint8_t size = 0;
    if(FIFOgetData(data, &size))
    {
        FIFOsending = TRUE;
        if (Send(data, size))
        {
        	fXcpTxIrqEn=1;
//			TxInterrupt();
        }
    }
    else
    {
        FIFOsending = FALSE;
    }
}

