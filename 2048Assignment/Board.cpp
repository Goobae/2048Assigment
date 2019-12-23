#include "Board.h"


Board::Board()
{
	Pieces_front = NULL;
	Pieces_back = NULL;
	boardSize = 4;
	totalPieces = boardSize * boardSize;
	smallestNumber = 2;
	biggestNumber = smallestNumber;
	noMoreMoves = false;
}

Board::~Board()
{

}

/*
	Left To do:
	-make sure when 2 2 2 it goes to 4 2 not 2 4
	-make the numbers nicer to read



*/

void Board::SetRandomScores()
{
	Piece* p = GetPiece(0, 3);
	p->SetScore(2);

	p = GetPiece(1, 3);
	p->SetScore(2);

	p = GetPiece(2, 3);
	p->SetScore(2);
	//SetNextRandomPiece();
	//SetNextRandomPiece();
	///* initialize random seed: */
	//srand(time(NULL));

	//int iter = 0;
	///* generate secret number between 1 and 10: */
	//do
	//{
	//	int x, y;
	//	//if (iter == 0)
	//	//{
	//	//	x = 2;
	//	//	y = 3;
	//	//}
	//	//else
	//	//{
	//	//	x = 3;
	//	//	y = 3;
	//	//}
	//	x = rand() % boardSize;
	//	y = rand() % boardSize;

	//	Piece* p = GetPiece(x, y);
	//	p->SetScore(2);
	//	iter++;
	//} while (iter < 2);

}

Piece* Board::GetPiece(int x, int y)
{
	Piece* temp = nullptr;

	if (x >= boardSize || y >= boardSize || x < 0 || y < 0) {
		return temp;
	}

	temp = Pieces_front;

	for (int i = 0; i < y * boardSize + x; i++)
	{
		temp = temp->nextPiece;
	}

	return temp;
}

void Board::DrawCoordinates()
{
	Piece* temp = Pieces_front;
	int itr = 0;
	do
	{
		temp->DrawCoordinates();

		if (itr == boardSize - 1)
		{
			cout << endl;
			itr = 0;
		}
		else
		{
			cout << " ";
			itr++;
		}

		temp = temp->nextPiece;

	} while (temp != nullptr);
}

void Board::DrawScores()
{
	Piece* temp = Pieces_front;
	int itr = 0;
	do
	{
		temp->DrawScore();

		if (itr == boardSize - 1)
		{
			cout << endl;
			itr = 0;
		}
		else
		{
			cout << " ";
			itr++;
		}

		temp = temp->nextPiece;

	} while (temp != nullptr);
}

int Board::GetScore()
{
	return biggestNumber;
}

void Board::Swipe(Direction direction)
{
	if (direction != Unknown)
	{
		RemoveBlockingZeros(direction);
		//ProcessRow(direction);
	}

	SetScores();
	SetNextRandomPiece();
}

void Board::Undo()
{
	Piece* p = Pieces_front;

	do
	{
		p->UndoScore();

		p = p->nextPiece;

	} while (p->nextPiece != nullptr);
}

bool Board::NoMoreMoves()
{
	return noMoreMoves;
}

void Board::GenerateBoard()
{
	int y = 0;
	int x = 0;

	Piece* temp;
	Piece* prev_piece;

	Pieces_front = new  Piece(x, y);
	temp = Pieces_front;
	prev_piece = Pieces_front;

	x++;

	for (int i = 0; i < boardSize * boardSize; i++)
	{
		if (i == 0) { continue; } //we already created this piece....
		if (i % boardSize == 0) { y++; x = 0; } //simulate new row

		temp = new Piece(x, y);
		temp->SetScore(0);
		temp->SetId(i);
		temp->prevPiece = prev_piece;

		prev_piece->nextPiece = temp;
		prev_piece = temp;

		x++;
	}

	Pieces_back = temp;
	//temp = Pieces_front;

	//do
	//{
	//	if (Pieces_back == nullptr)
	//	{
	//		prev_piece;
	//	}
	//	temp = temp->nextPiece;

	//} while (temp != nullptr);
}

void Board::Test(Piece* p)
{
	p->SetScore(100);
}

