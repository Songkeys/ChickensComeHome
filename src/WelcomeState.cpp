#include "header.h"
#include "WelcomeState.h"

#include "GameEngine.h"

WelcomeState::WelcomeState()
{
}


WelcomeState::~WelcomeState()
{
}

void WelcomeState::setBackground(GameEngine* pEngine)
{
	pEngine->fillBackground(0xff9800);

}