#include "header.h"
#include "Chicken.h"
#include "GameEngine.h"

Chicken::Chicken(int x, int y, GameEngine* pEngine, int w, int h)
	: DisplayableObject(x, y, (BaseEngine*) pEngine, w, h, true),
	image(pEngine->loadImage("resources/images/chicken.png", false))
{
	m_iDrawWidth = w;
	m_iDrawHeight = h;
	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;
}


Chicken::~Chicken()
{
}

void Chicken::virtDraw()
{
	if (isVisible())
	{
		image.renderImage(getEngine()->getForegroundSurface(),
			0,
			0,
			m_iCurrentScreenX + m_iStartDrawPosX,
			m_iCurrentScreenY + m_iStartDrawPosY,
			m_iDrawWidth,
			m_iDrawHeight);
	}
}