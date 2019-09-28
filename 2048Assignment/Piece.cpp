#include "Piece.h"
#include <iostream>

Piece::Piece()
{
	prevPiece = nullptr;
	nextPiece = nullptr;

	currentScore = 0;

	X =_x = 0;
	Y =_y = 0;
	_id = 0;
}

Piece::Piece(int x, int y)
{
	prevPiece = nullptr;
	nextPiece = nullptr;

	currentScore = 0;

	X = _x = x;
	Y = _y = y;
	_id = 0;
}

Piece::~Piece()
{
	
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
	_prevScores.push(currentScore);
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
	cout << "[" << _x << "," << _y << "]";
}

void Piece::UndoScore()
{
	if (!_prevScores.empty())
	{
		currentScore = _prevScores.top();
		_prevScores.pop();
	}
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
			numIterations--;
		}
		else
		{
			if (p->prevPiece == nullptr)
			{
				return this;
			}

			p = p->prevPiece;
			numIterations++;
		}
		
	} while (numIterations > 0 || numIterations < 0);

	return p;
}