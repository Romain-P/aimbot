#ifndef crosshair_h
#define crosshair_h

#include <iostream>
#include "../Drawable.h"
#include "../Colour.h"

class Crosshair : public Drawable
{
protected:
	float size;
	Colour colour;

public:
	Crosshair(float size, const Colour& colour) : Drawable(10000)
	{
		this->size = size;
		this->colour = colour;
	}

	virtual void draw() = 0;
};

#endif
