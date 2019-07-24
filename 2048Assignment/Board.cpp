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
			//y = 1, x = 0
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
				else {
					zeroZero = t;
					prevFirstPiece = t;
				}

			}

			cout << " X:" << t->_x << "Y:" << t->_y << " ";

			if (x + 1 == boardSize) {
				cout << endl;
			}

			tmpPiece = t;
		}
	}
}


