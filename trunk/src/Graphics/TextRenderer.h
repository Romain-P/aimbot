#ifndef textrenderer_h
#define textrenderer_h

#include <string>
#include "Glut/GraphicIncludes.h"

using std::string;

class TextRenderer
{
protected:
	void drawString(const string& text,
			float size,
			float leftX,
			float topY)
	{
		glPushMatrix();
			glTranslatef(leftX, topY, 0);
			glScalef(size, -size, size);
			for (unsigned int i = 0; i < text.length(); i++)
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text.at(i));
		glPopMatrix();
	}
};

#endif
