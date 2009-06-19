#ifndef inputhandler_h
#define inputhandler_h

#include "../Graphics/GraphicIncludes.h"
#include "../Physics/EnvironmentUpdater.h"

class GameCoordinator;

class InputHandler
{
private:
	EnvironmentUpdater* updater;

public:
	enum movements { FORWARD, LEFT, BACKWARD, RIGHT, UP, DOWN };

	InputHandler(GameCoordinator* coordinator);

	static void keyboardDelegate(unsigned char key, int x, int y);
	static void keyUpDelegate(unsigned char key, int x, int y);
	static void specialKeyDelegate(int key, int x, int y);
	static void mouseDelegate(int button, int state, int x, int y);
	static void motionDelegate(int x, int y);
	static void updateDelegate();

	void keyboardFunction(unsigned char key)
	{
		switch(key)
		{
		case 27:
		{
			exit(0);
			break;
		}
		case 'a':
		case 'A':
			break;
		case '`':
			//console->toggleVisibility();
			break;

		}
	}

	void keyUpFunction(unsigned char key)
	{

	}

	void specialKeyFunction(int key)
	{

	}

	void mouseFunction(int button, int state, int x, int y)
	{
		glutPostRedisplay();
	}

	void motionFunction(int x, int y)
	{
		glutPostRedisplay();
	}
};
#endif