void Board::ProcessRow(Direction dir)
{
	Piece* curPiece = Pieces_front;
	Piece* nextPiece = Pieces_front;

	int curPieceGetAfter = 0;
	int nextPieceGetAfter = 0;

	/* remember that they are all linked left to right
				[0, 0][1, 0][2, 0][3, 0]
				[0, 1][1, 1][2, 1][3, 1]
				[0, 2][1, 2][2, 2][3, 2]
				[0, 3][1, 3][2, 3][3, 3]

				[0, 0][1, 0][2, 0][3, 0][0, 1][1, 1][2, 1][3, 1][0, 2][1, 2][2, 2][3, 2][0, 3][1, 3][2, 3][3, 3]
	*/

	//iterate through the board to do the processing
	int innerIter = 0;
	int outerIter = 0;

	//prep the loop
	switch (dir)
	{
	case Right:
		nextPiece = Pieces_front->GetAfter(1);
		curPiece = Pieces_front;
		break;
	case Down:
		nextPiece = Pieces_front->GetAfter(boardSize);
		curPiece = Pieces_front;
		break;
	case Left:
		nextPiece = Pieces_back->GetAfter(-1);
		curPiece = Pieces_back;
		break;
	case Up:
		nextPiece = Pieces_back->GetAfter(-boardSize);
		curPiece = Pieces_back;
		break;
	}
	   
	do
	{
		innerIter = 0;
		do
		{
			if (curPiece == nextPiece)
			{
				break;
			}

			if (nextPiece->GetScore() == 0)
			{
				nextPiece->SetScore(curPiece->GetScore());
				curPiece->SetScore(0);
			}
			else if (curPiece->GetScore() != 0 && nextPiece->GetScore() != 0 && curPiece->GetScore() == nextPiece->GetScore())
			{
				nextPiece->SetScore(curPiece->GetScore() * 2);
				curPiece->SetScore(0);
			}
			else
			{
				//else check if any valid moves exist??
			}
			

			curPiece = nextPiece;
			switch (dir)
			{
			case Right:
				nextPiece = nextPiece->GetAfter(1);
				break;
			case Down:
				nextPiece = nextPiece->GetAfter(boardSize);
				break;
			case Left:
				nextPiece = nextPiece->GetAfter(-1);
				break;
			case Up:
				nextPiece = nextPiece->GetAfter(-boardSize);
				break;
			}

			innerIter++;

		} while (innerIter < boardSize - 1);

		outerIter++;

		switch (dir)
		{
		case Right:
			curPiece = Pieces_front->GetAfter(boardSize * outerIter);
			nextPiece = curPiece->GetAfter(1);
			break;
		case Down:
			curPiece = Pieces_front->GetAfter(outerIter);
			nextPiece = curPiece->GetAfter(boardSize);
			break;
		case Left:
			curPiece = Pieces_back->GetAfter(-boardSize * outerIter);
			nextPiece = curPiece->GetAfter(-1);
			break;
		case Up:
			curPiece = Pieces_back->GetAfter(-outerIter -1);
			nextPiece = curPiece->GetAfter(-boardSize);
			break;
		}
		
		
	} while (outerIter < boardSize);
}

void Board::RemoveBlockingZeros(Direction dir)
{
	//need to start opposite of the swipe
	Piece* curPiece = dir == Right || dir == Down ? Pieces_back: Pieces_front;
	Piece* nextPiece = GetNextPiece(curPiece, GetOppoDir(dir));
	Piece* startPiece = curPiece;
	Direction traversalDir = dir == Right || dir == Down ? Up : Down;
	
	do
	{
		do
		{
			if (curPiece->GetScore() == 0)
			{
				curPiece->SetScore(nextPiece->GetScore());
				nextPiece->SetScore(0);
			}

			curPiece = nextPiece;
			nextPiece = GetNextPiece(curPiece, GetOppoDir(dir));
		} while (nextPiece != nullptr);

		curPiece = GetNextPiece(startPiece, traversalDir);
		nextPiece = GetNextPiece(curPiece, GetOppoDir(dir));
		startPiece = curPiece;

	} while (curPiece != nullptr);
}

void Board::SetScores()
{
	int curSmall = 2;
	int curLarge = 0;

	Piece* p = Pieces_front;
	do
	{
		if (p->GetScore() != 0 && p->GetScore() < curSmall)
		{
			curSmall = p->GetScore();
		}

		if (p->GetScore() > curLarge)
		{
			curLarge = p->GetScore();
		}
		p = p->nextPiece;

	} while (p != nullptr);

	smallestNumber = curSmall;
	biggestNumber = curLarge;
}

Piece* Board::GetNextPiece(Piece* curPiece, Direction dir)
{
	//test to see if it is an edge piece
	if (curPiece == nullptr || curPiece->GetId() % boardSize == 0) 
	{
		return nullptr;
	}

	switch (dir)
	{
	case Right:
		if (curPiece->GetId() + 1 >= totalPieces)
			return nullptr;
		else
			return curPiece->GetAfter(1);
		break;
	case Down:
		if (curPiece->GetId() + boardSize >= totalPieces)
			return nullptr;
		else
			return curPiece->GetAfter(boardSize);
		break;
	case Left:
		if (curPiece->GetId() - 1 <= 0)
			return nullptr;
		else
			return curPiece->GetAfter(-1);
		break;
	case Up:
		if (curPiece->GetId() - boardSize <= 0)
			return nullptr;
		else
			return curPiece->GetAfter(-boardSize);
		break;
	}
	return nullptr;
}

Direction Board::GetOppoDir(Direction dir)
{
	switch (dir)
	{
	case Left:
		return Right;
	case Up:
		return Down;
	case Right:
		return Left;
	case Down:
		return Up;
	case Unknown:
		return dir;
	}
}

void Board::SetNextRandomPiece()
{
	Piece* p = Pieces_front;
	vector<Piece*> emptyPieces;
	
	do
	{
		if (p->GetScore() == 0)
		{
			emptyPieces.push_back(p);
		}

		p = p->nextPiece;

	} while (p->nextPiece != nullptr);

	if (emptyPieces.size() == 0) {
		noMoreMoves = true;
	}
	else
	{
		srand(time(NULL));
		emptyPieces.at(rand() % emptyPieces.size())->SetScore(smallestNumber);
	}
}

bool Board::ProcessNumber(int num)
{
	if (num == 1 ||	num % 2 == 0)
	{
		return true;
	}

	return false;
}

void Board::loopAll(void(*f)(Piece*), int start)
{
	//need to start opposite of the swipe
	Piece* curPiece = Pieces_front;
	Piece* nextPiece = Pieces_front->nextPiece;

	int iter = 0;
	do
	{
		if (iter >= start)
		{
			f(curPiece);
		}		

		curPiece = nextPiece;
		nextPiece = nextPiece->nextPiece;

	} while (nextPiece != nullptr);
}
