#include "header.h"
#include "Chicken.h"
#include "GameEngine.h"
#include "StartState.h"

Chicken::Chicken(int index, int x, int y, GameEngine* pEngine, int w, int h)
	: DisplayableObject(x, y, (BaseEngine*) pEngine, w, h, true), m_iIndex(index)
{
	m_iDrawWidth = w;
	m_iDrawHeight = h;
	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;
	image = pEngine->loadImage("resources/images/chicken_0.png", true).resizeTo(w, h);
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
		//getEngine()->drawForegroundString(m_iCurrentScreenX, m_iCurrentScreenY, std::to_string(m_iIndex).c_str(), 0, 0);
	}
}

void Chicken::virtKeyDown(int iKeyCode)
{
	if (m_pEngine->isPaused())
	{
		return;
	}

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
		return; // if entering from level state, the iKeyCode will be passed here...
		break;
	}

	GameEngine* pGameEngine = static_cast<GameEngine*>(getEngine());
	MazeMap* pMazeMap = pGameEngine->getMazeMap();
	int iNextMapX = pMazeMap->getMapXForScreenX(iNextScreenX);
	int iNextMapY = pMazeMap->getMapYForScreenY(iNextScreenY);
	int iNextValue = pMazeMap->getMapValue(iNextMapX, iNextMapY);
	switch (iNextValue)
	{
	case 0: // empty ground
	case 9: // chicken
	case 4: // egg
	case 3: // home
	case 2: // thorn
	{
		if (iNextValue >= 9 && isGoingToTouchWall(iKeyCode, iNextMapX, iNextMapY)) // chicken with wall
		{
			break; // stop
		}

		// keep moving

		// before move: reset current position
		int iCurrentMapX = pMazeMap->getMapXForScreenX(m_iCurrentScreenX + 10);
		int iCurrentMapY = pMazeMap->getMapYForScreenY(m_iCurrentScreenY + 10);
		if (pMazeMap->getMapValue(iCurrentMapX, iCurrentMapY) - 9 <= 0)
		{
			pMazeMap->setMapValue(iCurrentMapX, iCurrentMapY, 0);
		}
		else
		{
			pMazeMap->setMapValue(iCurrentMapX, iCurrentMapY, pMazeMap->getMapValue(iCurrentMapX, iCurrentMapY) - 9);
		}
		
		// move
		m_iCurrentScreenX = iNextScreenX;
		m_iCurrentScreenY = iNextScreenY;
		// after move: handle move result
		if (iNextValue == 2) // die
		{
			getEngine()->removeDisplayableObject(this);
			static_cast<StartState*>(pGameEngine->getState())->die();
		}
		else if (iNextValue == 3) // get home
		{
			getEngine()->removeDisplayableObject(this);
			static_cast<StartState*>(pGameEngine->getState())->getHome();
		}
		else if (iNextValue == 4) // get egg
		{
			pMazeMap->setAndRedrawMapValueAt(iNextMapX, iNextMapY, 9, getEngine(), getEngine()->getBackgroundSurface());
			virtRedrawRectangle();
			// open home
			for (int i = 0; i < pMazeMap->getMapWidth(); i++)
			{
				for (int j = 0; j < pMazeMap->getMapHeight(); j++)
				{
					if (pMazeMap->getMapValue(j, i) == 5) // found closed home
					{
						pMazeMap->setAndRedrawMapValueAt(j, i, 3, getEngine(), getEngine()->getBackgroundSurface());
					}
				}
			}
		}
		else // normal move
		{
			// update next map value
			pMazeMap->setMapValue(iNextMapX, iNextMapY, pMazeMap->getMapValue(iNextMapX, iNextMapY) + 9);
		}
	}
		break;
	default:
		break;
	}
	redrawDisplay();
}

bool Chicken::isGoingToTouchWall(int iKeyCode, int iCurrentMapX, int iCurrentMapY)
{
	MazeMap* pMazeMap = (static_cast<GameEngine*>(getEngine()))->getMazeMap();
	
	// print map
	/*
	for (int i = 0; i < pMazeMap->getMapWidth(); i++)
	{
		for (int j = 0; j < pMazeMap->getMapHeight(); j++)
		{
			std::cout << pMazeMap->getMapValue(j,i);
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	*/

	int currentValue = pMazeMap->getMapValue(iCurrentMapX, iCurrentMapY);
	if (currentValue == 1 || currentValue == 5) // wall or closed home
	{
		return true;
	}
	else if (currentValue >= 9) // chicken: still need checking
	{
		switch (iKeyCode)
		{
		case SDLK_UP:
			iCurrentMapY -= 1;
			break;
		case SDLK_DOWN:
			iCurrentMapY += 1;
			break;
		case SDLK_LEFT:
			iCurrentMapX -= 1;
			break;
		case SDLK_RIGHT:
			iCurrentMapX += 1;
			break;
		default:
			break;
		}
		return isGoingToTouchWall(iKeyCode, iCurrentMapX, iCurrentMapY);
	}
	else
	{
		return false;
	}
}

void Chicken::virtDoUpdate(int iCurrentTime)
{
	if (iCurrentTime / 10 % 15 == 0)
	{
		int randomIndex = rand() % 3;
		image = getEngine()->loadImage("resources/images/chicken_" + std::to_string(randomIndex) + ".png", true).resizeTo(m_iDrawWidth, m_iDrawHeight);
		redrawDisplay();
	}
}
