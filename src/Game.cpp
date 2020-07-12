#include "Game.h"
#include "Config.h"
#include "PlayerActor.h"
#include "EnemyActor.h"
#include "LoaderParams.h"
#include "states\PauseState.h"
#include "states\PlayState.h"

void const Game::createGameObjects()
{
	PlayerActor* player = new PlayerActor{ textureManager, inputHandler, LoaderParams{ "./assets/player.png", "player", 32, 32, 60, 60, 3 } };
	gameObjects.push_back(player);

	EnemyActor* enemy1 = new EnemyActor{ textureManager, LoaderParams{"./assets/player.png", "enemy", 32, 32, 200, 60, 3} };
	gameObjects.push_back(enemy1);

	EnemyActor* enemy2 = new EnemyActor{ textureManager, LoaderParams{"./assets/player.png", "enemy", 32, 32, 600, 60, 3}, 150 };
	gameObjects.push_back(enemy2);
}

Game::Game()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "Unable to initialize SDL" << std::endl;
	}

	window = SDL_CreateWindow(Config::TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Config::WIDTH, Config::HEIGHT, 0);

	if (window == 0) {
		std::cerr << "Unable to create window" << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (renderer == 0) {
		std::cerr << "Unable to create renderer" << std::endl;
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	isRunning = true;
	inputHandler = new InputHandler{};
	textureManager = new TextureManager{renderer};
	stateManager = new StateManager(new PauseState());

	this->createGameObjects();
}

Game::~Game()
{
	std::cout << "Cleaning up..." << std::endl;

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void Game::update()
{
	// we don't want to update our game objects if we are in a paused state
	if (!isPaused) {
		for (auto& object : gameObjects)
		{
			object->update();
		}
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);

	for (auto& object : gameObjects)
	{
		object->render(textureManager);
	}

	SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYUP:
		// escape button used to toggle between play and paused states
		if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
			isPaused ? stateManager->pushState(new PlayState()) : stateManager->pushState(new PauseState());
			isPaused = !isPaused;
		}
	}

	inputHandler->handleInput(event);
}

void Game::run()
{
	const int frameDelay = 1000 / Config::FPS;

	while (isRunning) {
		const Uint32 frameStart = SDL_GetTicks();

		this->handleEvents();
		this->update();
		this->render();

		const Uint32 frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < frameDelay) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
}
