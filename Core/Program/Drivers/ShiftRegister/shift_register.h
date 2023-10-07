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
#include <array>

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

	void Write(const std::array<uint8_t, bytesCount>& data) {
		for(uint8_t i = 0; i < bytesCount; i++) {
			_register[i].SetOutput(data[i]);
		}

		auto dataCopy = data;
		HAL_SPI_Transmit(&_spi, dataCopy.data(), data.size(), 100);

		_srStoreOutput.SetHigh();
		__NOP();
		_srStoreOutput.SetLow();
	}
};

}
