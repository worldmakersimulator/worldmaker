
#ifndef KERNEL_MODULE_H_
#define KERNEL_MODULE_H_

#include <iostream>
#include "common.h"

using namespace std;

namespace world_maker {

/**
 * Class Module.
 * This class represents a functional module that can be loaded in the kernel.
 */
class Module {
private:
	string name;	/* Module name, must be unique*/

public:

	/* Constructor */
	Module(string name);

	/* Destructor */
	virtual ~Module();

	/*************************************************
	 *  GETTING DATA METHODS
	 ************************************************/

	string get_module_name();

	/*************************************************
	 *  INITIALIZATION AND LOADING OPERATIONS
	 ************************************************/

	/**
	 * Initialize this module.
	 * This function must be called only from kernel.
	 * Module must implement this function to initialize itself.
	 * Must throw an exception with string description if initialization fails.
	 */
	virtual void initialize() = 0;

	/**
	 * Load this module.
	 * This function must be called only from kernel.
	 * Module must implement this function to load needed resources.
	 * Must throw an exception with string description if loading fails.
	 */
	virtual void load() = 0;

	/*************************************************
	 *  SIMULATION OPERATIONS
	 ************************************************/

 	/**
 	 * Update function.
 	 * This function must be called only from kernel.
 	 * Module must implement this function to update itself in every simulation tick.
 	 * \param delta Contains delta in seconds from last tick.
 	 */
 	virtual void tick(double delta) = 0;


 	/*************************************************
	 *  UNLOAD OPERATIONS
	 ************************************************/

	/**
	 * Unload this module.
	 * This function must be called only from kernel.
	 * Module must implement this function to release its resources.
	 * Must throw an exception with string description if unload fails.
	 */
 	virtual void unload() = 0;

};

} /* namespace world_maker */


#endif /* KERNEL_MODULE_H_ */
