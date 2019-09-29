/*
 * coders.h
 *
 *  Created on: 30.06.2019
 *      Author: Lukas
 */

#ifndef CAN_CODER_H_
#define CAN_CODER_H_
#include <math.h>
#include <malloc.h>

/* type defines for ceedling tests*/
#include "adc.h"

typedef struct{
	uint16_t bits;
	uint16_t offset;
	float range;
}coding_parameter;

uint16_t encode_float_to_uint16(float value, coding_parameter param);
uint8_t* encode_frame_big_endian(uint8_t* data , uint8_t data_length);
uint16_t* decode_fame_to_uint16(uint8_t* data, uint8_t* data_length);
float decode_uint16_to_float(uint16_t data, coding_parameter parameter);

extern coding_parameter uint16_5_5;
extern  coding_parameter int16_5_5;
#endif /* CAN_CODER_H_ */
