#ifndef cross_h
#define cross_h

#include "Crosshair.h"

class Cross : public Crosshair
{
public:
	Cross(float size, Colour colour) : Crosshair(size, colour)
	{
	}

	void draw()
	{
		glDisable(GL_BLEND);
		glBegin(GL_LINES);
		glVertex2f(halfWidth, halfHeight);
		glVertex2f(halfWidth + size, halfHeight);

		glVertex2f(halfWidth, halfHeight);
		glVertex2f(halfWidth, halfHeight + size);
		glEnd();
		glEnable(GL_BLEND);
	}
};

#endif
