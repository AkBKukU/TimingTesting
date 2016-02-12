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
	virtual ~UpdateBase();

	//virtual void updateUnscheduled();
	virtual void updateFixed() = 0;
	virtual void updateCustom() = 0;

	uint32_t getID();

	void registerCustomUpdate(uint16_t delayMS, uint32_t delayS);
	void registerCustomUpdate();
	void setCustomUpdate(uint16_t delayMS, uint32_t delayS);
	uint16_t getCustomMS();
	uint32_t getCustomS();
	void resetCustomUpdate();
	void unRegisterCustomUpdate();

	void registerFixedUpdate();
	void unRegisterFixedUpdate();

	uint16_t getDelayMilli();
	uint32_t getDelayS();

	UpdateBase *itemNext;
	UpdateBase *itemPrev;

	uint16_t delayMS;
	uint32_t delayS;

protected:

private:
	uint32_t itemId;


	uint16_t customMS;
	uint32_t customS;

};

#endif /* UPDATEBASE_H_ */
