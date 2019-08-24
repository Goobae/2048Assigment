#pragma once
#include "Direction.h"
#include "Piece.h"
#include <iostream>
#include <stdlib.h>     
#include <time.h>     
#include <string>
#include <vector>

using namespace std;

class Board
{
public:
	Board();
	~Board();

	void SetRandomScores();

	Piece* GetPiece(int x, int y);

	void DrawCoordinates();
	void DrawScores();
	void Swipe(Direction direction);

	
	void GenerateBoard();

private:
	int boardSize;

	Piece* Pieces_front;
	Piece* Pieces_back;

	void ProcessRow(Direction dir);
	void ProcessGroup(vector<Piece*> toProcess, int totalScore);
	bool ProcessNumber(int num);
};