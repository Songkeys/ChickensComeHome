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
	m_pState->initObjects();
	return 0;
}

void GameEngine::setState(State* pState)
{
	m_pState = pState;
}
