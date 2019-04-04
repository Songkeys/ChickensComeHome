#pragma once
#include "DisplayableObject.h"
#include "ImageManager.h"
class GameEngine;
class Chicken :
	public DisplayableObject
{
public:
	Chicken(int x, int y, GameEngine* pEngine, int w, int h);
	~Chicken();
	virtual void virtDraw() override;
	virtual void virtKeyDown(int iKeyCode) override;
private:
	SimpleImage image;
};

