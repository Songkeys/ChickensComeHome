#include "header.h"
#include "Chicken.h"
#include "GameEngine.h"

Chicken::Chicken(int x, int y, GameEngine* pEngine, int w, int h)
	: DisplayableObject(x, y, (BaseEngine*) pEngine, w, h, true)
{
	m_iDrawWidth = w;
	m_iDrawHeight = h;
	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;
	image = pEngine->loadImage("resources/images/chicken.png", false).resizeTo(w, h);
}


Chicken::~Chicken()
{
}

void Chicken::virtDraw()
{
	// draw the chicken
	if (isVisible())
	{
		image.renderImageWithMask(getEngine()->getForegroundSurface(),
			0,
			0,
			m_iCurrentScreenX + m_iStartDrawPosX,
			m_iCurrentScreenY + m_iStartDrawPosY,
			m_iDrawWidth,
			m_iDrawHeight);
	}
}

void Chicken::virtKeyDown(int iKeyCode)
{
	// move the chicken
	switch (iKeyCode)
	{
	case SDLK_UP:
		m_iCurrentScreenY -= m_iDrawHeight;
		break;
	case SDLK_DOWN:
		m_iCurrentScreenY += m_iDrawHeight;
		break;
	case SDLK_LEFT:
		m_iCurrentScreenX -= m_iDrawHeight;
		break;
	case SDLK_RIGHT:
		m_iCurrentScreenX += m_iDrawHeight;
		break;
	default:
		break;
	}
	redrawDisplay();
}