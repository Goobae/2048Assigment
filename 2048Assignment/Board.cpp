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
		int x = rand() % boardSize;
		int y = rand() % boardSize;

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

	temp = Pieces_front;

	do
	{
		if (Pieces_back == nullptr)
		{
			prev_piece;
		}
		temp = temp->nextPiece;

	} while (temp != nullptr);
}

void Board::ProcessRow(Direction dir)
{
	Piece* curPiece;
	Piece* nextPiece;

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
	vector<Piece*> toPorcess(boardSize);
	int iterator = 0;
	int tempScore = 0;


	//prep the loop
	if (dir == Right || dir == Down) {
		curPiece = Pieces_front;

		if (dir == Right)
		{
			nextPiece = Pieces_front->GetAfter(1);
		}
		else
		{
			nextPiece = Pieces_front->GetAfter(boardSize);
		}
	}
	else
	{
		curPiece = Pieces_back;

		if (dir == Left)
		{
			nextPiece = Pieces_back->GetAfter(-1);
		}
		else
		{
			nextPiece = Pieces_back->GetAfter(-boardSize);
		}
	}

	do
	{


		if (curPiece->GetScore() > nextPiece->GetScore() || curPiece->GetScore() == 0)
		{

		}
		else if (curPiece->GetScore() < nextPiece->GetScore())
		{

		}
		else
		{
			//curPiece.GetScore = nextPiece.GetScore

		}


		if (curPiece->GetScore() != 0)
		{
			tempScore = curPiece->GetScore();
		}

		if (ProcessNumber(curPiece->GetScore() + nextPiece->GetScore()) 
			|| nextPiece->GetScore() == tempScore
			|| nextPiece->GetScore() == 0)
		{
			toPorcess.push_back(curPiece);
		}
		else
		{
			ProcessGroup(toPorcess, tempScore - curPiece->GetScore());
		}
#pragma region nextPieceLogic

		//need to make sure we start with the  correct first piece/last piece
/*switch (dir)
{
case Left:
	nextPiece = Pieces_front->GetAfter(boardSize - 1);
	curPiece = Pieces_front->GetAfter(boardSize);

	break;
case Up:
	nextPiece = Pieces_back->GetAfter(-1);
	curPiece = Pieces_back;

	break;
case Right:
	nextPiece = Pieces_front->GetAfter(1);
	curPiece = Pieces_front;

	break;
case Down:
	curPiece = Pieces_front;
	nextPiece = Pieces_front->GetAfter(-boardSize + 1);

	break;
default:
	return;
	break;
}*/
#pragma endregion

	} while (iterator < boardSize - 1);
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