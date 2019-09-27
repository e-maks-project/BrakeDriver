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
	void (*enable_latt_driver)(void);       // dopisac piny w MX cube
	void (*disable_latt_driver)(void);      // dopisac piny MX cube
	void (*set_speed_forward)(uint16_t);
	void (*set_speed_backward)(uint16_t);
	bool (*is_high_limit_active)(void);
	bool (*is_low_limit_active)(void);
	void (*stop_latt)(void);
}latt_function ;

void init_irq_functions(void);
latt_function* get_latt_function_pointers(void); // for tests purposes
void set_latt_speed(latt_move_direction direction, float speed);

#endif /* ACTUATOR_LATT_H_ */
