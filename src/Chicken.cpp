#include "header.h"
#include "Chicken.h"



Chicken::Chicken(int x, int y, GameEngine* pEngine, int w, int h)
	: DisplayableObject(x, y, (BaseEngine*) pEngine, w, h, true)
{
}


Chicken::~Chicken()
{
}
