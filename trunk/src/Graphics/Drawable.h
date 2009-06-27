#ifndef drawable_h
#define drawable_h

#include "GraphicIncludes.h"
#include "../Graphics/ScreenBoundsUser.h"

class Drawable : public ScreenBoundsUser
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
