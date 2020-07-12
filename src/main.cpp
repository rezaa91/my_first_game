#include <iostream>
#include "Game.h"

int main(int argc, char** argv)
{
	std::cout << "Beginning game..." << std::endl;
	Game game{};
	game.run();
	std::cout << "Game finished" << std::endl;

	return 0;
}
