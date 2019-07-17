#include "Board.h"

Board::Board()
{
	topLeftPiece = new Piece();
}

Board::~Board()
{

}

void Board::Draw() 
{

}

void Board::Swipe(Direction direction)
{

}

void Board::GenerateBoard()
{
	for (int a = 0; a < 4; a++)
	{
		Piece* tmp = a == 0 ? topLeftPiece : new Piece();

		for (int b = 0; b < 3; b++)
		{
			Piece* t = new Piece();
			//take care of top pieces
			if (a == 0) {
				

			}
		}
	}
}

