
#ifndef WORLDMANAGER_WORLDMANAGER_H_
#define WORLDMANAGER_WORLDMANAGER_H_

#include <iostream>

#include "common.h"
#include "module.h"

using namespace std;

namespace world_maker {

/**
 * Class WorldManager.
 * This class represents a simulation world manager.
 * Controls terrain and natural resources.
 */
class WorldManager : public Module{


public:

	/* Constructor */
	WorldManager(string name);

	/* Destructor */
	~WorldManager();

	/**
	 * Initialize world manager.
	 * This function must be called only from kernel.
	 * Throw an exception with string description if initialization fails.
	 */
	void initialize();

	/**
	 * Load world manager.
	 * This function must be called only from kernel.
	 * Throw an exception with string description if loading fails.
	 */
	void load();

	/*************************************************
	 *  SIMULATION OPERATIONS
	 ************************************************/

	/**
	 * Update function.
	 * This function must be called only from kernel.
	 * \param delta Contains delta in seconds from last tick.
	 */
	void tick(double delta);


	/*************************************************
	 *  UNLOAD OPERATIONS
	 ************************************************/

	/**
	 * Unload world manager module.
	 * This function must be called only from kernel.
	 * Throw an exception with string description if unload fails.
	 */
	void unload();

};

} /* namespace world_maker */

#endif /* WORLDMANAGER_WORLDMANAGER_H_ */
