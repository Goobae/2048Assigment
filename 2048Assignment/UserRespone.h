#pragma once
#include "Direction.h"
#include <conio.h>

class UserRespone
{
public:

	UserRespone();

	bool IsContinue;
	bool IsUndo;
	Direction Dir;

private:
	void CheckResponse();
};

