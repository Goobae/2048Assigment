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


	bool userWillUndo = true;
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

		if (_board->NoMoreMoves())
		{
			userWillUndo == _WillUserUndo();
		}

	} while (input->IsContinue && userWillUndo);

	_GameOver();
}

void Game::Initialize()
{
	_board->GenerateBoard();
	_board->SetRandomScores();
}

void Game::_DrawControls()
{
	
}

void Game::_ClearScreen()
{
	cout << string(50, '\n');
}

void Game::_DrawGame()
{
	if (isLoaded)
	{
		_ClearScreen();
	}
	isLoaded = true;

	_DrawControls();

	cout << "Use Arrows to Move." << endl;
	cout << "'X' is Exit, and 'U' is Undo." << endl;
	cout << endl;
	cout<< "Current score is: " << (_board->GetScore() <= -1 ? 0 : _board->GetScore());
	cout << endl << endl;

	if (_board != nullptr)
	{
		_board->DrawScores();
	}
}

void Game::_GameOver()
{
	cout << endl;
	cout << "The Game Has Ended!" << endl;
	cout << "Your score was: " << _board->GetScore() << endl;
}

bool Game::_WillUserUndo()
{
	if (_board == nullptr)
	{
		return false;
	}
	
	cout << endl;
	cout << "There are no more moves, please Undo ('U') or Exit ('X')" << endl;

	UserResponse* input;
	do {
		input = _GetUserInputAndClean();
		if (input->ResponseType == IsUndo)
		{
			_board->Undo();

			_DrawGame();

			return true;
		}
	} while (input->IsContinue);

	return false;
}

UserResponse* Game::_GetUserInputAndClean()
{
	return new UserResponse();	
}