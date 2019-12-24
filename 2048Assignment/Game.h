#pragma once
#include <string>
#include "Board.h"
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include "UserResponse.h"
#include "ResponseType.h"
#include "Game.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();

	void Initialize();
	void Play();

	void TestFunc();
private:
	void DrawGame();
	void GameOver();
	void ClearScreen(); 
	void Test();

	Board* board;

	UserResponse* GetUserInputAndClean();
};

		

