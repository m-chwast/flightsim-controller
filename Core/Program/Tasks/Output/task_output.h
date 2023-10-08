/*
 * task_output.h
 *
 *  Created on: Oct 8, 2023
 *      Author: Mateusz Chwast
 */

#pragma once

#include "FreeRTOS.h"
#include "task.h"
#include "Tasks/task.h"
#include "ShiftRegister/shift_register.h"
#include "spi.h"

class TaskOutput final : public Task {
private:

	constexpr static uint16_t _stackSize = 512;
	constexpr static uint8_t _priority = 1;

	Hardware::GPIO_Output _sr_rclk = {SR_RCLK_GPIO_Port, SR_RCLK_Pin};

	Drivers::ShiftRegister<1> _sr = Drivers::ShiftRegister<1>(hspi2, &_sr_rclk);
	uint8_t _output = 0;

	virtual void Init() override;
	virtual void Loop() override;

public:

	TaskOutput()
		: Task("Output", _stackSize, _priority) {}
};
