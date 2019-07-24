#pragma once
#include "Direction.h"
#include <string>

using namespace std;

class Piece
{
public:
	Piece();
	Piece(int x, int y);
	~Piece();

	int GetScore();
	void SetScore(int score);
	void Draw();
	
	Piece* northPiece;
	Piece* southPiece;
	Piece* eastPiece;
	Piece* westPiece;

	int _x;
	int _y;

private:
	int currentScore;

};