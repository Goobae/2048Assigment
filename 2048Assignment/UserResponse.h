#pragma once
#include <conio.h>

#include "Direction.h"
#include "ResponseType.h"

using namespace std;

class UserResponse
{
public:
	UserResponse();

	bool IsContinue;
	Direction Dir;
	ResponseType ResponseType;

private:
	void _CheckResponse();
};