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

	 remember that they are all linked left to right
				[0, 0][1, 0][2, 0][3, 0]
				[0, 1][1, 1][2, 1][3, 1]
				[0, 2][1, 2][2, 2][3, 2]
				[0, 3][1, 3][2, 3][3, 3]

				[0, 0][1, 0][2, 0][3, 0][0, 1][1, 1][2, 1][3, 1][0, 2][1, 2][2, 2][3, 2][0, 3][1, 3][2, 3][3, 3]


	Left To do:
	
*/

void Board::SetRandomScores()
{
	Piece* p = GetPiece(0, 0);
	p->SetScore(2);

	//p = GetPiece(1, 3);
	//p->SetScore(2);

	p = GetPiece(3, 0);
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
		ProcessRow(direction, ProcessZeros);
		ProcessRow(direction, ProcessScores);
	}

	//SetScores();
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

void Board::Test()
{
	
	Board b;
	
}

void Board::Test2()
{
	cout << "a";
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
}

Piece* Board::GetFirstPieceForDirectionAndProcess(Direction dir, Process proc)
{
	if (proc == ProcessZeros) //proc 1 = remove 0 in between pieces
	{
		//removing 0's is out of the swipe
		switch (dir)
		{
		case Left:	// <- SO ->
		case Up:
			return Pieces_front;
		case Down:
		case Right:	// -> SO <-
			return Pieces_back;
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
			return Pieces_back;
		case Down:
		case Right:
			return Pieces_front;
		case Unknown:
		default:
			return nullptr;
		}
	}
	return nullptr;
}

void Board::Test(Piece* p)
{
	p->SetScore(100);
}

void Board::ProcessRow(Direction dir, Process proc)
{
	Piece* curPiece = GetFirstPieceForDirectionAndProcess(dir, proc);
	Piece* nextPiece = curPiece->GetNextPiece(dir, proc, boardSize);
	Piece* holderPiece = curPiece;

	bool reset = false;
	int counter = 0;
	 
	while (counter < boardSize)
	{
		do
		{
			switch (proc)
			{
			case ProcessZeros:
				if (ManageZeros(curPiece, nextPiece))
				{
					reset = true;
				}
				break;
			case ProcessScores:
				ManageScores(curPiece, nextPiece);
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
			nextPiece = curPiece->GetNextPiece(dir, proc, boardSize);
			
		} while (IsStillSameRow(curPiece, nextPiece, dir));
		
		curPiece = holderPiece->GetNextRowPiece(dir, proc, boardSize);

		if (curPiece == nullptr)
			break;

		nextPiece = curPiece->GetNextPiece(dir, proc, boardSize);
		holderPiece = curPiece;

		counter++;
	} 
}

bool Board::IsStillSameRow(Piece* curPiece, Piece* nextPiece, Direction dir)
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

bool Board::ManageZeros(Piece* curPiece, Piece* nextPiece)
{
	if (curPiece->GetScore() == 0 && nextPiece->GetScore())
	{
		curPiece->SetScore(nextPiece->GetScore());
		nextPiece->SetScore(0);;

		return true;
	}

	return false;
}

bool Board::ManageScores(Piece* curPiece, Piece* nextPiece)
{
	if (ProcessNumber(curPiece->GetScore() + nextPiece->GetScore()))
	{
		nextPiece->SetScore(curPiece->GetScore() + nextPiece->GetScore());
		curPiece->SetScore(0);

		return true;
	}

	return false;
}

bool Board::ProcessNumber(int num)
{
	if (num != 0 && num != 2 && (num == 1 || num % 4 == 0))
	{
		return true;
	}

	return false;
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
