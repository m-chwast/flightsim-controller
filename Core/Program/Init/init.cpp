#include "init.h"

#include "ShiftRegister/shift_register.h"
#include "spi.h"

void Init_CreateTasks(void) {
	Drivers::ShiftRegister<2> testSR(hspi2, {SR_RCLK_GPIO_Port, SR_RCLK_Pin});
}
