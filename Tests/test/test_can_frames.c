#include "unity.h"
#include "can_frames.h"
#include "can.h"
#include "coder.h"


void can_transmit_mock(uint16_t id, uint8_t dlc, uint8_t* data){}


void setUp(void)
{
	hardware_can.can_transmit = can_transmit_mock;
}

void tearDown(void)
{
}

void test_decode_joy_data_normal_case(void){
	// arrange
	uint8_t test_data[] = {0xEF,0xBE,0xAD, 0xDE};

	// act
	uint16_t test_results = decode_joy_data(
			USER_INTERFACE_X_AXIS_FRAME,test_data, USER_INTERFACE_DLC);

	// assert
	TEST_ASSERT_EQUAL_HEX(0xDEAD, test_results);
}

void test_decode_joy_data_wrong_frame_id(void){
	// arrange
	uint8_t test_data[2] = {0xAD, 0xDE};

	// act
	uint16_t test_results = decode_joy_data(
			0xBEEF,test_data, USER_INTERFACE_DLC);

	// assert
	TEST_ASSERT_EQUAL_UINT16(0xFFFF, test_results);
}
