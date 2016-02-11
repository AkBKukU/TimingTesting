/*
 * UpdateManager.cpp
 *
 *  Created on: Feb 9, 2016
 *      Author: mcudev
 */
#include <stdint.h>
#include <stdbool.h>

#include "UpdateManager.h"

#include "UpdateBase.h"
#include <UpdateBaseEmpty.h>


UpdateBase *UpdateManager::fixedRoot = 0;
UpdateBase *UpdateManager::customRoot = 0;
UpdateBase *UpdateManager::index = 0;

uint32_t UpdateManager::idCounter = 0;

uint16_t UpdateManager::timeMilliSeconds = 0; // `timeSeconds++` after 1000.

uint32_t UpdateManager::timeSeconds = 0; // Good for 136 years of runtime

UpdateManager::UpdateManager()
{
	 UpdateManager::init();
}
void UpdateManager::init()
{
	UpdateManager::fixedRoot = new UpdateBaseEmpty();
	UpdateManager::customRoot = new UpdateBaseEmpty();
}

uint32_t UpdateManager::assignID()
{
	return ++UpdateManager::idCounter;
}

void UpdateManager::update()
{
	timeMilliSeconds++;
	if (timeMilliSeconds >= 1000)
	{
		timeMilliSeconds = 0;
		timeSeconds++;
	}

	if(!(timeMilliSeconds % 10))
	{
		UpdateManager::runFixedUpdates();
	}

}

uint16_t UpdateManager::getTimeMilli()
{

}

uint32_t UpdateManager::getTimeS()
{

}

void UpdateManager::runFixedUpdates()
{
	// Start from begining
	UpdateManager::index = UpdateManager::fixedRoot;

	// Find last item
	while (UpdateManager::index->itemNext)
	{
		UpdateManager::index->updateFixed();
		UpdateManager::index = UpdateManager::index->itemNext;
	}
}


void UpdateManager::registerFixedUpdate(UpdateBase *newItem)
{
	// Start from begining
	UpdateManager::index = UpdateManager::fixedRoot;

	// Find last item
	while (UpdateManager::index->itemNext)
	{
		UpdateManager::index = UpdateManager::index->itemNext;
	}

	// Assign new item to current item
	UpdateManager::index->itemNext = newItem;
	UpdateManager::index->itemNext->itemPrev = UpdateManager::index;
}

extern "C" void UpdateManageraddTimeMilli()
{
	UpdateManager::update();
}
