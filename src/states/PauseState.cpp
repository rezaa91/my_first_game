#include "states/PauseState.h"
#include <iostream>

void PauseState::onEnter()
{
	std::cout << "Entering pause state..." << std::endl;
}

void PauseState::onExit()
{
	std::cout << "Exiting pause state..." << std::endl;
}