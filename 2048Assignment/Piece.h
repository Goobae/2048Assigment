#pragma once
#include "Direction.h"

class Piece
{
public:
	Piece();
	Piece(Piece* east, Piece* north, Piece* west, Piece* south);
	~Piece();

	int GetScore();
	void SetScore(int score);
	void Draw();
	
private:
	Piece* northPiece;
	Piece* southPiece;
	Piece* eastPiece;
	Piece* westPiece;
	
	int currentScore;
};