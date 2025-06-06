#include "MRRX_UDP.h"
#include "MRRX_DATA_Buff.h"
#include <CAN_Extern.h>
#include <../UDP/inc/udp_echoclient.h>

volatile unsigned short nOfFrame = 0;

void MRRX_UDP_Release()
{
		if (fMrrxDataSendUdp == 1 || Mrrx_data_state_buff.buff_mode_a.buff_mode == is_full)
		{
			fMrrxDataSendUdp = 0;

			if (Mrrx_data_state_buff.buff_mode_a.buff_mode == is_full)
			{
				cntMrrxDataSendUdp = 0;
			}

			if (((SystemTime - Mrrx_data_state_buff.buff_lastMessageTime) >= 100) && (Mrrx_data_state_buff.buff_timeout == FALSE))
			{
				Mrrx_data_state_buff.buff_timeout = TRUE;
				Mrrx_data_state_buff.buff_mode_a.buff_num_of_packet = 0;
				nOfFrame= 0;
			}

			uint16 nOfpack = 0;

			if (nOfFrame > 0)	// 10
			{
				nOfFrame = 0;
				nOfpack = Mrrx_data_state_buff.buff_mode_a.buff_num_of_packet;	// nOfPack = 10
				prepareUdpPacket(Mrrx_data_buff_a, udp_rr_data_packet, nOfpack);	// 10
				UdpSendPacket(udp_socket_mrr_dst, Mrrx_data_buff_a, ((nOfpack*(sizeof(udp_rr_data_packet_t)))+1));
/*
				can_msg_t test_msg= {
						.ide = kCanIdStd,
				        .id = 0x003,
				        .rtr = kCanRtrData,
				        .fdf = kCanFdTypeClassic,
				        .len = 1
				        };
				        test_msg.data[0] = 0xDD;
				        DEBUG_CAN(0, &test_msg);
*/
			}

			Mrrx_data_state_buff.buff_mode_a.buff_mode = is_fill;
		}
}
