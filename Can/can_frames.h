/*
 * cna_frames.h
 *
 *  Created on: 01.09.2019
 *      Author: Lukas
 */

#ifndef CAN_CAN_FRAMES_H_
#define CAN_CAN_FRAMES_H_

#include "can.h"

#define USER_INTERFACE_X_AXIS_FRAME  0x21D
#define USER_INTERFACE_Y_AXIS_FRAME  0X22D
#define USER_INTERFACE_DLC			 4

#define CONFIRMATION_FRAME_ID	 		0x01D
#define CONFIRMATION_FRAME_DLC          2
#define  FRAME_AXIS_VALUE_START_BYTE    2

#define NO_CAN_DATA						0xFFFF

typedef struct{
	void (*can_transmit)(uint16_t, uint8_t, uint8_t*);
	void (*can_recive)(uint32_t, uint8_t*, uint8_t);
	uint8_t hardware_functions_attached;
}can_functions;

typedef struct{
	uint8_t* data;
	uint8_t dlc;
	uint16_t frame_id;
}can_message;

typedef struct{
	float data;
	uint8_t direction;
}joy_data;

extern can_functions hardware_can;

void send_test_frame(void);
joy_data* get_joy_data(void);
void reset_joy_data(void);
void decode_joy_data(uint32_t frame_id, uint8_t* data, uint8_t dlc);
#endif /* CAN_CAN_FRAMES_H_ */
