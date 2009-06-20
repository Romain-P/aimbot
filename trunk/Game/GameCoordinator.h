#ifndef gamecoordinator_h
#define gamecoordinator_h

#include "GameState.h"
#include "Updater.h"
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
		console = new DevConsole(hud);
		display = new GlutDisplay(hud);
		inputHandler = new InputHandler(this);
	}

	void initialize()
	{
		setFunctionCallbacks();
		display->initGraphicsOptions();
	}

	~GameCoordinator()
	{
		delete hud;
		delete console;
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
