#include "BaseActor.h"

BaseActor::BaseActor(TextureManager* textureManager, const LoaderParams params)
	: id(params.id), transform(params.x, params.y), width(params.width), height(params.height), numberOfFrames(params.numberOfFrames)
{
	textureManager->loadTexture(params.path, params.id);
}
