
#include <iostream>
#include "kernel.h"
#include "module.h"
#include "worldmanager.h"

using namespace std;
using namespace world_maker;

int main() {
	Kernel *ker;			/* Kernel */
	Module *world;	/* World manager module */

	/* Initialize kernel */
	cout << "Begin execution" << endl;
	ker = new Kernel();
	ker->initialize();

	/* Declare modules */
	world = new WorldManager("WorldManager");

	/* Register modules */
	ker->register_module(world);

	/* Initialize all modules */
	ker->initialize_modules();

	/* Load all modules */
	ker->load_modules();

	/* Configure simulation */
	ker->configure_simulation(Kernel::FASTSIM, 20.0);

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
