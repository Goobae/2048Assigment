#include "UserRespone.h"


UserRespone::UserRespone()
{
	IsValidResponse = false;
	IsContinue = true;
	Dir = Unknown;

	CheckResponse();
}

void UserRespone::CheckResponse()
{
	int ch = _getch();
	if (ch == 0 || ch == 224)
	{
		switch (_getch())
		{
		case 72:
			//up
			Dir = Up;
			break;
		case 75:
			//left
			Dir = Left;
			break;
		case 77:
			//right
			Dir = Right;
			break;
		case 80:
			//down
			Dir = Down;
			break;
		}
	}

	if (Dir == Unknown)
	{
		IsValidResponse = false;
	}
	else
	{
		IsContinue = true;
	}
}
