#include "states/PauseState.h"
#include <iostream>
#include "Vector2D.h"
#include "Config.h"

PauseState::PauseState(TextureManager* textureManager, SDL_Rect& gameCamera)
	:textureManager(textureManager), gameCamera(gameCamera)
{
	textureManager->loadTexture("./assets/paused.png", "paused");
}

void PauseState::onEnter()
{
	std::cout << "Entering pause state..." << std::endl;
}

void PauseState::onExit()
{
	textureManager->removeTexture("paused");
}

void PauseState::render()
{
	const int width = 192;
	const int height = 64;
	const int midX = (Config::WIDTH / 2) - (width / 2) + gameCamera.x;
	const int midY = (Config::HEIGHT / 2) - (height / 2);

	textureManager->draw("paused", Vector2D{ midX, midY }, width, height);
}
