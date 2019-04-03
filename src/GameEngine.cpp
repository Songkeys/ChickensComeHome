#include "header.h"
#include "GameEngine.h"

#include "WelcomeState.h"


GameEngine::GameEngine()
	:m_pState(new WelcomeState())
{
}


GameEngine::~GameEngine()
{
}


void GameEngine::virtSetupBackgroundBuffer()
{
	m_pState->setBackground(this);
}

int GameEngine::virtInitialiseObjects()
{
	m_pState->initObjects(this);
	return 0;
}