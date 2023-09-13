/*
 * shift_register.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Mateusz Chwast
 */

#pragma once

#include "ShiftRegister/hc595.h"
#include "gpio.h"

namespace Drivers {

template <uint8_t bytesCount>
class ShiftRegister {
private:
	Hardware::HC595 _register[bytesCount];

public:


};

}
