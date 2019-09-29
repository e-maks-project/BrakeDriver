#include "unity.h"
#include "acs_711.h"
#include "adc.h"




void setUp(void)
{
	get_current_ptr()->is_fault = FALSE;
}

void tearDown(void)
{
}


void test_decode_voltage_normal_case(void){
	// arrange
	fill_adc_raw_values((uint32_t[]){1200,3000,688,3900} );
	// act
	calculate_current();
	//assert
	TEST_ASSERT_EQUAL_UINT16(1200,get_current_ptr()->voltage.encoded);
	TEST_ASSERT_FLOAT_WITHIN(0.01, 0.966, get_current_ptr()->voltage.decoded);
	//TEST_ASSERT_FLOAT_WITHIN(0.01, get_current_ptr()->current);

}

void test_decode_voltage_value_over_max(void){

}

void test_decode_voltage_value_below_min(void){

}

void test_decode_current_normal_case(void){

}

void test_decode_current_over_max_value(void){

}

void test_decode_current_below_min_value(void){

}

void test_decode_current_value_over_maximum_raitings(void){

}

void test_decode_current_value_over_below_minimum_ratings(void){

}
