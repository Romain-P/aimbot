#ifndef drawable_h
#define drawable_h

#include "GraphicIncludes.h"

class Drawable
{

public:
	int zIndex;

	Drawable()
	{
		zIndex = 0;
	}
	Drawable(int index)
	{
		zIndex = index;
	}
	virtual void draw() = 0;
};

#endif
