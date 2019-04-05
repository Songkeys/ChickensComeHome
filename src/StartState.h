#pragma once
#include "State.h"
class GameEngine;

class StartState :
	public State
{
public:
	StartState(GameEngine* pEngine);
	StartState(GameEngine* pEngine, std::string strLevelName);
	~StartState();
	void setBackground();
	void initObjects();
private:
	GameEngine* m_pEngine;
	std::string m_strLevelName = "1"; // filename without ".txt" extension, under resources/maps folder
};

