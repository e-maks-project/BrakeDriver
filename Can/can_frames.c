/*
 * can_frames.c
 *
 *  Created on: 01.09.2019
 *      Author: Lukas
 */

#include <math.h>
#include "can_frames.h"
#include "coder.h"
can_rx_interrupt_handler hal_can_rx={
		.process_message =decode_joy_data
};

can_message messages[]={
		{.frame_id = USER_INTERFACE_X_AXIS_FRAME ,.dlc = USER_INTERFACE_DLC},
		{.frame_id = CONFIRMATION_FRAME_ID, .dlc = CONFIRMATION_FRAME_DLC}
};

can_functions hardware_can= {
		.can_transmit = hal_can_send
 };

uint16_t decode_uint8_to_uint16(uint8_t* data, uint8_t start_byte){
	return ((uint16_t)data[start_byte + 1] << 8) | (uint16_t)data[start_byte];
}

void send_confirmation(uint8_t* data, uint8_t length){

	messages[1].data = data;
	if(hardware_can.can_transmit != NULL){
		hardware_can.can_transmit(messages[1].frame_id,messages[1].dlc,messages[1].data);
	}
}

uint16_t decode_joy_data(uint32_t frame_id, uint8_t* data, uint8_t dlc){
	// write tests for it
	if(frame_id == USER_INTERFACE_X_AXIS_FRAME){
		send_confirmation(data,dlc);
		return decode_uint8_to_uint16(data,FRAME_AXIS_VALUE_START_BYTE);
	}
	return NO_CAN_DATA;
}

//for tests purposes
void send_test_frame(void){
	hardware_can.can_transmit(0x0F0, 4, (uint8_t[]){0xDE, 0xAD, 0xBE, 0xEF});
}




