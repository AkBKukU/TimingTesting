#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "inc/hw_nvic.h"

#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"

//#include "UpdateManager.h"

/*
 * tickCounter.c
 *
 *  Created on: Jan 8, 2016
 *      Author: akbkuku
 */

#include "tickCounter.h"

extern void UpdateManagerupdateTime();

void TickCounter()
{
	UpdateManagerupdateTime();
}

void TickCounterInit() {
	// Set Tick Counter
	SysTickPeriodSet(SysCtlClockGet() / 1000);
	IntMasterEnable();
	SysTickIntEnable();
	SysTickEnable();
}
