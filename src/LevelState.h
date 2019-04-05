#pragma once
#include "State.h"
class LevelState :
	public State
{
public:
	LevelState(GameEngine* pEngine);
	~LevelState();
	void setBackground();
	void initObjects();
	void onKeyDown(int iKeyCode);
	void drawStringOnTop();
private:
	GameEngine* m_pEngine;
	std::string m_strLevelName = "";
};

