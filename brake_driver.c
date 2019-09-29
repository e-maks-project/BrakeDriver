/*
 * brake_driver.c
 *
 *  Created on: 18.08.2019
 *      Author: Lukas
 */
#include "brake_driver.h"
#include "brakes.h"
extern TIM_HandleTypeDef htim3;

int main(void){
	hal_init();
	float speed = 0;
	while(1){
		if (htim3.Instance->CNT == 300){
			//wait and check if new frame arrived
			//control_brakes(speed);

			printf("can_sending...\n");
			send_test_frame();
			printf("can sent \n");
			printf("\n\n");


		}

	}
}
