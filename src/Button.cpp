#include "header.h"
#include "Button.h"
#include "BaseEngine.h"
#include <string>

const int FontSize = 16; // the default font size in px the framework gives
const int padding = 10;

Button::Button(int x, int y, GameEngine* pEngine, const char* pText, void (*onClick)(GameEngine*))
	: DisplayableObject(x, y, (BaseEngine*) pEngine, 100, 100, true), m_pText(pText), m_pEngine(pEngine), m_pOnClick(onClick)
{
}


Button::~Button()
{
}


void Button::virtDraw()
{
	getEngine()->drawForegroundString(m_iCurrentScreenX, m_iCurrentScreenY, m_pText, 0xffffff, NULL);
}

void Button::virtMouseUp(int iButton, int iX, int iY)
{
	if (iX > m_iCurrentScreenX - padding
		&& iX < m_iCurrentScreenX + FontSize * strlen(m_pText) + padding
		&& iY > m_iCurrentScreenY - padding
		&& iY < m_iCurrentScreenY + FontSize + padding)
	{
		m_pOnClick(m_pEngine);
	}
}
