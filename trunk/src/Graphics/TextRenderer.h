#ifndef textrenderer_h
#define textrenderer_h

#include <string>
#include "GraphicIncludes.h"

using std::string;

class TextRenderer
{
protected:
	void drawString(const string& text, int leftX, int topY)
	{
		glPushMatrix();
			glTranslatef(leftX, topY, 0);
			glScalef(0.03, -0.04, 0.04);
			for (unsigned int i = 0; i < text.length(); i++)
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text.at(i));
		glPopMatrix();
	}
};

#endif
