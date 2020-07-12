#pragma once

#include <iostream>
#include <vector>
#include "SDL.h"
#include "BaseActor.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "states\StateManager.h"

class Game
{
private:
	SDL_Renderer* renderer = nullptr;
	SDL_Window* window = nullptr;
	bool isRunning = false;
	std::vector<BaseActor*> gameObjects;
	InputHandler* inputHandler = nullptr;
	TextureManager* textureManager = nullptr;
	StateManager* stateManager = nullptr;
	bool isPaused = true;

	void const createGameObjects();
public:
	Game();
	~Game();
	void update();
	void render();
	void handleEvents();
	void run();
};

