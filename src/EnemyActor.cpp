#include "EnemyActor.h"
#include "Config.h"

EnemyActor::EnemyActor(TextureManager* textureManager, const LoaderParams params, const int perimeterToCover)
	:BaseActor(textureManager, params), startingXPos(params.x), perimeterToCover(perimeterToCover)
{
}

void EnemyActor::update(SDL_Rect* camera)
{
	if (lastCameraXPosition != camera->x) {
		transform.setX(transform.getX() + (lastCameraXPosition - camera->x));
	}

	lastCameraXPosition = camera->x;

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

	// once we reach our perimeter distance, we want to return. Or we go too much to the left
	if (transform.getX() == startingXPos - perimeterToCover || transform.getX() <= 0) {
		isReturning = true;
	}

	// if we are back at our starting position, then move back to the left to cover perimeter. Or we go too much to the right
	if (transform.getX() == startingXPos || transform.getX() > Config::WIDTH - width) {
		isReturning = false;
	}
}

void EnemyActor::render(TextureManager* textureManager)
{
	textureManager->draw(id, transform, width, height, flip, currentColumn, currentRow);
}
