#include "adc.h"

uint32_t adc_raw_values[4];

void fill_adc_raw_values(uint32_t* data){
	for(uint8_t i = 0 ; i < 4; i++){
		adc_raw_values[i] = *(data + i);
	}
}


uint32_t* get_raw_adc_data(void){
	return adc_raw_values;
}
