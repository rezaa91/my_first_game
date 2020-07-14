#include "states\StateManager.h"

StateManager::StateManager(IState* state)
{
	states.push(state);
	state->onEnter();
}

void StateManager::pushState(IState* state)
{
	auto& lastState = states.top();
	lastState->onExit();
	states.pop();

	states.push(state);
	state->onEnter();
}

void StateManager::render()
{
	states.top()->render();
}
