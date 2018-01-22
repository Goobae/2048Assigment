#pragma once
#include "Direction.h"

class Piece
{
public:
	Piece(Piece* east, Piece* north, Piece* west, Piece* south);
	~Piece();

	void Swipe(Direction direction);
	
private:
	Piece* northPiece;
	Piece* southPiece;
	Piece* eastPiece;
	Piece* westPiece;
	
	int currentScore;
};