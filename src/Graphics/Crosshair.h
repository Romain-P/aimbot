#ifndef crosshair_h
#define crosshair_h

#include <iostream>
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

		std::cout << type << std::endl;
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
		default:
			drawDot();
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
		glDisable(GL_BLEND);
		glBegin(GL_LINES);
		glVertex2f(halfWidth - size, halfHeight);
		glVertex2f(halfWidth + size, halfHeight);

		glVertex2f(halfWidth, halfHeight + size);
		glVertex2f(halfWidth, halfHeight - size);
		glEnd();
		glEnable(GL_BLEND);
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
