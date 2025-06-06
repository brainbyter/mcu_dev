#include <Platform_Types.h>
#include <MRRX_DATA_Buff.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8 Mrrx_data_buff_a[1301];
udp_rr_data_packet_t udp_rr_data_packet[100];
Mrrx_data_state_buff_t Mrrx_data_state_buff;

void fill_can_message(udp_rr_data_packet_t *ptr, can_msg_t* inc_msg)
{
	memset(ptr->data, 0x00, sizeof(udp_rr_data_packet_t));	// clear data
	ptr->type_frame = 0x00;
	ptr->rtr_frame = 0x00;
	ptr->dlc_frame = inc_msg->len;
	ptr->id = reverse_bit32(inc_msg->id);
	memcpy(ptr->data, inc_msg->data, inc_msg->len);
}

void prepareUdpPacket(uint8 *udpPacketBuffer, udp_rr_data_packet_t *p_udp_rr_data_packet, uint16 nOfPackets)
{
	udpPacketBuffer[0] = 0x1F;
	memcpy(&udpPacketBuffer[1], p_udp_rr_data_packet, nOfPackets*sizeof(udp_rr_data_packet_t));	// 10*13=130
}

uint32 reverse_bit32(uint32 x)
{
	return (x&0xFF000000)>>24 | (x&0x000000FF)<<24 | (x&0x00FF0000)>>8 | (x&0x0000FF00)<<8;
}
