#include "states/PlayState.h"
#include <iostream>

void PlayState::onEnter()
{
	std::cout << "Entering play state..." << std::endl;
}

void PlayState::onExit()
{
	std::cout << "Exiting play state..." << std::endl;
}

void PlayState::render()
{
}
