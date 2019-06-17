//#pragma once
#include "Direction.h"
#include "GReturn.h"

class SwipeBehavior
{
	SwipeBehavior();
	~SwipeBehavior();

	GReturn Swipe(Direction* dir);
}; 