
#include "worldmanager.h"

using namespace std;

namespace world_maker {

/* Constructor */
WorldManager::WorldManager(string name) : Module(name)
{

}

/* Destructor */
WorldManager::~WorldManager()
{

}

void
WorldManager::initialize()
{
	// Do initializations
}

void
WorldManager::load()
{
	// Loading...
}

void
WorldManager::tick(double delta)
{
	// Update world elements
}

void
WorldManager::unload()
{
	// Unloading...
}

} /* namespace world_manager */
