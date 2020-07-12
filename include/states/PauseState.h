#pragma once

#include "states/IState.h"

class PauseState : public IState
{
public:
	virtual void onEnter();
	virtual void onExit();
};

