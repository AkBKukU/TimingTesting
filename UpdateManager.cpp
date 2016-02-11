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


// Root for 100Hz updates
UpdateBaseEmpty *UpdateManager::fixedRoot;

// Root for custom update frequencies
UpdateBaseEmpty *UpdateManager::customRoot;

// Index to traverse linked lists
UpdateBase *UpdateManager::index = 0;

// Test to call fixedUpdates
bool UpdateManager::fixedUpdate = false;

// Counter to assign IDs to new objects
uint32_t UpdateManager::idCounter = 0;

// Number of milliSeconds since last second
uint16_t UpdateManager::timeMilliSeconds = 0; // `timeSeconds++` after 1000.

// Runtime in seconds
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
	// Inrement the MilliSecond counter
	timeMilliSeconds++;

	// Wrap counter at one second
	if (timeMilliSeconds >= 1000)
	{
		timeMilliSeconds = 0;
		timeSeconds++;
	}

	// Every 10ms set the runFixedUpdates function to run
	if(!(timeMilliSeconds % 10))
	{
		fixedUpdate = true;
	}

}

uint16_t UpdateManager::getTimeMilli()
{
	return timeMilliSeconds;
}

uint32_t UpdateManager::getTimeS()
{
	return timeSeconds;
}


void UpdateManager::runFixedUpdates()
{
	// Check if it is time to run the updates
	if(fixedUpdate)
	{
		// Reset update
		fixedUpdate = false;

		// Start from begining
		UpdateManager::index = UpdateManager::fixedRoot;

		// Cycle through all items
		// TODO - Avoid calling update on root object
		while (UpdateManager::index->itemNext)
		{
			UpdateManager::index->updateFixed();
			UpdateManager::index = UpdateManager::index->itemNext;
		}
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
