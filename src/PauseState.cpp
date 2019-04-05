#include "header.h"
#include "PauseState.h"
#include "GameEngine.h"

PauseState::PauseState(GameEngine* pEngine, StartState* pStartState)
	:m_pEngine(pEngine), m_pStartState(pStartState)
{
	m_pEngine->notifyObjectsAboutKeys(false);
	m_pEngine->notifyObjectsAboutMouse(false);
}


PauseState::~PauseState()
{
}

void PauseState::drawStringsUnderneath()
{
	m_pEngine->drawBackgroundString(m_pEngine->getWindowWidth() / 2,
		m_pEngine->getWindowHeight() / 2,
		"Paused!",
		0x0,
		0);
	m_pEngine->pause();
	m_pEngine->virtSetupBackgroundBuffer();
}

void PauseState::onKeyDown(int iKeyCode)
{
	if (iKeyCode == SDLK_SPACE) // resume
	{
		m_pEngine->unpause();
		m_pEngine->setState((State*)m_pStartState);
		m_pEngine->virtSetupBackgroundBuffer();
		m_pEngine->redrawDisplay();
		m_pEngine->notifyObjectsAboutKeys(true);
		m_pEngine->notifyObjectsAboutMouse(true);
	}
}
