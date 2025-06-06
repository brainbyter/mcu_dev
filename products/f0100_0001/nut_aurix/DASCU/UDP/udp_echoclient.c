#include "lwip/pbuf.h"
#include "lwip/udp.h"
#include "lwip/tcp.h"
#include <string.h>
#include <stdio.h>
#include "lwip/ip4_addr.h"
#include "../inc/udp_echoclient.h"

#include "UDP_Extern.h"
#include "bsp_can.h"
#include "sw_version.h"

u8_t dataRx[1024];

struct udp_pcb *udp_socket_src;
struct udp_pcb *udp_socket_dst;
struct udp_pcb *udp_socket_mrr_dst;
struct udp_pcb *udp_socket_ic_dst;

struct udp_pcb *udp_socket_src_debug_pc;
struct udp_pcb *udp_socket_dst_debug_pc;

unsigned int udpSendPrepareCounter = 0;
unsigned int udpSendPrepare = 0;

void udp_rcv_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port);
void udp_rcv_callback_debug_pc(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port);


void udp_client_ic_connect(void)
{
	err_t err;

	udp_socket_ic_dst = udp_new();

	if (udp_socket_ic_dst != NULL)
	{
		ip_addr_t DestIPaddr;
		IP4_ADDR(&DestIPaddr, 192, 168, 1, 15);
		err= udp_connect(udp_socket_ic_dst, &DestIPaddr, 8020);
	}
}


void udp_client_mrr_connect(void)
{
	err_t err;

	udp_socket_mrr_dst = udp_new();

	if (udp_socket_mrr_dst != NULL)
	{
		ip_addr_t DestIPaddr;
		IP4_ADDR(&DestIPaddr, 192, 168, 1, 100);
		err= udp_connect(udp_socket_mrr_dst, &DestIPaddr, 6667);
	}
}

void udp_client_connect(void)
{
    err_t err;

    udp_socket_src = udp_new();
    udp_socket_dst = udp_new();

#ifdef HW_DEBUG
//    udp_socket_src_debug_pc = udp_new();
    udp_socket_dst_debug_pc = udp_new();
#endif

    if (udp_socket_dst != NULL)
    {
        ip_addr_t DestIPaddr;
        IP4_ADDR(&DestIPaddr, 192, 168, 1, 100);
        err= udp_connect(udp_socket_dst, &DestIPaddr, 6666);
    }

    if (udp_socket_src != NULL)
    {
        ip_addr_t SrcIPaddr;
        IP4_ADDR(&SrcIPaddr, 192, 168, 1, 65);
        udp_bind(udp_socket_src, &SrcIPaddr, 7777);

        if (err == ERR_OK)
        {
            udp_recv(udp_socket_src, udp_rcv_callback, NULL);
        }
    }

#ifdef HW_DEBUG
    if (udp_socket_dst_debug_pc != NULL)
    {
        ip_addr_t DestIPaddr;
        IP4_ADDR(&DestIPaddr, 192, 168, 1, 10);
        err= udp_connect(udp_socket_dst_debug_pc, &DestIPaddr, 6667);
    }
/*
    if (udp_socket_src_debug_pc != NULL)
    {
        ip_addr_t SrcIPaddr;
        IP4_ADDR(&SrcIPaddr, 192, 168, 1, 65);
        udp_bind(udp_socket_src_debug_pc, &SrcIPaddr, 55554);

        if (err == ERR_OK)
        {
            udp_recv(udp_socket_src_debug_pc, udp_rcv_callback_debug_pc, NULL);
        }
    }
*/
#endif
}


void UdpSendPacket(struct udp_pcb *udp_socket, uint8 *data, uint16 len)
{
	struct pbuf *p;

	p = pbuf_alloc(PBUF_TRANSPORT, len, PBUF_POOL);

	if (p != NULL)
	{
		pbuf_take(p, (char*)data, len);
		udp_send(udp_socket, p);
		pbuf_free(p);
	}
}

void udp_client_disconnect(void)
{
	udp_disconnect(udp_socket_dst);
#ifdef HW_DEBUG
	udp_disconnect(udp_socket_dst_debug_pc);
#endif
}

void udp_client_mrr_disconnect(void)
{
	udp_disconnect(udp_socket_mrr_dst);
}

void udp_client_ic_disconnect(void)
{
	udp_disconnect(udp_socket_ic_dst);
}


/* Callback receive message for FIFO */
void udp_rcv_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
{
	unsigned char inc_id = 0;
	unsigned short len = 0;

	//dataRx = swDataRx ? &dataRx_0[0] : &dataRx_1[0];
	//swDataRx ^= 0x01U;

	memcpy(dataRx, (unsigned char*)p->payload, p->len);

	inc_id = dataRx[0];
    len = p->len;
    pbuf_free(p);
    readUdpPacket(inc_id, &dataRx[1], len);
    memset(dataRx, 0x00, len);
}

/* Debug Callback */
void udp_rcv_callback_debug_pc(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
{
	unsigned char inc_id = 0;
	unsigned short len = 0;

	memcpy(dataRx, (unsigned char*)p->payload, p->len);
    inc_id = dataRx[0];
    len = p->len;
    pbuf_free(p);
    readUdpPacket(inc_id, &dataRx[1], len);
}
