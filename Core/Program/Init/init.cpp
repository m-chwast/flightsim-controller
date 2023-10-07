#include "init.h"

#include "ShiftRegister/shift_register.h"
#include "spi.h"

void Init_CreateTasks(void) {
	Drivers::ShiftRegister<2> testSR(hspi2, {nullptr, 0}, {nullptr, 0}, {nullptr, 0});
}
