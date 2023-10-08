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

		taskENTER_CRITICAL();

		_srClear.SetHigh();
		__NOP();
		_srClear.SetLow();

		_srEnable.SetLow();	// EN is active low

		taskEXIT_CRITICAL();
	}

	//Stores the values, but does not update the hardware
	void Store(const std::array<uint8_t, bytesCount>& data) {
		for(uint8_t i = 0; i < bytesCount; i++) {
			_register[i].SetOutput(data[i]);
		}
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
