#pragma once
#include "Direction.h"
#include "Piece.h"

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