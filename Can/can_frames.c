/*
 * can_frames.c
 *
 *  Created on: 01.09.2019
 *      Author: Lukas
 */

#include <math.h>
#include "can_frames.h"
#include "coder.h"
#include "latt.h"
can_rx_interrupt_handler hal_can_rx;

can_message messages[]={
		{.frame_id = USER_INTERFACE_X_AXIS_FRAME ,.dlc = USER_INTERFACE_DLC},
		{.frame_id = USER_INTERFACE_Y_AXIS_FRAME, .dlc = USER_INTERFACE_DLC}
};

can_functions hardware_can= {
		.can_transmit = hal_can_send
 };

uint16_t decode_uint8_to_uint16(uint8_t* data, uint8_t start_byte){
	return (uint16_t)data[start_byte + 1] + (uint16_t)(data[start_byte] << 8);
}

void decode_received_data(uint32_t frame_id, uint8_t* data, uint8_t dlc){
	if(frame_id == USER_INTERFACE_X_AXIS_FRAME){
		//todo Lukas decode uint16 to float, write some test
	}

}

void send_test_frame(void){
	hardware_can.can_transmit(0x0F0, 4, (uint8_t[]){0xDE, 0xAD, 0xBE, 0xEF});
}

void send_confirmation(uint8_t* data, uint8_t length){

	messages[1].data = data;
	if(hardware_can.can_transmit != NULL){
		hardware_can.can_transmit(messages[1].frame_id,messages[1].dlc,messages[1].data);
	}
}

uint16_t  extract_joy_data(uint16_t* coupled_data){
	if(coupled_data[0] == 0){
		return coupled_data[1];
	}
	return 0;
}


