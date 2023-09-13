/*
 * gpio_pin.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Mateusz Chwast
 */

#pragma once

#include "gpio.h"

namespace Hardware {

class GPIO_Output {
private:
	GPIO_TypeDef* _gpio;
	uint16_t _pin;

public:

	void SetLow() const {
		HAL_GPIO_WritePin(_gpio, _pin, GPIO_PIN_SET);
	}

	void SetHigh() const {
		HAL_GPIO_WritePin(_gpio, _pin, GPIO_PIN_RESET);
	}

	void Toggle() const {
		HAL_GPIO_TogglePin(_gpio, _pin);
	}
};

}


