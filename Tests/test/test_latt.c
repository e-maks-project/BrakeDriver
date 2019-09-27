#include "unity.h"
#include "latt.h"
#include "gpio.h"
#include "tim.h"


static forward_speed = 0;
static backward_speed = 0;

bool read_high_pin_mock(void){
	return TRUE;
}

bool read_low_pin_mock(void){
	return FALSE;
}

void set_forward_pwm_mock(uint16_t speed){
	forward_speed = speed;
};
void set_backward_pwm_mock(uint16_t speed){
	backward_speed = speed;
};
void reset_pwm_mock(void){}
void disable_latt_mock(void){}
void enable_latt_mock(void){}

void setUp(void)
{
	get_latt_function_pointers()->disable_latt_driver = disable_latt_mock;
	get_latt_function_pointers()->enable_latt_driver = enable_latt_mock;
	get_latt_function_pointers()->is_high_limit_active = read_low_pin_mock;
	get_latt_function_pointers()->is_low_limit_active = read_low_pin_mock;
	get_latt_function_pointers()->set_speed_backward = set_backward_pwm_mock;
	get_latt_function_pointers()->set_speed_forward = set_forward_pwm_mock;
	get_latt_function_pointers()->stop_latt = reset_pwm_mock;

	forward_speed = 0;
	backward_speed = 0;
}

void tearDown(void)
{
}

void test_set_latt_forward_speed_normal_case(void){
	// arrange
	// act
	set_latt_speed(move_forward, 500);

	// assert
	TEST_ASSERT_EQUAL_UINT16(500, forward_speed);
	TEST_ASSERT_EQUAL_UINT16(0, backward_speed);
}

void test_set_latt_forward_speed_min_reached(void){
	// arrange
	get_latt_function_pointers()->is_high_limit_active = read_low_pin_mock;
	get_latt_function_pointers()->is_low_limit_active = read_high_pin_mock ;

	// act
	set_latt_speed(move_forward, 500);

	// assert
	TEST_ASSERT_EQUAL_UINT16(500, forward_speed);
	TEST_ASSERT_EQUAL_UINT16(0, backward_speed);
}

void test_set_latt_forward_speed_max_reached(void){
	// arrange
	get_latt_function_pointers()->is_high_limit_active = read_high_pin_mock;

	// act
	set_latt_speed(move_forward, 500);

	// assert
	TEST_ASSERT_EQUAL_UINT16(0, forward_speed);
	TEST_ASSERT_EQUAL_UINT16(0, backward_speed);
}

void test_set_latt_backward_speed_normal_case(void){
	//arrange
	// act
	set_latt_speed(move_backward, 500);

	// assert
	TEST_ASSERT_EQUAL_UINT16(0, forward_speed);
	TEST_ASSERT_EQUAL_UINT16(500, backward_speed);
}

void test_set_latt_backward_speed_max_reached(void){
	// arrange
	get_latt_function_pointers()->is_high_limit_active = read_high_pin_mock;

	// act
	set_latt_speed(move_backward, 500);

	// assert
	TEST_ASSERT_EQUAL_UINT16(0, forward_speed);
	TEST_ASSERT_EQUAL_UINT16(500, backward_speed);
}

void test_set_latt_backward_speed_min_reached(void){
	// arrange
	get_latt_function_pointers()->is_low_limit_active = read_high_pin_mock;

	// act
	set_latt_speed(move_backward, 500);

	// assert
	TEST_ASSERT_EQUAL_UINT16(0, forward_speed);
	TEST_ASSERT_EQUAL_UINT16(0, backward_speed);
}
