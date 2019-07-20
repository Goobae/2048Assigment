#include "Piece.h"
Piece::Piece()
{
	eastPiece = nullptr;
	northPiece = nullptr;
	westPiece = nullptr;
	southPiece = nullptr;

	currentScore = 0;
}

Piece::~Piece()
{
	eastPiece = northPiece = westPiece = southPiece = 0;
}

int Piece::GetScore()
{
	return currentScore;
}

void Piece::SetScore(int score)
{
	currentScore = score;
}

void Piece::Draw()
{

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