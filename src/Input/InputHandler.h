#ifndef inputhandler_h
#define inputhandler_h

#include "MovementController.h"
#include "ConfigMap.h"
#include "../Game/GameState.h"
#include "../Graphics/Glut/GraphicIncludes.h"
#include "../Graphics/ScreenBoundsUser.h"
#include "../Graphics/Camera.h"
#include "../Physics/EnvironmentUpdater.h"
#include "../SceneObjects/Entities/CurrentPlayer.h"
#include "../Utils/Structures/Vector3.h"
#include "../Utils/Structures/KDTree.h"
#include "../Utils/Misc/StringCaster.h"

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

class InputHandler : public ScreenBoundsUser, public MovementController
{
private:
	MouseEvent mouseEvent;

	GameState* gameState;
	EnvironmentUpdater* updater;
	GameCoordinator* coordinator;
	CurrentPlayer* player;

	Camera* camera;
	KDTree* tree;

	float sens;
public:

	InputHandler(GameCoordinator* coordinator,
			GameState* gameState,
			Camera* camera);

	void keyboardFunction(unsigned char key);
	void keyUpFunction(unsigned char key);
	void specialKeyFunction(int key);
	void mouseFunction(int button, int state, int x, int y);
	void motionFunction(int x, int y);
	void passiveMotionFunction(int x, int y);
	void moveCamera(unsigned char key);
	void setKDTree(KDTree* tree);
	Position3 getClosestPoint();


	static void keyboardDelegate(unsigned char key, int x, int y);
	static void keyUpDelegate(unsigned char key, int x, int y);
	static void specialKeyDelegate(int key, int x, int y);
	static void mouseDelegate(int button, int state, int x, int y);
	static void motionDelegate(int x, int y);
	static void passiveMotionDelegate(int x, int y);
	static void updateDelegate();

};
#endif

