#pragma once
#include "Direction.h"
#include "Piece.h"
#include <iostream>
#include <time.h>     
#include <string>
#include <vector>
#include <functional>
#include "Process.h"


using namespace std::placeholders;

class Board
{
public:
	Board();
	~Board();

	void SetRandomScores();

	Piece* GetPiece(int x, int y); 

	void DrawCoordinates();
	void DrawScores();
	int GetScore();
	void Swipe(Direction direction);
	void Undo();
	void Test();
	void Test2();
	
	bool NoMoreMoves();
	
	void GenerateBoard();

	void Test(Piece* p);
private:
	int boardSize;
	int totalPieces;

	int smallestNumber;
	int biggestNumber;

	Piece* GetFirstPieceForDirectionAndProcess(Direction dir, Process proc);

	bool noMoreMoves;

	Piece* Pieces_front;
	Piece* Pieces_back;

	void ProcessRow(Direction dir, Process proc);

	bool IsStillSameRow(Piece* curPiece, Piece* nextPiece, Direction dir);

	bool ManageZeros(Piece* curPiece, Piece* nextPiece);
	bool ManageScores(Piece* curPiece, Piece* nextPiece);




	void SetScores();

	Direction GetOppoDir(Direction dir);
	void SetNextRandomPiece();
	bool ProcessNumber(int num);

	
};






/* we need to work on the following items:
	-Make sure we correctly handle moving numbers over if there are zeros
		-create code in ProcessRow
		-debug
-correctly handle seeing if there are any moves left
	-Check to see if a piece next to it can handle the number
		-create a function in process row that checks if current piece != next piece
		-debug
	-Validate the baord to see if it has any moves left
		-process row
		-test

*/







































// in hawaii test out hunger to see on average what times of the day you get hungry. See if the whole breakfast/lunch/dinner thing is real and what times work for you.


/*
think about the how insane having a static time with slices, and all the atoms stopped in time, in another direction, that would be sick. At that point,what is our minds, whats the point of reason, whats the point of God, feeling?
-> For the joy of it all, and how it all comes together to form this massive collection of instances where we all are feeling, being connected yet disconnected around stupid concepts that we create. Life is beautiful, insanely perfect.


/*
think about the how insane having a static time with slices
and all the atoms stopped in time. 

Standing all still not knowing what we are or who we are, 
or which this hunk of atoms we deem ourselves
is going to do or think next.

At that point
what is our minds
whats the point of reason
whats the point of God,
feeling?

->
For the joy of it all
and how it all comes together to form this massive collection of instances
where we all are feeling, being connected 
yet disconnected around stupid concepts that we create. 

Life is beautiful, insanely perfect.
																																																										   */

//look at animals for inspiration^^