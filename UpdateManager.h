/* ========================================================================= *\
 *                                                                           *
 *       File: UpdateManager.h                                               *
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

#include <stdint.h>
#include <stdbool.h>

#include "UpdateBase.h"
#include "UpdateRoot.h"

#ifndef UPDATEMANAGER_H_
#define UPDATEMANAGER_H_

class UpdateManager
{
public:

	// Constructor
	UpdateManager();

	// Initializes root items
	static void init();

	// Assigns unique ID to item
	static uint32_t assignID();

	// Keeps track of timing
	static void updateTime();

	// Return time in ms since last second
	static uint16_t getTimeMilli();

	// Return total runtime
	static uint32_t getTimeS();


	// Register item in fixed update list
	static void registerFixedUpdate(UpdateBase *newItem);
	// Unregister item in fixed update list
	static void unRegisterFixedUpdate(UpdateBase *item);

	// Register item in custom update list
	static void registerCustomUpdate(UpdateBase *newItem);
	// Unregister item in custom update list
	static void unRegisterCustomUpdate(UpdateBase *item);

	// Calls fixed and custom updates in lists
	static void update();

	// Number of times per second `updateTime()` is called
	static const uint16_t SECOND_DIVDER = 1000;
	// Number of times `SECOND_DIVDER` increments before calling the fixed
	// updates
	static const uint8_t FIXED_SPEED = 10;

private:

	// Adds a new item to the end of a linked list
	static void registerItem(UpdateBase *newItem, UpdateBase *root);
	// Removes and item from anywhere in a linked list
	static void unRegisterItem(UpdateBase *item, UpdateBase *root);
	// Used to navigate a linked list
	static bool traverseList();


	// Runs all fixed updates
	static void runFixedUpdates();
	// Checks for which custom updates to run
	static void runCustomUpdates();

	// Index for traversing linked lists
	static UpdateBase *index;
	// Root for fixed updates
	static UpdateBase *fixedRoot;
	// Root for custom updates
	static UpdateBase *customRoot;

	// Flag to call fixed updates
	static bool fixedUpdate;
	// Flag to call custom updates
	static bool customUpdate;

	// Holds last issued ID
	static uint32_t idCounter;

	// Number of `SECOND_DIVDER`s since last second
	static uint16_t timeMilliSeconds; // `timeSeconds++` after 1000.
	// Runtime in seconds
	static uint32_t timeSeconds; // Good for 136 years of runtime

};

#endif /* UPDATEMANAGER_H_ */
