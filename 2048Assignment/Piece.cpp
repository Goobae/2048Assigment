#include "Piece.h"
Piece::Piece(Piece* east, Piece* north, Piece* west, Piece* south)
{
	eastPiece = east;
	northPiece = north;
	westPiece = west;
	southPiece = south;

	currentScore = 0;
}

Piece::~Piece()
{
	eastPiece = northPiece = westPiece = southPiece = 0;
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