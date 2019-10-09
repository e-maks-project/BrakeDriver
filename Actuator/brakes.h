/*
 * brake_driver.h
 *
 *  Created on: 29.09.2019
 *      Author: Lukas
 */

#ifndef ACTUATOR_BRAKES_H_
#define ACTUATOR_BRAKES_H_
#include <stdio.h>
#include "main.h"

typedef struct{
	bool is_brake_open;
	bool is_brake_closed;
}brake_status;

void control_brakes(float speed);
bool are_brakes_turned_on(void);
#endif /* ACTUATOR_BRAKES_H_ */
