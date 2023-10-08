/*
 * gpio_pin.cpp
 *
 *  Created on: Oct 8, 2023
 *      Author: Mateusz Chwast
 */

#include "Drivers/GPIO/gpio_pin.h"

namespace Hardware {

GPIO_Output GPIO_Output::_dummyGPIO;

GPIO_Output& GPIO_Output::GetDummyGPIO() {
	return GPIO_Output::_dummyGPIO;
}

}
