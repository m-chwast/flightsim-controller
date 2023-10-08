/*
 * gpio_pin.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Mateusz Chwast
 */

#pragma once

#include "gpio.h"
#include "FreeRTOS.h"
#include "task.h"

namespace Hardware {

class GPIO_Output {
private:

	static GPIO_Output _dummyGPIO;

	GPIO_TypeDef* _gpio;
	uint16_t _pin;

	bool IsOperational() const {
		return _gpio != nullptr;
	}

public:

	GPIO_Output(GPIO_TypeDef* gpio, uint16_t pin)
		: _gpio{gpio}, _pin{pin} {}

	GPIO_Output() {
		GPIO_Output(nullptr, 0);
	}

	void SetLow() {
		if(!IsOperational()) {
			return;
		}
		taskENTER_CRITICAL();
		HAL_GPIO_WritePin(_gpio, _pin, GPIO_PIN_RESET);
		taskEXIT_CRITICAL();
	}

	void SetHigh() {
		if(!IsOperational()) {
			return;
		}
		taskENTER_CRITICAL();
		HAL_GPIO_WritePin(_gpio, _pin, GPIO_PIN_SET);
		taskEXIT_CRITICAL();
	}

	void Toggle() {
		if(!IsOperational()) {
			return;
		}
		taskENTER_CRITICAL();
		HAL_GPIO_TogglePin(_gpio, _pin);
		taskEXIT_CRITICAL();
	}

	void PulseHigh() {
		SetHigh();
		__NOP();
		SetLow();
	}

	static GPIO_Output& GetDummyGPIO();	//used for passing optional gpios by reference
};

}
