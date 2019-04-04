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
	int iNextScreenX = m_iCurrentScreenX;
	int iNextScreenY = m_iCurrentScreenY;

	// move the chicken
	switch (iKeyCode)
	{
	case SDLK_UP:
		iNextScreenY -= m_iDrawHeight;
		break;
	case SDLK_DOWN:
		iNextScreenY += m_iDrawHeight;
		break;
	case SDLK_LEFT:
		iNextScreenX -= m_iDrawWidth;
		break;
	case SDLK_RIGHT:
		iNextScreenX += m_iDrawWidth;
		break;
	default:
		break;
	}

	MazeMap* pMazeMap = (static_cast<GameEngine*>(getEngine()))->getMazeMap();
	int iNextMapX = pMazeMap->getMapXForScreenX(iNextScreenX);
	int iNextMapY = pMazeMap->getMapYForScreenY(iNextScreenY);
	int iNextValue = pMazeMap->getMapValue(iNextMapX, iNextMapY);
	std::cout << iNextValue;
	switch (iNextValue)
	{
	case 0: // empty ground
	{
		// reset previous map value
		int iCurrentMapX = pMazeMap->getMapXForScreenX(m_iCurrentScreenX);
		int iCurrentMapY = pMazeMap->getMapYForScreenY(m_iCurrentScreenY);
		pMazeMap->setMapValue(iCurrentMapX, iCurrentMapY, 0);
		// move
		m_iCurrentScreenX = iNextScreenX;
		m_iCurrentScreenY = iNextScreenY;
		// update next map value
		pMazeMap->setMapValue(iNextMapX, iNextMapY, 9);
	}
		break;
	case 9: // chicken
	{
		// check next next position until wall

	}
	default:
		break;
	}
	redrawDisplay();
}
