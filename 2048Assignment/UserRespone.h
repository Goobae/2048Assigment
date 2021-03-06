#pragma once
#include "Direction.h"
#include <conio.h>

struct Response
{
	enum
	{
		IsContinue,
		IsUndo,
		IsTest,
		IsMove,
		Unknown
	} ResponseType = Unknown;
};

class UserResponse
{
public:

	UserResponse();

	Response ResponseType;
	Direction Dir;

private:
	void CheckResponse();
};

