#ifndef playerhud_h
#define playerhud_h

#include "../GraphicIncludes.h"

class PlayerHUD
{
private:
	GameState* gameState;
public:
	PlayerHUD(GameState* state) : gameState(state)
	{

	}

	void showFPS()
	{
		drawText(gameState->getFps());
	}

	void drawText(string& text, int leftX, int topY)
	{
		glPushMatrix();
		glTranslatef(leftX, topY, 0);
		for (unsigned int i = 0; i < text.length(); i++)
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text.at(i));
		glPopMatrix();
	}
};


#endif
