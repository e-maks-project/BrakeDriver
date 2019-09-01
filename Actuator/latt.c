/*
 * latt.c
 *
 *  Created on: 23.08.2019
 *      Author: Lukas
 */
#include "latt.h"

extern pins_irq_handlers hal_pins_handlers;

void do_piston_propound(void){

}

void do_piston_slip(void){

}

void max_propound_actuator_activated(void){

}

void min_propound_actuator_activated(void){

}
void init_irq_functions(void){
	hal_pins_handlers.high_limit_activated_hadler = max_propound_actuator;
	hal_pins_handlers.low_limit_activated_hadler = min_propound_actuator;
}





