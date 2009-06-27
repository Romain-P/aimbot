#include "InputHandler.h"
#include "../Game/GameCoordinator.h"

InputHandler* inputHandler;

InputHandler::InputHandler(GameCoordinator* coordinator, Camera* camera)
{
	this->coordinator = coordinator;
	this->camera = camera;
	inputHandler = this;

	mouseEvent.firstEvent = true;
	width = glutGet(GLUT_SCREEN_WIDTH);
	height = glutGet(GLUT_SCREEN_HEIGHT);
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
}

/*void passivemotion( int x, int y ) {
        int deltaX = x - lastX;
        int deltaY = y - lastY;

        lastX = x;
        lastY = y;

        if( deltaX == 0 && deltaY == 0 ) return;

        int windowX             = glutGet( GLUT_WINDOW_X );
        int windowY             = glutGet( GLUT_WINDOW_Y );
        int screenWidth         = glutGet( GLUT_SCREEN_WIDTH );
        int screenHeight        = glutGet( GLUT_SCREEN_HEIGHT );

        int screenLeft = -windowX;
        int screenTop = -windowY;
        int screenRight = screenWidth - windowX;
        int screenBottom = screenHeight - windowY;

        if( x <= screenLeft+10 || (y) <= screenTop+10 || x >= screenRight-10 || y >= screenBottom - 10) {
                lastX = 150;
                lastY = 150;
                glutWarpPointer( lastX, lastY );
                //      If on Mac OS X, the following will also work (and CGwarpMouseCursorPosition seems faster than glutWarpPointer).
                //      CGPoint centerPos = CGPointMake( windowX + lastX, windowY + lastY );
                //      CGWarpMouseCursorPosition( centerPos );
                // Have to re-hide if the user touched any UI element with the invisible pointer, like the Dock.
                //      CGDisplayHideCursor(kCGDirectMainDisplay);
        }

        curX += deltaX;
        curY -= deltaY;
}*/

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
			glutWarpPointer(width / 2, height / 2);
			warped = true;
		}

		mouseEvent.deltaX = (x - mouseEvent.lastX);
		mouseEvent.deltaY = (y - mouseEvent.lastY);
		camera->calcLook(sens * mouseEvent.deltaX, sens * mouseEvent.deltaY);

		cout << mouseEvent.deltaX << endl;
	}

	if(warped)
	{
		mouseEvent.lastX = width / 2;
		mouseEvent.lastY = height / 2;
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
