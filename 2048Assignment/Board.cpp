#include "Board.h"
#include <string>

Board::Board()
{
	Pieces = NULL;
	/*zeroZero = new Piece(0, 0);*/
}

Board::~Board()
{

}

Piece* Board::GetPiece(int x, int y)
{
	
	return new Piece();
}

void Board::Draw()
{

}

void Board::Swipe(Direction direction)
{

}

void Board::GenerateBoard()
{
	int boardSize = 4;
	int y = 0;
	int x = 0;

	Piece* temp;
	Piece* prev_piece;

	Pieces = new  Piece(x, y);
	x++;

	temp = Pieces;
	prev_piece = Pieces;

	for (int i = 0; i < boardSize * boardSize; i++)
	{
		if (i == 0) { continue; } //we already created this piece....
		if (i % boardSize == 0) { y++; x = 0; } //simulate new row

		temp = new Piece(x, y);
		
		temp->prevPiece = prev_piece;
		prev_piece->nextPiece = temp;

		x++;
		prev_piece = temp;
	}


	temp = Pieces;
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