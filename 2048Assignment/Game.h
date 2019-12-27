#pragma once
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "Board.h"
#include "Game.h"
#include "ResponseType.h"
#include "UserResponse.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();

	void Initialize();
	void Play();

private:
	bool isLoaded = false;
	Board* _board;

	void _ClearScreen();
	void _DrawControls();
	void _DrawGame();
	void _GameOver();
	bool _WillUserUndo();
	UserResponse* _GetUserInputAndClean();
};