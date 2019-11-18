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
		.set_speed = hal_set_pwm,
		.set_motor_dir = set_motor_dir_pin,
		.is_piston_retracted = is_actuator_low_limit_active,
		.is_piston_extended = is_actuator_high_limit_active,
};

static void max_length_reached(void){
	latt.set_speed(0);
}

static void min_length_reached(void){
	latt.set_speed(0);
}

static void set_forward_speed(float speed){
	latt.set_speed(speed);
}

latt_function* get_latt_function_pointers(void){
	return &latt;
}

void set_latt_speed(latt_move_direction direction, float speed){
		latt.set_motor_dir((bool)direction);
		set_forward_speed(speed);
}
void stop_latt(void){

}

void init_latt_driver(void){

	hal_pins_handlers.high_limit_activated_handler = max_length_reached;
	hal_pins_handlers.low_limit_activated_handler = min_length_reached;
}
