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
	{
		camera->velocity.x = -sin(camera->theta);
		camera->velocity.z = -cos(camera->theta);
		break;
	}
	case 'a':
	{
		camera->velocity.x = cos(camera->theta);
		camera->velocity.z = sin(camera->theta);
		break;
	}
	case 's':
	{
		camera->velocity.x = sin(camera->theta);
		camera->velocity.z = cos(camera->theta);
		break;
	}
	case 'd':
	{
		camera->velocity.x = -cos(camera->theta);
		camera->velocity.z = -sin(camera->theta);
		break;
	}
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
	mouseEvent.firstEvent = true;
}

void InputHandler::motionFunction(int x, int y)
{
	static float sensitivity = 0.002f;

	if(mouseEvent.firstEvent)
	{
		mouseEvent.firstEvent = false;
		camera->calcLook(0, 0);
	}
	else
	{
		float dx = sensitivity * (x - mouseEvent.lastX);
		float dy = sensitivity * (y - mouseEvent.lastY);
		camera->calcLook(dx, dy);
	}

	mouseEvent.lastX = x;
	mouseEvent.lastY = y;

	glutPostRedisplay();
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
