//#pragma once
#include "Direction.h"
#include "GReturn.h"

class SwipeBehavior
{
public:
	SwipeBehavior();
	~SwipeBehavior();

	GReturn Swipe(Direction dir);
}; 