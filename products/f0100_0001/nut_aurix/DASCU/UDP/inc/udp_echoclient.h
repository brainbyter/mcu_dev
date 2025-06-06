#ifndef __UDP_ECHOCLIENT_H__
#define __UDP_ECHOCLIENT_H__

#include "Ifx_reg.h"
#include "Ifx_Types.h"
#include "IfxStm.h"

extern unsigned int udpSendPrepareCounter;
extern unsigned int udpSendPrepare;

extern struct udp_pcb *udp_socket_src;
extern struct udp_pcb *udp_socket_dst;
extern struct udp_pcb *udp_socket_mrr_dst;
extern struct udp_pcb *udp_socket_ic_dst;

extern struct udp_pcb *udp_socket_src_debug_pc;
extern struct udp_pcb *udp_socket_dst_debug_pc;


void udp_client_connect(void);
void udp_client_mrr_connect(void);
void udp_client_ic_connect(void);
extern void UdpSendPacket(struct udp_pcb *udp_socket, uint8 *data, uint16 len);

void udp_client_disconnect(void);
void udp_client_mrr_disconnect(void);
void udp_client_ic_disconnect(void);
#endif /* __UDP_ECHOCLIENT_H__ */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
