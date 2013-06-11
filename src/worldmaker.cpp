//============================================================================
// Name        : worldmaker.cpp
// Author      : Raúl Moreno
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "kernel/kernel.h"
#include "kernel/module.h"
#include <windows.h>

using namespace std;

int main() {
	kernel *ker;
	module *world;

	/* Initialize kernel */
	cout << "Begin execution" << endl;
	ker = new kernel();
	ker->initialize();

	/* Declare modules */
	world = new module("WorldManager");

	/* Loading modules */
	ker->register_module(world);

	/* Load all modules */
	ker->load_modules();

	/* Configure simulation */
	ker->configure_simulation(kernel::FASTSIM, 20.0);

	//SIMULATE
	ker->simulate();

	/* Unload modules */
	ker->unload_modules();

	cout << "Freeing last resources... ";

	delete(world);
	delete(ker);

	cout << "DONE!" << endl;

	return 0;
}
