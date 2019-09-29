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

static void turn_on_brakes(void){
	if(!brake.is_brake_open){
		set_latt_speed(move_forward, 80);// 80% PWM
	}else{
		set_latt_speed(move_forward,0);
	}
}

static void turn_off_brakes(void){
	if(!brake.is_brake_open){
		set_latt_speed(move_backward, 80);// 80% PWM
	}else{
		set_latt_speed(move_backward,0);
	}

}

void control_brakes(float speed){
	update_break_status();
	set_latt_speed(move_forward, 0);
	set_latt_speed(move_backward, 0);
	if(speed == 0 ){
		turn_on_brakes();
	}else{
		turn_off_brakes();
	}

}

