/*
 * task_output.cpp
 *
 *  Created on: Oct 8, 2023
 *      Author: Mateusz Chwast
 */

#include "Tasks/Output/task_output.h"

void TaskOutput::Init() {

}

void TaskOutput::Loop() {
	_sr.Store({_output});
	_sr.StoreBit(7, _output & 1);
	_sr.Update();
	_output++;
	HAL_GPIO_TogglePin(LED_LD2_GPIO_Port, LED_LD2_Pin);
	vTaskDelay(pdMS_TO_TICKS(400));
}
