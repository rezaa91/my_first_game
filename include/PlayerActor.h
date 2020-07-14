#pragma once

#include <vector>
#include "SDL.h"
#include "BaseActor.h"
#include "Vector2D.h"
#include "InputHandler.h"
#include "LoaderParams.h"
#include "TextureManager.h"

class PlayerActor : public BaseActor
{
private:
	InputHandler* inputHandler;
	Vector2D speed;
	Vector2D acceleration;
	bool isJumping = false;
	void jump();

public:
	PlayerActor(TextureManager* textureManager, InputHandler* inputHandler, const LoaderParams params);
	virtual void update(SDL_Rect* camera);
	virtual void render(TextureManager* textureManager);
};

