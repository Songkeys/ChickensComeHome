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
	m_pEngine->fillBackground(0x00ff00);

	// read map
	std::vector<std::string> lines;
	int width = 0;
	int height = 0;
	std::ifstream infile("resources/maps/1.txt");
	for (std::string line; std::getline(infile, line); ) // first time: get height and width
	{
		lines.push_back(line);
		int x = 0;
		for (char& c : line) {
			x++;
		}
		if (x > width) {
			width = x;
		}
		height++;
	}
	m_pEngine->getMazeMap().setMapSize(width, height);

	int x = 0;
	int y = 0;
	for (std::string line : lines) // second time: get map data
	{
		x = 0;
		for (char& c : line) {
			int value = c - '0';
			m_pEngine->getMazeMap().setMapValue(x, y, value);
			x++;
		}
		y++;
	}
	m_pEngine->getMazeMap().setTopLeftPositionOnScreen(50, 50);
	m_pEngine->getMazeMap().drawAllTiles(m_pEngine, m_pEngine->getBackgroundSurface());
	
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