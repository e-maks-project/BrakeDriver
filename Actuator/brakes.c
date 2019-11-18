/*
 * brake_driver.c
 *
 *  Created on: 29.09.2019
 *      Author: Lukas
 */

#include "brakes.h"
#include "latt.h"


static brake_status brake ={
		.is_brake_closed = TRUE,
		.is_brake_open   = FALSE
};

static void update_break_status(void){
	latt_function* latt = get_latt_function_pointers();
	brake.is_brake_open = latt->is_piston_retracted();
	brake.is_brake_closed = latt->is_piston_extended();
}


bool are_brakes_turned_on(void){
	return brake.is_brake_closed;
}

//todo Lukas: create brake open structure
void control_brakes(uint8_t joy_direction ){
	update_break_status();
	stop_latt();
	if(joy_direction == 0 ){
		set_latt_speed(enable_brake,80);
	}else{
		set_latt_speed(disable_brake,80);
	}
}

