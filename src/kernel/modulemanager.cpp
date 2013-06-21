
#include "modulemanager.h"

using namespace std;

namespace world_maker {

void
ModuleManager::register_module(Module *p_module)
{
	try{
		string str_mod_name = p_module->get_module_name();	/* Get module unique name */

		cout << "Kernel: Registering module \"" << str_mod_name << "\"... ";

		if(module_list.find(str_mod_name) == module_list.end())	/* If module name is not registered already in module list */
		{
			module_list[str_mod_name] = p_module;
			cout << "done!" << endl;
		}
		else /* Error, module name must be unique */
		{
			cout << "FAIL!" << endl;
			throw (string)"Module with name \""+str_mod_name+"\" is already registered"; /* Throw exception with string details */
		}
	}
	catch (string & e)	/* If module registration fails throw exception */
	{
		cout << "EXCEPTION: " << e << endl;
	}
}

void
ModuleManager::init_modules()
{
	map<string,Module*>::iterator it;
	Module *p_module;

	/* Iterates modules in module list to initialization */
	for(it = module_list.begin(); it != module_list.end(); it++)
	{
		p_module = it->second; /* Get next module from iterator */
		cout << "Kernel: Initializing module \"" << p_module->get_module_name() << "\"... ";

		try
		{
			p_module->initialize(); /* Call current module initialization function */
			cout << "done!" << endl;

		}
		catch(string & e) /* If initialization fails */
		{
			cout << "FAIL!" << endl;
			cout << "EXCEPTION: " << e << endl;
		}
	}
}

void
ModuleManager::load_modules()
{
	map<string,Module*>::iterator it;
	Module *p_module;

	/* Iterates modules in module list to load */
	for(it = module_list.begin(); it != module_list.end(); it++)
	{
		p_module = it->second; /* Get next module from iterator */
		cout << "Kernel: Loading module \"" << p_module->get_module_name() << "\"... ";

		try
		{
			p_module->load(); /* Call current module load function */
			cout << "done!" << endl;

		}
		catch(string & e) /* If loading fails */
		{
			cout << "FAIL!" << endl;
			cout << "EXCEPTION: " << e << endl;
		}
	}
}

void
ModuleManager::tick_modules(double delta)
{
	map<string,Module*>::iterator it;

	/* Iterates modules in module list to call tick function */
	for(it = module_list.begin(); it != module_list.end(); it++)
	{
		it->second->tick(delta); /* Call module tick function */
	}

}

void
ModuleManager::unload_modules()
{
	map<string,Module*>::iterator it;
	Module *p_module;

	/* Iterates all modules in module list to call unloading functions */
	for(it = module_list.begin(); it != module_list.end(); it++)
	{
		p_module = it->second; /* Get next module in list */
		cout << "Kernel: Unloading module \"" << p_module->get_module_name() << "\"... ";

		try
		{
			p_module->unload(); /* Call module unload function */
			cout << "done!" << endl;

		}
		catch(string & e) /* If unload fails */
		{
			cout << "FAIL!" << endl;
			cout << "EXCEPTION: " << e << endl;
		}
	}
}

} /* namespace world_maker */

