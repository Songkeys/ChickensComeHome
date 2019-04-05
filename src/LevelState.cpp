#include "header.h"
#include "LevelState.h"
#include "GameEngine.h"


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
	m_pEngine->drawBackgroundString(50, 100, "Input a level file name. Press Enter to confirm.", 0xffffff);
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
	std::cout << char(iKeyCode);
	m_strLevelName += char(iKeyCode);
	m_pEngine->drawForegroundString(100, 200, m_strLevelName.c_str(), 0xffffff);
	m_pEngine->redrawDisplay();
}
