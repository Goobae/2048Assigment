#include "Game.h"

Game::Game()
{
	_board = new Board();
}

Game::~Game()
{
	_board = nullptr;
}

void Game::Play()
{
	UserResponse* input;
	_DrawGame();
	do {
		input = _GetUserInputAndClean();
		if (input->ResponseType == IsUndo)
		{
			_board->Undo();
		}
		else if (input->ResponseType == IsTest)
		{
		}
		else if (input->ResponseType == IsMove)
		{
			_board->Swipe(input->Dir);
		}

		_DrawGame();

	} while (input->IsContinue && !_board->NoMoreMoves());

	_GameOver();
}

void Game::Initialize()
{
	_board->GenerateBoard();
	_board->SetRandomScores();
}

void Game::_ClearScreen()
{
	system("CLS");
}

void Game::_DrawGame()
{
	_ClearScreen();

	if (_board != nullptr)
	{
		_board->DrawScores();
	}
}

void Game::_GameOver()
{
	_ClearScreen();

	puts("The Game Has Ended!");
	puts("Your score was: " + _board->GetScore());
}

UserResponse* Game::_GetUserInputAndClean()
{
	return new UserResponse();	
}