#pragma once

class GameEngine;

class State
{
public:
	State(GameEngine* pEngine);
	State();
	~State();
	virtual void setBackground();
	virtual void initObjects();
private:
	GameEngine* m_pEngine;
};

