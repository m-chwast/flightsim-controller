#include "init.h"

#include "ShiftRegister/shift_register.h"

void Init_CreateTasks(void) {
	Drivers::ShiftRegister<2> testSR({nullptr, 0}, {nullptr, 0}, {nullptr, 0});
}
