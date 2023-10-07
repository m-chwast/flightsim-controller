/*
 * shift_register.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Mateusz Chwast
 */

#pragma once

#include "ShiftRegister/hc595.h"
#include "GPIO/gpio_pin.h"
#include "main.h"

namespace Drivers {

template <uint8_t bytesCount>
class ShiftRegister {

private:
	Hardware::HC595 _register[bytesCount];

	const Hardware::GPIO_Output& _srEnable;
	const Hardware::GPIO_Output& _srClear;
	const Hardware::GPIO_Output& _srStoreOutput;
	SPI_HandleTypeDef& _spi;

public:

	ShiftRegister(SPI_HandleTypeDef& spi,
			const Hardware::GPIO_Output& srStoreOutput,
			const Hardware::GPIO_Output& srEnable = {nullptr, 0},
			const Hardware::GPIO_Output& srClear = {nullptr, 0})
	: _srEnable{srEnable}, _srClear{srClear}, _srStoreOutput{srStoreOutput}, _spi{spi} {

	}
};

}
