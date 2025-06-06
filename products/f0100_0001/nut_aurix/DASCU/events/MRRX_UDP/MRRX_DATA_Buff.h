#include <Platform_Types.h>
#include "bsp_can.h"

typedef enum
{
	is_fill = 0x00,
	is_full = 0x01
} buff_mode_t;

typedef enum
{
	buff_A = 0x00,
	buff_B = 0x01
} data_buff_t;


typedef struct
{
	buff_mode_t buff_mode;
	uint16 buff_num_of_packet;
} mrxx_buff_mode_t;

typedef struct
{
	data_buff_t data_buff;
	mrxx_buff_mode_t buff_mode_a;
	mrxx_buff_mode_t buff_mode_b;
	boolean buff_timeout;
	uint32 buff_lastMessageTime;
} Mrrx_data_state_buff_t;

#pragma align 1
typedef struct __packed__
{
	uint8 dlc_frame : 4;
	uint8 : 2;
	uint8 rtr_frame : 1;
	uint8 type_frame : 1;
	uint32 id;
	uint8 data[8];
} udp_rr_data_packet_t;
#pragma align restore



extern uint8 Mrrx_data_buff_a[1301];
extern udp_rr_data_packet_t udp_rr_data_packet[100];
extern Mrrx_data_state_buff_t Mrrx_data_state_buff;

extern uint32 reverse_bit32(uint32 x);
extern void fill_can_message(udp_rr_data_packet_t *ptr, can_msg_t* inc_msg);
extern void prepareUdpPacket(uint8 *udpPacketBuffer, udp_rr_data_packet_t *p_udp_rr_data_packet, uint16 nOfPackets);
