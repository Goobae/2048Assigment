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

	Piece* GetPiece(int x, int y);

	void Draw();
	void Swipe(Direction direction);

	void GenerateBoard();

private:
	Piece* Pieces;

	
};