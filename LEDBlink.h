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
	void updateFixed();
};

#endif /* LEDBLINK_H_ */
