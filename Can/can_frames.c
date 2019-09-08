/*
 * can_frames.c
 *
 *  Created on: 01.09.2019
 *      Author: Lukas
 */

#include <math.h>
#include "can_frames.h"
#include "coder.h"
can_message messages[]={
		{.frame_id = USER_INTERFACE_FRAME_ID ,.dlc = USER_INTERFACE_FRAME_DLC},
		{.frame_id = CONFIRMATION_FRAME_ID, .dlc = CONFIRMATION_FRAME_DLC}
};

can_functions hardware_can= {
		.can_transmit = hal_can_send,
		//.can_recive =
};

void send_test_frame(void){
	hardware_can.can_transmit(0x0F0, 4, (uint8_t[]){0xDE, 0xAD, 0xBE, 0xEF});
}


void send_confirmation(uint8_t* data, uint8_t length){
	uint8_t data_to_encode[]={
				data[1],
				data[0]
		};
	 uint8_t* encoded_data = encode_frame_big_endian(data_to_encode,length);
	messages[1].data =  encoded_data;
	free(encoded_data);
}


uint16_t* couple_frame_data_to_uint16(uint8_t* data, uint8_t length){
	static uint16_t extracted_data[4];

	for(uint8_t i = 1 ;  i < length ; i += 2){
		extracted_data[i] = (uint16_t)data[i-1] | ((uint16_t)data[i] << 8);
	}
	return extracted_data;
}

uint16_t  extract_joy_data(uint16_t* coupled_data){
	if(coupled_data[0] == 0){
		return coupled_data[1];
	}
}

