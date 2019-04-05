#include "header.h"
#include "StartState.h"
#include "GameEngine.h"
#include "Chicken.h"
#include "WelcomeState.h"
#include "PauseState.h"
#include <fstream>
#include <string>
#include <vector>

StartState::StartState(GameEngine* pEngine)
	: m_pEngine(pEngine)
{
}

StartState::StartState(GameEngine* pEngine, std::string strLevelName)
	: m_pEngine(pEngine), m_strLevelName(strLevelName)
{
}

StartState::~StartState()
{
}

void StartState::setBackground()
{
	// set background
	m_pEngine->fillBackground(0x00ff00);
	SimpleImage bg = ImageManager::loadImage("resources/images/grass_bg.jpg", true);
	bg.renderImage(m_pEngine->getBackgroundSurface(), 0, 0, 0, 0, 800, 600);

	// read map
	std::vector<std::string> lines;
	int maxX = 0;
	int maxY = 0;
	std::ifstream infile("resources/maps/" + m_strLevelName + ".txt");
	for (std::string line; std::getline(infile, line); )
	{
		lines.push_back(line);
		int x = 0;
		for (char& c : line)
		{
			x++;
		}
		if (x > maxX)
		{
			maxX = x;
		}
		maxY++;
	}

	// set map size and position
	int screenWidthPadding = 100;
	int tileLength = (m_pEngine->getWindowWidth() - screenWidthPadding * 2) / maxX;
	MazeMap* pMazeMap = new MazeMap(
		tileLength,
		tileLength,
		maxX,
		maxY);
	m_pEngine->setMazeMap(pMazeMap);
	m_pEngine->getMazeMap()->setMapSize(maxX, maxY);
	m_pEngine->getMazeMap()->setTopLeftPositionOnScreen(screenWidthPadding, // x: center
		m_pEngine->getWindowHeight() - maxY * tileLength); // y: start with bottom

	// set map value
	int x = 0;
	int y = 0;
	for (std::string line : lines)
	{
		x = 0;
		for (char& c : line)
		{
			int value = c - '0';
			m_pEngine->getMazeMap()->setMapValue(x, y, value);
			x++;
		}
		y++;
	}
	m_pEngine->getMazeMap()->drawAllTiles(m_pEngine, m_pEngine->getBackgroundSurface());

	m_pEngine->redrawDisplay();
}

void StartState::initObjects()
{
	m_pEngine->notifyObjectsAboutKeys(true);
	m_pEngine->notifyObjectsAboutMouse(false);
	m_pEngine->drawableObjectsChanged();
	m_pEngine->destroyOldObjects(true);

	
	// set chickens
	int chickenId = 0;
	int x = m_pEngine->getMazeMap()->getMapWidth();
	int y = m_pEngine->getMazeMap()->getMapHeight();
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			bool isChicken = m_pEngine->getMazeMap()->getMapValue(i, j) == 9;
			if (isChicken)
			{
				int chickenX = m_pEngine->getMazeMap()->getScreenXForMapX(i);
				int chickenY = m_pEngine->getMazeMap()->getScreenYForMapY(j);
				int tileLength = m_pEngine->getMazeMap()->getTileWidth();
				Chicken* chicken = new Chicken(chickenId, chickenX, chickenY, m_pEngine, tileLength, tileLength);

				//m_pEngine->appendObjectToArray(chicken); // werid bug!!! an hour to figure out what happened!
				m_pEngine->storeObjectInArray(chickenId, chicken);
				chickenId++;
				m_iRemainingChickenCount++;
			}
		}
	}
	
	m_pEngine->setAllObjectsVisible(true);
	
}

void StartState::drawStringOnTop()
{
	m_pEngine->drawForegroundString(10, 10, "Remaining: ", 0x44ff00, 0);
	m_pEngine->drawForegroundString(10, 60, std::to_string(m_iRemainingChickenCount).c_str(), 0x44ff00, 0);
	m_pEngine->drawForegroundString(10, 110, "Died: ", 0xff0000, 0);
	m_pEngine->drawForegroundString(10, 160, std::to_string(m_iDiedChickenCount).c_str(), 0xff0000, 0);
	m_pEngine->drawForegroundString(10, 210, "Score: ", 0x004444, 0);
	m_pEngine->drawForegroundString(10, 260, std::to_string(m_iScore).c_str(), 0x004444, 0);
}

void switchToWelcome(GameEngine* pEngine, int iScore)
{
	State* pState = new WelcomeState(pEngine, iScore);
	pEngine->setState(pState);
	pState->setBackground();
	pState->initObjects();
}

void StartState::die()
{
	m_iRemainingChickenCount -= 1;
	m_iDiedChickenCount += 1;
	m_iScore -= 10;
	m_pEngine->redrawDisplay();
	if (m_iRemainingChickenCount == 0) // lose
	{
		m_iScore = -1;
		switchToWelcome(m_pEngine, m_iScore);
	}
}

void StartState::getHome()
{
	m_iRemainingChickenCount -= 1;
	m_pEngine->redrawDisplay();
	if (m_iRemainingChickenCount == 0) // win
	{
		switchToWelcome(m_pEngine, m_iScore);
	}
}

void switchToPause(GameEngine* pEngine)
{
	State* pState = new WelcomeState(pEngine);
	pEngine->setState(pState);
	pState->initObjects();
}

void StartState::loseScore(int iScore)
{
	m_iScore -= iScore;
	if (iScore < 0)
	{
		switchToWelcome(m_pEngine, m_iScore);
	}
}

void StartState::onKeyDown(int iKeyCode)
{
	if (iKeyCode == SDLK_ESCAPE) // back to welcome
	{
		m_iRemainingChickenCount = 1;
		die();
		//switchToWelcome(m_pEngine); // bug: why the background is not redrew?
		return;
	}
	else if (iKeyCode == SDLK_SPACE) // pause
	{
		State* pState = new PauseState(m_pEngine, this);
		m_pEngine->setState(pState);
	}
	else if (iKeyCode == SDLK_LEFT || iKeyCode == SDLK_RIGHT || iKeyCode == SDLK_UP || iKeyCode == SDLK_DOWN) // lose score for move
	{
		loseScore(1);
	}
}
