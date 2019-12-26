/**
  ******************************************************************************
  * File Name          : CAN.c
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

/* Includes ------------------------------------------------------------------*/
#include "can.h"

/* USER CODE BEGIN 0 */
CAN_FilterTypeDef hcan_filter;
static hal_can_messages can_messages;
can_rx_interrupt_handler hal_can_rx;

/* USER CODE END 0 */

CAN_HandleTypeDef hcan;

/* CAN init function */
void MX_CAN_Init(void)
{

  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 7;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_2TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_2TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_1TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = DISABLE;
  hcan.Init.AutoWakeUp = ENABLE;
  hcan.Init.AutoRetransmission = ENABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_CAN_MspInit(CAN_HandleTypeDef* canHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspInit 0 */

  /* USER CODE END CAN1_MspInit 0 */
    /* CAN1 clock enable */
    __HAL_RCC_CAN1_CLK_ENABLE();
  
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**CAN GPIO Configuration    
    PA11     ------> CAN_RX
    PA12     ------> CAN_TX 
    */
    GPIO_InitStruct.Pin = CAN_RX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(CAN_RX_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = CAN_TX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(CAN_TX_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN CAN1_MspInit 1 */
    HAL_CAN_ActivateNotification(&hcan,CAN_IT_RX_FIFO0_MSG_PENDING);

  /* USER CODE END CAN1_MspInit 1 */
  }
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef* canHandle)
{

  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspDeInit 0 */

  /* USER CODE END CAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_CAN1_CLK_DISABLE();
  
    /**CAN GPIO Configuration    
    PA11     ------> CAN_RX
    PA12     ------> CAN_TX 
    */
    HAL_GPIO_DeInit(GPIOA, CAN_RX_Pin|CAN_TX_Pin);

    /* CAN1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USB_HP_CAN1_TX_IRQn);
    HAL_NVIC_DisableIRQ(CAN1_RX1_IRQn);
  /* USER CODE BEGIN CAN1_MspDeInit 1 */

  /* USER CODE END CAN1_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */
void test_get_rx_message(void){
    uint32_t	fifo = HAL_CAN_GetRxFifoFillLevel(&hcan, CAN_RX_FIFO0) ;
	HAL_CAN_GetRxMessage(&hcan,CAN_RX_FIFO0,
				&can_messages.rx_header,
				can_messages.rx_data );
	printf("data\n");
}


void HAL_CAN_RxFifo0MsgPendingCallback (CAN_HandleTypeDef* can ){

	HAL_CAN_GetRxMessage(can,CAN_RX_FIFO0,
			&can_messages.rx_header,
			can_messages.rx_data );
	hal_can_rx.process_message(can_messages.rx_header.StdId,
			can_messages.rx_data,
			can_messages.rx_header.DLC);

}

void hal_can_filter_init(void){
	hcan_filter.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	//filter only user interface frames
	hcan_filter.FilterIdLow = CAN_FRAMES_ID_LOW;
	hcan_filter.FilterIdHigh = CAN_FRAMES_ID_HIGH;
	hcan_filter.FilterScale = CAN_FILTERSCALE_32BIT;
	hcan_filter.FilterActivation = ENABLE;

	HAL_CAN_ConfigFilter(&hcan,&hcan_filter);
}

void hal_can_send(uint16_t frame_id, uint8_t dlc, uint8_t* data){
	can_messages.tx_data = data;
	can_messages.tx_header.DLC = dlc;
	can_messages.tx_header.RTR = CAN_RTR_DATA;
	can_messages.tx_header.IDE  = CAN_ID_STD;
	can_messages.tx_header.StdId = frame_id;
	while(HAL_CAN_AddTxMessage(&hcan, &(can_messages.tx_header),can_messages.tx_data,&(can_messages.mailbox))!= HAL_OK);
}
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
