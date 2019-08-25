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

	X =_x = 0;
	Y =_y = 0;
}

Piece::Piece(int x, int y)
{
	prevPiece = nullptr;
	nextPiece = nullptr;

	currentScore = 0;

	X = _x = x;
	Y = _y = y;
}

Piece::~Piece()
{
	/*eastPiece = northPiece = westPiece = southPiece = nullptr;*/
}

int Piece::GetScore()
{
	return currentScore;
}


int Piece::GetId()
{
	return _id;
}

void Piece::SetScore(int score)
{
	currentScore = score;
}

void Piece::SetId(int id)
{
	_id = id;
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

Piece* Piece::GetAfter(int numIterations)
{
	if (numIterations == 0)
		return this;
	
	Piece* p = this;

	do
	{
		if (numIterations > 0) {

			
			if (p->nextPiece == nullptr)
			{
				return this;
			}

			p = p->nextPiece;
		}
		// p = -3
		else
		{
			//p =-3, direction = down, 
			if (p->prevPiece == nullptr)
			{
				return this;
			}
			p = p->prevPiece;
		}
		numIterations--;
	} while (numIterations > 0 || numIterations < 0);

	return p;
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