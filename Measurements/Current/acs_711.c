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
uint32_t* adc_encoded_data = //&adc_raw_values[ADC_ACS_INDEX];
current_measurement acs_data;

current_measurement* get_current_ptr(void){
	return &acs_data;
}

static  float decode_voltage(uint32_t encoded_voltage){
	float  voltage = (float)((float)encoded_voltage *STM32_ADC_REFERENCE_VOLTAGE
			/ STM32_ADC_RESOLUTION);
	acs_data.is_fault = (voltage > STM32_ADC_REFERENCE_VOLTAGE)? TRUE : FALSE;
	return (!acs_data.is_fault)? voltage : 0.0;
}
//todo Lukas : make units calculations
static float decode_current(float voltage){
	return (float)((voltage - ACS_711_OFFSET
			* (ACS_711_SENSITIVITY/1000)));
}

// todo Lukas: replace magic number
void calculate_current(void){
	acs_data.voltage.encoded = *adc_encoded_data;
	acs_data.voltage.decoded = decode_voltage(*adc_encoded_data);
	acs_data.current.decoded = decode_current(acs_data.voltage.decoded);
}

