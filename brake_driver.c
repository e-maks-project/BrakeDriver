/*
 * brake_driver.c
 *
 *  Created on: 18.08.2019
 *      Author: Lukas
 */
#include "brake_driver.h"
#include "can_frames.h"
extern TIM_HandleTypeDef htim3;

int main(void){
 	hal_init();

 	uint16_t frame_id;
 	uint8_t received_data[8]={0};

	while(1){
			HAL_Delay(5000);
			send_test_frame();
			receive_raw_can__data(&frame_id,received_data);
	}

}
