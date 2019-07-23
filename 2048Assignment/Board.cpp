#include "Board.h"

Board::Board()
{
	zeroZero = new Piece(0,0);
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
	int boardSize = 4;

	Piece* tmpPiece = zeroZero;
	Piece* prevFirstPiece = zeroZero;

	//starting from the bottom left -> top right
	for (int y = 0; y < boardSize; y++)
	{
		if (y != 0)
		{
			prevFirstPiece = tmpPiece;
		}

		for (int x = 0; x < boardSize; x++)
		{
			//each game always has a bottom left piece created, so skip it
			if (x == 0 && y == 0) continue;

			//new temp piece
			Piece* t = new Piece(x,y);

			if (x != 0) {
				t->westPiece = tmpPiece;
				tmpPiece->eastPiece = t;
			}

			if (y != 0)
			{
				t->southPiece = tmpPiece->southPiece->eastPiece;
				t->southPiece->northPiece = t;
			}
			////bottom and top rule
			//if (y != 0 && y != boardSize - 1 && x != 0 && x != boardSize - 1)
			//{
			//	t->southPiece = tmpPiece->southPiece->eastPiece;
			//	t->southPiece->northPiece = t;
			//}

			tmpPiece = t;
		}
	}
}


