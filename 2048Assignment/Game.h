#pragma once
#include <string>
#include "Board.h"
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include "UserRespone.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();

	void Initialize();
	void Play();
private:
	void DrawGame();
	void IsGameOver();

	bool isGameOver;
	Board* board;

	UserRespone* GetUserInputAndClean();
};

