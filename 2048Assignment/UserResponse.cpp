#include "UserResponse.h"


UserResponse::UserResponse()
{
	ResponseType = ResponseType::Invalid;
	Dir = Direction::Unknown;
	IsContinue = true;

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
			ResponseType = IsMove;
			break;
		case 75:
			//left
			Dir = Left;
			ResponseType = IsMove;
			break;
		case 77:
			//right
			Dir = Right;
			ResponseType = IsMove;
			break;
		case 80:
			//down
			Dir = Down;
			ResponseType = IsMove;
			break;
		}
	}
	else if (ch == 117)
	{
		// b key
		ResponseType = IsUndo;
	}
	else if (ch == 120)
	{
		// x key
		IsContinue = false;
		ResponseType = ResponseType::Invalid;
	}
	else if (ch == 116)
	{
		//t key
		ResponseType = IsTest;
	}

	//the rest are the other keys, we alreayd have IsContinue set to true
}
