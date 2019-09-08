/*
 * brake_driver.c
 *
 *  Created on: 18.08.2019
 *      Author: Lukas
 */
#include "brake_driver.h"

extern TIM_HandleTypeDef htim3;

int main(void){
	hal_init();
	while(1){
		if (htim3.Instance->CNT == 900){
			printf("can_sending...\n");
			send_test_frame();
			printf("can sent \n");
			printf("\n\n");


		}

	}
}
