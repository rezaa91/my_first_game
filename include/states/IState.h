#pragma once
class IState
{
public:
	virtual void onEnter() = 0;
	virtual void onExit() = 0;
	virtual void render() = 0;
};
