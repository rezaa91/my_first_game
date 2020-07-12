#include "InputHandler.h"

#include <iostream>

InputHandler::InputHandler()
{
	keyStates = SDL_GetKeyboardState(NULL);
}

void InputHandler::handleInput(SDL_Event& event)
{
	switch (event.type) {
	case SDL_MOUSEBUTTONDOWN:
		std::cout << "MOUSE BUTTON DOWN" << std::endl;
		break;
	case SDL_MOUSEBUTTONUP:
		std::cout << "MOUSE BUTTON UP" << std::endl;
		break;
	}
}

bool const InputHandler::isKeyDown(const SDL_Scancode key) const
{
	return keyStates[key] == 1;
}

