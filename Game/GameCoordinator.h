#ifndef gamecoordinator_h
#define gamecoordinator_h

#include "Updater.h"
#include "GameState.h"
#include "../Input/InputHandler.h"
#include "../Graphics/GlutDisplay.h"
#include "../Graphics/HUD/PlayerHUD.h"
#include "../Graphics/HUD/DevConsole.h"

class GameCoordinator
{
private:
	GameState gameState;
	Updater updater;
	InputHandler* inputHandler;

	PlayerHUD* hud;
	DevConsole* console;
	GlutDisplay* display;
public:
	GameCoordinator()
	{
		hud = new PlayerHUD(&gameState, &updater);
		display = new GlutDisplay(hud);
		console = new DevConsole(hud);
		inputHandler = new InputHandler(this);
	}

	void initialize()
	{
		setFunctionCallbacks();
	}

	~GameCoordinator()
	{
		delete display;
		delete inputHandler;
	}

	void setFunctionCallbacks()
	{
		glutDisplayFunc(&GlutDisplay::displayDelegate);
		glutReshapeFunc(&GlutDisplay::reshapeDelegate);

		glutMouseFunc(&InputHandler::mouseDelegate);
		glutMotionFunc(&InputHandler::motionDelegate);
		glutKeyboardFunc(&InputHandler::keyboardDelegate);
		glutKeyboardUpFunc(&InputHandler::keyUpDelegate);
		glutSpecialFunc(&InputHandler::specialKeyDelegate);

		glutIdleFunc(&Updater::updateDelegate);
	}

	void toggleConsoleVisibility()
	{
		console->toggleVisibility();
	}
};

#endif
