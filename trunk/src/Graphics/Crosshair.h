#ifndef crosshair_h
#define crosshair_h

#include "Drawable.h"
#include "Colour.h"

class Crosshair : public Drawable
{
private:
	int type;
	float size;

	Colour colour;

public:
	enum
	{
		DOT,
		CIRCLE,
		CROSS,
		CORNER
	};

	Crosshair(int type, float size)
	{
		this->type = type;
		this->size = size;
		colour = Colour(1, 0, 0.2f);
	}

	Crosshair(int type, float size, const Colour& colour)
	{
		this->type = type;
		this->size = size;
		this->colour = colour;
	}


	void draw()
	{
		glColor3f(colour.r, colour.g, colour.b);

		switch(type)
		{
		case DOT:
			drawDot();
			return;
		case CROSS:
			drawCross();
			return;
		case CORNER:
			drawCorner();
			return;
		}
	}

	void drawDot()
	{
		glPointSize(size);
		glBegin(GL_POINTS);
		glVertex2f(halfWidth, halfHeight);
		glEnd();
	}

	void drawCross()
	{
		glBegin(GL_LINES);
		glVertex2f(halfWidth - size * 0.5f, halfHeight);
		glVertex2f(halfWidth + size * 0.5f, halfHeight);

		glVertex2f(halfWidth, halfHeight + size * 0.5f);
		glVertex2f(halfWidth, halfHeight - size * 0.5f);
		glEnd();
	}

	void drawCorner()
	{
		glBegin(GL_LINES);
		glVertex2f(halfWidth, halfHeight);
		glVertex2f(halfWidth + size, halfHeight);

		glVertex2f(halfWidth, halfHeight);
		glVertex2f(halfWidth, halfHeight + size);
		glEnd();
	}
};

#endif
