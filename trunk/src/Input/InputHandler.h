#ifndef inputhandler_h
#define inputhandler_h

#include "MovementControls.h"
#include "../Graphics/GraphicIncludes.h"
#include "../Graphics/ScreenBoundsUser.h"
#include "../Graphics/Camera.h"
#include "../Physics/EnvironmentUpdater.h"
#include "../Utils/Structures/Vector3.h"

class GameCoordinator;

class MouseEvent
{
public:
	MouseEvent()
	{
		deltaX = 0;
		deltaY = 0;
	}

	int downX;
	int downY;
	int deltaX;
	int deltaY;
	int lastX;
	int lastY;
	int button;
	int state;
	bool firstEvent;
};

class InputHandler : public ScreenBoundsUser
{
private:
	MouseEvent mouseEvent;
	MovementControls controls;

	Camera* camera;
	EnvironmentUpdater* updater;
	GameCoordinator* coordinator;

public:

	InputHandler(GameCoordinator* coordinator, Camera* camera);

	void keyboardFunction(unsigned char key);
	void keyUpFunction(unsigned char key);
	void specialKeyFunction(int key);
	void mouseFunction(int button, int state, int x, int y);
	void motionFunction(int x, int y);
	void passiveMotionFunction(int x, int y);
	void moveCamera(unsigned char key);


	static void keyboardDelegate(unsigned char key, int x, int y);
	static void keyUpDelegate(unsigned char key, int x, int y);
	static void specialKeyDelegate(int key, int x, int y);
	static void mouseDelegate(int button, int state, int x, int y);
	static void motionDelegate(int x, int y);
	static void passiveMotionDelegate(int x, int y);
	static void updateDelegate();

};
#endif

