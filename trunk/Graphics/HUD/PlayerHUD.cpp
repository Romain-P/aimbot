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
	static string str;

	ss << updater->getFps();
	ss >> str;
	drawText(str, 40, 40);
	ss.str("");
	ss.clear();
}

void PlayerHUD::setShowFPS(bool show)
{
	showFPS = show;
}

void PlayerHUD::drawText(string& text, int leftX, int topY)
{
	glPushMatrix();
		glTranslatef(leftX, topY, 0);
		glScalef(0.14, -0.15, 0.14);
		for (unsigned int i = 0; i < text.length(); i++)
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text.at(i));
	glPopMatrix();
}


void PlayerHUD::draw()
{
	if(showFPS)
	{
		glDepthMask(GL_FALSE);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0, glutGet(GLUT_SCREEN_WIDTH), 0, glutGet(GLUT_SCREEN_HEIGHT));
			glScalef(1, -1, 1);
			glTranslatef(0, -glutGet(GLUT_SCREEN_HEIGHT), 0);
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
				glLoadIdentity();
				drawFPS();
			glPopMatrix();
			glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glDepthMask(GL_TRUE);
	}
}
