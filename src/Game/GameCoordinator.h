#ifndef gamecoordinator_h
#define gamecoordinator_h

#include "GameState.h"
#include "Updater.h"

#include "../Input/InputHandler.h"
#include "../Graphics/Glut/GraphicIncludes.h"
#include "../Graphics/Glut/GlutDisplay.h"
#include "../Graphics/HUD/PlayerHUD.h"
#include "../Graphics/HUD/DevConsole.h"
#include "../Graphics/SceneDisplay.h"
#include "../Graphics/Animator.h"
#include "../Graphics/LaserShotAnimation.h"
#include "../Physics/EnvironmentUpdater.h"
#include "../Utils/Structures/FileFormat.h"
#include "../SceneObjects/Entities/Player.h"
#include "../SceneObjects/Weapons/Laser.h"

class GameCoordinator
{
private:
	InputHandler* inputHandler;

	Camera* camera;
	GameState* gameState;

	PlayerHUD* hud;
	DevConsole* console;
	GlutDisplay* display;
	SceneDisplay* scene;

	Updater* updater;
	Animator* animator;
	EnvironmentUpdater* envUpdater;

	LaserShotAnimation* laserShot;
	Laser* laser;
	Player* player;

public:
	GameCoordinator()
	{
		camera = new Camera();
		gameState = new GameState(GameState::GAME_IN_SESSION, GameState::PLAYING);
		display = new GlutDisplay(camera);

		player = new Player();
		laserShot = new LaserShotAnimation();
		laser = new Laser(laserShot);

		player->addWeapon(laser);

		inputHandler = new InputHandler(this, gameState, camera, player);

		camera->setDisplay(display);

		envUpdater = new EnvironmentUpdater();
		animator = new Animator();
		updater = new Updater(display, envUpdater, animator);

		hud = new PlayerHUD(gameState, updater);
		console = new DevConsole(hud, display);

		scene = new SceneDisplay();

		display->addOrthographic(console);
		display->addOrthographic(hud);
		display->addOrthographic(laserShot);
		display->addDrawable(scene);

		envUpdater->addMovable(camera);

		animator->addAnimatable(laserShot);
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
		delete player;
		delete animator;
		delete laser;
		delete laserShot;
	}

	void setFunctionCallbacks()
	{
		glutDisplayFunc(&GlutDisplay::displayDelegate);
		glutReshapeFunc(&GlutDisplay::reshapeDelegate);

		glutMouseFunc(&InputHandler::mouseDelegate);
		glutMotionFunc(&InputHandler::motionDelegate);
		glutPassiveMotionFunc(&InputHandler::passiveMotionDelegate);
		glutKeyboardFunc(&InputHandler::keyboardDelegate);
		glutKeyboardUpFunc(&InputHandler::keyUpDelegate);
		glutSpecialFunc(&InputHandler::specialKeyDelegate);

		glutIdleFunc(&Updater::updateDelegate);
	}

	void toggleConsoleVisibility()
	{
		console->toggleVisibility();

		if(console->isVisible())
			gameState->setIngameState(GameState::IN_DEV_CONSOLE);
		else
			gameState->setIngameState(GameState::PLAYING);
	}

	void putCharToConsole(unsigned char ch)
	{
		console->putChar(ch);
	}
};

#endif
