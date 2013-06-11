/*
 * module.cpp
 *
 *  Created on: 07/06/2013
 *      Author: Raul
 */

#include "module.h"

module::module(string name)
{

	//Set module name
	this->name = name;
}

/*
 * ***********************************************************
 * 	INTERFACES
 *
 *
 *
 * ***********************************************************
 */

/*
 *  INITIALIZATION AND LOADING OPERATIONS
 */



/*
 *  GETTING DATA METHODS
 */

string module::get_module_name()
{
	return name;
}



/*
 * ***********************************************************
 * 	PRIVATE OPERATIONS - DONT USE IN FINAL CLASSES
 *
 *
 *
 * ***********************************************************
 */

/*
 *  INITIALIZATION AND LOADING OPERATIONS
 */

/* This function must be override */
void module::initialize()
{
	//Do initializations
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


