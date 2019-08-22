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

	if (x >= boardSize || y >= boardSize || x < 0  || y  < 0) {
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

}

void Board::Swipe(Direction direction)
{


	//FIGUREO OTO HANDLE THIS
	for (int i = 0; i < boardSize*boardSize; i++)
	{

	}

	switch (direction)
	{
	case Left:
		//pieces.push_back();
		break;
	case Up:
		break;
	case Right:
		break;
	case Down:
		break;
	default:
		break;
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

	temp = Pieces_front;
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

void Board::ProcessRow(Piece* p, Direction dir)
{
	for (int a = 0; a < boardSize; a++) {
		ProcessRowHelper(p, dir);
	}
} 

void Board::ProcessRowHelper(Piece* curPiece, Direction dir)
{
	Piece* nextPiece;
	
	if (curPiece->nextPiece == nullptr || curPiece->prevPiece == nullptr)
		return;

	Piece* p = nextPiece;

	for (int a = 0; a < boardSize; a++)
	{
		//WE NEED TO SET NEXT PIECE TO BE THE ACTUAL NEXT 'PIECE'IN THE ROW
	}

	if (ProcessNumber(curPiece->GetScore() + nextPiece->GetScore()))
	{
		curPiece->SetScore(0);
		nextPiece->SetScore(nextPiece->GetScore() * 2);
	}

	return ProcessRowHelper(nextPiece, dir);
}

bool ProcessNumber(int num)
{
	if (num == 1 ||
		num % 2 == 0)
	{
		return true;
	}

	return false;

}