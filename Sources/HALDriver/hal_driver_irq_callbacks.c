#include "stm32f2xx_hal.h"

// declare HAL tick timebase timer
extern TIM_HandleTypeDef htim6;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim6) {
		HAL_IncTick();
	}
}

void Error_Handler(void) {
	__disable_irq();
	while (1);
}
