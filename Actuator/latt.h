/*
 * latt.h
 *
 *  Created on: 23.08.2019
 *      Author: Lukas
 */

#ifndef ACTUATOR_LATT_H_
#define ACTUATOR_LATT_H_
/* parameters for LATT -4A /27/3-100-C-2M-E1 */

#include "gpio.h"
#include "tim.h"

#define LATT_MAX_SPEED  16 // mm/s
#define NOMINAL_LOAD	45 // Kg
#define NO_LOAD_CURRENT	0,5// A

typedef enum{
	move_forward,
	move_backward
}latt_move_direction;

typedef struct{
	void (*set_speed_forward)(uint16_t);
	void (*set_speed_backward)(uint16_t);
	bool (*is_piston_retracted)(void);
	bool (*is_piston_extended)(void);
	void (*stop_latt)(void);
}latt_function ;

latt_function* get_latt_function_pointers(void);
void init_latt_driver(void);
void set_latt_speed(latt_move_direction direction, float speed);

#endif /* ACTUATOR_LATT_H_ */
