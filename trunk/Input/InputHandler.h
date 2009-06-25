#ifndef inputhandler_h
#define inputhandler_h

#include "../Graphics/GraphicIncludes.h"
#include "../Graphics/Camera.h"
#include "../Physics/EnvironmentUpdater.h"
#include "../Utils/Structures/Vector3.h"

class GameCoordinator;

class MouseEvent
{
public:
	MouseEvent()
	{
	}

	int downX;
	int downY;
	int x;
	int y;
	int lastX;
	int lastY;
	int button;
	int state;
	bool firstEvent;
};

class InputHandler
{
private:
	MouseEvent mouseEvent;

	Camera* camera;
	EnvironmentUpdater* updater;
	GameCoordinator* coordinator;

public:
	enum movements { FORWARD, LEFT, BACKWARD, RIGHT, UP, DOWN };

	InputHandler(GameCoordinator* coordinator, Camera* camera);

	void keyboardFunction(unsigned char key);
	void keyUpFunction(unsigned char key);
	void specialKeyFunction(int key);
	void mouseFunction(int button, int state, int x, int y);
	void motionFunction(int x, int y);

	static void keyboardDelegate(unsigned char key, int x, int y);
	static void keyUpDelegate(unsigned char key, int x, int y);
	static void specialKeyDelegate(int key, int x, int y);
	static void mouseDelegate(int button, int state, int x, int y);
	static void motionDelegate(int x, int y);
	static void updateDelegate();

};
#endif

