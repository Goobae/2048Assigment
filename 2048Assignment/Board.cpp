#include "Board.h"
#include <string>

Board::Board()
{
	Pieces_front = NULL;
	boardSize = 4;
}

Board::~Board()
{

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

void Board::Draw()
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

	//cout << endl;

	//temp = Pieces_front;
	//temp->DrawScore();
	//temp = temp->GetAfter(5);
	//temp->DrawScore();
	//cout << endl;

	//temp = Pieces_front;
	//temp->DrawScore();
	//temp = temp->GetAfter(2);
	//temp->DrawScore();
	//cout << endl;

	//temp = Pieces_front;
	//temp->DrawScore();
	//temp = temp->GetAfter(-7);
	//temp->DrawScore();
	//cout << endl;

}

void Board::Swipe(Direction direction)
{
	ProcessRow(direction);
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
		temp->SetScore(i);
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
	int iterator = 0;
	do
	{
		//need to make sure we start with the  correct first piece/last piece
		switch (dir)
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
			nextPiece = Pieces_back->GetAfter(-boardSize + 1);
			curPiece = Pieces_back->GetAfter(boardSize);
			break;
		default:
			return;
			break;
		}

		if (ProcessNumber(curPiece->GetScore() + nextPiece->GetScore()))
		{
			curPiece->SetScore(0);
			nextPiece->SetScore(nextPiece->GetScore() * 2);
		}

	} while (iterator < boardSize - 1);
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