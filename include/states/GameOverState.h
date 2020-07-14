#pragma once

#include "states/IState.h"
#include "TextureManager.h"
#include "SDL.h"

class GameOverState : public IState
{
private:
	TextureManager* textureManager;
	SDL_Rect& gameCamera;
public:
	GameOverState(TextureManager* textureManager, SDL_Rect& gameCamera);
	virtual void onEnter();
	virtual void onExit();
	virtual void render();
};

