#include "Board.h"
#include <string>

Board::Board()
{
	zeroZero = new Piece(0, 0);
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

			Piece* t = new Piece(x, y);
			//y = 1, x = 1 errors out (t-> south piece is null at 56)
			// tmp-> south piece is null
			// make sure y = 1, x = 0 is linked to bot row piece;
			if (y != 0 && x != 0)
			{
				t->westPiece = tmpPiece;
				tmpPiece->eastPiece = t;

				t->southPiece = tmpPiece->southPiece->eastPiece;
				t->southPiece->northPiece = t;
			}
			else
			{
				if (x != 0) {
					t->southPiece = prevFirstPiece;
					prevFirstPiece->northPiece = t;
				}
				else
				{
					if (y == 0)
					{
						zeroZero = t;
					}
					else
					{
						t->southPiece = prevFirstPiece;
						prevFirstPiece->northPiece = t;
						
					}

					prevFirstPiece = t;
				}
			}

			cout << " X:" << t->_x << "Y:" << t->_y << " ";

			if (x + 1 == boardSize) {
				cout << endl;
			}

			if (x == 0)
			{
				tmpPiece = prevFirstPiece;
			}
			else
			{
				tmpPiece = t;
			}
		}
	}
}


