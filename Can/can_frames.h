/*
 * cna_frames.h
 *
 *  Created on: 01.09.2019
 *      Author: Lukas
 */

#ifndef CAN_CAN_FRAMES_H_
#define CAN_CAN_FRAMES_H_

#include "can.h"

#define USER_INTERFACE_FRAME_ID  0XD45
#define CONFIRMATION_FRAME_ID	 0xD10

#define USER_INTERFACE_FRAME_DLC 2
#define CONFIRMATION_FRAME_DLC   2

typedef struct{
	void (*can_transmit)(uint16_t, uint8_t, uint8_t*);
	void (*can_recive)(uint16_t, uint8_t, uint8_t*);
	uint8_t hardware_functions_attached;
}can_functions;

typedef struct{
	uint8_t* data;
	uint8_t dlc;
	uint16_t frame_id;
}can_message;


void send_test_frame(void);
#endif /* CAN_CAN_FRAMES_H_ */
