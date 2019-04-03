#pragma once
#include "BaseEngine.h"

class State;

class GameEngine :
	public BaseEngine
{
public:
	GameEngine();
	~GameEngine();
	void virtSetupBackgroundBuffer();
private:
	State* m_pState;
};

