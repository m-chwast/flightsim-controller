#include "init.h"

#include "ShiftRegister/shift_register.h"
#include "spi.h"
#include "Tasks/Output/task_output.h"


void Init_CreateTasks(void) {
	TaskOutput* taskOutput = new TaskOutput();
}
