#include "PlayerHUD.h"
#include "../../Game/Updater.h"
#include "../../Game/GameCoordinator.h"

PlayerHUD::PlayerHUD(
		GameCoordinator* coordinator,
		GameState* gameState,
		Updater* gameUpdater) :
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

	drawFooterBar();
}

void PlayerHUD::drawFooterBar()
{
	glColor4f(0.9f, 0.9f, 0.9f, 0.2f);
	glBegin(GL_QUADS);
		glVertex2f(0, 	  height);
		glVertex2f(110.f, height);
		glVertex2f(110.f, height - 60.f);
		glVertex2f(0, 	  height - 60.f);

		glVertex2f(110.f, height);
		glVertex2f(160.f, height);
		glVertex2f(160.f, height - 20.f);
		glVertex2f(110.f, height - 60.f);

		glVertex2f(160.f, height);
		glVertex2f(width, height);
		glVertex2f(width, height - 20.f);
		glVertex2f(160.f, height - 20.f);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.3f);
	glLineWidth(1.0f);
	glBegin(GL_LINE_STRIP);
		glVertex2f(0, 	  height - 60.f);
		glVertex2f(110.f, height - 60.f);
		glVertex2f(160.f, height - 20.f);
		glVertex2f(width, height - 20.f);
	glEnd();

	static char health[5];
	if(updater->getFrames() % 60 == 0)
		sprintf(health, "%3.f", coordinator->getPlayerHealth());

	glColor3f(0.1f, 0.1f, 0.1f);
	glLineWidth(2.0f);
	drawString(string(health), 0.28f, 9.f, height - 15.f);
}

void PlayerHUD::drawFPS()
{
	static char str[15];
	static float fps;

	if(updater->getFrames() % 200 == 0)
	{
		fps = updater->getFPS();
		sprintf(str, "%4.1f", fps);
	}

	glColor3f(0.9f, 0.9f, 0.9f);
	drawString(string(str), 0.1f, width - 100, 20.f);
}

void PlayerHUD::drawPosition()
{
	static char str1[22];
	//static char str2[22];
	static char str3[8];
	static Position3 position;
	//static Position3 closest;
	static float dist;

	if(updater->getFrames() % 60 == 0)
	{
		position = coordinator->getPlayerPosition();
		//closest = coordinator->getClosestPoint();
		//dist = position.dist(closest);
		sprintf(str1, "%3.2f %3.2f %3.2f", position.x, position.y, position.z);
		//sprintf(str2, "%3.2f %3.2f %3.2f", closest.x, closest.y, closest.z);
		sprintf(str3, "%3.3f", dist);
	}

	glColor3f(0.9f, 0.9f, 0.9f);
	drawString(string(str1), 0.1f, width - 400, 20.f);
	//drawString(string(str2), 0.1f, width - 400, 50.f);
	drawString(string(str3), 0.1f, width - 400, 80.f);
}

void PlayerHUD::drawAngles()
{
	static char str[15];
	static float theta;
	static float phi;

	if(updater->getFrames() % 60 == 0)
	{
		coordinator->getPlayerAngles(theta, phi);
		sprintf(str, "%2.3f %2.3f", theta, phi);
	}

	glColor3f(0.9f, 0.9f, 0.9f);
	drawString(string(str), 0.1f, width - 600, 20.f);
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
