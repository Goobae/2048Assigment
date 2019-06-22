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
		for (int b = 0; b < 3; b++)
		{
			Piece *tmp;
			tmp = new Piece();
		}
	}
}

