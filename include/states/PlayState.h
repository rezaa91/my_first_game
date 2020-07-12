#pragma once

#include "states/IState.h"

class PlayState : public IState
{
public:
	virtual void onEnter();
	virtual void onExit();
};

