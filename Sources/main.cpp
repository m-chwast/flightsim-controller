#include "HALDriver/hal_driver_init.h"

void SystemClock_Config(void);

int main(void) {
	System_Init();

	System_StartOS();
	
	// we never get here
	while(true);
}
