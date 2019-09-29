/*
 * acs_711.h
 *
 *  Created on: 18.08.2019
 *      Author: Lukas
 */

#ifndef CURRENT_ACS_711_H_
#define CURRENT_ACS_711_H_
#include "adc.h"
/* for acs 711 KLC-25AB*/
#define ACS_711_SENSITIVITY   55.0f // mV/A
#define ACS_NOISE             8.0f  //mV/A
#define ACS_711_OUTPUT_ERROR  4.0f  //%
#define ACS_711_OFFSET		  1.5f // I = 0 , V = 1,5V


typedef struct{
	uint32_t encoded;
	float decoded;
}data;

typedef struct{
	bool is_fault;
	data voltage;
	data current;
}current_measurement;

current_measurement* get_current_ptr(void);
void calculate_current(void);
#endif /* CURRENT_ACS_711_H_ */
