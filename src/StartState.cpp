#include "header.h"
#include "StartState.h"
#include "GameEngine.h"
#include <fstream>
#include <string>
#include <vector>

StartState::StartState(GameEngine* pEngine)
	: m_pEngine(pEngine)
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
	std::ifstream infile("resources/maps/1.txt");
	for (std::string line; std::getline(infile, line); )
	{
		lines.push_back(line);
		int x = 0;
		for (char& c : line) {
			x++;
		}
		if (x > maxX) {
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
		for (char& c : line) {
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
	m_pEngine->notifyObjectsAboutMouse(true);

	m_pEngine->drawableObjectsChanged();

	m_pEngine->destroyOldObjects(true);

	m_pEngine->createObjectArray(0);

	m_pEngine->setAllObjectsVisible(true);
}