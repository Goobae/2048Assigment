#include "Board.h"

/*
	Remember that they are all linked left to right
		[0, 0][1, 0][2, 0][3, 0]
		[0, 1][1, 1][2, 1][3, 1]
		[0, 2][1, 2][2, 2][3, 2]
		[0, 3][1, 3][2, 3][3, 3]

		[0, 0][1, 0][2, 0][3, 0][0, 1][1, 1][2, 1][3, 1][0, 2][1, 2][2, 2][3, 2][0, 3][1, 3][2, 3][3, 3]

	Left To do:
		Fix addition process flow so that it adds numbers from the opposite side.
*/

Board::Board()
{
	_piecesFront = NULL;
	_piecesBack = NULL;
	_boardSize = 4;
	_totalPieces = _boardSize * _boardSize;
	_smallestNumber = 2;
	_biggestNumber = _smallestNumber;
	_noMoreMoves = false;

	_PrimeAnswerArray();
}

Board::~Board()
{
	Piece* temp = _piecesFront;
	Piece* nextTemp = temp;
	while (temp->NextPiece != nullptr)
	{
		nextTemp = temp->NextPiece;
		temp->~Piece();
	}

	_piecesFront = nullptr;
	_piecesBack = nullptr;
}

void Board::DrawCoordinates()
{
	Piece* temp = _piecesFront;
	int itr = 0;
	do
	{
		temp->DrawCoordinates();

		if (itr == _boardSize - 1)
		{
			cout << endl;
			itr = 0;
		}
		else
		{
			cout << " ";
			itr++;
		}

		temp = temp->NextPiece;

	} while (temp != nullptr);
}

void Board::DrawScores()
{
	Piece* temp = _piecesFront;
	int itr = 0;
	do
	{
		temp->DrawScore();

		if (itr == _boardSize - 1)
		{
			cout << endl;
			itr = 0;
		}
		else
		{
			cout << " ";
			itr++;
		}

		temp = temp->NextPiece;

	} while (temp != nullptr);
}

void Board::GenerateBoard()
{
	int y = 0;
	int x = 0;

	Piece* temp;
	Piece* prev_piece;

	_piecesFront = new  Piece(x, y);
	temp = _piecesFront;
	prev_piece = _piecesFront;

	x++;

	for (int i = 0; i < _boardSize * _boardSize; i++)
	{
		if (i == 0) { continue; } //we already created this piece....
		if (i % _boardSize == 0) { y++; x = 0; } //simulate new row

		temp = new Piece(x, y);
		temp->SetScore(0);
		temp->SetId(i);
		temp->PrevPiece = prev_piece;

		prev_piece->NextPiece = temp;
		prev_piece = temp;

		x++;
	}

	_piecesBack = temp;
}

void Board::SetRandomScores()
{
	Piece* p = GetPiece(0, 0);
	p->SetScore(2);

	p = GetPiece(3, 0);
	p->SetScore(2);
	//_SetNextRandomPiece();
}

void Board::Swipe(Direction direction)
{
	if (direction != Unknown)
	{
		bool redo = true;
		while (redo)
		{
			_ProcessRow(direction, ProcessZeros);
			redo = _ProcessRow(direction, ProcessScores);
		}

	}

	_SetNextRandomPiece();
}

void Board::Undo()
{
	Piece* p = _piecesFront;

	do
	{
		p->UndoScore();

		p = p->NextPiece;

	} while (p->NextPiece != nullptr);
}

int Board::GetScore()
{
	return _biggestNumber;
}

bool Board::NoMoreMoves()
{
	return _noMoreMoves;
}

Piece* Board::GetPiece(int x, int y)
{
	Piece* temp = nullptr;

	if (x >= _boardSize || y >= _boardSize || x < 0 || y < 0) {
		return temp;
	}

	temp = _piecesFront;

	for (int i = 0; i < y * _boardSize + x; i++)
	{
		temp = temp->NextPiece;
	}

	return temp;
}

void Board::_PrimeAnswerArray()
{
	int score = 2;
	for (int i = 0; i < _answerArraySize; i++)
	{
		score = score * 2;
		_answerArray[i] = score;
	}
}

