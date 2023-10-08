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
#include "FreeRTOS.h"
#include "task.h"

namespace Drivers {

template <uint8_t bytesCount>
class ShiftRegister {

private:
	Hardware::HC595 _register[bytesCount];

	Hardware::GPIO_Output& _srEnable;
	Hardware::GPIO_Output& _srClear;
	Hardware::GPIO_Output& _srStoreOutput;
	SPI_HandleTypeDef& _spi;

public:

	ShiftRegister(SPI_HandleTypeDef& spi,
			Hardware::GPIO_Output& srStoreOutput,
			Hardware::GPIO_Output& srEnable = Hardware::GPIO_Output::dummyGPIO,
			Hardware::GPIO_Output& srClear = Hardware::GPIO_Output::dummyGPIO)
	: _srEnable{srEnable}, _srClear{srClear}, _srStoreOutput{srStoreOutput}, _spi{spi} {

		taskENTER_CRITICAL();

		_srClear.PulseHigh();

		_srEnable.SetLow();	// EN is active low

		taskEXIT_CRITICAL();
	}

	//Stores the values, but does not update the hardware
	void Store(const std::array<uint8_t, bytesCount>& data) {
		for(uint8_t i = 0; i < bytesCount; i++) {
			_register[i].SetOutput(data[i]);
		}
	}

	void StoreBit(uint8_t bit, bool isSet) {
		assert(bit < bytesCount * 8);
		uint8_t reg = bit / 8;
		uint8_t bitInReg = bit % 8;
		_register[reg].WriteBit(bitInReg, isSet);
	}

	//Updates the hardware with currently stored values
	void Update() const {
		std::array<uint8_t, bytesCount> data;
		for(uint8_t i = 0; i < bytesCount; i++) {
			data[i] = _register[i].GetOutput();
		}

		//io operations are not reentrant
		taskENTER_CRITICAL();
		HAL_SPI_Transmit(&_spi, data.data(), data.size(), HAL_MAX_DELAY);
		taskEXIT_CRITICAL();

		_srStoreOutput.PulseHigh();
	}

	void Write(const std::array<uint8_t, bytesCount>& data) {
		Store(data);
		Update();
	}
};

}
