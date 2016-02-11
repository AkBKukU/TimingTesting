/*
 * UpdateBase.h
 *
 *  Created on: Feb 9, 2016
 *      Author: mcudev
 */
#include <stdint.h>
#include <stdbool.h>


#ifndef UPDATEBASE_H_
#define UPDATEBASE_H_

class UpdateBase
{

public:
	UpdateBase();
	//~UpdateBase();

	//virtual void updateUnscheduled();
	virtual void updateFixed() = 0;
	//virtual void updateCustom();

	uint32_t getID();

	void registerCustomUpdate(uint16_t delayMS, uint32_t delayS);
	void unRegisterCustomUpdate();

	void registerFixedUpdate();
	void unRegisterFixedUpdate();

	uint16_t getDelayMilli();
	uint32_t getDelayS();

	UpdateBase *itemNext;
	UpdateBase *itemPrev;

protected:

private:
	uint32_t itemId;

	uint16_t delayMilliSeconds;
	uint32_t delaySeconds;
};

#endif /* UPDATEBASE_H_ */
