/*
 * module.h
 *
 *  Created on: 07/06/2013
 *      Author: Raul
 */

#ifndef MODULE_H_
#define MODULE_H_

#include <iostream>

using namespace std;

class module {
private:
	string name;

public:

	/* Constructor */
	module(string name);

	/* Destructor */
	~module();

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

	string get_module_name();


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
	void initialize();



 	/* Register world */

 	/* Register entity */


	/*
	 *  SIMULATION OPERATIONS
	 */

 	//Tick update function
 	void tick(double delta);


 	/*
	 *  UNLOAD OPERATIONS
	 */

	//Unload module
	void unload();

};


#endif /* MODULE_H_ */
