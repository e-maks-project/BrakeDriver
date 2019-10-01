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
	while(1){
		if (htim3.Instance->CNT == 300){
			if(get_joy_data()->is_data_new){
				//pass joy data to brakes
				reset_joy_data();
			}else{
				//turn off brakes
			}
			printf("can_sending...\n");
			send_test_frame();
			printf("can sent \n");
			printf("\n\n");

		}

	}
}
