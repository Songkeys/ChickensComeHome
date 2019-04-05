#pragma once
#include "State.h"
class GameEngine;
class StartState;
class PauseState :
	public State
{
public:
	PauseState(GameEngine* pEngine, StartState* pStartState);
	~PauseState();
	void drawStringsUnderneath() override;
	void onKeyDown(int iKeyCode);
private:
	GameEngine* m_pEngine;
	StartState* m_pStartState;
};

