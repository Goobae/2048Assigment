#include "Game.h"

Game::Game()
{
	board = new Board();
}

Game::~Game()
{
}

void Game::Initialize()
{
	board->GenerateBoard();
	board->SetRandomScores();
}

void Game::Play()
{
	UserResponse* input;
	DrawGame();
	do {
			input = GetUserInputAndClean();
			if (input->ResponseType == IsUndo)
			{
				board->Undo();
			}
			else if (input->ResponseType == IsTest)
			{
				Test();
			}
			else if (input->Dir == IsMove)
			{
				board->Swipe(input->Dir);
			}
						
			DrawGame();
		
	} while (input->IsContinue);

	GameOver();
}

void Game::DrawGame()
{
	ClearScreen();

	if (board != nullptr)
	{
		board->DrawScores();
	}
}

void Game::GameOver()
{
	ClearScreen();

	puts("The Game Has Ended!");
}

void Game::ClearScreen()
{
	system("CLS");
}

void Game::Test()
{
	board->Test();
}

UserResponse* Game::GetUserInputAndClean()
{
	return new UserResponse();	
}
