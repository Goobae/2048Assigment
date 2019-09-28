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
	UserRespone* input;
	DrawGame();
	do {
			input = GetUserInputAndClean();
			if (input->IsUndo)
			{
				board->Undo();
			}
			else if (input->Dir != Unknown)
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

UserRespone* Game::GetUserInputAndClean()
{
	return new UserRespone();	
}
