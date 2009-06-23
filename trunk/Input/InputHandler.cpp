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
	int modifiers = glutGetModifiers();
	key = tolower(key);

	switch(key)
	{
	case 27:
		exit(0);
		break;
	case 'w':
		camera->velocity.z = -1;
		break;
	case 'a':
		camera->velocity.x = -1;
		break;
	case 's':
		camera->velocity.z = 1;
		break;
	case 'd':
		camera->velocity.x = 1;
		break;
	case ' ':
		camera->velocity.y = -1;
		break;
	case '`':
		coordinator->toggleConsoleVisibility();
		break;
	}
	glutPostRedisplay();
}

void InputHandler::keyUpFunction(unsigned char key)
{
	key = tolower(key);

	switch (key)
	{
	case 'w':
		if(camera->velocity.z < 0)
			camera->velocity.z = 0;
		break;
	case 'a':
		if(camera->velocity.x < 0)
			camera->velocity.x = 0;
		break;
	case 's':
		if(camera->velocity.z > 0)
			camera->velocity.z = 0;
		break;
	case 'd':
		if(camera->velocity.x > 0)
			camera->velocity.x = 0;
		break;
	case ' ':
		camera->velocity.y = 0;
		break;
	}
	glutPostRedisplay();
}

void InputHandler::mouseFunction(int button, int state, int x, int y)
{
	mouseEvent.downX = x;
	mouseEvent.downY = y;
}

void InputHandler::motionFunction(int x, int y)
{
	camera->n.z = 0.5 * (y - mouseEvent.downY);
	camera->n.y = 0.5 * (x - mouseEvent.downX);
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
