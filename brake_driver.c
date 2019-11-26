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
		HAL_Delay(10000);
			control_brakes(get_joy_data()->direction);
			reset_joy_data();

		/* tests
			set_latt_speed(move_forward,100);
				HAL_Delay(5000);
				set_latt_speed(move_backward,100);
				HAL_Delay(5000);

			send_test_frame();
			test_get_rx_message();
			*/
		}

}
