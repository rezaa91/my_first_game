#pragma once

#include <iostream>
#include <stack>
#include "IState.h"

class StateManager
{
private:
	std::stack<IState*> states;
public:
	StateManager(IState* state);
	void pushState(IState* state);
	void render();
};

