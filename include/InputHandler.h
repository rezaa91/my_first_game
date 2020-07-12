#pragma once

#include "SDL.h"

class InputHandler
{
private:
	const Uint8* keyStates;
public:
	InputHandler();
	void handleInput(SDL_Event& event);
	bool const isKeyDown(const SDL_Scancode key) const;
};
