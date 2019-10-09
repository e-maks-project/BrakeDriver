/*
 * brake_driver.c
 *
 *  Created on: 18.08.2019
 *      Author: Lukas
 */
#include "brake_driver.h"
#include "brakes.h"
#include "latt.h"
extern TIM_HandleTypeDef htim3;

int main(void){
	hal_init();
	init_latt_driver();
	float speed = 0;
	while(1){
		if (htim3.Instance->CNT == 300){
			// set speed cording to can frames
			control_brakes(speed);
		}

	}
}
