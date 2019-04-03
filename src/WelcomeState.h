#pragma once
#include "State.h"
class GameEngine;

class WelcomeState :
	public State
{
public:
	WelcomeState(GameEngine* pEngine);
	~WelcomeState();
	void setBackground();
	void initObjects();
private:
	GameEngine* m_pEngine;
};

