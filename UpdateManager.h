/*
 * UpdateManager.h
 *
 *  Created on: Feb 9, 2016
 *      Author: mcudev
 */
#include <stdint.h>
#include <stdbool.h>

#include "UpdateBase.h"
#include "UpdateBaseEmpty.h"

#ifndef UPDATEMANAGER_H_
#define UPDATEMANAGER_H_

class UpdateManager
{
public:
	UpdateManager();
	static void init();
	static uint32_t assignID();

	static void update();

	static uint16_t getTimeMilli();
	static uint32_t getTimeS();

	static void registerFixedUpdate(UpdateBase *newItem);

private:

	static void runFixedUpdates();

	static UpdateBase *index;
	static UpdateBaseEmpty *fixedRoot;
	static UpdateBaseEmpty *customRoot;

	static uint32_t idCounter;

	static uint16_t timeMilliSeconds; // `timeSeconds++` after 1000.

	static uint32_t timeSeconds; // Good for 136 years of runtime

};

#endif /* UPDATEMANAGER_H_ */
