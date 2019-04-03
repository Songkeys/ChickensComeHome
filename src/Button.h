#pragma once
#include "DisplayableObject.h"
class Button :
	public DisplayableObject
{
public:
	Button(int x, int y, BaseEngine* pEngine, const char* pText, void(*onClick)());
	~Button();
	void virtDraw();
	//void virtMouseMoved(int iX, int iY);
	//void virtMouseDown(int iButton, int iX, int iY);
	void virtMouseUp(int iButton, int iX, int iY);
private:
	const char* m_pText;
	void (*m_pOnClick)();
};

