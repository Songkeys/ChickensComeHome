#include "header.h"
#include "LevelState.h"
#include "GameEngine.h"
#include "StartState.h"
#include <fstream>

LevelState::LevelState(GameEngine* pEngine)
	:m_pEngine(pEngine)
{
}


LevelState::~LevelState()
{
}

void LevelState::setBackground()
{
	m_pEngine->fillBackground(0x0000ff);
	m_pEngine->drawBackgroundString(50, 100, "Input a level name. Press Enter to confirm.", 0xffffff);
	m_pEngine->redrawDisplay();
}

void LevelState::initObjects()
{
	m_pEngine->notifyObjectsAboutMouse(true);
	m_pEngine->notifyObjectsAboutKeys(true);

	m_pEngine->drawableObjectsChanged();

	m_pEngine->destroyOldObjects(true);

	m_pEngine->setAllObjectsVisible(true);
}

void LevelState::onKeyDown(int iKeyCode)
{
	setBackground();
	if (iKeyCode == SDLK_BACKSPACE) // delete
	{
		if (m_strLevelName != "")
		{
			m_strLevelName.pop_back();
			m_pEngine->redrawDisplay();
		}
	}
	else if (iKeyCode == SDLK_RETURN) // confirm
	{
		// check if file exists
		if (std::ifstream("resources/maps/" + m_strLevelName + ".txt")) // exists
		{
			State* pState = new StartState(m_pEngine, m_strLevelName);
			//State* pState = new WelcomeState(m_pEngine);
			m_pEngine->setState(pState);
			pState->initObjects();
		}
		else // error
		{
			m_pEngine->drawBackgroundString(50, 400, "Cannot find this level file :(", 0xff4400);
			m_pEngine->redrawDisplay();
		}
	}
	else // character input
	{
		m_strLevelName += char(iKeyCode);
		m_pEngine->redrawDisplay();
	}
}

void LevelState::drawStringOnTop()
{
	if (m_strLevelName != "")
	{
		m_pEngine->drawForegroundString(100, 200, m_strLevelName.c_str(), 0xffffff);
	}
}