#pragma once
#include "Direction.h"
#include <string>

using namespace std;

class Piece
{
public:
	Piece();
	Piece(string representation);
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
	string rep;
};