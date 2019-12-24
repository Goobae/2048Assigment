#pragma once
#include "Direction.h"
#include "ResponseType.h"
#include <conio.h>

class UserResponse
{
public:

	UserResponse();

	bool IsContinue;
	ResponseType ResponseType;
	Direction Dir;

private:
	void CheckResponse();
};

