
#ifndef _HARDWARE_MOCK_TIM_H_
#define _HARDWARE_MOCK_TIM_H_


#include "stm32f1xx_hal.h"


void hal_set_forward_pwm(uint16_t pwm_in_percents);
void hal_set_backward_pwm(uint16_t pwm_in_percents);
void hal_reset_pwms(void);

#endif
