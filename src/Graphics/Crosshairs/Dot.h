#ifndef dot_h
#define dot_h

#include "Crosshair.h"

class Dot : public Crosshair
{
public:
	Dot(float size, Colour colour) : Crosshair(size, colour)
	{
	}

	void draw()
	{
		glColor3f(colour.r, colour.g, colour.b);
		glPointSize(size);
		glBegin(GL_POINTS);
		glVertex2f(halfWidth, halfHeight);
		glEnd();
	}
};

#endif
