#include "InputHandler.h"
#include "../Game/GameCoordinator.h"

InputHandler* inputHandler;

InputHandler::InputHandler(
		GameCoordinator* coordinator,
		GameState* gameState,
		Camera* camera) :
	ScreenBoundsUser(),
	MovementController()
{
	this->coordinator = coordinator;
	this->camera = camera;
	this->gameState = gameState;

	inputHandler = this;
	mouseEvent.firstEvent = true;

	sens = StringCaster<float>::cast(ConfigMap::Instance().get("mouse.sensitivity"));

	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
}

void InputHandler::keyboardFunction(unsigned char key)
{
	switch(gameState->getIngameState())
	{
		case GameState::PLAYING:
		{
			key = tolower(key);
			if( key == fore  || key == back ||
				key == right ||	key == left ||
				key == up    || key == down)
			{
				push(key);
				CurrentPlayer::Instance().updateVelocity(getVelocity());
			}
			else if(key == 27)
				exit(0);
			else if(key == '`')
				coordinator->toggleConsoleVisibility();
			break;
		}
		case GameState::IN_DEV_CONSOLE:
		{
			clearMovementKeys();

			int mods = glutGetModifiers();

			switch(key)
			{
				case 27:
				case '`':
					coordinator->toggleConsoleVisibility();
					break;
				default:
				{
					if(key == 127 && mods & GLUT_ACTIVE_CTRL)
						coordinator->eraseWordFromConsole();
					else
						coordinator->putCharToConsole(key);
				}
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
	if( key == fore  || key == back ||
		key == right ||	key == left ||
		key == up    || key == down)
	{
		pop(key);
		CurrentPlayer::Instance().updateVelocity(getVelocity());
	}

	glutPostRedisplay();
}

void InputHandler::mouseFunction(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			std::cout << "firing" << std::endl;
			player->firePrimary();
		}
		else if (button == GLUT_RIGHT_BUTTON)
			player->fireSecondary();
	}
	else if (state == GLUT_UP)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
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
	if(gameState->getIngameState() == GameState::IN_DEV_CONSOLE)
		return;

	static bool warped = false;

	// prevents a major jump on the first mouse movement
	if(mouseEvent.firstEvent)
	{
		mouseEvent.firstEvent = false;
		CurrentPlayer::Instance().calcLook(0, 0);
	}
	else
	{
		// reset mouse pointer to centre if it's about to go off screen
		if(x + mouseEvent.deltaX > width || x + mouseEvent.deltaX < 0 ||
			y + mouseEvent.deltaY > height || y + mouseEvent.deltaY < 0)
		{
			glutWarpPointer(halfWidth, halfHeight);
			warped = true;
		}

		mouseEvent.deltaX = (x - mouseEvent.lastX);
		mouseEvent.deltaY = (y - mouseEvent.lastY);

		CurrentPlayer::Instance().calcLook(sens * mouseEvent.deltaX, sens * mouseEvent.deltaY);
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

void InputHandler::setKDTree(KDTree* tree)
{
	this->tree = tree;
}

Position3 InputHandler::getClosestPoint()
{
	vector<KDPair> closest =
		tree->findNearest(CurrentPlayer::Instance().getPosition(), 1);

	return closest.front().node->position;
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
