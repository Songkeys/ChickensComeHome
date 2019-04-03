#include "header.h"
#include "WelcomeState.h"

#include "GameEngine.h"
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

void switchToStart(GameEngine* pEngine) {
	std::cout << "out";
	pEngine->setState(new WelcomeState(pEngine));
};

void switchToRanking(GameEngine* pEngine)
{
	//m_pEngine->setState();
}

void WelcomeState::initObjects()
{
	m_pEngine->notifyObjectsAboutMouse(true);

	m_pEngine->drawableObjectsChanged();

	m_pEngine->destroyOldObjects(true);

	m_pEngine->createObjectArray(3);

	m_pEngine->storeObjectInArray(0, new Button(100, 100, m_pEngine, "Start", &switchToStart));
	m_pEngine->storeObjectInArray(1, new Button(100, 200, m_pEngine, "Ranking", &switchToRanking));
	m_pEngine->storeObjectInArray(2, new Button(100, 300, m_pEngine, "Exit", &switchToStart));

	m_pEngine->setAllObjectsVisible(true);
}
