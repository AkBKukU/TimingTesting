/*
 * LEDBlink.h
 *
 *  Created on: Feb 10, 2016
 *      Author: mcudev
 */

#ifndef LEDBLINK_H_
#define LEDBLINK_H_

#include "UpdateBase.h"

class LEDBlink: public UpdateBase
{
public:
	LEDBlink();
	void initLED(uint32_t peri, uint32_t port, uint32_t pin);
	void off();
	void updateFixed();
	void updateCustom();

private:

	uint8_t counter,
			align,
		stage;

	uint32_t LEDport;
	uint32_t LEDpin;
};

#endif /* LEDBLINK_H_ */
