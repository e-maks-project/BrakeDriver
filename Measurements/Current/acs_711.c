/*
 * acs_711.c
 *
 *  Created on: 18.08.2019
 *      Author: Lukas
 */
#include "acs_711.h"
// todo Lukas create tests

//todo Lukas: do something with it
extern uint32_t adc_raw_values[];
uint32_t* adc_encoded_data = &adc_raw_values[ADC_ACS_INDEX];
current_measurement acs_data;

current_measurement* get_current_ptr(void){
	return &acs_data;
}

float decode_voltage(uint32_t encoded_voltage){
	return (float)((float)encoded_voltage *STM32_ADC_REFERENCE_VOLTAGE
			/ STM32_ADC_RESOLUTION);
}

float unwrap_voltage(float voltage){
	return (float)((voltage - ACS_711_OFFSET
			* ACS_711_SENSITIVITY));
}

// todo Lukas: replace magic number
void calculate_current(void){
	acs_data.voltage.encoded = adc_encoded_data[0];
	acs_data.voltage.decoded = decode_voltage(adc_encoded_data[0]);
	acs_data.current.decoded = unwrap_voltage(acs_data.voltage.decoded);
}

