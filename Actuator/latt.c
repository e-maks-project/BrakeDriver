/*
 * latt.c
 *
 *  Created on: 23.08.2019
 *      Author: Lukas
 */
#include "latt.h"
#include "gpio.h"

extern pins_irq_handlers hal_pins_handlers;

//as default piston is propounded

static latt_function latt ={
		.stop_latt = hal_reset_pwms,
		.set_speed_forward = hal_set_pwm_1,
		.set_speed_backward = hal_set_pwm_2,
		.is_piston_retracted = is_actuator_low_limit_active,
		.is_piston_extended = is_actuator_high_limit_active,
		.set_enable_backward = set_enable_2,
		.set_enable_forward  = set_enable_1,
		.reset_enable_backward = reset_enable_2,
		.reset_enable_forward = reset_enable_1
};

static void max_length_reached(void){
	latt.set_speed_forward(0);

}

static void min_length_reached(void){
	latt.set_speed_backward(0);
}

static void set_forward_speed(float speed){
	if(latt.is_piston_extended()){
		latt.set_speed_forward(0);
	}else{
		latt.set_speed_backward(0);
		latt.set_speed_forward(speed);
	}
}
static void set_backward_speed(float speed){
	if(latt.is_piston_retracted()){
		latt.set_speed_backward(0);
	}else{
		latt.set_speed_forward(0);
		latt.set_speed_backward(speed);
	}
}

latt_function* get_latt_function_pointers(void){
	return &latt;
}

void set_latt_speed(latt_move_direction direction, float speed){

	if(direction == move_forward){
		latt.reset_enable_backward();
		latt.set_enable_forward();
		set_forward_speed(speed);
	}else{
		latt.reset_enable_forward();
		latt.set_enable_backward();
		set_backward_speed(speed);

	}
}

void init_latt_driver(void){

	hal_pins_handlers.high_limit_activated_handler = max_length_reached;
	hal_pins_handlers.low_limit_activated_handler = min_length_reached;
}
