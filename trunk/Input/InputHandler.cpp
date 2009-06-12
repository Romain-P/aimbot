#include "InputHandler.h"

InputHandler* inputHandler;

InputHandler::InputHandler()
{
}

inline void InputHandler::keyboardDelegate(unsigned char key, int x, int y)
{
	inputHandler->keyboardFunction(key);
}

inline void InputHandler::specialKeyDelegate(unsigned char key, int x, int y)
{
	inputHandler->specialKeyFunction(key);
}

inline void InputHandler::mouseDelegate(int button, int state, int x, int y)
{
	inputHandler->mouseFunction(button, state, x, y);
}

inline void InputHandler::motionDelegate(int x, int y)
{
	inputHandler->motionFunction(x, y);
}



void UserInput::registerFunctions()
{
	glutKeyboardFunc(&UserInput::keyboardDelegate);
	glutMouseFunc(&UserInput::mouseDelegate);
	glutMotionFunc(&UserInput::motionDelegate);
}

void UserInput::mouseFunction(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN) {
		mouseStartX = x;
		mouseStartY = y;
		mouseButton = button;
	}
	if(state == GLUT_UP) {

	}
}

void UserInput::motionFunction(int x, int y)
{
	float dx = (x - mouseStartX);
	float dy = (y - mouseStartY);

	switch(mouseButton) {
	case GLUT_LEFT_BUTTON:
		camera->circle(dx * 0.0001f, dy * 0.0001f, cueball->position);
		break;
	case GLUT_MIDDLE_BUTTON:
		camera->zoom((1000 + dy * 0.05f) / 1000.f, cueball->position);
		break;
	case GLUT_RIGHT_BUTTON:
		cue->alpha += dx * 0.003f;
		cue->beta -= dy * 0.003f;
		constrain(cue->beta, 275.f, 358.f);
		break;
	}
	glutPostRedisplay();
}

void UserInput::keyboardFunction(unsigned char key, int x, int y)
{
	switch(key) {
		case 'r': {
			cue->energy += 0.02f;
			constrain(cue->energy, 0.f, 1.2f);
			break;
        }
		case 'e': {
			cue->animate();
			cue->motionIndex = 0;
			cue->position = cueball->position;
			break;
		}
		case 27: exit(0);

	}
	glutPostRedisplay();
}
