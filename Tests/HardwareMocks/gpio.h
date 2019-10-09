
#include "stm32f1xx_hal.h"

#ifndef _HARDWAREMOCK_GPIO_H_
#define _HARDWAREMOCK_GPIO_H_

typedef struct {
	void(*high_limit_activated_handler)(void);
	void(*low_limit_activated_handler)(void);
}pins_irq_handlers;


void hal_set_piston_enable_pins(void);
void hal_reset_piston_enable_pins(void);

bool is_actuator_low_limit_active(void);
bool is_actuator_high_limit_active(void);

#endif
