#include <stdint.h>
#include <stdbool.h>

#include "tickCounter.h"
#include "UpdateManager.h"
#include <LEDBlink.h>

//UpdateManager UM;

LEDBlink *led = 0;
/*
 * main.c
 */
int main(void)
{

    //Set the clock
	SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

	// Start the Systick Interupt
	TickCounterInit();

	// Initialize the update manager
	UpdateManager::init();

	// Initialize the LED Blinker
	led = new LEDBlink();

	// Test if the ID was set
	uint32_t test = led->getID();

	while(test)
	{
		UpdateManager::runFixedUpdates();
	}

	return test;
}
