#include "UserResponse.h"


UserResponse::UserResponse()
{
	//IsContinue = true;
	//IsUndo = false;
	//IsTest = true;
	//ResponseType = ResponseType.Unknown;
	Dir = Unknown;

	CheckResponse();
}

void UserResponse::CheckResponse()
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
	else if (ch == 117)
	{
		// b key
		//IsUndo = true;
	}
	else if (ch == 120)
	{
		// x key
		//IsContinue = false;
	}
	else if (ch == 116)
	{
		//t key
		//IsTest = true;
	}

	//the rest are the other keys, we alreayd have IsContinue set to true
}
