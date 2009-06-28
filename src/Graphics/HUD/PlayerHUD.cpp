#include "PlayerHUD.h"
#include "../../Game/Updater.h"

PlayerHUD::PlayerHUD(GameState* gameState, Updater* gameUpdater) :
	Drawable(300)
{
	state = gameState;
	updater = gameUpdater;
	showFPS = true;

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
	static stringstream ss;
	static string a, b, c, d;
	static float minFps = 10000, maxFps = 0, avg, fps;

	fps = updater->getFPS();
	avg = 0.1f * fps + 0.9f * avg;

	if(fps < minFps)
		minFps = fps;
	if(fps > maxFps)
		maxFps = fps;

	ss << fps << avg << maxFps << minFps;
	ss >> a >> b >> c >> d;

	drawString(a, 20.f, 20.f);

	ss.str("");
	ss.clear();
}

void PlayerHUD::toggleFPS()
{
	showFPS = !showFPS;
}
