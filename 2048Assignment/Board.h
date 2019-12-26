#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

#include "Direction.h"
#include "Piece.h"
#include "Process.h"

using namespace std;

class Board
{
public:
	Board();
	~Board();

	void DrawCoordinates();
	void DrawScores();
	void GenerateBoard();
	void SetRandomScores();
	void Swipe(Direction direction);
	void Undo();
	
	int GetScore();
	bool NoMoreMoves();
	Piece* GetPiece(int x, int y); 
		
private:
	bool _noMoreMoves;
	int _answerArraySize = 12;
	int _biggestNumber;
	int _boardSize;
	int _smallestNumber;
	int _totalPieces;	
	int _answerArray[12];
	Piece* _piecesFront;
	Piece* _piecesBack;

	void _PrimeAnswerArray();
	void _SetNextRandomPiece();
	bool _IsStillSameRow(Piece* curPiece, Piece* nextPiece, Direction dir);
	bool _ManageScores(Piece* curPiece, Piece* nextPiece);
	bool _ManageZeros(Piece* curPiece, Piece* nextPiece);
	bool _ProcessNumber(Piece* curPiece, Piece* nextPiece);
	bool _ProcessRow(Direction dir, Process proc);
	Piece* _GetFirstPiece(Direction dir);
};