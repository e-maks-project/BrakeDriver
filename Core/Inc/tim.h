/**
  ******************************************************************************
  * File Name          : TIM.h
  * Description        : This file provides code for the configuration
  *                      of the TIM instances.
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
#ifndef __tim_H
#define __tim_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;

/* USER CODE BEGIN Private defines */
#define NUMBER_OF_ENCODERS  4
#define PWM1_CHANNEL        2
#define PWM2_CHANNEL		3

typedef struct{
	void (*set_slip_pwm) (uint16_t);
	void (*set_propound_pwm) (uint16_t);
}hal_pwm;
/* USER CODE END Private defines */

void MX_TIM1_Init(void);
void MX_TIM3_Init(void);
                        
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
                    
/* USER CODE BEGIN Prototypes */
typedef struct {
	volatile uint16_t pulse_count;
	volatile uint16_t forward_count;
	volatile uint16_t rotaction_count;
}hal_encoder;

typedef struct{
	hal_encoder* encoders;
	uint8_t number_of_encoders;
}hal_encoders;

void hal_set_pwm_1(uint16_t pwm_in_percents);
void hal_set_pwm_2(uint16_t pwm_in_percents);
void hal_reset_pwms(void);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ tim_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
