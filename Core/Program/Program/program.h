/*
 * program.h
 *
 *  Created on: Oct 8, 2023
 *      Author: Mateusz Chwast
 */

#pragma once

#include "Tasks/Output/task_output.h"

//all the main tasks are here
class Program final {
private:

	static TaskOutput* _taskOutput;

public:

	static void CreateTasks();
};


