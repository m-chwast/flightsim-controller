#include "init.h"

#include "ShiftRegister/shift_register.h"
#include "spi.h"
#include "Tasks/task.h"

static void TestTaskHandler(void* param);

void Init_CreateTasks(void) {
	xTaskCreate(TestTaskHandler, "Test task", 512, nullptr, 2, nullptr);
}

static void TestTaskHandler(void* param) {
	Drivers::ShiftRegister<1> testSR(hspi2, {SR_RCLK_GPIO_Port, SR_RCLK_Pin});

	uint8_t output = 0;

	while(true) {
		testSR.Store({output});
		testSR.StoreBit(7, output & 1);
		testSR.Update();
		output++;
		vTaskDelay(pdMS_TO_TICKS(250));
	}
}
