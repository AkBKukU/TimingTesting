/* ========================================================================= *\
 *                                                                           *
 *       File: UpdateManager.cpp                                             *
 * Created on: Feb 9, 2016                                                   *
 *     Author: Shelby Jueden (AkBKukU)                                       *
 *                                                                           *
 * ------------------------------------------------------------------------- *
 *                                                                           *
 * Update Manager is the controlling code for a timing framework designed to *
 * allow ease of development when creating projects. It controls two sets of *
 * linked lists, one for fixed updates and one for custom updates. The fixed *
 * updates are run at 100Hz. This can be set by changing the `SECOND_DIVDER` *
 * and `FIXED_SPEED` values.                                                 *
 *                                                                           *
\* ========================================================================= */

// TODO Abstract out a linked list management only class
#include <stdint.h>
#include <stdbool.h>

#include "UpdateManager.h"

#include "UpdateBase.h"
#include "UpdateRoot.h"


// Index for traversing linked lists
UpdateBase *UpdateManager::index = 0;
// Root for fixed updates
UpdateBase *UpdateManager::fixedRoot = 0;
// Root for custom updates
UpdateBase *UpdateManager::customRoot = 0;

// Flag to call fixed updates
bool UpdateManager::fixedUpdate = false;
// Flag to call custom updates
bool UpdateManager::customUpdate = false;

// Holds last issued ID
uint32_t UpdateManager::idCounter = 0;

// Number of `SECOND_DIVDER`s since last second
uint16_t UpdateManager::timeMilliSeconds = 0;

// Runtime in seconds
uint32_t UpdateManager::timeSeconds = 0;



/*
 * Only calls init()
 */
UpdateManager::UpdateManager()
{
	 UpdateManager::init();
}

/*
 * Initalizes root items for the fixed and custom linked lists
 */
void UpdateManager::init()
{
	UpdateManager::fixedRoot = new UpdateRoot();
	UpdateManager::customRoot = new UpdateRoot();
	// custom root is automatically put in the fixed list so it must be removed
	UpdateManager::customRoot->unRegisterFixedUpdate();
}

/*
 * Issues a new ID for an item
 */
uint32_t UpdateManager::assignID()
{
	return ++UpdateManager::idCounter;
}

/*
 * Controls the frequency this the fixed updates are called at. Also flags the
 * custom updates every time it is called.
 *
 * updateTime() should be called (1s / `SECOND_DIVDER`)
 */
void UpdateManager::updateTime()
{
	// Inrement the MilliSecond counter
	timeMilliSeconds++;

	// Set flag for custom updates
	customUpdate = true;

	// Wrap counter at one second
	if (timeMilliSeconds >= SECOND_DIVDER)
	{
		timeMilliSeconds = 0;
		timeSeconds++;
	}

	// Every ((1s / `SECOND_DIVDER`) * `FIXED_SPEED`) set the runFixedUpdates
	// function to run
	if(!(timeMilliSeconds % FIXED_SPEED))
	{
		fixedUpdate = true;
	}

}

/*
 *  Returns the number of (1s / `SECOND_DIVDER`) since the last second
 */
uint16_t UpdateManager::getTimeMilli()
{
	return timeMilliSeconds;
}

/*
 * Returns the runtime in seconds
 */
uint32_t UpdateManager::getTimeS()
{
	return timeSeconds;
}

/*
 * Primary update function. Calls both fixed and custom updates
 */
void UpdateManager::update()
{
	// Run fixed updates if flag was thrown
	if(customUpdate)
	{
		// Reset flag
		customUpdate = false;
		runCustomUpdates();
	}

	// Run custom updates if flag was thrown
	if(fixedUpdate)
	{
		// Reset flag
		fixedUpdate = false;
		runFixedUpdates();
	}
}

/*
 * Runs all fixed updates in the linked list
 */
void UpdateManager::runFixedUpdates()
{
	// Start from begining
	UpdateManager::index = UpdateManager::fixedRoot;

	// Cycle through all items
	while( traverseList() )
	{
		UpdateManager::index->updateFixed();
	}
}


/*
 * Checks if all custom updates are ready to be run and runs them if so
 */
void UpdateManager::runCustomUpdates()
{
	// Start from begining
	UpdateManager::index = UpdateManager::customRoot;

	// Cycle through all items
	while( traverseList() )
	{
		// Check if MS delay has ended
		if(UpdateManager::index->delayMS == 0)
		{
			// Check if S delay has ended
			if(UpdateManager::index->delayS == 0)
			{
				// Run custom update
				UpdateManager::index->updateCustom();

				// Reset delay for custom update
				UpdateManager::index->resetCustomUpdate();
			}
			else{
				// Decrease S delay and reset MS delay
				UpdateManager::index->delayS--;
				UpdateManager::index->delayMS = SECOND_DIVDER - 1;
			}
		}
		else{
			// Decrease MS delay
			UpdateManager::index->delayMS--;
		}

	}
}

/*
 * Traverse a linked list using the static `index` variable
 */
bool UpdateManager::traverseList()
{
	// Check if at last item in list
	if(UpdateManager::index->itemNext != 0)
	{
		// Move to next item
		UpdateManager::index = UpdateManager::index->itemNext;

		// Return valid index found
		return true;
	}
	else{
		// Return no valid index found
		return false;
	}
}

/*
 * Add new item to the end of a linked list
 */
void UpdateManager::registerItem(UpdateBase *newItem, UpdateBase *root)
{
	// Start from begining.
	// Assume root is valid
	UpdateManager::index = root;

	// Find last item

	// Cycle through all items
	while(traverseList());

	// Assign new item to current item
	UpdateManager::index->itemNext = newItem;
	UpdateManager::index->itemNext->itemPrev = UpdateManager::index;
}

void UpdateManager::unRegisterItem(UpdateBase *item, UpdateBase *root)
{
	// Start from begining
	// Assume root is valid
	UpdateManager::index = root;

	// Cycle through all items
	while(traverseList() )
	{
		if(UpdateManager::index == item)
		{
			UpdateManager::index->itemPrev->itemNext = 0;

			if(UpdateManager::index->itemNext != 0)
			{
				UpdateManager::index->itemPrev->itemNext =
					UpdateManager::index->itemNext;
				UpdateManager::index->itemNext->itemPrev =
					UpdateManager::index->itemPrev;
			}else{
				UpdateManager::index->itemPrev->itemNext = 0;
			}

			UpdateManager::index->itemPrev = 0;
			UpdateManager::index->itemNext = 0;
			return;
		}
	}
}


void UpdateManager::registerFixedUpdate(UpdateBase *newItem)
{
	// Make sure root is set
	if(UpdateManager::fixedRoot == 0)
		return;

	registerItem(newItem, UpdateManager::fixedRoot);
}


void UpdateManager::unRegisterFixedUpdate(UpdateBase *item)
{
	// Make sure root is set
	if(UpdateManager::fixedRoot == 0)
		return;
	unRegisterItem(item, UpdateManager::fixedRoot);
}


void UpdateManager::registerCustomUpdate(UpdateBase *newItem)
{
	// Make sure root is set
	if(UpdateManager::customRoot == 0)
	{
		UpdateManager::customRoot = newItem;
		return;
	}

	registerItem(newItem, UpdateManager::customRoot);
}


void UpdateManager::unRegisterCustomUpdate(UpdateBase *item)
{
	// Make sure root is set
	if(UpdateManager::customRoot == 0)
		return;
	unRegisterItem(item, UpdateManager::customRoot);
}

extern "C" void UpdateManagerupdateTime()
{
	UpdateManager::updateTime();
}

