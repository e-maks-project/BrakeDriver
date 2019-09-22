/*
 * coders.c
 *
 *  Created on: 30.06.2019
 *      Author: Lukas
 */
#include "coder.h"
#include <malloc.h>

coding_parameter uint16_5_5 ={.bits =16, .offset = 0,.range = 100};
coding_parameter int16_5_5 = {.bits = 16, .offset = 127,.range =100};

uint16_t encode_float_to_uint16(float value, coding_parameter param){
	if( value > param.range){
		return 0;
	}
	return(uint16_t)((value + param.offset) * pow(2,param.bits) /param.range);
}

uint8_t* encode_frame_big_endian(uint8_t* data , uint8_t data_length){
	 uint8_t* encoded_data = (uint8_t*)calloc(data_length, sizeof(uint8_t));
	for( uint8_t i = 1 ; i <= data_length  ;i++){
		encoded_data[i] = data[data_length-i];
	}
	return encoded_data;
}

uint16_t* decode_fame_to_uint16(uint8_t* data, uint8_t* data_length){
	uint16_t* decoded_frame_data = (uint16_t*)calloc(data_length,sizeof(uint16_t));
	for( uint8_t i = 1 ; i < data_length; i+=2){
		decoded_frame_data = (uint16_t)data[i-1] +((uint16_t)data[i] << 8);
	}
	return decoded_frame_data;
}

uint16 decode_uint8_to_uint16(uint8* uint8_data, uint8 start_byte){
	return (uint16)uint8_data[start_byte + 1]
										+ uint8_data[start_byte];
}
