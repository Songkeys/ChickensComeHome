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
	virtual void onKeyDown(int iKeyCode);
private:
	GameEngine* m_pEngine;
};

