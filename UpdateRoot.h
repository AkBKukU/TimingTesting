/*
 * UpdateRoot.h
 *
 *  Created on: Feb 10, 2016
 *      Author: mcudev
 */

#ifndef UPDATEBASEEMPTY_H_
#define UPDATEBASEEMPTY_H_

#include "UpdateBase.h"

class UpdateRoot: public UpdateBase {
public:
	UpdateRoot();
	//~UpdateBaseEmpty();
	void updateFixed();
	void updateCustom();

protected:
};

#endif /* UPDATEBASEEMPTY_H_ */
