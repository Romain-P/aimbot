#include "PlayerHUD.h"
#include "../../Game/Updater.h"

PlayerHUD::PlayerHUD(GameState* gameState, Updater* gameUpdater) :
	Drawable(300)
{
	state = gameState;
	updater = gameUpdater;
	showFPS = true;
}

void PlayerHUD::drawFPS()
{
	static stringstream ss;
	static string a, b, c, d;
	static float minFps = 10000, maxFps = 0, avg, fps;

	fps = updater->getFps();
	avg = 0.5f * fps + 0.5f * avg;

	if(fps < minFps)
		minFps = fps;
	if(fps > maxFps)
		maxFps = fps;

	ss << fps << avg << maxFps << minFps;
	ss >> a >> b >> c >> d;

	//drawText(a, 20.f, 20.f);

	ss.str("");
	ss.clear();
}

void PlayerHUD::drawText(string& text, float leftX, float topY)
{
	glPushMatrix();
		glTranslatef(leftX, topY, 0);
		glScalef(0.14, -0.14, 0.14);
		for (unsigned int i = 0; i < text.length(); i++)
		{
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text.at(i));
		}
	glPopMatrix();
}


void PlayerHUD::draw()
{
	if(showFPS)
	{
		drawFPS();
	}
}

void PlayerHUD::setShowFPS(bool show)
{
	showFPS = show;
}
