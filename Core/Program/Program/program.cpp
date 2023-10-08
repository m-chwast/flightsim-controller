#include "Program/cprogram.h"
#include "Program/program.h"
#include "Tasks/Output/task_output.h"

//function called from C code
void Program_CreateTasks(void) {
	Program::CreateTasks();
}

//cpp logic

TaskOutput* Program::_taskOutput;

void Program::CreateTasks() {
	_taskOutput = new TaskOutput();
}
