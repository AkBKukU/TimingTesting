/*
 * UpdateBaseEmpty.h
 *
 *  Created on: Feb 10, 2016
 *      Author: mcudev
 */

#ifndef UPDATEBASEEMPTY_H_
#define UPDATEBASEEMPTY_H_

#include "UpdateBase.h"

class UpdateBaseEmpty: public UpdateBase {
public:
	typedef UpdateBase super;
	UpdateBaseEmpty();
	void updateFixed();
};

#endif /* UPDATEBASEEMPTY_H_ */
