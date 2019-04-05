#include "header.h"
#include "WelcomeState.h"
#include "StartState.h"
#include "GameEngine.h"
#include "LevelState.h"
#include "Button.h"

WelcomeState::WelcomeState(GameEngine* pEngine)
	:m_pEngine(pEngine)
{
}


WelcomeState::~WelcomeState()
{
}

void WelcomeState::setBackground()
{
	m_pEngine->fillBackground(0x0000ff);
	// image
}

void switchToStart(GameEngine* pEngine)
{
	State* pState = new StartState(pEngine, "1");
	pEngine->setState(pState);
	pState->initObjects();
};

void switchToLevels(GameEngine* pEngine)
{
	State* pState = new LevelState(pEngine);
	pEngine->setState(pState);
	pState->initObjects();
}

void WelcomeState::initObjects()
{
	m_pEngine->notifyObjectsAboutKeys(true);
	m_pEngine->notifyObjectsAboutMouse(true);

	m_pEngine->drawableObjectsChanged();

	m_pEngine->destroyOldObjects(true);

	m_pEngine->storeObjectInArray(0, new Button(100, 100, m_pEngine, "Start", &switchToStart));
	m_pEngine->storeObjectInArray(1, new Button(100, 200, m_pEngine, "Levels", &switchToLevels));
	m_pEngine->storeObjectInArray(2, new Button(100, 300, m_pEngine, "Help", &switchToStart));

	m_pEngine->setAllObjectsVisible(true);
}
