#include "EnemyActor.h"

EnemyActor::EnemyActor(TextureManager* textureManager, const LoaderParams params, const int perimeterToCover)
	:BaseActor(textureManager, params), startingXPos(params.x), perimeterToCover(perimeterToCover)
{
}

void EnemyActor::update()
{
	currentRow = (int)((SDL_GetTicks() / 100) % numberOfFrames);

	// return back to starting position
	if (isReturning) {
		flip = SDL_FLIP_NONE;
		transform.setX(transform.getX() + 1);
	}
	// move to the left until perimeter reached, then return
	else {
		flip = SDL_FLIP_HORIZONTAL;
		transform.setX(transform.getX() - 1);
	}

	// once we reach our perimeter distance, we want to return
	if (transform.getX() == startingXPos - perimeterToCover) {
		isReturning = true;
	}

	// if we are back at our starting position, then move back to the left to cover perimeter
	if (transform.getX() == startingXPos) {
		isReturning = false;
	}
}

void EnemyActor::render(TextureManager* textureManager)
{
	textureManager->draw(id, transform, width, height, flip, currentColumn, currentRow);
}
