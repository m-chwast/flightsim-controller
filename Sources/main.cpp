#include "HALDriver/hal_driver_init.h"
#include "Drivers/usb.hpp"

 

int main(void) {
	System_Init();

	static Drivers::Usb usb;
	(void)usb;

	System_StartOS();
	
	// we never get here
	while(true);
}
