#include "InputHandler.h"

InputHandler* inputHandler;

InputHandler::InputHandler()
{
	inputHandler = this;
}

inline void InputHandler::keyboardDelegate(unsigned char key, int x, int y)
{
	inputHandler->keyboardFunction(key);
}

inline void InputHandler::keyUpDelegate(unsigned char key, int x, int y)
{
	inputHandler->keyUpFunction(key);
}

inline void InputHandler::specialKeyDelegate(int key, int x, int y)
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
