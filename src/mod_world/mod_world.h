/*
 * mod_world.h
 *
 *  Created on: 11/06/2013
 *      Author: Raul
 */

#ifndef KERNEL_MOD_WORLD_H_
#define KERNEL_MOD_WORLD_H_

#include <iostream>

#include "common.h"
#include "module.h"

using namespace std;

class mod_world : public module{


public:

	/* Constructor */
	mod_world(string name);

	/* Destructor */
	~mod_world();

};

#endif /* KERNEL_MOD_WORLD_H_ */
