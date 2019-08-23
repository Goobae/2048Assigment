#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Initialize()
{
	board = new Board();
	board->GenerateBoard();
}

void Game::Play()
{
	Direction input;

	do {
		DrawGame();
		input = GetUserInputAndClean();
	} while (input != Unknown);
}

void Game::DrawGame()
{
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	//std::cout << "\x1B[2J\x1B[H";

	if (board != nullptr)
	{
		board->Draw();
	}
}

Direction Game::GetUserInputAndClean()
{
	//string input = getchar();

	

	return Unknown;
}
