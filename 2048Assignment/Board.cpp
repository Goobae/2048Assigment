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
	Piece* tmpPiece = topLeftPiece;
	Piece* prevFirstPiece = topLeftPiece;

	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			Piece* t = new Piece();

			//take care of left and right pieces
			if (b != 0)
			{
				t->eastPiece = tmpPiece;
				tmpPiece->westPiece = t;
			}

			//take care of top pieces and south
			if (a != 0) {
				t->northPiece = tmpPiece->northPiece->eastPiece;
				tmpPiece->northPiece->eastPiece->southPiece = t;
			}

			if (b == 0) {
				prevFirstPiece = t;
			}

			tmpPiece = t;
		}

		if (a < 4)
		{
			tmpPiece = new Piece();
			prevFirstPiece->southPiece = tmpPiece;
			tmpPiece->northPiece = prevFirstPiece;
		}
	}
}


