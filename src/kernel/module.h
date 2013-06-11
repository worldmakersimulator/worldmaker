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

 	/* Initialization */
 	void initialize();

 	string get_module_name();

 	/* Load module */
 	void load();

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

 	/* Destructor */
 	~module();
};


#endif /* MODULE_H_ */
