/*
 * cna_frames.h
 *
 *  Created on: 01.09.2019
 *      Author: Lukas
 */

#ifndef CAN_CAN_FRAMES_H_
#define CAN_CAN_FRAMES_H_

#include "can.h"

/*
 * can interface
 * can interface jest zgodny z protoko³em do projektu E-maks
 *
 * send_test_frame(ID, lenght, data)
 * - ID(uint16 - uint16 Id ramki
 * - length(uint8) - ilosc danych w ramce ( w B)
 * - data(uint8) - skaŸnik na tablice danych
 *  funkcja s³uzy do wysy³¹nia randomowych testowych ramek
 *
 *
 *raw_received_data(uint16* received_id, uint8* received_data)
 *raw_received_data(uint16* funkcja s³uzy do odbierania ramek CAN, mo¿na j¹ wstawic w petle glowna programu
 *- received_id(uint16) - wskaznik na globalna zmienn¹ aplikacji tzrymaj¹ca addres ramki
 *- received_data(uin8*)- wskaznika na tablice 8B trzymaj¹ca dane z ottzymanej ramki
 *-
 *-void decode_joy_data(uint32_t frame_id, uint8_t* data, uint8_t dlc);
 *-void funkcja dekoduje surowe dane z CANA na wartoœc wychylenia potencjometru w USERINTERFACE BOARD
 *- frame_id(uint32) - id ramki która przysz³a, tylko ramnki zwychylenie joysticka bed¹ obslugiwane t¹ funkcjia
 *- data(uint8) - dane z ramkkiz wychyleniem joysticka( zarowno osie X jak i Y)
 *- dlc(uint8) - d³ugosc danych "data" zgodne z d³ugoscia ramki w CAN protocole E-maks, zalecane uzywanie USER_INTERFACE_DLC
 */


#define USER_INTERFACE_X_AXIS_FRAME  0x21D
#define USER_INTERFACE_Y_AXIS_FRAME  0X22D
#define USER_INTERFACE_DLC			 4

#define CONFIRMATION_FRAME_ID	 		0x01D
#define CONFIRMATION_FRAME_DLC          2
#define  FRAME_AXIS_VALUE_START_BYTE    2

#define NO_CAN_DATA						0xFFFF

typedef struct{
	void (*can_transmit)(uint16_t, uint8_t, uint8_t*);
	void (*can_receive)(uint16_t*, uint8_t*);
	uint8_t hardware_functions_attached;
}can_functions;

typedef struct{
	uint8_t* data;
	uint8_t dlc;
	uint16_t frame_id;
}can_message;

typedef struct{
	float data;
	uint8_t direction;
}joy_data;

extern can_functions hardware_can;

void send_test_frame(void);
joy_data* get_joy_data(void);
void reset_joy_data(void);
void decode_joy_data(uint32_t frame_id, uint8_t* data, uint8_t dlc);
void receive_raw_can__data(uint16_t* received_id, uint8_t* received_data);

#endif /* CAN_CAN_FRAMES_H_ */
