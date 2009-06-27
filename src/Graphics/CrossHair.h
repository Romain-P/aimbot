#ifndef crosshair_h
#define crosshair_h

#include "Drawable.h"

class CrossHair : public Drawable
{
private:
	int type;
	float size;

public:
	enum
	{
		DOT,
		CIRCLE,
		CROSS,
		CORNER
	};

	CrossHair(int type, float size)
	{
		this->type = type;
		this->size = size;
	}


	void draw()
	{
		switch(type)
		{
		case DOT:
			drawDot();
			return;
		case CIRCLE:
			drawCircle();
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

	}

	void drawCircle()
	{

	}

	void drawCross()
	{

	}

	void drawCorner()
	{

	}
};

#endif
