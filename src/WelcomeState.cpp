#include "header.h"
#include "WelcomeState.h"

#include "GameEngine.h"
#include "Button.h"

WelcomeState::WelcomeState()
{
}


WelcomeState::~WelcomeState()
{
}

void WelcomeState::setBackground(GameEngine* pEngine)
{
	pEngine->fillBackground(0x0000ff);
	// image
	
}

void switchToStart() {
	std::cout << "ok";
};


void WelcomeState::initObjects(GameEngine* pEngine)
{
	pEngine->notifyObjectsAboutMouse(true);

	pEngine->drawableObjectsChanged();

	pEngine->destroyOldObjects(true);

	pEngine->createObjectArray(3);

	pEngine->storeObjectInArray(0, new Button(100, 100, pEngine, "Start", &switchToStart));

	pEngine->setAllObjectsVisible(true);
}