void Board::_SetNextRandomPiece()
{
	Piece* p = _piecesFront;
	vector<Piece*> emptyPieces;

	do
	{
		if (p->GetScore() == 0)
		{
			emptyPieces.push_back(p);
		}

		p = p->NextPiece;

	} while (p->NextPiece != nullptr);

	if (emptyPieces.size() == 0) {
		_noMoreMoves = true;
	}
	else
	{
		srand(time(NULL));
		emptyPieces.at(rand() % emptyPieces.size())->SetScore(_smallestNumber);
	}
}

bool Board::_IsStillSameRow(Piece* curPiece, Piece* nextPiece, Direction dir)
{
	if (curPiece == nullptr || nextPiece == nullptr)
	{
		return false;
	}

	switch (dir)
	{
	case Right:
	case Left:
		return curPiece->Y == nextPiece->Y;
	case Up:
	case Down:
		return curPiece->X == nextPiece->X;
	case Unknown:
	default:
		//this is an error
		return false;
	}

	return false;
}

bool Board::_ManageScores(Piece* curPiece, Piece* nextPiece)
{
	if (_ProcessNumber(curPiece, nextPiece))
	{
		nextPiece->SetScore(curPiece->GetScore() + nextPiece->GetScore());
		curPiece->SetScore(0);

		return true;
	}

	return false;
}

bool Board::_ManageZeros(Piece* curPiece, Piece* nextPiece)
{
	if (curPiece->GetScore() == 0 && nextPiece->GetScore())
	{
		curPiece->SetScore(nextPiece->GetScore());
		nextPiece->SetScore(0);;

		return true;
	}

	return false;
}

bool Board::_ProcessNumber(Piece* curPiece, Piece* nextPiece)
{
	if (curPiece->GetScore() == 0 || nextPiece->GetScore() == 0)
		return false;

	for (size_t i = 0; i < _answerArraySize; i++)
	{
		if (curPiece->GetScore() + nextPiece->GetScore() == _answerArray[i])
		{
			return true;
		}
	}


	return false;
}

bool Board::_ProcessRow(Direction dir, Process proc)
{
	Piece* curPiece = _GetFirstPiece(dir, proc);
	Piece* nextPiece = curPiece->GetNextPiece(dir, proc, _boardSize);
	Piece* holderPiece = curPiece;

	bool reset = false;
	int counter = 0;
	bool isMasterReset = false;

	while (counter < _boardSize)
	{
		do
		{
			switch (proc)
			{
			case ProcessZeros:
				if (_ManageZeros(curPiece, nextPiece))
				{
					reset = true;
				}
				break;
			case ProcessScores:
				if (_ManageScores(curPiece, nextPiece))
				{
					isMasterReset = true;
				}
				break;
			default:
				break;
			}

			if (reset)
			{
				nextPiece = holderPiece;
				reset = false;
			}

			curPiece = nextPiece;
			nextPiece = curPiece->GetNextPiece(dir, proc, _boardSize);

		} while (_IsStillSameRow(curPiece, nextPiece, dir));

		curPiece = holderPiece->GetNextRowPiece(dir, proc, _boardSize);

		if (curPiece == nullptr)
			break;

		nextPiece = curPiece->GetNextPiece(dir, proc, _boardSize);
		holderPiece = curPiece;

		counter++;
	}

	return isMasterReset;
}

Piece* Board::_GetFirstPiece(Direction dir, Process proc)
{
	if (proc == ProcessZeros) //proc 1 = remove 0 in between pieces
	{
		//removing 0's is out of the swipe
		switch (dir)
		{
		case Left:	// <- SO ->
		case Up:
			return _piecesFront;
		case Down:
		case Right:	// -> SO <-
			return _piecesBack;
		case Unknown:
		default:
			return nullptr;
		}
	}
	else if (proc == ProcessScores) // proc 2 = add up score
	{
		//just get direction of swipe
		switch (dir)
		{
		case Left:
		case Up:
			return _piecesBack;
		case Down:
		case Right:
			return _piecesFront;
		case Unknown:
		default:
			return nullptr;
		}
	}
	return nullptr;
}
