#include "states\GameOverState.h"
#include <iostream>
#include "Vector2D.h"
#include "Config.h"

GameOverState::GameOverState(TextureManager* textureManager, SDL_Rect& gameCamera)
	: textureManager(textureManager), gameCamera(gameCamera)
{
	textureManager->loadTexture("./assets/gameOver.png", "gameOver");
}

void GameOverState::onEnter()
{
	std::cout << "Entering Game Over State" << std::endl;
}

void GameOverState::onExit()
{
	std::cout << "Exiting Game Over State" << std::endl;
}

void GameOverState::render()
{
	const int textureWidth = 192;
	const int textureHeight = 64;
	const int x = Config::WIDTH / 2 - (textureWidth / 2) + gameCamera.x;
	const int y = Config::HEIGHT / 2 - (textureHeight / 2);
	textureManager->draw("gameOver", Vector2D{x, y}, textureWidth, textureHeight);
}
