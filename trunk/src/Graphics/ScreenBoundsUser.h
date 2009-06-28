#ifndef screenboundsuser_h
#define screenboundsuser_h

#include "GraphicIncludes.h"

class ScreenBoundsUser
{
protected:
	int topLeftX;
	int topLeftY;
	int width;
	int height;

	ScreenBoundsUser()
	{
		topLeftX = glutGet(GLUT_WINDOW_X);
		topLeftY = glutGet(GLUT_WINDOW_Y);
		width = glutGet(GLUT_SCREEN_WIDTH);
		height = glutGet(GLUT_SCREEN_HEIGHT);
	}
};


#endif
