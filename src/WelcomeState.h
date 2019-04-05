#pragma once
#include "State.h"
class GameEngine;

class WelcomeState :
	public State
{
public:
	WelcomeState(GameEngine* pEngine);
	WelcomeState(GameEngine* pEngine, int iLastScore);
	~WelcomeState();
	void setBackground();
	void initObjects();
private:
	GameEngine* m_pEngine;
	int m_iLastScore = 0;
};

