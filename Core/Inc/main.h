/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef char bool;
#define TRUE  1
#define FALSE 0

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LATT_MIN_LENGTH_Pin GPIO_PIN_2
#define LATT_MIN_LENGTH_GPIO_Port GPIOC
#define LATT_MAX_LENGTH_Pin GPIO_PIN_3
#define LATT_MAX_LENGTH_GPIO_Port GPIOC
#define ACS_FAULT_Pin GPIO_PIN_0
#define ACS_FAULT_GPIO_Port GPIOA
#define ACS_CURRENT_Pin GPIO_PIN_1
#define ACS_CURRENT_GPIO_Port GPIOA
#define LATT_LOW_LIMIT_ACTUATOR_Pin GPIO_PIN_6
#define LATT_LOW_LIMIT_ACTUATOR_GPIO_Port GPIOA
#define LATT_LOW_LIMIT_ACTUATOR_EXTI_IRQn EXTI9_5_IRQn
#define LATT_HIGH_LIMIT_ACTUATOR_Pin GPIO_PIN_7
#define LATT_HIGH_LIMIT_ACTUATOR_GPIO_Port GPIOA
#define LATT_HIGH_LIMIT_ACTUATOR_EXTI_IRQn EXTI9_5_IRQn
#define Enable1_Pin GPIO_PIN_7
#define Enable1_GPIO_Port GPIOC
#define Enable2_Pin GPIO_PIN_8
#define Enable2_GPIO_Port GPIOC
/* USER CODE BEGIN Private defines */
#define EXTI_LOW_LIMIT_SWITCH_PIN_INDEX  6
#define EXTI_HIGH_LIMIT_SWITCH_PIN_INDEX 7
void hal_init(void);
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
