#include "PlayerHUD.h"
#include "../../Game/Updater.h"

PlayerHUD::PlayerHUD(GameState* gameState, Updater* gameUpdater)
{
	state = gameState;
	updater = gameUpdater;
}

void PlayerHUD::drawFPS()
{
	if(updater->getFrames() % 5 == 0)
	{
		ss << updater->getFps();
		string str = ss.str();
		drawText(str, 40, 40);
		ss.clear();
	}
}

void PlayerHUD::setShowFPS(bool show)
{
	showFPS = show;
}

void PlayerHUD::drawText(string& text, int leftX, int topY)
{
	glPushMatrix();
	glTranslatef(leftX, topY, 0);
	for (unsigned int i = 0; i < text.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text.at(i));
	glPopMatrix();
}


void PlayerHUD::draw()
{
	if(showFPS)
	{
		drawFPS();
	}
}
