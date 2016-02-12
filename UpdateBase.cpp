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
#include "UpdateRoot.h"
#include <typeinfo>       // operator typeid

// TODO Abstract out a linked list item only class

UpdateBase::UpdateBase()
{
	// Initalize indexes to next and previous items
	itemNext = 0;
	itemPrev = 0;

	customMS = 0;
	customS = 0;

	// Get an ID
	itemId = UpdateManager::assignID();

	// Register default fixed update
	this->registerFixedUpdate();
}

UpdateBase::~UpdateBase()
{
	itemId = 0;
	UpdateBase::unRegisterFixedUpdate();
}

uint32_t UpdateBase::getID()
{
	return itemId;
}

void UpdateBase::registerCustomUpdate(uint16_t delayMS, uint32_t delayS)
{
	setCustomUpdate(delayMS, delayS);
	registerCustomUpdate();
}

void UpdateBase::registerCustomUpdate()
{
	resetCustomUpdate();
	UpdateManager::registerCustomUpdate(this);
}

void UpdateBase::setCustomUpdate(uint16_t newDelayMS, uint32_t newDelayS)
{
	customMS = newDelayMS - 1 ;
	customS = newDelayS;

	resetCustomUpdate();
}

void UpdateBase::resetCustomUpdate()
{
	delayMS = customMS;
	delayS = customS;
}

uint16_t UpdateBase::getCustomMS()
{
	return customMS + 1;
}

uint32_t UpdateBase::getCustomS()
{
	return customS;
}

void UpdateBase::unRegisterCustomUpdate()
{
	UpdateManager::unRegisterCustomUpdate(this);
}

void UpdateBase::registerFixedUpdate()
{
	UpdateManager::registerFixedUpdate(this);
}

void UpdateBase::unRegisterFixedUpdate()
{
	UpdateManager::unRegisterFixedUpdate(this);
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

