#include "PlayerActor.h"
#include "Config.h"

void PlayerActor::jump()
{
	// can't initiate a new jump if player still jumping
	if (isJumping) {
		return;
	}

	isJumping = true;
	std::cout << "Jumping" << std::endl;
}

PlayerActor::PlayerActor(TextureManager* textureManager, InputHandler* inputHandler,const LoaderParams params)
	: inputHandler(inputHandler), BaseActor(textureManager, params), speed(2, 2), acceleration(1, 0)
{
}

void PlayerActor::update()
{
	currentRow = 0;

	if (inputHandler->isKeyDown(SDL_SCANCODE_LSHIFT)) {
		acceleration = 4;
	} else {
		acceleration = 2;
	}

	if (inputHandler->isKeyDown(SDL_SCANCODE_A)) {
		flip = SDL_FLIP_HORIZONTAL;

		if (transform.getX() >= 0) {
			currentRow = (int)(SDL_GetTicks() / 100) % numberOfFrames;
			transform.setX(transform.getX() - acceleration.getX());
		}
	}

	if (inputHandler->isKeyDown(SDL_SCANCODE_D)) {
		flip = SDL_FLIP_NONE;

		if (transform.getX() <= (Config::WIDTH - width)) {
			currentRow = (int)(SDL_GetTicks() / 100) % numberOfFrames;
			transform.setX(transform.getX() + acceleration.getX());
		}
	}

	// if left and right keys both pressed down, then prevent animation in idle state
	if (inputHandler->isKeyDown(SDL_SCANCODE_A) && inputHandler->isKeyDown(SDL_SCANCODE_D)) {
		currentRow = 0;
	}

	if (inputHandler->isKeyDown(SDL_SCANCODE_SPACE)) {
		this->jump();
	}
}

void PlayerActor::render(TextureManager* textureManager)
{
	textureManager->draw(id, transform, width, height, flip, currentColumn, currentRow);
}
