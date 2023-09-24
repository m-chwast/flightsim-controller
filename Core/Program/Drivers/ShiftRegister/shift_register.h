/*
 * shift_register.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Mateusz Chwast
 */

#pragma once

#include "ShiftRegister/hc595.h"
#include "GPIO/gpio_pin.h"

namespace Drivers {

template <uint8_t bytesCount>
class ShiftRegister {

private:
	Hardware::HC595 _register[bytesCount];

	const Hardware::GPIO_Output& _srEnable;
	const Hardware::GPIO_Output& _srClear;
	const Hardware::GPIO_Output& _srStoreOutput;

public:

	ShiftRegister(const Hardware::GPIO_Output& srEnable,
			const Hardware::GPIO_Output& srClear,
			const Hardware::GPIO_Output& srStoreOutput)
	: _srEnable{srEnable}, _srClear{srClear}, _srStoreOutput{srStoreOutput} {

	}
};

}
