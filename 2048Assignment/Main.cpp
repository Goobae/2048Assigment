#include <iostream>
#include <string>

#include "GReturn.h"
#include "SwipeBehavior.h"
#include "Board.h"
#include "Game.h"

	int main() {

		Game* game = new Game();
		game->Initialize();
		game->Play();

		char* a = new char('a');
		cin.read(a, 1);
		return 0;

	}

