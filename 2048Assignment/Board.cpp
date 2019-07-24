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
		for (int x = 0; x < boardSize; x++)
		{
			if (x != 0 || y != 0) {

				Piece* t = new Piece(x, y);

				if (x != 0) {
					t->westPiece = tmpPiece;
					tmpPiece->eastPiece = t;
				}
				else
				{ 	
					prevFirstPiece = t;
				}

				if (y != 0)
				{
					//define tmpPiece.easetPiece !!!!!
					t->southPiece = tmpPiece->southPiece->eastPiece;
					t->southPiece->northPiece = t;
				}

				tmpPiece = t;
			}			
		}
	}
}


