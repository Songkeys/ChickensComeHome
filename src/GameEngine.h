#pragma once
#include "BaseEngine.h"
#include "MazeMap.h"
class State;

class GameEngine :
	public BaseEngine
{
public:
	GameEngine();
	~GameEngine();
	void virtSetupBackgroundBuffer();
	int virtInitialiseObjects();
	void setState(State* pState);
	MazeMap& getMazeMap() { return m_oMazeMap; }
private:
	State* m_pState;
	MazeMap m_oMazeMap;
};

