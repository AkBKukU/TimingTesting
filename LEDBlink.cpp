
#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ssi.h"
#include "inc/hw_ints.h"
#include "inc/hw_nvic.h"

#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/ssi.h"
#include "driverlib/interrupt.h"
#include "driverlib/pwm.h"
/*
 * LEDBlink.cpp
 *
 *  Created on: Feb 10, 2016
 *      Author: mcudev
 */

#include <LEDBlink.h>
#include "UpdateBase.h"

LEDBlink::LEDBlink()
{
	// TODO Auto-generated constructor stub

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE , GPIO_PIN_1 );
	GPIOPinWrite(GPIO_PORTF_BASE , GPIO_PIN_1 , GPIO_PIN_1 );
}


void LEDBlink::updateFixed()
{

	uint32_t pinStatus = GPIOPinRead(GPIO_PORTF_BASE , GPIO_PIN_1 );
	if(pinStatus)
	{
		GPIOPinWrite(GPIO_PORTF_BASE , GPIO_PIN_1 , GPIO_PIN_1 );
	}else{

		GPIOPinWrite(GPIO_PORTF_BASE , GPIO_PIN_1 , 0 );
	}
}
