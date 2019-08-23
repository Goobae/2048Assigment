#pragma once
#include <string>
#include "Board.h"
#include <stdio.h>

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
	Board* board;

	Direction GetUserInputAndClean();
};

