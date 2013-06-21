
#include "kernel.h"

using namespace std;

namespace world_maker {

Kernel::Kernel()
{
	mode = FASTSIM;
	simulation_time = 0.0;
	elapsed_time = 0.0;
}

/*************************************************
 *  INTIALIZATION AND LOADING OPERATIONS
 ************************************************/

void
Kernel::initialize()
{
	cout << "Kernel: Initializing World Maker Simulator... ";

	//Do initializations

	cout << "done!" << endl;
}

void
Kernel::register_module(Module *module)
{
	mod_manager.register_module(module); /* Register module from parameter in kernel */
}

void
Kernel::initialize_modules()
{
	mod_manager.init_modules(); /* Call module manager to initialize all modules */
}

void
Kernel::configure_simulation(MODE mode, double time)
{
	this->mode = mode; /* Set simulation mode from params */
	this->simulation_time = time; /* Set simulation time from params */
	cout << "Kernel: Simulation configured, MODE: " << mode << " TIME: " << time << endl;
}

void
Kernel::load_modules()
{
	mod_manager.load_modules(); /* Call module manager to load all modules */
}

/*************************************************
 * WORLD OPERATIONS
 ************************************************/

//Register world


/*************************************************
 * ENTITIES OPERATIONS
 ************************************************/

//Register entity


/*************************************************
 *  SIMULATION OPERATIONS
 ************************************************/

void
Kernel::simulate()
{
	double delta;
	clock_t last, now;

	cout << "Kernel: Simulation started" << endl;

	delta = 1.0;

	/* Initializes last clock time to for first iteration */
	last = clock();

	while(elapsed_time < simulation_time) /*  Iterates until simulation elapsed time reach maximum simulation time */
	{
		switch(mode) /* Simulation mode */
		{
		/* Real time simulation */
		case REALTIME:
			/* How much time has passed since last iteration */
			now = clock();
			delta = (double)(now - last) / CLOCKS_PER_SEC;
			last = now;
			break;
		/* Fast time simulation */
		case FASTSIM:
			/* Delta is fixed */
			delta = FAST_SIM_DELTA;
			break;
		}

		/* Call module manager to update all modules with this delta */
		mod_manager.tick_modules(delta);

		/* Count how much simulation time has passed */
		elapsed_time += delta;
	}

	cout << "Kernel: Simulation ended, " << elapsed_time << " seconds elapsed" << endl;
}


/*************************************************
 *  UNLOAD OPERATIONS
 ************************************************/

void
Kernel::unload_modules()
{
	mod_manager.unload_modules(); /* Call module manager to unload all modules */
}


/* Destructor */
Kernel::~Kernel()
{


}

} /* namespace world_maker */
