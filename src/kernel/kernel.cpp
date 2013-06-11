/*
 * kernel.cpp
 *
 *  Created on: 07/06/2013
 *      Author: Raul
 */

#include "kernel.h"

kernel::kernel()
{
	mode = FASTSIM;
	simulation_time = 0.0;
	elapsed_time = 0.0;
}

/*
 *  INTIALIZATION AND LOADING OPERATIONS
 */

//Initialization
void kernel::initialize()
{
	cout << "Kernel: Initializing World Maker Simulator... ";

	cout << "done!" << endl;
}

//Configure
void kernel::configure_simulation(MODE mode, double time)
{
	this->mode = mode;
	this->simulation_time = time;
	cout << "Kernel: Simulation configured, MODE: " << mode << " TIME: " << time << endl;
}

//Load modules
void kernel::load_modules()
{
	map<string,module*>::iterator it;
	module *mod;

	for(it = module_list.begin(); it != module_list.end(); it++)
	{
		mod = it->second;
		cout << "Kernel: Loading module \"" << mod->get_module_name() << "\"... ";

		try
		{
			mod->load();
			cout << "done!" << endl;

		}
		catch(string & e)
		{
			cout << "FAIL!" << endl;
			cout << "EXCEPTION: " << e << endl;
		}
	}
}

/*
 * WORLD OPERATIONS
 */

//Register world


/*
 * ENTITIES OPERATIONS
 */

//Register entity


/*
 *  MODULE MANAGING OPERATIONS
 */

//Register module
void kernel::register_module(module *mod)
{
	try{
		string mod_name = mod->get_module_name();

		cout << "Kernel: Registering module \"" << mod_name << "\"... ";

		if(module_list.find(mod_name) == module_list.end())
		{
			module_list[mod_name] = mod;
			cout << "done!" << endl;
		}
		else
		{
			cout << "FAIL!" << endl;
			throw (string)"Module with name \""+mod_name+"\" is already registered";
		}
	}
	catch (string & e)
	{
		cout << "EXCEPTION: " << e << endl;
	}
}

/*
 *  MODULE MANAGING OPERATIONS
 */

//Begin simulation
void kernel::simulate()
{
	map<string,module*>::iterator it;
	double delta;
	clock_t last, now;

	cout << "Kernel: Simulation started" << endl;

	delta = 1.0;
	last = clock();

	while(elapsed_time < simulation_time)
	{
		//////REAL-TIME SIMULATION
		switch(mode)
		{
		case REALTIME:
			now = clock();
			delta = (double)(now - last) / CLOCKS_PER_SEC;
			last = now;
			break;

		case FASTSIM:
			delta = 1.0;
			break;
		}

		//Update module ticks
		for(it = module_list.begin(); it != module_list.end(); it++)
		{
			it->second->tick(delta);
		}

		//Update elapsed time
		elapsed_time += delta;
	}

	cout << "Kernel: Simulation ended, " << elapsed_time << " seconds elapsed" << endl;
}


/*
 *  UNLOAD OPERATIONS
 */

//Unload modules
void kernel::unload_modules()
{
	map<string,module*>::iterator it;
	module *mod;

	for(it = module_list.begin(); it != module_list.end(); it++)
	{
		mod = it->second;
		cout << "Kernel: Unloading module \"" << mod->get_module_name() << "\"... ";

		try
		{
			mod->unload();
			cout << "done!" << endl;

		}
		catch(string & e)
		{
			cout << "FAIL!" << endl;
			cout << "EXCEPTION: " << e << endl;
		}
	}
}


/* Destructor */
kernel::~kernel()
{


}
