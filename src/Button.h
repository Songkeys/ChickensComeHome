#pragma once
#include "DisplayableObject.h"
class GameEngine;
class Button :
	public DisplayableObject
{
public:
	Button(int x, int y, GameEngine* pEngine, const char* pText, void(*onClick)(GameEngine*));
	~Button();
	void virtDraw();
	//void virtMouseMoved(int iX, int iY);
	//void virtMouseDown(int iButton, int iX, int iY);
	void virtMouseUp(int iButton, int iX, int iY);
private:
	const char* m_pText;
	GameEngine* m_pEngine;
	void (*m_pOnClick)(GameEngine*);
};

