/*
 * task_logging.h
 *
 *  Created on: Oct 9, 2023
 *      Author: Mateusz Chwast
 */

#pragma once

#include "Tasks/task.h"

class TaskLogging final : public Task {
private:

	constexpr static const char* _name = "Logging";
	constexpr static uint16_t _stackSize = 128;
	constexpr static uint8_t _priority = 1;

	void Loop() override {

	}

public:

	TaskLogging()
		: Task(_name, _stackSize, _priority) {}
};
