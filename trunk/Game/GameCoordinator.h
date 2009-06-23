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
#include "../Physics/EnvironmentUpdater.h"
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
	EnvironmentUpdater* envUpdater;

public:
	GameCoordinator()
	{
		camera = new Camera();
		display = new GlutDisplay(camera);
		inputHandler = new InputHandler(this, camera);
		camera->setDisplay(display);

		envUpdater = new EnvironmentUpdater();
		updater = new Updater(display, envUpdater);

		gameState = new GameState();
		hud = new PlayerHUD(gameState, updater);
		console = new DevConsole(hud);

		scene = new SceneDisplay();

		display->addDrawable((Drawable*)hud);
		display->addDrawable((Drawable*)scene);

		envUpdater->addMovable((Movable*)camera);
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
		delete envUpdater;
		delete scene;
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
		if(console->isVisible())
			display->removeDrawable((Drawable*)console);
		else
			display->addDrawable((Drawable*)console);
	}
};

#endif
