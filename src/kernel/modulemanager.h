
#ifndef KERNEL_MODULEMANAGER_H_
#define KERNEL_MODULEMANAGER_H_

#include <map>

#include "module.h"

using namespace std;

namespace world_maker {

/**
 * Class ModuleManager.
 * This class implements functionality for module management.
 */
class ModuleManager {

private:
	map <string, Module*> module_list;	/* List of registered modules */

public:
	/**
	 * Register a module in the manager.
	 * This function must be called only from kernel.
	 * \param p_module Pointer to module want to be registered in kernel.
	 */
	void register_module(Module *p_module);

	/**
	 * Initializes all registered modules.
	 * This function must be called only from kernel.
	 * Calls initialization functions in all modules in module list.
	 */
	void init_modules();

	/**
	 * Loads all registered modules.
	 * This function must be called only from kernel.
	 * Do not call before initialize all modules.
	 * Calls loading functions in all modules in module list.
	 */
	void load_modules();

	/**
	 * Update all registered modules.
	 * This function must be called only from kernel.
	 * Do not call before load all modules.
	 * Calls update functions in all modules in module list.
	 * \param delta Contains delta in seconds from last tick.
	 */
	void tick_modules(double delta);

	/**
	 * Unload all registered modules.
	 * This function must be called only from kernel.
	 * Do not call before load all modules.
	 * Calls unload functions in all modules in module list.
	 */
	void unload_modules();

};

}

#endif /* KERNEL_MODULEMANAGER_H_ */
