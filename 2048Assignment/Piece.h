#pragma once
#include "Direction.h"

class Piece
{
public:
	Piece();
	~Piece();

	int GetScore();
	void SetScore(int score);
	void Draw();
	
	Piece* northPiece;
	Piece* southPiece;
	Piece* eastPiece;
	Piece* westPiece;

private:
	int currentScore;
};