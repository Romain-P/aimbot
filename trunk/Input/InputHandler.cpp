#include "InputHandler.h"
#include "../Game/GameCoordinator.h"

InputHandler* inputHandler;

InputHandler::InputHandler(GameCoordinator* coordinator, Camera* camera)
{
	this->coordinator = coordinator;
	this->camera = camera;
	inputHandler = this;
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
	case 'w': 	case 'W':
		camera->velocity = Vector3(-1, 0, 0);
		break;
	case 'a': 	case 'A':
		camera->velocity = Vector3(0, 0, -1);
		break;
	case 's': 	case 'S':
		camera->velocity = Vector3(1, 0, 0);
		break;
	case 'd':	case 'D':
		camera->velocity = Vector3(0, 0, 1);
		break;

	case '`':
		coordinator->toggleConsoleVisibility();
		break;

	}
	glutPostRedisplay();
}

void InputHandler::keyUpFunction(unsigned char key)
{
	switch (key)
	{
	case 'w': 	case 'W':
		camera->velocity = Vector3(0);
		break;
	case 'a': 	case 'A':
		camera->velocity = Vector3(0);
		break;
	case 's': 	case 'S':
		camera->velocity = Vector3(0);
		break;
	case 'd':	case 'D':
		camera->velocity = Vector3(0);
		break;
	}
	glutPostRedisplay();
}

void InputHandler::mouseFunction(int button, int state, int x, int y)
{

}

void InputHandler::motionFunction(int x, int y)
{

}

void InputHandler::specialKeyFunction(int key)
{
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
