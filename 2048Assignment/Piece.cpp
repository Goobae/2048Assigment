#include "Piece.h"

Piece::Piece(int x, int y)
{
	_currentScore = 0;
	_id = 0;

	X = _x = x;
	Y = _y = y;	

	PrevPiece = nullptr;
	NextPiece = nullptr;
}

Piece::~Piece()
{
	PrevPiece = nullptr;
	NextPiece = nullptr;

	_prevScores.empty();
}

void Piece::DrawCoordinates()
{
	cout << "[" << _x << "," << _y << "]";
}

void Piece::DrawScore()
{
	cout << _currentScore;
}

void Piece::SetId(int id)
{
	_id = id;
}

void Piece::SetScore(int score)
{
	_prevScores.push(_currentScore);
	_currentScore = score;
}

void Piece::UndoScore()
{
	if (!_prevScores.empty())
	{
		_currentScore = _prevScores.top();
		_prevScores.pop();
	}
}

int Piece::GetId()
{
	return _id;
}

int Piece::GetScore()
{
	return _currentScore;
}

Piece* Piece::GetNextPiece(Direction dir, Process proc, int boardSize)
{
	Piece* p = this;

	if (proc == ProcessZeros)
	{
		switch (dir)
		{
		case Left:
			return p->_GetAfter(1);
			break;
		case Up:
			return p->_GetAfter(boardSize);
			break;
		case Right:
			return p->_GetAfter(-1);
			break;
		case Down:
			return p->_GetAfter(-boardSize);
			break;
		case Unknown:
		default:
			return nullptr;
			break;
		}
	}
	else if (proc == ProcessScores)
	{
		switch (dir)
		{
		case Left:
			return p->_GetAfter(-1);
			break;
		case Up:
			return p->_GetAfter(-boardSize);
			break;
		case Right:
			return p->_GetAfter(1);
			break;
		case Down:
			return p->_GetAfter(boardSize);
			break;
		case Unknown:
		default:
			return nullptr;
			break;
		}
	}
}

Piece* Piece::GetNextRowPiece(Direction dir, Process proc, int boardSize)
{
	Piece* p = this;

	if (proc == ProcessZeros)
	{
		switch (dir)
		{
		case Left:
			return p->_GetAfter(boardSize);
			break;
		case Up:
			return p->_GetAfter(1);
			break;
		case Right:
			return p->_GetAfter(-boardSize);
			break;
		case Down:
			return p->_GetAfter(-1);
			break;
		case Unknown:
		default:
			return nullptr;
			break;
		}
	}
	else if (proc == ProcessScores)
	{
		switch (dir)
		{
		case Left:
			return p->_GetAfter(-boardSize);
			break;
		case Up:
			return p->_GetAfter(-1);
			break;
		case Right:
			return p->_GetAfter(boardSize);
			break;
		case Down:
			return p->_GetAfter(1);
			break;
		case Unknown:
		default:
			return nullptr;
			break;
		}
	}
}

Piece* Piece::_GetAfter(int numIterations)
{
	if (numIterations == 0)
		return this;
	
	Piece* p = this;

	do
	{
		if (numIterations > 0) {

			
			if (p->NextPiece == nullptr)
			{
				return nullptr;
			}

			p = p->NextPiece;
			numIterations--;
		}
		else
		{
			if (p->PrevPiece == nullptr)
			{
				return nullptr;
			}

			p = p->PrevPiece;
			numIterations++;
		}
		
	} while (numIterations > 0 || numIterations < 0);

	return p;
}