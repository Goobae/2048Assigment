#include "Board.h"


Board::Board()
{
	Pieces_front = NULL;
	boardSize = 4;
}

Board::~Board()
{

}

void Board::SetRandomScores()
{
	/* initialize random seed: */
	srand(time(NULL));

	int iter = 0;
	/* generate secret number between 1 and 10: */
	do
	{
		int x, y;
		if (iter == 0)
		{
			x = 2;
			y = 2;
		}
		else
		{
			x = 2;
			y = 1;
		}
		//int x = rand() % boardSize;
		//int y = rand() % boardSize;

		Piece* p = GetPiece(x, y);
		p->SetScore(2);
		iter++;
	} while (iter < 2);

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

void Board::Swipe(Direction direction)
{
	if (direction != Unknown)
	{
		ProcessRow(direction);
	}
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
	int iterator = 0;
	int outerIter = 0;

	//prep the loop. start opposite of the swipe.
	switch (dir)
	{
	case Right:
		nextPiece = Pieces_front->GetAfter(1);
		curPiece = Pieces_front;
		break;
	case Down:
		nextPiece = Pieces_front->GetAfter(boardSize - 1);
		curPiece = Pieces_front;
		break;
	case Left:
		//returns this
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
		iterator = 0;
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
				continue;
			}
			else if (ProcessNumber(curPiece->GetScore() + nextPiece->GetScore()))
			{
				curPiece->SetScore(curPiece->GetScore() * 2);
				nextPiece->SetScore(0);
			}
			//else check if any valid moves exist??

			curPiece = nextPiece;
			switch (dir)
			{
			case Right:
				nextPiece = nextPiece->nextPiece;
			case Down:
				nextPiece = nextPiece->GetAfter(boardSize);
				break;
			case Left:
				nextPiece = nextPiece->prevPiece;
				break;
			case Up:
				nextPiece = nextPiece->GetAfter(-boardSize);
				break;
			}

			iterator++;

		} while (iterator < boardSize - 1);

		switch (dir)
		{
		case Right:
			curPiece = curPiece->GetAfter(outerIter + 1);
			nextPiece = curPiece->GetAfter(1);
			break;
		case Down:
			curPiece = Pieces_front->GetAfter(outerIter + 1);
			nextPiece = curPiece->GetAfter(boardSize - 1);
			break;
		case Left:
			curPiece = Pieces_back->GetAfter(-boardSize + 1);
			nextPiece = curPiece->GetAfter(-outerIter - 1);
			break;
		case Up:
			curPiece = Pieces_back->GetAfter(-outerIter -1);
			nextPiece = curPiece->GetAfter(-boardSize);
			break;
		}
		
		outerIter++;
	} while (outerIter < boardSize - 1);
}

void Board::ProcessGroup(vector<Piece*> toProcess, int totalScore)
{
	for (int i = 0; i < toProcess.size(); i++)
	{
		if (i == toProcess.size() - 1)
		{
			toProcess.at(i)->SetScore(totalScore);
		}
		else
		{
			toProcess.at(i)->SetScore(0);
		}
	}
}

bool Board::ProcessNumber(int num)
{
	if (num == 1 ||
		num % 2 == 0)
	{
		return true;
	}

	return false;
}