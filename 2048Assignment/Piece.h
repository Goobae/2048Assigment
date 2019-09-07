#pragma once
#include "Direction.h"
#include <stack>  
#include <string>

using namespace std;

class Piece
{
public:
	Piece();
	Piece(int x, int y);
	~Piece();

	int X;
	int Y;
	int GetScore();
	int GetId();

	void SetScore(int score);
	void SetId(int id);
	void DrawScore();
	void DrawCoordinates();
	void UndoScore();

	Piece* GetAfter(int numIterations);
	
	Piece* nextPiece;
	Piece* prevPiece;

private:
	int currentScore;
	int _x;
	int _y;
	stack<int> _prevScores ;
	int _id;
};