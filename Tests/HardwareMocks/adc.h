
#ifndef _HARDWAREMOCK_ADC_H_
#define _HARDWAREMOCK_ADC_H_
#include "stm32f1xx_hal.h"
#define NUMBER_OF_ADC_CHANNLES  3
#define ADC_ACS_INDEX    	    0
#define ADC_1_INDEX				1
#define ADC_2_INDEX				2

#define STM32_ADC_RESOLUTION  4096.0f
#define STM32_ADC_REFERENCE_VOLTAGE 3.3f

void fill_adc_raw_values(uint32_t* data);
uint32_t* get_raw_adc_data(void);

#endif
