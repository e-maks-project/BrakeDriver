#include "unity.h"
#include "brakes.h"
#include "latt.h"
#include "gpio.h"
#include "tim.h"


static uint16_t  forward_speed = 0;
static uint16_t  backward_speed = 0;

bool read_inactive(void){
	return FALSE;
}

bool read_active(void){
	return TRUE;
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
	get_latt_function_pointers()->is_piston_extended = read_inactive;
	get_latt_function_pointers()->is_piston_retracted = read_inactive;
}

void tearDown(void)
{
}
void test_set_up(void){
	get_latt_function_pointers()->disable_latt_driver = disable_latt_mock;
	get_latt_function_pointers()->enable_latt_driver = enable_latt_mock;
	get_latt_function_pointers()->is_piston_extended = read_inactive;
	get_latt_function_pointers()->is_piston_retracted = read_inactive;
	get_latt_function_pointers()->set_speed_backward = set_backward_pwm_mock;
	get_latt_function_pointers()->set_speed_forward = set_forward_pwm_mock;
	get_latt_function_pointers()->stop_latt = reset_pwm_mock;
}

void test_control_brakes_brakes_turned_on_braking(void){
	// arrange
	get_latt_function_pointers()->is_piston_extended = read_active;

	// act
	control_brakes(0);

	// assert
	TEST_ASSERT_TRUE(are_brakes_turned_on());
	TEST_ASSERT_EQUAL_UINT16(0,forward_speed);
	TEST_ASSERT_EQUAL_UINT16(0,backward_speed);
}

void test_control_brakes_brakes_turned_on_no_braking(void){
	// arrange
	get_latt_function_pointers()->is_piston_extended = read_active;

	// act
	control_brakes(1.0);

	// assert
	TEST_ASSERT_TRUE(are_brakes_turned_on());
	TEST_ASSERT_EQUAL_UINT16(0,forward_speed);
	TEST_ASSERT_EQUAL_UINT16(80,backward_speed);
}

void test_control_brakes_turned_off_braking(void){
	// arrange
	get_latt_function_pointers()->is_piston_extended = read_inactive;

	// act
	control_brakes(0);

	// assert
	TEST_ASSERT_FALSE(are_brakes_turned_on());
	TEST_ASSERT_EQUAL_UINT16(80,forward_speed);
	TEST_ASSERT_EQUAL_UINT16(0,backward_speed);
}

void test_control_brakes_turned_off_not_braking(void){
	// arrange
	get_latt_function_pointers()->is_piston_extended = read_inactive;
	get_latt_function_pointers()->is_piston_retracted = read_active;

	// act
	control_brakes(1.0);

	// assert
	TEST_ASSERT_FALSE(are_brakes_turned_on());
	TEST_ASSERT_EQUAL_UINT16(0,forward_speed);
	TEST_ASSERT_EQUAL_UINT16(0,backward_speed);
}
