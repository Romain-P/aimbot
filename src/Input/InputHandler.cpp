#include "InputHandler.h"
#include "../Game/GameCoordinator.h"

InputHandler* inputHandler;

InputHandler::InputHandler(
		GameCoordinator* coordinator,
		GameState* gameState,
		Camera* camera,
		Player* player) :
	ScreenBoundsUser()
{
	this->coordinator = coordinator;
	this->camera = camera;
	this->gameState = gameState;
	this->player = player;

	inputHandler = this;
	mouseEvent.firstEvent = true;
}

void InputHandler::keyboardFunction(unsigned char key)
{
	switch(gameState->getIngameState())
	{
		case GameState::PLAYING:
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
					camera->updateVelocity(controls.getDirection());
					break;
				}
				case 27:
					exit(0);
					break;
				case '`':
					coordinator->toggleConsoleVisibility();
					break;
			}
			break;
		}
		case GameState::IN_DEV_CONSOLE:
		{
			switch(key)
			{
				case 27:
				case '`':
					coordinator->toggleConsoleVisibility();
					break;
				default:
					coordinator->putCharToConsole(key);
			}
			break;
		}
	}

	glutPostRedisplay();
}

void InputHandler::keyUpFunction(unsigned char key)
{
	if(gameState->getIngameState() == GameState::IN_DEV_CONSOLE)
		return;

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
			camera->updateVelocity(controls.getDirection());
			break;
		}
	}
	glutPostRedisplay();
}

void InputHandler::mouseFunction(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON) {
			std::cout << "firing" << std::endl;
			player->firePrimary();
		}
		else if (button == GLUT_RIGHT_BUTTON)
			player->fireSecondary();
	}
	else if (state == GLUT_UP) {
		if (button == GLUT_LEFT_BUTTON) {
			std::cout << "releasing" << std::endl;
			player->releasePrimary();
		}
		else if (button == GLUT_RIGHT_BUTTON)
			player->releaseSecondary();
	}

	mouseEvent.firstEvent = true;
}

void InputHandler::motionFunction(int x, int y)
{
	passiveMotionFunction(x, y);
}

void InputHandler::passiveMotionFunction(int x, int y)
{
	static float sens = 0.002f;
	static bool warped = false;

	// prevents a major jump on the first mouse movement
	if(mouseEvent.firstEvent)
	{
		mouseEvent.firstEvent = false;
		camera->calcLook(0, 0);
	}
	else
	{
		// reset mouse pointer to centre if it's about to go off screen
		if(x + 2 * mouseEvent.deltaX > width || x + 2 * mouseEvent.deltaX < 0 ||
			y + 2 * mouseEvent.deltaY > height || y + 2 * mouseEvent.deltaY < 0)
		{
			glutWarpPointer(halfWidth, halfHeight);
			warped = true;
		}

		mouseEvent.deltaX = (x - mouseEvent.lastX);
		mouseEvent.deltaY = (y - mouseEvent.lastY);
		camera->calcLook(sens * mouseEvent.deltaX, sens * mouseEvent.deltaY);
	}

	if(warped)
	{
		mouseEvent.lastX = halfWidth;
		mouseEvent.lastY = halfHeight;
		warped = false;
	}
	else
	{
		mouseEvent.lastX = x;
		mouseEvent.lastY = y;
	}
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
