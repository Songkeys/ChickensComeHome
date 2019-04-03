#pragma once
#include "State.h"
class WelcomeState :
	public State
{
public:
	WelcomeState();
	~WelcomeState();
	void setBackground(GameEngine* pEngine);
	void initObjects(GameEngine* pEngine);
};

