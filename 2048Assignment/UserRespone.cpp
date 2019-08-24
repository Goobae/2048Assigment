#include "UserRespone.h"

UserRespone::UserRespone(int response)
{
	Response = response;
	IsValidResponse = false;
	IsContinue = true;
	Dir = Unknown;

	CheckResponse();
}

void UserRespone::CheckResponse()
{
	switch (Response)
	{

	case 65:
		Dir = Up;
		break;
	case 66:
		Dir = Down;
		break;
	case 67:
		Dir = Right;
		break;
	case 68:
		Dir = Left;
		break;
	default:
		Dir = Unknown;
		break;
	}

	if (Dir == Unknown)
	{
		IsValidResponse = false;
	}
	if (Response == 113 || Response == 81)
	{
		IsContinue = false;
	}
	else
	{
		IsContinue = true;
	}
}
