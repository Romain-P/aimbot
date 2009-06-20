#ifndef playerhud_h
#define playerhud_h

#include <string>
#include <sstream>

#include "../Drawable.h"
#include "../../Game/GameState.h"

class Updater;

using std::string;
using std::stringstream;

class PlayerHUD : public Drawable
{
private:
	bool showFPS;
	GameState* state;
	Updater* updater;
	stringstream ss;

public:
	PlayerHUD(GameState* gameState, Updater* gameUpdater)
	{
		state = gameState;
		updater = gameUpdater;
	}

	virtual ~PlayerHUD()
	{
	}

	void setShowFPS(bool show)
	{
		showFPS = show;
	}

	void drawFPS();

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
