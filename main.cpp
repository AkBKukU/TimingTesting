#include <stdint.h>
#include <stdbool.h>

#include "tickCounter.h"
#include "UpdateManager.h"
#include "LEDBlink.h"

//UpdateManager UM;

LEDBlink *ledRED = 0;
LEDBlink *ledGREEN = 0;
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
	ledRED = new LEDBlink();
	ledRED->initLED(SYSCTL_PERIPH_GPIOF, GPIO_PORTF_BASE,GPIO_PIN_1);
	ledRED->unRegisterFixedUpdate();
	ledRED->off();
	ledRED->registerCustomUpdate(1, 0);

	ledGREEN = new LEDBlink();
	ledGREEN->initLED(SYSCTL_PERIPH_GPIOF, GPIO_PORTF_BASE,GPIO_PIN_2);

	// Loop fixed updates to allow it to run as needed
	while(1)
	{
		UpdateManager::update();
	}

	return 0;
}
