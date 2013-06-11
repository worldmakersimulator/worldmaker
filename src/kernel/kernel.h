/*
 * kernel.h
 *
 *  Created on: 07/06/2013
 *      Author: Raul
 */

#ifndef KERNEL_H_
#define KERNEL_H_

#include <iostream>
#include <map>
#include <ctime>
#include "module.h"

using namespace std;

class kernel {

public:
	enum MODE {FASTSIM, REALTIME};

private:
	MODE mode;
	double simulation_time;
	double elapsed_time;
	map <string, module*> module_list;


public:

	/* Constructor */
	kernel();


	/*
	 *  INTIALIZATION AND LOADING OPERATIONS
	 */

 	//Initialization
 	void initialize();

 	//Configure
 	void configure_simulation(MODE mode, double time);

 	//Load modules
 	void load_modules();


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
 	void register_module(module *mod);

 	/*
	 *  SIMULATION OPERATIONS
	 */

 	//Begin simulation
 	void simulate();

 	/*
 	 *  UNLOAD OPERATIONS
 	 */

 	//Unload modules
 	void unload_modules();

 	/* Destructor */
 	~kernel();
};


#endif /* KERNEL_H_ */
