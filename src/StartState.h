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
	void die();
	void getHome();
	void loseScore(int iScore);
	void drawStringOnTop() override;
	void onKeyDown(int iKeyCode);
private:
	GameEngine* m_pEngine;
	std::string m_strLevelName = "1"; // filename without ".txt" extension, under resources/maps folder
	int m_iRemainingChickenCount = 0;
	int m_iDiedChickenCount = 0;
	int m_iScore = 120;
};

