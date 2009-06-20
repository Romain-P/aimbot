#ifndef drawable_h
#define drawable_h

#include "GraphicIncludes.h"

class Drawable
{

public:
	int zIndex;
	virtual void draw() = 0;
};

#endif
