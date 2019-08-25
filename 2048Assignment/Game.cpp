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
			board->Swipe(input->Dir);
			DrawGame();
		
	} while (input->IsValidResponse || input->IsContinue);

	puts("The Game Has Ended!");
}

void Game::DrawGame()
{
	system("CLS");

	if (board != nullptr)
	{
		board->DrawScores();
	}
}

void Game::IsGameOver()
{
}

UserRespone* Game::GetUserInputAndClean()
{
	return new UserRespone();	
}
