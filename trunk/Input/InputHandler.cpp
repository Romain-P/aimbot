#include "InputHandler.h"
#include "../Game/GameCoordinator.h"

InputHandler* inputHandler;

InputHandler::InputHandler(GameCoordinator* coordinator)
{
	this->coordinator = coordinator;
	inputHandler = this;
}

void InputHandler::keyboardDelegate(unsigned char key, int x, int y)
{
	inputHandler->keyboardFunction(key);
}

void InputHandler::keyUpDelegate(unsigned char key, int x, int y)
{
	inputHandler->keyUpFunction(key);
}

void InputHandler::specialKeyDelegate(int key, int x, int y)
{
	inputHandler->specialKeyFunction(key);
}

void InputHandler::mouseDelegate(int button, int state, int x, int y)
{
	inputHandler->mouseFunction(button, state, x, y);
}

void InputHandler::motionDelegate(int x, int y)
{
	inputHandler->motionFunction(x, y);
}

void InputHandler::keyboardFunction(unsigned char key)
{
	switch(key)
	{
	case 27:
	{
		exit(0);
		break;
	}
	case 'a':
	case 'A':
		break;
	case '`':
		coordinator->toggleConsoleVisibility();
		break;

	}
}
