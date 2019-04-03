#pragma once
#include "State.h"
class GameEngine;

class StartState :
	public State
{
public:
	StartState(GameEngine* pEngine);
	~StartState();
	void setBackground();
	void initObjects();
private:
	GameEngine* m_pEngine;
};

