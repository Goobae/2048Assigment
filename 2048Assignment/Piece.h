#pragma once
#include <iostream>
#include <stack>  
#include <string>

#include "Direction.h"
#include "Process.h"

using namespace std;

class Piece
{
public:
	Piece(int x, int y);
	~Piece();

	int X;
	int Y;
	Piece* NextPiece;
	Piece* PrevPiece;

	void DrawCoordinates();
	void DrawScore();
	void SetId(int id);
	void SetScore(int score);
	void UndoScore();
	int GetId();
	int GetScore();
	Piece* GetNextPiece(Direction dir, int boardSize);
	Piece* GetNextRowPiece(Direction dir, int boardSize);

private:
	int _currentScore;
	int _id;
	int _x;
	int _y;
	stack<int> _prevScores;

	Piece* _GetAfter(int numIterations);	
};