/*
 * brake_driver.c
 *
 *  Created on: 18.08.2019
 *      Author: Lukas
 */
#include "brake_driver.h"
#include "can_frames.h"
#include "brakes.h"
#include "latt.h"
extern TIM_HandleTypeDef htim3;

int main(void){
	hal_init();
	init_latt_driver();
	float speed =0 ;
	while(1){
		if (htim3.Instance->CNT == 300){
				//control_brakes(speed);
				set_latt_speed(move_forward,80);
				set_latt_speed(move_backward,80);
				printf("can_sending...\n");
				send_test_frame();
				printf("can sent \n");
				printf("\n\n");



			// set speed cording to can frames

		}

	}
}
