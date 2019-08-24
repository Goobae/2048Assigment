#pragma once
#include "Direction.h"
class UserRespone
{
public:

	UserRespone(int response);

	bool IsValidResponse;
	bool IsContinue;
	Direction Dir;
	int Response;

private:
	void CheckResponse();
};

