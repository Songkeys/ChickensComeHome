#pragma once
#include "DisplayableObject.h"
#include "ImageManager.h"
class GameEngine;
class Chicken :
	public DisplayableObject
{
public:
	Chicken(int index, int x, int y, GameEngine* pEngine, int w, int h);
	~Chicken();
	virtual void virtDraw() override;
	virtual void virtKeyDown(int iKeyCode) override;
	virtual void virtDoUpdate(int iCurrentTime) override;
	virtual void virtMouseUp(int iButton, int iX, int iY) override {};
private:
	bool isGoingToTouchWall(int iKeyCode, int iCurrentMapX, int iCurrentMapY);
	SimpleImage image;
	int m_iIndex;
};

