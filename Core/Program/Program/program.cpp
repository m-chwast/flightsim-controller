#include "Program/cprogram.h"
#include "Program/program.h"
#include "usart.h"


//function called from C code
void Program_CreateTasks(void) {
	Program::CreateTasks();
}

//cpp logic

void* operator new(size_t size) {
	return pvPortMalloc(size);
}

void* operator new[](size_t size) {
    return pvPortMalloc(size);
}

void operator delete(void* p) {
	vPortFree(p);
}

void operator delete[](void* p) {
	vPortFree(p);
}

Console* Program::_console;
TaskOutput* Program::_taskOutput;
TaskLogging* Program::_taskLogging;

void Program::CreateTasks() {
	_console = new Console();

	_taskOutput = new TaskOutput();
	_taskLogging = new TaskLogging(huart2);
}
