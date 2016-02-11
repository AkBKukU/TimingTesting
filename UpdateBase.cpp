/*
 * UpdateBase.cpp
 *
 *  Created on: Feb 9, 2016
 *      Author: mcudev
 */
#include <stdint.h>
#include <stdbool.h>

#include "UpdateBase.h"

#include "UpdateManager.h"

UpdateBase::UpdateBase()
{
	// Initalize indexes to next and previous items
	itemNext = 0;
	itemPrev = 0;

	// Get an ID
	itemId = UpdateManager::assignID();

	// Register default fixed update
	this->registerFixedUpdate();
}

uint32_t UpdateBase::getID()
{
	return itemId;
}

void UpdateBase::registerCustomUpdate(uint16_t delayMS, uint32_t delayS)
{
	// TODO
}

void UpdateBase::unRegisterCustomUpdate()
{
	// TODO
}

void UpdateBase::registerFixedUpdate()
{
	UpdateManager::registerFixedUpdate(this);
}

void UpdateBase::unRegisterFixedUpdate()
{
	// TODO
}

uint16_t UpdateBase::getDelayMilli()
{
	// TODO
	return 0;
}

uint32_t UpdateBase::getDelayS()
{
	// TODO
	return 0;
}

