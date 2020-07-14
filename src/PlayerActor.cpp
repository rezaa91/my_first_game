#include "PlayerActor.h"
#include "Config.h"

void PlayerActor::jump()
{
	const int heightToJump = 60;
	const int startingYPos = startingPosition.getY();

	if (!isJumping) {
		if (transform.getY() != startingYPos) {
			transform.setY(transform.getY() + 3);
		}

		return;
	}


	if (startingYPos - transform.getY() <= heightToJump) {
		transform.setY(transform.getY() - 3);
	}
	
	if (startingYPos - transform.getY() == heightToJump) {
		// we have reached peak of jump
		isJumping = false;
	}

}

PlayerActor::PlayerActor(TextureManager* textureManager, InputHandler* inputHandler, const LoaderParams params)
	: inputHandler(inputHandler), BaseActor(textureManager, params), speed(2, 2), acceleration(1, 0), isJumping(false)
{
}

void PlayerActor::update(SDL_Rect* camera)
{
	this->jump();

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

		// only allow movement to the right, up to the right-side of the screen (minus the textures width, so not to go off-screen)
		if (transform.getX() < (Config::WIDTH + camera->w - width)) {
			currentRow = (int)(SDL_GetTicks() / 100) % numberOfFrames;
			transform.setX(transform.getX() + acceleration.getX());
		}
	}

	// if left and right keys both pressed down, then prevent animation in idle state
	if (inputHandler->isKeyDown(SDL_SCANCODE_A) && inputHandler->isKeyDown(SDL_SCANCODE_D)) {
		currentRow = 0;
	}

	// only allow player to jump if grounded
	if (inputHandler->isKeyDown(SDL_SCANCODE_SPACE) && transform.getY() == startingPosition.getY()) {
		isJumping = true;
	}
}

void PlayerActor::render(TextureManager* textureManager)
{
	textureManager->draw(id, transform, width, height, flip, currentColumn, currentRow);
}
