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

typedef struct{
	uint16_t speed_value_encoded;
	float speed_value_decoded;
}actuator_parameters;
extern actuator_parameters latt;


#endif /* ACTUATOR_LATT_H_ */
