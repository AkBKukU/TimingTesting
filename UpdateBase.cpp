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
	itemNext = 0;
	itemPrev = 0;

	itemId = UpdateManager::assignID();
	this->registerFixedUpdate();
}

uint32_t UpdateBase::getID()
{
	return itemId;
}

void UpdateBase::registerCustomUpdate(uint16_t delayMS, uint32_t delayS)
{

}

void UpdateBase::unRegisterCustomUpdate()
{

}

void UpdateBase::registerFixedUpdate()
{
	UpdateManager::registerFixedUpdate(this);
}

void UpdateBase::unRegisterFixedUpdate()
{

}

uint16_t UpdateBase::getDelayMilli()
{

}

uint32_t UpdateBase::getDelayS()
{

}

