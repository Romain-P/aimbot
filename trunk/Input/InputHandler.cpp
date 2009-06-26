#include "InputHandler.h"
#include "../Game/GameCoordinator.h"

InputHandler* inputHandler;

InputHandler::InputHandler(GameCoordinator* coordinator, Camera* camera)
{
	this->coordinator = coordinator;
	this->camera = camera;
	inputHandler = this;
	mouseEvent.firstEvent = true;

	glutWarpPointer(glutGet(GLUT_SCREEN_WIDTH) / 2, glutGet(GLUT_SCREEN_HEIGHT) / 2);
}

void InputHandler::keyboardFunction(unsigned char key)
{
	key = tolower(key);

	switch(key)
	{
		case MovementControls::FORWARD:
		case MovementControls::RIGHT:
		case MovementControls::BACKWARD:
		case MovementControls::LEFT:
		case MovementControls::UP:
		case MovementControls::DOWN:
		{
			controls.push(key);
			Vector3 temp = controls.getDirection();

			camera->velocity.x = 2 * cos(camera->theta) * temp.x - sin(camera->theta) * temp.z;
			camera->velocity.z = 2 * sin(camera->theta) * temp.x + cos(camera->theta) * temp.z;
			break;
		}
		case 27:
			exit(0);
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
		case MovementControls::FORWARD:
		case MovementControls::RIGHT:
		case MovementControls::BACKWARD:
		case MovementControls::LEFT:
		case MovementControls::UP:
		case MovementControls::DOWN:
		{
			controls.pop(key);
			Vector3 temp = controls.getDirection();

			camera->velocity.x = 2 * cos(camera->theta) * temp.x - sin(camera->theta) * temp.z;
			camera->velocity.z = 2 * sin(camera->theta) * temp.x + cos(camera->theta) * temp.z;

			break;
		}
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
	/*
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
	*/
}

void InputHandler::passiveMotionFunction(int x, int y)
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

	//glutWarpPointer(halfWidth, halfHeight);
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

void InputHandler::passiveMotionDelegate(int x, int y)
{
	inputHandler->passiveMotionFunction(x, y);
}
