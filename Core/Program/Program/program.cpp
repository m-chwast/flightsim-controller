#include "Program/cprogram.h"
#include "Program/program.h"


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

TaskOutput* Program::_taskOutput;
TaskLogging* Program::_taskLogging;

void Program::CreateTasks() {
	_taskOutput = new TaskOutput();
	_taskLogging = new TaskLogging();
}
