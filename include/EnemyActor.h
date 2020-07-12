#pragma once

#include "BaseActor.h"
#include "TextureManager.h"
#include "LoaderParams.h"

class EnemyActor : public BaseActor
{
protected:
	const int perimeterToCover;
	const int startingXPos;

	// enemies move left to right, if moving 'right' back to starting pos, set this to true
	bool isReturning = false;
public:
	EnemyActor(TextureManager* textureManager, const LoaderParams params, const int perimeterToCover = 200);
	virtual void update();
	virtual void render(TextureManager* textureManager);
};

