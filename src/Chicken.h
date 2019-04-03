#pragma once
#include "DisplayableObject.h"
class GameEngine;
class Chicken :
	public DisplayableObject
{
public:
	Chicken(int x, int y, GameEngine* pEngine, int w, int h);
	~Chicken();
};

