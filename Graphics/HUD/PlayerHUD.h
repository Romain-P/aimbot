#ifndef playerhud_h
#define playerhud_h

#include <string>
#include <sstream>

#include "../Drawable.h"
#include "../GraphicIncludes.h"
#include "../../Game/Updater.h"
#include "../../Game/GameState.h"

using std::string;
using std::stringstream;

class PlayerHUD : public Drawable
{
private:
	bool showFPS;
	GameState* gameState;
	Updater* updater;
	stringstream ss;
public:
	PlayerHUD(GameState* state, Updater* gameUpdater) :
		gameState(state),
		updater(gameUpdater)
	{
	}

	void setShowFPS(bool show)
	{
		showFPS = show;
	}

	void drawFPS()
	{
		if(updater->getFrames() % 5 == 0)
		{
			ss << updater->getFps();
			//drawText(ss.str(), 40, 40);
			ss.clear();
		}
	}

	void drawText(string& text, int leftX, int topY)
	{
		glPushMatrix();
		glTranslatef(leftX, topY, 0);
		for (unsigned int i = 0; i < text.length(); i++)
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text.at(i));
		glPopMatrix();
	}

	void draw()
	{
		if(showFPS)
		{
			drawFPS();
		}
	}
};


#endif
