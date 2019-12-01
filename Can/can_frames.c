/*
 * can_frames.c
 *
 *  Created on: 01.09.2019
 *      Author: Lukas
 */

#include <math.h>
#include "can_frames.h"
#include "coder.h"
extern can_rx_interrupt_handler hal_can_rx={
		.process_message =decode_joy_data
};

static joy_data joy ={
		.data = 0.0
};

static can_message messages[]={
		{.frame_id = USER_INTERFACE_X_AXIS_FRAME ,.dlc = USER_INTERFACE_DLC},
		{.frame_id = CONFIRMATION_FRAME_ID, .dlc = CONFIRMATION_FRAME_DLC}
};

can_functions hardware_can= {
		.can_transmit = hal_can_send
 };

static uint16_t decode_uint8_to_uint16(uint8_t* data, uint8_t start_byte){
	return ((uint16_t)data[start_byte + 1] << 8) | (uint16_t)data[start_byte];
}

static void send_confirmation(uint8_t* data, uint8_t length){

	messages[1].data = data;
	if(hardware_can.can_transmit != NULL){
		hardware_can.can_transmit(messages[1].frame_id,messages[1].dlc,messages[1].data);
	}
}
void decode_joy_data(uint32_t frame_id, uint8_t* data, uint8_t dlc){
	// write tests for it
	if(frame_id == USER_INTERFACE_X_AXIS_FRAME){
		send_confirmation(data,dlc);
		uint16_t joy_data = decode_uint8_to_uint16(data,0);
		joy.direction =decode_uint8_to_uint16(data,2);
		joy.data = decode_uint16_to_float(joy_data,uint16_5_5);
	}
}

//todo Lukas place it after brakes controll function
void reset_joy_data(void){
	joy.data = 0.0;
}


joy_data* get_joy_data(void){

	return &joy;
}

//for tests purposes
void send_test_frame(void){
	hardware_can.can_transmit(0x0F0, 4, (uint8_t[]){0xDE, 0xAD, 0xBE, 0xEF});
}
