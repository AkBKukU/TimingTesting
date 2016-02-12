
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

#include "LEDBlink.h"
#include "UpdateBase.h"




LEDBlink::LEDBlink()
{
	// TODO Auto-generated constructor stub

	counter = 0;
	stage = 0;
	align = 2;
}


void LEDBlink::initLED(uint32_t peri, uint32_t port, uint32_t pin)
{
	LEDport = port;
	LEDpin = pin;
	SysCtlPeripheralEnable(peri);
	GPIOPinTypeGPIOOutput(port , pin );
	GPIOPinWrite(port , pin , pin );
}

void LEDBlink::updateFixed()
{
	uint32_t pinStatus = GPIOPinRead(LEDport , LEDpin );
	if(pinStatus)
	{
		GPIOPinWrite(LEDport , LEDpin , 0 );
	}else{

		GPIOPinWrite(LEDport , LEDpin , LEDpin );
	}
}

void LEDBlink::updateCustom()
{
	if(align)
	{
		align--;
	}else{
		if(getCustomMS() == 15)
		{
			setCustomUpdate(1, 0);
		}
		if(counter == 5)
		{
			setCustomUpdate(15, 0);

			GPIOPinWrite(LEDport , LEDpin , 0 );
			counter = 0;
		}else{

			uint32_t pinStatus = GPIOPinRead(LEDport , LEDpin );
			if(pinStatus)
			{
				GPIOPinWrite(LEDport , LEDpin , 0 );
			}else{

				GPIOPinWrite(LEDport , LEDpin , LEDpin );
			}
			counter++;

		}
	}

}

void LEDBlink::off()
{
	GPIOPinWrite(LEDport , LEDpin , 0 );
}
