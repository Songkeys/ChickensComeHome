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
	void virtKeyDown(int iKeyCode);
	State* getState() { return m_pState; };
	void setState(State* pState);
	void virtDrawStringsOnTop() override;
	MazeMap* getMazeMap() { return m_pMazeMap; }
	void setMazeMap(MazeMap* pMazeMap) { m_pMazeMap = pMazeMap; }
private:
	State* m_pState;
	MazeMap* m_pMazeMap;
};

