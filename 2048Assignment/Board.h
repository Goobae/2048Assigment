#pragma once
#include "Direction.h"
#include "Piece.h"
#include <iostream>

using namespace std;

class Board
{
public:
	Board();
	~Board();

	void Draw();
	void Swipe(Direction direction);

	void GenerateBoard();

private:
	Piece* zeroZero;
};