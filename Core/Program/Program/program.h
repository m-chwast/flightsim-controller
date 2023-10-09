/*
 * program.h
 *
 *  Created on: Oct 8, 2023
 *      Author: Mateusz Chwast
 */

#pragma once

#include "Tasks/Output/task_output.h"
#include "Tasks/Logging/task_logging.h"
#include "Tasks/Logging/console.h"

//all the main tasks are here
class Program final {
private:

	static Console* _console;

	static TaskOutput* _taskOutput;
	static TaskLogging* _taskLogging;

public:

	static void CreateTasks();
};


