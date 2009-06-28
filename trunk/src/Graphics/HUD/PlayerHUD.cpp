#include "PlayerHUD.h"
#include "../../Game/Updater.h"

PlayerHUD::PlayerHUD(GameState* gameState, Updater* gameUpdater) :
	Drawable(300)
{
	state = gameState;
	updater = gameUpdater;
	showFPS = false;

	crosshair = new Crosshair(Crosshair::DOT, 3.f);
}

PlayerHUD::~PlayerHUD()
{
	delete crosshair;
}

void PlayerHUD::draw()
{
	if(showFPS)
		drawFPS();

	crosshair->draw();
}

void PlayerHUD::drawFPS()
{
	static char str[15];
	static float avg, fps;

	if(updater->getFrames() % 200 == 0)
		fps = updater->getFPS();
	//avg = 0.02f * fps + 0.98f * avg;
	sprintf(str, "%4.1f", fps);
	glColor3f(0.9, 0.9, 0.9);
	drawString(string(str), width - 100, 20.f);
}

void PlayerHUD::toggleFPS()
{
	showFPS = !showFPS;
}
