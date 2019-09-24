/*
 * latt.c
 *
 *  Created on: 23.08.2019
 *      Author: Lukas
 */
#include "latt.h"

extern pins_irq_handlers hal_pins_handlers;
actuator_parameters latt ={
		.is_max_length_reached = TRUE,
		.is_min_length_reached = FALSE
};
latt_function hardware_functions ={
		.stop_latt = hal_reset_pwms,
		.set_speed_forward = hal_set_forward_pwm,
		.set_speed_backward = hal_set_backward_pwm,
		.enable_latt_driver = hal_set_piston_enable_pins,
		.disable_latt_driver = hal_reset_piston_enable_pins
};

void max_length_reached(void){
	latt.is_max_length_reached = TRUE;
	latt.is_min_length_reached = FALSE;
}

void min_length_reached(void){
	latt.is_max_length_reached = FALSE;
	latt.is_min_length_reached = TRUE;
}
void init_irq_functions(void){
	hal_pins_handlers.high_limit_activated_handler = max_length_reached;
	hal_pins_handlers.low_limit_activated_handler = min_length_reached;
}


bool is_edge_reached(void){
	return (latt.is_max_length_reached == TRUE
			|| latt.is_min_length_reached == TRUE);
}

void set_latt_speed(float encoded_speed){
	//todo Lukas fill this
	//todo Lukas create tests first
}






