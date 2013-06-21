
#include "module.h"

namespace world_maker {

/* Constructor */
Module::Module(string name)
{
	this->name = name;	/* Set module name */
}


Module::~Module()
{

}

/*************************************************
 *  GETTING DATA METHODS
 ************************************************/

string
Module::get_module_name()
{
	return name;
}

} /* namespace world_maker */

