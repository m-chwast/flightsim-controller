/*
 * hc595.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Mateusz Chwast
 */

#pragma once

#include <cstdint>
#include <cassert>

namespace Hardware {

class HC595 {
private:
	uint8_t _output = 0;

public:

	void SetBit(uint8_t bit) {
		assert(bit < 8);
		_output |= (1 << bit);
	}

	void ResetBit(uint8_t bit) {
		assert(bit < 8);
		_output &= ~(1 << bit);
	}

	bool GetBit(uint8_t bit) const {
		assert(bit < 8);
		return _output & (1 << bit);
	}

	void SetOutput(uint8_t output) {
		_output = output;
	}

	uint8_t GetOutput() const {
		return _output;
	}
};

}
