#include "PlayerHUD.h"
#include "../../Game/Updater.h"
#include "../../Game/GameCoordinator.h"

PlayerHUD::PlayerHUD(GameState* gameState, Updater* gameUpdater, GameCoordinator* coordinator) :
	Drawable(300)
{
	state = gameState;
	updater = gameUpdater;
	this->coordinator = coordinator;

	showFPS = false;
	showPosition = false;
	showAngles = false;

	crosshair = new Cross(6.f, Colour(1.f, 0.9f, 0.9f));
}

PlayerHUD::~PlayerHUD()
{
	delete crosshair;
}

void PlayerHUD::draw()
{
	if(showFPS)
		drawFPS();
	if(showPosition)
		drawPosition();
	if(showAngles)
		drawAngles();

	crosshair->draw();
}

void PlayerHUD::drawFPS()
{
	static char str[15];
	static float fps;

	if(updater->getFrames() % 200 == 0)
		fps = updater->getFPS();
	sprintf(str, "%4.1f", fps);
	glColor3f(0.9f, 0.9f, 0.9f);
	drawString(string(str), width - 100, 20.f);
}

void PlayerHUD::drawPosition()
{
	static char str[22];
	static Position3 position;

	if(updater->getFrames() % 60 == 0)
		position = coordinator->getCameraPosition();

	sprintf(str, "%3.2f %3.2f %3.2f", position.x, position.y, position.z);
	glColor3f(0.9f, 0.9f, 0.9f);
	drawString(string(str), width - 400, 20.f);
}

void PlayerHUD::drawAngles()
{
	static char str[15];
	static float theta;
	static float phi;

	if(updater->getFrames() % 60 == 0)
	{
		theta = coordinator->getCameraTheta();
		phi = coordinator->getCameraPhi();
	}

	sprintf(str, "%3.2f %3.2f", theta, phi);
	glColor3f(0.9f, 0.9f, 0.9f);
	drawString(string(str), width - 600, 20.f);
}

void PlayerHUD::toggleFPS()
{
	showFPS = !showFPS;
}

void PlayerHUD::togglePosition()
{
	showPosition = !showPosition;
}

void PlayerHUD::toggleAngles()
{
	showAngles = !showAngles;
}
