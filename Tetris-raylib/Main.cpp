#include "Game.h"
#include <exception>
#include <iostream>

int main()
{
	Game game(600, 800);

	try {
		game.Run();
	}
	catch (std::exception& e)
	{
		std::cerr << "Error!, halting: " << e.what() << std::endl;
	}

	return 0;
}