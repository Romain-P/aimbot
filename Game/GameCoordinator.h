#ifndef gamecoordinator_h
#define gamecoordinator_h

#include "GameState.h"
#include "Updater.h"

#include "../Input/InputHandler.h"
#include "../Graphics/GraphicIncludes.h"
#include "../Graphics/GlutDisplay.h"
#include "../Graphics/HUD/PlayerHUD.h"
#include "../Graphics/HUD/DevConsole.h"
#include "../Graphics/SceneDisplay.h"
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
	SceneDisplay* scene;

public:
	GameCoordinator()
	{
		camera = new Camera();
		display = new GlutDisplay(camera);
		updater = new Updater(display);

		gameState = new GameState();
		hud = new PlayerHUD(gameState, updater);
		console = new DevConsole(hud);
		scene = new SceneDisplay();

		display->addDrawable((Drawable*)hud);
		display->addDrawable((Drawable*)console);
		display->addDrawable((Drawable*)scene);

		inputHandler = new InputHandler(this);
	}

	void initialize()
	{
		setFunctionCallbacks();
		display->initGraphicsOptions();
	}

	~GameCoordinator()
	{
		delete camera;
		delete display;
		delete updater;
		delete gameState;
		delete hud;
		delete console;
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
