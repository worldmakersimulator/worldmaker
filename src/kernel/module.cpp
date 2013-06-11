/*
 * module.cpp
 *
 *  Created on: 07/06/2013
 *      Author: Raul
 */

#include "module.h"

module::module(string name)
{
	this->name = name;

}

void module::initialize()
{
	cout << name+": Initializing..." << endl;

	cout << name+": Initialized" << endl;
}

string module::get_module_name()
{
	return name;
}

/* Load module */
void module::load()
{
	//Loads module
}

/*
 *  SIMULATION OPERATIONS
 */

//Tick update function
void module::tick(double delta)
{
	//Do something
}


/*
 *  UNLOAD OPERATIONS
 */

//Unload module
void module::unload()
{
	//Unload module
}

module::~module()
{


}


