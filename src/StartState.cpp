#include "header.h"
#include "StartState.h"
#include "GameEngine.h"


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

	// drawMap
	m_pEngine->getMazeMap();
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