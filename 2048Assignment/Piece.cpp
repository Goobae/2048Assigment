#include "Piece.h"
#include <iostream>

Piece::Piece()
{
	//eastPiece = nullptr;
	//northPiece = nullptr;
	//westPiece = nullptr;
	//southPiece = nullptr;
	prevPiece = nullptr;
	nextPiece = nullptr;

	currentScore = 0;

	_x = 0;
	_y = 0;
}

Piece::Piece(int x, int y)
{
	prevPiece = nullptr;
	nextPiece = nullptr;

	currentScore = 0;

	_x = x;
	_y = y;
}

Piece::~Piece()
{
	/*eastPiece = northPiece = westPiece = southPiece = nullptr;*/
}

int Piece::GetScore()
{
	return currentScore;
}

void Piece::SetScore(int score)
{
	currentScore = score;
}

void Piece::DrawScore()
{
	cout << currentScore;
}

void Piece::DrawCoordinates()
{
	//string out =;
	cout << "[" << _x << "," << _y << "]";
}


//
//void Piece::Swipe(Direction direction)
//{
//	Piece* temp;
//
//	if (direction == East && eastPiece != 0)
//		temp = eastPiece;
//	else if (direction == North && northPiece != 0)
//		temp = eastPiece;
//	else if (direction == West && westPiece != 0)
//		temp = eastPiece;
//	else if (direction == South && southPiece != 0)
//		temp = eastPiece;
//	else
//		return;
//
//	if(temp ->currentScore == currentScore)
//		temp-> currentScore += currentScore;
//}