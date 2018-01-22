#pragma once
#include "Direction.h"

class Board
{
public:
	Board();
	~Board();

	void Swipe(Direction direction);

	void GenerateGame();

private:
	int* topLeftPiece;
};