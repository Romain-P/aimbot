#ifndef gamecoordinator_h
#define gamecoordinator_h

#include "GameState.h"
#include "Updater.h"

#include "../Graphics/Glut/GraphicIncludes.h"
#include "../Graphics/Glut/GlutDisplay.h"
#include "../Graphics/HUD/PlayerHUD.h"
#include "../Graphics/HUD/DevConsole.h"
#include "../Graphics/SceneDisplay.h"
#include "../Graphics/Animation/Animator.h"
#include "../Input/InputHandler.h"
#include "../Physics/EnvironmentUpdater.h"
#include "../SceneObjects/Entities/CurrentPlayer.h"
#include "../SceneObjects/Weapons/Laser.h"
#include "../Utils/Structures/FileFormat.h"

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

	Laser* laser;
	Player* player;

public:
	GameCoordinator()
	{
		gameState = new GameState(GameState::GAME_IN_SESSION, GameState::PLAYING);

		camera = new Camera();
		display = new GlutDisplay(camera);
		camera->setDisplay(display);

		inputHandler = new InputHandler(this, gameState, camera);

		laser = new Laser();

		CurrentPlayer::Instance().addWeapon(laser);
		CurrentPlayer::Instance().setCamera(camera);
		CurrentPlayer::Instance().calcLook(0, 0);

		envUpdater = new EnvironmentUpdater();
		animator = new Animator();
		updater = new Updater(display, envUpdater, animator);

		hud = new PlayerHUD(this, gameState, updater);
		console = new DevConsole(hud, display);

		scene = new SceneDisplay(this, animator);
		inputHandler->setKDTree(scene->getKDTree());

		display->addOrthographic(console);
		display->addOrthographic(hud);
		display->addOrthographic(laser->getPrimaryShotAnimation());
		display->addDrawable(scene);

		envUpdater->addMovable(&CurrentPlayer::Instance());

		animator->addAnimatable(laser->getPrimaryShotAnimation());
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


	/* Delegation functions */

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

	void eraseWordFromConsole()
	{
		console->eraseWord();
	}

	const Position3 getPlayerPosition()
	{
		return CurrentPlayer::Instance().getPosition();
	}

	const Position3 getClosestPoint()
	{
		return inputHandler->getClosestPoint();
	}

	const Position3 getClosestPoint2()
	{
		return inputHandler->getClosestPoint2();
	}

	float getPlayerHealth()
	{
		return CurrentPlayer::Instance().getHealth();
	}

	void getPlayerAngles(float& theta, float& phi)
	{
		theta = CurrentPlayer::Instance().theta;
		phi = CurrentPlayer::Instance().phi;
	}
};

#endif
