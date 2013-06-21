
#ifndef KERNEL_KERNEL_H_
#define KERNEL_KERNEL_H_

#include <iostream>
#include <map>
#include <ctime>

#include "common.h"
#include "module.h"
#include "modulemanager.h"

#define FAST_SIM_DELTA 1.0 /* Simulation delta in seconds for fast simulation */

using namespace std;

namespace world_maker {

/**
 * Class Kernel.
 * This class represents the core functionality of World Maker Simulator.
 */
class Kernel {

public:
	enum MODE {FASTSIM, REALTIME};	/* Simulation modes enumeration */

private:
	MODE mode;				/* Simulation mode */
	double simulation_time;	/* Simulation time in seconds */
	double elapsed_time;	/* Simulation elapsed time in seconds */

	ModuleManager mod_manager;	/* Module manager */

public:

	/** Constructor */
	Kernel();


	/*************************************************
	 *  INTIALIZATION AND LOADING OPERATIONS
	 ************************************************/

 	/**
 	 * Initializes the kernel.
 	 * This must be done before anything, object creation.
 	 */
 	void initialize();

 	/**
	 * Register a module in kernel.
	 * Adds the module to list for execution.
	 * \param module Module pointer to be registered in kernel.
	 */
	void register_module(Module *module);

 	/**
	 * Initializes all registered modules.
	 * Iterates module list and call its initialization functions.
	 */
	void initialize_modules();

	/**
	 * Configure simulation.
	 * Specify simulation mode and total time in seconds to simulate
	 * \param mode Set simulation mode.
	 * \param time Set simulation total time in seconds.
	 */
	void configure_simulation(MODE mode, double time);

	/**
	 * Load all registered modules.
	 * Iterates module list and call its loading functions.
	 */
	void load_modules();

 	/************************************************
 	 * WORLD OPERATIONS
 	 ***********************************************/

 	//Register world


 	/************************************************
 	 * ENTITIES OPERATIONS
 	 ***********************************************/

 	//Register entity


 	/*************************************************
	 *  SIMULATION OPERATIONS
	 ************************************************/

 	/**
 	 * Initiates simulation.
 	 * Before calling this function, simulation must be configured with corresponding method.
 	 * The function returns when simulation is over.
 	 */
 	void simulate();

 	/*************************************************
 	 *  UNLOAD OPERATIONS
 	 ************************************************/

 	/**
 	 * Unload loaded modules.
 	 * Unload all registered modules in module list.
 	 */
 	void unload_modules();

 	/* Destructor */
 	~Kernel();
};

}	/* namespace world_maker */

#endif /* KERNEL_KERNEL_H_ */
