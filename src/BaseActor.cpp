#include "BaseActor.h"

BaseActor::BaseActor(TextureManager* textureManager, const LoaderParams params)
	: id(params.id),
	transform(params.x, params.y),
	width(params.width),
	height(params.height),
	numberOfFrames(params.numberOfFrames),
	startingPosition(params.x, params.y)
{
	textureManager->loadTexture(params.path, params.id);
}

Vector2D BaseActor::getPosition()
{
	return transform;
}

SDL_Rect BaseActor::getRect()
{
	rect.w = width;
	rect.h = height;
	rect.x = transform.getX();
	rect.y = transform.getY();

	return rect;
}
