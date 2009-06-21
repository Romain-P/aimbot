#ifndef gamecoordinator_h
#define gamecoordinator_h

#include "GameState.h"
#include "Updater.h"

#include "../Input/InputHandler.h"
#include "../Graphics/GraphicIncludes.h"
#include "../Graphics/GlutDisplay.h"
#include "../Graphics/HUD/PlayerHUD.h"
#include "../Graphics/HUD/DevConsole.h"
#include "../Utils/Structures/FileFormat.h"

class GameCoordinator
{
private:
	Camera* camera;
	GameState* gameState;
	Updater* updater;
	InputHandler* inputHandler;
	PlayerHUD* hud;
	DevConsole* console;
	GlutDisplay* display;
public:
	//I don't know how to untangle this mess, there must be cleaner ways of doing this
	GameCoordinator()
	{
		camera = new Camera();
		display = new GlutDisplay(camera);
		updater = new Updater(display);

		gameState = new GameState();
		hud = new PlayerHUD(gameState, updater);
		console = new DevConsole(hud);
		display = new GlutDisplay(camera);

		display->addDrawable((Drawable*)hud);
		display->addDrawable((Drawable*)console);

		inputHandler = new InputHandler(this);
	}

	void initialize()
	{
		setFunctionCallbacks();
		display->initGraphicsOptions();
	}

	~GameCoordinator()
	{
		delete console;
		delete updater;
		delete gameState;
		delete hud;
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
