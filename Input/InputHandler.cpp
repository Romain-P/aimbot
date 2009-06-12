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

void InputHandler::mouseFunction(int button, int state, int x, int y)
{
}

void InputHandler::motionFunction(int x, int y)
{
	glutPostRedisplay();
}

void InputHandler::keyboardFunction(unsigned char key, int x, int y)
{
	glutPostRedisplay();
}
