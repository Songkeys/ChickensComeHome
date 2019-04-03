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
	std::cout << "???";
	m_pEngine->fillBackground(0x00ff00);
	m_pEngine->redrawDisplay();
}

void StartState::initObjects()
{
}