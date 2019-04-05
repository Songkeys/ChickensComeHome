#include "header.h"
#include "GameEngine.h"

#include "WelcomeState.h"


GameEngine::GameEngine()
	:m_pState(new WelcomeState(this))
{
}


GameEngine::~GameEngine()
{
}


void GameEngine::virtSetupBackgroundBuffer()
{
	m_pState->setBackground();
}

int GameEngine::virtInitialiseObjects()
{
	createObjectArray(100); // big enough to use
	m_pState->initObjects();
	return 0;
}

void GameEngine::virtKeyDown(int iKeyCode)
{
	m_pState->onKeyDown(iKeyCode);
}

void GameEngine::setState(State* pState)
{
	m_pState = pState;
	virtSetupBackgroundBuffer();
}

void GameEngine::virtDrawStringsOnTop()
{
	m_pState->drawStringOnTop();
}