#pragma once

class GameEngine;

class State
{
public:
	State();
	~State();
	virtual void setBackground(GameEngine* pEngine);
};

