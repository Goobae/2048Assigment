#pragma once
#include "Direction.h"
#include <conio.h>

class UserRespone
{
public:

	UserRespone();

	bool IsValidResponse;
	bool IsContinue;
	Direction Dir;

private:
	void CheckResponse();
};

