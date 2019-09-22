/**
  ******************************************************************************
  * File Name          : CAN.h
  * Description        : This file provides code for the configuration
  *                      of the CAN instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __can_H
#define __can_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern CAN_HandleTypeDef hcan;

/* USER CODE BEGIN Private defines */
#define CAN_FRAMES_ID_LOW			0x20D
#define CAN_FRAMES_ID_HIGH			0x24D

typedef struct{
	void(*process_message)(uint32_t, uint8_t*, uint8_t);
	uint8_t* received_data;
}can_rx_interrupt_handler;

typedef struct{
	CAN_TxHeaderTypeDef     tx_header;
	CAN_RxHeaderTypeDef	    rx_header;
	uint32_t 				mailbox;
	uint8_t*				tx_data;
	uint8_t*				rx_data;
}hal_can_messages;

/* USER CODE END Private defines */

void MX_CAN_Init(void);

/* USER CODE BEGIN Prototypes */
void hal_can_send(uint16_t frame_id, uint8_t dlc, uint8_t* data);
extern can_rx_interrupt_handler hal_can_rx;
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ can_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
