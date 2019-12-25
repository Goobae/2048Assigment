#include <iostream>
#include <string>

#include "GReturn.h"
#include "Board.h"
#include "Game.h"

	int main() {

		Game* game = new Game();

		game->Initialize();
		game->Play();
		//game->TestFunc();

		char* a = new char('a');
		cin.read(a, 1);
		return 0;

	}

